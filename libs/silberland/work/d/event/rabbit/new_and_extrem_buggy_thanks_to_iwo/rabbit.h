#include "../event.h"

#define RABBITMASTER RABBIT("master/master")
#define EVENTRABBIT RABBIT("npc/hasi")
#define RABBITLOG RABBIT("log/rabbit.log")

#define DAUER 10

#define MAXRABBITS 150
#define ALERT 20

#define REPORT 20

#define FUCKDELAY 20
#define WURFDELAY 25

#define SCHWELLE 50


#define RABBITID "\nrabbit"
#define P_SEX "Sex"

#define REGIONS


#define tell_iwo(x) if(find_player("iwo")) tell_object(find_player("iwo"), x)
#define tell_angrox(x) if(find_player("angrox")) tell_object(find_player("angrox"), x)
