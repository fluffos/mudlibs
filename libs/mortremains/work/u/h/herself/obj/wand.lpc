/*
** This is Herself's personal magic wand. 
** Created July 15, 2000
*/


#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author" , "herself");
    set_weapon_type("quarterstaff");
    set("id" , ({"wand" , "magic wand" }) );
    set("short" , "magic wand");
    set("long" , wrap(
	"A magical wand. It sparkles with pixie dust.") );
    set("name" , "wand");
    set("nosecond", 0);
    set("value" , 0);
    set("mass" , 1);
    set_verbs( ({"point at" , "strike at" , "zap"}) );
}     
void init() {
    add_action("brush" , "brush");
}

int brush(string str) {
    object ob;
    if (!str) return 0;

    ob = present(str, environment(TP));
    if (!ob) {
	write ("Brush what?\n");

	return 1;
    }
    if (!living(ob)) {
	notify_fail ("That person isn't here.\n");
	return 0;
    }

    write(wrap(
	"You brush "+ob->query("cap_name")+
	"'s hair with your brush.\n"));

    say(
      TPN+" brushes "+ob->query("cap_name")+
      "'s hair with "+possessive(TP->query("gender"))+" brush.\n");
    tell_object(ob,
      TPN+" brushes your hair with "+possessive(TP->query("gender"))+
      " brush. Now you look all pretty. \n");
    return 1;
}

/* End of File */
