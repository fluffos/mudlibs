#include <cmd.h>
#include <invis_levels.h>

nomask int
I_cmd(string str) {
    object ob, *inv;
    int i;

    if (!CHECK) return 0;

    if (str) {
	if (!(ob = get_object(str))) {
	    printf("No '%s' found.\n", str);
	    return 1;
	}
    } else {
	ob = this_player();
    }

    printf("'%s' contains:\n", tilde_path(object_name(ob)));
    inv = all_inventory(ob);
    i = -1;
    while (++i < sizeof(inv)) {
	if (!(str = (string)inv[i]->short(IL_TOTALLY_INVISIBLE, this_player()))) {
	    str = (str = (string)inv[i]->query_name())
	    ? sprintf("<%s>", str) : "-";
	}
	printf("%2d: %-35s %s\n", i+1, tilde_path(object_name(inv[i])),
	  str);
    }

    return 1;
}
