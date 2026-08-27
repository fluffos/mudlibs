/*** Falling Wall Spell ***/
/*** Coded by:  Taniwha ***/
/*** Fixed up by Wonderflug ***/

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Crumble Wall"
#define	NIVEL	5
#define	ESCUELA	({"invocacion"})
#define	ESFERA	({""})
#define	CANCION	"'retro lithos'"
#define	SALV	100
#define	TIPO	"stone"
#define TYPE	"impact" // yes this is correct it does impact damage
#define SIZE_D	7

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("many");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("This spell collapses the walls in a room, crushing the "
    "occupants with the rubble.  The caster avoids damage until the roof "
    "falls in as well, then everyone takes double damage.  The damage caused "
    "is equal to the level of the caster d7, with a maximum of 15d7.");
  set_help_extras("Damage Type: "+tipo(TIPO)+"\nSaving Throw: None");
  set_gp_cost(NIVEL);
  set_casting_time(3);
  set_rounds(({({
    "The walls begin to rumble and shake as you start your spell.\n",
    "The walls begin to rumble and shake.\n"}),({
    "The shaking suddenly stops as you near the end of your spell.\n",
    "The shaking suddenly stops and a dreadful silence cloaks the area.\n"}),"round3"}));
}

mixed extra_checks(string str, object caster)
{
  if (ENV(caster)->query_outside())
    return "Nobody's stupid enough to stand around outside next to a wall with YOU around.\n";

  if (ENV(caster)->QP("walls gone") >= 4 )
    return "There's no walls left to bring down here!\n";

  return 1;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,NO_D=MIN(15,caster->QL),i,j;
  string str;
  object rubble;

  target-=({caster});
  
  if (!pointerp(target) || !sizeof(target)) 
  {
    tell_object(caster, "There is noone here by that name.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  rubble=clone_object("/std/object");
  rubble->move(ENV(caster));
  rubble->reset_get();
  rubble->set_name("pile of rubble");
  rubble->add_alias("rubble");
  rubble->set_main_plural("piles of rubble");
  rubble->set_long("A pile of rubble, as you look round you realize "
    "that it's fallen from the walls here.\n");

  if (ENV(caster)->QP("walls gone")>=2)
  {
    tell_room(ENV(caster),"As another wall falls down the entire roof collapses, to "+caster->QCN+"'s dismay.\n", caster);
    tell_object(caster,"You seem to have miscalculated..\nThe roof collapses upon you!\n");
    target+=({caster});
    NO_D=MIN(25,NO_D*2);
  }

  ENV(caster)->ASP("walls gone",ENV(caster)->QP("walls gone")+1);

  for (i=0;i<sizeof(target);i++)
    if (target[i] && living(target[i]))
    {
      damage=fix_damage(caster,target[i],-roll(NO_D,SIZE_D));
      target[i]->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
      target[i]->attack_by(caster);
      tell_object(target[i],"A wall crumbles and you are crushed by rubble.\n");
      tell_room(ENV(caster), target[i]->QCN+" is pummeled by falling rubble.\n", target[i] );
    }

  if ( pointerp(out_range) && sizeof(out_range) )
    tell_object(caster, "Alas, "+query_multiple_short(out_range)+
      " got out of range of the falling wall.\n");

  return 0;
}
