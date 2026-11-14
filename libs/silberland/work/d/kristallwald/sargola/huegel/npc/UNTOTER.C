inherit "std/npc";
#include <properties.h>
#include <language.h>
#include <moving.h>
#include <combat.h>
#include "../def.h"

create()
{ object ob;
  if (!is_clone(ME)) return;
  ::create();
  SetProp (P_SHORT, "Ein Untoter");
  SetProp (P_LONG, BS("Ein fuerchterlich stinkender und zerflederter "
	+"Untoter. Er stiert Dich aus dunklen Augenhoehlen an und "
	+"will Dir, so vermutest Du, nichts gutes. Mit seinen verfaulten "
	+"Koerperteile verbreitet er sicherlich eine Menge Krankheiten."));

  SetProp (P_NAME, ({"Untote", "Untoten","Untoten","Untoten"}) );
  SetProp (P_GENDER, MALE);
  AddId ( ({"untoter" }) );
  create_default_npc (14);
  SetProp(P_AGGRESSIVE, 1);
  SetProp(P_BODY, 80);
  SetProp(P_SIZE, 150);
 
  SetProp (P_HANDS, ({" mit seinem Ruessel", 20, DT_TERROR}));
  SetProp (P_MSGOUT, "schleicht weiter");
  SetProp (P_MSGIN, "schleicht herein");
  SetProp(P_MMSGIN, "schleicht herein");
  SetProp(P_MMSGOUT, "schleicht weiter");


/* kfetzen.c ist einer mit einer Krankheit...*/
  SUID;
  if(random(5)==1)
  {
	  (clone_object(ARMOUR+"kfetzen"))->move(TO);
	  command_me("ziehe fetzen an");
  }
  else
  {
	  (clone_object(ARMOUR+"fetzen"))->move(TO);
	  command_me("ziehe fetzen an");
  }
  (clone_object("/d/ebene/obj/waffe/messer"))->move(TO);
  command_me("zuecke messer");
 ob = clone_object("obj/money");
 ob->move(TO);
 ob->SetProp(P_AMOUNT, random(100)+50);

  SetAttackChats(5,
  	({"Der Untote reisst eine schreckliche Fratze.\n",
  	"Der Untote beruehrt Deinen Arm mit seinen verfaulten Fingern.\n",
  	"Du blickst den Untoten an und musst fast kotzen...\n",
  	"Der Untote hustet Dir seine Bazillen ins Gesicht.\n",
	}) );

}


int Attack(object enemy)
{
	if(random(8)==1)
	{
		tell_object(enemy, "Der Untote haucht Dir seinen Atem ins "
			+"Gesicht. Dir wird uebel...");
		if(!present("\nkretze", TP))
			(clone_object(OBJ+"kretze"))->move(enemy);
		
	}
	::Attack(enemy);
}