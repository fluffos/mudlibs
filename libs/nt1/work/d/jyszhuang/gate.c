// Room: /d/jyszhuang/gate.c
// Modified by Lonely Nitan@Mud

#include <localtime.h>
#include <ansi.h>
#include <room.h>

inherit ROOM;

int do_close_men();
int do_open_men(string arg);


void create()
{
        mixed *local;
        object *ob;
        local = localtime(time());

        set("short", HIY"精意山庄"NOR);
        set("long",
HIR"这里就是江湖中流传了近千年，江湖中最神秘的精意山庄，江湖中人\n"
"只知道有这个山庄，但一直以来没有人知道它的位置，也没有人知道精意\n"
"山庄的主人是谁，但江湖中人都知道一件事就是：精意山庄中人，哪怕是\n"
"个仆人，他的智慧、他的武学，江湖中自古以来任何大宗师都无法望之其\n"
"背！精意山庄自古就是江湖中最神圣、最充满诱惑的地方，甚至比无敌于\n"
"天下的武学秘籍、绝世美女、黄金宝藏，都充满诱惑。如果说江湖中所有\n"
"人都认同的真理只有一个的话，那么这个真理就是：精意山庄就是智慧与\n"
"力量的唯一主人！\n"NOR
HIM"    传说是最近从天空中坠落的一颗陨石上刻画着山庄的位置。\n"NOR
CYN"    然而当江湖中人找到陨石来到了这里，却发现不论用什么办法都无法\n"
"进入山庄，除非在每个月的２１号这天。当人们进入山庄内，更让他们惊\n"
"奇的是山庄中不见任何人，但很多明显的迹象表明山庄不是没有人，而是\n"
"在每个月的２１号这天山庄的人突然消失。比这更奇怪的就是：每个月的\n"
"２１号进去的人，在２２号突然发现自己又在山庄外了。这里到底蕴藏着\n"
"什么秘密？山庄内到底有些什么？？？无人知晓！\n"NOR

);

        set("no_fight", 1);

        set("objects", ([
	]));


    if( local[LT_HOUR] == 2 || local[LT_HOUR] == 4 || 
		local[LT_HOUR] == 6 || local[LT_HOUR] == 8 || 
		local[LT_HOUR] >= 10 && local[LT_HOUR] <= 12 
		)
	{
  		set("exits", ([
			"south" : __DIR__"beidajie2",
			"enter" : __DIR__"square",
			]));
	}
	else
	{
  		set("exits", ([
			"south" : __DIR__"beidajie2",
			]));
	}

	setup();
 
}



int do_open_men(string arg)
{
	object ob, me = this_player();
	object room;

	if (query("exits/enter"))
		  return notify_fail("这扇门已经是打开的。\n");

        if (!arg || arg != "men" )
		  return notify_fail("你要打开什么？\n");

        if ( (string)SECURITY_D->get_status(me) != "(arch)" &&(string)SECURITY_D->get_status(me) != "(admin)" )
		  return notify_fail("什么？\n");

	log_file("status_log", sprintf( "%s opened jysz door on %s.\n", me->query("id"), ctime(time()) ));

	set("exits/enter", "/d/jyszhuang/square");
	message_vision("$N用手指凌空一点，吱地一声，打开一道大门。\n", this_player());

	return 1;
}

int do_close_men()
{
	if (!query("exits/enter"))
		  return notify_fail("这扇门已经是关上的。\n");

  	delete("exits/enter");
	message("vision", "大门慢慢地关上了。\n", this_object());
     	return 1;
}


void init()
{

	add_action("do_open_men", "open");
	add_action("do_close_men", "close");
}

