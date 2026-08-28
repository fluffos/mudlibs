// namhas

inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("summon_skeleton");
    set_train_difficulty(2);
    set_base_percent(11);
    add_base_stat("wis",40);  // Total of Base Stats is 100
    add_base_stat("int",10);
    add_base_stat("pow",50);
    set_parent_skill("necromancy");
    set_ep_cost(20);
    set_sp_cost(30);
    set_hp_cost(5);
    set_duration(1);
}

do_success(me,result)
{
    clone_object("/home/sinister/monster/skeleton");
    tell_room( capitalize(me->query_name())+" summons a human skeleton.\n", ({ me }));
    tell_object(me, "You successfully summoned a human skeleton.\n");
    me->add_alignx (-10);
    me->add_aligny (-3);
    return 1;
}

do_failure(me,result)
{
    tell_room( capitalize(me->query_name())+" claps his hands three times rapidly but nothing happnens.\n", ({ me }));
    tell_object(me, "You clap your hands three times rapidly, but you fail in your skill.\n");
    return 1;
}

int
do_message ()
{
    tell_object (THIS, "You begin to do the skill.\n");
    tell_room (ENV(THIS), THIS->query_cap_name() + " begins to do something.\n", ({THIS}));
}
