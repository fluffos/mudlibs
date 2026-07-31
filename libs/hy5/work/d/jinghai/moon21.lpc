// Room: /d/jinghai/moon21.c

inherit ROOM;

void create()
{
	set("short", "走廊尽头");
	set("long", @LONG
顺着走廊走到了这里，发现没有路了。很奇怪！这里是走
廊的尽头。两侧的墙上悬挂着油毡火把，火苗随风跳动着，昏
暗的光线中，你隐约看见对面的墙上刻着一些[石像]石像描述
的是个妖魔的形象，手里拿着钢叉。另人不解的是石像突出了
墙面。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"moon9",
]));

	setup();
}
void init()
{
        add_action("do_an","an");
}

int do_an(string arg)
{
        object me = this_player();

	if( !arg && arg != "石像" && arg != "shixiang")
		return 0;
	message_vision("地下突然裂开一个洞，$N感觉身体一沉陷了下去。\n",me);
	me->move(__DIR__"moon28");
	return 1;
}
