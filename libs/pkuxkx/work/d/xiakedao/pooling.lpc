//瀑布
//for xiakedao
//modified by aiai 98/10/27
#include <ansi.h>

inherit ROOM;

void create()
{
	set ("short", "瀑布");
	set ("long", @LONG

转了两个弯后，只见一道瀑布(waterfall)从十余丈高处直挂下来，
看来这瀑布便是山涧的源头。路旁有一株大树，参天耸立。
此树树干甚为粗壮，似乎需要四五个人手拉手才能将其抱
拢。由于瀑布的常年冲刷，树干显得极其光滑。可以看到
在很高的一段树枝上，挂着一件油布雨衣（raincoat〕。
LONG );

        set("outdoors", "xiakedao");

	set("no_sleep_room",1);

	set("exits", ([
                "westdown" :__DIR__"hillpath3",
	]));
	set("item_desc", ([ /* sizeof() == 2 */

	"油布雨衣" :"那是一件高高挂于树上的雨衣，不知怎样才能弄下来。要是有根树枝就好了，\n"
		     "或许能够挑下来。\n",
	"瀑布"     :HIW"好大一条瀑布，如银河泻地。隐隐可以看到，瀑布之中似乎有一个山洞，\n"
			"不知道能够跃到那里去.\n"NOR,
]));

	setup();
}

void init()
{
	add_action("do_tiao",  "tiao");
	add_action("do_climb", "climb");
	add_action("do_jump",  "jump");
	add_action("do_jump",  "yue");
}

int do_jump(string arg)
{
	object me;
	object raincoat;
	me = this_player();
         if ( (!arg) || ( arg != "瀑布" && arg != "waterfall") )
	{
		tell_object(me,"你想跳什么呀跳，小心掉到山谷里！\n");
		return 1;
	}
	if ( ! objectp( raincoat= present("raincoat",me) ) )
		return notify_fail("如此湍急之瀑布，冒然跃去怕是不妥。还是想想办法吧。\n");
	else{
		me->start_busy(3);
		call_out("ok_jump",1,me);
		return 1;
	}
}

int ok_jump(object me)
{
	message_vision(HIR"$N纵身一跃，向瀑布深处的洞口跳去。\n"NOR,me);
	message_vision(HIW"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"/ // // // // // // // // // // // // // // // // // // // // // \n"
			"～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～\n"NOR,me);
	message_vision(HIG"$N穿过瀑布，进入洞口。\n"NOR,me);
	me->move(__DIR__"dongkou");
	return 1;
}

int do_climb(string arg)
{
	object me;
	if ( (!arg) || ( ( arg != "tree" ) && ( arg != "树" ) ) )
		return notify_fail("你想爬什么?\n");
	
	me = this_player();
	if ( me->query_skill("dodge",1) < 200 )
	{
		message_vision("$N使出毕生功力，轻身跃上。无奈树干太滑，无处着力，$N最终还是掉了下来。\n",me);
		return 1;
	}
	else {
		me->start_busy(3);		
		call_out("ok_climb",1,me);
		return 1;
	}
}

int ok_climb(object me)
{
	message_vision(HIG"$N使出壁虎游墙功，贴着树干直蹿了上去...\n"NOR,me);
	call_out("ok_getyi",2,me);
	return 1;
}
int ok_getyi(object me)
{
	object raincoat; 
	message_vision(HIY"紧接着，$N轻舒猿臂，将雨衣拿了下来。\n"NOR, me);
      raincoat = new("/d/xiakedao/obj/raincoat");
	raincoat->move(me);
	return 1;
}	
int do_tiao(string arg)
{
	object raincoat,shuzhi;
	object me;
	me = this_player();
	if ( ( !arg ) || ( ( arg != "油布雨衣" ) && ( arg != "raincoat" ) )  )
		return notify_fail("你想挑什么？\n");
	if ( ! objectp( shuzhi = present("shu zhi",me) ) )
		return notify_fail("奇怪，奇怪，你拿什么挑呀？\n");
       raincoat = new("/d/xiakedao/obj/raincoat");
	raincoat->move(me);
	message_vision(HIB"$N用手紧握住一根树枝，小心翼翼地将雨衣挑了下来。\n"NOR,me);
	destruct(shuzhi);
	return 1;
} 
