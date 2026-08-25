//      /bin/high_mortal/_create.c
//      from the Nightmare mudlib
//      The power of creation for mages
//      created by Descartes of Borg 02 march 1993
//      fixed directories Bohemund of New Hampshire 19 march 1994
//      Lowered values somewhat 09 July 94 - Zaknaifen of Approval
 
#include <std.h>
 
inherit DAEMON;
 
object make_it(string what, int x);
object do_weapon(int x);
object do_armour(int x);
 
int cmd_create(string str) {
    int cost, can;
    object ob;
 
    if(!str) {
	notify_fail("Create what?\n");
	return 0;
    }
    if((int)this_player()->query_skill("conjuring") < 90) {
	notify_fail("You are not quite adept enough at conjuring.\n");
	return 0;
    }
    if(environment(this_player())->query_property("no magic")) {
	notify_fail("A supernatural force prevents your magic.\n");
	return 0;
    }
    if(str != "weapon" && str != "armour" && str != "bag") {
	notify_fail("You cannot create that!\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 70) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    this_player()->add_mp(-70);
    say(this_player()->query_cap_name()+" utters a spell of conjuring.\n");
    can = (int)this_player()->query_skill("conjuring");
    can -= random(101);
    if(can < 0) {
	write("You fail to create anything.\n");
	return 1;
    }
    ob = make_it(str, can);
    if(ob->move(this_player())) {
	write("You drop "+ob->query_short()+".\n");
	say(this_player()->query_cap_name()+" drops "+ob->query_short()+".\n");
	ob->move(environment(this_player()));
    }
    write("You create a "+(string)ob->query_name()+".\n");
    say(this_player()->query_cap_name()+" creates a "+(string)ob->query_name()+".\n");
    this_player()->add_skill_points("conjuring", random(100));
    return 1;
}
 
object make_it(string str, int x) {
    object ob;
 
    switch(str) {
	case "bag":
	   ob = new(BAG);
	    ob->set_name("bag");
	    ob->set_id( ({ "bag", "bag of holding" }) );
	    ob->set_short((string)this_player()->query_cap_name()+"'s bag of holding");
	    ob->set_long(
		"It is a magic bag created by "+(string)this_player()->query_cap_name()+".\n"
	    );
	    ob->set_weight(50);
	    ob->set_value(60);
	    ob->set_max_internal_encumbrance(1500);
	    ob->set_destroy();
	    break;
	case "armour":
	    ob = do_armour(x);
	    break;
	default:
	    ob = do_weapon(x);
    }
    return ob;
}
 
object do_weapon(int x) {
    string what;
    object ob;
 
   ob = new(WEAPON);
    if(random(100) > x) what = "throwing star";
    else what = "mace";
	ob->set_name(what);
	ob->set_id( ({ (string)this_player()->query_name()+"'s "+what, what }) );
	ob->set_short((string)this_player()->query_cap_name()+"'s "+what);
	ob->set_long("A "+what+" created by "+(string)this_player()->query_cap_name()+".\n");
	if(what == "mace") ob->set_type("blunt");
	else ob->set_type("projectile");
	if(x > 17) x = 17;
	ob->set_wc(random(x)+2);
	ob->set_weight(567);
	ob->set_value(random(50)+10);
	return ob;
}
 
object do_armour(int x) {
    object ob;
 
   ob = new(ARMOUR);
    ob->set_name("helm");    
    ob->set_id( ({ "helm", "mage's helm" }) );
    ob->set_short("Mage's helm");
    ob->set_long("A helm of mage conjuring.\n");
    ob->set_limbs( ({ "head" }) );
    ob->set_type("helm");
    if(x > 30) x = 30;
    x = x/2;
    ob->set_ac(random(x));
    ob->set_value(random(50)+10);
    ob->set_weight(700);
    ob->set_destroy();
    return ob;
}
 
void help() {
    write("Syntax: <create [weapon | armour | bag]>\n\n");
    write("Creates from nothing an armour or bag or weapon.\n");
}
