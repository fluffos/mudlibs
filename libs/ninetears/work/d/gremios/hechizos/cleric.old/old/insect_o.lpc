inherit "obj/monster";
string animal;
object target, ob;

void set_target(object ob);

void setup()
{
    switch(random(12))
    {
      case 0: animal = "wasps"; break;
      case 1: animal = "fleas"; break;
      case 2: animal = "insects"; break;
      case 3: animal = "killer bees"; break;
      case 4: animal = "gnats"; break;
      case 5: animal = "mosquitoes"; break;
      case 6: animal = "critters"; break;
      case 7: animal = "spiders"; break;
      case 8: animal = "hornets"; break;
      case 9: animal = "army ants"; break;
      case 10: animal = "beetles"; break;
      case 11: animal = "moths"; break;
    }

    set_name(animal);
    set_main_plural("swarms of "+animal);
    set_short("swarm of "+animal);
    add_adjective("swarm of");
    add_alias("swarm");
    set_long("Looks like an ordinary swarm of "+animal+".\n");
    set_race(animal);
    set_level(random(5));
    set_al(0);
    call_out("destruct", 500);
}

void destruct()
{
 if(!animal) return;
 tell_object(environment(),
  "The swarm of "+animal+" disperses.\n");
 dest_me();
}

void heart_beat()
{
 ::heart_beat();

 if(!target)
   return;

 if(environment(this_object()) == environment(target))
   return;

 if(environment(this_object()))
   tell_room(environment(this_object()), "The swarm  of "+animal+" buzzes "
    "after "+target->query_objective()+".\n",target);

 if(environment(target))
   tell_room(environment(target), "A swarm of "+animal+" buzzes in right "
    "behind "+target->query_objective()+".\n",target);

 this_object()->move(environment(target));
 tell_object(target,"The swarm of "+animal+" buzzes in right behind you.\n");
}

void set_target(object ob)
{
 target = ob;
}
