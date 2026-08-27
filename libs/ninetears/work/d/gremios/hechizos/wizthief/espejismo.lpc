#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Espejismo"
#define	ESCUELA	({"proteccion"})
#define	ESFERA	({""})
#define	CANCION	"'sancti numbro duplis'"
#define	NIVEL	3
#define MAX_IMG 8

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo crea imagenes alrededor del objetivo "
    "en forma de espejo. Estas imagenes son indistinguibles con el "
    "objetivo, y los atacantes pueden confunfirse con una imagen, en vez "
    "de acertar al objetivo real. El numero de imganes depende del nivel "
    "del hechicero. La experiencia de los atacantes puede ser determinante "
    "para acertar al objetivo.");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Acumulas magia en tu interior para crear un hechizo de proteccion.\n");
  tell_room(ENV(caster),caster->QCN+" acumula en su interior energia para crear un hechizo de proteccion.\n", caster);
  return 1;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int num_images;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target!=caster)
  {
    tell_object(caster,"Solo puedes formular este hechizo sobre ti mismo.\n");
    return -1;
  }

  if (target->query_mirror_spell())
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

 if((string)TP->query_guild_ob()=="/d/gremios/magos/aweon")
   { num_images=MIN(MAX_IMG,caster->QL/3)+POWER;
     num_images-=1;
   }
 else
    num_images=MIN(MAX_IMG,caster->QL/3)+POWER;

  clone_object(SHADOWS+"mirror_sh")->setup_shadow(target,num_images,caster->QL*POWER*10+10);
  return NIVEL*100+num_images*10;
}

string extra_look(object ob)
{
  // Bug q hacia ver siempre 0 imagenes, pq se usaba TP y era el q mira.
  return "Tiene "+ob->query_mirror_spell()+" imagenes identicas a su alrededor.\n";
}
