// Traducido por Lummen 28-7-97
// Guldan Jul'98

#include <spells.h>
inherit BASE_SPELL;

#define MULT 3
#define TRAP_GP 15
#define TRAP_LOCKOUT 100
#define LOCKOUT "trap"

int OK; // NOT nice *sigh*
string item;
string trap = "/std/spells/wizard/maj_missile";
string trap_desc = "Un pequenyo cofre, cubierto de runas, que por alguna razon te preocupa.\n";
int trap_target;

void setup()
{
  set_spell_name("Trampa");
  set_school("Wizthief");
  set_spell_level(30);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_gp_cost(5);
  add_property_to_check(LOCKOUT);
  set_help_desc("Este es el hechizo base de una trampa magica.\n");
  set_help_extras("Nota: El coste en GP de este hechizo esta incluido en el coste "
    "del comienzo del hechizo \"trampa\".\n");
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object *list;
  OK = 0;

  if (stringp(item))
  {
    list = find_match(item,caster);
    if (!sizeof(list))
    {
      tell_object(caster,"No tienes el objeto "+item+" necesario para realizar el hechizo.\n");
      tell_room(ENV(caster),caster->QCN+" intenta resolver un pequenyo acertijo perdiendo algo de tiempo.\n");
      OK = -1;
      return 0;
    }
    list[0]->move(ENV(caster));
    list[0]->dest_me();
    tell_object(caster,"El objeto "+item+" comienza a desvanecerse hasta transformase en una sustancia con poder.\n");
  }
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if (OK==-1) return 0;

  if (!quiet)
  {
    tell_object(caster,"Pronuncias el cantico 'entrapous snarium'.\n");
    if (!TO->query_hide_shadow())
      tell_room(ENV(caster),caster->QCN+" pronuncia el cantico 'entrapous snarium'.\n",({caster}));
  }
  caster->ATP(LOCKOUT,1,TRAP_LOCKOUT);
  caster->ATP("trap_aware",1,100);
  ob=clone_object(OBJETOS+"trap");
  ob->move(ENV(caster));
  // ob->set_trap(trap,trap_target,300,500,trap_desc);
  ob->set_trap(trap,trap_target,MULT*caster->query_int()+caster->QL,500,trap_desc); 
  tell_object(caster,"Seleccionas una trampa magica en las sombras.\n");
  if (!TO->query_hide_shadow())
    tell_room(ENV(caster),caster->QCN+" selecciona una trampa en las sombras.\n",caster);
}
