#include <room.h>
#include <npc_defs.h>
#include <areas.h>
#include <daemons.h>
#include <cloth_defs.h>



mixed inv;

#define TP this_player()
#define TNAME (string)TP->query_name()
#define INVNO 16

void makeinv();

void
create_room()
{
    set_short("Simo's Clothroom");
    set_long("You are in Simo's Clothroom, which, unlike Mr. Forrester,\
sells mainly basic everyday clothing. You can see lots of ready clothes around\
 ('list' if you wish to see them). You can also 'value' and 'sell' clothes.");
    set_light_level(LT_LIGHTS);
    set_exits(([ "west" : AREA_TRISTEZA+"virtual/S4_6" ]));
    set_commands(([
	"list"	: "list",
	"buy"	: "buy",
	"sell"	: "sell",
	"value"	: "value",
      ]));
    //  add_monster(AREA_TRISTEZA + "npc/guard_lieutenant",
    //    "Guard Lieutenant arrives.", 1);
    // add_monster(AREA_TRISTEZA+"npc/guard_captain", "Guard Captain arrives.", 1);
    add_monster( ({ AREA_TRISTEZA+"npc/shopkeeper",
	({ "set_name", "Simo" }),
	({ "set_id", ({ "shopkeeper", "human", "tailor", "simo" }) }),
	({ "set_short", "Simo the Clothroom owner" }),
	({ "set_long", "This stout fellow sells only relatively cheap\
 clothing, for the common folk." }),
	({ "set_gender", G_MALE }),
	({ "set_alignment", AL_GOOD })
      }), "Simo arrives.", 1 );
}

void
init_room()
{
    string dummy;
    object ob;
    string tmp, tmp2;

    if ((ob = this_player())
      && (ob != present("shopkeeper", this_object())) && ob->query_npc() &&
      sscanf(object_name(ob), "%s/tristeza/%s", tmp, tmp2) < 2 )
	call_out("throw_out", 0, this_player());
}

void
throw_out(object o)
{
    if (o && environment(o) == this_object() && 
      present( "shopkeeper", this_object())) {
	tell_here("Simo says: No monsters allowed in shops!", o);
	o -> run_away();
    }
}

int
check()
{
    if (!present("shopkeeper", this_object()) )
    {
	notify_fail(
	  "You can't do that, because the shop keeper isn't here.\n");
	return 0;
    }
    makeinv();
    return 1;
}

int
buy(string arg)
{
    mixed ninv;
    object ob;
    int n, s, cost;
    string my_name;

    if (!check()) return 0;
    s = sizeof(inv) / 3;
    if (!arg || !sscanf(arg, "%d", n)) return notify_fail(
	  "Buy which piece of clothing (1-" + s + ")?\n"), 0;
    if (n < 1 || n > s) return notify_fail(
	  "Huh? I got only " + s + " different pieces here.\n"), 0;
    n = (n - 1) * 3;
    cost = inv[n + 2];
    if ((int) TP -> query_money() < cost) {
	this_player()->tell_me(capitalize(inv[n]) + " costs " + cost
	  + " gp, you don't have enough cash.");
	return 1;
    }
    ob = clone_object(CLOTHING_FILE);
    if (!ob) return notify_fail(
	  "Something is buggy here! Contact co-admin or admin!\n"), 0;
    TP -> add_money(-cost);
    my_name = (string) this_player()->query_name();
    this_player() -> tell_me("Ok. You buy " + inv[n] + ".");
    tell_here(my_name + " buys " + inv[n] + ".", TP);
    ob -> set_name(inv[n + 1]);
    ob -> set_short(inv[n]);
    ob -> set_id(({ "cloth", explode(lower_case(inv[n]), " "), inv[n + 1] }));
    ob -> set_long("It's a brand new " + inv[n] + ".");
    ob -> set_weight((int) CLOTHING_D -> query_base_weight(inv[n + 1]));
    ob -> set_cloth_type(inv[n + 1]);
    ob -> set_value((cost * 3) / 4);
    if (!TP -> add_weight((int) ob -> query_weight())) {
	this_player() -> tell_me("Oops, it's too heavy. You drop it.");
	tell_here(my_name + " drops " + inv[n] + ".\n", ({ TP }));
	move_object(ob, this_object());
    } else move_object(ob, TP);
    if (!n) inv = inv[3 .. 999];
    else if (n == (INVNO - 4)) inv = inv[0 .. -4];
    else inv = (inv[0 .. (n - 1)] + inv[(n + 3) .. 999]);
    return 1;
}

int
sell(string arg)
{
    object *inv, ob;
    int i, s, fart;
    string txt;

    if (!check()) return 0;
    if (!arg) 
    {
	inv = all_inventory(TP);
	fart = 0;
	if (inv && (s = sizeof(inv)) > 0) 
	    for (i = 0; i < s; i++) 
		if (inv[i] -> is_clothing()) 
		{
		    if (!fart++) txt = "You could sell these things:";
		    this_player() -> tell_me(sprintf("\n%-40s: %7d gold", capitalize
			((string) inv[i] -> query_short()), (int)
			inv[i] -> query_value()));
		}
	if (!fart) 
	{
	    this_player()->tell_me("You don't have anything to sell here.");
	    return 1;
	}
	else
	{
	    this_player()->tell_me(txt);
	    return 1;
	}
    }
    if (!(ob = present(lower_case(arg), TP))) return notify_fail(
	  "You don't carry any \"" + arg + "\".\n"), 0;

    if (!ob -> is_clothing()) {
	this_player()->tell_me("You can only sell clothes here.");
	return 1;
    }

    this_player() -> tell_me("Ok. You sell " + (string) ob -> query_short()
      + " for " + (int) ob -> query_value() + " gold.");
    tell_here((string)this_player()->query_name() + " sells "
      + (string) ob -> query_short()+ ".", this_player());
    TP -> add_money((int) ob -> query_value());
    TP -> add_weight(-((int) ob -> query_weight()));
    destruct(ob);
    return 1;
}

int
value(string arg)
{
    if (!check()) return 0;
    return sell(0);
}

int
list(string arg)
{
    int i, s;
    string txt;
    if (!check()) return 0;
    s = sizeof(inv) / 3;
    txt = sprintf("%2s. %-40s %6s", "No", "Name", "Cost");
    for (i = 0; i < s; i++)
	txt += sprintf("\n%2d. %-40s %6d", i + 1, capitalize(inv[i * 3]),
	  inv[i * 3 + 2]);
    this_player()->tell_me(txt);
    return 1;
}

void
makeinv()
{
    int i, s;
    mixed c;

    if (!inv) inv = ({ });
    if ((s = sizeof(inv) / 3) < INVNO) {
	for (i = 0; i < INVNO - s; i++) {
	    c = (mixed) CLOTHING_D -> create_random_cloth(0, 120);
	    inv += ({ c[0], c[1], c[2] });
	}
    }
}
