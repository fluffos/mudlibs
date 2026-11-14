/* The conjurer for the free_turanu quest
   Cadra 12-01-95 */

#include "path.h"
#include <rooms.h>
#include <combat.h>
#include <moving.h>
#include <properties.h>

inherit "/obj/spellmonster";


remove_door() {
  (PALACE("warcade"))->RemoveExit("south");
  tell_room(PALACE("warcade"),"The southern wall looks massive again.\n");
  say("Elosar sighs: My spell expired.\n");
  return;
}

int do_push(string str) {
  object ob;
  if (!str) return 0;
  if (!this_player()) return 0;
  if (!id(str)) return (int) notify_fail("Poke whom?\n") && 0;
  if (!ob=present("palaceobj",this_player())) {
    write("You don't seem to know what you are doing in here! Begone!!!\n");
    this_player()->move(CITY("church"),M_GO,"into a puff of smoke");
    return 1;
    }
  if (!ob->QueryWandGiven()) return (int) notify_fail(
"Elosar says: I would need my wand to help you.\n") && 0;
  write("Elosar says: Ok, here you are, but make sure that someone is there "
"to use the exit.\n");
  say("Elosar waves his wand.\n");
  (PALACE("warcade"))->AddExit("south",PALACE("prstair"));
  tell_room(PALACE("warcade"),
"The stone door opens and a way to the south is visible.\n");
  say("Elosar says: It is done.\n");
  call_out(20,"remove_door");
  return 1;
}

create() {
  if (::create()) return 1;
  SetName("Elosar Dreamweaver");
  SetShort("An old conjurer");
  SetLong(
"You face an old elf. He looks tired and full of sorrow but still mighty. "
"You feel quite sure that it would not be the best idea to attack him. Perhaps "
"he could help you?\n");
  SetRace("elf");
  SetIds(({"elf","conjurer"}));
  SetAds(({"old","an","a"}));
  AddDefence(DT_PSYCHO,100);
  AddDefence(DT_ACID,50);
  AddDefence(DT_COLD,50);
  AddDefence(DT_MAGIC,80);
  SetAttribute("MagicDefence",80);
  SetAlign(1000);
  SetHands( ({ ({"left hand",0,16}),({"right hand",0,17}) }) );
  AddSpell("freeze","get hit by cold air.","gets hit by cold air.",
    30,40,DT_COLD);
  AddSpell("cloud","are covered by a cloud.","is covered by a cloud.",
    35,40,DT_ACID);
  AddSpell("dimensional rift","feel the horror of the netherhells.",
    "looks terrified.",50,70,DT_PSYCHO);
  SetSpellChance(40);
  SetMale();
  SetLevel(35);
  SetDex(45);
  SetHP(2000);
  SetAC(16);
  AddQuestion(({"help"}),
"Elosar says: I could help you if you want to visit the catacombs of the "
"palace, but I need my wand of conjuring for this.\n");
  AddQuestion(({"catacombs","catacomb"}),
"Elosar says: The catacombs are deep beneath the palace. Cadra closed the "
"entrance long ago. Only two persons together are able to bring me my wand so "
"I could open a one-way door.\n");
  AddQuestion(({"door","one-way door"}),
"Elosar says: The only thing I could do is to open the closed exit in the "
"western arcades for a short moment. But I can do it as often as you wish. "
"Just poke me then.\n");
  AddQuestion(({"cadra"}),"Elosar says: She's my Lady.\n");
  AddQuestion(({"turanu","tiriki"}),
"Elosar says: Oh, you know our little friends?\n");
  AddQuestion(({"shadows","shadow"}),
"Elosar says: After the shadows overtook the catacombs, Cadra decided to close "
"the entrance to prevent others from running into a trap.\n");
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
    ([P_SHORT:"a conjurer staff",
      P_LONG:
"This is a long staff made of oakwood. It looks somehow like a serpent "
"that is made of wood.\n",
      P_IDS:({"staff"}),
      P_ADS:({"wooden","serpent","a","the","oakwood","long"}),
      P_NUMBER_HANDS:2,
      P_WC:20,
      P_SIZE:PSIZE_NORMAL,
      P_RESET_QUALITY: 100,
      P_WEAPON_TYPE:WT_STAFF,
      P_DAM_TYPE:DT_BLUDGEON,
      P_WEIGHT:2800,
      P_VALUE:14000,
      ]) );
}

do_give(string str) {
  string what,whom;
  object ob;
  if (!str) return (int) notify_fail(
"Elosar says: What are you trying?\n") && 0;
  if (!this_player()) return 0;
  if (sscanf(str,"%s to %s",what,whom)!=2) return (int) notify_fail(
"Give what to whom?\n") && 0;
  if (!id(whom)) return 0;
  if (!ob=(present(what,this_player()))) return (int) notify_fail(
"You don't have it!\n") && 0;
  if (str=="wand") {
    if (!ob=present("tirconwand",this_player())) return 0;
    this_player()->SetWandGiven();
    ob->remove();
    if (ob) destruct(ob);
    if (!ob=present("palaceobj",this_player())) {
      write("Elosar says: Thanks, but you seem to be wrong here. I'll help "
"you out of here.\n");
      this_player()->move(CITY("church"),M_GO,"into a puff of smoke");
      return 1;
      }
    if (!ob->QueryPartner()) {
      write("Elosar says: You seem to be alone? Try to restart with a partner. "
"This time I'll help you out of here.\n");
      this_player()->move(CITY("church"),M_GO,"into a puff of smoke");
      return 1;
      }
    (ob->QueryPartner())->SetWandGiven();
    return 1;
    }
}
    
init() {
  ::init();
  add_action("do_push","poke");
  add_action("do_give","return");
  add_action("do_give","give");
  add_action("do_give","offer");
}
