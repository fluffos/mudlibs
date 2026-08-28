inherit "/obj/skill/obj/skill";
create_skill()
{
    set_skill_name("plant_diagnoses");
    set_train_difficulty(2);
    set_base_percent(10);
    add_base_stat("wis",40);
    add_base_stat("int",35);
    add_base_stat("dex",20);
    add_base_stat("str",5);
    set_parent_skill("upkeep");
    set_ep_cost(25);
    set_sp_cost(0);
    set_hp_cost(2);
    set_duration(5);
}
do_success(me,target,skill)
{
  object obj;
  if(!(environment(THIS)->query_farm())){
    write("You can only diagnose plants in designated farmlands.\n");
    return;
  }
  else
  {
    environment(THIS)->do_diagnose();
  }
}
do_failure(me,target,skill)
{
  if(!(environment(THIS)->query_farm())){
    write("You can only diagnose plants in designated farmlands.\n");
    return;
  }
  else
  {
    write("You fail to diagnose the plants disease.\n");
  }
}
