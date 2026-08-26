/*
** File: gun.c
** Purpose: FUN!!
** Credits: Created by Herself on July 25, 2000
*/


#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author" , "herself");
    set_weapon_type("club");
    set("id" , ({"squirtgun" , "squirt gun" , "gun"}) );
    set("short" , "a squirt gun");
    set("long" , wrap(
	"A small plastic squirt gun. It never runs out of water. "));
    set("name" , "squirt gun");
    set("nosecond", 0);
    set("value" , 0);
    set("mass" , 1);
    set_verbs( ({"squirt" , "hit" , "bop"}) );
}     
void init() {
    add_action("squirt" , "squirt");
}

int squirt(string str) {
    object ob;
    if (!str) return 0;

    ob = present(str, environment(TP));
    if (!ob) {
	write("Squirt who?\n");

	return 1;
    }
    if (!living(ob)) {
	notify_fail ("That person isn't here.\n");
	return 0;
    }

    write(wrap(
	"You squirt "+ob->query("cap_name")+
	" with your squirt gun!\n"));

    say(
      TPN+" squirts "+ob->query("cap_name")+
      "with "+possessive(TP->query("gender"))+" squirt gun!\n");
    tell_object(ob,
      TPN+" squirts you with "+possessive(TP->query("gender"))+
      " squirt gun. Now you're all wet!!\n");
    return 1;
}

/* End of File */
