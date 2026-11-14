#include "../def.h"

inherit "std/armour";

#include <properties.h>
#include <combat.h>
#include <language.h>
#include <new_skills.h>

string unterarme();


create()
{
  if (!is_clone(this_object())) return;
  ::create();

  SetProp(P_SHORT, "Knoecherne Armschienen");
  SetProp(P_LONG, BS( 
    "Diese Knochen sind durch gefinkelte Schleiftechnik wie ein "
	+"Unterarm geformt und schoetzen diesen dadurch vor Schlaegen.") );
  SetProp(P_NAME, "Armschienen");
  SetProp(P_GENDER, FEMALE);
  SetProp(P_ARMOUR_TYPE, AT_GLOVE );
  SetProp(P_AC, 7);
  SetProp(P_MATERIAL, MAT_BONE );
  SetProp(P_WEIGHT, 400);
  SetProp(P_VALUE, 1000);
 
//  SetProp(P_WEAR_RESTRICTIONS, ([SR_INCLUDE_RACE: "Elf","Mensch"]) );

  SetProp(P_WEAR_FUNC, TO);

  AddId( ({"armschienen", "schienen","knochenschienen"}) );

  AddDetail( ({"schleiftechnik","technik"}),
    "Genaugesagt sind maechtige Knochen wie laengliche Schalen "
	+"geschliffen worden.\n");

  AddDetail("schalen",
	"Sie passen gut auf groessere Unterarme.");

  AddDetail( ({"unterarm","unterarme"}), #'unterarme );
  
  AddDetail("schlaege",
	"Deren haben die Armschienen wohl schon viele abgehalten, wie "
	+"Du an den vielen Kerben erkennen kannst.");

  AddDetail("kerben",
	"Sie sind hin und wieder recht tief.\n");

}

string unterarme()
{
	if(TP->QueryProp(P_RACE) == "Zwerg" || TP->QueryProp(P_RACE) == "Hobbit")
		return "Diese Armschienen sind Dir wohl etwas zu gross.\n";
	return "Diese Armschienen passen genau auf Deine Unterarme.\n";
}



int DefendFunc (mixed dam_type, int spell, object enemy)
{
  if( member(dam_type, ({ DT_RIP, DT_WHIP}) ) != -1)
  {
    return 2+random(3);
  }
  return 0;
}


int WearFunc()
{
  if( TP->QueryProp(P_FROG) || TP->QueryProp(P_SIZE)<144 )
  {
    write("Deine Arme sind viel zu kurz dafuer.\n");
    return 0;
  }
  return 1;
}
