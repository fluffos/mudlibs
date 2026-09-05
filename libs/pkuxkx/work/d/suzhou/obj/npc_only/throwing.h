#include <ansi.h>
void init()
{
	add_action("do_throw","throw");
}

int do_throw(string arg)
{
	string id;
	object me=this_player(),ob=this_object(),target,rp_target;
	int effect;
	if (userp(me))
	return 0;
	if (me->query("owner")&&me->is_stupid_long())
	rp_target=me->query("owner");
	if (!arg)
	{
		tell_object(rp_target,"npc的暗器必须有目标，格式是throw at <id>。\n");
		return 1;
	}
	if (sscanf(arg,"at %s",id)!=1)
	{
		tell_object(rp_target,"npc的暗器必须有目标，格式是throw at <id>。\n");
		return 1;
	}
	if (!target=present(id,environment(me)))
	{
		tell_object(rp_target,id+"在这里吗？\n");
		return 1;
	}
	if (!target->is_character())
	{
		tell_object(rp_target,id+"不是一个活物。\n");
		return 1;
	}
	if (userp(target))
	{
		tell_object(rp_target,"不能用"+query("name")+"来偷袭玩家。\n");
		return 1;
	}
	if (me==target)
	{
		tell_object(rp_target,"指导自杀？\n");
		return 1;
	}
	effect=query("effect")/2+random(query("effect")/2);
	if (random(2))
	{
		ob->move(target);
		tell_room(environment(target),RED+"只听"+target->name()+RED+"一声惨叫，被一"+query("unit")+query("name")+RED+"钉在身上。\n"+NOR);
		if (query("high_biao"))
		effect=effect*2+random(2500);
		F_KUNGFU->hit_wound("qi", query("effect"), effect, me, target);
	}
	else
	{
		ob->move(environment(target));
		tell_room(environment(target),WHT+target->name()+WHT+"潇洒地躲过了"+me->name()+WHT+"射出的一"+query("unit")+query("name")+WHT+"。\n"+NOR);
	}
	return 1;
}
