#include <spells.h>
inherit BASE_SPELL;

string	NOMBRE	= "Muro de fuego";
mixed	ESCUELA	= ({"invocacion"});
mixed	ESFERA	= ({"sol"});
int	NIVEL	= 4;
string	CANCION	= "'pyris xenro haltus'";
string	MURO	= OBJETOS+"wall_fire_obj";
string	LOCKOUT	= "wall_fire_cast";
#define	WALLFIRE_DURATION_LEVELX	6

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("pass");
  set_range(0);
  set_help_extras("Damage Type: Magical\nSaving Throw: Level");
  set_help_desc("This spell will throw up a wall of fire to cover one exit in "
    "a room.  Anyone trying to pass through the wall except for the "
    "caster will take some damage, and newbies shall not be allowed "
    "through the wall at all.  This is a very dangerous spell, and it "
    "has often been reported that novice casters have killed themselves "
    "by trying to cast the wall over the only exit in a room.  Of course "
    "the massive fire wall consumes all the oxygen in the area very "
    "quickly and the poor sods die.  The wall lasts "+
    WALLFIRE_DURATION_LEVELX+" rounds per level.  Note the wall is "
    "only one-way.  Coming through from the other side will not do "
    "damage.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
  object ob,*obs;
  int i,num_exits,num_walls,kill_flag;

  if (caster->QP(LOCKOUT))
  {
    tell_object(caster,"You just can't muster the concentration to finish the spell just yet.\n");
    return -1;
  }

  if (!(ENV(caster)->query_exit(target)))
  {
    tell_object(caster,"You look around and realize there's no exit of that name here.\n");
    tell_room(ENV(caster),caster->QCN+" looks around confusedly and stops casting.\n",caster);
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  num_walls=0;
  num_exits=sizeof((ENV(caster))->query_direc());
  obs=all_inventory(ENV(caster));
  for (i=0;i<sizeof(obs);i++)
    if (obs[i]->query_is_wall()) num_walls++;

  //if(0) // taniwha 1995, the lock out takes care of this
  // wonderflug 1996, bugger that rot.  they WILL die.
  if ( num_exits - num_walls <= 1 )
  { /* bing we're dead now */
    tell_object(caster, "Just as you complete the spell you realize "
      "that you're trying \nto seal up the last exit in the area.  With "
      "horror, you try to abort \nthe spell, but the magic's already "
      "taken control, and you can't stop.  \nYour lasts thoughts are "
      "how could you be so stupid, ignoring age-old advice, \n"
      "before the flames engulf you and leave nothing but ashes.\n");
    tell_room(ENV(caster), caster->QCN+
      " gets a look of abject horror on "+caster->query_pronoun()+
      " face as a spell \ngoes awry.  Suddenly a wall of flame springs "
      "up beneath "+caster->query_objective()+" and in \nmoments "
      "nothing is left but ash.\n", caster);
    caster->do_death(caster);
    return 0;
  }

  ob=clone_object(MURO);
  ob->set_spell(caster,target);
  ob->move(ENV(caster));
  caster->ATP(LOCKOUT,1,50);
  tell_room(ENV(caster),"A massive wall of fire springs up over the "+target+" exit!\n");
}
