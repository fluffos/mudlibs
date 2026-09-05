// Room: /clone/misc/cityhall.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:40 2009
// create by Zine Aug 28 2010

#include <ansi.h>
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "襄阳府衙");
	set("long",	@LONG
这里就是当年襄阳府衙的正厅，也就是郭靖大侠指挥多次击退蒙古大军的
帅府。影壁之后一架不知名的器械积满了灰尘。桌案(desk)上似乎压着什么东
西。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"backyard",
	    "south" : __DIR__"southdoor",
   	    "west" : __DIR__"westdoor",
		"east" : __DIR__"eastdoor",
		"southeast" : __DIR__"jiaomen",
	]));
	set("item_desc", ([
		"desk" : "桌上一书压着一本书，你可以把它拿(na)起来。\n", 
	]));
	set("objects", ([("/biwu/xy/obj/bow") : 1,
    ]));
	
	set("flag","帅旗");
	set("default_flag_hp",10);
	set("flag_hp",10);	
	set("open",1);
	setup();
}

void init()
{
	add_action("do_open", ({ "open", "kai","kaiqi"}));
	add_action("do_close", ({ "close", "guan", "bi"}));
	add_action("do_na", ({ "find", "na","zhao"}));
	::init();
}

int do_close()
{
	object room1= load_object(__DIR__"weststreet");
	object room2= load_object(__DIR__"eaststreet");
	object room3= load_object(__DIR__"southstreet");
	object room4= load_object(__DIR__"northstreet");
	object room5= load_object(__DIR__"backyard");
	object me= this_player();
	if(me->is_busy())
		{
			return notify_fail("你正忙着呢。\n");
		}
	if (!query("closed"))
		{ 
			room1->delete("exits/east");
			room2->delete("exits/west");
			room3->delete("exits/north");
			room4->delete("exits/south");
			room5->delete("exits/north");
			delete("exits/south");
			delete("exits/east");
			delete("exits/west");
			set("closed",1);
			delete("open");
			me->add_busy(1);
			message_vision(HIW"$N按动机关，把襄阳府衙所有大门关闭。\n"NOR, me);
			return 1;
		 }
	else
		 { 
			return notify_fail("所有门都已经关闭了。\n");}
		 }
int do_open()
{
	object room1= load_object(__DIR__"weststreet");
	object room2= load_object(__DIR__"eaststreet");
	object room3= load_object(__DIR__"southstreet");
	object room4= load_object(__DIR__"northstreet");
	object room5= load_object(__DIR__"backyard");
	object me= this_player();
	if(me->is_busy())
		{
			return notify_fail("你正忙着呢。\n");
		}
	if (!query("open"))
		{
			room1->set("exits/east", __DIR__"westdoor");
			room2->set("exits/west", __DIR__"eastdoor");
			room3->set("exits/north", __DIR__"southdoor");
			room4->set("exits/south", __DIR__"northdoor");
			room5->set("exits/north", __DIR__"northdoor");
			set("exits/south",__DIR__"southdoor");
			set("exits/east",__DIR__"eastdoor");
			set("exits/west",__DIR__"westdoor");
			set("open",1);
			delete("closed");
			me->add_busy(1);
			message_vision(HIC"$N按动机关，把襄阳府衙所有大门打开。\n"NOR, me);
			return 1;
		}
	else
		{
			return notify_fail(HIR"四门都打开了，你还要开哪个门？\n"NOR);
		}
}

int find(object me)
{
	object ob,ob1,ob2;
	if (this_object()->query_temp("wmfound"))
		{
			if(random(10)>8)
				{
                    ob1= new("/biwu/xy/obj/map");
					ob1->move(me);
					me->set_temp("xiangyang/got", 1);
					message_vision("$N找到了一本襄阳山川兵力分布图。\n", me);
				}
			else
				{
                    ob2= new("/biwu/xy/obj/zinebook");
					ob2->move(me);
					me->set_temp("xiangyang/got", 1);
					message_vision("$N找到了一本人物传记。\n", me);
				}
		}
	else 
		{
            ob = new("/biwu/xy/obj/wmbook");
			ob->move(me);
			me->set_temp("xiangyang/got", 1);
			message_vision("$N找到了一本武穆遗书。\n", me);
			this_object()->set_temp("wmfound",1);
		}
	return 1;
}

int do_na()
{
	object me = this_player();
	if(me->is_busy())
		{
			return notify_fail("你正忙着呢。\n");
		}
    if( (int)me->query_temp("xiangyang/got") ) 
		{
			return notify_fail("你已经在桌上找到了一本书，看来是不会再有新的发现了。\n");
		}
	else 
		{
			message_vision("$N小心翼翼地翻着桌上的书，从中选出最感兴趣的。\n", me);
			find(me);  
		}
    return 1; 
}

int valid_leave(object me, string dir)
{  
	if(!present("shenbi gong", me))
		{return 1;}
	else
		{
			if ( dir == "east" || dir == "west"|| dir == "south"|| dir == "north"|| dir == "southeast" )
			return notify_fail(HIR"你刚准备带走神臂弓，竟发现神臂弓被人用一条儿臂粗的钢索固定在墙上。\n"NOR);
			return ::valid_leave(me, dir);
		}
}
