// lingzhi.c

inherit ITEM;

void create()
{
	set_name("紫灵芝", ({ "zi lingzhi"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",2000);
		set("unit", "枝");
		set("long", "这是一枝紫灵芝。\n");
	}
}
/*
int valid_get(object me)
{
	object wg,env;

	if(!me)
		return 0;

	if(!(env = environment())
	|| !env->is_room()
	|| !(wg = present("hong wugong",env))
	|| !living(wg))
		return 1;

	message_vision(sprintf("$N看到$n要摘%s，“呼”的一下冲了过来。\n",
		name()),wg,me);

	wg->kill_ob(me);
	me->kill_ob(wg);
	return 0;
}
*/
