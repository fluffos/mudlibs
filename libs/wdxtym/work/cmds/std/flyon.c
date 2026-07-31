// flyon.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_flyon(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *env,obn;

	if (! arg) return notify_fail("你要驾御什么东西？\n");

	if (me->query_skill("fly", 1) < 100 ) 
		return notify_fail("你的御剑术太差，不怕摔下来吗。(100级以上方可御剑飞行)\n");    

	if (me->query_temp("is_flying"))
		return notify_fail("你已经激发御剑飞行状态了！\n");

	if (me->is_busy())
		return notify_fail("你上一个动作还没有完成！\n");

	if (me->is_fighting())
		return notify_fail("你还在战斗中！没空驾御飞剑去。\n");

	// Check if a container is specified.
	 if (! objectp(obj = present(arg,me)))
	return notify_fail("你没有东西可以驾御飞行。\n");
	 
	 if (obj->item_owner() && obj->apply_damage() && (int)obj->weapon_level()>=9)
	  {
	       return do_flyon(me, obj);
	  }
	 else
	  {
		return notify_fail("你无法驾御< "+obj->query("name")+" >飞行。(9级以上兵器才能驾御)\n");
	  }
	return write("站在了飞剑上。\n");
       
	
}
	
int do_flyon(object me, object obj)
{
	object old_env;

	if( !obj ) return 0;

	//obj->set_weight(1);
	
		message_vision( "$N纵身跃上$n，护身罡气从"+obj->query("name")+"自动激发。\n", me, obj );
		obj->set_temp("is_flyed_by", me);
		me->set_temp("is_flying", obj);
	
	
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : flyon <飞剑ID>
 
这个指令可以让你驾御自己的飞剑，配合御剑术，瞬息万里。
 
HELP
    );
    return 1;
}
