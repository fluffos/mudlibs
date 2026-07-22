// Room: /d/city/dongdajie0.c

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是东城门，可以听到守城
官兵的盘查声。北边是一家打铁铺，敲敲打打的声音不断从其中传出来。南边
是家兵器铺，人来人往生意很是兴旺。
LONG
	);
	set("outdoors", "扬州");

	set("objects", ([
		"/d/zhiye/npc/caikuang-shi": 1,
	]) );

	set("exits", ([
		"east" : __DIR__"dongmen",
		"south" : "/d/zhiye/bingqipu1",
		"west" : __DIR__"dongdajie1",
		"north" : "/d/zhiye/datiepu1",
	]));

	set("incity",1);
	setup();
}

void init()
{
        object ob, me;
        me = this_player();

        if ( wizardp(me) && me->query("env/test")== 3) {
		if (!objectp(ob = present("lushi", me))){
			ob = new("/d/zhiye/obj/kuangshi4-2");
			ob->move(me);
			ob = new("/d/zhiye/obj/kuangshi4-2");
			ob->move(me);
        	}
		if (!objectp(ob = present("tiechui", me))){
			ob = new("/d/zhiye/obj/tiechui");
			ob->move(me);
		}
	}
}