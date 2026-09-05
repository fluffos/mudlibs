// Room: /d/diaoyudao/shuding.c 树顶
// hongdou 98.09.20

#include <ansi.h>

inherit ROOM;

void init()
{
        add_action("do_kan", "kan");
}

void create()
{
	set("short", "树顶");
	set("long", @LONG
古木参天，此树也不知生了几百年。这里是冰火岛的制高点，
举目远眺，可见一处平原，平原尽头浓烟滚滚，那就是岛上的
火山了吧。一段树干(shugan)吸引了你的目光。
LONG
	);
	set("item_desc", ([
               "shugan" : "这是一段极粗大结实的树干，看起来是做家具的好材料。\n",
       ]));

	set("exits", ([
                "down" : __DIR__"shulin8",
	]));

	set("outdoors", "bhdao");
	setup();
}

int do_kan(string arg)
{
	object ob,mupai,rope;
        object me = this_player();
	if( !arg || arg!="shugan" ) 
	{
	     if ( !arg ) return notify_fail("你要砍什么？\n");
             if ( arg!="shugan" )  return notify_fail("你要砍什么？\n"); 
        }
	if (arg=="shugan"&& objectp(rope=present("long rope", me)))
	{
	  tell_object(me, HIY"你把树干砍成几段，三下五除二就用绳索扎成了个木排。\n"NOR);
	  message("vision",me->name()+"扎好了木排。\n",environment(me),({me}));
	  mupai = new(__DIR__"obj/mupai");
          mupai->move(me);
          destruct(rope);
	  return 1;
	}
	else
	{
	 tell_object(me, HIY"你没有绳子，砍些木头来有什么用？\n"NOR);
	 }
	 
}
