// get_card.c - 抢夺卡

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    	set_name("抢夺卡", ({ "get card", "card", "get" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "叠");
	set("base_unit", "张");
	set("long", "梦幻时空的卡片，使用（use）可以把别人的社会声望抢走。\n");
	set("value", 0 );
        set("base_weight", 3);
        set_amount(1);

}

void init()
{
	add_action("do_use", "use");
}

int do_use(string arg)
{
	object me, ob;
	string item, target;
	int i, j, n;

	me=this_player();
if( !arg)
          return notify_fail("用法：use 卡片名 for 人名\n");

        if( sscanf(arg, "%s for %s", item, target)==2 ) ;
        else return notify_fail("用法：use 卡片名 for 人名\n");
        
	if(!id(item))  return notify_fail("你想要使用什么东西？\n");

	if( me->is_busy() ) return notify_fail("你正忙着呢！\n");
	me->start_busy(1);

	ob = find_player(target);
	if( !ob ) ob = find_living(target);
	if( !ob ) return notify_fail("现在找不到这个人！\n");

        if( me == ob )
                return notify_fail("你抢你自己的东西做什么！\n");

        if( wizardp(ob) ) return notify_fail("这张片对巫师无效！\n");

        if( !me->query_temp("wqa's room/flag") ) 
                return notify_fail("你现在不在梦幻时空！\n");

        if( !ob->query_temp("wqa's room/flag") ) 
                return notify_fail("这个人现在不在梦幻时空！\n");

        if(query_ip_name(ob) == query_ip_name(me) && !wizardp(me) ) 
                return notify_fail("请多看一看游戏规则！下不为例！\n");

        message_vision( HIR "$N开始使用" + this_object()->query("name") + "....\n" NOR, me);
/*
        message_vision( HIR "“呜哇！”从天空上伸出一只大手，把$N捉了去....\n" NOR, ob);

        // set("name", "卡片");  set("id", "card");
        CHANNEL_D->do_channel(this_object(), "chat", "大家快来看呀，" + 
                me->name() + "将" + ob->name() + "一脚踢回梦幻时空起点！" );

        ob->move("/d/wqa/01");

        message( "vision", HIW "\n你的眼前突然出现一团白色的光芒，"
                + ob->name() + "出现在你眼前！\n" NOR, environment(ob), ({ ob }) );
*/
        i = me->query_temp("wqa's room/point");
        j = ob->query_temp("wqa's room/point");
        if( i <= 0 ) i = 1;
        if( j <= 0 ) j = 1;

        // 抢别人的东西，五次有一次不成功
        if( random(5) == 0 ) {
                n = -random(i);
                i += n;  j -= n;
        }
        else {
                n = random(j);
                i += n;  j -= n;
        }
        if( i <= 0 ) i = 1;
        if( j <= 0 ) j = 1;

        me->set_temp("wqa's room/point", i);
        ob->set_temp("wqa's room/point", j);
        
        // set("name", "卡片");  set("id", "card");
        CHANNEL_D->do_channel(this_object(), "game", me->name() + "对着"
                + ob->name() + "奸笑：“你的就是我的，我的也是我的！”\n"
                "        " + me->name() + "从" + ob->name() + "处获得" 
                + chinese_number(n) + "点社会声望！\n" );

	add_amount(-1);        
	return 1;
}
