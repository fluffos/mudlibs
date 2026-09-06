#include "path.h"
#include <spellmonster.h>
#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <combat.h>

inherit "/obj/monster/spellmonster";

protected int catch_me() {
  object *vics,pl;
  vics = filter(QueryEnemies()||({}),#'valid_victim); //');
  pl = vics[random(sizeof(vics))];
  if (!pl) return 0;
  tell_object(pl,"The old ent catches you with its strong branches and throws you high "
	      "into the air. You fall unconcious. As you awake and look around, you "
	      "see that you've been thrown far away.\n");
  show_room(environment(pl),
	    "The old ent catches "+pl->QueryName()+" and throws "+
	    pl->QueryObjective()+" high into the air.\n"
	    "You see "+pl->QueryObjective()+" vanish between some clouds.\n",
	    ({pl}));
  switch (random(15)) {
   case  0: pl->move("/d/daydream/xilef/plane/plane1",M_SILENT); break;
   case  1: pl->move(PORT("quai1"),M_SILENT); break;
   case  2: pl->move(CITY("blue_highway"),M_SILENT); break;
   case  3: pl->move(PIRATE("bottomcliff"),M_SILENT); break;
   case  4: pl->move(TOWER("first/arounde2"),M_SILENT); break;
   case  5: pl->move(PARK("pa1n1"),M_SILENT); break;
   case  6: pl->move(CITY("treetop"),M_SILENT); break;
   case  7: pl->move(CITY("sea"),M_SILENT); break;
   default: pl->move(CITY("southroad2"),M_SILENT);
   }
  pl->Defend(random(30)+70,DT_BLUDGEON, this_object());
  pl->LookAfterMove();
  return 0;
}
	
create() {
  if (::create()) return 1;
  SetName("ent");
  SetShort("an old ent");
  SetLong(
"A very old ent stands besides the path. In former times it had to guard the "
"city park so noone beyond level 5 could enter. Nowadays the park is open "
"to everyone, and the old ent looks friendly at every person entering. "
"The tree looks large and strong. Aging does not effect trees like it "
"does to other creatures.\n");
  SetLevel(39);
  SetStr(50);
  SetHP(1500);
  SetIds(({"ent","tree"}));
  SetAds(({"strong","old","very old","guard"}));
  SetSize(PSIZE_LARGE);
  SetAlign(200);
  AddDefence(DT_FIRE,-100);
  AddDefence(DT_COLD,50);
  AddDefence(DT_WATER,40);
  AddDefence(DT_ELECTRO,-40);
  AddDefence(DT_BLUDGEON,20);
  AddDefence(DT_SLASH,10);
  SetAC(16);
  SetAttr("MagicDefence",70);
  SetHands( ({ ({"strong branch",0,20}),
			   ({"tiny little twigs",0,4}),
			   ({"knobby roots",0,25}) }) );
  AddSpell("catch",
           ([
             S_FUN:#'catch_me, //'
             S_CHANCE:100,
             S_COMBAT_DELAY:1,
             S_DELAY:2,
             S_SIMULT:0
           ])
          );
  SetCastChance(45);
}

Defend(int dam,int dam_type,object weapon) {
  object who;
  int i;
  if (this_player()==this_object())
    for (i=0;(who=previous_object(i))==this_object();i++);
  else who=this_player();
  if (!who) return;
  if (who->QueryLevel()<6) {
    write("The ent looks at you with sad eyes and says:\n"
	  "   \"You are much too small to fight me. Better train with the\n"
	  "    small monsters in the park.\"\n"
	  "Then it pushes you through the gate.\n");
    show("The old ent looks at "+who->QueryName()+" and pushes "+
	 who->QuerObjective()+" through the gate into the park.\n");
    who->StopHunting(this_object());
    who->move(PARK("pa1n4"),M_GO,"west");
    return;
    }
  return ::Defend(dam,dam_type,weapon);
}

int l_west() {
  if (!this_player()) return 0;
  if (member((QueryEnemies()||({}))-({0}),this_player())!=-1) {
	write("The old ent stops you as you want to enter the city park.\n"
		  "It won't let in any of its own enemies.\n");
	say(this_player()->QueryName()+" tries to run west, but the old ent\n"
		"won't let any of its own enemies enter the city park.\n");
	return 1;
	}
  write("The old ent looks friendly at you as you enter the city park.\n");
  show("The old ent looks friendly at you as you enter the city park.\n");
  return 0;
}

init() {
  ::init();
  add_action("l_west","west");
  add_action("l_west","enter");
}
