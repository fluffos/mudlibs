/* NOTE:
   I disabled the services here because they're buggy and not worth the money.
   -Nulvect
*/

#include <lodos.h>
#include <std.h>
inherit ROOM;
int myRead(string str);
void create() {
    ::create();
    set_short("A place of health");
    set_long("The tiles on the walls and floor are a pale "
      "maroon color. Sunlight splashes down upon you, "
      "though there are no openings from which it could "
      "have come in. A churning, light red pool sits "
      "in the center of the room.");
    set_listen("default", "A strange quiet floods this place.");
    set_items(([ "pool" : "The pool is a bubbling light red color",
	//"list" : "Maybe you could read it?"
      ]));
    set_properties((["light" : 2, "no attack" : 1, "no steal" : 1,
	"no bump" : 1 ]));
    set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
    set_exits(([ "north" : ROOMS"temple8" ]));
}
int myRead(string str) {
    if (str != "list") return 0;
    write(
      "%^CYAN%^[-]============= { %^RESET%^Arial's Healing Center %^CYAN%^} ===============[-]\n"
      "%^YELLOW%^             Service               Syntax                 Gold\n%^RESET%^"
      "               -+-                   -+-                   -+-\n"
      "      -+-   resurrect   -+-<resurrect for [person]>-+-   25000\n"
      "      -+-     cure      -+-     <cure [person]>     -+-   700\n"
      "      -+-     heal      -+-     <heal [person]>     -+-   300\n"
      "      -+-     boost     -+-    <boost [person]>     -+-   250\n"
      "      -+-    replace    -+-    <replace [limb]>     -+-   900\n"
      "      -+-    purify     -+-    <purify [person]>    -+-   200\n");
    write("Note: To buy a service: <buy [service (syntax)]>\n"
      "To resurrect player named bob type: <buy resurrect for bob>\n"
      "Replace always assumes you as the target, but you enter "
      "the limb you wish to have replaced. The rest of the "
      "services target another living creature in the same room.");
    return 1;
}
int buy(string str) {
    string oi;
    object ob;
    int mon;
    ob = present("arial", this_object());
    mon = this_player()->query_money("gold");
    if (!ob) return 0;
    if (sscanf(str, "purify %s", oi)) {
	if (mon < 200) {
	    ob->force_me("say You do not have enough money.");
	    return 1;
	}
	ob->force_me("purify "+oi);
	this_player()->add_money("gold", -200);
	return 1;
    }
    if (sscanf(str, "replace %s", oi)) {
	if (mon < 900) {
	    ob->force_me("say You do not have enough money.");
	    return 1;
	}
	this_player()->add_money("gold", -900);
	ob->force_me("replace "+this_player()->query_name()+" "+oi);
	return 1;
    }
    if (sscanf(str, "boost %s", oi)) {
	if (mon < 250) {
	    ob->force_me("say You do not have enough money.");
	    return 1;
	}
	this_player()->add_money("gold", -250);
	ob->force_me("boost "+oi);
	return 1;
    }
    if (sscanf(str, "heal %s", oi)) {
	if (mon < 300) {
	    ob->force_me("say You do not have enough money.");
	    return 1;
	}
	this_player()->add_money("gold", -300);
	ob->force_me("heal "+oi);
	return 1;
    }
    if (sscanf(str, "cure %s", oi)) {
	if (mon < 900) {
	    ob->force_me("say You do not have enough money.");
	    return 1;
	}
	this_player()->add_money("gold", -900);
	ob->force_me("cure "+oi);
	return 1;
    }
    if (sscanf(str, "resurrect for %s", oi)) {
	ob = find_living(oi);
	if (!oi) {
	    write("Could not find "+oi);
	    return 1;
	}
	if (mon < 25000) {
	    present("arial", this_object())->force_me("say You do not have enough money.");
	    return 1;
	}
	if (!ob->query_ghost()) {
	    write("That person is already alive.");
	    return 1;
	}
	this_player()->add_money("gold", -25000);
	tell_room(environment(this_player()), "%^YELLOW%^Arial raises her hands and prays for the resurrection of "+oi, ({ }));
	ob->revive();
	ob->fix_vital_bonus();
	ob->add_hp(100);
	ob->add_sp(100);
	ob->add_mp(100);
	ob->set_heart_beat(1);
	ob->set_heal_rate(2);
	return 1;
    }
    write("Syntax: <buy [service]>");
    return 1;
}
void init() {
    ::init();
  /*
    add_action("myRead", "read");
    add_action("buy", "buy");
  */
}
void reset() {
    ::reset();
    if (!present("arial"))
	new(MOB"arial")->move(this_object());
}
