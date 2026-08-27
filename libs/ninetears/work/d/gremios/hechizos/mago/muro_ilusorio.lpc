#include <spells.h>
inherit BASE_SPELL;

string	NOMBRE	= "Muro Ilusorio";
mixed	ESCUELA	= ({"wizwar"});
mixed	ESFERA	= ({""});
int	NIVEL	= 4;
string	CANCION	= "'megnoui ilerium cezan'";
string	LOCKOUT	= "muro_ilusion_hecho";
#define	WALLFIRE_DURATION_LEVELX	6

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("pass");
  set_range(0);
  set_help_extras("La direccion proveniente de la salida bloqueada sera "
                  "accesible de todas formas, pues la ilusion solo afecta "
                  "a una de las partes de la misma.");
  set_help_desc("Este hechizo crea un muro ilusorio que permite al mago "
                "bloquear una salida aunque el pueda pasar a traves de "
                "ella. Esto puede ser muy util para escapar, pero cuidado, "
                "el perseguidor puede darse cuenta que no es real e ignorarlo.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
  object ob,*obs;
  int i,num_exits,kill_flag;

  if (caster->QP(LOCKOUT))
  {
    tell_object(caster,"Aun no estas preparado para poder formular otro hechizo.\n");
    return -1;
  }

  if (!(ENV(caster)->query_exit(target)))
  {
    tell_object(caster,"Miras a tu alrededor y te percatas que no hay salidas en esa direccion.\n");
    tell_room(ENV(caster),caster->QCN+" mira a su alrededor confundido y dejar de recitar "
                          "el hechizo.\n",caster);
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }
  ob=clone_object("/d/gremios/hechizos/objetos/muro_ilusion");
	// muro hay q ponerlo en objetos
  ob->set_spell(caster,target);
  ob->move(ENV(caster));
  caster->ATP(LOCKOUT,1,50);
}
