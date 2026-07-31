inherit ROOM;
void create()
{
	set("short", "风雨楼第十层");
	set("long", @LONG
这是一个纠集了江湖上十大正派高手的楼，共有十层之高。
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
	set("exits", ([
		"down" : __DIR__"b9",
		"up":__DIR__"b11",
	]));
		set("objects", ([
			__DIR__"zhang": 1,
		]));
setup();
}

void init()
{
add_action("do_dazuo","dazuo");
add_action("do_dazuo","exercise");
add_action("do_dazuo","steal");
add_action("do_dazuo","beg");
add_action("do_dazuo","fight");
add_action("do_dazuo","ansuan");
add_action("do_dazuo","hit");
add_action("do_dazuo","get");
}

int do_dazuo()
{
   object me;
   me = this_player();
   tell_object(me,"这里不能用这个指令。\n");
return 1;
}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
int sizeinv;

if( userp(me) &&
dir=="up" && ob=present("zhang sanfeng", this_object()))
return notify_fail( 
"你想硬闯？！\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
return 1;
}

