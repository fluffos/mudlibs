inherit "/std/effect/poison_blue";

void setup(object target, object source, object apparatus, int rank, int level)
{
   int damage = (rank * 2) + random(ceil(level / 5.0) + 5);
   set_poison_strength(rank + to_int(ceil(level / 10.0)) + 2);

   if (!present("inject_damage", source))
   {
      load_object("/d/obj/spec_damage");
      new("/d/obj/spec_damage", apparatus->short(), "inject_damage")->move(source);
      present("inject_damage", source)->set_combat_messages("combat-inject");
      present("inject_damage", source)->set_death_message("$N was poisoned with a lethal substance by $N1 at $o1.");
   }
   else
   {
      present("inject_damage", source)->setup(apparatus->short(), "inject_damage");
   }

   source->add_event(target, present("inject_damage", source), target->query_random_armor_slot(), ([ "unstoppable" : damage ]), source);

   source->start_fight(target);
   source->handle_events();

   set_effect_duration(query_poison_strength());
   set_effect_delay(12);
   set_effect_type("poison damage");
   set_effect_name("poison");
}