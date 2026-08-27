#include "/d/gremios/comandos/tweaks.h"
#define AC_PENALTY 15

void make_spell(object doer, object victim);

string help()
{
    return
    "\n\n"
    "Comando : Duende de fuego\n"
    "Sintaxis: duende <objetivo>\n"
    "Coste en Pg: 10\n"
    "Descripcion: \n"
    "     El duende de fuego te permite sumir a alguien en llamas incandescentes, "
    "haciendo de el un objetivo mas facil para un ataque de mele.\n\n";
}

int faerie(string str, object doer) 
{ 
    object *vlist;
    object victim;

    if (!str)
    {
	write("Quien es tu objetivo?\n");
	return 1;
    }
   if(!doer) doer = TP;

    vlist = find_match(str, environment(doer));

    if(!sizeof(vlist)) {
	write("Intentalo con algo que este aqui.\n");
	return 1;  }

    victim=vlist[0];

    if(victim->query_hide_shadow()) {
	write("Intentalo con alguien que este aqui.\n");
	return 1; } 

    if(doer->query_property("pacify_on")) {
	write("Alguna cosa te previene de hacer esto\n");
	return 1; }

    if(victim->query_dead()) {
	write("Esto no tiene efecto en un espiritu\n");
	return 1;  }

    if(victim->query_property("pacify_on"))  {
	write("Esto es demasiado fuerte para hacerlo ahora.\n");
	return 1;  }

    if(victim == doer)  {
	write("No es muy brillante hacer esto.\n");
	return 1;  } 

    if(victim->query_static_property("faerie_on"))  {
	write("Tu objetivo ya esta bajo los "
	  "efectos del duende de fuego.\n\n");
	return 1;  }

    if(doer->query_timed_property("FAERIE")) {
	write("Tendras que esperar antes de hacer esto de "
	  "nuevo.\n");
	return 1;  }

    if((doer->query_race() == "Elfo" ||
	doer->query_race() == "Medio-Elfo") &&
      environment(doer)->query_light() < 10)  {
	write("No eres capaz de encontrar a tu objetivo "
	  "con tanta oscuridad.\n");
	return 1;  }

    if((doer->query_race() == "Drow" ||
	doer->query_race() == "Medio-Drow") &&
      environment(doer)->query_light() > 80) {
	write("La luz brilla demasiado para localizar "
	  "exactamente a tu objetivo.\n\n");
	return 1; }


    doer->adjust_gp(-10);
    call_out("make_spell", 0, doer, victim);
    if(!doer->query_hide_shadow())  victim->attack_by(doer);

    return 1;
}


void make_spell(object doer, object victim)
{
    int duration;
    duration = (doer->query_int()+doer->query_level())*2;

    tell_object(doer,"\n     Levantas un dedo y senyalas en la direccion de "
      +victim->query_cap_name()+", unas llamas se abalanzan y le engullen.\n");
      
    if(!doer->query_hide_shadow())
	tell_object(victim, "\n     "+doer->query_cap_name()+" levanta un dedo "
	  "en tu direccion, y de repente eres engullido por llamas "
	  "incandescentes!\n");
    else
	tell_object(victim, "     Eres engullido en llamas "
	  "incandescentes!\n");

    tell_room(environment(victim), "\n     "+victim->query_cap_name()+
      " es engullido por llamas incandescentes!!\n", 
      ({doer, victim}));

    victim->adjust_tmp_ac_bon(-AC_PENALTY);
    victim->add_extra_look(this_object());
    victim->add_static_property("faerie_on", 1);
    doer->add_timed_property("FAERIE", 1, 900);

    call_out("wear_off",duration, victim);
}

void wear_off(object victim)
{
    if(victim)
    {
	victim->adjust_tmp_ac_bon(AC_PENALTY);
	tell_object(victim, "Las llamas de tu alrededor se apagan.\n");
	victim->remove_extra_look(this_object());
	victim->remove_static_property("faerie_on");
    }
}

string extra_look()
{
    return "Esta circundado por llamas incandescentes que le hacen un objetivo "
    "facil.\n";
}
