/*

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 * Author       : Patrick Pedersen <ctx.xda@gmail.com>
 * Documentation: https://github.com/UniQHW/EasyButton_Handler/README.md#ieasybuttonhandler

 */

#include <Arduino.h>
#include "IEasyButtonHandler.h"

/* Calibration */
void IEasyButtonHandler::init() {
  while(eb->activated());
}

/* Events */
void IEasyButtonHandler::onPush()                          { return; }
void IEasyButtonHandler::onQuickPushed()                   { return; }
void IEasyButtonHandler::onComplete(unsigned long ms)      { return; }
void IEasyButtonHandler::whileIdle(unsigned long ms)       { return; }
void IEasyButtonHandler::whileActivated(unsigned long ms)  { return; }

/* Standard Handler */
void IEasyButtonHandler::handle() {
  unsigned long time_stamp;
  if (eb->activated()) {
    time_stamp = millis();
    onPush();

    while(eb->activated()) {
      whileActivated(millis() - time_stamp);
    }

    unsigned long stamp = millis() - time_stamp;

    /* A quick push doesn't toggle audio playback */
    if(stamp < AUDIO_PLAYBACK_TIME) {
      onQuickPushed();
    } else {
      onComplete(stamp - AUDIO_PLAYBACK_TIME);
    }

  } else {
    time_stamp = millis();
    whileIdle(millis() - time_stamp);
  }
}
