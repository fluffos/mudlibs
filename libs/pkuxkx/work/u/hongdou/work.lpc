// Room: /work.c 劳动
// hongdou 98.09.20

#include <ansi.h>

inherit ROOM;

void init()
{
	add_action("do_work", "work");
}
	

void create()
{
	set("short", "劳动广场");
	set("long", @LONG
这里是位于广场西南边的劳动广场，到处是义务劳动的人们，在
广场上空飘着轻气球，气球上挂着五彩条幅，写着“热烈庆祝五·一
劳动节”。这里的人们都在热火朝天地苦干，没有一个在偷闲，你是
不是也要参加劳动(work)。
LONG
	);

	set("exits", ([
             "northeast" : __DIR__"guangchang",
	]));

	setup();
}

int do_work()
{
    object me = this_player();
    if ( (int)me->query_condition("work_drug" ) > 0 ) 
            return notify_fail("你已经为这里出过力了，还是多休息一下吧！\n");
    if( me->is_busy() )
       return notify_fail("你正在劳动，没空干别的！\n");    
    message_vision("$N开始在广场瞎忙活起来......\n",me);
    me->start_busy(15);
    message_vision("$N已经精疲力尽，坐在地上不住地喘着粗气。\n",me);
    me->apply_condition("work_drug",2000);
    me->set("jing", 10); 
    me->set("qi",10);
    me->add("max_jing",20);
    me->add("max_qi",20);
    tell_object(me,"你的最大精和气增加了！\n");	
    return 1;
}  
     
