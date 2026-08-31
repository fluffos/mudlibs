#include <std.h>

inherit BARKEEP;

create() {
 ::create();
   set_property("no bump", 1);
   set_name("dexter");
   set_id( ({ "dexter", "barkeep" }) );
   set_short("Dexter, the barkeep");
   set_level(22);
   set_long("Dexter sits behind the counter serving drinks all day. "
     "He is excelent at mixing drinks.");
   set_gender("male");
   set_alignment(172);
   set("race", "gnome");
   add_money("silver", random(600));
   set_body_type("human");
   set_currency("gold");
   set_menu(({
	"whiskey", "ale", "spirits", "pretzel", "special"
	}),
	({ "alcoholic", "alcoholic", "alcoholic", "food", "alcoholic" }),
        ({  25, 2, 26, 1, 30})
    );
    set_my_mess(
	({
        "You swallow the whiskey and wince.",
        "The ale goes down smooth.",
        "The spirits hit you hard.",
        "Very dry and salty.",
        "You stumble around from the special of the house."
	})
    );
    set_your_mess(
	({
	"swallows some sour whiskey and winces.",
        "quickly downs some watered down ale.",
        "stumbles around a bit.",
        "munches on pretzel.",
        "drinks a special of the house and stumbles around in a drunken haze."
    	})
    );
    set_menu_short(
	({
        "whiskey sour",
	"wattered down ale",
	"glass of spirits",
        "pretzel",
        "special of the house"
	})
    );
    set_menu_long(
	({
        "A shot of whiskey sour.",
        "The drink for those who can't take the heat.",
        "A glass of various hard alcohols.",
        "The pretzel doesn't look very filling.",
        "Made with great skill by the barkeep of The Dull and Rusty. Its ingredients are secret to all."
   	})
    );
}
