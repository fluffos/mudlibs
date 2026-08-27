//Coletazo de los Guerreros del Pantano by Gurthang'Jun00.
//Cavas, Ene'03 metiendo la manaza como siempre.

inherit "/std/commands/base_command";
#include <spells.h>

#define LVL             caster->query_level()
#define FUE             caster->query_str()
#define COSTE           1
#define FALLO(s)        { notify_fail(s+"\n"); return 0;}
#define INFO(s)         { tell_object(caster,s+"\n"); return 0;}
#define STATTARGET      ( target->query_con()+target->query_dex() )
#define ACTARGET        ( 100-target->query_total_ac() )/2
#define BASETARGET      ( STATTARGET+ACTARGET)
#define BASECASTER      (LVL + caster->query_dex()+caster->query_str() )
#define DANYO           ((LVL+FUE)/2)
#define PIFIA           ( random(BASETARGET)-random(BASECASTER)-LVL )

void setup()
{
  set_command_name("coletazo");
  target_type = "one";
  lockout = 0;
  only_combat();
  set_help_string(
    "\n\n"
    "Nombre del Comando:  Coletazo\n"
    "Coste de GP:         2\n"
    "Sintaxis:            coletazo <objetivo>\n"
    "Descripcion: \n"
    "Los hombre-lagartos son la unica raza que posee una cola, y no todos "
     "ellos saben manejarla como un arma letal. Los Guerreros Saurios son "
    "maestros en el arte de golpear al enemigo con la cola. Mientras con las "
     "garras distraen la atencion del enemigo, sin previo aviso le golpean con "
    "ella desde angulos inexperados.\n\n");
}

int coletazo(string str, object ob)
{
   return ::exec_command(str,ob);
}


int do_command(object target, object caster)
{
  int cost = COSTE;
  string *alis = ({ }); 
         
  if(!caster->query_race_name("Hombre-Lagarto"))
    FALLO("Creo que te has confunido de raza y no tienes una cola para golpear.\n")
  if (caster->query_timed_property("lagarto_property") && !DEBUG(caster))
    FALLO("Tu cola no es tan rapida como para volver ha golpear a tu enemigo.\n")
  if(!command_cost(cost,caster,0))
    FALLO("Estas tan cansado que no puedes ni mover tu cola.\n")
  if (member_array(target,caster->query_attacker_list())>-1)
  {
  tell_object(caster,"Disimulando tus movimientos te pones en posicion para "
        "golpear a "+target->query_cap_name()+" con tu cola.\n");
  caster->add_timed_property("lagarto_property",1,3);
  caster->adjust_gp(-cost);
  call_out("hacer_strike",0,caster,target);
  return 1;
  }
  else {
  notify_fail("No estas en lucha con "+target->query_cap_name()+".\n");  
  return 0;
  }
} 
 


void hacer_strike(object caster,object target)
{
  int Danyo;
  int Pifia;
  
  if(!target)
  {
     tell_object(caster,"Mucho disimular tu ataque para que al final tu enemigo"
                 " no este.\n");
     tell_room(ENV(caster),caster->query_cap_name()+" realiza un giro de cintura "
                "golpear a su enemigo con la cola, pero donde esta este?\n",caster);
     return 1;
   }
  if(target->query_dead())
  {
    notify_fail("Tu objetivo ya esta muerto, aun quieres seguir pegandole ?.\n");
    return 0;
  }
  if(ENV(caster)!=ENV(target))
  {
      tell_object(caster,"Mucho disimular tu ataque para que al final tu enemigo "
                "no este.\n");
     tell_room(ENV(caster),caster->query_cap_name()+" realiza un giro de cintura "
                "golpear a su enemigo con la cola, pero donde esta este?\n",caster);
     return 1;
   }
     
  if ((Pifia=PIFIA)>=0)
  {
    tell_object(caster,"Casi pero tu oponente te ha visto llegar.\n");
    tell_object(target, "Te das cuenta de la intenciones de "
       +caster->query_cap_name()+" y esquivas su coletazo.\n");
    tell_room(ENV(caster), caster->query_cap_name()+" intenta golpear a "+
        target->query_cap_name()+" con su cola pero falla.\n", ({ caster, target }));
      target->attack_by(caster);
      caster->attack_by(target);
    return 1;
  }
  else
  {
     Danyo = DANYO;
     tell_object(target, caster->query_cap_name()+" te golpea en la cara con "
        "un rapido movimiento de su cola.\n");
     tell_object(caster, "Golpeas a "+target->query_cap_name()+" dejando algunos "
        "moratones alli donde le has alcanzado con la cola.\n");
     tell_room(ENV(caster),  caster->query_cap_name()+" golpea con la cola la "
               "cara de "+target->query_cap_name()+".\n", ({ caster, target }) );
    
     Danyo = Danyo + caster->query_damage_bonus();
     
     log_comandos("COLETAZO",caster->query_cap_name()+" (LVL) "+caster->query_level()+" golpea a "+target->query_cap_name()+" (LVL) "+target->query_level()+" con Danyo: "+(-Danyo)+"\n");
     command_damage(-Danyo, caster, target);  
  }
  return 1;
}
