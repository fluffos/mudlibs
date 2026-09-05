#include <ansi.h>
// yu.c 俞岱岩
#include <title.h>
inherit NPC;
inherit F_MASTER;

void heal();
string ask_dan();

void create()
{
        set_name("俞岱岩", ({ "yu daiyan", "yu" }));
       set("nickname", RED "武当三侠" NOR);
        set("long",
                "他就是武当七侠中的俞岱岩。\n"
                "自从他遭奸人毒手后，武功远不如前，但由此潜心道学，倒也颇有小成。\n");
        set("title",RED "武当派" NOR + GRN +"真人" NOR);
        set("gender", "男性");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 400000);
        set("score", 150000);

        set_skill("force", 120);
        set_skill("taiji-shengong", 120);
        set_skill("dodge", 60);
        set_skill("tiyunzong", 60);
        set_skill("cuff", 100);
        set_skill("taiji-quan", 100);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("taiji-jian", 120);
        set_skill("taoism", 150);
        set_skill("literate", 120);
        set_skill("medical-skill", 150);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "弟子");
        set("inquiry",([
                "炼丹" : (:ask_dan:),
                ]));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="武当派" || (string)ob->query("class")!="taoist") {
                command("say 我武当乃是道家门派。");
                command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜我徒侄谷虚。"); 
                return;
        }
	if ((int)ob->query("shen") < 10000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，我一定收你。");
                return;
        }
        command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
                "我辈中人，今天就收下你吧。");
        command("recruit " + ob->query("id"));
		if ((string)ob->query("gender")!="女性")
			ob->set("title" ,RED "武当派" NOR + GRN "道长" NOR);
		else
      ob->set("title" ,RED "武当派" NOR + GRN "女道长" NOR);
//title系统记录玩家title by seagate@pkuxkx
	  ob->set_title(TITLE_RANK, ob->query("title"));
}

void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <1000 && (string)ob->query("family/master_id") == "yu daiyan")
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
}		

void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 50");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");

	return;
}

int prevent_learn(object me, string skill)
{
	if(skill=="medical-skill") {
		write("医术乃是我多年炼丹所得，岂能轻易教你？\n");
		return 1;
	}
	else 
		return ::prevent_learn(me,skill);
}

string ask_dan()
{
	object me;
	me=this_player();
	
	if(me->query_temp("quest_liandan/shou_fail"))
		return "这点小事也办不好！回去向"+me->query_temp("quest_liandan/promoter")+"领罚吧！\n";
	else if(me->query_temp("quest_liandan/shou_success")) {
		me->set_temp("quest_liandan/success",1);
		me->delete_temp("quest_liandan/shou_success");
		me->delete_temp("quest_liandan/start");
		me->delete_temp("quest_liandan/allow_show");
		if(me->query_skill("medical-skill",1)<100)
			me->improve_skill("medical-skill",1000);
		return "不错不错！看来"+RANK_D->query_respect(me)+"也对炼丹很有心得！快回去向"+me->query_temp("quest_liandan/promoter")+"报告炼丹情况吧。\n";
	}
	else if(me->query_temp("quest_liandan/start")) {
		me->set_temp("quest_liandan/allow_shou",1);
		return "我最近正在研究炼制炼制黑玉断续膏，稍微有点心得，配了一炉丹药试试效果，你过去帮我看看(kan)炉火。\n注意时刻关注丹炉(lu)的火候，随时进行调整！\n";
	}
	else
		return "炼丹最注重火候了，必须时时刻刻盯着炼丹炉，稍有变化就要立刻对炉火进行调整。";
}