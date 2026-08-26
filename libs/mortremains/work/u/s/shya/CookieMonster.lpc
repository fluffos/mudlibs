//Created June 11, 2000 by Shya //

#include <mudlib.h>
inherit MONSTER;

void create() {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "shya");
    set("long", "A Blue Cookie Monster with a handful of cookies to 'toss'.\n");
    set("short", "Cookie Monster");
    set ("id", ({"monster", "cookie", "cookie monster"}) );
    set_name("Cookie Monster");
    set ("gender", "male") ;
    enable_commands() ;
    set ("chat_chance", 30);
    set ("chat_output", ({
        "Cookie Monster starts singing.\n",
        "'Cookie cookie cookie starts with C.'\n",
        "'C is for cookie that's good enough for me.'\n",
        "'C is for cookie that's good enough for me.'\n",
        "'Cookie cookie cookie starts with C.'\n"
       }) );
}
void init() {
    add_action("toss_func", "toss");   
}
int toss_func(string str) {
    string name;
    object target;

    if (!str) {
	return 0;
    }

    if (sscanf(str, "%s at %s", str, name) != 2) {
	return 0;
    }

if (str!="cookie") {
	return 0;
    }

    target = find_player(name);
    if (!target) {
	write("There's no player named "+capitalize(name)+
	  " on the mud!\n");
	return 1;
    }

 write("Your Cookie Monster tosses cookies at "+target->query("cap_name")+" with a mighty scream.\n");
say("Shya's Cookie Monster tosses some cookies.\n");
    tell_object(target, wrap(
    "Shya's Cookie Monster tosses some cookies at you." 
    ) );
    return 1;
}

