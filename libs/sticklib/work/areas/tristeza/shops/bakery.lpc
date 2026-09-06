/****************************************************************
*								*
*	Main Town Bakery;  /areas/tristeza/shops/bakery.c	*
*								*
*	Version 2.0						*
*								*
*	Last modifications 05-dec-94 by Doomdark.		*
*								*
*	7-Apr-95: Graah: Added tinning service			*
*	9-Mar-96: Germ: Moved from /room/shop.c			*
*								*
*	27-aug-98, Doomdark: Modified for StickLib.		*
****************************************************************/

#include <room.h>
#include <areas.h>
#include <city_name.h>
#include <generic_items.h>
#include <corpse_defs.h>

inherit "/lib/food_shop";

#define TIN_COST 300

void
init_foods()
{
    /* ids, short, strength, weight, cost, long desc, eat msg, said msg */
    foods = ({
      ({ "bread", "loaf", "rye" }), "Loaf of rye bread",
      10, 2, 55,
      "This is a loaf of " CITY_NAME "n rye bread.",
      "Munch munch munch...dry, but tasty!",
      " eats a loaf of bread.",

      ({ "jerky", "beef", "strip" }), "Strip of beef jerky",
      15, 1, 90,
      "This is a strip of salty beef jerky. Horse meat, perhaps?",
      "Chew chew chew...tough, but delicious!",
      " chews a strip of beef jerky.",

      ({ "bread", "waybread", "slice" }), "Slice of waybread",
      20, 1, 300,
      "While this is not Elvish waybread, it still is the best single\
 foodstuff you can get. A single slice will keep a man going for\
 a long time.",
      "Chomp munch mum yum...yum! Tasty stuff!",
      " eats a slice of waybread."
    });
}

void
create_shop()
{
    set_short("Royal Baker of " CITY_NAME);
    set_long(
      "The best food shop in " CITY_NAME ", Royal Baker, has these foods for sale:\n\n"+
      list_foods(0) +
      sprintf("\n%-30s %6d\n", "Preservation of a corpse", TIN_COST) +
      "\nYou can 'fill bag' (or any container) with breads - or with some other\
 food: for example 'fill bag with jerky'. If you want to make canned\
 corpse, use 'tin corpse'. Tins give twice more heal than plain \
corpses - if you are able to eat corpses at all.");

    set_light_level(LT_DIM);
    set(NO_PK);
    set(ROOM_WD, WD_INDOORS);
    set_exits(([ "north" : AREA_TRISTEZA+"virtual/S9_7",
	"west"  : AREA_TRISTEZA+"virtual/S8_8" ]));
    // add_monster(AREA_TRISTEZA + "npc/guard_lieutenant",
    //   "Guard Lieutenant arrives.", 1);
    // add_monster(AREA_TRISTEZA+"npc/guard_captain", "Guard Captain arrives.", 1);
    add_monster( ({ AREA_TRISTEZA+"npc/shopkeeper",
	({ "set_name", "baker" }),
	({ "set_id", ({ "baker", "shopkeeper" }) }),
	({ "set_short", "Baker" }),
	({ "set_race", "hobbit" }),
	({ "set_long", "The baker is a fat, merry hobbit.\
 He is wiping flour from his hands." }),
	({ "set_random_pick", 0 })
      }), "Baker arrives.", 1 );
}

void
init_room()
{
    object o;

    if (!interactive(o = this_player()) &&
      o && environment(o) == this_object() &&
      o->query_name() != "baker" &&
      !this_player()->id("city_guard") &&
      !this_player()->query_ctrl())
	call_out("throw_out", 0, o);
    // Call out used since we don't want to throw it out before arrive msg gets
    // printed!!!

    add_action("tin_cmd", "tin");
    add_action("tin_cmd", "can");
}

void
throw_out(object who)
{
    if (!present("shopkeeper", this_object()) ||
      environment(who) != this_object()) return;

    // Coded this way so we get "Baker says... Baker throws Foobar out.",
    // and also, players in the other room get "Foobar arrives."

    if (who->id("shopkeeper")) return;
    tell_here("Baker says: No monsters allowed!\nBaker throws ", who, 1);
    who->move_player("north#"+AREA_TRISTEZA+"virtual/S9_7");
}

status
tin_cmd(string str)
{
    object material;
    object tin, *inv;
    string sh, tmp, tmp1;
    int i;

    if (!present("shopkeeper", this_object()))
	return notify_fail("There is no one to serve you here.\n"), 0;

    if (!str)
	return notify_fail("What did you want to get canned?\n"),0;

    str = lower_case(str);

    material = present(str, environment(this_player()));

    if (material == this_player() || (!material && (str == "me" || str == "myself")))
    {
	this_player()->tell_me("What?!??! Make a tin of yourself? *LAUGH*");
	tell_here((string)this_player()->query_name() + " tries to get " +
	  (string)this_player()->Objective() +
	  "self canned, but fails.\n", this_player());
	material = 0;
	return 1;
    }

    /* Must not carry the corpse; too hard to check weights... */
    if (!material)
    {
	material = present(str, this_player());
	if (material) {
	    notify_fail("Place " + (string)material->short() +
	      " on the ground first.\n");
	    material = 0;
	    return 0;
	}
    }

    // Who forgot to check an important thing such as this? //Bull
    if(!material) {
	return notify_fail("There is nothing like that around.\n"),0;
    }

    if (living(material))
    {
	this_player()->tell_me((string)material->query_name()+" doesn't let you do that!");
	environment(this_player())->tell_here((string)this_player()->query_name() +
	  " tries to get "+(string)material->query_name() +
	  " canned, but the latter doesn't allow it.\n",({material,this_player()}));
	material->tell_me((string)this_player()->query_name() +
	  " tries to get you canned!");
	material = 0;
	return 1;
    }

    /* Todo: tinning other foodstuff? */

    if (sscanf(object_name(material), (CORPSE_FILE)[1..<1]+"#%s", tmp) != 1)
    {
	notify_fail("Baker says: We can't preserve this material.\n");
	material = 0;
	return 0;
    }

    if ((int)material->query_decay() < 2)
    {
	notify_fail("Baker says: That stiff is too old to be preserved.\n");
	material = 0;
	return 0;
    }

    if ((int)this_player()->query_money() < TIN_COST)
    {
	this_player()->tell_me("Baker exclaims: \
 It would cost you " + TIN_COST + " gold coins, which you don't have!");
	return 1;
    }

    this_player()->add_money(-(TIN_COST));

    tmp = (string)material->query_short();
    if (!tmp) tmp = "something invisible";

    this_player()->tell_me("Ok.");
    tell_here("The baker preserves " + tmp + ".");

    sh = capitalize((string)material->query_orig_name());

    if (sscanf(sh, "Ghost of %s", tmp1) == 1) sh = tmp1;

    switch(random(7))
    {
    case 0: sh += " meat"; break;
    case 1: sh += " soup"; break;
    case 2: sh = "pickled " + sh; break;
    case 3: sh += " jam"; break;
    case 4: sh = "marinaded " + sh; break;
    case 5: sh = "sour " + sh; break;
    default: sh = "deep fried " + sh; break;
    }

    /* Create the tin */
    tin = clone_object(GENERIC_TIN);
    tin->set_short("Tin of " + sh);
    tin->set_long("This is a normal tin of " + sh + ", made at the Baker's.\
 This kind of preserved food never spoils unless opened.");
    tin->set_id(({lower_case(sh),"tin"}));

    i = (int)material->query_orig_level();
    i -= -(4 * ((int)material->query_decay() - 5));
    tin->set_tin_level(i);
    tin->set_tin_strength_baker(i);

    /* Make tins worth only a little. Would allow cheats otherwise... */
    tin->set_value(1);

    /* Move material's inventory outside it */
    inv = all_inventory(material);
    for (i = 0; i < sizeof(inv); i++)
	if (!inv[0]->drop()) move_object(inv[i], environment(material));

    destruct(material);

    material = 0;

    if (!this_player()->add_weight(tin->query_weight()))
    {
	move_object(tin, environment(this_player()));
	this_player()->tell_me("Oops, you fumbled with the " + (string)tin->query_short() +
	  ". Dropped.");
	tell_here((string)this_player()->query_name() + " fumbled with the " + 
	  (string)tin->query_short() + " and drops it.\n", this_player());
    } else {
	move_object(tin, this_player());
	this_player()->tell_me("You get the " + (string)tin->query_short() + ".");
	tell_here((string)this_player()->query_name() + " gets a " + 
	  (string)tin->short() + ".\n", this_player());
    }

    return 1;
}
