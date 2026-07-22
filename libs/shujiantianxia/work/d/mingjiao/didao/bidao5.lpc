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
这是已经是秘道的另一边，窄窄的，只能容人一身，向上看如一口井，四
周都是石壁(wall)，向北不知道可通向哪里。
LONG
     );

	set("exits", ([
		"northdown" : __DIR__"bidao6",
	]));
       	set("item_desc", ([
               "wall" : "四周都是石壁，但偶尔有几处松动之处，似乎可以拉动。\n"
        ]));
        setup();
}

void check_trigger()
{
	if((int)query("left_trigger")==2){
		message("vision", "\n石壁缓缓向前，却是一堵极厚，极巨，极重极实的石门。\n", this_object() );
		set("exits/out", __DIR__"bidao4");
		delete("left_trigger");
		remove_call_out("close_passage");
		call_out("close_passage", 10);
	}
}

void close_passage()
{
	if( !query("exits/out")) return;
	message("vision", "\n石门发出轧轧的声音，将出口处堵住了。\n", this_object() );
	delete("exits/out");
}

void init()
{
	add_action("do_pull",({"pull", "la"}));
}

int do_pull(string arg)
{
	object me = this_player();

	if (!arg || arg=="") return 0;
	if ( me->query_skill("force", 1) < 120 )
		return notify_fail("你深深的吸了口气，用力的推，无奈内力不够，确实推不动！\n");
	if (arg=="wall")
		return notify_fail("你吸了一口气，用力对着石壁一拉，结果毫天动静。\n");
	if (arg=="石壁")
		return notify_fail("你吸了一口气，用力对着石壁一拉，结果毫天动静。\n");
        if (arg=="wall right")
		return notify_fail("你吸了一口气，用力对着石壁向右一拉，结果毫天动静。\n");
        if (arg=="wall left"){
		message_vision("$N吸了口气，将石壁往左拉，石壁动了动，又移回原位。\n", me);
		add("left_trigger", 1);
    		check_trigger();
		return 1;
	}
        else{
              write("你要将石壁拉向那个方向？\n");
              return 1;
        }
}
