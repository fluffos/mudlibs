inherit "obj/monster";
string animal;

void setup()
{
    switch(random(5))
    {
      case 0: animal = "rabbit"; break;
      case 1: animal = "badger"; break;
      case 2: animal = "squirrel"; break;
      case 3: animal = "cat"; break;
      case 4: animal = "weasel"; break;
    }

    set_name(animal);
    set_main_plural(animal+"s");
    set_short(animal);
    set_long("Looks like an ordinary "+animal+".\n");
    set_race(animal);
    set_level(random(3)-3);
    set_al(-100);
    call_out("destruct", 500);
}

void destruct()
{
 tell_object(environment(),
  "The "+animal+" returns to its daily tasks.\n");
 dest_me();
}
