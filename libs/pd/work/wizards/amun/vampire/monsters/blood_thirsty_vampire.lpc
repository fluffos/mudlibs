#include <std.h>
#include <vampq.h>
inherit BARKEEP;
void create() {
    ::create();
    set_name("Blood Thirsty Vampire");
    set("id", ({ "vampire", "monster", "thirsty vampire", "blood thirsty vampire" }) );
    set_level( 1000 );
    set("short", "Blood-thirsty Vampire" );
    set("long", "%^BOLD%^%^RED%^The vampire bares his teeth at travelers and blood can be seen dripping from them. He is wearing raggid clothes and he is standing behind the counter as if he works here, but there is something off about him.%^RESET%^" );
    set("race", "vampire" ); 
    set_gender( "male" );
    set_body_type("vampire");
    set_skill("melee", 1000);
    set_class("fighter");
    set_currency("gold");
    set_menu( ({"blood"}), ({"soft drink"}), ({25}) );
    set_menu_short(
      ({ "%^BOLD%^%^RED%^B%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood%^RESET%^" })
    );
    set_my_mess( ({ "You drink the blood and it slithers down your throat..MMM that tastes good.%^RESET%^\n" }) );
}
