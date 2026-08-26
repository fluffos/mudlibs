
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a water leaper");
    set("prevent_summon" , 1);
    set ("long", @EndText
A strange looking creature who haunts these parts. 
He has a long pointed tail, and wings as if he could
fly. His body is toad-like. 
EndText
    );
    set("id" , ({"leaper" , "water leaper" , "water"}) );
    set_size(10);
    set_name("leaper");
    set("gender", "neuter");
    set("race" , "demon");
    set("lore_type" , "demon");
    set("damage" , ({3,5}) );
    set("weapon_name" , "claws");
    set_verbs( ({"slash at" , "claw at" , "rip" , "tear into"}) );
    set_verbs2( ({"slashes at" , "claws at" , "rips" , "tears into"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(21);
}
