#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Drenar energia"
#define	NIVEL	7
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica","lummen"})
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("Cuando este hechizo es formulado, el destinatario corre el riesgo de "
     "ser drenado, es decir, de ser reducido(s) alguno(s) de su(s) stat(s).\n");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
  tell_object(caster,"Empiezas a rezar a "+capitalize(caster->query_deity())+".\n");
  tell_room(ENV(caster),caster->QCN+" parece estar rezando a alguien.\n",caster);
  return NIVEL*100;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int drain,stat,adj;

  if (caster->QP("energy_drained"))
  {
    notify_fail("Es demasiado pronto para formular este hechizo de nuevo, la energia negativa parece estresar tu cuerpo.\n");
    return -1;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target==caster)
  {
    tell_object(caster,"No puedes formular este hechizo sobre ti.\n");
    return -1;
  }

  if (target->query_deity()==caster->query_deity())
  {
    tell_object(caster,target->QCN+" sigue al mismo dios que tu. No puedes drenar a "+target->query_objective()+".\n");
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,"Empiezas a reunir energia negativa.\n");
    tell_object(caster,"Tocas a "+target->QCN+" drenando su energia.\n");
    tell_object(target,caster->QCN+" te toca, provocandote una gran debilidad.\n");
    tell_room(ENV(caster),caster->QCN+" toca a "+target->QCN+" y notas que "+target->QCN+" se siente debil.\n",({caster,target}));
  }

  drain=MIN(18,caster->QL/(10-2*POWER));
  caster->ATP("energy_drained",1,1000);

 if (interactive(target))
  if (target->query_tmp_str()>=0)
  {
    if (drain>target->query_str()-3) target->adjust_tmp_str(-target->query_str()-3);
    else target->adjust_tmp_str(-drain);
    return NIVEL*100;
  }
  if (target->query_tmp_dex()>=0)
  {
    if (drain>target->query_dex()-3) target->adjust_tmp_dex(-target->query_dex()-3);
    else target->adjust_tmp_dex(-drain);
    return NIVEL*100;
  }
  if (target->query_tmp_con()>=0)
  {
    if (drain>target->query_con()-3) target->adjust_tmp_con(-target->query_con()-3);
    else target->adjust_tmp_con(-drain);
    return NIVEL*100;
  }
  if (target->query_tmp_int()>=0)
  {
    if (drain>target->query_int()-3) target->adjust_tmp_int(-target->query_int()-3);
    else target->adjust_tmp_int(-drain);
    return NIVEL*100;
  }
  if (target->query_tmp_wis()>=0)
  {
    if (caster->query_guild_name()!="Clerigo de Gestur"&&
        caster->query_guild_name()!="Clerigo de Lummen"&&
        caster->query_guild_name()!="Cleriga de Astaroth")
    {
      if (drain>target->query_wis()-3) target->adjust_tmp_wis(-target->query_wis()-3);
      else target->adjust_tmp_wis(-drain);
      return NIVEL*100;
    }
  }
  if (target->query_tmp_cha()>=0)
  {
    if (drain>target->query_cha()-3) target->adjust_tmp_cha(-target->query_cha()-3);
    else target->adjust_tmp_cha(-drain);
    return NIVEL*100;
  }
  return NIVEL*100;
}
