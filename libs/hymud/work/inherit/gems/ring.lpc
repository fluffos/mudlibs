#include <ansi.h>
#include <armor.h>

inherit FINGER;
inherit F_GEMS;

void init_sockets(object me)
{
	//set("max_sockets", 1);
	if (me->query("combat_exp") > 10000000)
		///add("max_sockets", 1);
	if (me->query("combat_exp") > 10000000)
		///add("max_sockets", 1);

        if (me->query("combat_exp") < 10000000 && (int)query("sockets/max",1)>=2)
        //set("sockets/max",2);

        if ((int)query("sockets/max",1)>3)
        //set("sockets/max",3);

	if (me->query("diablo/" + TYPE_FINGER + "/id") != query("id")) return;

	//set("sockets", me->query("diablo/" + TYPE_FINGER + "/sockets"));
	set_ring_desc();
}

void setup()
{
	init_sockets(this_player());
	::setup();
}

void spec_prop(object me, string socket, int socket_level, int mode)
{
int i;
	if (!valid_gem(socket, socket_level)) return;
if (me->query("diablo/" + TYPE_FINGER + "/id") != query("id")) return;
if (me->query("max_neili") < 100)  return;
	
	return;
}

int wear()
{
	int i, sockets, ret;
	object me = environment();

	if (!(ret = ::wear())) return 0;


	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), 1);
	return ret;
}

int unequip()
{
	int i, sockets, ret;
	object me = environment();

	if (!(ret = ::unequip())) return 0;

	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), -1);
	return ret;
}
