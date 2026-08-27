inherit "obj/monster";
string animal;
object target, ob;

void set_target(object ob);

string doom()
{
    switch(random(12))
    {
      case 0: return "devil-spawn";
      case 1: return "chaos-curse"; 
      case 2: return "homunculus"; 
      case 3: return "crazed imp"; 
      case 4: return "dread-claws"; 
      case 5: return "nightmare";
      case 6: return "critters"; 
      case 7: return "demon-spawn";
      case 8: return "lurker"; 
      case 9: return "quasit";
      case 10: return "crawling horror"; 
      case 11: return "creeping doom"; 
    }
}

void setup()
{
    animal = doom();
    set_name(animal);
    set_short(animal);
    set_main_plural(animal+"s");
    add_alias("doom");
    set_long("It's a DOOM.\n");
    set_race(animal);
    set_level(10+random(10));
    set_al(0);
    call_out("destruct", 500);
}

void destruct()
{
 if(!animal) return;
 tell_object(environment(),
  "An oppressive cloud seems to leave the room.\n");
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
   tell_room(environment(this_object()), "The horrible presence leaves "
    "after "+target->query_objective()+".\n",target);

 if(environment(target))
   tell_room(environment(target), "A "+animal+" follows right "
    "behind "+target->query_objective()+".\n",target);

 this_object()->move(environment(target));
 tell_object(target,"The "+animal+" follows right behind you.\n");
}

void set_target(object ob)
{
 target = ob;
}
