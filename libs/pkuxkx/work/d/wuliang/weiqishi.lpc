// by paladin
// modified by iszt@pkuxkx, 2007-02-05

inherit ROOM;
void create()
{
	set("short", "围棋室");
	set("long", @LONG
室中并无衾枕衣服，只壁上悬了一张七弦琴，弦线俱已断绝。又见床左有张
石几，几上刻了十九道棋盘，棋局上布着二百馀枚棋子，然黑白对峙，这一局并
未下毕。你忍不住观看起这残局(canju)来。
LONG
	);
	set("no_fight", 1);
	set("item_desc", ([ /* sizeof() == 2 */
		"canju" : "这局棋后果如何，你实在推想不出，似乎黑棋已然胜定，但白棋未始没有反败为胜之机。\n",
	]));

	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"shishi",
	]));
	set("no_clean_up", 0);

}

void init()
{
	add_action("do_watch","watch");
	add_action("do_move","move");
}

int do_move(string arg)
{
	object me = this_player();
	object qipu;

	if ( !arg || arg != "canju")
		return 0;
	if ( !me->query_temp("riyue/getnote"))
	{
		message_vision("$N把残局移开，但什么也没发现。\n",me);
		return 1;
	}
	message_vision("$N把残局移开，从下面捡起一本棋谱。\n",me);
	seteuid(getuid());
	qipu=new("/d/riyuejiao/npc/obj/ouxuepu");
	qipu->move(me);
	me->delete_temp("riyue/getnote");
	return 1;
}

int do_watch(string arg)
{
	object me;
	int times;
	me = this_player();

	if(!arg || (sscanf(arg, "canju %d", times) != 1 && arg != "canju"))
		return notify_fail("你想读什么？\n");

	if(!times)
		times = 1;
	if(times > 50)
		return notify_fail("学习次数不能超过五十次。\n");
  if(me->is_busy())
  {
  	write("你真行，这么忙还不忘看人下棋。\n");
  	return 1;
  }	

	if( (int)me->query("jing",) < 50 * times)
	{
		write("你精力不够，无法领悟残局。\n");
		return 1;
	}

	message_vision("$N正专心观看残局。\n", me);

	if( (int)me->query_skill("literate",1) < 80)
	{
		write("你的读书写字水平不足以靠领悟残局提高。\n");
		return 1;
	}
	if( (int)me->query_skill("literate",1) > 150)
	{
		write("你看了半天，发现残局对你太浅了。\n");
		return 1;
	}

	message_vision("$N对着残局研究了一会,似乎有些心得。\n", me);
	me->add("jing", -50 * times);

	me->improve_skill("literate",(int)(me->query_skill("literate")+10) * times);

	return 1;
}
