
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "an eel");
    set("prevent_summon" , 1);
    set ("long", @EndText
A slimy slithering eel. 
EndText
    );
    set("id" , ({"eel"}) );
    set_size(3);
    set_name("eel");
    set("gender", "neuter");
    set("race" , "fish");
    set("damage" , ({3, 5}) );
    set("weapon_name" , "tail");
    set_verbs( ({"slap at" , "hit" , "smack at"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(13);
}
