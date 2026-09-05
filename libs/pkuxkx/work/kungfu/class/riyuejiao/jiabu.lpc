//jiabu.c 贾布
//by bing
//modify by whuan

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <title.h>
#include "riyuenpc.h"
#include "riyuenpc2.h"
string ask_jian();
string ask_dao();
string ask_jieyao();
void create()
{
        set_name("贾布", ({ "jia bu", "jia", "bu" }));
        set("title",GRN "日月神教" NOR + HIR "青龙堂" NOR + HIY "长老" NOR);
        set("long","他一张瘦脸蜡也似黄，两边太阳穴高高喜起，便如藏了一枚核桃相似，
他在教中资历也不甚深，只是近数年教中变迁甚大，他在教中已是
极有权势、极有头脸的第一流人物。他乃是日月神教青龙堂长老。\n");
        set("gender", "男性");
	set("nickname", YEL "黄面尊者" NOR);
        set("age", 41);
        set("attitude","heroism");
        set("shen_type", -1);
	set("shen",-30000);
        set("str", 30);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 1200);
        set("max_jing", 1000);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 100);
        set("combat_exp", 500000);
        set("dao_count",random(2));
        set("jian_count",random(2));
        set("yao_count",1);
	      set("score",2000);
        set("chat_chance", 30);
        set("chat_msg", ({
                (: heal :),
       }));
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.xuanmu" :),
        }) );
        set("inquiry", ([
            "东方不败"   : (: ask_df :),
            "东方教主"   : (: ask_df :),
            "日月神刀"   : (: ask_dao :),
            "日月神剑"   : (: ask_jian :),
            "解药"       : (: ask_jieyao :),	
	          "任我行"     : (: ask_ren :),
	          "任教主"     : (: ask_ren :),
	          "任盈盈"     : "她是任教主的女儿，一般不住在黑木崖上，圣教主对她很尊重。",
	          "圣药"       : "那是圣教主对有功之人的赏赐，吃了以后对教主更加忠心。在风雷堂童堂主处领取。",
	          "三尸脑神丹" : "那是圣教主对有功之人的赏赐，吃了以后对教主更加忠心。在风雷堂童堂主处领取。",
       ]) );

        set_skill("force", 150);
        set_skill("riyue-shengong", 150);
        set_skill("dodge", 180);
        set_skill("parry", 150);
        set_skill("kaishan-zhang", 120);
	set_skill("sword",120);
	set_skill("riyue-jian",120);
        set_skill("feitian-shenfa", 120);
        set_skill("strike", 150);
        set_skill("literate",100);
	set_skill("flatter",120);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "riyue-jian");
        map_skill("dodge", "feitian-shenfa");
        map_skill("strike", "kaishan-zhang");
        map_skill("sword","riyue-jian");
	prepare_skill("strike", "kaishan-zhang");
	create_family("日月神教", 20, "弟子");
        setup();
        carry_object("/d/riyuejiao/obj/heiyi")->wear();
	carry_object("/d/riyuejiao/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
       }
void init()
{
	object ob;
	mapping fam;
        ::init();
	ob = this_player();
	if (interactive(ob) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        if ( ((int)ob->query("score") < 0 || (int)ob->query("shen") >0 )
		&& ((fam = ob->query("family")) && fam["master_id"] == "shangguan yun"))
        {
                command("say 你不去杀那些所谓的正教大侠,反而多次残害同道中人，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }


}

void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("riyue_drug") != 0) && (ob->query("family/family_name") != "日月神教" ))
	{
	   command("say 大胆叛逆，竟敢反出神教，我今天就为教除逆！\n");
	   command("kill "+ob->query("id"));
	   return;
	}

        if ((int)ob->query("family/generation") == 20 && ob->query("family/family_name") == "日月神教")
	{
	   command("say 您开什么玩笑？有圣教主作您师傅还不够吗？");
	   return;
	}

	if (ob->query("family/family_name") != "日月神教")
	{
	   command("say 我们日月神教拜师要从堂主拜起，" + RANK_D->query_respect(ob) + "先去拜堂主吧！\n");
	   return;
	}

	if (ob->query("riyue_drug") == 0)
	{
	   command("say " + RANK_D->query_respect(ob) + "吃了我教的圣药了吗？\n");
	   return;
	}
	
	if (ob->query("riyue_drug") == 999)
	{
	   command("say " + RANK_D->query_respect(ob) + "还没吃今年的圣药，我不能收你。\n");
	}

	if ((int)ob->query("score") < 400)
	{
	   command("say " + RANK_D->query_respect(ob) + "对本教的贡献还不够，我不能收你。\n");
	   return;
	}

	if ((int)ob->query_skill("flatter",1) < 30)
	{
	   command("say " + RANK_D->query_respect(ob) + "还没学会黑木崖上流行的切口，还是先回去好好学习一下吧！\n");
	   return;
	}

	if ((int)ob->query_skill("riyue-shengong",1) < 30)
	{
	   command("say " + RANK_D->query_respect(ob) + "的日月神功好象还没学好，再回去好好学学吧！\n");
	   return;
	}
	
	if ((int)ob->query("shen") > -5000)
	{
	   command("say 我最痛恨那些所谓正教中的伪君子，" + RANK_D->query_respect(ob) + "若是能杀他几个，我一定收你。\n");
	   return;
	}

        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
        command("recruit "+ob->query("id"));

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
	        if((string)ob->query("gender")=="女性")
		      	ob->set("title",MAG "日月神教" NOR + HIR +"女坛主" NOR);
	        else	
	        	ob->set("title",MAG "日月神教" NOR + HIG +"坛主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
	      }
}

string ask_dao()
{	 mapping fam;
        object ob;
         object me=this_player();
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "日月神教")
             return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if((int)me->query("score")<2000)
                return "你对本门的贡献有限，宝刀不能给你。";
        if (me->query_temp("killing") == "jia bu")
              return "你上次打伤了我，还想从我这里要宝物？";
        if (query("dao_count") < 1)
                return "你来晚了，宝刀已经被人拿了。";
        add("dao_count", -1);
        ob = new("/d/riyuejiao/obj/riyuedao");
        ob->move(this_player());
        return "好吧，这把宝刀你拿回去好好保管。";
}

string ask_jian()
{	 mapping fam;
        object ob;
         object me=this_player();
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "日月神教")
             return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if((int)me->query("score")<2000)
                return "你对本门的贡献有限，宝剑不能给你。";
        if (me->query_temp("killing") == "jia bu")
              return "你上次打伤了我，还想从我这里要宝物？";
        if (query("jian_count") < 1)
                return "你来晚了，宝剑已经被人拿了。";
        add("jian_count", -1);
        ob = new("/d/riyuejiao/obj/riyuejian");
        ob->move(this_player());
        return "好吧，这把宝剑你拿回去好好保管。";
}

string ask_jieyao()
{	 mapping fam;
        object ob;
         object me=this_player();
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "日月神教")
             return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if((int)me->query("score")<2000)
                return "你对本门的贡献有限，解药不能给你。";
        if ( !me->query("riyue_drug"))
        	      return "你的神丹之毒不是已经解了么？";
        if (query("yao_count") < 1)
                return "你来晚了，解药已经被人拿了。";
        add("yao_count", -1);
        me->add("score",-50);
        ob = new("/d/riyuejiao/obj/jieyao");
        ob->move(this_player());
        return RANK_D->query_respect(this_player())+"对本派贡献非小，这颗解药能解除你的神丹之毒。";
}
