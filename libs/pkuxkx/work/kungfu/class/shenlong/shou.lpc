// shou.c
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("瘦头陀", ({ "shou toutuo", "shou" ,"toutuo"}));
        set("title", MAG"神龙教"+HIB"右护法"NOR);
	set("nickname",HIR "辽东瘦尊者" NOR);
	set("long", "这头陀身材奇矮, 而且胖得出奇, 整个人就活脱脱是一个大冬瓜.\n光溜溜的脑袋上瞪着一对铜铃大眼, 样子非常滑稽.\n" );
	set("gender", "男性");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi",2000);
        set("qi",2000);
	set("max_jing",1000);
        set("jing",1000);
	set("combat_exp", 400000);
	set("score", 30000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("poison", 80);
        set_skill("force", 80);
        set_skill("flatter", 80);
        set_skill("strike", 80);
        set_skill("whip", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("yixingbu", 80);
        set_skill("shenlong-bian", 80);
        set_skill("huagu-mianzhang", 80);
        set_skill("shenlong-xinfa", 80);
        set_skill("literate", 80);
        map_skill("dodge", "yixingbu");
        map_skill("force", "shenlong-xinfa");
        map_skill("strike", "huagu-mianzhang");
        map_skill("parry", "shenlong-bian");
        map_skill("dodge", "yixingbu");
        map_skill("whip", "shenlong-bian");
        prepare_skill("strike", "huagu-mianzhang");
	create_family("神龙教",2,"弟子");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 50);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
        set("inquiry", ([
		"神龙教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "教主脾气不好,要讨他欢心才好。\n",
		"口号" : "万年不老!永享仙福!寿与天齐!文武仁圣!\n",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changbian")->wield();
	add_money("silver", 30);
}

void init()
{
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
        if (ob->query("party/party_name") != MAG "神龙教" NOR ) {
		command("say 你不是本教教众, 想来找死啊!");
		return;
	}
        if (ob->query("family/master_name") == "洪安通" || ob->query("family/master_id")=="hong antong") {
                command("say 不敢！有教主做您师傅还不够吗？");
                return;
        }
	if ((int)ob->query("shen") > 0  ) {
		command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
	ob->set("title",ob->query("party/party_name")+ob->query("party/rank"));
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
        command("say 岛上神龙众多，你赶快去问沐姑娘讨一杯雄黄酒吧。");
}
#include "/kungfu/class/shenlong/shenlong.h"; 
