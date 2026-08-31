#include <std.h>
#include <guild.h>
#include <boat.h>
inherit BARKEEP;
void create() {
    ::create();
    set_property("no bump", 1);
    set_name("Mick");
    set_id( ({ "mick", "monster" }) );
    set_level( 25 );
    set_short( "Mick" );
    set_long( "Mick is a short gremlin that keeps watch over the pub. Usually he sits on a stool behind the bar, but today he is walking around looking for things that are not there." );
    set_race( "gremlin" ); 
    set_gender( "male" );
    set_body_type("gremlin");
    set_class("rogue");
    set_currency("gold");
    set_skill("bargaining", 90);
    set_menu_header("The following drinks are served at the GT Bar:");
    set_menu_footer("<buy drink_name> gets you a drink.");
    set_menu( ([
	"mick's moonshine" : ([
	  "type" : "alcoholic",
	  "strength" : 60,
	  "long" : "%^BOLD%^%^BLACK%^Mick's Moonshine%^RESET%^",
	  "my_mess" : "%^BOLD%^%^BLACK%^The moonshine numbs your throat and you wince at the taste!%^RESET%^",
	  "your_mess" : "winces as the moonshine numbs their throat!"
	]),
	"boiling brew" : ([
	  "type" : "alcoholic",
	  "strength" : 20,
	  "long" : "%^RESET%^%^RED%^Boiling Brew%^RESET%^",
	  "my_mess" : "%^BOLD%^%^RED%^Your throat engulfs into flames as you suck down the brew!%^RESET%^",
	  "your_mess" : "sheds a tear as their throat is engulfed in flames!"
	]),
	"risky rum" : ([
	  "type" : "alcoholic",
	  "strength" : 30,
	  "long" : "%^RESET%^%^ORANGE%^Risky Rum%^RESET%^",
	  "my_mess" : "%^RESET%^%^ORANGE%^The rum slides nicely down your throat and calms your nerves.%^RESET%^",
	  "your_mess" : "sighs happily as the rum hits the spot!"
	])
      ]) );
}
