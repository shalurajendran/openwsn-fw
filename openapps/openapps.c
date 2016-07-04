/**
\brief Applications running on top of the OpenWSN stack.

\author Thomas Watteyne <watteyne@eecs.berkeley.edu>, September 2014.
*/

#include "opendefs.h"

// CoAP
#include "c6t.h"
#include "cinfo.h"
#include "cleds.h"
#include "cexample.h"
#include "cstorm.h"
#include "cwellknown.h"
#include "rrt.h"
// TCP
#include "techo.h"
// UDP
#include "uecho.h"
#include "uinject.h"

//=========================== variables =======================================

//=========================== prototypes ======================================

//=========================== public ==========================================

//=========================== private =========================================

void openapps_init(void) {
   // CoAP
   c6t_init();
   cinfo_init();
   //cexample_init();
   cleds__init();
   cstorm_init();
   cwellknown_init();
   rrt_init();
   // TCP
   techo_init();
   // UDP
   uecho_init();
#ifdef GOLDEN_IMAGE_ROOT
   uinject_init();
#endif
}

uint8_t openapps_getBandwidth(uint8_t appId){
    uint8_t bandwidth_numOfCells = 0; // number of cells per slotframe
    if (appId == COMPONENT_UINJECT){
        bandwidth_numOfCells += uinject_getBandwidth();
    } else {
        // add other app bandwidth here
    }
    return bandwidth_numOfCells;
}
