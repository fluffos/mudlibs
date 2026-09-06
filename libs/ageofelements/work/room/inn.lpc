#include <mxp.h>

/* this constant should be 1 for new games */
#define FOODS 1
#define Level this_player()->query_level()
#define Name this_player()->query_name()
#define Speak(s) write("Innkeeper says: "+s+"\n")

inherit "/lib/room";

int cm = FOODS * 4;
int mm = FOODS * 2;
int rmm = FOODS;

string last_eater;

string show_menu() {
    string menu;

    if (!(cm || mm || rmm)) {
	menu = "Innkeeper says: We have completely sold out. Please return later!";
    } else {
	menu =  sprintf("1: %sCommoner's Meal%s     %d at 20 gold\n", MXPTAG("send 'buy 1'"), MXPTAG("/send"), cm);
	menu += sprintf("2: %sMerchant's Meal%s     %d at 50 gold\n", MXPTAG("send 'buy 2'"), MXPTAG("/send"), mm);
	menu += sprintf("3: %sRich Person's Meal%s  %d at 90 gold\n", MXPTAG("send 'buy 3'"), MXPTAG("/send"), rmm);
	menu += sprintf("4: %sA Mug of Beer%s         at  2 gold\n", MXPTAG("send 'buy 4'"), MXPTAG("/send"));
	menu += sprintf("\n");
	menu += sprintf("Use 'buy <number>' to buy the desired menu item.\n");
	menu += sprintf("The food will be consumed at once. Bon appetite!");
    }

    return menu;
}

void create_room() {
    set_lumens(1);

    set_brief("Eastroad Inn");

    set_description(sprintf(
	"You are in the Eastroad Inn. Here you can buy food to still your "
	"hunger, but only a limited selection is available on the %smenu%s."
      , MXPTAG("send 'look at &text;' HINT='look at menu'"), MXPTAG("/send")));

    add_exit("east", "/room/eastroad5");

    add_item("menu", #'show_menu);

    set_commands( ([
	"buy": "buy"
	, "order": "buy"
      ]) );
}

void reset_room() {
    cm = FOODS * 4;
    mm = FOODS * 2;
    rmm = FOODS;
}

string query_description() {
    return sprintf("%s\n\n%s", ::query_description(), funcall(#'show_menu));
}

int no_food() {
    Speak("Sorry - we have sold out of that.");

    if (cm || mm || rmm) {
	Speak("Why don't you try something else?");
    } else {
	Speak("Why don't you come back later?");
    }

    return 1;
}

int pays(int n) {
    if (this_player()->query_money() < n) {
	Speak("You cannot afford that.");
	return 0;
    }

    this_player()->add_money(-n);

    return 1;
}

int tease(int n) {
    if (Name == last_eater) {
	Speak("My, my! Are we hungry today?.");
    }

    last_eater = Name;
    this_player()->heal_self(n);

    return 1;
}

int buy(string s) {
    if (!s) {
	Speak("What do you want to buy?");
	return 1;
    }

    /* commoner's meal, price 20, heals 4, preferably for levels 1-6 */
    if (s=="1" || s=="<1>") {
	if (!cm) {
	    return no_food();
	}

	if (!pays(20)) {
	    return 1;
	}

	if (Level > 6) {
	    Speak("You don't look like a commoner to me.");

	    if (mm || rmm) {
		Speak("You should eat food more suited for you.");
		return 1;
	    }

	    Speak("But as we have no better food - here you are.");
	}

	write("You are served a commoner's meal. Very nourishing!\n");
	say(Name+" orders a commoner's meal.\n");

	cm = cm - 1;

	return tease(4);
     }

    /* merchant's meal, price 50, heals 8, preferably for levels 7-12 */
    if (s == "2" || s == "<2>") {
	if (!mm) {
	    return no_food();
	}

	if (!pays(50)) {
	    return 1;
	}

	if (Level > 12) {
	    Speak("You look more like a rich person to me.");

	    if (rmm) {
		Speak("You should eat food more suited for you.");
		return 1;
	    }

	    Speak("But as we have no better food - here you are.");
	}

	write("You are served a merchant's meal. Very good!\n");
	say(Name+" orders a merchant's meal.\n");

	mm = mm - 1;

	return tease(8);
    }

    /* rich person's meal, price 90, heals 12, preferably for levels 13+ */
    if (s == "3"|| s == "<3>") {
	if (!rmm) {
	    return no_food();
	}

	if (!pays(90)) {
	    return 1;
	}

	write("You are served a rich person's meal. Very delicious!\n");
	say(Name+" orders a rich person's meal.\n");

	rmm = rmm - 1;

	return tease(12);
    }

    if (s == "4" || s == "<4>" || s == "mug" || s == "beer") {
	if (!pays(2)) {
	    return 1;
	}

	if (!this_player()->drink_alcohol(2)) {
	    Speak("You look a little too drunk for that. Let me take it back.");
	    this_player()->add_money(2);
	    return 1;
	}

	write("You drink a mug of first class beer. That feels good!\n");
	say(Name+" drinks a beer.\n");
	return 1;
    }

    Speak("We have no such number on the menu, try 1, 2, 3 or 4.");
    return 1;
}
