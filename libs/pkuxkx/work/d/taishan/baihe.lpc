// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "白鹤泉");
	set("long", @LONG
相传从前这里有一个白鹤泉，它的水清凉甘甜，为泰山之最。
这泉水长年涌流不断，喷出的水象仙鹤扑扇着翅膀洗澡一样，因以
为名。可惜后来有一个自私自利的小官，独霸了泉水，后来更因迷
信风水之说，把泉眼堵塞，白鹤泉从此便干涸了。现在只剩下一座
刻着「白鹤泉」三字的石坊以为纪念。从这里继续北上，便是上山
之路。路边长了一些薄荷(bohe)。
LONG
	);
    set("item_desc", ([
		"bohe" : "薄荷清凉醒脑，可以入药，一般生长在山间。你可以摘(zhai)下来。\n", 
	    ]));
	set("exits", ([
		"northup" : __DIR__"yitian",
		"southdown" : __DIR__"daizong",
	]));

	set("resource/water",1);
	set("outdoors", "taishan");
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
    if (me->query_temp("薄荷"))
    {
        return notify_fail("薄荷已经被摘完了。\n");
    }
    me->set_temp("薄荷",1);
    gc=new("/d/taishan/obj/bohe");
    gc->move(me);
    message_vision("$N摘下了一片薄荷。\n",me);
    return 1;
}