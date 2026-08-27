#include "/d/gremios/comandos/tweaks.h"
#define AC_PENALTY 15

void make_spell(object doer, object victim);

string help()
{
    return
    "\n\n"
    "Nombre del Comando: Fuego Fatuo\n"
    "Sintaxis: fuegofatuo <objetivo>\n"
    "Coste GPs: 10\n"
    "Descripcion: \n"
    "     Faerie fire lets you engulf somebody in sparkling flames, "
    "making him an easier target to melee attack.\n\n";
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
	write("Prueba con alguien que este aqui.\n");
	return 1;  }

    victim=vlist[0];

    if(victim->query_hide_shadow()) {
	write("Prueba con alguien que este aqui.\n");
	return 1; } 

    if(doer->query_property("pacify_on")) {
	write("Algo te impide gestar el fuego fatuo.\n");
	return 1; }

    if(victim->query_dead()) {
	write("No tendria ningun efecto sobre un espiritu.\n");
	return 1;  }
/*
    if(victim->query_property("pacify_on"))  {
	write("This one's way too harmless already.\n");
	return 1;  }*/

    if(victim == doer)  {
	write("No es una brillante idea.\n");
	return 1;  } 

    if(victim->query_static_property("faerie_on"))  {
	write("Tu objetivo ya se encuentra bajo el efecto "
	  "del fuego fatuo.\n\n");
	return 1;  }

    if(doer->query_timed_property("FAERIE")) {
	write("Deberas esperar antes de ser capaz de volver a generar "
	  "el fuego fatuo.\n");
	return 1;  }

    if((doer->query_race() == "elfo" ||
	doer->query_race() == "medio-elfo") &&
      environment(doer)->query_light() < 10)  {
	write("No eres capaz de encontrar tu objetivo en esta "
	  "oscuridad.\n");
	return 1;  }

    if((doer->query_race() == "drow" ||
	doer->query_race() == "medio-drow") &&
      environment(doer)->query_light() > 80) {
	write("La luz es tan brillante que no eres capaz de localizar "
	  "a tu objetivo.\n\n");
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
      +victim->query_cap_name()+", y unas llamas rojas surgen envolviendo"
      +victim->query_objective()+".\n");

    if(!doer->query_hide_shadow())
	tell_object(victim, "\n     "+doer->query_cap_name()+" levanta un dedo "
	  "en tu direccion, y eres envuelto en "
	  "llamas!\n");
    else
	tell_object(victim, "     De repente eres envuelto en "
	  "llamas!\n");

    tell_room(environment(victim), "\n     El cuerpo de "+victim->query_cap_name()+
      " se ve de repente envuelto en llamas!!\n", 
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
	tell_object(victim, "Las llamas de tu alrededor mueren.\n");
	victim->remove_extra_look(this_object());
	victim->remove_static_property("faerie_on");
    }
}

string extra_look()
{
    return "Esta envuelto por unas llamas que hacen de el un objetivo "
    "facil.\n";
}
