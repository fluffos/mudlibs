inherit BASE;

object victim;
object killer;

set_victim (object ob)
{
  victim = ob;
}

set_killer (object ob)
{
  killer = ob;
}

create ()
{
  set_no_autoload (1);
  set_name ("uncon");
}

init ()
{
  call_out ("check_hp", random(5) + 10);
  add_action ("do_uncon", "");
}

do_uncon ()
{
  tell_object (victim, "You are unconscious and unable to do anything.\n");
  return 1;
}

check_hp ()
{
  object *all, ob;

  if (random(101) < victim->query_con()) {
    victim->add_hp(random(100));
    victim->set_con (victim->query_con()-1);
  }
  else {
    tell_object (victim, "You feel the life force draining away from you.\n");
    victim->add_hp(-random(20));
    tell_room (ENV(victim), victim->query_cap_name() + " bleeds from deep wounds.\n", ({victim}));
  }

  if (victim->query_hp() < -50)
    {
      tell_object (victim, "You die.\n");
      tell_room (ENV(victim), victim->query_cap_name() + " dies.\n", ({victim}));

      if (victim->query_race() != "raceless")
        killer->add_kill (victim->query_race());

      if (killer->query_kills())
        switch (killer->query_kills()[victim->query_race()])
          {
            case 1:
              tell_object (killer, "You feel victorious as you killed "+
                victim->query_race()+" first time.\n");
              break;
            case 10:
              tell_object (killer, "You are getting the idea in killing "+
                pluralize(victim->query_race())+".\n");
              break;
            case 30:
              tell_object (killer, "You feel yourself as average "+
                victim->query_race()+" killer.\n");
              break;
            case 50:
              tell_object (killer, "It seems "+
                pluralize(victim->query_race())+
                " are getting killed more easily.\n");
              break;
            case 70:
              tell_object (killer, "You feel yourself as expert "+
                victim->query_race()+" killer.\n");
              break;
            case 85:
              tell_object (killer, "Fuck those "+victim->query_race()+
                " bastards prove no resistance against you.\n");
              break;
            case 100:
              tell_object (killer, "You feel like "+
                pluralize(victim->query_race())+
                " are far too easy for such great warrior as you.\n");
              break;
          }

      all = all_inventory(victim);
      if (sizeof(all) > 0)
        all -= ({ THOB });
      for (int i=0;i<sizeof(all);i++)
        all[i]->move (ENV(victim));
      
      if (victim->query_money()) {
        ob = clone_object ("/obj/money");
        ob->set_amount (victim->query_money());        
        victim->add_money (-victim->query_money());
      }

		ob = clone_object ("/obj/corpse");
		ob->create_corpse(victim);
		ob->move(ENV(victim));

      if (victim && victim->query_npc()) {
        destruct (victim);
        destruct (THOB);
      }
      else {
        victim->move ("/world/misc/hell");
        destruct (THOB);
      }
    }

  if (victim->query_hp() > 50)
    {
      tell_object (victim, "You recover from unconsciousness.\n");
      tell_room (ENV(victim), victim->query_cap_name() + " recovers from unconsciousness!\n", ({victim}));
      destruct (THOB);
    }

  call_out ("check_hp", 5 + random(10));
}
