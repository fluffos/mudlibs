// by advent
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "冰火洞");
	set("long", 
"这里是张殷夫妇的起居室。\n"
"但见山洞极是宽敞，山洞之中，花香流动，火光映壁。\n"

	);
	set("exits", ([
		"north" : __DIR__"shidong",
		"south" : __DIR__"shulinout",
	]));
	set("objects",([	
		__DIR__"npc/zhangcui" : 1,
		__DIR__"npc/yinsu" : 1,
		__DIR__"npc/wuji" : 1,
		]));
	setup();
}
void init()
{
        add_action("do_kao", "kao");
}
int do_kao(string arg)
{
	object ob,kaolu,rou,ju;
        object me = this_player();
	if( !arg || arg!="rou" ) 
	{
	     if ( !arg ) return notify_fail("你要烤什么？\n");
             if ( arg!="rou" )  return notify_fail("你要烤什么？\n"); 
        }
	if (arg=="rou" && objectp(rou=present("lu rou", me)) && objectp(ju=present("huo ju", me)))
	{
	  tell_object(me, HIR"你从身上掏出新鲜鹿肉，放在火炬上烤成了香喷喷的烤鹿肉。\n"NOR);
	  message("vision",me->name()+"得到了拷鹿肉。\n",environment(me),({me}));
	  kaolu = new(__DIR__"obj/kaolu");
          kaolu->move(me);
          destruct(ju);
          destruct(rou);
	  return 1;
	}
}
