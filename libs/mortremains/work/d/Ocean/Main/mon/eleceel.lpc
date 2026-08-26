
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "an electric eel");
    set("prevent_summon" , 1);
    set ("long", @EndText
A slimy slithering eel. His body crackles as the 
electricity runs through it.
EndText
    );
    set("id" , ({"fish" , "eel" , "electric eel"}) );
    set_size(4);
    set_name("electric eel");
    set("gender", "neuter");
    set("race" , "fish");
    set("damage_type","electricity");
    set("weapon_name" , "tail");
    set_verbs( ({"slap at" , "hit" , "smack at"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(15);
}
