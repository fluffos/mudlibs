#include <shop.h>
#include <npc_defs.h>
#include <areas.h>

#define TP this_player()

int
shop_open()
{
    if ( !present("halic", this_object()) )
    {
	notify_fail("The shopkeeper is not here.\n");
	return 0;
    }
    return 1;
}

void
create_shop()
{
    set_store(AREA_TRISTEZA+"shops/armourer_store");
    set(NO_PK);
    set(IN_CITY);
    set_short("Halic's Armour Shop");
    set_long(
      "You are in the armour shop; only armours are sold and bought here. You can\
 also ask Halic to 'mend' or 'fix' your armours, or get an 'offer' of costs.\
\nA plaque hangs on the wall, which is painted with sickly green and\
 pink colours for some reason.");
    set_exits(([ "south" : AREA_TRISTEZA+"virtual/S3_7" ]));
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    // add_monster(AREA_TRISTEZA + "npc/guard_lieutenant",
    //   "Guard Lieutenant arrives.", 1);
    // add_monster(AREA_TRISTEZA+"npc/guard_captain", "Guard Captain arrives.", 1);
    add_monster( ({ AREA_TRISTEZA+"npc/shopkeeper",
	({ "set_name", "Halic" }),
	({ "set_id", ({ "keeper","shopkeeper","armour shop keeper",
	    "shop keeper","halic","halic the armour shop keeper" }) }),
	({ "set_gender", G_MALE }),
	({ "set_short", "Halic the armour shop keeper" }),
	({ "set_dead_ob", this_object() }),
	({ "set_long",
	  "Mr. Halic (first names Anence P.) inherited the Armour Shop from her aunt.\
Halic has bulging eyes, hands which twitch all the time and he drools on the\
floor and the armours he sells constantly. His hair is bright yellow,\
skin very pale and eyes bright blue." }),
	({ "load_chat", 1, ({"Halic drools on you."}) })
      }),
      "Halic says: Oh, I'm very sorry you had to wait, I was having a coffee break!", 1 );
}

/* Reward killing of shopkeeper: he returns with more money. */
int
monster_died(mixed hilipati)
{
    (AREA_TRISTEZA+"shops/armourer_store")->set_money(
      (int)(AREA_TRISTEZA+"shops/armourer_store")->
      query_money() + 10000);
    return 0;
}

void init_shop() {
    add_action("check_armour","mend");
    add_action("check_armour","fix");
    add_action("check_armour","offer");
}

/* Armourer can now mend armours that have taken damage. 28.3.1993 //Frobozz */

how_much(ob) {
    return ob->query_orig_value() - ob->query_value();
}

check_armour(str) {
    object what;
    int cost,damage;
    if(!str) {
	notify_fail(capitalize(query_verb()) + " what?\n");
	return 0;
    }
    if(!shop_open()) return 0;
    str=lower_case(str);
    what=present(str,TP);
    str=capitalize(str);
    if(!what) {
	TP->tell_me("You don't have "+str+".");
	return 1;
    }
    if(!what->is_armour()) {
	TP->tell_me(str+" is not an armour.");
	return 1;
    }
    if(what->query_worn()) {
	TP->tell_me("You must remove it first.");
	return 1;
    }
    if(!what->query_damage()) {
	TP->tell_me("It is not damaged.");
	return 1;
    }
    cost=how_much(what)*3;
    if(query_verb()=="offer") {
	TP->tell_me("It costs "+cost+" gold coins.");
	environment(TP)->tell_here(TP->query_name()
	  +" asked how much it would cost to mend "+str+".");
	return 1;
    }
    if(TP->query_money()<cost) {
	TP->tell_me("It costs "+cost+" gold coins which you don't have.");
	return 1;
    }
    if(random(101)<(damage=what->query_damage())) {
	TP->tell_me("Oh no! "+str+" broke!");
	destruct(what);
	return 1;
    }
    TP->add_money(-cost);
    what->add_damage(-damage);
    TP->tell_me("Ok. "+capitalize(str)+" is mended.");
    environment(TP)->tell_here(TP->query_name()+" had "+str+" mended.");
    return 1;
}
