
#include <mudlib.h>

inherit WEAPON ;

void create() {
    seteuid(getuid() );
    set("author", "herself");
    set("id" , ({"nines" , "whip" , "nine tails" , "tails" }) );
    set("short" , "cat o' nine tails whip");
    set("long" , "A black handled weapon with nine thin leather\n"+
      "whips coming off the handle. \n");
    set_weapon_type("whip");
    set("name" , "nine tails");
    set_verbs( ({"whip" , "swat at" , "lash at" }) );
    set("nosecond", 0);
    set("value" , 200);
}

void init () {
    add_action("whip" , "whip");
}


int whip(string str) {
    object ob;
    if (!str) return 0;

    ob = present(str, environment(TP));
    if (!ob) {
	write ("Whip who? \n");
	return 1;
    }

    if (!living(ob)) {
	notify_fail ("That person is not here with you!\n");
	return 0;

    }
    write(wrap(
	"You snap your whip at "+ob->query("cap_name")+
	"'s rear end!\n"));

    say(
      TPN+" snaps her whip at "+ob->query("cap_name")+
      "'s rear end!\n", ({ ob }) );
    tell_object(ob,
      TPN+" snaps her whip at your rear end!\n"+
      "Wow does that sting!\n");
    return 1;
}
