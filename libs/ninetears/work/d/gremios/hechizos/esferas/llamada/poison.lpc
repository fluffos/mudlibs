#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Veneno"
#define	NIVEL	5
#define	ESCUELA	({""})
#define	ESFERA	({"llamada"})
#define	TIPO	"poison"
#define	CANCION	"'Toxoplasmosis'"

void setup_poison(int damage, object caster, object target)
{
  object ob=clone_object(OBJETOS+"poisoned");

  target->ATP("poisoned",1,(caster->QL*30));
  ob->set_get();
  ob->move(target);
  ob->reset_drop();
  ob->reset_get();
  ob->set_spell(caster,damage);
}

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere("llamada");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  
  set_help_extras("Damage Type: "+tipo(TIPO)+"\nSaving Throw: Level Constitution and Resist Poison");
  set_help_desc("This spell causes the victim lose HP at a rate dependent on "
    " the victims constitution. There is an initial saving throw based "
    " on relative level and constitution. And a 100% save for resist "
    " poison. Note that the intended victim will become immune for a "
    " period if the initial attack fails. "
    " The strength of the poison depends on casters guild and level. "       
    " Cyrcia priests poison is twice as powerful as that of other "
    " priests at the same level. "
    " Neutralize poison will neutralize this spell.");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int quiet, int time)
{
  if (wrong_alignment(caster))
  {
    punish_align(caster);
    return 0;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if (target->QP("poisoned") || target->QP("poison") || target->query_dead() || target->QP("undead"))
  {
    tell_object(caster,target->QCN+" cannot be poisoned.\n");
    target->attack_by(caster);
    return 0;
  }

  if (random(target->QL+target->query_con())>random(caster->QL*2))
  {
    target->ATP("poison",50,caster->QL*60);
    tell_object(caster,"Oops your target was unharmed by the attack.\n");
    tell_object(target,caster->QCN+" hisses at you strangely. Must have been some sort of failed attack.\n");
    tell_room(ENV(caster),caster->QCN+" looks strangely at "+target->QCN+".\n",({caster,target}));
    target->attack_by(caster);
    return 1;
  }

  setup_poison(-fix_damage(caster,target,-caster->QL/2),caster,target);
  tell_object(caster,"You scratch "+target->QCN+", leaving a festering, poisoned wound.\n");
  tell_object(target,caster->QCN+" scratches you, and a festering wound appears on you!\n");
  tell_room(ENV(caster),caster->QCN+" scratches and poisons "+target->QCN+
    " leaving a festering wound.\n",({caster,target}));
  target->attack_by(caster);
  return 0;
}
