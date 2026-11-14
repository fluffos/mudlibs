inherit "std/npc";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include "../def.h"

create()
{
  if (!is_clone(ME)) return;
  ::create();
  SetProp (P_SHORT, "Ein Aasgeier");
  SetProp (P_LONG, BS("Der Aasgeier ist ein grosser Vogel, der seinen Namen "
  	+"nicht Umsonst traegt: Er ernaehrt sich vorzugsweise von Kadavern. "
  	+"Er hat braune, buschige Federn und einen schlanken, weissen Hals. "
  	+"Sein Schnabel wie seine Krallen sind stumpf."));
	
  AddDetail(({"federn","federkleid"}),
  	BS("Das Federkleid des Aasgeiers ist, bis auf den Hals, braun."));
  AddDetail("hals",
  	BS("Der Hals ist aussergewoehnlich lang und von weisser Farbe. Er ist "
  	+"kaum mit Federn bedeckt, damit es ihm moeglich ist, tief in den "
  	+"Kadaver einzudringen und die Gedaerme herauszuholen."));
  AddDetail("farbe",
  	BS("Die Farben des Aasgeiers sind braun und weiss."));
  AddDetail( ({"faerbung","schnabel"}),
  	BS("Der Schnabel ist halb gebogen und von schwarz-gelber Faerbung. Er "
  	+"ist stupmf und benoetigt ihn nur dazu, um Loecher in seine toten "
  	+"Opfer zu bohren."));
  AddDetail("krallen",
  	BS("Die Krallen sind stumpf. Der Aasgeier kann damit kein Tier erlegen. "
  	+"Er wartet vielmehr, bis eines von selbst verendet..."));
  
  SetProp (P_NAME, "Aasgeier");
  SetProp (P_GENDER, MALE);
  AddId ( ({"aasgeier", "geier" }) );
  create_default_npc (15);
 
  SetProp (P_HANDS, ({" mit seinem stumpfen Schnabel", 70}));
  SetProp (P_ALIGN, -200);

  SetProp (P_MSGOUT, "gleitet weiter");
  SetProp (P_MSGIN, "gleitet herein");
  SetProp(P_MMSGIN, "gleitet herein");
  SetProp(P_MMSGOUT, "gleitet weiter");

  enable_commands();

}