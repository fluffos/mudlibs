#include <std.h>

inherit DAEMON;

void clone_weapon(string what, string nom, string with);
void clone_armour(string what, string nom, string with);
void screw_player(object ob, int x, int die) ;

int cmd_wish(string str) {
    string what, nom, with, tmp;

    if(!str) return notify_fail("Wish for what?\n");
    if(sscanf(str, "for % called %s with %s", what, nom, with) != 3)
      return notify_fail("Wish for what called what with what?\n");
    if(sscanf(what, "a %s", tmp)) what = tmp;
    else if(sscanf(what, "an %s", tmp)) what = tmp;
    switch(what) {
        case "sword": case "knife": case "hammer": case "spear":
	  case "warhammer": case "scimitar": case "blade": case "axe":
            clone_weapon(what, nom, with);
            return 1;
        case "helm": case "armour": case "body armour": case "boot":
	  case "glove": case "pants":
            clone_armour(what, nom, with);
            return 1;
        default:
            message("my_action", "If wishes were horses...", this_player());
            return 1;
    }
}

void clone_weapon(string what, string nom, string with) {
    object ob;
    int x;

    ob = new(WEAPON);
    ob->set_name(what);
    ob->set_short(nom);
    ob->set_long("A weapon created by "+(string)this_player()->query_CapName()+
      ".");
    switch(what) {
        case "sword": case "scimitar": case "blade":
            ob->set_type("blade");
            ob->set_wc(5);
            break;
	case "hammer": case "warhammer": 
            ob->set_type("blunt");
            ob->set_class(5);
            break;
	case "knife": case "axe":
            ob->set_type("knife");
            ob->set_class(5);
            break;
	case "spear":
            ob->set_type("projectile");
            ob->set_class(5);
            break;
    }
    sscanf(with, "%d strength", x);
    if(x > 0) ob->set_class(x);
    else x = 5;
    screw_player(ob, x, 20);
}

void screw_player(object ob, int x, int die) {
    if(x > die*3) {
        ob->move(this_player());
        message("my_action", "You really should not have...", this_player());
        this_player()->die();
    }
    else if(x > die && random(die*5) > x) {
        ob->move(this_player());
        message("my_action", "When you play with fire...", this_player());
        this_player()->die();
    }
    else if((int)this_player()->query_mp() < x) {
        ob->remove();
        message("my_action", "You are too much of a wimp.", this_player());
    }
    else {
        ob->move(this_player());
        message("my_action", "Wheeeeeeee!!!!!!", this_player());
        this_player()->add_mp(-(5*(random(x)+5)));
    }
}

void clone_armour(string what, string nom, string with) {
    object ob;
    int x;

    ob = new(ARMOUR);
    ob->set_name(what);
    ob->set_short(nom);
    switch(what) {
        case "helm":
            ob->set_limbs(({ "head" }));
            ob->set_type("helm");
            ob->set_ac(1);
            break;
        case "armour":
            ob->set_type("armour");
             if(random(2)) ob->set_limbs(({ "torso", "right arm", "left arm" }));
              else ob->set_limbs(({ "torso", "first arm", "second arm", "third arm", "fourth arm" }));
            ob->set_ac(1);
            break;
        case "glove":
            ob->set_type("glove");
            ob->set_ac(1);
        case "boot":
            ob->set_type("boot");
            ob->set_ac(1);
    }
    sscanf(with, "%d strength", x);
    if(x < 1) x = 1;
    ob->set_ac(x);
    screw_player(ob, x, 10);
}


