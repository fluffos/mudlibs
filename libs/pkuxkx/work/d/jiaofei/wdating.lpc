//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;
int do_look(string arg);
int do_open(string arg);
void create()
{
			set("short", HIW"白虎堂大厅"NOR);
  		set("long", @LONG
这里便是白虎堂的大厅了，厅内的摆设极其考究，大厅的墙壁上挂着一幅白
虎仕女图，正对门口的椅子坐着一个妙龄美女，你不由心中一荡。
LONG
        );
			set("exits", ([ 
  			"south" : __DIR__"wguangchang",
  			"north" : __DIR__"whouyuan",	
   		]));

			set("objects",([
//     __DIR__"tufei":1,
        ]));
			set("jieyao",1);
			setup();

}
void init()
{
//  		add_action("do_look", "look");
//  		add_action("do_open", "open");
}

int do_look(string arg)
{
			object me=this_player();
			if(arg !="foxiang" && arg !="duilian") return 0;
			if(arg =="duilian")
			{
				tell_object(me,	"上联书“"+HIR"殿宇耸云霞辉映法界"NOR
				+"”，下联书“+"HIR"楼台临水月光昭禅机"NOR+"”\n");
				return 1;
			}
			if(arg =="foxiang")
			{
				if (random(me->query_kar())>20)
				{
					tell_object(me,"你转到佛像背后，仔细看了看，发现佛像的后背（jiguan）似乎可以打开。\n");
					me->set_temp("jiaofei/m_look_foxiang",1);
				}
				else
					tell_object(me,"一尊寻常的毗卢佛像。\n");
				return 1;	
			}	
}

int do_open(string arg)
{
			object me=this_player();
			object jieyao;
			if (!me->query_temp("jiaofei/m_look_foxiang")) return 0;
			if (arg!="jiguan") return 0;
			tell_object(me,"你轻按机关，只见佛像后背打开一扇小门，原来是个暗格。");
			if (query("jieyao")<1) 
				tell_object(me,"只见里面空空如也！\n");
			else
			{
				tell_object(me,"只见里面有一瓶解药，就顺手拿了出来。\n");
			//jieyao=new(__DIR_"obj/jieyao");
			//jieyao->move(me);
			add("jieyao",-1);
		  }
			return 1;	
}

