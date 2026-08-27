// Vilat 22.10.2002
// NPC entrenador de Skills

#include <money.h>
inherit "/obj/monster";

mixed skills_entrenables=({});
string hab;
int ml;
int lvlactual;
int coste;
int scost;
int puntos;
int pback;
object plent;

int entrenamiento2(string str);
int calcular_puntos(int level, int n);

void add_skill_entrenable(string skill, int minlevel, int maxlevel,string clase) {
	skill=CAP(skill);
	clase=CAP(clase);
	if(member_array(skill,skills_entrenables)==-1) {
		skills_entrenables+=({skill,minlevel,maxlevel,clase});
		return;
		}
	for (int i=0;i<sizeof(skills_entrenables);i+=4) if(skills_entrenables[i]==skill) {
		skills_entrenables[i+1]=minlevel;
		skills_entrenables[i+2]=maxlevel;
		skills_entrenables[i+3]=clase;
		}
	return;
	}

void init() {
	::init();
	add_action("lista","listar");
	add_action("entrenamiento","entrenar");
	}

int lista() {
	if(!sizeof(skills_entrenables)) return notify_fail(TO->query_short()+" dice: No tengo nada que ensenyarte.\n");
	tell_object(TP,TO->query_short()+" dice: Puedo entrenarte en las siguientes habilidades:\n");
	for (int i=0;i<sizeof(skills_entrenables);i+=4) tell_object(TP,TO->query_short()+" dice: "+skills_entrenables[i]+" del nivel "+(string)skills_entrenables[i+1]+" a "+(string)skills_entrenables[i+2]+" si eres "+skills_entrenables[i+3]+".\n");
	return 1;
	}

int entrenamiento(string str) {
	int i;
	if(TP->query_dead()) return notify_fail(TO->query_short()+" pregunta: De veras quieres que entrene a un muerto?\n");
	if(!str) return notify_fail("Debes especificar que quieres entrenar.\n");
	if(!sizeof(skills_entrenables)) return notify_fail(TO->query_short()+" dice: No tengo nada que ensenyarte.\n");
	str=CAP(str);
	if(member_array(str,skills_entrenables)==-1) return notify_fail(TO->query_short()+" dice: No puedo ensenyarte eso.\n");
	for (i=0;i<sizeof(skills_entrenables);i+=4) if(skills_entrenables[i]==str) break;
	if(skills_entrenables[i+3]!=CAP(TP->query_property("clase"))&&skills_entrenables[i+3]!="General") return notify_fail(TO->query_short()+" dice: Solo ensenyare esa habilidad a un "+skills_entrenables[i+3]+".\n");
	lvlactual=TP->query_habilidad(str);
	ml=skills_entrenables[i+2];
	if(skills_entrenables[i+1]>lvlactual) return notify_fail(TO->query_short()+" dice: No ensenyare a alguien tan inexperto como tu.\n");
	if(ml<lvlactual) return notify_fail(TO->query_short()+" dice: No tengo nada que ensenyarte, pues sabes mas que yo.\n");
	tell_object(TP,TO->query_short()+" pregunta: Cuanto quieres entrenar?\n");
	hab=skills_entrenables[i];
	puntos=0;
	plent=TP;
	input_to("entrenamiento2",2);
	return 1;
	}

int entrenamiento2(string str) {
	if (!str) return 0;
	sscanf(str, "%d", puntos);
	if(!puntos) {
		tell_object(plent,TO->query_short()+" dice: De acuerdo, no te ensenyare nada.\n");
		return 1;
		}
	if(plent->query_habilidad(hab)+puntos>ml) return tell_object(plent,TO->query_short()+" dice: No puedo ensenyarte tanto.\n");
	pback=plent->query_habilidad(hab)+puntos;
	puntos=calcular_puntos(lvlactual,puntos);
	if(puntos>plent->query_disp_sp()) return tell_object(plent,TO->query_short()+" dice: Lo siento pero no tienes suficientes Puntos de Skill.\n");
	coste=puntos*scost;
	if(coste>plent->query_value()) return tell_object(plent,TO->query_short()+" dice: Lo siento pero no tienes suficiente dinero.\n");

	tell_object(plent,TO->query_short()+" pregunta: Eso te costara "+(string)MONEY_HAND->money_value_string(coste)+" y "+(string)puntos+" Puntos de Skill, sigues queriendo entrenarte?\n");
	input_to("entrenamiento3",2);
	return 1;
	}

void set_coste(int i) { if (i>0) scost=i*100; }

int calcular_puntos(int level, int n) {
	int tmp;
	for(int i=level;i<n+level;i++) {
		if(i>90) tmp++;
		if(i>80) tmp++;
		if(i>60) tmp++;
		if(i>40) tmp++;
		if(i>20) tmp++;
		tmp++;
		}
	return tmp;
	}

int entrenamiento3(string str) {
	str=lower_case(str);
	if(!str||member_array(str,({"s","n"}))==-1) {
		tell_object(plent,TO->query_short()+" dice: Debes responder 's' o 'n'.\n");
		input_to("entrenamiento3",2);
		return 1;
		}
	if(str=="n") return tell_object(plent,TO->query_short()+" dice: De acuerdo, no te entrenare esta vez.\n");
	plent->pay_money(coste);
	plent->adjust_disp_sp(-puntos);
	plent->set_habilidad(hab,pback);
	tell_object(plent,TO->query_short()+" te entrena en la skill \""+hab+"\" hasta el nivel "+(string)pback+".\n");
	return 1;
	}

