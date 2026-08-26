// Copied from Beek's _mudlibs command ;)   Leto
#include <mudlib.h>
#include <net/daemons.h>

inherit DAEMON;

mapping count(string *list) {
    int i;
    mapping ret = ([]);
    for (i=0; i<sizeof(list); i++) {
	ret[list[i]]++;
    }
    return ret;
}

cmd_mudlibs() {
    int i;
    string *mud_names;
    mapping info;
    string mudlib;
    string *mudlibs = ({});
    mapping result;
    string *kinds;

    mud_names = DNS_MASTER->query_mud_names();
    for (i=0; i<sizeof(mud_names); i++) {
	info = DNS_MASTER->query_mud_info(mud_names[i]);
     //mudlib = info["MUDLIB"];
     mudlib = info["MUDLIB"]+" version "+info["VERSION"];
	if (mudlib) {
	    printf("%s is using %s.\n", mud_names[i], mudlib);
	    mudlibs += ({ mudlib });
	}
    }
    printf("-------------------------\n");
    result = count(mudlibs);
    kinds = keys(result);
    for (i=0; i<sizeof(kinds); i++) {
        kinds[i] = sprintf("%s: %i\n", kinds[i], result[kinds[i]]);
    }
    write(implode(sort_array(kinds, 0), ""));
    return 1;
}
