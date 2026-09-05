// bao.c 鲍大楚
//by bing
#include "riyuenpc.h"
#include "riyuenpc2.h"
#include <title.h>
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask();
void do_answer(string);
void create()
{
        set_name("鲍大楚", ({ "bao dachu", "bao" }));
        set("title",GRN "日月神教" NOR + HIR "朱雀堂" NOR + YEL "堂主" NOR);
		set("start_room","/d/riyuejiao/zhuquetang");
        set("long","他身材瘦削，脸色阴沉，乃是日月神教朱雀堂主。\n");
        set("gender", "男性");
        set("age", 58);
        set("attitude","heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set("combat_exp", 50000);
	      set("score",1000);
	      set("drug_count",1);
        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
        set("inquiry", ([
      "东方不败" : (: ask_df :),
      "东方教主" : (: ask_df :),
      "圣药" : (: ask :),
	    "三尸脑神丹" : (: ask :),
	    "任我行" : (: ask_ren :),
	    "任教主" : (: ask_ren :),
	    "任盈盈" : "她是任教主的女儿，一般不住在黑木崖上，圣教主对她很尊重。",
       ]) );

        set_skill("force", 50);
        set_skill("riyue-shengong", 40);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("ryingzhua-gong", 40);
	      set_skill("sword",50);
	      set_skill("riyue-jian",50);
        set_skill("feitian-shenfa", 40);
        set_skill("claw", 50);
        set_skill("literate",40);
	      set_skill("flatter",50);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "riyue-jian");
        map_skill("dodge", "feitian-shenfa");
        map_skill("claw", "ryingzhua-gong");
        map_skill("sword","riyue-jian");
        prepare_skill("claw", "ryingzhua-gong");
        create_family("日月神教", 21, "弟子");
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
        if ( ((int)ob->query("score") < -100 || (int)ob->query("shen") >1000 )
		&& ((fam = ob->query("family")) && fam["master_id"] == "bao dachu"))
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

	if (ob->query("betrayer")>3)
	{
	   command("say 本教最忌欺师灭祖之事，你多次判师，我怎么还能收你？");
	   return;
	}


        if ((int)ob->query("family/generation") == 20 && ob->query("family/family_name") == "日月神教")
	{
	   command("say 您开什么玩笑？有圣教主作您师傅还不够吗？");
	   return;
	}
    if( !ob->query("family")&&ob->query("combat_exp")>5000&&!ob->query("reborn/chushi"))  
	{
		command ("say 你的年纪太大了，在神教也不会有很好的发展！\n");
		return;
	}
	if ((int)ob->query("shen") > 0)
	{
	   command("say 我最痛恨那些所谓正教中的伪君子，" + RANK_D->query_respect(ob) + "若是能杀他几个，我一定收你。\n");
	   return;
	}
	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
	{
       		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
	return;		
	}	
        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
        command("recruit "+ob->query("id"));

}


void do_answer(string arg)
{
	object me=this_player();
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        	command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
        	command("say 好吧，"+RANK_D->query_respect(me)+"，我就收下你了！");
		me->set("mud_age",me->query("lingjiu/mud_age"));
		me->set("age",14+me->query("mud_age")/3600/24);
		me->delete("lingjiu/skill_status");
		me->delete("lingjiu/qi");
		me->delete("lingjiu/eff_qi");
		me->delete("lingjiu/max_qi");
		me->delete("lingjiu/jing");
		me->delete("lingjiu/eff_jing");
		me->delete("lingjiu/max_jing");
		me->delete("lingjiu/jingli");
		me->delete("lingjiu/neili");
		me->delete("lingjiu/max_jingli");
		me->delete("lingjiu/max_neili");
		me->delete("lingjiu/combat_exp");
		me->delete("lingjiu/need_xiulian");
		me->delete("lingjiu/mud_age");
		me->delete("lingjiu/xiulian");
		me->delete("lingjiu/last_xiulian_time");
	        command("recruit "+me->query("id"));
	}
return;
}

void recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
  {
	  if((string)ob->query("gender")=="女性")
		  ob->set("title",MAG "日月神教" NOR + HIR +"女教众" NOR);
	  else
		  ob->set("title",MAG "日月神教" NOR + HIG +"教众" NOR);
//title系统记录玩家title by seagate@pkuxkx
	  ob->set_title(TITLE_RANK, ob->query("title"));
	}
}

string ask()
{
	object me,drug;
	int age;
	mapping fam;
	me = this_player();
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教" )
                return RANK_D->query_respect(me) +
                "与本教素无来往，不知此话从何谈起？\n";
	age = (int)me->query("age");
	if ((me->query("riyue_drug") == 999) || ( me->query("riyue_drug") < age))
	{
		if (me->query("score") < (age - 14)*100)
		{
			return RANK_D->query_respect(me) + "对本教贡献不够，不能够得到今年的解药。\n";
		}
		else if ( query("drug_count") == 1)
			{
				drug = new("/d/riyuejiao/obj/naoshendan");
				drug->move(me);
				set("drug_count",0);
				return "恭喜" + RANK_D->query_respect(me) + "！这是本教圣药，速速服下吧！\n";
			}
			else {  return "对不起，今天的圣药已经给别人了，你过会儿再来吧！\n";   }
	}
	else  { return RANK_D->query_respect(me) + "还没到服下一颗圣药的时候，等到明年生日再来吧！\n"; }
}
