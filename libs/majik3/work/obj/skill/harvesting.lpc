inherit "/obj/skill/obj/skill";

create_skill()
{
    set_skill_name("harvesting");
    set_train_difficulty(2);
    set_base_percent(1);
    add_base_stat("wis",20);
    add_base_stat("int",10);
    add_base_stat("str",45);
    add_base_stat("agi",15);
    add_base_stat("dex",20);
    set_parent_skill("farming");
    set_ep_cost(50);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(3);
}
do_success(me,target,skill)
{
  object ob;
  ob = environment(THIS);
  if(!(ob->query_farm()))
  {
    write("You can only harvest in designated farm lands.\n");
    return 1;
  }
  else
  {
    write("You try to harvest some crops.\n");
    ob->do_harvest();
    return 1;
  }
}
do_failure(me,target,skill)
{
  do_success();
  return 1;
}
