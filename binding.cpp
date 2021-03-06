#include <emscripten/bind.h>
#include "newtonraphson.hpp"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(newtonraphson) {
   class_<NewtonRaphson>("NewtonRaphson")
      .constructor<float>()
      .function("solve", &NewtonRaphson::solve)
      ;
}