#include <std.h>

inherit OBJECT;

#define TP this_player()

int hatched;
object mon;

void create() {
    ::create();
    set_name("egg");
    set("id", ({"dragon egg", "egg"}) );
    set_short("A small oval egg");
    set_long("This egg is very rough as warm to the touch.  The egg vibrates as "
      "though something inside it moves.");
    hatched = 0;
}

void init() {
    add_action("cmd_hatch", "hatch");
    add_action("cmd_command", "command");
}

int cmd_hatch(string str) {

    if (!str || str != "egg") {
	return notify_fail("Hatch what?\n");
    }

    if (environment(TP)->query_property("indoors")) {
	return notify_fail("You can not hatch the egg here.");
    }

    if (hatched == 1) {
	return notify_fail("You have already hatched this egg.\n");
    }
    write("You hatch the egg, and a dragon appears.");
    hatched = 1;
    mon = new("/std/monster");
    mon->set_name("dragon");
    mon->set_id( ({ TP->query_name()+"_dragon", "dragon",
	"baby dragon" }) );
    mon->set_short("A baby dragon");
    mon->set_long("This baby dragon will fly you to a location.  The syntax is "
      "<command> dragon <location>.  This dragon was hatched "
      "by "+capitalize(TP->query_name())+".");
    if (random(5) > 1) {
	mon->set_gender("male");
    } else mon->set_gender("female");
    mon->set_level(1);
    mon->set_exp(0);
    mon->set_race("dragon");
    mon->set_body_type("dragon");
    mon->set_class("dragon");
    mon->set_subclass("blue");
    mon->move(environment(TP));
    return 1;
}

int cmd_command(string str) {
    string loc;

    if (!present(TP->query_name()+"_dragon", environment(TP))) {
	return notify_fail("Your dragon is not here to command.\n");
    }

    if (environment(TP)->query_property("indoors")) {
	return notify_fail("You can not fly here.\n");
    }

    if  (!str || sscanf(str, "dragon %s", str) != 1)
    {
	return notify_fail("Command dragon where?\n");
    }
    else {
	switch(str) {
	case "tirun": loc = "/d/nopk/tirun/square";
	    break;
	case "elven village": loc = "/d/nopk/standard/rain_forest/corinthor/rooms/square";
	    break;
	case "arlon": loc = "/d/nopk/arlon/room/square";
	case "tenebrae": loc = "/d/shadow/rooms/tene10";
	    break;
	case "lodos": loc = "/d/lodos/square";
	    break;
	case "roston": loc = "/d/roston/rooms/roston";
	    break;
	case "helgrath": loc = "/d/helgrath/rooms/wilndursquare";
	    break;
	case "merkkirri": loc = "/d/freepk/merkkerri/jungle/merkkirri/mjungle1";
	    break;
	default: write("You can not fly to that location.");
	}
    }

    if (loc) {
	write("The dragon heeds your request.");
	call_out("fly_loc", 6, str, loc);
    }
    return 1;
}

int fly_loc(string str, string loc) {
    write("You are swept off to "+capitalize(str)+".");
    TP->move_player(loc, "is swept off to "+capitalize(str)+".");
    mon->move(environment(TP));
    write("Your dragon flies away.");
    mon->remove();
    call_out("remove_egg", 3);
    return 1;
}

int remove_egg() {
    if (hatched == 1) {
	write("Your egg fades away.");
	this_object()->remove();
	return 1;
    }
}

int bury() {
    write("You have to keep this egg.");
    return 1;
}

int query_auto_load() {
    if (TP->query_guild() == "Dragon Warriors") {
	return 1;
    }
}
