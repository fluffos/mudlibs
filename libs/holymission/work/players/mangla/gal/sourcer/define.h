#ifndef __define.h__
#define __define.h__

#include "/sys/vt100.h"

mixed call = (: call_other :);

#define TP this_player()
#define TPN TP->query_name()
#define TPL TP->queryLlevel()
#define TPR TP->query_race()
#define TPRN TP->query_real_name()
#define TPI TP->query_immortal()

#define TO this_object()
#define TON this_object()->query_name()
#define TOL TO->query_level()
#define TOS TO->short()

#define TS(x) if(find_living("sourcer")) tell_object(find_living("sourcer"),x)  
#define TR(x) tell_object( environment(this_object()), x)
#define TELL(x) tell_object(this_player(), x) 
#define SAY(x) say(x,this_player())
#define E(x) environment(x)
#define FTO file_name(this_object())

#define CITY "players/sourcer/death/city/"
#define DEATH "players/sourcer/death/"
#define SWAMP "players/sourcer/death/swamp/"
#define SPELLS "players/sourcer/death/spells/"
#define FOREST "players/sourcer/death/forest/"
#define FIELD "players/sourcer/death/fields/"
#define BEACH "players/sourcer/death/beach/"
#define MEADOW "players/sourcer/death/meadow/"
#define HILL "players/sourcer/death/hills/"
#define DOBJ "players/sourcer/death/obj/"
#define LOGDIR "death/log/"
#define DEFAULT "/players/sourcer/default/"

#define ERROR(x) write_file(LOGDIR+"error.log",x)

#define WINFO(x) if(TPI) write(VT_TA_B+"WizInfo: "+VT_TA_AO+x)
#define BOLD(x) write(VT_TA_B+x+VT_TA_AO) 

#define MALE 1
#define FEMALE 2
#define NEUTER 0

#define LOG(x) write_file("log/illigal_use.log",x)
#define LOG_ERR(x) write_file("log/error",x)
#define CONTROL "/players/sourcer/death/city/control"
#endif

