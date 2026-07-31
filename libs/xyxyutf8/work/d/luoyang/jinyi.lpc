//changan city
// Cracked by 凌惊雪 1-3-2003
inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "金衣楼");
        set ("long",@LONG 
这是一个隐蔽的小楼，楼里的陈设富丽堂皇。除此之外，小楼里
只有一张很大的桌子。桌子上堆埋了各式各样的账册和卷宗。还有一
些似乎是武学秘籍，楼的左边有一扇小门，楼上就是金衣楼其余楼所在。
LONG);
        set("exits", ([ 
                "up" : __DIR__"jinyi",
        ]));
  	set("no_fight", 1);
  	set("no_magic", 1);
  	set("item_desc", ([ /* sizeof() == 1 */
  		"door" : "一面隐藏在书柜后面的小木门，你应该可以推开它（push）。\n"
	]));  	
	set("no_clean_up", 0);
        setup();
}

void init()
{ 
	add_action("do_push","push");
}

int valid_leave(object who,string dir)
{
	if( !query("exits/"+dir) )
		return ::valid_leave(who,dir);
	this_player()->start_busy(1);	
	if(random(10)==5)
	{
		who->move("/d/luoyang/lou1");
		return 2;
	}
	else if(random(10)==5)
	{
		who->move("/d/luoyang/lou2");
		return 2;
	}
	else if(random(10)==5)
	{
		who->move("/d/luoyang/lou3");
		return 2;
	}
	else	if(random(10)==5)
	{
		who->move("/d/luoyang/lou4");
		return 2;
	}
	else	return notify_fail("你沉迷于桌上的武学秘籍，流连忘返。\n");	
}

int do_push(string arg)
{
  	object me=this_player();
  	if( !arg || ( arg!="door" && arg!="小门") )
  		return 0;
  	message_vision("$N伸手推开书柜，转眼又到了花空烟水流。\n", me);
  	me->move(__DIR__"huakong");
      	return 1;
}
