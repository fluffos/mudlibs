// Room: /city/wudao2.c
// Date: Feb 27.1998 by Java
#include <ansi.h>;
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "四海擂");
	set("long", @LONG
这里是四海擂台，玩家可在此依次向本门擂主挑战，争夺 "本门第一" 的
称号。台上告示(gaoshi)分明，各位大侠还是要读一下，以免巫师误会。本擂
客串古龙大侠主持擂务，对于这个酒歌放纵于天外的前辈，大家对他一贯是信
赖有加的。
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east" : __DIR__"wudao",
	]));
        set("objects", ([
                __DIR__"npc/gulong" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
}
string look_gaoshi()
{
	return 
"
1. 本擂台点到为止，只分胜败，不决生死。
2. 本擂台由当值巫师安排各门派顺次比武。原则上在线人数多的门派优先。
3. 在比武中，如果发生非比武门派弟子搅乱擂台，巫师有权以任何必要形式维
   护正常比武顺利进行。
4. 大侠们也应度德量力，因实力过分悬殊去鬼门关旅游将没有路费。
5. 允许使用现行所有武功，允许perform，powerup，enforce，poison 等。
6. 允许使用除金丝甲，软猥甲，真丝宝甲外的所有防具。
7. 不允许使用攻击力超过50的兵器如敖拜匕首，倚天剑，伏魔刀等，但自铸兵
   器不在此限。
8. 违反6.7 条，经核实后除立即取消称号外，追加重罚。
9. 每个门派得出前两名获得者奖品可向天神选取。

                                    四海擂台  敬启\n";
}
void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");
	add_action("do_quit","practice");
	add_action("do_quit","lian");
	add_action("do_quit","study");
	add_action("do_quit","du");
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"，专心看比武吧！\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	object obj;
	if (objectp(obj = present("gu long", environment(me))))
		if (obj->query("candidate")->query("id") == me->query("id"))
		return notify_fail("古龙拦住你说：你是候选人，岂有逃席之理。\n");

        return ::valid_leave(me, dir);
}
