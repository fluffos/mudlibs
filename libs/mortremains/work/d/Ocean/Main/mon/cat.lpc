
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a catfish");
    set("prevent_summon" , 1);
    set ("long", @EndText
A nasty bottom-feeder. It's body is flat, with little whiskers
coming off it's face. 
EndText
    );
    set("id" , ({"fish" , "cat" , "catfish"}) );
    set_size(2);
    set_name("catfish");
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
    set_level(random(10)+5);
}
