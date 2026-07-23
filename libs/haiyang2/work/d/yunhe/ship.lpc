// Room: /d/yunhe/chuancang
// Date: netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","船头" );
    set("long",  @LONG
这是一只大船的船头，两个丫环模样的人正在这里看风景，里
面是船仓。地上堆放着几块木板。好像可以移动 船头并不高好像
可以跳出去。
LONG 
    );
	set("exits", ([
		"enter" :__DIR__"chuancang",
			]));
      set("objects", ([
		"d/qianjin/npc/dancer" : 2,

	]));    
    set("outdoors", "yunhe");
    setup();
		
}
int init()
{
	add_action("do_move","move");
	add_action("do_jump","jump");
}

int do_move( string arg)
{
	object me=this_player();
	if (!arg || arg=="") return 0;
	if (arg=="board" || arg=="muban")
	{message("vision","你将木板移开，露出一个小洞\n",me);
	 set("exits/down", __DIR__"chuandi");
	call_out("close",5);
	return 1;
	}
}
	
int do_jump(string arg)
{
	object me=this_player();
	if (!arg || arg=="") return 0;
	if (arg=="down")
	{message("vision", HIR"\n你奋不顾身的跳进江中，四面八方的水向你涌来。\n"+
				"你扑腾了两下没有什么作用，渐渐向江底沉了下去...\n"+
				"许多小鱼游来游去......\n\n"NOR,me); 
	me->move(__DIR__"jiang");
		
	        me->die();
		return 1;
	}
	if (arg=="riverside" || arg=="hean"  || arg=="河岸")
	message("vision","你一纵身跳到了河岸上\n",me);
	me->move("/d/hangzhou/duanqiao");
	message("vision", me->name()+"从河里跳了上来\n",environment(me), ({me}) );
	return 1;
}

void close()
{  delete("exits/down");
}