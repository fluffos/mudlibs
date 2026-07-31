// 精神药粉 

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
        set_name(HIC"钻石药粉"NOR, ({ "jing itemc", "33item" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一包钻石药粉可以使用(use id)。据说可以恢复精力\n") ;
set("treasure",1);
                set("unit", "包");

                set("value", 96000);
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

        if( !objectp(ob = present("jing itemc", me)) )
                return notify_fail("你没有这种东西。\n");

        message_vision(HIC"\n$n"HIC"一口吃下了$N"HIC"  $n觉的全身舒服多了!  \n"NOR,this_object(),me);
        me->start_busy(1) ;
me->add("jing",650);

	if((int)me->query("jing") < (int)me->query("max_jing")+(int)me->query("max_jing")/3)
        {
        me->add("jing",me->query("eff_jing")/5);
        me->add("eff_jing",me->query("eff_jing")/5);
if (me->query("jing") > me->query("max_jing")+550)
me->set("jing",me->query("max_jing")+550);
if (me->query("eff_jing") > me->query("max_jing"))
me->set("eff_jing",me->query("max_jing"));
message_vision(HIG"$N身上的精神了不少!!\n"NOR, me);
         }


        destruct(this_object());

        return 1;
}
