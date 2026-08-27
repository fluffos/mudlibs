#include <spells.h>
inherit BASE_SPELL;

#define NOMBRE  "Invocar ayudante"
#define NIVEL   9
#define ESCUELA ({""})
#define ESFERA  ({""})
#define CANCION ""
#define GP_COST 50

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este Hechizo convoca a un guerrero que protegera al Hechicero "
    "de cualquier agresion, sirviendole cual vasallo. El nivel "
    "del ayudante depende del nivel del Hechicero, al igual que la habilidad de este.\n");
  set_gp_cost(NIVEL);
  set_casting_time(3);
  set_rounds(({"round1","round2","round3"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Inicias tu canto pronunciando palabras arcanas ya casi olvidadas.\n");
  tell_room(ENV(caster),caster->QCN+" inicia un canto arcano con palabras ya casi olvidadas.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"El canto adquiere un tono embrujador y seductor mientras a tu alrededor se\nlevanta un aire sobrenatural que revuelve tus ropajes.\n");
  tell_room(ENV(caster),"El canto de "+caster->QCN+" adquiere un tono embrujador y seductor al tiempo que se levanta el aire a tu alrededor revolviendo tu pelo y ropajes.\n",caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;
  int nivel;
  
  if (caster->QP("matador_de_ayudantes"))
  {
    tell_object(caster, "Al final de tu hechizo nadie viene a ayudarte pues te has convertido ahora en alguien despreciable al matar a tus propios protectores.\n");
    tell_room(ENV(caster),"Al final del hechizo resulta que nadie viene a ayudar a "+caster->QCN+".\n",caster);
    return -1;
  }

  if (!caster->QP("protector_sumoneado"))
  {
    tell_object(caster,"El final del hechizo es espectacular. Se abre un portal delante de ti que comunica las dimensiones de la magia con la del tiempo mortal, de el aparece una figura que poco a poco toma cuerpo y forma, tu protector ha llegado.\n");
    tell_room(ENV(caster),caster->QCN+" finaliza su hechizo de una forma espectacular. Se abre un portal entre dos dimensones y de el aprarece una figura que poco a poco toma forma y cuerpo, su protector ha llegado.\n",caster);
    ob=clone_object("/std/spells/wizard/magoguerrero/protector");
    ob->set_owner(caster);
    ob->move(ENV(caster));  
    caster->ATP("protector_sumoneado",1,200+caster->QL*20);
  }
  else tell_object(caster,"No puedes volver a pedir la proteccion de otro protector de momento, tendras que esperar un rato mas.\n");
  return 1;
}
