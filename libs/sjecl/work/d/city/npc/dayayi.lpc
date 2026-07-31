// yayi.c  官府衙役

inherit NPC;
void create()
{
        object ob;
        set_name("大衙役", ({ "da yayi", "yayi", "dayayi", "ya yi" }));
        set("gender", "男性");
        set("age", 30);

        set("long", "一个高大威猛的汉子，因为久在官府做事，脸上已经磨炼得毫无表情。\n");
        set("combat_exp", 800000);
        set("max_neili",2000);
        set("max_qi",1500);
        set("eff_jingli",1000);
        set("max_jing",1000);
        set("neili",2000);
        set("qi",1500);
        set("jingli",1000);
        set("jing",1000);
        set("shen_type", 1);

        set_skill("stick", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set("chat_chance", 2);
        set("inquiry", ([
		"工作" : "那还不简单？你只要有胆量把文书揭下来(jie wenshu)，然后把目标杀了就可以。",
	]));
	set("chat_msg", ({
		"大衙役小声嘀咕道：“常听人说武林之中藏龙卧虎，也不知道是真是假？”\n",
		"大衙役朗声说道：“各路英雄，本城目前悬赏捉拿江洋大盗，望各位能协助官府，惩治凶徒。”\n",
	}));
	setup();
	carry_object("/d/city/npc/obj/yayifu")->wear();
	if(clonep()) {
		ob = unew(BINGQI_D("shawei-bang"));
		if(ob) {
		ob->move(this_object());
		ob->wield();
		}
	}
}
