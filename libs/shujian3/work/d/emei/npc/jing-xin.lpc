// /kungfu/class/emei/jing-xin.c
// Update by Lklv 2001.10.18
// lane 2004.12.24 add 福利

#include "nigu.h"
inherit F_MASTER;
inherit NPC;
int ask_gold();

void create()
{
        set_name("静心师太", ({"jingxin shitai", "jingxin", "shitai"}));
        set("long", "她是在华藏庵修行的师太，常见在侧殿里与年轻峨嵋弟子讨论问题。\n");

        set("gender", "女性");
        set("attitude", "friendly");
	set("unique", 1);
        set("class", "bonze");

        set("age", 45);
	set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 500000);
        set("score", 100);
	set("inquiry",([
                "剃度"  : (: ask_for_join :),
                "出家"  : (: ask_for_join :),
		"铲除魔教" : (: ask_gold :),

        ]));
	set_skill("dacheng-fofa", 130);
	set_skill("linji-zhuang", 130);
	set_skill("huifeng-jian", 130);
	set_skill("literate", 130);
	set_skill("sword", 130);
	set_skill("parry", 130);
	set_skill("dodge", 130);
	set_skill("force", 130);
	set_skill("anying-fuxiang", 130);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");

        create_family("峨嵋派", 4, "弟子");

        setup();
	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();

}

int ask_gold()
{
	object me;
	int skill, gold;
	mapping myfam;
	me = this_player();
	skill = me->query_skill("linji-zhuang", 1);
	myfam = (mapping)me->query("family");

	if( !myfam || myfam["family_name"] != "峨嵋派" ) {
		command("wa2 "+(string)me->query("id"));
		command("say "+ RANK_D->query_respect(me) +"有这种想法真是太好了!");
		return 1;
	}

	if( (int)me->query("emei_given") >= (int)me->query("age") ) {
		command("innocent");
		command("say 不是你说要去铲除魔教的吗？");
		return 1;
	}

	if( skill < 120 ) {
		command("joke "+(string)me->query("id"));
		command("say "+ RANK_D->query_respect(me) +"年纪还轻，还是安心学好武功吧。\n");
		return 1;
	}

	gold = 200000 + skill * 3000;
	if( 100 >= skill ) gold += gold/2;
	me->add("balance", gold);
	me->set("emei_given", (int)me->query("age"));
	command("say 你有这种想法真是太好了，可惜现在魔教日益壮大，铲除魔教恐怕不是这么容易吧！");
	command("say 我将这" + MONEY_D->money_str(gold) + "存入你的钱庄，你就下峨嵋山巡视下吧，如遇魔教恶徒切不可手软啊！");
	return 1;
}