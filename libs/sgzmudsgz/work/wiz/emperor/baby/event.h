// event.h by fire on July 21, 1998
#include <path.h>
#define EV_SETTLE PEVENT+"ev_settle"
#define EV_QUIT PEVENT+"ev_quit"
#define EV_ENTER PEVENT+"ev_enter"
#define EV_LDAPP PEVENT+"ev_ldapp"  // this is the area leader appear regular
#define EV_LDDISAPP PEVENT+"ev_lddisapp"  // this makes the area leader disappear 
#define EV_POSITION PEVENT+"ev_position" // this is a char get a local position
#define EV_LINCOME PEVENT+"ev_lincome" // this is for areas to get local income
#define EV_ADDLOYALTY PEVENT+"ev_addloyalty" // this is for areas to get local income
#define EV_ADDREPUTATION PEVENT+"ev_addreputation" // this is for chars to increase reputation auto
#define EV_AREAPAY PEVENT+"ev_areapay" // this is for pay local officer salary
#define EV_ADJPOPULATION PEVENT+"ev_adjpopulation" // adjust the population
#define EV_LOCALMEETING PEVENT+"ev_localmeeting" // local meeting
#define EV_LEARNSKILLS PEVENT+"ev_learnskills" // local meeting
#define EV_INFORMSB PEVENT+"ev_informsb" // use soldier to inform sb sth
#define EV_LEAVE PEVENT+"ev_leave" // for an officer risign
#define EV_DONATE PEVENT+"ev_donate" // for an officer risign
#define EV_WAR PEVENT+"ev_war" // for an officer risign
#define EV_MERCHANT PEVENT+"ev_merchant" // for an officer risign
#define EV_JOB PEVENT+"ev_job" // for an officer risign
#define EV_SLEEP PEVENT+"ev_sleep" // for makelove
// following are task type TT 
#define TT_LOCALMEETING 1
#define TT_WAR 2
#define TT_TRAIN 3
#define ROBOT "/sgdomain/robot/robot"
