/*************************************************************************

  Copyright 2011-2015 Ibrahim Sha'ath

  This file is part of LibKeyFinder.

  LibKeyFinder is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  LibKeyFinder is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with LibKeyFinder.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/

#ifndef WINDOWFUNCTIONS_H
#define WINDOWFUNCTIONS_H

#include "constants.h"

namespace KeyFinder {

  class WindowFunction {
  public:
    double window(temporal_window_t windowType, int sample, int width) const;
    double gaussianWindow(int sample, int width, double sigma) const;
    std::vector<double> convolve(const std::vector<double>& input, const std::vector<double>& window) const;
  };

}

#endif
