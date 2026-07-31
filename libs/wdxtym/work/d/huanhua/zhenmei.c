//zhenmei.c

inherit ROOM;
int flag=0;
#include <ansi.h>
void init();

void create()
{
        set("short", "振眉阁");
        set("long", @LONG
振眉阁是萧西楼办事,读书,练剑和筹划帮内事物之地.里面很阔,四壁
有字画,对面立着个大书架(shelf),橱中有书,设备虽简陋,但却有一
种大气魄.阁内中央,放着几张楠木桌椅,是平时待客用的.
LONG
        );
        set("valid_startroom",1);

        set("no_beg",1);
        set("no_steal",1);
        set("exits", ([
                "east" :  __DIR__"changlang3",
                "west" :  __DIR__"jianshi",
                ]));
        set("objects", ([
                  __DIR__"npc/xiaoxilou" :1,
                  __DIR__"npc/xiaoren" :1,
                       ]));

        set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        	
	set("item_desc", ([
	    "shelf" : "一个简陋的书架,好象可以打开(dakai).\n",
	    
	]));
}
void init()
{
 add_action("do_dakai", "dakai");
}
int do_dakai(string arg)
{

	object me=this_player();
	object ob;
	if(!arg || arg!="shelf")
		return notify_fail("你要打开什么？\n");
	else if ( flag==0 )
		{
			flag=1;
			message_vision("只听“吱呀”一响，书架打开了.\n",me);
			message_vision(HIC"一本书掉了出来.\n"NOR,me);
		ob = new (__DIR__"obj/sishuwujing");
 		ob->move( __DIR__"zhenmei");

		}
	     else message_vision("书架已经被人打开了!\n",me); 		

	return 1;
}


