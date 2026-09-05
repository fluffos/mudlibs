// Room: /d/suzhou/bailianchi.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "白莲池");
	set("long", @LONG
白莲池位于二仙亭的北面，池中种有千叶莲花，池上架彩
莲曲桥，相传吴王夫差与西施曾在此采莲赏荷。池中飘了一些
鱼腥草(cao)。
LONG );
    set("item_desc", ([
		"cao" : "鱼腥草可以入药，一般生长水上。你可以摘(zhai)下来。\n", 
	    ]));
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"erxianting",
	]));
	set("objects", ([
		__DIR__"npc/lady2" : 1,
	]));
    set("couldfish",1);
	setup();
	
}

void init()
{ 
	add_action("do_zhai","zhai"); 
}

int do_zhai()
{
    object me=this_player();
    object gc;
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("鱼腥草"))
    {
        return notify_fail("鱼腥草已经被摘完了。\n");
    }
    me->set_temp("鱼腥草",1);
    gc=new("/d/taishan/obj/yuxingcao");
    gc->move(me);
    message_vision("$N摘下了一片鱼腥草。\n",me);
    return 1;
}

int valid_leave(object me,string dir)
{  
	if (dir=="northwest")
    {
           return notify_fail("你远远望去，大江滚滚东去入海，却没有路通过去。\n");
        
    }
	return ::valid_leave(me, dir);
}
