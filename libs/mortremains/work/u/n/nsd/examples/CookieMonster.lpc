//Created June 11, 2000 by Shya //
inherit OBJECT;

void create() {
    set("author", "shya");
    set("long", @EndText
A Blue Cookie Monster with a handful of cookies to 'toss'.
EndText);
    set("short", "Cookie Monster");
    set("id", ({ "monster", "cookie monster", "cookie", 
    }) );
}

void init() {
    add_action("toss_func", "toss");   
}
int toss_func(string str) {
    string name;
    object target;

    if (!str) {
 write("Toss cookie at who?\n");
	return 1;
    }

    if (sscanf(str, "%s at %s", str, name) != 2) {
 write("Who do you want to toss a cookie at?\n");
	return 1;
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

 write("Your Cookie Monster tosses cookies at "+target->query("cap_name"));
say("A Cookie Monster tosses some cookies.\n");
    tell_object(target, wrap(
    "Shya's Cookie Monster tosses some cookies at you." 
    ) );
    return 1;
}

