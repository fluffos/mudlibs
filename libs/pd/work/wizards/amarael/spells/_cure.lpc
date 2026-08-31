#include <std.h>
#include <daemons.h>

inherit DAEMON;

int spell();
void send_messages(object tp, object ob, string clas, string limb);

int cmd_cure(string str) {
    string whom, limb, clas;
    int amount, cost, healing, i;
    object tp, ob;
    string *limbs;
    tp = this_player();

    if(!spell())
      return notify_fail("What?\n");
    if(tp->query_alignment() < 500)
      return notify_fail("You have betrayed the source of your powers.\n");
    if(tp->query_ghost())
      return notify_fail("Your voice is hollow.\n");
    if(tp->query_disable())
      return notify_fail("You are too busy too cure.\n");
    if(tp->query_magic_round())
      return notify_fail("You are in the middle of another spell.\n");
    if(!str)
      return notify_fail("Cure who?\n");

    if(str == "me" || str == "myself")
      ob = tp;
    else
      ob = present(str, environment(tp));
    if(!ob) {
        if(sscanf(str, "%s %s", whom, limb) != 2)
          return notify_fail("Correct syntax: <cure [who] [(limb)]\n");
        if(whom == "me" || whom == "myself")
          ob = tp;
        else
          ob = present(whom, environment(tp));
        }
    if(!ob)
      return notify_fail("Cure whom?\n");
    if(!ob->is_living() || ob->query_ghost())
      return notify_fail("Only the living can be cured.\n");

    clas = tp->query_subclass();
    healing = tp->query_skill("healing");
    healing += tp->query_level();
    if(clas == "cleric")
      healing += tp->query_skill("faith")/2;
    else
      healing += tp->query_skill("faith");


    if(!limb)
      cost = healing/4;
    else if(limb == "all")
      cost = healing/3; 
    else if(member_array(limb, ob->query_limbs()) == -1)
      return notify_fail(ob->query_cap_name()+" has no "+limb+"!\n");
    else 
      cost = healing/5;

    if(ob != tp) cost = random(cost);
    if(tp->query_mp() < cost)
      return notify_fail("Too low on magic power.\n");
    tp->add_mp(-cost);
    amount = (healing);
    this_player()->set_magic_round();
    tp->add_skill_points("healing", amount);
    if(tp != ob)
      tp->add_alignment(amount/5);
    if(!limb) {
      ob->add_hp(amount);
      send_messages(tp, ob, clas, 0);
      }
    else if(limb == "all") {
      limbs = (string *)ob->query_limbs();
      i = sizeof(limbs);
      while(i--) {
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
    return 1;
}

void send_messages(object tp, object ob, string clas, string limb) {
    string what, thing;
    if(clas == "cleric" || clas == "paladin") {
      thing = "prayer";
      what = "a prayer of healing";
      }
    else if(clas == "blue") {
      thing = "magic";
      what = "a spell of healing";
      }
    else {
      thing = "nonsense";
      what = "nonsense";
      }
    if(tp == ob) {
      message("info", "You cure your own wounds through "+thing+".", tp);
      message("info", tp->query_cap_name()+" mutters "+what+".", environment(tp), tp);
      }
    else {
      message("info", "You cure "+ob->query_cap_name()+"'s wounds through "+thing+".", tp);
      message("info", tp->query_cap_name()+" cures your wounds through "+thing+".", ob);
      message("info", tp->query_cap_name()+" mutters "+what+".", environment(tp), ({tp, ob}));
      }
}

int spell() {
   object tp;
   tp = this_player();
   if(tp->is_monster()) return 1;
   if(tp->query_level() < 20) return 0;
   if(tp->query_skill("healing") < 50) return 0;
   if(tp->query_subclass() != "cleric" && tp->query_subclass() != "paladin" && tp->query_subclass() != "blue") return 0;
   return 1;
}

void help() {
    write("
Syntax: <cure [player] [(limb)]>

Cures the player named to a degree depending on your skill level.
If no limb is given, it heals hp, otherwise it heals the limb named.
'all' is a valid argument for the limb.
");
}
