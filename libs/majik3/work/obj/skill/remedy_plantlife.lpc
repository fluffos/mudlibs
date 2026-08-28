inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("remedy_plantlife");
  set_train_difficulty(2);
  set_base_percent(1);
  add_base_stat("wis",70);
  add_base_stat("int",10);
  add_base_stat("agi",10);
  add_base_stat("dex",10);
  set_parent_skill("upkeep");
  set_ep_cost(40);
  set_sp_cost(0);
  set_hp_cost(0);
  set_duration(3);
}
do_success(me,target,skill)
{
  object ob;

  ob = environment(THIS);
  if(!(present(target,THIS)))
  {
    write("You don't have that item in your inventory.\n");
    return;
  }
  if(!(ob->query_farm()))
  {
    write("You can only remedy plants in designated farm lands.\n");
    return 1;
  }
  else
  {
    write("You try to aid the plants.\n");
    ob->do_remedy(target);
    return 1;
  }
}
do_failure(me,target,skill)
{
  do_success(me,target,skill);
  return 1;
}
