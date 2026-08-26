
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a sea anemone");
    set("prevent_summon" , 1);
    set ("long", @EndText
This creature looks like a beautiful flower, but
beware... its sting can be deadly.
EndText
    );
    set("id" , ({"fish" , "anemone" , "sea anemone"}) );
    set_size(1);
    set_name("sea anemone");
    set("gender", "neuter");
    set("race" , "fish");
    set("damage" , ({1, 2}) );
    set("natt" , 2);
    set("weapon_name" , "tenticles");
    set("damage_type" , "poison");
    set_verbs( ({"swing at" , "swipe at" , "lash at"}) );
    set_verbs2( ({"swings at" , "swipes at" , "lashes at"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(12);
}
