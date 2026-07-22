// Room: /d/mr/houting.c
// this is made by beyond
// last update 1997/JULY/5
// Lklv Modify at 2001.9.20

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"后厅"NOR);
	set("long", @LONG
朱栏宝槛，曲砌峰山。奇花与丽日争妍，翠竹共青天斗碧。径铺彩石，径
这里是慕容家里商议事情的地方，不是慕容弟子最好不要到这里来。在后堂正
中摆放着一个香案，上面摆放着一个灵位牌子（paizi)，在正中墙上挂着一幅
百鸟朝奉图，边墙上挂着一口宝剑。东西两面各是一间厢房，南面是内堂。
LONG
    );
	set("item_desc",([
		"paizi" : "慕容世代祖先灵位\n",
		"sword" : "那是一口玲珑般的宝剑，透着碧玉色。\n",
		"baojian" : "那是一口玲珑般的宝剑，透着碧玉色。\n",
		"jian" : "那是一口玲珑般的宝剑，透着碧玉色。\n",
	]));

	set("exits",([
		"east" : __DIR__"xiangfang2",
		"west" : __DIR__"xiangfang3",
		"south" : __DIR__"neitang",
		"north" : __DIR__"dating",
	]));

	setup();
}

void init()
{
        add_action("do_ketou", "ketou");
        add_action("do_ketou", "拜祭");
}

int do_ketou()
{
        object me,ob,obj;

        me = this_player();
        ob = this_object();

	if (me->query("family/family_name") != "姑苏慕容")
		return notify_fail("你对着灵牌磕了几个响头，对慕容家的祖先表示了敬意。\n");
        if ( !present("yu xi",me) ) return 0;
        if ( me->query_temp("慕容/ketou") == 2 ) {
		obj=unew(BINGQI_D("sword/biyu-jian"));
        if(!clonep(obj) || (int)me->query("combat_exp", 1) < 50000)
		return notify_fail("你磕了半天头，结果什么也没有发生。\n");
        obj->move(ob);
        message("vision","只听见铛的一声，灵牌里掉下一把寒光闪闪的宝剑。\n",me);
        destruct(present("yu xi",me));
        me->delete_temp("慕容/ketou");
        return 1;
	}
	else {
		me->add_temp("慕容/ketou", 1);
		message_vision("$N恭恭敬敬地在灵牌前磕了个响头。\n", me);
		return 1;
        }
}
