// houfang.c
// by chenww

inherit ROOM;
#include <ansi.h>
int flag=0;
void create()
{
	set("short", "后房");
	set("long", @LONG
这里是见天洞的后房,空间非常大,里面摆放了许多副棺材(guan cai).
这些棺材里都是倒下了的萧家子弟和浣花剑手,他们为浣花剑派而死,尸首
也因此停放在萧家的祖祠的侧房里.
LONG
	);
/*        set("objects", ([
                 __DIR__"obj/guancai" :1,
        ]));
*/        
        set("outdoors", "huanhua");

	set("exits", ([
		"west" : __DIR__"jiantiand",
	]));
	
	set("item_desc", ([
	    "guan cai" : "一副黑漆漆的大棺材,棺材盖没盖严，里面好象有什么东西。\n",
	    
	]));
	setup();
}

void init()
{
	add_action("do_dakai", "dakai");
	add_action("do_dakai", "move");
	add_action("do_dakai", "push");
	add_action("do_dakai", "open");			
}
int do_dakai(string arg)
{
	object me=this_player();
	object ob;
	if(!arg || arg!="guan cai")
		return notify_fail("你要打开什么？\n");
	
	else if ( flag==0 )
		{
			flag=1;
			message_vision("你小心翼翼地推开了棺材盖....哇，里面居然有一块古玉。.\n",me);
			message_vision("$N四下看了看，赶忙把古玉揣进了兜里.\n"NOR,me);
		ob = new ( __DIR__"obj/wenyu" );
 		ob->move( this_player() );

		}
	     else message_vision("这是一个空荡荡的大黑棺材。\n",me); 		

	return 1;
}

 