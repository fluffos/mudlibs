// /d/mingjiao/bidao4.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06


inherit ROOM;
void check_trigger();
void close_passage();

void create()
{
        set("short","秘道");
        set("long", @LONG
这是已经是秘道的尽头，窄窄的，只能容人一身，向上看如一口井，四周
都是石壁(wall)，向西则是向上的秘道，连接出口。
LONG
     );

	set("exits", ([
		"south" : __DIR__"bidao3",
                "westup"  : __DIR__"bidao17",
	]));
       	set("item_desc", ([
               "wall" : "四周皆为石壁，但偶尔有几处松动之处，似乎可以推动。。\n"
        ]));

        setup();
}

void check_trigger()
{
	if( (int)query("right_trigger")==2){
		message("vision", "\n石壁缓缓退后，却是一堵极厚，极巨，极重极实的石门。\n", this_object());
		set("exits/enter", __DIR__"bidao5");
		delete("right_trigger");
		remove_call_out("close_passage");
		call_out("close_passage", 10);
        }
}

void close_passage()
{
        if( !query("exits/enter") ) return;
        message("vision", "\n石门发出轧轧的声音，将入口处堵住了。\n", this_object());
        delete("exits/enter");
}

void init()
{
	add_action("do_push",({"push", "tui"}));
}

int do_push(string arg)
{
	object me = this_player();

	if (!arg || arg=="" ) return 0;
	if (me->query_skill("force", 1) < 120)
		return notify_fail("你深深的吸了口气，用力的推，无奈内力不够，确实推不动！\n");
	if (arg=="wall")
		return notify_fail("你吸了一口气，用力对着石壁一推，结果毫天动静。\n");
	if (arg=="石壁")
		return notify_fail("你吸了一口气，用力对着石壁一推，结果毫天动静。\n");
	if (arg=="wall left")
		return notify_fail("你吸了一口气，用力对着石壁向左一推，结果毫天动静。\n");
	if (arg=="wall right"){
		message_vision("$N吸了口气，将石壁往右推，石壁动了动，又移回原位。\n",me);
		add("right_trigger", 1);
    		check_trigger();
		return 1;
	}else{
	     write("你要将石壁推向那个方向？\n");
             return 1;
        }
}
