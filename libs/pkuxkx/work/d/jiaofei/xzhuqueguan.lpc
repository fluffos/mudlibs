//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;
int do_break(string arg);
int do_knock(string arg);
void create()
{
			set("short", HIR"朱雀观"NOR);
  		set("long", @LONG
前方是一座道观在小指峰的第一节与第二节之间。朱雀观依山而建，布局甚
是精巧。所谓“小桥通活水，茅舍倚青山”，在风水上可称之为宝地，看来是有高
人在此。此刻观门紧闭。有一道士懒洋洋地盘坐在观前绿茵之上，不知是在打坐
修炼还是在晒太阳。
LONG
        );
			set("exits", ([ 
  			"southdown" : __DIR__"xshijie2",				
   		]));

			set("objects",([
     __DIR__"npc/daoshi":1,
        ]));
      set("outdoors", "tiezhang");  
			setup();

}
void init()
{
  		add_action("do_knock", "knock");
  		add_action("do_break", "break");
}

int do_knock(string arg)
{
			object me=this_player();
			if(arg !="gate" && arg !="door") return 0;
			if(arg =="gate" || arg =="gate" )
			{
				if(present("dao shi",environment(me)))
					tell_object(me,"道士说道：诸位到此有何公干？\n");
				else
					tell_object(me,"你走上前去，扣了扣门环，但是毫无动静。\n");
			}
			return 1;
}

int do_break(string arg)
{
			object me=this_player();
			if(arg !="gate" && arg !="door") return 0;
			if(arg =="gate" || arg =="door" )
			{
				if(present("dao shi",environment(me)))
					tell_object(me,"道士大声叫道：有土匪啊！\n你只好灰头土脸的退了回来。\n");
				else
				{
   				message_vision("$N走到后门前，扎了一个马步，深吸一口气，双掌同时拍出。\n", me);					
					if(me->query("neili")<1000)
					{
        		message_vision("$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", me);
            this_player()->set("neili",0);						
					}
					else
					{
        	message_vision("$N双臂发力，吐气扬声，将观门震倒。\n", me);
        	set("exits/northup", __DIR__"xqianyuan");
          me->add("neili",-1000);						
					}
				}
			}
			return 1;
}

