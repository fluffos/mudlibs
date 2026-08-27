/* Traducido por Lummen '98
 * Unholy Word is a spell by which evil clerics can 'strike down' their
 * opponents, calling upon their god(ess)' power to brand the target
 * with the holy symbol of the deity.  This 'brand' reduces the
 * target's ability to function... he/she is flooded with lethargy
 * and fear, making even the simplest application of guild or
 * spell abilities difficult.  Furthermore, until the symbol
 * has been removed, (by a dispel magic spell [maybe], or over a period
 * of time), the target is unable to regen HPs *or* GPs.
 */

#include <spells.h>
inherit BASE_SPELL;
//inherit BASES+"UD_query";

#define	NOMBRE	"Palabra Impia"
#define	NIVEL	7
#define	ESCUELA	({"conjuracion"})
#define	ESFERA	({"combate"})
#define	CANCION	"'xysiargin'"
#define	TIPO	"magical"
#define	OBJETO	OBJETOS+"unholy_obj"

void setup()
{ 
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: Resistencia Magica");
  set_help_desc("Este poderoso hechizo invoca todo el poder de "+
     TP->query_guild_name()+" sobre un oponente. El objetivo afectado pierde "
     "una porcion de su fuerza, y no podra regerear puntos de vida y puntos "
     "de guild hasta que el efecto del hechizo se consuman. El poder del "
     "hechizo dependera de la naturaleza destructiva de su deidad. "
     "Consecuentemente, este hechizo podria llegar a curar. Igualmente "
     "importante tenemos que el hechicero debe encontrarse en la "
     "Suboscuridad, donde su deidad basa su poder, en el momento de realizar "
     "el el hechizo.\n");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(ENV(caster),"Una nube oscura comienza a formarse alrededor de "+
    caster->QCN+", del cual comienzan a surgir multitud de relampagos "
    "ruidosos de color morado.\n");
  return NIVEL*100;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;
  int resist;
  int theroll;
  int i;
  int has_symbol;
  mixed symbol;
  string faith;
  
  faith=target->query_guild_name();
  symbol=find_match("simbolos sagrados",target);

  if (!ENV(caster)->query_underground())
  {
    tell_object(caster,"Estas demasiado lejos de la suboscuridad para que tu deidad te ayude.\n");
    tell_room(ENV(TP),TP->QCN+" para de formular un hechizo.\n",TP);
    return -1;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target->query_property("unholy_on"))
  {
    tell_object(caster,"Tu objetivo ya esta afectado por este hechizo.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  resist=target->query_res("magical");
  theroll=20+random(80);

  if (sizeof(symbol))
  {
    has_symbol=0;
    for (i=0;i<sizeof(symbol);i++)
      if (symbol[i]->QP("faith")==faith) resist+=50;
  }

  if (theroll<resist) 
  {
    tell_object(caster,"Senyalas a "+target->QCN+" pero no parece ocurrirle nada!\n");
    tell_object(target,caster->QCN+" completa el hechizo, y te senyala pero no parece que te ocurra nada.\n");
    tell_room(ENV(caster),caster->QCN+" completa el hechizo y senyala a "+target->QCN+" pero no parece enterarse!\n", ({ caster, target }) );
    return 0;
  }
 
  ob=clone_object(OBJETO);
  ob->set_get();
  ob->move(target);
  ob->reset_get();
  ob->reset_drop();

  target->set_no_heal();
  target->add_extra_look(ob);
  target->ASP("noregen",1);
  target->ATP("unholy_on",1,caster->QL*POWER*2);

  if (target->query_str()>6)
  {
    target->adjust_temp_str(-POWER);
  }

  tell_room(ENV(caster),target->QCN+" es empujado hacia atras por una violenta rafaga de energia, el simbolo de "+capitalize(caster->query_guild_name())+" le corrompe cada centimetro de su piel.\n",({caster,target}));
  tell_object(caster,"Fomulas el hechizo Palabra Arcana sobre "+target->QCN+" y el Simbolo de las "+capitalize(caster->query_guild_name())+" le corrompe cada centimetro de su piel sin que pueda hacer nada para evitarlo!\n");
  tell_object(target, caster->QCN+" completa el hechizo, y sientes como las energia arcanas te recorren todo tu ser introduciendose en tu piel. Tu piel es corrompida por el Simbolo de las "+capitalize(caster->query_guild_name())+"!\n");

  target->attack_by(caster);
  caster->remove_spell("curacion");
  return NIVEL*100;
}
 