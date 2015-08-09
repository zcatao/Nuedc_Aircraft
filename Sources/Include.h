


#ifndef   INCLUDE_H_
#define   INCLUDE_H_


/* Aditional standard ANSI C types */
#ifndef int8_t
typedef signed char         int8_t;
#endif
#ifndef int16_t
typedef signed int          int16_t;
#endif
#ifndef int32_t
typedef signed long int     int32_t;
#endif

#ifndef uint8_t
typedef unsigned char       uint8_t;
#endif
#ifndef uint16_t
typedef unsigned int        uint16_t;
#endif
#ifndef uint32_t
typedef unsigned long int   uint32_t;
#endif
#ifndef TPE_Float
typedef float               TPE_Float;
#endif
#ifndef char_t
typedef char                char_t;
#endif

#include  "hidef.h"
#include  "MC9S12XS128.h"

#pragma   LINK_INFO DERIVATIVE "MC9S12XS128"

#include "math.h"
#include <stdio.h>

#include  "CPU_BUS.h"

//#include  "SCI0.h"
#include  "SCI1.h"
#include  "ATD.h"
#include  "PIT.h"
#include  "Events.h"
#include  "Oled.h"
#include  "PWM.h"
#include  "SPR.h"
#include  "SPR.h"

#endif
