/********************************************************************
** File:  lawd.c
** Purpose: Keeps track of the legal goings on in and around
**     the start area.
** Credits/Blame:
**   31 May 99   Cyanide created the file.
********************************************************************/

inherit DAEMON;

int is_suspect(mixed);

string *suspects;

/*******************************************************************/

void create() {
    suspects = ({});
}

/*******************************************************************/

varargs int add_suspect(mixed mix) {
    object ob;
    string suspect;

    if (stringp(mix)) {
	suspect = lower_case((string)mix);
	ob = find_player(suspect);
    } else {
	if (objectp(mix)) {
	    ob = (object)mix;
	    suspect = ob->query("name");
	}
    }

    if (ob && !is_suspect(ob) && userp(ob)) {
	suspects += ({ suspect });
	return 1;
    } else {
	return 0;
    }
}

/*******************************************************************/

varargs int remove_suspect(mixed mix) {
    object ob;
    string suspect;

    if (stringp(mix)) {
	suspect = lower_case((string)mix);
	ob = find_player(suspect);
    } else {
	if (objectp(mix)) {
	    ob = (object)mix;
	    suspect = ob->query("name");
	}
    }

    if (member_array(suspect, suspects) != -1) {
	suspects = filter_array(suspects, "filter_suspects", TO, suspect);
	return 1;
    } else {
	return 0;
    }
}

/*******************************************************************/

string *query_suspects() { return suspects; }

/*******************************************************************/

int is_suspect(mixed mix) {
    object ob;
    string suspect;
    int i = 1;

    if (stringp(mix)) {
	suspect = lower_case((string)mix);
	ob = find_player(suspect);
    } else {
	if (objectp(mix)) {
	    ob = (object)mix;
	    suspect = ob->query("name");
	}
    }

    i += member_array(suspect, suspects);
    return i;
}

/*******************************************************************/

int filter_suspects(string foo, string suspect) { return suspect!=foo; }

/***[ EOF ]*********************************************************/
