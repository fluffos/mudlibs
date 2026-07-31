// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "双内丹" NOR, ({ "force wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的双内丹，据说吃了可以重新选择双内功。\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;
int i;
        me = this_player();
        if (! id(arg))
{
tell_object(me, "你要吃什么?\n");
                return notify_fail("你要吃什么？\n");
}

i=0;




    if ( !me->query("zhuanshen")    )
{
tell_object(me, "你没有转生!\n");
        return notify_fail("你没有转生!\n");
}

    if ( me->query("tforceok")==2    )
{
tell_object(me, "你不需要用它!\n");
        return notify_fail("你不需要用它!\n");
}

        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

        if (	me->query_skill("bahuang-gong",1)) i=i+1;
        if (	me->query_skill("xuantian-wuji",1)) i=i+1;
	if (	me->query_skill("beiming-shengong",1)) i=i+1;
	if (	me->query_skill("bibo-shengong",1)) i=i+1;
	if (	me->query_skill("hamagong",1)) i=i+1;
	if (	me->query_skill("huagong-dafa",1)) i=i+1;
	if (	me->query_skill("huntian-qigong",1)) i=i+1;
	if (	me->query_skill("jiuyang-shengong",1)) i=i+1;
	if (	me->query_skill("kuihua-xinfa",1)) i=i+1;
	if (	me->query_skill("kurong-changong",1)) i=i+1;
	if (	me->query_skill("linji-zhuang",1)) i=i+1;
	if (	me->query_skill("longxiang",1)) i=i+1;
 	if (	me->query_skill("shenlong-xinfa",1)) i=i+1;
	if (	me->query_skill("xiantian-qigong",1)) i=i+1;
	if (	me->query_skill("xiaowuxiang",1)) i=i+1;
	if (	me->query_skill("yijinjing",1)) i=i+1;
	if (	me->query_skill("yunv-xinfa",1)) i=i+1;
	if (	me->query_skill("yunlong-shengong",1)) i=i+1;
	if (	me->query_skill("shenyuan-gong",1)) i=i+1;
	if (	me->query_skill("huashan-neigong",1)) i=i+1;
        if (	me->query_skill("zixia-shengong",1)) i=i+1;
        if (	me->query_skill("shayi-xinfa",1)) i=i+1;
        if (	me->query_skill("biyun-xinfa",1)) i=i+1;
        if (	me->query_skill("bingxue-xinfa",1)) i=i+1;
        if (	me->query_skill("wudu-shengong",1)) i=i+1;
        if (	me->query_skill("taiji-shengong",1)) i=i+1;
        if (	me->query_skill("guiyuan-tunafa",1)) i=i+1;

	if (	me->query_skill("longxiang",1) && me->query_skill("xiaowuxiang",1)) i=i-1;
	if (	me->query_skill("beiming-shengong",1) && me->query_skill("bahuang-gong",1)) i=i-1;


        if (i>1)
        {
tell_object(me, "请先放弃 你身上多余不要的内功，现在共有"+i+"门，只保留一种主内功。!\n");
                return notify_fail("请先放弃 你身上多余不要的内功，只保留一种主内功。\n");
}
   

                message_vision("$N眨眨眼。\n", me);
                tell_object(me, "你现在有"+i+"门内功。\n");



                tell_object(me, HIR "你觉得似乎自己发生了变化 。\n" NOR);
                me->set("tforceok",2);

        destruct(this_object());
	return 1;
}
