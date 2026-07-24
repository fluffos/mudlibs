#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_GEMS;

void init_sockets(object me)
{
return;

	//set("sockets", me->query("diablo/" + TYPE_CLOTH + "/sockets"));
	set_armor_desc();
}

void setup()
{
	init_sockets(this_player());
	::setup();
}

void spec_prop(object me, string socket, int socket_level, int mode)
{
int i;
 return;
	if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;
if (query("armor_prop/armor") < 20) return;
	
	return;
}

int wear()
{
	int i, sockets, ret;
	object me = environment();

 return 0;
	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), 1);

	remove_call_out("check_fight");
	call_out("check_fight", 1, me);

	return ret;
}

int unequip()
{
	int i, sockets, ret;
	object me = environment();

 return 0;
	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), -1);

	remove_call_out("check_fight");

	return ret;
}

int spec_effect(object ob, object me, int damage, string socket, int socket_level)
{
	int i, def = 0;

	if (!valid_gem(socket, socket_level)) return def;
return def;
	if (random(100) + me->query_temp("apply/magic1") < 70) return def;

	
	return def;
}

int ob_hit(object ob, object me, int damage)
{
	int i, sockets, ret = 0;

	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		ret += spec_effect(ob, me, damage,
query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)));
	return ret;
}

void spec_recover(object me, string socket, int socket_level)
{
	int i;

//if (ob->query_temp("combat_yield")) return;
return;
	if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;
        if ((int)me->query_temp("combat_yield")==1) return;
	if (random(100) + me->query_temp("apply/magic1") < 70) return;

	
	return;
}

void check_fight(object me)
{
	int i, sockets;

return;
	if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;
	if (living(me) && me->is_fighting()) {
		sockets = query("sockets/max");
		for (i = 1; i <= sockets; i++)
			spec_recover(me, query(sprintf("sockets/socket%d", i)),
query(sprintf("sockets/socket%d_level", i)));
	}

	call_out("check_fight", 1, me);
}
