// Room: /d/diaoyudao/yading.c 崖顶
// hongdou 98.09.20

#include <ansi.h>
inherit ROOM;

void init()
{
	add_action("do_climb", "climb");
}

void create()
{
	set("short", "崖顶");
	set("long", @LONG
你登上了崖顶，强烈海风吹来，使你不能轻松地站稳。从这
里向下望，崖底周围是旺盛的灌木丛，从灌木丛中还生长出许多
藤蔓(teng)，攀附着崖壁蜿蜒爬上来，在靠海一面的崖壁上有很
多海鸟都在那里筑巢。
LONG
);

	set("exits", ([
                "down" : __DIR__"shanya",
	]));
	set("item_desc", ([
               "teng" : "这是一根粗壮的藤蔓，从海鸟窝边延伸生长到崖顶上来。\n",
         ]));

	set("outdoors", "diaoyudao");
	setup();
}

int do_climb(string arg)
{
        object me = this_player();
	object room;
	if( !arg || arg!="teng" ) 
	{
	     if ( !arg ) return notify_fail("你要往哪儿爬？\n");
             if ( arg!="teng" )  return notify_fail("那里不能爬！\n"); 
        }
	if(!( room = find_object(__DIR__"niaochao")) )
        room = load_object(__DIR__"niaochao");

	if (arg=="teng")
	{
	    if (((int)room->query_temp("无人"))==1)
	       	return notify_fail("\n你想顺着藤蔓溜下去，发现藤蔓正在摇摆不定，看来已经有人
下去了，藤蔓明显禁不住两个人的体重，你随后打消了念头。\n");
	       
	    if (this_player()->query_temp("崖") ) 
                 return notify_fail("你刚刚爬过，太危险了没什么好爬的？\n");
	    message_vision(HIY "$N顺着藤蔓慢慢向下溜去......\n" NOR,me);
            if( (int)me->query_skill("dodge") < 80)
	    {
                message_vision(HIR"藤蔓不堪$N的重负，从中断折，$N向海中落去，... 啊...！\n"NOR, me);
                tell_object(me, HIR"\n你掉进了大海，和波涛顽强的搏斗，渐渐体力不支。\n"NOR);
		tell_object(me,HIC"\n突然一个大浪将你掀了起来，你随即失去知觉。\n"NOR);
		me->unconcious();
		me->move("/d/diaoyudao/dhaian1");
		return 1;
	    }
	    else {
//		write("你顺着藤蔓溜到了鸟巢旁。\n");
		room->set_temp("无人",1);
		me->move(__DIR__"niaochao");	
                message("vision",me->name()+"出现在你身旁，看样子他想抢你的东西。\n",environment(me),({me}));
		this_player()->set_temp("崖", 1);
          	return 1;
       		 }
	}   
}