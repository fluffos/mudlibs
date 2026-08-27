// Apellido - Tyrael - Jun'02

#include <standard.h>
#include <cmd.h>
#include <player.h>

inherit CMD_BASE;

void setup()
{
	position = 0;
}

string query_usage()
{
	return "apellido <apellido>";
}

string query_short_help()
{
	return "Sirve para ponerte un apellido.";
}


int cmd (string str, object me)
{
	if (me->query_apellido()!="") {
		tell_object(me, "Ya tienes un apellido.\n");
		return 1;
	}

	if (me->query_race_name() == "drow") {
		string casa = me->query_race_group_name();
		
		if (!casa) {
			tell_object(me, "Aun no tienes casa.\n");
			return 1;
		}
		str = casa[8..sizeof(casa)];
	}
	if (!str) {
		tell_object(me, "Si indicas el apellido mejor aun.\n");
		return 1;
	}

	// Usar replaces para colores
	me->set_apellido(str);
	return 1;
}
