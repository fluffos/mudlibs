#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Cambio de Sexo"
#define	NIVEL	7
#define	ESFERA	({"alteracion"})
#define	ESCUELA	({"yvendur"})
#define	CANCION	"'switchum changeum'"
#define	TIPO	"laughter"


void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("Este poderoso conjuro solicita la fuerza suprema "
    "de tu Dios para cambiar el sexo de un objetivo.  "
    "El formulador de este hechizo debe luchar contra la naturaleza, "
    "incluso los mas altos sacerdotes deben estar meditando durante "
    "dias para formularlo.  No garantiza el cambio de sexo al instante "
    "sobre el objetivo ya que depende de un gran nivel de destreza. "
    "La duracion de este hechizo depende del nivel del lanzador.");
  set_gp_cost(15);
  set_casting_time(3);
  set_rounds(({"round1","round2","round3"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Un cumulo de poder se forma delante de ti.\n");
  tell_room(ENV(caster),"Un cumulo de poder se forma delante de "+caster->QCN+".\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (target->query_gender()==1)
  {
    tell_object(caster, "Trasladas todo el poder dentro de tu mente, llamando la fuerza de la naturaleza.\n");
    tell_room(ENV(caster), caster->QCN+" gesticula, y un cumulo de poder extraido de la naturaleza se apodera de su mente\n", caster);
  }
  else
  {
    tell_object(caster, "Traslada el poder de la naturaleza en una nube de energia falica.\n");
    tell_room(ENV(caster), caster->QCN+" traslada el poder de la naturaleza creando una nube de energia falica.\n", caster);
  }
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duracion;


  if (!target->query_alive() || !living(target))
  {
    tell_object(caster,"Esto no tiene sexo.\n");
    tell_room(ENV(caster),caster->QCN+" para de formular un hechizo.\n",caster);
    return 0;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return 0;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  target->set_gender((target->query_gender()==1?2:1));
  duracion=TP->query_level()*3+TP->query_cha()-target->query_level()+random(30);
  if(duracion<0)
     duracion=5;
  call_out("apagate",duracion,target); 
  if (target->query_gender()==1)
  {
    if (target!=caster)
      tell_object(caster,"Concentras todo tu poder en el cuerpo de "+
        target->QCN+".\nUn flash de energia se estrella en la piel de "
        +target->QCN+" y de repente aparece como un nuevo hombre.\n");

    tell_object(target,"Una nube falica se avalnza sobre ti, "
      "el poder de esta nube se extiende por dentro de tus venas convirtiendote en un nuevo hombre.\n");
    tell_room(ENV(caster), caster->QCN+
      " gesticula y una nube falica se adentra en el cuerpo de "+
      target->QCN+".\nUn flash de luz te ciega la cara"
      "... cuando notas que "+target->QCN+" ha sido transformado en un nuevo hombre.\n",
      ({ target, caster }) );
  }
  else
  {
    tell_object(target, "La nube de energia de tu alrededor se "
      "adentra en tu cuerpo ...\n"
      "Notas al instante que has perdido algo de tu cuerpo...\n");
    if ( target != caster )
      tell_object(caster, "Envias flashes de poder sobre el cuerpo "
        "de "+target->QCN+" y este comienza a chillar incesantemente.\nParece "
        "haber perdido algun organo vital.\n");
    tell_room(ENV(caster), caster->QCN+" gesticula, "
      "y el poder que le rodeaba penetra en "+target->QCN+
      "\nEscuchas un grito a tu alrededor despues de ver un flash de luz.\n"
      "Cuando el flash desaparece notas que "+target->QCN+
      " ha perdido algun organo vital.\n",
      ({ target, caster }) );
  }
  return 0;
}


int apagate(object target)
{
  if(target->query_gender()==1)
      target->set_gender(2);
  else
     if(target->query_gender()==2)
        target->set_gender(1);
 
  tell_object(target,"Sufres una mutacion y vuelves a recobrar tu antiguo sexo.\n");
  tell_room(environment(target),target->query_cap_name()+" sufre una mutacion de sexo.\n",target);
  return 1;

}
