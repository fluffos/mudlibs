inherit ROOM;

void create()
{
  set("short","内室");
  set("long",@LONG
这里是内室，较为气闷。此内室甚是安静，地上放着各式的竹签
竹签（qian)按奇怪位置分列，好像和奇门八卦暗合。
LONG);
  set("outdoors","yinju");
set("exits",([
   "north"  : __DIR__"maowu",
      ]));
  set("item_desc", ([
                "qian" : "通过竹签，可以学习一种奇门功夫（study)。\n",
]));
  setup();
}
void init()
{
        add_action("do_study","study");
}
int do_study(string arg)
{
        object me = this_player();

	if (arg != "qian" && arg != "bei")
		return 0;

	if (me->is_busy())
      {
		write("你现在正忙着呢。\n");
		return 1;
	}

	if( me->is_fighting() )
       {
		write("你无法在战斗中专心下来研究签上的文字！\n");
		return 1;
	}

	if (me->query("jing") < 30) {
		write("你太累了，无法集中精神来研究签上的文字。\n");
		return 1;
	}
	if (me->query_skill("count", 1) > 60) 
      {
		write("你仔细地读了一遍签上的文字，发现已经太浅显了，无法学到新的知识。\n");
		return 1;
	}
	
	me->receive_damage("jing", 25);
	message_vision("$N仔细地注视着竹签的排列位置。\n", me);
	write("你对于阴阳八卦之学有了进一步的认识。\n");
	me->improve_skill("count", me->query("int") / 2 + random(me->query("int") / 2));
	return 1;
}
