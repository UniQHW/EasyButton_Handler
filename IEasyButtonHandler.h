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

#ifndef IEASYBUTTONHANDLER_H
#define IEASYBUTTONHANDLER_H

#include "EasyButton.h"

/* IEasyButtonHandler
 * ----------
 * Description: A handler interface for EasyButton objects
 * ---------- */
class IEasyButtonHandler {
public:
  IEasyButtonHandler(EasyButton *_eb) {
    eb = _eb;
  }

  void init();

private:
  EasyButton *eb;

protected:

  /* Events */
  virtual void onPush();                          // Triggered directly after button push
  virtual void onQuickPushed();                   // Triggered after a rapid press, which doesn't toggle audio playback (and hence, skips onComplete())
  virtual void onComplete(unsigned long ms);      // Triggered directly before device enters idle mode
  virtual void whileIdle(unsigned long ms);       // Polled while button is in idle mode
  virtual void whileActivated(unsigned long ms);  // Polled while button is activated

public:

  /* Standard Handler */
  void handle();
};

#endif // IEASYBUTTONHANDLER_H
