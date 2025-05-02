#define pri
#include <LSA08.h>

#include "Variables.h"
#include "SetupLoop.h"
#include "pid.h"
#include "Function.h"
#include "Calibration.h"
#include "Digital.h"
#include "Decision.h"

void setup() {
  // put your setup code here, to run once:
  s_req();
}

void loop() {
  // put your main code here, to run repeatedly:
  l_req();
}
