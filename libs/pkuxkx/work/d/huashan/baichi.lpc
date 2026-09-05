// baichi.c

inherit ROOM;

void create()
{
        set("short", "百尺峡");
	set("long", @LONG
走过千尺幢，前面又见另一要命的百尺峡，百尺峡不似千尺幢般险峻
，但亦十分陡峭，岩壁两侧设有铁索以作扶拦。路边有一些薄荷(bohe)。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"qianchi",
  "eastup" : __DIR__"laojun",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );
        set("item_desc", ([
		"bohe" : "薄荷清凉醒脑，可以入药，一般生长在山间。你可以摘(zhai)下来。\n", 
	    ]));
        set("room","room14");
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