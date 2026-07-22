// Room: /u/xdd/gumu/guoyuan.c
// Modify by river 98/08/29
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIG"果园"NOR);
	set("long", @LONG
转过山腰，出现一大片果林。一棵棵果树长得高大茂盛，枝叶繁密，累累
鲜果(guo)，鲜嫩诱人。清风拂叶，沙沙作响，更令这群果随风招摇起舞，送
来阵阵果香，看来你可以大大的饱餐一顿了。但听见密林深处，杜鹃鸟间或轻
啼。林子边上从地底下涌出一汪清泉(quan)。
LONG        );

	set("outdoors","古墓");
	set("resource/water", 1);
	set("drink_msg", HIC"$N捧起一汪清泉，美美地喝了一口。\n"NOR);
	set("exits", ([
		"south" : __DIR__"rukou",
		"north" : __DIR__"guolin1",
		"eastup" : __DIR__"shanpo",
		"west" : __DIR__"guolin5",
	]));

	set("item_desc", ([
		"guo" : "累累鲜果挂在枝头，好象可以采（cai）下来。\n",
		"quan" : "一洌清泉清澈见底，你忍不住想去喝（he）几口。\n",
	]));
    
	setup();
}

void init()
{
	add_action("do_cai", "cai");
	add_action("do_he", "he");
	add_action("do_zhao","zhao");
}

int do_cai(string arg)
{
	object me = this_player();
	object food;
	if (arg == "guo"){
		if(objectp(present("ye guo", me)))
			return notify_fail("你不是已经有了？吃完了再采吧。\n");   
		food = new(__DIR__"obj/guo");
		message_vision(YEL"$N伸手从树上摘下一个$n。\n"NOR, me,food);
		food->move(me);
		return 1;
	}
	return notify_fail("你要采什么? \n");
}

int do_he(string arg)
{
	object me = this_player();
	if (arg == "quan"){
		if (me->query("water") < me->query("str")*10 ){
			message_vision(HIC"$N捧起一汪清泉，美美地喝了一口。\n"NOR, me);
			me->add("water", 40, me);
			return 1;
		}
		return notify_fail("你喝太多了，不怕撑死？\n");  
	} 
	return notify_fail("你要喝什么？\n");
}

int do_zhao(string arg)
{
	mapping fam;
	object me = this_player();

	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");                      

	if (arg == "quan"){   
		if (me->query("gender") != "女性")
			return notify_fail("你又不是女人，对着自己的倒影有什么多看的。\n");
		if ((int)me->query_skill("cuff", 1) < 10)
			return notify_fail("你对着泉水招首弄姿地看了半天，有点孤芳自赏的感觉。\n"); 
		if (me->query_skill("meinu-quanfa", 1) >= 1)
			return notify_fail("你已经学会美女拳法，自己好好练吧。\n");      
		write("你摹仿自己水中的倒影，心中有所体会。\n");
		me->receive_damage("jing", 15);
		me->improve_skill("meinu-quanfa", 2);
		return 1;
	}
	return 0;
}
