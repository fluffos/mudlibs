#include <npc.h>
#include <guild.h>

#include "../global.h"

private object owner;
private int followable;
private mixed *cmd_queue;

private int follow_cmd(int follow);

public object get_owner() {
    return owner;
}

public void set_owner(mixed new_owner) {
    if (!new_owner) {
	GUILD_SLAVE_D->remove_slave(owner, this_object());
	owner = 0;
	return;
    }

    if (stringp(new_owner)) {
	new_owner = find_player(new_owner);
    }

    owner = new_owner;

    GUILD_SLAVE_D->add_slave(owner, this_object());
    GUILD_SLAVE_D->set_follow(owner, this_object(), 1); // 1 = moving messages
}

public int get_followable() {
    return followable;
}

public void set_followable(int new_followable) {
    followable = new_followable;
}

public int do_cmd(string cmd, string arg) {
    mixed x;

    if (cmd == "leave") {
	owner->tell_me(sprintf("You ask the %s to leave you.", query_name()));
	return 1;
    }

    if ((cmd != "summon") && (environment() != environment(owner))) {
	return notify_fail(
	  sprintf("But your %s is not here!\n", query_name())), 0;
    }

    switch (cmd) {
    case "stay":
	return follow_cmd(0);

    case "follow":
	return follow_cmd(1);
    }

    return 0;
}

int monster_died(object npc, object killer) {
    return 0;
}

void create_monster() {
    set_name("minion");
    set_id(({ "minion" }));
    set_short("A minion");
    set_gender(({ G_MALE, G_FEMALE })[random(1)]);
    set_guild(GN_DRUID);
    set_level(1);
    set_ep(0);
    set(LIV_HEAL_RATE, 1);
    set(NPC_NO_CORPSE, 1);
    set(NPC_SET_PK_FLAG, 1);
    set_dead_ob(this_object());

    load_chat(2, ({
	"The minion dances.",
	"The minion sings.",
      }));
}

private int follow_cmd(int follow) {
    if (!followable) {
	return notify_fail(sprintf("%s does not know how to do that.\n",
	    query_name())), 0;
    }

    if (follow == (GUILD_SLAVE_D->query_follow(owner, this_object()) & 1)) {
	return notify_fail(follow
	  ? "But it's already following you!\n"
	  : "But it's not following you!\n"
	), 0;
    }

    owner->tell_me(sprintf("You command your %s to %s.", query_name(), follow ?
	"follow you" : "stay here"));

    return GUILD_SLAVE_D->set_follow(owner, this_object(), follow | 2);
}

private void process_queue() {
    closure *cl;

    cl = cmd_queue[0];
    funcall(cl[1], cl[2]);
    cmd_queue = cmd_queue[1..];
    if (sizeof(cmd_queue) > 0) {
	cl = cmd_queue[0];
	funcall(cl[0], &(cl[2]));
	call_out("process_queue", 2);
    }
}

private void add_command_to_queue(closure *cl) {
    cmd_queue += ({ cl });

    if (sizeof(cmd_queue) == 1) {
	funcall(cl[0], &(cl[2]));
	call_out("process_queue", 2);
    }
}
