#define UNBLOCK ({ "drink" })

inherit "/std/object";

void create() {
    ::create();
    set_name("");
    set_short("");
    set_id(({ "drink", "drink_ob" }));
}

void init() {
    ::init();
    add_action("block_cmd", "");
}

int block_cmd() {
    mapping tmp;
    tmp="/cmds/skills/_drink"->query_bl();

    if(!tmp || !tmp[this_player()] || !present(tmp[this_player()], environment(this_player()))) remove();
    if(member_array(query_verb(), UNBLOCK)!=-1) return 0;
    write("You may do nothing while drinking blood.\n");
    return 1;
}
