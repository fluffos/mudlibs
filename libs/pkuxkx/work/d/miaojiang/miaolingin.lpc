// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "苗岭边缘");
	set("long", @LONG
这里是苗岭的边缘，南面是连成片的森林，似乎有瘴气，没事不要轻易进入。
这里遍地是一种黄色的小草(grass)。
LONG );
    set("item_desc", ([
		"grass" : "一株黄色的小草，不知道有什么作用，你可以摘(zhai)下它。\n", 
	]));
	set("outdoors", "miaojiang");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : "/d/yueyang/guandaos3",
		"eastdown" :      "/d/nanchang/guandaow3",
        "southup" : __DIR__"miaoling1",
	]));
	setup();
	
}


void init()
{
	add_action("do_zhai", ({ "zhai", }));
}

int found(object me)
{
	object ob = new("/d/miaojiang/obj/grass");
	if (ob) 
	{
		ob->move(me);
		me->add_busy(random(2));
		message_vision("$N摘下一朵黄色的小草。\n", me);
	}
	return 1;
}

int do_zhai()
{	
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
    else if (present("xiao cao",me)&&present("xiao cao",me)->query("miao_cao"))
    {
        return notify_fail("你身上不是有一株小草吗？\n");
    }
    else 
		{      
			tell_object(me,"你伸手去摘那朵土黄色的小草。\n", me);
            found(me);    
        }
	return 1; 
}