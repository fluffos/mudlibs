inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("planting");
    set_train_difficulty(2);
    set_base_percent(10);
    add_base_stat("wis",10);
    add_base_stat("pow",5);
    add_base_stat("int",10);
    add_base_stat("agi",30);
    add_base_stat("dex",20);
    add_base_stat("str",20);
    add_base_stat("stu",5);
    set_parent_skill("farming");
    set_ep_cost(15);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(5);
}
do_success(me,target,skill)
{
  object ob;
  ob = environment(THIS);
  if(!(ob->query_farm()))
  {
    write("You can only plant in designated farm lands.\n");
    return 1;
  }
  else
  {
    write("You begin to plant.\n");
    ob->do_plant();
    return 1;
  }
}
do_failure(me,target,skill)
{
  do_success();
  return 1;
}
