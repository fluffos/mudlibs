// namhas

inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("awareness");
    set_train_difficulty(10);
    set_base_percent(10);
    add_base_stat("int",95);  // Total of Base Stats is 100
    add_base_stat("wis", 5);
    set_parent_skill("furtiveness");
    set_ep_cost(0);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(0);
}

query_can_use(me, target)
{
    write ("This skill is automatically in use.\n");
    return 0;
}
