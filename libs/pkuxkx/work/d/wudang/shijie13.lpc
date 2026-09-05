// shijie13.c 石阶
// by Xiang

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", 
"你走在一条坚实的石阶上，不时地有进香客从你的身边走\n"
"过。一边是峭壁，一边是悬崖，抬头隐约可见笼罩在云雾中的\n"
"天柱峰，听着流水淙淙，令人心旷神怡。两旁的路边长了一些\n"
"薄荷(bohe)。\n"
	);
        set("outdoors", "wudang");
    set("item_desc", ([
		"bohe" : "薄荷清凉醒脑，可以入药，一般生长在山间。你可以摘(zhai)下来。\n", 
	    ]));
	set("exits", ([
		"southdown" : __DIR__"shijie12",
		"northup" : __DIR__"yuzhen",
	]));
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