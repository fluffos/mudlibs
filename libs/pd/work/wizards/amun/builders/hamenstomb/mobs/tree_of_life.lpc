#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Tree of Life");
    set("id", ({ "tree", "monster", "tree of life" }) );
    set_level( 55 );
    set("short", "%^RESET%^%^ORANGE%^Tree of %^BOLD%^WHITE%^Life" );
    set("long", "%^RESET%^%^ORANGE%^The Tree of %^BOLD%^%^WHITE%^Life %^RESET%^%^ORANGE%^stands before you.  It seems to be staring at you as you approach it.%^RESET%^" );
    set("race", "plant" ); 
    set_gender( "female" );
    set_body_type("plant");
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(1, ({"%^RESET%^%^ORANGE%^Tree of %^BOLD%^WHITE%^Life %^RESET%^%^ORANGE%^moves as if it is alive."}), 0);
    set_emotes(20, ({"%^RESET%^%^ORANGE%^Tree of %^BOLD%^WHITE%^Life %^RED%^SMASHES %^RESET%^%^ORANGE%^you with his branches!"}), 1);
    new(WEP+"great_branch")->move(this_object());
    force_me("wield branch");
}
