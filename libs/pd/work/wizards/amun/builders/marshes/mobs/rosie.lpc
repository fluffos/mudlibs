#include <std.h>
#include <amun.h>
inherit BARKEEP;
void create() {
    ::create();
    set_name("Rosie");
    set("id", ({ "rosie", "monster" }) );
    set_level( 500 );
    set("short", "Rosie" );
    set("long", "Rosie is currently the barmaid here at the pub, but she was once a great warrior. After helping rid the marsh of the dragon, she did some work in Hamen's Tomb. She has a red hour-glass along her stomach and the rest of her hair is pure black." );
    set("race", "raknid" ); 
    set_gender( "female" );
    set_body_type("raknid");
    set_class("fighter");
    set_currency("gold");
    set_skill("bargaining", 90);
    set_menu( ({"frozen mist", "murky water", "marsh mallow"}), ({"drink", "drink", "drink"}), ({ 25, 25, 25}) );
    set_menu_short(
      ({
	"%^BOLD%^%^CYAN%^Frozen Mist",
	"%^RESET%^%^ORANGE%^Murky %^RESET%^Water",
	"%^BOLD%^%^BLACK%^Marsh Mallow",
      })
    );
    set_my_mess(
      ({
	"The frozen mist gives you a head rush as it slides down your throat.\n",
	"You down the murkey water and notice it has a strong bite!\n",
	"Letting the marsh mallow expand slightly in your mouth, you begin to choke then swallow.\n",
      })
    );
}
