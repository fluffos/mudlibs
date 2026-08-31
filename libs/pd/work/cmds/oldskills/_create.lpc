//      /bin/high_mortal/_create.c
//      from the Nightmare mudlib
//      The power of creation for mages
//      created by Descartes of Borg 02 march 1993
//    stormy hack
#include <std.h>
inherit DAEMON;
int spell();
object make_it(string what, int x);
object do_weapon(int x);
object do_armour(int x);
object do_bread(int x);
int cmd_create(string str) {
    int can;
    object ob;
    if(!str) {
        notify_fail("Create what?\n");
        return 0;
    }
    if (!spell()) return notify_fail("What?\n");
    if((int)this_player()->query_skill("conjuring") < 75) {
        notify_fail("You are not quite adept enough at conjuring.\n");
        return 0;
    }
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("A supernatural force prevents your magic.\n");
        return 0;
    }
    if(str != "weapon" && str != "armour" && str != "bag" && str != "bread") {
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
            ob = new("std/bag_logic");
            ob->set_name("bag");
            ob->set_id( ({ "bag", "bag of holding" }) );
            ob->set_short((string)this_player()->query_cap_name()+"'s bag of holding");
            ob->set_long(
                "It is a magic bag created by "+(string)this_player()->query_cap_name()+".\n"
            );
            ob->set_weight(3);
            ob->set_value(0);
            ob->set_max_internal_encumbrance(this_player()->query_skill("conjuring")*10);
            ob->set_destroy();
            break;
        case "armour":
            ob = do_armour(x);
            break;
        case "bread":
            ob = do_bread(x);
            break;
        default:
            ob = do_weapon(x);
    }
    return ob;
}
 
object do_weapon(int x) {
    string what;
    int i, b;
    object ob;
 
 i = this_player()->query_skill("conjuring")/30;
 i += random(i)+15;
   if (i < 10) b = 0; else
   if (i < 20) b = 1; else
   if (i < 30) b = 2; else
   if (i < 40) b = 3; else
   if (i < 50) b = 4; else b = 4;
   if (i > 60) b = 5;
 
    ob = new("/std/weapon");
    if(random(100) > x) what = "whiplash";
    else what = "staff";
        ob->set_name(what);
        ob->set_id( ({ (string)this_player()->query_name()+"'s "+what, what }) );
        ob->set_short((string)this_player()->query_cap_name()+"'s "+what);
        ob->set_long("A "+what+" created by "+(string)this_player()->query_cap_name()+".\n");
        if(what == "staff") ob->set_type("blunt");
        else ob->set_type("flail");
        ob->set_wc((b*2)+ random(3)+ random(3)+ 5);
        ob->set_weight(10);
        ob->set_value(0);
      ob->set_destroy();
        return ob;
}
 
object do_bread(int x) {
    object ob;
 
    ob = new("/std/food");
    ob->set_name("bread");
    ob->set_id( ({ "bread", "mage's bread" }) );
    ob->set_short("Mage's bread");
    ob->set_long("A loaf of mage's bread.\n");
    ob->set_strength(this_player()->query_skill("conjuring")/10);
    ob->set_my_mess("The bread fills the void in your belly.");
    ob->set_value(0);
    ob->set_weight(1);
    ob->set_destroy();
    return ob;
}
 
object do_armour(int x) {
    string what;
    int i, b;
    object ob;
 
 i = this_player()->query_skill("conjuring")/30;
 i += random(i)+15;
   if (i < 10) b = 0; else
   if (i < 20) b = 1; else
   if (i < 30) b = 2; else
   if (i < 40) b = 3; else
   if (i < 50) b = 4; else b = 4;
   if (i > 60) b = 5;
 
    ob = new("/std/armour");
    if(random(100) > x) what = "helm";
    else what = "breastplate";
    ob->set_name(what);
    ob->set_id( ({ "mage's "+what, what }) );
    ob->set_short("Mage's "+what);
    ob->set_long("A Mage's "+what+" created by "+(string)this_player()->query_cap_name()+".\n");
    if(what == "breastplate") ob->set_limbs( ({"torso"}) );
    else ob->set_limbs( ({"head"}) );
    if(what == "breastplate") ob->set_type("body armour");
    else ob->set_type("helmet");
    ob->set_ac((b*2)+ random(3)+ random(3)+ 5);
    ob->set_value(0);
    ob->set_weight(20);
    ob->set_destroy();
    return ob;
}
 
void help() {
    write("Syntax: <create [weapon | armour | bag | bread]>\n\n");
    write("Allows a mage with high conjuring skill to create something from nothing.\n");
}
int spell() {
   object o;
   o = this_player();
   if (o && o->query_class() == "mage")
     if (o->query_skill("conjuring") >= 75)
     return 1;
}
