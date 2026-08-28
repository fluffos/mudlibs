// namhas

inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("dodge");
    set_train_difficulty(4);
    set_base_percent(10);
    add_base_stat("agi",100);  // Total of Base Stats is 100
    set_parent_skill("unarmed_combat");
    set_ep_cost(2);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(0);
}

query_can_use(me, target)
{
    write ("This skill is automagically in use.\n");
    return 0;
}
