
 inherit "/std/container";

object owner;
object owner2;

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

 owner = owner2;
}

int configure(object caster)
{
 owner = caster;
 owner2 = owner;
 set_short(caster->query_cap_name()+"'s Floating Disc");

}

void heart_beat() {

tell_object(owner,"hb\n");
if(environment(this_object()) != environment(owner)) return;
else {

if (environment(this_object()))
say(environment(this_object()), owner->query_cap_name()+"'s "
 "floating disc floats after "+owner->query_cap_name()+".\n",owner);

if (environment(owner))
tell_room(environment(owner), owner->query_cap_name()+"'s "
 "floating discs floats in.\n",owner);

this_object()->move(environment(owner));
tell_object(owner,"Your floating disc floats in after you.\n");
}
else return;
}


void wear_off( )
{
  tell_object(owner,"Your floating disc vanishes spilling its contents!\n");

 this_object()->dest_me();
}


void waiver( )
{

  tell_object(owner,"You floating disc waivers dangerously!\n");

}
