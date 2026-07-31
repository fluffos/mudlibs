#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "琼崖下");
	set("long", @LONG
转过山脚,前面的沙滩与山壁逐渐融合在一起,消失在波涛汹涌的海
水中,海涛裂岸,发出轰轰隆隆的巨响.前面已是无路可通了.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"underhill2",
]));
	set("objects",([
		__DIR__"npc/man4":1,
	]));
	setup();
}
void init()
{
        add_action("do_break","break");
}
int do_break(string arg)
{
        object me;
        me = this_player();
        if (arg != "山壁" ) return 0;
        if (me->query("max_neili") < 5000 || me->query("str") < 15)
                return notify_fail(HIR"你对着山壁猛拍了几掌,结果什么反映都没有..\n"NOR);
        if (me->query_skill("dodge") < 150 )
                return notify_fail(HIR"你对着山壁猛拍了几掌,结果山上掉下了一堆碎石头,给你砸了个狗血喷头..\n"NOR);
                me->add("eff_qi",-100);
        message_vision("$N对着山壁猛拍了几掌,结果无意中大开了一个很隐秘的山洞.\n",me);
        me->add("qi",-100);
        me->start_busy(2);
        set("exits/enter", __DIR__"dong");
        return 1;
}
