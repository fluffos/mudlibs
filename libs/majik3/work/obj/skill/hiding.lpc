// namhas

inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("hiding");
    set_train_difficulty(2);
    set_base_percent(15);
    add_base_stat("dex",75);  // Total of Base Stats is 100
    add_base_stat("agi",75);
    add_base_stat("siz",-50);
    set_parent_skill("furtiveness");
    set_ep_cost(5);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(5);
}

do_success (me, target, chance)
{
  me->set("hide", 1);
  write ("You step into the shadows.\n");
  return 1;
}

do_failure (me, target, chance)
{
  object *all, o;
  int i;

  all = all_inventory(ENV(me));

  foreach (o in all)
    {
      if (!living(o))
        all -= ({ o });

      if (o == me)
        all -= ({ me });
    }

  if (sizeof(all) > 0)
    {
      i = random(sizeof(all));
      write ("You tried to hide but "+all[i]->query_cap_name()+" obviously had noticed your puny attempt.\n");
      tell_object (all[i], me->query_cap_name() + " tries to hide.\n");
      me->set("hide", 0);
    }
  else
    {
      write ("You clumsily step into the shadows.\n");
      me->set("hide", 1);
    }

  return 1;
}

query_can_use(me, target)
{
  if (me->query("hide")) {
    write ("You are already hiding.\n");
    return 0;
  }
  return 1;
}
