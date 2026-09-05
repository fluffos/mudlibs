// Room: /clone/misc/weststreet.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "西大街");
	set("long", @LONG
这里是古襄阳的西大街，一条笔直的长街直贯东西。地上堆(dui)着几个沙
袋，不知道有何用途。
LONG
	);
	set("exits", ([ /* sizeof() == 6 */
		"west" : __DIR__"westgate",
		"east" : __DIR__"westdoor",
	    "north" : __DIR__"dune",
		"south" : __DIR__"lot",
		"northwest" : __DIR__"xx1",
	]));
	set("objects", ([
       ("/biwu/xy/npc/yexingren") : random(2),
    ]));
	set("no_clean_up", 0);
	set("west_hp", 6);
	setup();
}

void init()
{
	add_action("do_dui", ({ "accumulate", "dui"}));
	::init();
}

int check(object me)
{
	object shadai;
	object nextdoor= load_object(__DIR__"cityhall");
	if(nextdoor->query("open"))
		{
			tell_object(me,"府衙四门大敞着，直接进去就可以了，何必舍近求远？\n");
			return 1;
		}
	else 
		{
			if(me->is_busy())
				{
					return notify_fail("你正忙着呢。\n");
				}
			else
				{
					if (query("finished"))
						{
							tell_object(me,"已经堆出了一条可以翻过墙的路，你不用再继续堆沙包了。\n");
						}
					else
						{
							message_vision("$N把身上的沙袋放在墙角，越堆越高。\n", me);
							message_vision("沙包越来越高，很快就能让人直接翻过墙去。\n", me);
							if(query("west_hp") - 1 <= 0)
								{
									message_vision("$N把身上的沙袋放在墙角，越堆越高。\n", me);
									tell_object(me,"沙包足够多了，已经堆出一条可以翻过墙的路。\n");
									set("exits/eastup", __DIR__"qiangtou");
									me->add_busy(random(2));
									shadai=present("sha dai",me);
									set("finished",1);
									if(objectp(shadai)) 
									destruct(shadai);
								}
							else
								{
									add("west_hp",-1);
									me->add_busy(random(2));
									shadai=present("sha dai",me);
									if(objectp(shadai)) 
									destruct(shadai);
								}	
						}
					return 1;
				}
		}
}

int do_dui()
{
	object me = this_player();
    if(!present("sha dai", me))
		{
			tell_object(me,"你身上什么都没有，你要把什么堆在这里？\n");
		}
    else 
		{      
			check(me);    
        }
    return 1; 
}