inherit "/std/guildroom";
#include "path.h"
#include "config.h"

object guildmaster;

void setup()
{
  set_short(GUILDTITLE);
  set_long(GUILDTITLE+ "\n\n"
           "     This is the great training arena of the Daggerford "
           "ability to crush and mangle.  To the north, you can see a stair"
           " well, which leads up to more rooms of the guild.  To the west "
           "a large open faced building.  There is a large sign attached to"
           " a post in the middle of the ground.  Maybe you'd like to get "
           "some more information on this guild about how to join it.\n\n");
  add_sign("A large sign attached to the wall off to the side.  "
           "It has writting scrawled on it in some "
           "red substance (You're sure its just paint).\n",
           "\t________________________________________  \n"
           "\t|\\______________________________________/| \n"
           "\t||                                      || \n"
           "\t||        %^RED%^WELCOME TO THE ARENA%^RESET%^          || \n"
           "\t||                                      || \n"
           "\t||   -- Type 'join' become a member of  || \n"
           "\t||      fighter's guild.                || \n"
           "\t||   -- For more information on the     || \n"
           "\t||      Fighters' Guild type 'info'.    || \n"
           "\t||   -- To advance your levels type     || \n"
           "\t||      'advance'.                      || \n"
           "\t||   -- To see how much it will take    || \n"
           "\t||      out of you to improve yourself  || \n"
           "\t||      type 'cost'.                    || \n"
           "\t||                                      || \n"
           "\t||______________________________________|| \n"
           "\t|/______________________________________\\| \n\n");
  set_light (50);
  set_exit_color("orange");
  add_exit("este", ROOMDESALIDA, "door");
  set_guild(GUILDOWNER);
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
		if((string)(this_player()->query_guild_ob()) != GUILD)
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


