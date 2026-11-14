#define MAGIERNAME "protheg"

#define MOST "/d/wueste/protheg/most/"
#define PO5MASTER "/d/wueste/protheg/po5/npc/master.lpc"
#define KARAVANE "/d/wueste/protheg/karavanen/room/"
#define KILLMASTER "/players/protheg/killmaster/killmaster"
#define DUNKELELF "/d/unterwelt/basics/central/npc/std_darkelf"

#define BLINDFIGHT \
  if((enemy->QueryProp(P_BLIND)) && (!spell)) { \
    if((enemy->QueryAttribute(A_DEX)>28) && !random(3)) \
	dam=dam/3; \
      else \
	dam=0; \
    \
    if(!random(5)) \
      tell_object(enemy, ({ \
	BS("Koenntest Du doch nur etwas erkennen!"), \
	BS("Dein Schlag geht voll daneben!"), \
	BS("Blind kaempfen macht keinen Spass!"), \
	BS("Du stolperst fast!")})[random(4)]); \
    } 

#define CLOSURE(x) #'x
