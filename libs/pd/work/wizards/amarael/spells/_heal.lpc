#include <std.h>
#include <daemons.h>

inherit "/wizards/amarael/spells/elemspell_d";

int spell();
void send_messages(object tp, object ob, string clas, string limb);

int cmd_heal(string str) {
    string whom, limb, clas;
    int amount, cost, healing, i, wisdom;
    object tp, ob;
    string * limbs;

    tp = this_player();
    clas = tp->query_subclass();

    if(!spell())
      return notify_fail("What?\n");
    if(!str)
      return notify_fail("Heal whom?\n");
    if(tp->query_disable()) {
      return notify_fail("You are too busy for that.\n");
    if(tp->query_alignment() < 300)
      return notify_fail("You have betrayed the source of your powers.\n");

    healing = (int)tp->query_skill("healing")/2;
    healing += (int)tp->query_level()/2;
    healing += (int)tp->query_skill("faith")/2;

    if(str == "me" || str == "myself")
      ob = tp;
    else
      ob = present(str, environment(tp));
    if(!ob) {
      if(sscanf(str, "%s %s", whom, limb) != 2)
        return notify_fail("Correct syntax: <heal [who] [(limb)]\n");
      if(whom == "me" || whom == "myself")
        ob = tp;
      else
        ob = present(whom, environment(tp));
      }
    if(!ob)
      return notify_fail("Heal whom?\n");

    if(!limb)
      cost = healing/4;
    else if(limb == "all")
      cost = healing/3;
    else if(member_array(limb, (string *)ob->query_limbs()) == -1)
      return notify_fail("That limb is missing!\n");
    else
      cost = healing/5;

    if(ob != tp) cost = cost+(random(cost)/2);
    if(tp->query_mp() < cost)
      return notify_fail("Too low on magic power.\n");
    tp->add_mp(-cost);
    amount = (healing);
    if(tp != ob)
      tp->add_alignment(amount/4);
    tp->add_skill_points("healing", amount);

    if(!limb) {
      ob->add_hp(amount);
      send_messages(tp, ob, clas, 0);}
      }
    else if(limb == "all") {
      limbs = (string *)ob->query_limbs();
      for(i=0; i<sizeof(limbs); i++) {
        ob->heal_limb(limbs[i], (amount/2));
        }
      ob->add_hp(amount/2);
      send_messages(tp, ob, clas, 0);
      }
    else {
      ob->heal_limb(limb, amount);
      ob->add_hp(amount/3);
      send_messages(tp, ob, clas, 0);
      }
    this_player()->set_magic_round();
    return 1;
}

void send_messages(object tp, object ob, string clas, string limb) {
    string what, thing;
    if(clas == "monk" || clas == "cleric") {
        thing = "prayer";
        what = "a prayer of healing";
    }
    else if(tp->query_class() == "mage") {
        thing = "magic";
        what = "a spell of healing";
    }
    else {
        thing = "nonsense";
        what = "nonsense";
    }
    if(tp == ob) {
     tell_object(tp, "You heal your own wounds through " + thing + ".");
     tell_room(environment(tp), tp->query_cap_name() +" mutters " + what + ".", ({ tp }) );
    }
    else {
      tell_object(tp, "You heal " + ob->query_cap_name() +"'s wounds through " + thing + ".");
      tell_object(ob, tp->query_cap_name() + " heals your wounds through " + thing + ".");
      tell_room(environment(tp), tp->query_cap_name() + " mutters " + what + ".", ({ tp, ob }) );
    }
}
void help() {
     write("Syntax: <heal [player] [(limb)]>\n\n"+
        "Heals the player named.  If no limb is given, then\n"+
        "it heals hp.  Otherwise it heals the limb named.  The arg \"all\"\n"+
        "is a valid arg for the limb.\n");
}

int spell() {
   object tp;
   tp = this_player();
   if(!tp) return 0;
   if(tp->is_monster()) return 1;
   if(tp->query_level() < 2)			return 0;
   if(tp->query_subclass() == "cleric")		return 1;
   if(tp->query_subclass() == "monk")		return 1;
   if(tp->query_subclass() == "paladin")	return 1;
   if(tp->query_subclass() == "blue")		return 1;
   if(tp->query_subclass() == "necromancer")	return 0;
   if(tp->query_class() == "mage")		return 1;
   return 0;
}
