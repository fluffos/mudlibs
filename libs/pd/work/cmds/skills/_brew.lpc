#include <std.h>
#include <dirs.h>

#define TEA_OB DIR_CLASS_CMDS+"/obj/brew_tea_ob"

inherit DAEMON;

int abil();

string type() { return "other"; }

int cmd_brew(string str) {
    object ob;
    string type;

    if (!abil()) {
	return 0;
    }
    if(!str) {
	notify_fail("Brew what?\n");
	return 0;
    }
    if(this_player()->query_disable()) {
	write("You are too busy doing something else!");
	return 1;
    }
    this_player()->set_disable();
    if(!present("brewpot",this_player())) {
	notify_fail("You do not have anything to brew in!\n");
	return 0;
    }
    if(!present("campfire",environment(this_player()))) {
	notify_fail("You have no way to cook it!\n");
	return 0;
    }
    if(!present(str,this_player())) {
	notify_fail("You do not have that!\n");
	return 0;
    }
    if (!present(str, this_player())->query_property("brewable"))
      return notify_fail("You cannot brew that!\n");
    write("You sit down and brew yourself some tea.");
    say(this_player()->query_cap_name()+" sits down and begins brewing something.");
    type = present(str, this_player())->query_type();
    ob = new(TEA_OB);
    switch(type) {
      case "healing": ob->set_strength(25); ob->set_my_mess(ob->query_my_mess()+"\nYou feel better."); break;
      case "poison": ob->set_poisoned(30); ob->set_my_mess(ob->query_my_mess()+"\nYou feel nauseous."); break;
      case "antidote": ob->set_my_mess(ob->query_my_mess()+"\nYou feel a tingling sensation."); break;
    }
    ob->set_property("tea_type", type);
    ob->set_id( ob->query_id() + ({ type, type+" tea" }) );
    if (ob->move(this_player())) ob->move(environment(this_player()));
    present(str,this_player())->remove();
    return 1;
}

void help() {
    write("Syntax: <brew [herb]>\n\n"
      "Rangers can use herbs that they have foraged for to\n"
      "brew potent teas with different effects.\n"
    );
}

int abil() {
    if(this_player()->query_subclass() != "ranger") return 0;
    if(this_player()->query_skill("nature") < 90) return 0;
    return 1;
}
