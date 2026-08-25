// _balefire.c
// Cleric/Monk ability
// Coded by Drakken and Aleas.
// Sat Oct 15 16:38:52 CET 1994

#include <std.h>

inherit DAEMON;

#define ANGEL "/cmds/skills/mon/angel"

void clone_angel(int nr, int power, object foe) {
    object ob;
    string * x = ({ "first", "second" });

    ob = new(ANGEL);
    ob->set_short(lower_case(possessive_noun(this_player()))+" "+x[nr-1]+" guardian angel");
    ob->setup_angel(power);
    message("enviroment","%^BOLD%^%^MAGENTA%^A guardian angel decends from heaven to assist "+
        (string)this_player()->query_cap_name()+"!%^RESET%^",environment(this_player()),this_player());
    message("enviroment","%^BOLD%^%^MAGENTA%^A guardian angel decends from heaven to assist "
        "you!%^RESET%^",this_player());
    ob->move(environment(this_player()));
    if (!ob->kill_ob(foe,0)) foe->kill_ob(ob,0);
}
 
int cmd_balefire (string str) {
    object tp, ob;
    object env, *rooms, *attackers, *inv, *helpers;
    string *sorties, Class;
    int i, j, tmp, level, faith, power;

    tp = this_player();
    env = environment(tp);
    if (!env) return 0;

    if(tp->query_ghost())
        return notify_fail("Your voice is hollow.\n");

    if(tp->query_casting()) return 1;
    tp->set_magic_round();

    Class = (string)tp->query_class();
    if (Class != "monk" && Class != "cleric") {
	if(Class == "kataan") {
	    message("my_action","%^BOLD%^A lightning bold shoot from the sky and hits you!%^RESET%^",tp);
	    message("other_action","%^BOLD%^A lightning bold shoot from the sky and hits "+
		(string)tp->query_cap_name()+"!%^RESET%^",environment(tp),tp);
	    tp->add_mp(-25);
	    tp->do_damage((string)tp->return_limb(),25);
	    return 1;
	    } else
            return notify_fail("You aren't a faithful one!\n");
    }

    if (tp->query_alignment() < 1350)
        return notify_fail("The powers of goodness only help their strongest followers.\n");

    if(environment(tp)->query_property("no magic"))
        return notify_fail("A magical force prevents you from setting the signal.\n");

    if (str)
        return notify_fail("Balefire does affect everyone!\n");

    tmp = 0;
    attackers = (object *)this_player()->query_attackers();
    if(attackers && sizeof(attackers))
        for(i=0; i<sizeof(attackers); i++) {
            ob = attackers[i];
            if (ob && objectp(ob) && environment(ob) == env) {
                tmp = 1;
                break;
            }
        }
    if (!tmp)
        return notify_fail("You are not in battle!\n");

    level = (int)tp->query_level();
    faith = (int)tp->query_skill("faith");
    if(faith < 60 || level < 6)
        return  notify_fail("You are not skilled enough for setting the signal.\n");

    power = tp->query_mp();
    if (power < 250)
        return  notify_fail("You currently lack the mental strength to set the signal.\n");

    rooms = ({ env });
    sorties = (string *)env->query_exits();
    if(sorties && sizeof(sorties)) {
        for(i=0, tmp = sizeof(sorties); i<tmp; i++) {
            catch(call_other((object)env->query_exit(sorties[i]),"???"));
            if(!(ob = find_object(env->query_exit(sorties[i])))) continue;
            if(ob->query_property("no magic")) continue;
            rooms += ({ ob });
        }
        rooms = distinct_array(rooms);
    }

    tp->set_disable();
    tp->add_mp(-250);
    for(i=0; i<sizeof(attackers); i++) {
        ob = attackers[i];
        if (ob && objectp(ob) && member_array(environment(ob),rooms) != -1 ) {
            if (ob->query_alignment() < -1) {
                power += ob->query_mp();
                ob->add_mp(-2 * (int)ob->query_max_mp());
            } else if (ob->query_alignment() > 200)
                power -= ob->query_mp();
        }
    }
    message("my_action","%^YELLOW%^You set a balefire!%^RESET%^",tp);
    helpers = ({ });
    i = sizeof(rooms);
    while (i--) {
        message("environment","%^YELLOW%^"+(string)tp->query_cap_name()+
            " has set a balefire!%^RESET%^",rooms[i],tp);
        inv = all_inventory(rooms[i]);
        j = sizeof(inv);
        while (j--) {
            if (living(inv[j]) 
                && inv[j] != tp
                && !creatorp(inv[j])
                && !inv[j]->query_ghost()
                && member_array(inv[j],attackers) == -1
                && inv[j]->query_alignment() > 200
            ) {
                helpers += ({ inv[j] });
                power += inv[j]->query_mp();
                power += inv[j]->query_skill("faith");
                if (userp(inv[j])) {
                    message("other_action","%^RESET%^%^BOLD%^"
                        "You feel an undeniable demand to assist a good soul in need!%^RESET%^",inv[j]);
                    if (environment(inv[j]) != env)
                        inv[j]->move_player(env,"to help");
                    inv[j]->set_mp(0);
                    if (!inv[j]->kill_ob(ob,0)) ob->kill_ob(inv[j],0);
                }
            }
        }
    }
    power += faith * 3;
    power *= level/10 + 1;
    ob->do_damage("torso",power/50);
    tp->add_skill_points("faith",power/100);
    tp->add_alignment(random(10));
    if ((int)tp->query_skill("faith") > 90) {
        if (power > 1000)
            clone_angel(1, power, ob);
        if (power > 2000)
            clone_angel(2, power, ob);
    }   
    ob->kill_ob(tp,1);
    return 1;
}

void help() { 
    message("help",
        "Syntax: <balefire>\n\n"
        "Allows a follower of faith to set a signal to the forces of "
        "good that the caster is in danger. Anyone around with a saintly soul "
        "will hear the call and try to help. Those of really high "
        "faith might even get devine assistance. ",
        this_player());
}

