/*
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef GPIOCONST_H
#define GPIOCONST_H

namespace GPIO {

typedef struct pins_t {
  const char *name;
  const char *key;
  unsigned int gpio;
  int pwm_mux_mode;
  int isAllocatedByDefault;
} pins_t;

class GPIOConst
{
 public:
  GPIOConst();
  virtual ~GPIOConst();

  static GPIOConst* getInstance();
  int getGpioByKey(const char *key);
  int getGpioByName(const char *name);
  const char* getGpioNameByPin(unsigned int pin);
  const char* getGpioKeyByPin(unsigned int pin);
  const char* getEdgeValueByIndex(unsigned int index);
  int getEdgeIndexByValue(const char* value);
  int isPinAllocatedByDefault(unsigned int pin);

 private:
  static pins_t pinTable[97];
  static const char* strEdge[4];
  static GPIOConst* instance;
};

} /* namespace GPIO */
#endif  // GPIOCONST_H
