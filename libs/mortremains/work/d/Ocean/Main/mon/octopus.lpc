
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a giant octopus");
    set("prevent_summon" , 1);
    set ("long", @EndText
This is a huge octopus. His eyes are the size of 
dinner plates, and hit tentacles look about 10 feet long!
EndText
    );
    set("id" , ({"octopus" , "pus" , "octo"}) );
    set_size(9);
    set_name("octopus");
    set("gender", "neuter");
    set("race" , "cephalopod");
    set("damage" , ({1, 2}) );
    set("natt" , 8);
    set("weapon_name" , "tentacles");
    set("damage_type" , "crushing");
    set_verbs( ({"squeeze" , "grab" , "entwine"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(22);
}
