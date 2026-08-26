
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a seahorse");
    set("prevent_summon" , 1);
    set ("long", @EndText
A tiny creature with a somewhat horse-like head. 
Along it's body are little spines which look like 
thorns. 
EndText
    );
    set("id" , ({"seahorse" , "horse"}) );
    set_size(1);
    set_name("seahorse");
    set("gender", "neuter");
    set("race" , "fish");
    set("damage" , ({1, 2}) );
    set("weapon_name" , "tail");
    set_verbs( ({"slap at" , "hit" , "smack at"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(14);
}
