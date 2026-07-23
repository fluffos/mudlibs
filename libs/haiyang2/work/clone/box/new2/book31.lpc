// 回城术

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
        set_name(HIY"回城术卷轴"NOR, ({ "portal axes", "31axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个魔法卷轴可以使用(spell id)上面的魔法。\n") ;

                set("unit", "个");
                set("value", 140000);
                set("zhen", 1);
        }
        setup();
}

void init()
{
        add_action("do_shot","spell");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;
	string startroom;
        me = this_player();

 	if (!id(arg))
	return notify_fail("你无法使用这个卷轴!\n");

        if(me->is_busy() )
                return notify_fail("你正忙着哪。\n");
        if( me->query("combat_exp")< 500000)
        return notify_fail("你的经验太少用不了！\n");

        if (me->query("neili") < 400)
        return notify_fail("你的法力不足！\n");
        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
        if (me->is_busy()) 
        return notify_fail("你正忙着呢!\n");

	if( environment(me)->query("outdoors")=="12gong" )
		return notify_fail("在12宫内不允许使用回城术。\n");

   if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
	return notify_fail("只有在比较安全的地方才能使用回城术。\n");
	
        if( !environment(me)->query("no_fight") )
		return notify_fail("只有在比较安全的地方才能使用回城术。\n");	        

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIY"\n$N"HIY"上的魔法力量用完了!  $N"HIY"消失了。\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("portal axes", me)) )
                return notify_fail("你没有这种东西。\n");

        startroom = me->query("startroom");
        if( !me->query("startroom") )
		return notify_fail("请先确定你要去的目标吧!\n");
	me->add("neili",-150);

	message_vision(YEL "\n$N在地上划了一个五芒星，口中喃喃地念著咒文!!\n" NOR, me);	
	message_vision(YEL "\n$N站在的地上出现了巨大的光芒，把$N包围了!\n" NOR, me);
        message_vision(YEL "\n$N在光芒中，消失不见了!\n" NOR, me);
        me->move(startroom);
	me->start_busy(3);
        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIY"\n$N"HIY"上的魔法力量用完了!  $N"HIY"消失了。\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        return 1;
}
