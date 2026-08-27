// Paris. Abr'98
// Hechizo para el aliento del dragon. No podia dejar que un aliento
// acido te dijese que eres golpeado por fuego :). Basicamente es, casi casi,
// como la Tormenta de Meteoritos, pero un poquito mas bestia.

#include <spells.h>
#define	NOMBRE "Aliento Acido"
#define	ESCUELA	({"invocacion"})
#define	ESFERA	({})
#define	CANCION	""
#define	NIVEL	9
#define	TIPO	"acid"
#define	SALV	50
#define	SIZE_D	8

inherit BASE_SPELL;

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("many");
  set_range(2);
  set_line_of_sight_needed(1);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: 1/2");
  set_help_desc("El aliento de dragon es un poderoso hechizo que hace que "
     "el atacante exhale una poderosa bola de acido que derrite "
     "todo aquello que toca.\n");
  set_casting_time(2);
  set_gp_cost(NIVEL);
  set_rounds(
  ({({
    "Comienzas a aspirar el aire que te rodea llenando tus pulmones.\n",
    "El aire de tu alrededor empieza a adquirir un olor fetido.\n",
  }),"round2"}));
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,NO_D=MIN(40,caster->QL),i;
 
  if (!quiet)
  {
    tell_room(ENV(caster),caster->QCN+" llena sus pulmones completamente de aire.\n",caster);
    tell_object(caster, "Llenas completamente tus pulmones de aire.\n");
  }

  if (!sizeof(target)) 
  {
    tell_object(caster, "Al expulsar la bola de acido tu bola impacta en la nada.\n");
    tell_room(ENV(caster), caster->QCN+" exhala una bola de acido que impacta en la nada.\n",caster);
    return -1;
  }
  
  tell_object(caster,"Exhalas una bola de acido corrosivo sobre tus enemigos.\n");
  tell_room(ENV(caster),caster->QCN+" exhala una bola de acido muy corrosivo que impacta sobre sus enemigos.\n",caster);

  for (i=0;i<sizeof(target);i++)
  {
    tell_object(target[i],"Una Bola de Acido te golpea derritiendote la piel "
        "y la carne haciendo que gritescon terribles alaridos de dolor.\n");
    tell_room(ENV(target[i]), target[i]->QCN+" desaparece bajo una bola de "
      "acido mientras deja escapar terribles alaridos de dolor \n",target[i]);
    target[i]->destruct_mirror_shadow();
    damage=fix_damage(caster,target[i],-roll(NO_D,SIZE_D));
    target[i]->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
    if (target[i]->query_dead()) tell_object(caster,"La piel de "+target[i]->QCN+
        " se derrite entre gritos de dolor dejando al descubierto sus organos vitales.\n");
    target[i]->attack_by(caster);
  }

  tell_object(caster, "Envuelves a "+query_multiple_short(target)+
    " en una gran bola de acido.\n");

  if (sizeof(out_range)) tell_object(caster,"Ooopps, "+query_multiple_short(out_range)+
      " huye a un lugar seguro.\n");
  return NIVEL*100;
}
