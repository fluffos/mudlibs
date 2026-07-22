// Room: /d/jjf/zuixing.c
#include <ansi.h> 
inherit ROOM;

string look_up()
{
	string str = @STR

醉星楼二楼
    上得楼梯，迎面是一面玉石屏风，上绘嫦娥奔月的故事。转过屏
风，只见两人坐在一张桌上狂饮作乐，旁边舞女在奏乐起舞。一边，
几个青衣小童正在伺候着。有的在上菜，有的在打扇。

STR;
	str+= "    这里唯一的出口是 "HIG"down"NOR"。\n";
	return str;
}	
 
void create ()
{
  	set("short", "醉星楼");
  	set ("long", @LONG
高祖时，太子李建成和三子李元吉对高祖御旨起麒麟阁十分不满，
认为这是对太宗皇帝的偏爱。
    于是二人穷二府之资，在麒麟阁的对面造了一座及其华丽宏伟的彩
楼，名「醉星楼」。为了吸引百姓前来观看，二人甚至不惜发送食物钱
财。
    后二王薨，太宗仁慈，此楼依然保留。尚有二王死忠在此维护日常，
但是据说到了夜晚，楼内常常传来哭泣之声。

LONG);
	set("no_fight", 1);
  	set("objects", ([
  		__DIR__"npc/qinbing-jian" : 1,
  		__DIR__"npc/qinbing-qi" : 1,
	]));
	set("exits", ([
  		"west" : "/d/city/xuanwu-n0",
  		"up" : __FILE__,
	]));
	set("item_desc",([
		"up" : (: look_up :),
	]));	
	setup();
}

int valid_leave(object me, string dir)
{
	if( !userp(me) )
		return 0;
	if( dir!= "up" )
		return ::valid_leave(me,dir);
	tell_object(me,look_up());
	if( !me->query_temp("pendding/jjf_break") 
	 || time()<me->query("maze/zuixing")+7200 )
	{
		tell_object(me,"\n店小二说道：醉星楼现在不营业，你老请回。\n");
		tell_object(me,"你向下离去。\n");
		me->command("look");
		return 2;	
	}
	else
	{
		me->delete_temp("maze");
		if( MAZE_D->enter_maze(me, "zuixing") )
		{
        		me->set_temp("maze/zuixing",1);
        		me->set("maze/zuixing",time());
		}
		return 2;
	}
}