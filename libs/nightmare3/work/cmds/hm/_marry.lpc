#include <std.h>

inherit DAEMON;

int cmd_marry(string str) {
    object ob1, ob2, ring;
    string who, whom;

    if(!archp(this_player()) && (string)this_player()->query_class() != "monk") {
	notify_fail("You do not have the power to wed people.\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 240) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(!str) {
         notify_fail("Syntax: marry <who> to <whom>\n"); /*Plura 930120*/
         return 0;
      }
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
    if(ob1->query_married() || ob2->query_married()) {
	notify_fail("Both partied must be unwed!\n");
	return 0;
    }
    if(archp(this_player())) {
        if(!creatorp(ob1) || !creatorp(ob2)) {
            message("my_action", "You can only marry immortals!",this_player());
            return 1;
        }
    }
    else this_player()->add_mp(-250);
    ob1->set_married(lower_case(whom));
    ob2->set_married(lower_case(who));
    ring = new("std/obj/wed_ring");
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
    write("Syntax: <marry [who] to [whom]>\n\n");
    write("This command allows a high mortal monk to marry two people.\n");
    write("This costs 250 magic points, to prevent unscrupulous monks from marrying\n");
    write("anyone without permission.  High mortal monks should develop\n");
    write("ceremonies based on game beliefs as monks (not RL beliefs)\n");
    write("This will make things more iteresting as far as marriage goes!\n");
}
