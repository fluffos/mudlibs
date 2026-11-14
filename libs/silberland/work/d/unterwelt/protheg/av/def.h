#define GEBIET "av"
#include "../def.h"

#include "../avmitte/avmitte.h"

#define STURZRAUM_0 ROOM "dummyraum"
#define STURZRAUM_1 ROOM "noufer_2_5_1"
#define STURZRAUM_2 ROOM "noufer_5_2_1"

#define DHRKION "/d/unterwelt/zordan/dhrkion/master/dhrkion"

#define BAT "/d/unterwelt/basics/central/npc/bat"
#define SPIDER "/d/unterwelt/basics/central/npc/spinne"

#define STURZ void sturz_ausgabe(int flag) \
{ \
  switch(flag) \
    { \
    case 1: \
      if(!TP) return; \
      if(ENV(TP)!=find_object(STURZRAUM_0)) return; \
      tell_room(ME, \
		BS("Du hoerst einen langgezogenen Schrei der in der Tiefe " \
		   "verstummt..."), ({TP})); \
      write(BS("Du stuerzt tief...")+"\n"); \
      break; \
    case 2: \
      if(!TP) return; \
      if(ENV(TP)!=find_object(STURZRAUM_0)) return; \
      write(BS("Du schrammst an der Felswand entlang. Der rauhe Fels reisst " \
	       "Dir die Haut in Fetzen...")+"\n"); \
      TP->AddHp(-30); \
      break; \
    case 3: \
      if(!TP) return; \
      if(ENV(TP)!=find_object(STURZRAUM_0)) return; \
      tell_room(ME, \
		BS("Du hoerst von weit unten einen dumpfen Aufprall. Der " \
		   "Schrei bricht schlagartig ab..."), ({TP})); \
      write(BS("Mit lautem Krachen schlaegst Du unten auf einer " \
	       "scharfkantigen Klippe auf. Der harte Aufprall " \
	       "raubt Dir die Sinne. Hilflos bleibst Du mehr tot " \
	       "als lebendig liegen.")+"\n"); \
      TP->move(wohin(), M_GO | M_SILENT | M_NO_SHOW); \
      tell_room(ENV(TP), \
		BS("Mit lautem Krachen schlaegt "+TP->name(WER)+" vor Dir " \
		   "auf dem Boden auf. "+TP->name(WER)+" muss oben in " \
		   "der Wand irgendwo abgestuerzt sein."), ({TP})); \
      SetProp(P_KILL_NAME, "Ein harter Aufprall"); \
      TP->do_damage(150); \
      if(interactive(TP)) \
        present("DIE_IF_DISCO", TP)->remove(1); \
      break; \
    } \
} \
 \
int sturz(string str) \
{ \
  int i; \
  object ob; \
  \
  catch(call_other(ROOM "weg_h03", "???")); \
  \
  if(find_object(ROOM "weg_h03")->QueryGebetet(TP)) \
    if(random(3)) \
      return write(BS("Eine unheimliche Macht haelt Dich gluecklicherweise " \
		      "zurueck...")), 1; \
  \
  tell_room(ME,				 \
	    "\n"+ \
	    BS(TP->name(WER)+" passt nicht auf, tritt ueber den Sims " \
	       "und verliert das Gleichgewicht.")+ \
	    BS("Mit einem lauten Schrei stuerzt "+TP->QueryPronoun(WER)+ \
	       " in die Tiefe...")+"\n\n", ({TP})); \
  write("\n"+BS("Das WAR der Schritt in die falsche Richtung...")+"\n \n"); \
  TP->SetProp(P_PARALYZED, \
	      ([PARALYZE_TIME: 6, \
		PARALYZE_MSG: "Im freien Fall????\n", \
		PARALYZE_MSG_OTHER: "", \
		PARALYZE_END: "Aber - Du kannst Dich noch bewegen...\n", \
		PARALYZE_END_OTHER: "" ])); \
  TP->move(STURZRAUM_0, M_GO | M_SILENT | M_NO_SHOW | M_NOCHECK); \
  ob=clone_object(OBJ "die_if_disco"); \
  ob->move(TP, M_NOCHECK); \
  for(i = 1; i < 4; i++) \
    call_out("sturz_ausgabe", 3*i - 1, i); \
  return 1; \
}
