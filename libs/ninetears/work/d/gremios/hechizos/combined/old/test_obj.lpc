

#define damage 5
#define TYPE "poison"
inherit "/std/container";

object owner;

void setup()
{
  set_long("A floating disc.\n");
  set_max_weight(2000);
  set_weight(0);
  reset_get();
  set_value(1);
  set_short("floating disc");
  set_name("floating disc");
  add_alias("disc");

set_heart_beat(1);
  call_out("waiver",50,owner);
  call_out("wear_off",60,owner);

}

int configure(mixed caster)
{
 owner = caster;
 set_short(caster->query_cap_name()+"'s Poison Cloud");

}

void heart_beat() {
  object *targets;
  int i;

    targets = all_inventory(environment(this_object()));
   tell_object(owner,"Bing\n");

  for(i=0;i<=sizeof(targets);i++)
   {
     targets[i]->spell_damage(targets[i],damage,TYPE);
     tell_object(targets[i],"The cloud does damage to you!\n");
   }
set_heart_beat(5);

}




void reset()
{
  set_heart_beat(1);
}
void wear_off()
{
  tell_object(owner,"Your floating disc vanishes spilling its contents!\n");

 this_object()->dest_me();
}


void waiver( )
{

  tell_object(owner,"You floating disc waivers dangerously!\n");

}
