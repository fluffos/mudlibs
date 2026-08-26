
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a stingray");
    set("prevent_summon" , 1);
    set ("long", @EndText
A flat triangle shaped animal. On the end of its tail
is a barbed stinger.
EndText
    );
    set("id" , ({"ray" , "stingray" , "fish"}) );
    set_size(3);
    set_name("stingray");
    set("gender", "neuter");
    set("race" , "fish");
    set("damage" , ({3, 5}) );
    set("damage_type" , "poison");
    set("weapon_name" , "stinger");
    set_verbs( ({"swipe at" , "slash at" , "sting"}) );
    set_verbs2( ({"swipes at" , "slashes at" , "stings"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(17);
}
