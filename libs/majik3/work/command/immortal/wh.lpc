
#include <security.h>

int record;

create ()
{
    restore_object ("/data/misc/who");
}

int
main(string arg)
{
    string idle;
    int idle_t;
    object *list;
    int j;
    string flags;
    string meep;
    string *harr;

    message("normal", "^cW^bb" + sprintf("%-78s","WHO LIST WITH LAST COMMANDS (" + query_load_average() + ")")+"^c0\n",THIS);

    for (list = users(), j = 0; j < sizeof (list); j++)
    {
        flags = "";
        if (in_edit (list[j]))
            flags += "E";
        if (in_input (list[j]))
            flags += "B";
        if (query_idle (list[j]) > 60 * 5)
            flags += "I";

        idle_t = 0;
        idle_t = query_idle (list[j]);
        idle = "";

        if (idle_t > 60 * 60 * 24)
            idle = "^c1"+sprintf ("%4d", idle_t / (60*60*24))+"^c0d";
        else if (idle_t > 60 * 60)
            idle = "^c1"+sprintf ("%4d", idle_t / (60* 60))+"^c0h";
        else if (idle_t < 60)
            idle = "^c1"+sprintf ("%4d", idle_t)+"^c0s";
        else
            idle = "^c1"+sprintf ("%4d", idle_t / 60)+"^c0m";

	harr = list[j]->query_clh_arr();

	if (harr)
		meep = harr[sizeof(harr) - 1];
	else
		meep = "";

	if (strlen(meep) > 52)
		meep = meep[0..51];

         if (list[j]->query_security() >= SEC1)
        {
            message ("normal","^c0^cp<^c0^c1" + sprintf("%3s",flags) + "^c0^cp>^c0 " + sprintf("%-11s %-52s (%s)\n",capitalize(list[j]->query_name()),meep,idle),THIS);
        }
        else
        {
            message ("normal","^c0^cc[^c0^c1" + sprintf("%3s",flags) + "^c0^cc]^c0 " + sprintf("%-11s %-52s (%s)\n",capitalize(list[j]->query_name()),meep,idle),THIS);
        }
    }
    if (j > record) {
        record = j;
        save_object ("/data/misc/who");
    }

    message("normal","^c1"+ j + "^c0 players shown (best: ^c1" + record + "^c0 players). (^cp<>^c0=immortal, ^cc[]^c0=mortal)\n",THIS);
    return 1;
}
