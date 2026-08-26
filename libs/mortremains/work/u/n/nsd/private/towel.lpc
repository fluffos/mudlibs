/*
** File: towel.c
** Author: Lady Nsd
** Special thanks: Nightmask helped here big deal. Thanks babe :)
*/

#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());

    set ("id", ({ "towel" }) ) ;
    set ("short", "a clean white towel") ;
    set ("long", "A clean white towel ready for your use."+
      " You can 'wear' it,\n"+
      "'dry' your partner, or yourself by typing 'dryme'.\n"+
      "And if you feel like it, you can also 'snap' a buddy!!\n");

    set_armor_type("robes");
}
void init() {
    add_action("dry", "dry");
    add_action("dryme", "dryme");
    add_action("snap", "snap");
}
int dryme(string str) {
    say(TPN+" dries "+POSS+" body with the towel.\n");
    write("You dry your body with the towel.\n");
    return 1;
}
int dry (string str) {
    object ob;
    if (!str) return 0;
    ob = present(str, environment(TP));
    if(!ob) {
	write("Dry who?\n");
	return 1;
    }
    if (!living(ob)) {
	notify_fail ("That player is not in the room.\n");
	return 0;
    }
    write(
      "You dry "+ob->query("cap_name")+"'s body"+
      " with the towel.\n");
    say(TPN+" dries "+ob->query("cap_name")+"'s body"+
      " with the towel.\n", ({ ob }) );
    tell_object(ob,
      TPN+" dries your body with the towel.\n");
    return 1;
}
int snap (string str) {
    object ob;
    if (!str) return 0;
    ob = present(str, environment(TP));
    if(!ob) {
	write("Who you want to snap?\n");
	return 1;
    }
    if (!living(ob)) {
	notify_fail ("That player is not in the room.\n");
	return 0;
    }
    write(wrap(
	"You snap "+ob->query("cap_name")+"'s butt"+
	" with the towel. "+ob->query("cap_name")+" grabs "+
	objective(ob->query("gender"))+"self in gesture\n"+
	"of pain. Damn, you're an evil fuck.. heh heh\n"));
    say(TPN+" snaps "+ob->query("cap_name")+"'s butt"+
      " with the towel. "+TPN+" is an evil fuck.\n", ({ ob }) );
    tell_object(ob, wrap(
	TPN+" snaps your butt with the towel. You grab yourself\n"+
	"in gesture of pain. Isn't "+TPN+" an evil fuck??\n"));
    return 1;
}
