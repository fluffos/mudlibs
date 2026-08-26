/*
** File: image.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "@@query_short") ;

    set ("long", @EndText
Your image on the mirrors!
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"image"}) );
    set_size(6);
    set_name("image");
    set("gender", "neuter");
    set("race", "image");
    set("lore_type", "arcanology");
    set("prevent_summon",1);
    set("undead", 0);
    set("damage", ({5,8}) );
    set("weapon_name", " ? ");
    set_verbs( ({ "attack", "swing at", "peer at", "knock" }) ) ;
    set("natt",1);
    set("chat_chance", 30);
    set("chat_output", ({
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
    }) );
    set("wealth", 200);
    set_level(10);
    arm("?", "?");
    wear("?", "?");
}
string query_short() {
    object ob = query_current_attacker();
    string str;

    if (ob) {
	str = "image of "+ob->query("cap_name");
    } else {
	str = "an image";
    }

    return str;

    /*
	// string str = "image of "query_current_attacker()""
	string str = query_current_attacker()->query("name");
	return "image of "+str;
    */
}
void die() {
    say(wrap(
	"Your image winks out and ceases behaving by itself...\n"));
    ::die() ;
    return ;
}
/* End of File */
