#ifndef __LOCAL_H_
#define __LOCAL_H_

#define HEARTBEAT_MSG        0x00102000

// activates the Dummrumleuchte:
// 4 bytes payload = active duration in ms
// when active duration == 0 -> manual deactivation
#define ACTIVATE_MSG         0x00102010

// deactivates the Dummrumleuchte
#define DEACTIVATE_MSG       0x00102011

#define RESET_MSG            0x00102FFF


#endif // __LOCAL_H_
