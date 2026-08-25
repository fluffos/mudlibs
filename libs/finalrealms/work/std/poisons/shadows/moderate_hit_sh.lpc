/*** Poisoned weapon shadow ***/
/*** Moderate hit poison.  Does an extra 2-20 ***/
/*** By Wonderflug ***/

#define STRENGTH 10

object my_weapon;

void destruct_shadow() 
{
  destruct(this_object());
}

void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_weapon = ob;
}

int test_add_poison() { return 0; }

void do_poison_effect( object target, object me ) 
{
  int damage;

  damage = random(STRENGTH)+1;
  damage += random(STRENGTH)+1;
  damage = damage*( (100 - (int)target->query_property("poison")) / 100 );

  target->adjust_hp(-damage, me);
}


int weapon_attack( object him, object me )
{
  int ret;

  ret = my_weapon->weapon_attack(him, me);
  if ( ret > 0 )
  {
    tell_object(me, him->query_cap_name()+" spasms in pain from the poison "
	"on your weapon.\n");
    tell_object(him, "You notice some poison on the weapon and you spasm "
	"in pain from the wound.\n");
    tell_room(environment(me), him->query_cap_name()+" spasms in pain as "+
	him->query_pronoun()+" gets hit.\n", ({ me, him }) );

    do_poison_effect( him, me );

    if ( (string)me->query_guild_name() != "assassin" )
    {
	tell_object(me,"The poison seems to have ruined your weapon.\n");
	this_object()->dest_me();
    }
    else call_out("destruct_shadow",0,0);
    return ret;
  }
  return ret;
}

string short()
{
   return "Poisoned "+(string)my_weapon->short();
}

string long()
{
   return (string)my_weapon->long()+"\nPoison glistens along the blade.\n";
}

