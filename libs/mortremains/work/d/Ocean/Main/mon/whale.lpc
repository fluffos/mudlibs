
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a killer whale");
    set("prevent_summon" , 1);
    set ("long", @EndText
A monstrous beast who rules the deep ocean. His body is
solid black with a thin white stripe.
EndText
    );
    set("id" , ({"whale" , "killer" , "killer whale" , "shamu"}) );
    set_size(25);
    set_name("shamu");
    set("gender", "neuter");
    set("race" , "orca");
    set("damage" , ({3,8}) );
    set("weapon_name" , "tail");
    set_verbs( ({"slap at" , "hit" , "swing at" , "pummel"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(random(24)+3);
}
