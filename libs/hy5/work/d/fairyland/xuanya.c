// Room: /u/qingyun/jyzj/xuanya.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>

inherit ROOM;

int do_jump(string arg);

void create()
{
	set("short", HIY"悬崖"NOR);
	set("long", @LONG
你来到悬崖之上，突然在对面传来几声狼嗥，甚是凄厉可怖。只见对面几
只大灰狼仰起头，向着你张牙舞爪的嗥叫，想是要食以果腹，只是之间有一条
深不见底的万丈峡谷，无法过来。
LONG	);
	set("exits", ([
		"eastdown" : __DIR__"conglin2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
}

void init()
{
	add_action("do_jump", ({"jump", "tiao", "yue"}));
}

int do_jump(string arg)
{
        object me = this_player();

        if (arg == "down") { 
                message("vision", me->name() + "一个纵身，跳下了悬崖。\n", environment(me), ({me}));
if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) {
message_vision("$N一纵身想跳下悬崖，结果......\n", me);
me->unconcious();
return 1;
}
if (me->query_kar() >= 25) {
			if (me->query_skill("dodge", 1) >= 50) {
				write(HIR"\n你向下一跳，直向万丈深渊掉去！！！\n\n"NOR);
				write(HIR"\n你下落的速度太快，冲开弥漫之雾，直向下堕！！！\n\n"NOR);
				write(HIR"\n你只觉身旁风声虎虎，身子不断的向下摔落......\n"
					   "偶尔见到峭壁上有树枝伸出，便想去抓，但下落之\n"
					   "力太大，树枝喀喇的一声断了！！！\n\n"NOR);
				write(HIY"\n但，你的下落速度慢了一点，急忙使一招“乌龙绞柱”，牢牢的抱住了一株松树。\n\n"NOR);
        		        me->move(__DIR__"songshu");
                		message("vision", me->name() + "死死的抱住了这棵小松树。\n", environment(me), ({me}));
			}
			else {
				write(HIR"\n你向下一跳，直向万丈深渊掉去！！！\n\n"NOR);
				write(HIR"\n你下落的速度太快，冲开弥漫之雾，直向下堕！！！\n\n"NOR);
				write(HIR"\n你只觉身旁风声虎虎，身子不断的向下摔落......\n"
					   "偶尔见到峭壁上有树枝伸出，便想去抓，但下落之\n"
					   "力太大，树枝喀喇的一声断了！！！\n"NOR);
				write(HIR"\n"
					"		.\n"
					"		.\n"
					"		.\n"NOR);
	                	me->move(__DIR__"xuedi");
			        me->unconcious();
        	        	message("vision", me->name() + "从悬崖上摔了下来。\n", environment(me), ({me}));
			}
		}
	 	else {
			if (me->query_skill("dodge", 1) >= 150) {
				write(HIR"\n你向下一跳，直向万丈深渊掉去！！！\n\n"NOR);
				write(HIR"\n你下落的速度太快，冲开弥漫之雾，直向下堕！！！\n\n"NOR);
				write(HIR"\n你只觉身旁风声虎虎，身子不断的向下摔落......\n"
					   "偶尔见到峭壁上有树枝伸出，便想去抓，但下落之\n"
					   "力太大，树枝喀喇的一声断了！！！\n\n"NOR);
				write(HIY"\n但，你的下落速度慢了一点，急忙使一招“乌龙绞柱”，牢牢的抱住了一株松树。\n\n"NOR);
        		        me->move(__DIR__"songshu");
                		message("vision", me->name() + "死死的抱住了这棵小松树。\n", environment(me), ({me}));
			}
			else if (me->query_skill("dodge", 1) >= 20) {
				write(HIR"\n你向下一跳，直向万丈深渊掉去！！！\n\n"NOR);
				write(HIR"\n你下落的速度太快，冲开弥漫之雾，直向下堕！！！\n\n"NOR);
				write(HIR"\n你只觉身旁风声虎虎，身子不断的向下摔落......\n"
					   "偶尔见到峭壁上有树枝伸出，便想去抓，但下落之\n"
					   "力太大，树枝喀喇的一声断了！！！\n"NOR);
				write(HIR"\n"
					"		.\n"
					"		.\n"
					"		.\n"NOR);
				me->move(__DIR__"xuedi");
				me->unconcious();
				message("vision", me->name() + "从悬崖上摔了下来。\n", environment(me), ({me}));
			}
			else {
				write(HIR"\n你向下一跳，直向万丈深渊掉去！！！\n\n"NOR);
				write(HIR"\n你下落的速度太快，冲开弥漫之雾，直向下堕！！！\n\n"NOR);
				write(HIR"\n你只觉身旁风声虎虎，身子不断的向下摔落......\n"
					   "偶尔见到峭壁上有树枝伸出，便想去抓，但下落之\n"
					   "力太大，树枝喀喇的一声断了！！！\n"NOR);
				write(HIR"\n"
					"		.\n"
					"		.\n"
					"		.\n"NOR);
		                me->move(__DIR__"xuedi");
//			        me->set_temp("last_damage_from", "跳下悬崖" + "摔");
				me->die();
	        	        message("vision", me->name() + "从悬崖上摔了下来。\n", environment(me), ({me}));
			}
		}
		return 1;
	}
	return 0;
}				
     
