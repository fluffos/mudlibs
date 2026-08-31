#include <std.h>
inherit BARKEEP;

create() {
 ::create();
   set_property("no bump", 1);
   set_name("tempest");
   set_id( ({ "tempest", "barkeep" }) );
   set_short("Tempest");
   set("aggressive", 0);
   set_level(17);
   set_long("A swirling mass of mist and liquid surrounds Tempest. Tempest is "
	"the barkeep of the Spider's Web. The elemental makes drinks here all "
	"night and day long.");
   set_gender("neuter");
   set_alignment(-122);
   set("race", "elemental");
   set_hp(500);
   add_money("gold", random(200));
   set_body_type("human");
   set_currency("gold");
   set_menu(
	({
	"venom", "wine", "shot", "rage"
	}),
	({ "alcoholic", "alcoholic", "alcoholic",  "alcoholic" }),
	({ 15, 12, 17, 28 })
    );
    set_my_mess(
	({
	"You swallow the vemon and feel the burn enter your blood stream.",
	"As you drink the wine, your vision blackens for a moment.",
	"You choke down the horrible taste of Ontex and cough.",
        "The full force of Tempest's Rage sends you sprawling to the ground!"
	})
    );
    set_your_mess(
	({
	"swallows spider venom and gets a pale white face.",
	"drinks Black Wine, and gets cloudy eyes for a moment.",
	"chokes on the harsh taste of Ontex.",
        "is sent sprawling to the ground from Tempest's Rage!"
    	})
    );
    set_menu_short(
	({
	"Spider Venom",
	"Black Wine",
	"a Shot of Ontex",
        "Tempest's Rage",
	})
    );
    set_menu_long(
	({
	"A thin, greenish liquid. It doesn't exactly look healthy.",
	"The black liquid in the glass is Tempest's Black Wine.",
	"A shot of a powerful drink created by the Tirunian bartender, Tempest.",
        "The strongest alcoholic beverage created in the Spyder's Web."
   	})
    );
}
