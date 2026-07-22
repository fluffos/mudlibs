// start_card.c - 起点卡

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    	set_name("起点卡", ({ "start card", "card" ,"start" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "叠");
	set("base_unit", "张");
	set("long", "梦幻时空的卡片，使用（use）可以使人退回起点。\n");
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
	int increasement;

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

        if( !me->query_temp("wqa's room/flag") ) 
                return notify_fail("你现在不在梦幻时空！\n");

        if( !ob->query_temp("wqa's room/flag") ) 
                return notify_fail("这个人现在不在梦幻时空！\n");
if( wizardp(ob) ) return notify_fail("这张片对巫师无效！\n");


        //if(query_ip_name(ob) == query_ip_name(me) && !wizardp(me) ) 
        //        return notify_fail("请多看一看游戏规则！下不为例！\n");


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
        environment(ob)->use_start_card( ob );
        
        // set("name", "卡片");  set("id", "card");
        CHANNEL_D->do_channel(this_object(), "game", "大家快来看呀，"
                + me->name() + "将" + ( me == ob ? "自己" : ob->name() )
                + "一脚踢回梦幻时空起点！" );

	add_amount(-1);        
	return 1;
}
