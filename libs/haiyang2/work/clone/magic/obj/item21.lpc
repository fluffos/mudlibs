// 白色香菇

#include <ansi.h>
inherit ITEM;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

void create()
{
        set_name(HIC"白色香菇"NOR, ({ "mp itema", "2item" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个白色香菇可以使用(use id)。据说可以恢复法力\n") ;

                set("unit", "个");
                set("value", 77000);
                set("zhen", 1);
        }
        setup();
}

void init()
{
        add_action("do_shot","use");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;

        me = this_player();

 	if (!id(arg))
	return notify_fail("你要用什么东西?\n");

        if(me->is_busy() )
                return notify_fail("你正忙着哪。\n");

        if( me->query("combat_exp")< 500000)
        return notify_fail("你的经验太少用不了！\n");



        if( !objectp(ob = present("mp itema", me)) )
                return notify_fail("你没有这种东西。\n");

        message_vision(HIC"\n$n"HIC"一口吃下了$N"HIC"  $n觉的全身舒服多了!  \n"NOR,this_object(),me);
        me->start_busy(1) ;
me->add("neili",500);

	if((int)me->query("neili") < (int)me->query("max_neili")+(int)me->query("max_neili")/3)
        {
        me->add("neili",me->query("max_neili")/6);
if (me->query("neili") > me->query("max_neili")+200)
me->set("neili",me->query("max_neili")+200);
message_vision(HIC"$N的法力恢复了不少!!\n"NOR, me);
        }


        destruct(this_object());

        return 1;
}
