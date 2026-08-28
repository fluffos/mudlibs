// namhas

inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("sneak");
    set_train_difficulty(2);
    set_base_percent(10);
    add_base_stat("agi",100);  // Total of Base Stats is 100
    set_parent_skill("furtiveness");
    set_ep_cost(1);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(1);
}

do_critical_success (me, target, chance)
{
  write ("Ok, you will sneak for while...\n");
  me->set("sneak", 1);
  call_out ("end_sneak", random(256) + me->query_skill_chance("sneak") * 2, me);
  return 1;
}

do_success (me, target, chance)
{
  write ("Ok, you will sneak for while...\n");
  me->set("sneak", 1);
  call_out ("end_sneak", random(60) + me->query_skill_chance("sneak"), me);
  return 1;
}

do_failure (me, target, chance)
{
  write ("Ok, you will sneak for while...\n");
  me->set("sneak", 0);
  return 1;
}

end_sneak (object ob)
{
  if (ob) {
    if (random(101) < ob->query_skill_chance("sneak")) {
      if (random(101) > ob->query_skill_chance("sneak") && !random(10))
        {
          ob->add_skill_exp("sneak", 1);
        }
      ob->set("sneak", 1);
      call_out ("end_sneak", random(60) + ob->query_skill_chance("sneak"));
     }
    else
      ob->set("sneak", 0);
  }
}

query_can_use(me, target)
{
  if (me->query("sneak")) {
    write ("You are already sneaking.\n");
    return 0;
  }
  return 1;
}
