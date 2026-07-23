// dabaiyuan.c
// By jpei

inherit NPC;

int do_cut(string arg);

void create()
{
        set_name("大白猿", ({ "da baiyuan", "da", "baiyuan", "yuan" }) );
        set("race", "野兽");
        set("age", 54);
        set("long", "一只浑身长着白毛的老猿，肚上脓血模糊，生着一个大疮。\n仔细检查才发现，它肚子上的突起是被人用针线缝了什么进去，看来需要割开缝过之处才行。\n");

        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 1000);
    
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
	if (clonep()) call_out("disappear", 120);
}

void init()
{
	add_action("do_cut", ({"cut", "sever", "ge", "heal", "zhi", "yizhi", "zhiliao"}));
	::init();
}

void disappear()
{
	message_vision("$N等了许久，也没有人救治它，泱泱地去了。\n", this_object());
	destruct(this_object());
}

int do_cut(string arg)
{
	object thread, yaocao;
	object me = this_player();

	if (id(arg)) {
		if (!present("sharp rock", me))
			return notify_fail("可惜你手头没有刀剪。\n");
		if (!present("fish bone", me) || !thread = present("xi si", me))
			return notify_fail("可惜你手头没有针线。\n");
		if (!yaocao = present("yao cao", me))
			return notify_fail("可惜你手头没有草药。\n");
		destruct(thread);
		destruct(yaocao);
		remove_call_out("disappear");
if (!me->query("jiuyangget"))
{
		new("/d/fairyland/obj/jiuyang-zhenjing")->move(me);
		new("/d/fairyland/obj/pantao")->move(me);
		write("你用尖石慢慢割开白猿肚腹上缝补过之处，只见里面竟藏着一个油布包裹，打开一看，是一套经书。\n");
		write("这时你来不及仔细检查，忙揣入怀中。然后用鱼骨做针，树皮撮成的细丝作线，勉强补好了白猿的伤口。\n");
		write("你把草药嚼烂了给它敷在伤处，白猿十分感激你，给了你一个罕见的大蟠桃，然后走了。\n");
                me->set("jiuyangget",1);
                me->set("jiuyangok",1);
 }
      		destruct(this_object());
	}
	return 0;
}
