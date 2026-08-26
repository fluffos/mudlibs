/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: coerce.c,v 1.1 1998/01/06 04:36:51 ceres Exp $
 * $Log: coerce.c,v $
 * Revision 1.1  1998/01/06 04:36:51  ceres
 * Initial revision
 * 
*/
/*
 *  coerce.c - Shadow to allow a player to command NPCs and PCs
 *
 *  NOTE: This is in an extremely early stage.  A number of safeguards
 *      need to be added before this can be used in the game.
 *
 *  Success depends on the player's intelligence and skill bonus
 *  relative to the victim's intelligence.  One bonus point counts as
 *  1/100 of an intelligence point.  If the difference is less than 0,
 *  the player always fails; if it's over 20, the player always succeeds.
 *  Before 'coerce'ing the victim, the player must 'control' it; changing
 *  control has a chance of causing the victim to attack.
 */
inherit "/std/effect_shadow";

#include <tasks.h>

// In the following mappings, the key is the command.  The value is a
// penalty (in 1/100ths of intelligence points); this makes some commands
// more difficult than others.

// These are the commands that can be used on players (not yet implemented)
mapping p_cmds = ([
                   "kiss": 0,
                   "get": 0
                   ]);

// These commands can be used on NPCs
mapping npc_cmds = ([
                     "emote": 0,
                     "get": 0,
                     "take": 0,
                     "drop": 0,
                     "put": 0,
                     "follow": 500,
                     "unfollow": 500,
                     "protect": 1000,
                     "unprotect": 1000,
                     "wear": 0,
                     "remove": 0,
                     "equip": 0,
                     "say": 0,
                     "tell": 0,
                     "go": 0
                     ]);

// These require special handling
mapping npc_special = ([
                        "go": "npc_go",
                        //"drop" : "npc_drop",
                        //"put": "npc_put"
                        ]);

object current_slave;
int skill_lvl;
string skill = "magic.methods.mental.charming";
int margin = 1000;
int level_factor = 2;

void create() {
    if (clonep(this_object())) {
        //tell_object(this_player(), "Creating shadow...\n");
        this_player()->add_command("coerce", this_object(), "%I %s");
        this_player()->add_command("control", this_object(), "%I");
        skill_lvl = (int)this_player()->query_int()*100 +
          this_player()->query_skill_bonus(skill);
    }
}

int do_control(object *slave, mixed *args_b, mixed *args_a, mixed *args)
{
    int slave_lvl, result;

    if (sizeof(slave) != 1) {
        this_player()->add_failed_mess(0, "You can only $V one person " +
                                       "at a time.\n", 0);
        return 0;
    }
    if (!living(slave[0])) {
        this_player()->add_failed_mess(0, "You can't $V $I!\n", slave);
        return 0;
    }
    if (current_slave) {
        slave_lvl = (int)current_slave->query_int()*100
          + (int)current_slave->query_level()*level_factor;
        if (random(2*margin) < (slave_lvl - skill_lvl + margin)) {
            if (!(current_slave->query_property("player"))) {
                // Attack player
                current_slave->attack_ob(this_player());
            } else {
                tell_object(current_slave, "You feel like someone is " +
                            "playing with your mind.\n");
                tell_object(this_player(), "You feel that " +
                            current_slave->the_short() +
                            " suspects something.\n");
            }
        }
    }
    current_slave = 0;
    slave_lvl = (int)slave[0]->query_int()*100
      + (int)slave[0]->query_level()*level_factor;
    result = TASKER->attempt_task(slave_lvl, skill_lvl, 20, margin);
    if ((result == FAIL) || (result == BARF)) {
        if (random(2*margin) < (slave_lvl - skill_lvl + margin)) {
            if (!(slave[0]->query_property("player"))) {
                // Attack player
                slave[0]->attack_ob(this_player());
            } else {
                tell_object(slave[0], "You feel like someone is playing " +
                            "with your mind.\n");
                tell_object(this_player(), "You feel that " +
                            slave[0]->the_short() + " suspects something.\n");
            }
        } else {
            write(capitalize(slave[0]->the_short()) +
                  " looks around quizically for a moment.\n");
        }
    } else {
        if (result == AWARD) {
            this_player()->add_skill_level(skill, 1, 0);
        }
        current_slave = slave[0];
    }
    return 1;
}

int do_coerce(object *slave, mixed *args_b, mixed *args_a, mixed *args)
{
    string cmd, rest;
    int result, slave_lvl, cmd_result;

    if (sizeof(slave) != 1) {
        this_player()->add_failed_mess(0, "You can only $V one person " +
                                       "at a time.\n", 0);
        return 0;
    }
    if (!living(slave[0])) {
        this_player()->add_failed_mess(0, "You can't $V $I!\n", slave);
        return 0;
    }
    parse_command(args[1], environment(this_player()), "%w %s",
                  cmd, rest);
    if (!slave[0]) {
        this_player()->add_failed_mess(0, "$V who?\n");
        return 0;
    }
    if (slave[0] != current_slave) {
        this_player()->add_failed_mess(0,
            "$I looks around quizzically for a moment.\n", slave);
        return 0;
    }
    if (!cmd) {
        this_player()->add_failed_mess(0, "$V $I to do what?\n", slave);
        return 0;
    }
    if (slave[0]->query_property("player")) {
        // Player commands
        if (undefinedp(p_cmds[cmd])) {
            this_player()->add_failed_mess(0, "You can't $V $I to do that!\n",
                                           slave);
            return 0;
        }
        // I'm not sure how to call a command on a player...maybe I can't?
        this_player()->add_failed_mess(0, "$V players not yet implemented.\n");
        return 0;
    } else {
        // NPC commands
        if (undefinedp(npc_cmds[cmd])) {
            this_player()->add_failed_mess(0, "You can't $V $I to do that!\n",
                                           slave);
            return 0;
        }
        // Will probably need more checks here, as more dangerous commands
        // are entered.
        slave_lvl = (int)slave[0]->query_int()*100
          + (int)slave[0]->query_level()*level_factor;
        result = TASKER->attempt_task(slave_lvl, (skill_lvl - npc_cmds[cmd]),
                                      10, margin);
        if ((result == FAIL) || (result == BARF)) {
            write(capitalize(slave[0]->the_short()) +
                  " looks at you quizzically.\n");
            this_player()->add_succeeded_mess(0, 0, 0);
            return 1;
        }
        if (undefinedp(npc_special[cmd])) {
            cmd_result = slave[0]->do_command(args[1]);
        } else {
            cmd_result = call_other(this_object(), npc_special[cmd], rest);
        }
        if (!cmd_result) {
            write(capitalize(slave[0]->the_short()) +
                  " looks at you quizzically.\n");
            this_player()->add_succeeded_mess(0, 0, 0);
            return 1;
        }
        if (result == AWARD) {
            this_player()->add_skill_level(skill, 1, 0);
        }
        this_player()->add_succeeded_mess(0, 0, 0);
        return 1;
    }
}

void remove_cmd() {
    if (this_player()->remove_object2(this_object())) {
        //write("Shadow removed.\n");
    } else {
        //write("Shadow not removed :(\n");
    }
}

int npc_go(string dir) {
    // This is tricky, since there may be exits with non-standard names.
    mixed exits;
    int i;

    if (!environment(current_slave)
        || !function_exists("query_dest_dir", environment(current_slave))) {
        return 0;
    }
    exits = environment(current_slave)->query_dest_dir();
    for (i = 0; i < sizeof(exits); i += 2) {
        if (exits[i] == dir) {
            return current_slave->do_command(dir);
        }
    }
    return 0;
}
