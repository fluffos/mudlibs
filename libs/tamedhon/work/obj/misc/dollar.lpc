inherit "std/unit";

#include <properties.h>
#include <language.h>

void create(){
  if (!clonep(this_object())) return;
   ::create();
   SetProp(P_NAME,({"Dollarnote","Dollarnoten"}));
   AddSingularId("note");
   AddPluralId("noten");
   AddSingularId("dollar");
   AddPluralId("dollars");
   AddId("schein");
   AddId("scheine");
	 /* Kommt noch ...
	 SetProp( P_LONG,
	    "Hmm, ob jemand Dir die wechseln kann.\n"
	 	+ "Kaufen wirst Du damit wohl nichts koennen.\n"
	 );
	 */
   SetProp(P_GENDER,FEMALE);
   SetCoinsPerUnits(0,1);
   SetGramsPerUnits(10,1);
}
