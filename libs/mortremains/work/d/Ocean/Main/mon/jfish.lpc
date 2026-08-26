
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a jellyfish");
    set("prevent_summon" , 1);
    set ("long", @EndText
A pulsating mass. It's tenticles swing around 
lazily... 
EndText
    );
    set("id" , ({"fish" , "jellyfish" }) );
    set_size(1);
    set_name("jellyfish");
    set("gender", "neuter");
    set("race" , "fish");
    set("damage" , ({1, 2}) );
    set("weapon_name" , "tenticles");
    set("damage_type" , "poison");
    set_verbs( ({"swing at" , "swipe at" , "lash at"}) );
    set_verbs2( ({"swings at" , "swipes at" , "lashes at"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(13);
}
