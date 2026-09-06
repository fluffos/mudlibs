#include "../DEFS.h"

#include <npc_defs.h>
#include <city_name.h>

inherit TRISTEZA_ROOM_C;

object harry;		// Variables for Harry
int count;
string *chat_str, *a_chat_str;
string *func, *type, *match;

void
notify(string s)
{
    if (harry) environment(harry)->tell_here(s, harry);
}

status
read_cmd(string str)
{
    if (str != "map") return 0;
    this_player()->tell_me(query_long(str, this_player()));
    return 1;
}

void
inform(string s)
{
    if (harry) environment(harry) -> tell_here(s, harry);
}

void
reset_room()
{
    if (!harry) {
	if (!chat_str) {
	    chat_str = ({
	      "Harry says: What are you waiting for?",
	      "Harry says: Hello there!",
	      "Harry says: I don't like winter.",
	      "Harry says: I don't like snow.",
	      "Harry says: I don't like rain.",
	      "Harry says: Who are you?",
	      "Harry says: Why do you look like that?",
	      "Harry says: What are you doing here?",
	      "Harry says: Nice weather, isn't it?",
	      "Harry says: Nice to meet you; my name is Harry; Harry P. Ness!",
	      "Harry says: I like children!",
	      "Harry smiles."
	    });
	    a_chat_str = ({
	      "Harry says: Don't hit me!",
	      "Harry says: That hurt!",
	      "Harry says: Help, someone!",
	      "Harry says: Why can't you go bullying elsewhere?",
	      "Harry says: Aooooo!",
	      "Harry says: I hate bashers!",
	      "Harry says: Bastard!",
	      "Harry says: You big brute!"
	    });

	    func = allocate(12);
	    type = allocate(12);
	    match = allocate(12);

	    func[0] = "why_did";
	    type[0] = "sells";
	    type[1] = "attack";
	    type[2] = "left";
	    match[2] = "the game";
	    type[3] = "takes";
	    type[4] = "drops";
	    func[5] = "how_does_it_feel";
	    type[5] = "is now level";
	    func[6] = "smiles";
	    type[6] = "smiles";
	    match[6] = " happily.";
	    func[7] = "say_hello";
	    type[7] = "arrives";
	    func[8] = "test_say";
	    type[8] = "says:";
	    type[9] = "tells you:";
	    func[10] = "follow";
	    type[10] = "leaves";
	    func[11] = "gives";
	    type[11] = "gives";
	}
	harry = clone_object(NPC_FILE);
	// Reuse the same arrays.
	harry -> load_chat(2, chat_str);
	harry -> load_a_chat(20, a_chat_str);
	harry -> set_match(this_object(), func, type, match);
	harry -> set_name("harry");
	harry -> set_id(({ "harry the affectionate", "Harry" }));
	harry -> set_short("Harry the affectionate");
	harry->set_long(
	  "He is a respected elder citizen of " CITY_NAME ", Harry P. Ness.\
 Somehow he gives you the creeps, though you can't say\
 why...");
	harry -> set_level(3);
	harry -> set_alignment(AL_NICE);
	harry->set_wander(8);
	harry->set_gender(G_MALE);

	harry -> set_random_pick(20);

	harry -> move_player("foo", this_object());
	add_monster(harry, 0, 0);
    }
}

void
create_room()
{
    ::create_room();
    set_short("Market Square, at Well and Gallows");
    set_long("You are standing at the center of market square, which is\
 also the center point of " + CITY_NAME + ". Two major roads, Main Street and\
 Newbie Road cross here. At the exact center of the city stands the City\
 Gallows. This is also the location of the city Well.\n\
A map of " + CITY_NAME + " is nailed into the Well. Suddenly you \
notice a new-looking rope ladder going straight up. A building seems \
to be floating above the city!");
    set_exits(([
	"north"	: CITY_DIR + "S7_6",
	"northeast" : CITY_DIR + "S8_6",
	"east"	: CITY_DIR + "S8_7",
	"southeast" : CITY_DIR + "S8_8",
	"south"	: CITY_DIR + "S7_8",
	"southwest" : CITY_DIR + "S6_8",
	"west"	: CITY_DIR + "S6_7",
	"northwest" : CITY_DIR + "S6_6",
	"up": CITY_PATH + "shops/fcafe",
	"down" : WELL
      ]));
    set_items(([
	"well" : "A wishing well. Guaranteed to fulfill your wishes. A map is nailed to it.",
	"gallows" : "It's a traditional wooden gallows. A lever is used to operate the trapdoor.",
	"map" : lambda(({ 'map, 'looker }), ({ #'read_file, MAP_FILE }))
      ]));
add_command("throw", "throw");
reset_room();
}

status
throw(string str)
{
    int amount;
    object tp, well;

    if (str != "coin" && str != "coins") return 0;
    tp = this_player();
    if ((int) tp -> query_money() < 1) {
	this_player()->tell_me("You wish you had a coin...");
	return 1;
    }
    this_player()->tell_me("You throw a coin in the wishing well.");
    tell_here(capitalize((string)tp->query_name()) +
      " throws a coin in the wishing well.", this_player());
    tp -> add_money(-1);
    (WELL) -> coin_drop();
    return 1;
}


status
test_if_valid_who(string who) {
    object ob;
    // Let's make Harry less annoying to higher players
    if (!(ob = present(lower_case(who),environment(harry))) ||
      (int) ob->query_level() > 14) return 0;
    return 1;
}

void
why_did(string str)
{
    string who, what;
    int i;
    i = sizeof(str) - 1;
    if (str[i..i] == "\n")
	str = str[0..i-1];
    if (sscanf(str, "%s %s", who, what) < 2 || !test_if_valid_who(who))
	return;
    if (sscanf(str, "%s sells %s.", who, what) == 2)
	inform("Harry says: Why did you sell " + what + "?");
    else if (sscanf(str, "%s attacks %s.", who, what) == 2)
	inform("Harry says: Why does " + who + " attack " + what + "?");
    else if (sscanf(str, "%s left the game.", who) == 1)
	inform("Harry says: Why did " + who + " quit the game?");
    else if (sscanf(str, "%s takes %s.", who, what) == 2)
	inform("Harry says: Why did " + who + " take " + what + "?");
    else if (sscanf(str, "%s drops %s.", who, what) == 2)
	inform("Harry says: Why did " + who + " drop " + what + "?");
}

void
how_does_it_feel(string str)
{
    string who, what;
    if (sscanf(str, "%s %s", who, what) < 2 || !test_if_valid_who(who))
	return;
    if (sscanf(str, "%s is now level %s.", who, what) == 2)
	inform("Harry says: How does it feel, being of level "+what+"?");
}

void
smiles(string str)
{
    string who, what;
    if (sscanf(str, "%s %s", who, what) < 2 || !test_if_valid_who(who))
	return;
    if (sscanf(str, "%s smiles happily.", who) == 1 && who != "Harry")
	notify("Harry smiles happily.");
}

void
say_hello(string str)
{
    string who;
    if (sscanf(str, "%s arrives.", who) < 1 || !test_if_valid_who(who))
	return;
    notify("Harry says: Hi " + who + ", nice to see you!");
}

void
test_say(string str)
{
    string a, b, message;
    if (sscanf(str, "%s %s", a, b) < 2 || !test_if_valid_who(a))
	return;
    if (sscanf(str, "%s says: %s", a, b) < 2) return;

    str = b;

    if (str == "hello" || str == "hi" || str == "hello everybody")
	message = "Harry says: Pleased to meet you!";
    else if (str == "shut up")
	message = "Harry says: Why do you want me to shut up?";
    else if (sscanf(str, "%sstay here%s", a, b) == 2 ||
      sscanf(str, "%snot follow%s", a, b) == 2 ||
      sscanf(str, "%sget lost%s", a, b) == 2) {
	message = "Harry says: Ok then... :-(";
    }
    if (!message && !random(3))
	message = "Harry says: Why do you say '" + str + "'???";
    notify(message);
}

void
follow(string str)
{
    string who, where;
    object ob;
    if (sscanf(str, "%s leaves %s.\n", who, where) == 2) {
	ob = find_living(lower_case(who));
	if(ob && !ob->query_coder_level() && (int) ob->query_level() < 15)
	    harry -> init_command(where);
    }
}

void
gives(string str)
{
    string who, what, whom, s;
    int rand;
    object obj, next_obj;
    if (sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3 ||
      !test_if_valid_who(who))
	return;
    if (whom != "you") return;
    if (what == "firebreather" || what == "special" ||
      what == "beer" || what == "bottle") {
	rand = random(4);
	if (!rand) {
	    if (random(10) > 6) {
		notify("Harry sighs and says: I guess you're gonna kill me now.");
		obj = first_inventory(harry);
		while(obj) {
		    next_obj = next_inventory(harry);
		    move_object(obj, environment(harry));
		    if (!s) s = "";
		    else s += "\n";
		    s += "Harry drops " + (string) obj -> query_name() + ".";
		    obj = next_obj;
		}
		notify("Harry sighs and says: I guess you're gonna kill me now."
		  + (s ? s : ""));

		harry -> init_command("west");
	    }
	}
	else if (rand == 1)
	    harry -> init_command("drink " + what);
	else if (rand == 2) {
	    obj = first_inventory(harry);
	    while (!obj -> id(what))
		obj = next_inventory(obj);
	    move_object(obj, environment(harry));
	    notify("Harry drops the " + what + ".");
	} else {
	    obj = first_inventory(harry);
	    while(!obj -> id(what))
		obj = next_inventory(obj);
	    move_object(obj, find_living(lower_case(who)));
	    notify("Harry returned the " + what + " to " + who + ".");
	}
    } else if(what == "corpse") {
	notify("Harry says: HEY, bury your corpses yourself, asshole.");
	obj = first_inventory(harry);
	while (!obj->id(what))
	    obj = next_inventory(obj);
	move_object(obj, find_living(lower_case(who)));
	notify("Harry returned the " + what + " to " + who + ".");
    } else {
	notify("Harry says: Thank you very much, "+who+"!");
    }
}

void
monster_died()
{
    object obj, b;
    int num;
    obj = first_inventory(harry);
    while (obj) {
	b = next_inventory(obj);
	if (obj -> id("bottle")) {
	    destruct(obj);
	    num = 1;
	}
	obj = b;
    }
    if (num) tell_here("There is a crushing sound of bottles breaking,\
 as the body falls.");
}
