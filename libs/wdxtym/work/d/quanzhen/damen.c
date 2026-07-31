// damen.c 大门

#include <ansi.h>
inherit ROOM;
void init();
int close_gate();
int valid_leave();
string look_gate();
int do_knock(string arg);

void create()
{
	set("short", "全真教大门");
	set("long", @LONG
你已走到了终南山半山腰，前面就是全真教的总部重阳宫了。殿
宇依山而筑，高低错落有致。周围古木森森，翠竹成林，景色清幽。
正前方黄墙碧瓦，飞檐翘檩，正中一道二丈来宽，三丈来高的朱红杉
木包铜大门(gate)，气势不凡。门上挂着一块匾(bian)，门前的石柱
上挂着一副对联(duilian)。
LONG
	);
	set("exits", ([
		"westdown" : __DIR__"jiaobei",
		"north" : __DIR__"jingji/enter",
	]));
	set("outdoors", "quanzhen");
	set("item_desc", ([
		"【大门】":"一道三丈来高的"HIR"朱红杉木"HIY"包铜"NOR"大门。\n"
				ZJOBACTS2"敲门:knock gate\n",
		"【牌匾】": HIG"
＊＊＊＊＊＊＊＊＊＊＊＊＊
＊＊		　＊＊
＊＊　全　真　古　教　＊＊
＊＊		　＊＊
＊＊＊＊＊＊＊＊＊＊＊＊＊"NOR"\n",
		"【对联】": HIY"
　　一生二二生三三生万物\n
　　地法天天法道道法自然"NOR"\n"
	]) );
	set("objects",([
		__DIR__"npc/zhike" : 1,
	]));
	set("valid_startroom", 1);
	setup();
}

void init()
{
	add_action("do_knock", "knock");
}

int close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"datang1")) )
		room = load_object(__DIR__"datang1");
	if(objectp(room))
	{
	delete("exits/east");
	message("vision", "乒地一声，里面有人把大门关上了。\n",this_object());
	if (objectp(present("qingguan", room)))
		message("vision", "知客道长上前把大门关了起来。\n", room);
	else
		message("vision", "道童上前把大门关了起来。\n", room);
	}
	else message("vision", "ERROR: gate not found(close).\n", room);

	return 1;
}

int do_knock(string arg)
{
	object room;

	if (query("exits/east"))
		return notify_fail("大门已经是开着了。\n");

	if (!arg || (arg != "gate" && arg != "east"))
		return notify_fail("你要敲什么？\n");

	if(!( room = find_object(__DIR__"datang1")) )
		room = load_object(__DIR__"datang1");
	if(objectp(room))
	{
		set("exits/east", __DIR__"datang1");
		message_vision("$N轻轻地敲了敲门，只听吱地一声，一位道童应声打开大门，他用警惕的目光上上下下打量着$N。\n",this_player());
		message("vision", "外面传来一阵敲门声，道童应声上前把大门开。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir != "east")
	return ::valid_leave(me, dir);

	if ( (me->query("family/family_name") == "全真教"))
	{
		write("道童侧身让开，说道：师兄辛苦了，请进。\n");
		return 1;
	}
	else if(present("chongyang ling", me))
	{
		write("道童打个稽首，侧身让开，说道：原来是贵客驾到，请进请进！\n");
		return 1;
	}
	if (me->query("shen") >= 0)
		return notify_fail("道童说道：这位施主请回罢，重阳宫不接待俗人。\n");
	else
		return notify_fail("道童说道：你等邪魔外道，重阳宫向不接纳，请了！\n");
}

string look_gate()
{
	return "一道三丈来高的朱红杉木包铜大门。\n";
}
