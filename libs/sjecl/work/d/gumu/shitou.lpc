// shitou.c By River 98/08/29

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIC"石室"NOR);
	set("long", @LONG
此地供各弟子打坐静修之用。地上仅有几个蒲团，几个古墓弟子正在闭目
领悟。正面的石墙( qiang)上刻着不少文字, 仔细一看，原来都抄录着四书五
经等古籍，用来给古墓弟子提高修养。
LONG
	);

	set("exits", ([
		"west" : __DIR__"gmqs",
		"south" : __DIR__"yaofang",
		"north" : __DIR__"lgf",
	]));

	set("item_desc", ([
		"qiang" : "墙上写满了各种古籍文字。\n",
	]));

	create_door("west", "石门", "east", DOOR_CLOSED);

	setup();
}

void init()
{
	add_action("do_du","read");
	add_action("do_lingwu","yanxi");
}

int do_du(string arg)
{
	mapping fam;
	object me = this_player(); 

	if ( !living(me) ) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");
	if (arg == "qiang"){                 
		if ((int)me->query("jing") < 20 )
			return notify_fail("你觉得好累,好想睡觉。\n");
		if ( me->query_skill("literate",1) >100)
			return notify_fail("你已经完全读懂了墙上的文字。\n");
		if ( me->query("potential", 1) < 1)
			return notify_fail("你的潜能没了，不能再继续修习了。\n");
		me->add("potential", -1);
		me->receive_damage("jing", 150 / (int)me->query("int"));
		me->improve_skill("literate", me->query_int() *5/6 );
		write("你对着石壁，仿佛有所领悟。\n");
		return 1;
	}
	return notify_fail("你要读什么？\n");
}

int do_lingwu(string arg)
{
	mapping fam;
	object me;
	int lvl;
         
	me = this_player();

	if (! living(me)) return 0;

	if( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");

	if (! arg ) return 0;

	if ( arg != "parry" && arg != "sword" && arg != "cuff" && arg != "hand"
	 &&  arg != "strike" && arg != "force" && arg != "throwing" && arg != "dodge" )
		return notify_fail("你无法从这里领悟其他的武功。\n");

	lvl = me->query_skill( arg, 1);

	if ( lvl < 101 ) 
		return notify_fail("你的"+to_chinese(arg)+"太低，无法在此领悟。\n");

	if ( lvl > 120 ) 
		return notify_fail("你已经无法从这里领悟到什么了。\n");

	if (me->query("jing") < 40)
		return notify_fail("你精力不能集中,去稍作歇息吧。\n");

	if ((int)me->query_skill("literate", 1) < 100)
		return notify_fail("你读书写字等级不够，无法领悟此处的奥妙。 \n");

	me->receive_damage("jing", 20 + random(20));
	me->improve_skill( arg, (int)(me->query_int()/2)+ (int)(me->query_skill(arg, 1)/4 ));
	tell_object(me,"你对着石壁，对"+to_chinese(arg)+"有所领悟。\n");
	return 1;
}
