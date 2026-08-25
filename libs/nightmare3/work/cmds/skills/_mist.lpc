//      _mist.c
//      Monk/Cleric/Kataan ability
//      created by Drakken and Aleas 24 June 1994

#include <std.h>
#include <rooms.h>

inherit OBJECT;         // not a bug - a feature !

object caster;
object org_env;
int org_scry;

// this function is used to setup a cloned copy of the spell object
// here the actual functionality is implemented.
void setup_mist(object ob) {
    object env;
    int faith, wis, duration;

    caster = ob;
    org_env = env = environment(caster);
    org_scry = (int)env->query_property("no scry");
    faith = (int)caster->query_skill("faith");
    wis = (int)caster->query_stats("wisdom");
    duration = faith + wis * 3;
    call_out("remove_mist",duration);
    if (org_scry == 0)
        org_env->set_property("no scry",1);
    set_short("");
    set_long("");
    set_weight(0);
    set_value(0);
    this_object()->move(environment(caster));
}

void init() {
    // no :: here
    add_action("checkdest",({ "go", "enter" }) );
}

int query_invis() { return 1; }

void remove_mist() {
    if (org_scry == 0)
        org_env->remove_property("no scry");
    message("my_action","The misty cloud vailing you disappears.",caster);
    destruct(this_object());
}

int checkdest(string str) {
    string verb;
    object env;
    int i;

    verb = query_verb();
    if (!verb || !str)
        return notify_fail("What?\n");
    if (verb == "enter")
	i = (int)org_env->cmd_enter(str);
    else
	i = (int)org_env->cmd_go(str);
    if (i) {
        env = environment(caster);
        if (env != org_env) {
            if (org_scry == 0)
                org_env->remove_property("no scry");
            org_env = env;
            org_scry = (int)env->query_property("no scry");
            if (org_scry == 0)
                org_env->set_property("no scry",1);
        }
	move_object(env);
    }
    return i;
}

int cmd_mist(string str) {
    object ob;
    int cost, faith;
    string  Class;

    if(str)
        return notify_fail("What?\n");
    Class = (string)this_player()->query_class();
    if(Class != "monk" && Class != "kataan" && Class != "cleric")
        return notify_fail("Your aren't a faithfull one!\n");
    if(this_player()->query_ghost())
        return notify_fail("Your voice is hollow.\n");
    if(Class == "monk") {
      if((int)this_player()->query_alignment() < 200)
        return notify_fail("You have betrayed the source of your powers.\n");
    }
    if(Class == "cleric") {
      if((int)this_player()->query_alignment() < 0)
        return notify_fail("You have betrayed the source of your powers.\n");
    }
    if(Class == "kataan") {
      if((int)this_player()->query_alignment() > -200)
        return notify_fail("The demons of the underworld aren't with you!\n");
    }
    if(environment(this_player())->query_property("no magic"))
        return notify_fail("Something seems to be blocking your concentration.\n");
    faith = (int)this_player()->query_skill("faith");
    cost = 20 + random(60 - (int)this_player()->query_stats("wisdom")/2);
    if((int)this_player()->query_mp() < cost)
        return notify_fail("Too low on magic power.\n");
    this_player()->add_mp(-cost);
    this_player()->add_skill_points("faith", cost/3);
    switch(Class) {
        case "monk":
            message("my_action","You mutter a prayer of disorientation."
                " You feel that noone is watching you.",this_player());
            break;
        case "cleric":
            message("my_action","You pray to Tempos for a vailing."
                " You feel that noone is watching you.",this_player());
            break;
        case "kataan":
            message("my_action","You pray to the demons of the underworld for a vailing."
                " You feel that noone is watching you.",this_player());
            break;
    }
    message("other_action",this_player()->query_cap_name()+" speaks a mystical prayer"
                " and looks shadowy for a moment.",environment(this_player()),this_player());
    ob = new(base_name(this_object()));         // clone a copy of us.
    ob->setup_mist(this_player());
    return 1;
}
 
void help() {
    message("help", "Usage : <mist>\n\n"
      "This spell creates a cloud of mist preventing "
      "others from sensing your location.\n\nSee also: scry",
      this_player());
    return;
}
