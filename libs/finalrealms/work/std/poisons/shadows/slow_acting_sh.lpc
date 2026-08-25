/*** Poisoned weapon shadow ***/
/*** Slow acting poison.  Same as the poison spell ***/
/*** By Wonderflug ***/

#define DURATION 300
#define STRENGTH 5
#define MYPOISON "/std/spells/cleric/poisoned"

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
  object boo;
  int t;

  t = DURATION;
  t = t* ( (100 - (int)target->query_property("poison")) / 100 );
  if ( t <= 0 ) t = 1;

  target->add_timed_property("poisoned",1,t);
  boo = clone_object(MYPOISON);
  boo->set_get();
  boo->move(target);
  boo->reset_drop(); boo->reset_get();
  boo->set_spell(target, STRENGTH);
}


int weapon_attack( object him, object me )
{
  int ret;

  ret = my_weapon->weapon_attack(him, me);
  if ( ret > 0 )
  {
    tell_object(me, him->query_cap_name()+"'s wound turns green from the "
	"poison on your weapon.\n");
    tell_object(him, "You notice some poison on the weapon and the wound "
	"seems to turn a \nhorrid shade of green..\n");
    tell_room(environment(me), him->query_cap_name()+"'s wound turns a "
	"sickly shade of green.\n", ({ him, me}) );

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

