#include <room.h>
#include <areas.h>
#include <npc_defs.h>
#include <daemons.h>
#include <cloth_defs.h>
#include <city_name.h>



mixed inv;

#define INVNO 16

void makeinv();

void
create_room()
{
    set_short("Royal Tailor Shop");
    set_long("You are at the finest tailor of " CITY_NAME ", owned by the\
 Forrester family. You can see lots of ready clothes around ('list' if you\
 wish to see them), and perhaps you can also order custom-fitted handmade\
 clothing. You can of course 'value' and 'sell' clothing too. There is a\
 plaque on the wall.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(IN_CITY);
    set(NO_PK);
    set_exits(([ "east" : AREA_TRISTEZA+"virtual/S4_6" ]));
    set_commands(([
	"list"	: "list_cmd",
	"buy"	: "buy_cmd",
	"sell"	: "sell_cmd",
	"value"	: "value_cmd",
	"custombuy" : "buy_custom",
	"customvalue" : "buy_custom"
      ]));
    inv = ({ });
    //add_monster(AREA_TRISTEZA + "npc/guard_lieutenant", "Guard Lieutenant arrives.", 1);
    //add_monster(AREA_TRISTEZA+"npc/guard_captain", "Guard Captain arrives.", 1);
    add_monster( ({ AREA_TRISTEZA+"npc/shopkeeper",
	({ "set_name", "Mr. Forrester" }),
	({ "set_id", ({ "shopkeeper", "human", "tailor",
	    "mr. forrester", "Forrester", "forrester" }) }),
	({ "set_short", "Mr. Forrester, the Royal Tailor" }),
	({ "set_long", 
	  "Mr. Forrester is the most famous tailor of" + CITY_NAME +
	  ". Clothes designed and made by him are naturally very expensive." }),
	({ "set_gender", G_MALE })
      }), "Mr. Forrester arrives.", 1 );
}

void
init_room()
{
    string dummy;
    object ob;

    if ((ob = this_player()) && (!interactive(ob) && !ob->query_ctrl() &&
	(sscanf(object_name(ob), "areas/tristeza/%s", dummy) != 1)))
    {
	/* tell_room(this_object(), "No monsters allowed in shops!\n"); */
	ob -> run_away();
	return;
    }
}

int
read_cmd(string arg)
{
    if (!arg || lower_case(arg) != "plaque") return 0;
    this_player() -> tell_me("To buy custom-made clothing, use 'customvalue'\
 command first to see how much your purchase would cost. Then type 'custombuy\
 cloth name'. For example: 'custombuy perfect black silk robe'.\
 Note that custom clothes are quite expensive!");
    CLOTHING_D -> show_list();
    return 1;
}

int
check()
{
    if (!present( "shopkeeper", this_object() ))
    {
	notify_fail("You can't do that, because the shop keeper isn't here.\n");
	return 0;
    }
    if ((int) this_player() -> query_level() < 28 &&
      (int)this_player()->query_gender() != G_FEMALE) {
	this_player()->tell_me("Get away, peasant! We serve only\
 Barons and higher.");
	return 1;
    }
    makeinv();
    return 1;
}

int
buy_cmd(string arg)
{
    mixed ninv;
    object ob;
    int n, s, cost;

    if (!check()) return 0;
    s = sizeof(inv) / 3;
    if (!arg || !sscanf(arg, "%d", n)) return notify_fail(
	  "Buy which piece of clothing (1-" + s + ")?\n"), 0;

    if (n < 1 || n > s) return notify_fail(
	  "Huh? I got only " + s + " different pieces here.\n"), 0;

    n = (n - 1) * 3;
    cost = inv[n + 2];

    if ((int) this_player() -> query_money() < cost) return notify_fail(
	  capitalize(inv[n]) + " costs " + cost + " gp, you don't have enough cash.\n"), 0;

    if (!(ob = clone_object(CLOTH_FILE))) return notify_fail(
	  "Something is buggy here! Contact co-admin or admin!\n"), 0;

    this_player() -> add_money(-cost);
    this_player() -> tell_me("Ok. You buy " + inv[n] + ".");
    tell_here((string) this_player()->query_name() + " buys " + inv[n] + ".", this_player());
    ob -> set_name(inv[n + 1]);
    ob -> set_short(inv[n]);
    ob -> set_id(({ "cloth", explode(lower_case(inv[n]), " "), inv[n + 1] }));
    ob -> set_long("It's a brand new " + inv[n] + ".");
    ob -> set_weight((int) CLOTHING_D -> query_base_weight(inv[n + 1]));
    ob -> set_cloth_type(inv[n + 1]);
    ob -> set_value((cost * 3) / 4);
    if (!this_player() -> add_weight((int) ob -> query_weight())) {
	this_player() -> tell_me("Oops, it's too heavy. You drop it.");
	tell_here((string) this_player()->query_name() + " drops " + inv[n] + ".", this_player());
	move_object(ob, this_object());
    } else move_object(ob, this_player());
    if (n == 0) inv = inv[3 .. 999];
    else if (n == (INVNO - 4)) inv = inv[0 .. -4];
    else inv = (inv[0 .. (n - 1)] + inv[(n + 3) .. 999]);
    return 1;
}

int
buy_custom(string arg)
{
    object ob;
    mixed c;
    int cost;
    if (!arg) return notify_fail("Try '" + query_verb() + " quality color\
 material type', for example '" + query_verb() + " average white cotton socks'."), 0;

    if (!(c = (mixed) CLOTHING_D -> create_custom_cloth(arg))) return
	notify_fail("There can't be such clothing.\n"), 0;

    cost = ((c[2] * 4) / 3);
    if (query_verb() == "customvalue") {
	this_player() -> tell_me(capitalize(c[0]) + " would cost " + cost + " gold coins.");
	return 1;
    }
    if (!(ob = clone_object(CLOTH_FILE))) return notify_fail(
	  "Something is buggy here! Contact co-admin or admin!\n"), 0;

    if ((int) this_player() -> query_money() < cost) return notify_fail(
	  capitalize(c[0]) + " costs " + cost + " gp, you don't have enough cash.\n"), 0;

    this_player() -> add_money(-cost);
    this_player() -> tell_me("Ok. You buy " + c[0] + ", which costs " + cost + " gold.");
    tell_here((string) this_player()->query_name() + " buys " + c[0] + ".", this_player());
    ob -> set_name(c[1]);
    ob -> set_short(c[0]);
    ob -> set_long("It's a brand new " + c[0] + ".");
    ob -> set_weight((int) CLOTHING_D -> query_base_weight(c[1]));
    ob -> set_cloth_type(c[1]);
    ob -> set_value((c[2] * 3) / 4);
    if (!this_player() -> add_weight((int) ob -> query_weight())) {
	this_player() -> tell_me("Oops, it's too heavy. You drop it.");
	tell_here((string) this_player()->query_name() + " drops " + c[0] + ".", this_player());
	move_object(ob, this_object());
    } else move_object(ob, this_player());
    return 1;
}

int
sell_cmd(string arg)
{
    object *inv, ob, tp;
    int i, s, fart;
    string a;
    if (!check() || !(tp = this_player())) return 0;
    if (!arg) {
	inv = all_inventory(tp);
	fart = 0;
	if (inv && (s = sizeof(inv))) {
	    for (i = 0; i < s; i++) {
		if (inv[i] -> is_clothing()) {
		    fart++;
		    if (!a) a = "";
		    a += sprintf("\n%-40s: %7d gold",
		      capitalize((string) inv[i] -> query_name(0, tp)), (int) inv[i] -> query_value());
		}
	    }
	}
	if (!fart) tp->tell_me("You don't have anything to sell here.");
	else tp->tell_me("You could sell these things:" + a);
	return 1;
    }
    if (!(ob = present(lower_case(arg), tp))) return notify_fail(
	  "You don't carry any \"" + arg + "\".\n"), 0;

    if (!ob -> is_clothing()) return notify_fail(
	  "You can only sell clothes here.\n"), 0;

    this_player() -> tell_me("Ok. You sell " +
      (string) ob -> query_name(0, tp)
      + " for " + (int) ob -> query_value() + " gold coins.");
    tell_here((string) this_player()->query_name() + " sells " + (string) ob -> query_name() + ".", tp);
    tp -> add_money((int) ob -> query_value());
    tp -> add_weight(-((int) ob -> query_weight()));
    destruct(ob);
    return 1;
}

int
value_cmd(string arg)
{
    if (!check()) return 0;
    return sell_cmd(0);
}

void
makeinv()
{
    int i, s;
    mixed c;

    if (!inv) inv = ({ });
    if ((s = sizeof(inv) / 3) < INVNO) {
	for (i = 0; i < INVNO - s; i++) {
	    c = (mixed) CLOTHING_D -> create_random_cloth(100, 999999);
	    inv += ({ c[0], c[1], c[2] });
	}
    }
}

int
list_cmd(string arg)
{
    int i, s;
    string a;
    object tp;

    if (arg && arg != "clothes") return notify_fail("List what?\n"), 0;

    if (!check() || !(tp = this_player())) return 0;

    if (!(s = sizeof(inv) / 3))
    {
	tp->tell_me("Mr. Forrester says: Unfortunately we are sold out!");
	return 1;
    }

    a = sprintf("%2s. %-40s %6s", "No", "Name", "Cost");

    for (i = 0; i < s; i++)
    {
	a += sprintf("\n%2d. %-40s %6d", i + 1, capitalize(inv[i * 3]),
	  inv[i * 3 + 2]);
    }

    tp -> tell_me(a);
    return 1;
}
