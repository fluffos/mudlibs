#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Aullido infernal"
#define	NIVEL	5
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	CANCION	"'kyrnie ov daemon'"
#define	TIPO	"evil"
#define	SALV	50
#define	SIZE_D	3
#define	NO_D	15

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("many");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_extras("Damage Type: "+tipo(TIPO)+"\nSaving Throw: 1/2");
  set_help_desc("This spell causes the caster to emit"
    " a horrifying howl, the sound of which is heavily"
    " laced with demonic energies.  Targets"
    " suffer damage from the excruciating"
    " pain of the powerful sonic attack.  The Priest"
    " can not channel the energies required for"
    " spellcasting for a short time after using"
    " this spell.  Furthermore, the chaotic nature of"
    " the forces using the caster as a conduit is such"
    " that all knowledge of the spell \"Heal\" is lost.\n"); 
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i,damage;

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  for (i=0;i<sizeof(target);i++)
  {
    tell_object(target[i],caster->QCN+" throws back "+caster->query_possessive()+" head, emitting a piercing howl, the noise of which batters at your senses!\n");
    tell_room(ENV(target[i]), target[i]->QCN+" staggers as "+target[i]->query_pronoun()+" is assaulted by demonic powers!\n",target[i]);
    damage=fix_damage(caster, target[i],-roll(NO_D,SIZE_D));
    damage-=target[i]->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
    target[i]->attack_by(caster);
    caster->ATP("stillcasting",1,random(3));
    caster->remove_spell("heal");
  }
  return NIVEL*100+damage;
}
