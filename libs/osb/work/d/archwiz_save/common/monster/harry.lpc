/* Schnullerbacke is back!
 *
 * Some little additions for the postquest by Thragor, 18dec93
 */

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <equipment.h>
#include <npc.h>

#define POSTQUEST "/d/daydream/thragor/postquest/encode"

inherit "/std/npc";

object harry;

create() {
  string *chats, *achats, *funs, *type, *match;
  if (::create()) return;

  chats = ({
 "Harry says: What are you waiting for?\n"
,"Harry says: Hello there!\n"
,"Harry says: I don't like winter.\n"
,"Harry says: I don't like snow.\n"
,"Harry says: I don't like rain.\n"
,"Harry says: Who are you?\n"
,"Harry says: Why do you look like that?\n"
,"Harry says: What are you doing here?\n"
,"Harry says: Nice weather, isn't it?\n"
,"Harry smiles.\n"
          });
  achats = ({
 "Harry says: Don't hit me!\n"
,"Harry says: That hurt!\n"
,"Harry says: Help, someone!\n"
,"Harry says: Why can't you go bullying elsewhere?\n"
,"Harry says: Aooooo\n"
,"Harry says: I hate bashers!\n"
,"Harry says: Bastard\n"
,"Harry says: You big brute!\n"
           });
  funs = ({ "why_did", 0     , 0          , 0      , 0
          , "smiles"  , "say_hi" , "test_say", 0
          , "follow" , "gives"
         });
  type = ({ "sells", "attack", "left"     , "takes", "drops"
          , "smiles"  , "arrives", "says:"   , "tells you:"
          , "leaves" , "gives"
         });
  match = ({ ""     , ""       , "the world", ""      , ""
           , "happily", ""        , ""         , ""
           , ""       , "you"
          });

  SetName("Harry");
  SetShort("Harry the affectionate");
  SetLong("Harry has an agreeable look.\n");
  SetAlign(50);
  SetGender(GENDER_MALE);
  SetLevel(9);
  SetMaxHP(50);
  SetHP(50);
  SetXP(2283);
  SetGoChance(5);
  InitChats(2, chats);
  SetAttribute("MagicDefence",6);
  InitAChats(20,chats);
  InitMatch(funs, type, match);
  // BEGONE AddItem(SCROLLS("panic"),REFRESH_REMOVE);
  call_out("pick_any_obj", random(200)+1);
  call_out("drop_any_obj", random(400)+1);
}

#if 0
heart_beat() {
  ::heart_beat();
  if (random(100) <= 20) pick_any_obj(); 
  if (random(100) <= 10) drop_any_obj(); 
}
#endif

pick_any_obj() {
  object ob, *inv;
  mixed rc;
  string sh;

  if (!environment(this_object())) return;

  if (previous_object() == this_object())
  {
    while(remove_call_out("pick_any_obj") >= 0);
    call_out("pick_any_obj", random(200)+1);
  }

  inv = all_inventory(environment(this_object()));
  inv -= ({ this_object() })+filter(inv, #'interactive);
  if (!sizeof(inv))
    return;
  ob = inv[0];
  sh = ob->Short() || "something";
  rc = DropTake("take", ob);
  if (!ob)
    return;
  if (!sizeof(rc)) {
    show(capitalize(QueryName())+" tries to take "+sh+" but fails.\n");
    return;
  }
  if (!ob->wield(this_object()) && !ob->wear(this_object()))
    if (ob->QueryWearData()) {
      if (EQ_OK != ob->Wield(this_object(), ob->QueryWeaponType()))
        ob->Wear(this_object(), ob->QueryArmourType());
    }
}

valid_drop_item(object ob)
{
  return ob->QueryCreator()!=object_name(this_object());
}

drop_any_obj() {
  string sh;
  object ob, *inv;
  mixed rc;

  if (!environment(this_object()))
    return;

  if (previous_object() == this_object())
  {
    while(remove_call_out("drop_any_obj") >= 0);
    call_out("drop_any_obj", random(400)+1);
  }

  if (!sizeof(inv = filter(all_inventory(),#'valid_drop_item)))
    return;

  ob = inv[0];
  sh = ob->Short() || "something";
  rc = DropTake("drop", ob, PUTGET_REALLY);
  if (!ob)
    return;
  if (!sizeof(rc)) {
    show(capitalize(QueryName())+" tries to drop "+sh+" but fails.\n");
    return;
  }
}


why_did(str) {
  string who, what;
  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  sscanf(str, "%s %s", who, what);
  if(who == "harry" || who == "Harry") return;
  if (sscanf(str, "%s sells %s.", who, what) == 2)
    notify("Harry says: Why did you sell " + what + "\n");
  if (sscanf(str, "%s attacks %s.", who, what) == 2)
    notify("Harry says: Why does " + who + " attack " + what + "?\n");
  if (sscanf(str, "%s left the game.", who) == 1)
    notify("Harry says: Why did " + who + " leave the world ?\n");
  if (sscanf(str, "%s takes %s.", who, what) == 2)
    notify("Harry says: Why did " + who + " take " + what + " ?\n");
  if (sscanf(str, "%s drops %s.", who, what) == 2)
    notify("Harry says: Why did " + who + " drop " + what + " ?\n");
}

notify2(str) {
  if (!(this_player())) {return;}
  if (environment(this_player()))
    tell_room(environment(this_player()), str, ({ this_player() }));
  write(str);
}

notify(str) {
  call_out("notify2", 1, str);
}

how_does_it_feel(str) {  /* No levels anymore, this is unused */
  string who, what;
  sscanf(str, "%s %s", who, what);
  if(who == "harry" || who == "Harry") return;
  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  if (sscanf(str, "%s is now level %s.", who, what) == 2)
    notify("Harry says: How does it feel, being of level " + what + " ?\n");
}
    
smiles(str) {
  string who, what;
  sscanf(str, "%s %s", who, what);
  if(who == "harry" || who == "Harry") return;
  if (sscanf(str, "%s smiles happily", who) == 1 && who != "Harry")
    notify("Harry smiles happily.\n");
}
    
say_hi(str) {
  string who, what;
  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  if (sscanf(str, "%s arrives%s", who, what) == 1)
    notify( "Harry says: Hi " + who + ", nice to see you !\n");
}
    
test_say(str) {
  string a, b, message;

  sscanf(str, "%s %s", a, b);
  if(a == "harry" || a == "Harry") return;
  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  if (!sscanf(str, "%s says: %s", a, b) == 2) return;
  str = b;
  
  if (str == "hello" || str == "hi" || str == "hello everybody")
    message = "Harry says: Pleased to meet you!\n";

  if (str == "shut up")
    message = "Harry says: Why do you want me to shut up ?\n";

  if (sscanf(str, "%sstay here%s", a, b) == 2 ||
      sscanf(str, "%snot follow%s", a, b) == 2 ||
      sscanf(str, "%sget lost%s", a, b) == 2)
    message = "Harry says: Ok then.\n";

  if (!message)  message = "Harry says: Why do you say '" + str + "'???\n";

  notify(message);
}

follow(str) {
  string who, where;
  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  if (sscanf(str, "%s leaves %s.", who, where) == 2)
    call_out("_follow", 0, where);
}

_follow(where) { command_me (where); }

gives(str) {
  string who, what, whom;
  int rand;
  object obj, next_obj;

  if (strlen(str) && str[<1] == '\n')
    str = str[0..<2];
  if(sscanf(str, "%s gives you %s.", who, what) != 2) return;

  if(what == "firebreather" || what == "special" ||
     what == "beer" || what == "bottle") {
    switch(random(4)) {
    case 0:
      if (random(10) > 6) {
        notify("Harry sighs and says: I guess you're gonna kill me now.\n");
        DropTake("drop", "all");
        command_me("west");
      }
      break;
    case 1:
      command_me("drink " + what);
      break;
    case 2:
      DropTake("drop", what);
      break;
    case 3:
      GivePut("give", what, lower_case(who));
      break;
    }
  } 
  else if (what == "corpse") {
    notify("Harry says: HEY, bury your corpses yourself, asshole.\n");
    GivePut("give", what, lower_case(who));
  } 
  else notify("Harry says: Thank you very much, sir.\n");
}

second_life() {
  object *inv;

  inv = filter_objects(all_inventory(this_object()), "id", "bottle");
  if (sizeof(inv)) {
    filter_objects(inv, "remove");
    notify(
        "There is a crushing sound of bottles breaking, as the body falls.\n"
          );
  }
  return 0;
}

init()
{
 ::init();
 add_action("ask_about","ask");
}

int ask_about(string str)
{
 string myname,what;

 if (!str) return
  (int)notify_fail("Whom do you want to ask about what?\n");
 if (sscanf(str,"%s about %s",myname,what)!=2) return
  (int)notify_fail("Whom do you want to ask about what?\n");
 if (!this_object()->id(myname)) return
  (int)notify_fail(
   "Harry says: Why don't you ask me?\n");
 what = lower_case(what);
 if (what!="code"&&what!="the code") return
  (int)notify_fail(
   "Harry says: Why do you ask me about '"+what+"'?\n");
 POSTQUEST->get_code(11,this_player());
 return 1; 
}
