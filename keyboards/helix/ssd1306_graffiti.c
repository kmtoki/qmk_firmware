#ifdef SSD1306OLED

#include "ssd1306_graffiti.h"
#include "config.h"
#include "i2c.h"
#include <string.h>
#include "print.h"
#include "helix.h"
#include "common/glcdfont.c"
#ifdef ADAFRUIT_BLE_ENABLE
#include "adafruit_ble.h"
#endif
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#endif
#include "sendchar.h"
#include "pincontrol.h"

//assign the right code to your layers
#define _BASE 0
#define _LOWER 2
#define _RAISE 4
#define _MOUSE 8
#define _ADJUST 16

// Controls the SSD1306 128x32 OLED display via i2c

#define i2cAddress 0x3C

#define DisplayHeight 32
#define DisplayWidth 128

#define FontHeight 8
#define FontWidth 6

#define MatrixRows (DisplayHeight / FontHeight)
#define MatrixCols (DisplayWidth / FontWidth)

//static uint16_t last_battery_update;
//static uint32_t vbat;
//#define BatteryUpdateInterval 10000 /* milliseconds */
#define ScreenOffInterval 300000 /* milliseconds */

enum ssd1306_cmds {
  DisplayOff = 0xAE,
  DisplayOn = 0xAF,

  SetContrast = 0x81,
  DisplayAllOnResume = 0xA4,

  DisplayAllOn = 0xA5,
  NormalDisplay = 0xA6,
  InvertDisplay = 0xA7,
  SetDisplayOffset = 0xD3,
  SetComPins = 0xda,
  SetVComDetect = 0xdb,
  SetDisplayClockDiv = 0xD5,
  SetPreCharge = 0xd9,
  SetMultiPlex = 0xa8,
  SetLowColumn = 0x00,
  SetHighColumn = 0x10,
  SetStartLine = 0x40,

  SetMemoryMode = 0x20,
  ColumnAddr = 0x21,
  PageAddr = 0x22,

  ComScanInc = 0xc0,
  ComScanDec = 0xc8,
  SegRemap = 0xa0,
  SetChargePump = 0x8d,
  ExternalVcc = 0x01,
  SwitchCapVcc = 0x02,

  ActivateScroll = 0x2f,
  DeActivateScroll = 0x2e,
  SetVerticalScrollArea = 0xa3,
  RightHorizontalScroll = 0x26,
  LeftHorizontalScroll = 0x27,
  VerticalAndRightHorizontalScroll = 0x29,
  VerticalAndLeftHorizontalScroll = 0x2a,
};


// Write command sequence.
// Returns true on success.
static inline bool _send_cmd1(uint8_t cmd) {
  bool res = false;

  if (i2c_start_write(i2cAddress)) {
    xprintf("failed to start write to %d\n", i2cAddress);
    goto done;
  }

  if (i2c_master_write(0x0 /* command byte follows */)) {
    print("failed to write control byte\n");

    goto done;
  }

  if (i2c_master_write(cmd)) {
    xprintf("failed to write command %d\n", cmd);
    goto done;
  }
  res = true;
done:
  i2c_master_stop();
  return res;
}

// Write 2-byte command sequence.
// Returns true on success
static inline bool _send_cmd2(uint8_t cmd, uint8_t opr) {
  if (!_send_cmd1(cmd)) {
    return false;
  }
  return _send_cmd1(opr);
}

// Write 3-byte command sequence.
// Returns true on success
static inline bool _send_cmd3(uint8_t cmd, uint8_t opr1, uint8_t opr2) {
  if (!_send_cmd1(cmd)) {
    return false;
  }
  if (!_send_cmd1(opr1)) {
    return false;
  }
  return _send_cmd1(opr2);
}

#define send_cmd1(c) if (!_send_cmd1(c)) {goto done;}
#define send_cmd2(c,o) if (!_send_cmd2(c,o)) {goto done;}
#define send_cmd3(c,o1,o2) if (!_send_cmd3(c,o1,o2)) {goto done;}

void ssd1306_clear(void) {
  // Clear all of the display bits (there can be random noise
  // in the RAM on startup)
  send_cmd3(PageAddr, 0, (DisplayHeight / 4) - 1);
  send_cmd3(ColumnAddr, 0, DisplayWidth - 1);

  if (i2c_start_write(i2cAddress)) {
    goto done;
  }
  if (i2c_master_write(0x40)) {
    // Data mode
    goto done;
  }

  for (uint8_t row = 0; row < MatrixRows; ++row) {
    for (uint8_t col = 0; col < DisplayWidth; ++col) {
      i2c_master_write(0);
    }
  }

done:
  i2c_master_stop();

}

bool ssd1306_init(void) {
  bool success = false;

  send_cmd1(DisplayOff);
  send_cmd2(SetDisplayClockDiv, 0x80);
  send_cmd2(SetMultiPlex, DisplayHeight - 1);

  send_cmd2(SetDisplayOffset, 0);


  send_cmd1(SetStartLine | 0x0);
  send_cmd2(SetChargePump, 0x14 /* Enable */);
  send_cmd2(SetMemoryMode, 0 /* horizontal addressing */);

/// Flips the display orientation 0 degrees
  send_cmd1(SegRemap | 0x1);
  send_cmd1(ComScanDec);
/*
// the following Flip the display orientation 180 degrees
  send_cmd1(SegRemap);
  send_cmd1(ComScanInc);
// end flip */
  send_cmd2(SetComPins, 0x2);
  send_cmd2(SetContrast, 0x8f);
  send_cmd2(SetPreCharge, 0xf1);
  send_cmd2(SetVComDetect, 0x40);
  send_cmd1(DisplayAllOnResume);
  send_cmd1(NormalDisplay);
  send_cmd1(DeActivateScroll);
  send_cmd1(DisplayOn);

  send_cmd2(SetContrast, 0); // Dim

  ssd1306_clear();

  // Scroll Setup and Activate
  send_cmd1(RightHorizontalScroll);
  send_cmd3(0, 0b000, 0b000);
  send_cmd3(0b011, 0, 0xff);
  send_cmd1(ActivateScroll);

  success = true;

done:
  return success;
}

bool ssd1306_off(void) {
  bool success = false;

  send_cmd1(DisplayOff);
  success = true;

done:
  return success;
}

bool ssd1306_on(void) {
  bool success = false;

  send_cmd1(DisplayOn);
  success = true;

done:
  return success;
}

void ssd1306_graffiti(void) {
  // Invader character
  static const int8_t bitmaps[2][1][16] = {
    {
      {
        0x0,0x0,0xe,0x18,0xbe,0x6d,0x3d,0x3c,0x3d,0x6d,0xbe,0x18,0xe,0x0,0x0,0x0,
      },

    },
    {
      {
        0x0,0x0,0x78,0x1d,0xbe,0x6c,0x3c,0x3c,0x3c,0x6c,0xbe,0x1d,0x78,0x0,0x0,0x0,
      },

    },
  };
  static int frame = 0;

  int frames = sizeof(bitmaps) / sizeof(bitmaps[0]);
  int rows = sizeof(bitmaps[0]) / sizeof(bitmaps[0][0]);
  int cols = sizeof(bitmaps[0][0]) / sizeof(bitmaps[0][0][0]);

  // Move to the home position
  send_cmd1(DeActivateScroll);
  send_cmd3(PageAddr, 0, DisplayHeight / 4 - 1);
  send_cmd3(ColumnAddr, 0, DisplayWidth - 1);

  if (i2c_start_write(i2cAddress)) {
    goto done;
  }
  if (i2c_master_write(0x40)) {
    // Data mode
    goto done;
  }

  for (uint8_t row = 0; row < DisplayHeight; ++row) {
    for (uint8_t col = 0; col < DisplayWidth; ++col) {
      //if (row < rows && col < cols) {
        i2c_master_write(bitmaps[frame][row % rows][col % cols]);
      //}
      //else {
      //  i2c_master_write(0);
      //}
    }
  }

  frame++;

  if (frame == frames) {
    frame = 0;
  }

  send_cmd1(ActivateScroll);

done:
  i2c_master_stop();
}

#endif
