inherit "/std/effect";

int stat_penalty;
int penalty_duration;

void mudlib_setup()
{
   ::mudlib_setup();
   add_save(({ "stat_penalty", "penalty_duration" }));
}

int query_stat_penalty()
{
   return stat_penalty;
}

int query_penalty_duration()
{
   return penalty_duration;
}

void setup(int penalty, int duration)
{
   stat_penalty = penalty;
   penalty_duration = duration;

   set_effect_duration(duration);
   set_effect_delay(8);
   set_effect_type("bacta immersion side effects");
   set_effect_name("bacta immersion side effects");
}

void do_effect(object ob)
{
   if (!ob->has_buff("/d/buffs/bacta_immersion"))
   {
      load_object("/d/buffs/bacta_immersion");
      ob->add_buff(new("/d/buffs/bacta_immersion", stat_penalty));
   }
}

void transfer_to_existing_effect(object new_effect)
{
   add_effect_duration(new_effect->query_penalty_duration());
}