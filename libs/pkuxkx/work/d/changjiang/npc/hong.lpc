// sample master.c code
// xiake island master.c
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
#include "/d/menggu/shediao_bonus.h"
void create()
{
        set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
        set("nickname", GRN "九指神丐" NOR);
        set("title",MAG "丐帮" NOR + YEL "第十七代" NOR+ MAG "掌门" NOR);
        set("gender", "男性");
        set("age", 75);
        set("long", "他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
        set("attitude", "peaceful");
        
        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 24);
        set("leiting", 1);
        set("chat_chance", 2);
        set("chat_msg", ({
                "洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来这里看看。”\n",
                "洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
        }));
		set("uni_target",1);
		
        set("qi", 15000);
        set("max_qi", 15000);
        set("per", 38);
        set("jing", 13000);
        set("max_jing", 13000);
        set("neili", 16000);
        set("max_neili", 16000);
        set("jiali", 450);
        set("no_nuoyi",1);
        
        set("combat_exp",15000000);
        set("score", 200000);
        set_skill("force", 400);             // 基本内功
        set_skill("huntian-qigong", 380);    // 混天气功
        set_skill("parry",350);
        set_skill("hand",380);
        set_skill("strike", 350);
        set_skill("liuhe-dao", 400);   // 六合刀
        set_skill("blade", 400);   // 基本刀法
        set_skill("xianglong-zhang", 400);   // 降龙十八掌
        set_skill("shexing-shou",430);
        set_skill("dodge", 350);             // 基本躲闪

        set_skill("xiaoyaoyou", 350);        // 逍遥游
        set_skill("staff", 350);             // 基本棍杖
        set_skill("dagou-bang", 350);        // 打狗棒法
        set_skill("checking", 300);          // 道听途说
        set_skill("begging", 250);
          // 道听途说
        set_skill("stealing", 150);
          // 道听途说
        
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("staff", "dagou-bang");

        prepare_skill("strike", "xianglong-zhang");
		set_temp("apply/armor", 600);
		set_temp("apply/damage", 450);
        create_family("丐帮", 17, "帮主");
        set("shen_type",1);set("score",100000);setup();
		carry_object("/d/gaibang/obj/cloth")->wear();
   
}
void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="丐帮")
        {
                command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob)+ "先要从一袋弟子做起。");
                return;
        }
        if ((int)ob->query("score")<1500){
            command("shake"+ob->query("id"));
            command("say 小兄弟如能为本帮立下点功劳,我一定收你.");
            return;
             }         
        if (ob->query("dai")<9)
        {
                command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
        if (ob->query("dai")== 9 )
        {
        if ((int)ob->query_str() < 30 || (int)ob->query_con() < 20) {
                command("say 当叫化子需要能吃苦耐劳，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当叫化子？");
                return;
        }
        if (!ob->query("gaibangnewbiejobdone_2")&&!ob->query("gaibangnewbiejobdone"))
        {
            command("say 你对我派贡献还不够，多去帮帮彭、鲁两位长老吧。");
            return;
        }
//      if ((string)ob->query("family/family_name") != "" &&
//          (string)ob->query("family/family_name") != "丐帮") {
//              command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老叫化呢？");
//              return;
//      }
        //command("say " + RANK_D->query_respect(ob) + "各项条件都不错，只可惜老叫化现在没力气收徒……");
        command("recruit " + ob->query("id"));
        this_player()->set("title",MAG "丐帮" NOR + YEL +"九袋" NOR + MAG "长老" NOR);
//title系统记录玩家title by seagate@pkuxkx
	    ob->set_title(TITLE_RANK, ob->query("title"));
}

}
int dest(object ob)
{
	if (ob)
	{
		destruct(ob);
	}
	return 1;
}
int leave(object hong)
{
	if (hong)
	{
		message_vision(HIR"$N哈哈一笑，飘然离开。\n"NOR,this_object());
		destruct(this_object());
	}
	return 1;
}
int shediao_bonus(object me)
{
	int e_reward=0;
	me->delete_temp("shediaoquest");
	me->set("shediaoquest/kanglong/finish",1);
	if (me->query("family/family_name")=="丐帮")
	{
		command("say 我就指点你几招吧。");
		message_vision(HIC"$N开始悉心指点$n降龙十八掌的运用技巧。\n"NOR,this_object(),me);
		tell_object(me,HIC"完成射雕主线任务【亢龙有悔】，你被洪七公指点了降龙十八掌的精髓。\n"NOR);
	}
	else
	{
		e_reward=bonus(me,4500);
		me->add("combat_exp",e_reward);
		tell_object(me,HIC"完成射雕主线任务【亢龙有悔】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
	}
	return 1;
}
int accept_object(object me, object ob)
{
	if (me->query_temp("shediaoquest/kanglong/start")!=16)
		return notify_fail(this_object()->query("name")+"不想要"+ob->query("name")+"。\n");
	if (ob->query("id")!="jiaohua ji")
		return notify_fail(this_object()->query("name")+"不想要"+ob->query("name")+"。\n");
	if (!ob->query("is__jiaohuaji"))
		return notify_fail(this_object()->query("name")+"不想要"+ob->query("name")+"。\n");
	message_vision("$N道：“妙极，妙极，连我叫化祖宗，也整治不出这般了不起的叫化鸡。”\n",this_object());
	call_out("dest",1,ob);
	call_out("leave",20+random(10),this_object());
	if (me->query("shediaoquest/kanglong/finish"))
	{
		return 1;
	}
	shediao_bonus(me);
	return 1;
}
