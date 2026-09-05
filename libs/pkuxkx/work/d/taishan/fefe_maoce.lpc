// Room: /taishan/fefe_maoce.c
// ERIC 96.9.23 

inherit ROOM;

void create()
{
	set("short", "茅厕");
	set("long", @LONG
*****************************
    *         便后冲水          *
    *****************************
LONG
	);
	set("no_beg",1);

	setup();
}

void init()
{
        add_action("do_out", "out");
}

int do_out()
{
	object me;
	me = this_player();

	message("vision",
		me->name() + "突然低声地唱起歌来，一边唱一边提起了裤子，往外走了出去。\n",
		environment(me), ({me}) );
       	me->move("/d/taishan/fefe5");
             	message("vision",
		me->name() + "从茅厕里走了出来，还低声地哼着歌子，看起来十分舒服。\n",
             environment(me), ({me}) );
	return 1;

}	
