// longwang.c 龙王殿
// Modify By River@SJ 99.06

#include <ansi.h>
#include <wanted.h>
inherit ROOM;
void create()
{
       set("short",MAG"龙王殿"NOR);
       set("long", @LONG
这里是专为“紫衫龙王”黛绮丝建造的行殿，也是张无忌教主为召集明教
首领宣示行善去恶、除暴安良的教旨之处。这里摆有一张香案，长年都有香束
燃着，幽香熏得你头脑晕晕的。
LONG);
	set("exits", ([
		"east" : __DIR__"jyt",
		"west" : __DIR__"tuqi",
                "northwest" : __DIR__"yuanzi",
	]));

        set("objects",([
		__DIR__"npc/f-dizi" : 1,
                __DIR__"npc/m-dizi" : 1,
                CLASS_D("mingjiao") + "/yang" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	mapping myfam;

	myfam = (mapping)me->query("family");
	ob = present("yang xiao", environment(me));

	if (dir == "northwest" && is_wanted(me))
		return 0;
	if (dir == "northwest" && (!ob || !living(ob)) && !wizardp(me))
		return notify_fail(YEL"\n突然一个声音在你耳边响起：擅闯杨左使女儿的闺房者杀！\n\n"NOR);
	if (dir == "northwest" && !myfam && ob && !wizardp(me))
		return notify_fail("杨逍把手一伸拦住你的去路：擅闯我女儿的闺房者杀！\n");
	if ((!myfam || myfam["master_name"] != "张无忌" || !me->query_temp("mj_jiaozhu"))
	 && dir == "northwest"
	 && objectp(ob)
	 && !wizardp(me))
		return notify_fail(YEL"\n杨逍把手一伸拦住你的去路：里面是我女儿的闺房，不准擅自进入！\n\n"NOR);
	return ::valid_leave(me, dir);
}
