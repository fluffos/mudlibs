// Room: /d/diaoyudao/niaochao.c 崖壁
// hongdou 98.09.20

#include <ansi.h>
inherit ROOM;

void init()
{
	add_action("do_climb", "climb");
	add_action("do_fan", "fan");
}

void create()
{
	set("short", "崖壁");
	set("long", @LONG
你拉着藤蔓，顺着崖壁，慢慢移动到鸟巢(chao)旁，海风吹来，
你紧紧扳住崖壁上的岩石，固定摇摆不停身体。下面就是大海，如
果掉下去，后果不堪设想。
LONG
);

	set("item_desc", ([
               "chao" : "这是一个海鸟用各种树枝、羽毛等东西筑成的巢穴，翻翻看里面一定有鸟蛋。\n",
         ]));

	set("outdoors", "diaoyudao");
	setup();
}

int do_climb(string arg)
{
        object me = this_player();
	object ob,ob1,room;
	if( !arg || arg!="teng" ) 
	{
	     if ( !arg ) return notify_fail("你要往哪儿爬？\n");
             if ( arg!="teng" )  return notify_fail("那里不能爬！\n"); 
        }
	if(!( room = find_object(__DIR__"niaochao")) )
        room = load_object(__DIR__"niaochao");

	if (arg=="teng")
	{

            if( ((int)me->query_skill("dodge") < 150)  && (random(8)<=6))
	    {
                message_vision(HIR"由于你抓藤蔓的时间过长，双臂无力再向上爬了，$N向海中落去，... 啊...！\n"NOR, me);
                tell_object(me, HIR"你掉进了大海，和波涛顽强的搏斗，渐渐体力不支。\n"NOR);
		tell_object(me,HIC"\n突然一个大浪将你掀了起来，你随即失去知觉。\n"NOR);
		room->set_temp("无人",0);
		me->unconcious();
		me->move("/d/diaoyudao/dhaian"+(random(2)+1));
		return 1;
	    }
	    else {
		write("你顺着藤蔓爬上了崖顶。\n");
		room->set_temp("无人",0);
		me->move(__DIR__"yading");	
          	return 1;
       		 }
	}   
}

int do_fan(string arg)
{
        object me = this_player();
	object ob,ob1,room;
	if( !arg || arg!="chao" ) 
	{
	     if ( !arg ) return notify_fail("你要干什么？\n");
             if ( arg!="chao" )  return notify_fail("那里没有什么！\n"); 
        }
	if(!( room = find_object(__DIR__"niaochao")) )
        room = load_object(__DIR__"niaochao");

	if (arg=="chao")
	{
	    if ((room->query_temp("无")) || (me->query_temp("翻")>=3 ) )
		return notify_fail("那里只剩下一堆凌乱的树枝，什么都没有!\n");
	    if (this_player()->query_temp("翻")==0)
	    {
		message_vision("\n$N从鸟巢里拿出了一枚鸟蛋。\n",me);
		ob=new("/d/diaoyudao/obj/niaodan");
		ob->move(me);
		me->add_temp("翻",1);
		return 1;
	    }
	    if (this_player()->query_temp("翻")==1)
	    {
		message_vision("\n$N从鸟巢里翻出了一手的鸟粪，$N恶心差点吐出来！还是赶快离开这危险之地吧。\n",me); 		 
		me->add_temp("翻",1);
		return 1;
	    }
	    if (this_player()->query_temp("翻")==2)
	    {
		message_vision("\n$N掀开整个鸟巢，发现底下竟然有一大块布，可能是风刮到这里，
而海鸟却在这里筑了巢。$N随即将它取了出来，竟是一面帅旗。\n",me);
		ob1=new("/d/diaoyudao/obj/shuaiqi");
		ob1->move(me);
		room->set_temp("无",1);
		me->add_temp("翻",1);
		return 1;
	    }
	}
}