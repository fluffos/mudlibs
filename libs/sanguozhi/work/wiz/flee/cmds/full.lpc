#include <mudlib.h>
#include <daemons.h>

inherit CMD;
inherit M_GRAMMAR;

private void main(string arg)
{
	int t_id;
	object ob, troop;
	mapping t, info;

	ob = CHAR_D->find_char(arg);
	if( !ob||!objectp(ob)||!ob->query_link() ){
		write("No such person on line\n");
		return;
	};

	troop = environment(ob);
	if( !troop||!objectp(troop)||!troop->is_troop() ){
		write("He is not in a troop!\n");
		return;
	};

	t_id = troop->get_id();
	t    = TROOP_D->get_troops(t_id,"soldier");
	info = ([ ]);
	foreach(string ss in keys(t) ){
		info[ss] = t[ss];
		info[ss]["energy"] = 30;
	}
	TROOP_D->set_troops(t_id, "soldier", info);

	write("OK, recovered!\n");

	return;
}
