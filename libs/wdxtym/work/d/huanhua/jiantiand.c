
inherit ROOM;
#include <ansi.h>
int flag=0;
void create()
{
	set("short", "见天洞");
	set("long", @LONG
见天洞内打扫得一尘不染,烛火常明.壁内各处有凹进去了的地方,
供奉着一樽栩栩如生的神像.神像前是七星灯火,供奉着祭祀用的三牲
礼酒,坛前有一个用黄绫包起来的经卷(jing juan).
LONG
	);

	set("valid_startroom", 1);	

	set("exits", ([
//                 "east" : __DIR__"houfang",
		"west" : __DIR__"jiashan",
	]));

	set("objects", ([
		  __DIR__"npc/dizi" : 2,
	]));
	set("coor/x",140);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	
	set("item_desc", ([
	    "jing juan" : "一个用黄绫仔细包起来的经卷,看起来好象可以打开(dakai).\n",
	    
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
	if(!arg || arg!="jing juan")
		return notify_fail("你要打开什么？\n");
//	if (me->query_kar() < 28) {
//	message_vision("你打开了黄绫,却发现里面只是个空盒子.\n");
//       return 1;}
		
	else if ( flag==0 )
		{
			flag=1;
			message_vision("你仔细地解开了黄绫.\n",me);
			message_vision(HIY"一本发黄的古书掉了出来.\n"NOR,me);
		ob = new ( __DIR__"obj/jian-book" );
 		ob->move( __DIR__"jiantiand");

		}
	     else message_vision("黄绫已经被解开的了!\n",me); 		

	return 1;
}

 
