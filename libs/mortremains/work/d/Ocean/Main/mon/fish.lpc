
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a fish");
    set("prevent_summon" , 1);
    set ("long", @EndText
A small generic fish. It swims around happily.
EndText
    );
    set("id" , ({"fish"}) );
    set("moving" , 1);
    set("speed" , 4);
    set_size(1);
    set_name("fish");
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
    set_level(12);
}
string query_min(string dir) {
    if (!dir || dir=="") dir = "somewhere";

    dir = TON+" swims in from the "+dir+".";
    return dir;
}

string query_mout(string dir) {
    if ( dir == "" || dir == 0 ) dir = "somewhere";
    dir = TON+" swims "+dir+".";

    return dir;
}
