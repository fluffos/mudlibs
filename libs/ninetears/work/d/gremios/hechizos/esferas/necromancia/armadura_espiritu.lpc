#include <spells.h>
inherit BASE_SPELL;

#define NOMBRE	"Armadura de espiritu"
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	NIVEL	3
#define	CANCION	"'spiritis solis armanis'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo proporciona al hechicero un aura protectora "
    "creada a partir de una porcion de su esecia vital. La armadura espiritual "
    "otorga un bonus a la Clase de Armadura de duracion limitada.\n"
    "Cuando el hechizo acaba, la armadura se disipa y el hechicero pierde "
    "un trozo de su esencia vital, sufriendo 2-8 puntos de danyo, si la tirada "
    "de salvacion es acertada el danyo se reducira a la mitad. "
    "Este hechizo SOLO afecta al hechicero.\n"
    "\nNota: podras quitarte toda tu armadura cuando el hechizo sea formulado,"
    " pero no podras ponertela cuando el efecto de este perdure. "
    "La proteccion y duracion dependera del nivel. "
    "ATENCION: Este hechizo puede matarte si no tienes suficiente puntos de vida "
    "cuando se acabe su duracion.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object shadow;

//  if (!caster || !pointerp(caster)) caster=TP;
  if (caster->query_spirit_armour_spell())
  {
//    tell_object(TP,MSG_AFECTADO);	// Guldan pongo TP por que si te la echas 2 veces seguidas peta ???
    return -1;
  }     

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(caster, "Te rodeas con una capa de tu propia esencia vital.\n");
  tell_room(ENV(caster),caster->QCN+" formula un hechizo y un aura mistica le rodea produciendo una gran conmocion.\n",caster);
  tell_object(caster,"Tu esencia vital te rodea proporcionandote una proteccion adicional.\n");
  shadow=clone_object(SHADOWS+"sp_armour_sh");
  shadow->setshadow(caster,caster->QL*10*POWER); 
  return NIVEL*100;
}

string extra_look()
{
  return "Esta rodeado por un aura mistica brillante.\n";
}
