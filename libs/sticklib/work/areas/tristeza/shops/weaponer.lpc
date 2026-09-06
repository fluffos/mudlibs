#include <shop.h>
#include <npc_defs.h>
#include <areas.h>
#include <city_name.h>

int
shop_open()
{
    if (!present("boris", this_object()))
    {
	notify_fail("The shopkeeper is not here.\n");
	return 0;
    }

    return 1;
}


void
create_shop()
{
    set(IN_CITY);
    set(NO_PK);
    set_store(AREA_TRISTEZA+"shops/weaponer_store");
    set_short("Weaponsmith's shop");
    set_long("You are in the shop of the United Weaponsmiths of "
      + CITY_NAME+". A plaque hangs on the wall. You can also ask Boris to\
 'sharpen' or 'mend' or 'fix' a weapon, or have an 'offer' of its cost.");
    set_exits(([ "north" : AREA_TRISTEZA+"virtual/S3_7" ]));
    set_light_level(LT_LIGHTS);
    set_commands(([
	"sharpen" : "check_weapon",
	"sharp" : "check_weapon",
	"mend" : "check_weapon",
	"fix" : "check_weapon",
	"offer" : "check_weapon",
      ]));

    add_monster( ({ AREA_TRISTEZA+"npc/shopkeeper",
	({ "set_name", "Boris" }),
	({ "set_gender", G_MALE }),
	({ "set_id", ({ "shopkeeper", "boris",
	    "boris the shopkeeper" }) }),
	({ "set_short", "Boris the shopkeeper" }),
	({ "set_long", "Boris is an old, retired weaponsmith\
who takes care of the shop. He is bent and staggering, and constantly mumbles\
to himself." }),
	({ "set_dead_ob", this_object() })
      }), "Boris arrives.", 1 );
}

int
how_much(object ob)
{
    return (int) ob->query_orig_value() - (int) ob->query_value();
}

int
check_weapon(string str)
{
    object what;
    int cost;
    string wname;
    if (!str) return notify_fail(capitalize(query_verb())+" what?\n"), 0;
    if (!shop_open()) return 0;
    str = lower_case(str);
    what = present(str, this_player());
    if (!what) {
	this_player()->tell_me("You don't have "+str+".");
	return 1;
    }
    if (!(wname = (string) what->query_name(0, this_player())))
	wname = "<invisible weapon>";
    if (!what->is_weapon()) {
	this_player()->tell_me(capitalize(wname)+" is not a weapon.");
	return 1;
    }
    if (what->query_wielded()) {
	this_player()->tell_me("You must remove it first.");
	return 1;
    }
    if (what->query_blunt()) {
	this_player()->tell_me("Cannot sharpen "+wname
	  + ", it is a blunt weapon.");
	return 1;
    }
    if (!what->query_bluntness()) {
	this_player()->tell_me("It is sharp already.");
	return 1;
    }
    cost = how_much(what) * 3;
    if (query_verb() == "offer") {
	this_player()->tell_me("It costs "+cost+" gold coins.");
	tell_here((string) this_player()->query_name()
	  +" asked how much it would cost to sharpen "+wname+".");
	return 1;
    }
    if ((int) this_player()->query_money() < cost) {
	this_player()->tell_me("It costs "+cost
	  +" gold coins which you don't have.");
	return 1;
    }
    if (random(101) < (int) what->query_bluntness()) {
	this_player()->tell_me("Oh no! Your weapon broke when sharpened!");
	destruct(what);
	return 1;
    }
    this_player()->add_money(-cost);
    what->set_bluntness(0);
    this_player()->tell_me("Ok. "+capitalize(wname)+" is sharpened.");
    tell_here((string)this_player()->query_name()+" had "
      +wname+" sharpened.");
    return 1;
}

int
monster_died(mixed hilipati)
{
    (AREA_TRISTEZA+"shops/weaponer_store")->set_money(
      (int)(AREA_TRISTEZA+"shops/weaponer_store")->query_money()+10000);
    return 0;
}
