// ding.c 丁春秋
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("丁春秋", ({ "ding chunqiu", "ding" }));
	set("nickname", "星宿老怪");
	set("long", 
		"他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。\n"
		"可是他看起来形貌清奇，仙风道骨。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("shen", -150000);
	set("str", 65);
	set("int", 60);
	set("con", 68);
	set("dex", 68);
	set("per", 68);
	
	set("max_qi", 39000);
	set("max_jing", 39000);
	set("neili", 54000);
	set("max_neili", 54000);
	set("max_neili", 54000);
	set("jiali", 100);
	set("combat_exp", 8500000);
	set("score", 400000);

	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("huagong-dafa", 380);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 380);
	set_skill("dodge", 250);
	set_skill("zhaixinggong", 380);
	set_skill("strike", 250);
	set_skill("chousui-zhang", 380);
	set_skill("claw", 350);
	set_skill("sanyin-wugongzhao", 380);
	set_skill("parry", 200);
	set_skill("staff", 300);
	set_skill("poison", 380);
	set_skill("tianshan-zhang", 380);
	set_skill("chanhun-suo", 380);
	set_skill("whip", 380);
	set_skill("literate", 150);
set_skill("blade", 250);
set_skill("xuantian-strike", 380);
set_skill("bingpo-blade", 380);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
(: perform_action, "whip.duo" :),
(: perform_action, "whip.huixuan" :),
(: perform_action, "whip.suo" :),
         }) );
	set("book_count", 1);
	set("zhen_count", 8);
	set("san_count", 3);
	set("wx_count", 6);
	set("xcs_count", 4);


        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);


	create_family("星宿派", 1, "开山祖师");
	set("class", "taoist");

	setup();
      carry_object("/kungfu/class/xingxiu/chanhunsuo")->wield();
      carry_object("/clone/misc/cloth")->wield();
}


void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
who->set_temp("killtlbb82",1);
	::die();
}

void init()
{
        remove_call_out("leave");
        call_out("leave",120);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}