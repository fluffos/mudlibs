// A daemon which handles information messages about the mud, right
// now only login/outs and net deads/recoveries.
// accessed thru the "inform" command.
// Diewarzau 3/16/94 (DarkeMUD)

#include <daemons.h>
#include <objects.h>

private mapping whos_listening;

void create() {
    object *who;
    int i, j;
    string *inf_types;

    seteuid(getuid());
    who = users();
    whos_listening = allocate_mapping(30);
    for(i=0;i<sizeof(who);i++) {
	inf_types = (string *)who[i]->query_inform();
	for(j=0;j<sizeof(inf_types);j++) {
	    if(!whos_listening[inf_types[j]])
		whos_listening[inf_types[j]] = ({});
	    whos_listening[inf_types[j]] = distinct_array(
		whos_listening[inf_types[j]] + ({ who[i] }));
	}
    }
}

int add_user(object who, string *inf_types) {
    int i;

    if(!inf_types || !sizeof(inf_types)) return 0;
    if(!who) return 0;
    i = sizeof(inf_types);
    while(i--) {
	if(!whos_listening[inf_types[i]]) whos_listening[inf_types[i]] = ({});
	whos_listening[inf_types[i]] = distinct_array(
	    whos_listening[inf_types[i]] + ({ who }));
    }
    return 1;
}

varargs int do_inform(string type, string msg, object *exclude) {
    object *get;
    int i;

    if(!whos_listening[type]) return 0;
    get = whos_listening[type];
    get = filter_array(get,"trap_func",this_object(),type);
    if(exclude && sizeof(exclude))
	{ i = sizeof(exclude);
	while(i--) {
	    if(member_array(exclude[i],get) >-1)
		get = exclude_array(get, member_array(exclude[i],get));
	}}
    message("info",msg,get);
    return 1;
}

int remove_user(object who) {
    string *inf_types;
    int i,j;

    if(!keys(whos_listening)) return 0;
    inf_types = keys(whos_listening);
    i = sizeof(inf_types);
    while(i--) {
	while((j=member_array(who,whos_listening[inf_types[i]])) > -1)
	    whos_listening[inf_types[i]] = exclude_array(
		whos_listening[inf_types[i]], j);
    }
    return 1;
}

int trap_func(object ob, string type) {
    if(!objectp(ob)) return 0;
    return interactive(ob) && !ob->query_inf_blocked(type);
}
