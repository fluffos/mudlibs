#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Power Word Quack"
#define	NIVEL	7
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	CANCION	""
#define	TIPO	"evil"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("This spell summons the little ceramic ducks of death, "
    "incarnations of the evil God Ducky, these cause such pain to the "
    "soul of those with GOOD taste that they suffer massive "
    "internal damage as their eyes try to retreat through their brain.\n"
    "The soul of an older player having more value, this spell does "
    "damage in proportion to the level of the victom");
  set_gp_cost(NIVEL);
  set_casting_time(4);
  set_rounds(({"round1","round2","round3","round4"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"You begin to chant, and as you do so, your voice changes pitch.\n");
  tell_room(ENV(caster),caster->QCN+" chants in a harsh quacking voice.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Your chanting becomes a loud chaotic quacking!\n");
  tell_room(ENV(caster),caster->QCN+"'s chant grows louder, into a loud chaotic quacking!.\n",caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"The sound of your quacking fades and is repalced by a multitude of higher pitched quacks.\n");
  tell_room(ENV(caster),caster->QCN+" stops chanting but the sound is taken up by a multitude of smaller voices.\n",caster);
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int skill,check,cost,c_roll,t_roll;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    tell_room(ENV(caster),caster->QCN+" looks very confused and quacks angrilly.\n",caster);
    return -1;
  }

  if (target->query_dead())
  {
    tell_object(caster,target->QCN+" is already dead.\n");
    tell_room(ENV(caster),caster->QCN+" looks very confused and curses.\n",caster);
    return -1;
  }

  if (target->query_pacify_spell())
  {
    tell_object(caster,"You don't feel like harming "+target->QCN+", seeing how peaceful "+target->query_pronoun()+" is.\n");
    return -1;
  }

  // 100% save on protection from evil
  if (target->query_res(TIPO))
  {
    tell_object(target,"You hear "+caster->QCN+" quack once angrilly and a funny clattery sound like one wing clapping, a few quiet angry quacks and silence reigns.\n");
    caster->attack_ob(target);
    tell_object(caster,"Your quack fails.\n");
    tell_room(ENV(caster),caster->QCN+" quacks something at "+target->QCN+" and there's a rattling sound and a few quiet but angry departing quacks.\n",caster);
    return 0;
  }

  if(target->query_property("pacify_on"))
  {
    tell_room(ENV(caster),"The Gods step in to save the life of "+target->QCN+" who is harmless.\n");
    return 0;
  }

  tell_object(caster,"%^BOLD%^The sound of quacking fills the air as you avert your eyes from the vision of horror forming before you !%^RESET%^\n");
  tell_room(ENV(caster),caster->QCN+" Quacks once in the silence. A flutter of wings and many strident quacks reply, you recoil and your eyes slam shut, barely in time to save your life from the vision of evil (and extreeme bad taste) flying in.\n",caster);
  tell_object(target,"%^BOLD%^Your eyes try to shut, but the sight of small badly painted ceramic ducks flying towards you is too much!\n%^RED%^A massive stabbing pain engulfs you as evil overwhelms you and your eyes try to burrow into your brain to escape the horror.%^RESET%^\n");
  target->attack_by(caster);
  target->spell_damage(target->query_level()*2,TIPO,caster);
  return 0;
}
