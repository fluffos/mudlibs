
#include "money.h"
int a;
int fix(string str,object fixer)
{
	if (!fixer) fixer = this_player();
	//if(fixer->query_fighting()) {
	
	if(fixer->query_creator()) {
		tell_room(fixer, "Tyrael es generoso, pero %^BOLD%^RED%^Leviathan%^RESET%^ lo es mas, y te restaura tu vida y tus\npuntos de guild al reconocerte como Creador.\n\n");
                fixer->set_gp(fixer->query_max_gp(), fixer);
                fixer->set_hp(fixer->query_max_hp(), fixer);
		return 1;
	}
	if(sizeof(fixer->query_attacker_list())) {
		notify_fail("Muahaha... no querras curarte mientras estas en peleas? xD\n");
		return 0;
	}
	if(fixer->query_property("nosanar")) {
		notify_fail("No consigues concentrarte para invocar el poder sanador de Tyrael.\n");
		return 0;
	}
	if(fixer->query_hp()>fixer->query_max_hp()/2){
		notify_fail("Tyrael se niega a curar a alguien en tan buen estado.\n");
		fixer->set_gp(fixer->query_max_gp(), fixer);
		return 0;
	}

	if (fixer->query_fighting()) {
		notify_fail("Tyrael te da energia pero se niega a darte vida hasta que mates a tus enemigos.\n");
		fixer->set_gp(fixer->query_max_gp(), fixer);
		return 0;
	}
	

	fixer->add_timed_property("nosanar", 1, fixer->query_level());
	tell_object(fixer, "Sientes como Tyrael se adentra en ti y restaura tu vitalidad y energia. Masomenos...\n");
	if (!fixer->query_hidden())
		tell_room(environment(fixer), fixer->query_short() + " invoca la presencia de los dioses y sus heridas mas graves desaparecen.\n", fixer);
	
	a=(random(fixer->query_max_gp()/3))+(fixer->query_max_hp()/2);
	fixer->set_hp(a, fixer);
	fixer->set_gp(fixer->query_max_gp(), fixer);
	return 1;
}
