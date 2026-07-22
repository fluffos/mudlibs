// NPC: /d/gb/npc/jydizi.c 接引弟子

#include <ansi.h>
#include <combat.h>
inherit NPC;
string ask_for_test();
void create()
{
	set_name("接引弟子", ({"jieyin dizi", "jieyin", "dizi"}));
	set("long",
		"他是一位体格强健的壮汉，他身材魁梧，虎背熊腰，一看便知有\n"
		"着一身好武艺。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");

	set("inquiry",([
		"入帮"	: (: ask_for_test :),
		"考验"	: (: ask_for_test :),
	]));

	set("age", 20);
	set("shen_type", 1);
	set("str", 30);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_qi", 500);
	set("max_jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 40);
	set_skill("huntian-qigong", 40);
	set_skill("dodge", 50);
	set_skill("xiaoyaoyou", 50);
	set_skill("hand", 90);
	set_skill("suohou-shou", 90);
	set_skill("parry", 30);
        set_skill("liuhe-daofa",70);
        set_skill("blade",70);

	map_skill("force", "huntian-qigong");
        map_skill("blade","liuhe-daofa");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("hand", "suohou-shou");
	map_skill("parry", "liuhe-daofa");
	prepare_skill("hand", "suohou-shou");

	set("startroom","/d/gb/fenduo2");
	set("chat_chance", 3);
	set("chat_msg", ({
		"接引弟子说道: 我们要广招天下英雄，光大丐帮。\n",
		"接引弟子用手轻轻的抚摩着刀锋。\n",
		"接引弟子说道：江湖上奇人异士入我丐帮，都要先让我来考验。 \n",
	}) );
  	create_family("丐帮", 19, "弟子");
	setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object(CLASS_D("gaibang/obj/gb_budai3"))->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
void init()
{
	add_action("do_test", "test");
}

string ask_for_test()
{
	object me = this_player();

        if (me->query("gb_pass"))
		return "你已经是丐帮帮众了，可别跟我开这等玩笑。\n";
	me->set_temp("pending/join_gb", 1);
	return "为丐帮效力需要有一定的功夫，你若愿意可以让我考验一番。(test)\n";
}

int do_test()
{
	int i;
	object me = this_player();

	if( !me->query_temp("pending/join_gb") )
		return 0;
	if (!living(this_object())) return 0;
	message_vision(
		"$N躬身一揖，恭恭敬敬的道：“请指教。”\n\n"
		"$n双手抱拳朗声说道：“请”。\n\n",
		me, this_object() );
	for (i=0;i<6;i++){
		if (interactive(me) && me->query_temp("pending/join_gb") && living(me))
			COMBAT_D->do_attack(this_object(), me, query_temp("weapon"), 1);
		if((!living(me))||((int)me->query("qi")<(int)me->query("max_qi")/4))
			return notify_fail("真是可惜呀，看来你还要多多努力。\n");
	}
	command("smile");
	command("say 恭喜，恭喜，从今以后你就是丐帮的帮众了。\n");
	command("say 你可以向丐帮的吴长老申请为丐帮工作。(ask wu about job)\n");
	me->delete_temp("pending/join_gb");
	me->set("gb_pass",1);
	return 1;
}