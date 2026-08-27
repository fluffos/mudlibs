#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Seto de espinas"
#define	NIVEL	7
#define	ESFERA	({"vegetal"})
#define	ESCUELA	({""})
#define	CANCION	"'deus topiary'"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("none");
  set_range(0);
  set_help_extras("Tipo de Danyo: Fisico\nTirada de Salvacion: Nivel de Destreza");
  set_help_desc("Este hechizo puede crear un seto de espinas en una habitacion."
    "Cualquiera que este en la habitacion sufrira un danyo con tirada de salvacion "
    ", y un danyo extra si atacan al hechicero. "
    "Este hechizo durara 1 turno/nivel +3 , hasta que se disipe, o hasta "
    "que el hechicero salga del juego o muera. El hechicero tiene un x10 "
    "al bonus de salvacion, pero no inmunidad total.");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({({
    "Unos pequenyos brotes comienzan a salir del suelo al ser iluminados por un haz de luz.\n",
    "Unos pequenyos brotes comienzan a salir del suelo al ser iluminados por un haz de luz.\n"
    }),"round2"}));
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if (caster->QP("thorn_hedge_cast"))
  {
    tell_object(caster,"Tu hechizo falla por alguna razon.\n");
    tell_room(ENV(caster),"Un pequnyo haz de luz ilumina la habitacion, pero de pronto se disipa.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  ob=clone_object(OBJETOS+"thorns");
  ob->move(ENV(caster));
  ob->set_spell(caster,3+caster->QL);
  caster->ATP("thorn_hedge_cast",1,50);
  tell_room(ENV(caster),"El haz de luz comienza a brillar intensamente, de pronto los brotes "
    "comienzan a crecer a una velocidad increible, formandose asi un denso Seto de Espinas!\n");
  return 0;
}
