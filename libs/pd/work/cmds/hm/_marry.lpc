#include <std.h>

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_class() == "clergy" &&
      tp->query_level() >= 20)
        return 1;
  return 0;
}

string type() { return "other"; }

int cmd_marry(string str) {
    object ob1, ob2, ring;
    string who, whom;

    if (!abil()) return 0;

    if((int)this_player()->query_mp() < 240) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(!str) {
         notify_fail("Syntax: marry <who> to <whom>\n"); /*Plura 930120*/
         return 0;
      }
// this is seeker callin inferno a moron =p it doesnt belong here
//
//    if (ob1->is_monster() || ob2->is_monster()) {
//      return notify_fail("You cannot marry monsters.\n"); // Inferno
//    }
    if(sscanf(str, "%s to %s", who, whom) != 2) return 0;
    ob1 = present(who, environment(this_player()));
    ob2 = present(whom, environment(this_player()));
    if(!ob1 || !ob2) {
	notify_fail("Both parties must be present to be wed!\n");
	return 0;
    }
    if(ob1 == ob2) {
        notify_fail("That's weird.\n");
	return 0;
    }
      if (ob1->is_monster() || ob2->is_monster()) {
      return notify_fail("You cannot marry monsters.\n"); // Inferno
    }
    if (!ob1->is_player() || !ob2->is_player())
      return notify_fail("Only players may be wed.\n");
    if(ob1->query_married() || ob2->query_married()) {
	notify_fail("Both parties must be unwed!\n");
	return 0;
    }
    this_player()->add_mp(-250);
    ob1->set_married(lower_case(whom));
    ob2->set_married(lower_case(who));
    ring = new("/std/obj/wed_ring");
    ring->set_me(lower_case(who));
    ring->set_spouse(lower_case(whom));
    ring->move(ob1);
    ring = new("/std/obj/wed_ring");
    ring->set_me(lower_case(whom));
    ring->set_spouse(lower_case(who));
    ring->move(ob2);
    write("You pronounce "+capitalize(who)+" and "+capitalize(whom)+" united in marriage.\n");
    shout(capitalize(who)+" and "+capitalize(whom)+" are now united in marriage!\n");
    return 1;
}

void help() {
    write("Syntax: <marry [who] to [whom]>\n");
    write("This command allows a high mortal clergy to marry two people.");
    write("This costs 250 magic points, to prevent unscrupulous clergy from marrying");
    write("anyone without permission.  High mortal clergy should develop");
    write("ceremonies based on game beliefs as clergy (not RL beliefs)");
    write("This will make things more interesting as far as marriage goes!");
}
