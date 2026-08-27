#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Restauracion"
#define	NIVEL	7
#define	ESCUELA	({""})
#define	ESFERA	({"curadora"})
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("Cuando este hechizo es formulado, todas las caracteristicas que hubiera "
    "sido alteradas por algun metodo, ya sea resucitar o cualquier otro, "
    "volveran a su estado normal.");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
  tell_object(caster,"Comienzas a invocar a tu Dios "+capitalize(caster->query_deity())+".\n");
  tell_room(ENV(caster),caster->QCN+" comienza a invocar a su Dios.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int rest,stat,adj;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target==caster)
  {
    tell_object(caster,"No puedes formular este hechizo sobre ti mismo.\n");
    return -1;
  }

  if (target->query_deity()!=caster->query_deity())
  {
    tell_object(caster,target->QCN+" no sigue a la misma deidad que tu. No puedes restaurar a "+target->QCN+".\n");
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,"Tu foco de energia positiva formula el hechizo.\n");
    tell_object(caster,"Tocas a "+target->QCN+" restaurandolo con la energia.\n");
    tell_object(target,caster->QCN+" te toca, causando que te sientas revitalizado.\n");
    tell_room(ENV(caster),caster->QCN+" toca a "+target->QCN+" causando que "+target->QCN+" se vea revitalizado.\n",({caster,target}));
  }

  rest=MIN(18,caster->QL/(10-POWER*2));

  if (target->query_tmp_str()<0)
  {
    if (rest>-target->query_tmp_str()) target->adjust_tmp_str(-target->query_tmp_str());
    else target->adjust_tmp_str(rest);
    return 0;
  }

  if(target->query_tmp_dex()<0)
  {
    if (rest>-target->query_tmp_dex()) target->adjust_tmp_dex(-target->query_tmp_dex());
    else target->adjust_tmp_dex(rest);
    return 0;
  }
 
  if(target->query_tmp_con()<0)
  {
    if (rest>-target->query_tmp_con()) target->adjust_tmp_con(-target->query_tmp_con());
    else target->adjust_tmp_con(rest);
    return 0;
  }

  if(target->query_tmp_int()<0)
  {
    if (rest>-target->query_tmp_int()) target->adjust_tmp_int(-target->query_tmp_int());
    else target->adjust_tmp_int(rest);
    return 0;
  }

  if(target->query_tmp_wis()<0)
  {
    if (caster->query_guild_name()!="Clerigo de Gestur" && 
        caster->query_guild_name()!="Clerigo de Lummen")
    {
      if (rest>-target->query_tmp_wis()) target->adjust_tmp_wis(-target->query_tmp_wis());
      else target->adjust_tmp_wis(rest);
      return 0;
    }
  }

  if(target->query_tmp_cha()<0)
  {
    if (rest>-target->query_tmp_cha()) target->adjust_tmp_cha(-target->query_tmp_cha());
    else target->adjust_tmp_cha(rest);
    return 0;
  }
}
