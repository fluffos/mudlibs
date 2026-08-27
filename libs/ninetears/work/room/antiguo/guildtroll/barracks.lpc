inherit "/std/guildroom";
#include "path.h"
#include "config.h"

object guildmaster;

void setup()
{
  set_short(GUILDTITLE);
  set_long(GUILDTITLE+ "\n\n"
           "     Te encuentras a la entrada de una cueva, el olor es nauseabundo, "
           "por el suelo se pueden ver restos de animales a medio comer, y huesos que "
	   "deben de llevar ahi muchos anyos. Es realmente un sitio sobrecogedor, solo "
	   "algun ser sin civilizar podria vivir aqui dentro. Respiras en el aire el aroma "
	   "de la muerte... quizas aqui te podrian ensenyar a matar tu tambien...\n\n");
  add_sign("A large sign attached to the wall off to the side.  "
           "It has writting scrawled on it in some "
           "red substance (You're sure its just paint).\n",
           "\t________________________________________  \n"
           "\t|\\______________________________________/| \n"
           "\t||                                      || \n"
           "\t||   -- Escribe 'join' para ser un      || \n"
           "\t||      miembro del guild de trolls.    || \n"
           "\t||   -- Para mas informacino sobre el   || \n"
           "\t||      guild, escribe 'info'.          || \n"
           "\t||   -- Para avanzar niveles escribe    || \n"
           "\t||      'advanzar'.                     || \n"
           "\t||   -- Para saber la experiencia que   || \n"
           "\t||      necesitas para subir usa el     || \n"
           "\t||      comando 'coste'.                || \n"
           "\t||______________________________________|| \n"
           "\t|/______________________________________\\| \n\n");
  set_light (20);
  set_exit_color("orange");
  add_exit("arriba", ROOMDESALIDA, "door");
  set_guild(GUILD);
set_teaching_person(TEACHINGPERSON);

    add_exit ("sur", ROOMS+"hall", "corridor");
    modify_exit("sur", ({"function", "knight_test"}));


}

void reset()
{
	if (!guildmaster) {
		guildmaster = clone_object(GUILDMASTER);
		guildmaster->move(this_object());
	}
}

int do_join(string str)
{
	if (!guildmaster) {
		notify_fail("No hay nadie que te pueda alistar al gremio en este momento.\n");
		return 0;
	}
	if (guildmaster->query_fighting()) {
		notify_fail("El guildmaster no te puede alistar, esta ocupado pensando en sus enemigos.\n");
		return 0;
	}
	this_player()->set_kill_xp((this_player()->query_level() / 2) * 1000000);
	return ::do_join(str);
}

int do_advance(string str)
{
	if (!guildmaster) {
		notify_fail("No has notado que tu maestro... no esta?\n");
		return 0;
	}
	if (guildmaster->query_fighting()) {
		notify_fail("Tu guildmaster esta mas preocupado en matar a sus enemigos.\n");
		return 0;
	}
	if (::do_advance(str)) {
		this_player()->set_kill_xp((this_player()->query_level() / 2) * 1000000);
		return 1;
	}
	return 0;
}

int knight_test()
{

        if (!guildmaster) {
                notify_fail("Te aprovechas de que no esta el guildmaster para colarte en el gremio.\n");
                return 1;
        }
	else
	{
		if((string)(this_player()->query_guild_ob()) != GUILDOWNER)
		{
		notify_fail("El guildmaster te impide la entrada al gremio.\n");
		return 0;
		}
		else
		{
                return 1;

		}
	}

}


