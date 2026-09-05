// benyin.c 本因方丈
// by paladin


#include <ansi.h>
#include <title.h>
#include "/kungfu/class/tianlong/tianlong.h"
inherit NPC;
inherit F_MASTER;

#include <no1master.h>

void do_answer(string);
string ask_for_leave();

void create()
{

        set_name("本因方丈", ({ "benyin fangzhang", "benyin" }));
        set("long",
                "他就是本因方丈。\n"
                "他是枯荣大师的师侄。本观、本参、本相、本尘的师兄，精通商阳剑。\n");
        set("title",RED "天龙寺" NOR + GRN +"方丈" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 30);
        set("chat_chance_combat", 100);

        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 60);
        set("combat_exp", 200000);
        set("score", 8000);

        set_skill("force", 80);
        set_skill("sword", 60);
        set_skill("duanjia-jian", 60);
        set_skill("dodge", 80);
        set_skill("duanshi-shenfa", 60);
        set_skill("finger", 80);
        set_skill("parry", 90);
        set_skill("kurong-shengong", 80);
        set_skill("literate", 50);
        set_skill("yiyang-zhi", 85);

        map_skill("force", "kurong-shengong");
        map_skill("dodge", "duanshi-shenfa");
        map_skill("finger", "yiyang-zhi");
        map_skill("parry", "yiyang-zhi");
        map_skill("sword", "duanjia-jian");

	      set("inquiry",([
      		"还俗"  : (: ask_for_leave :),
	      ]));

        prepare_skill("finger","yiyang-zhi");
        create_family("天龙寺", 15, "掌门");
        set("class", "bonze");

        setup();
		setup_no1master();
}


void init()
{
        mapping fam;
        object ob;
        ::init();
        ob=this_player();
        if((int)ob->query("PKS")>=10&&(string)ob->query("family/master_id")=="benyin")
        {
        command("say 你多次残害黎民百姓,邪气太重,我怎可容你.\n");
        command ("expell "+ob->query("id"));
        return;
        }
        add_action("do_decide", "decide");
}

string ask_for_leave()
{
	object me;

	me = this_player();

	if( (string)me->query("class")!="monk" )
		return "阿弥陀佛！施主并未出家，何故跟贫僧开这等玩笑？";

	if( (string)me->query("family/family_name") != "天龙寺")
		return "阿弥陀佛！施主非我天龙寺弟子，脱离门派的事情贫僧作不得主。";

	me->set_temp("pending/leave_tianlong", 1);
		return "阿弥陀佛！如果" + RANK_D->query_respect(me) + "真想离我佛门而去，就请下决心(decide)吧！";
}

int do_decide()
{
	string* skillname;
	int lev;
	mapping skills;
	int i;
	object me = this_player();
//	object body;
	
	if (me->query_temp("pending/leave_tianlong") != 1)
		return 0;
	message_vision("$N对$n说道：「阿弥陀佛！从此施主就不再是我天龙寺门下了，请好自为之！」\n",this_object(), me);
	tell_object(me,HIR "你决定叛出天龙寺门下！\n" NOR);
	me->delete_temp("pending/leave_tianlong");
	if (me->query("combat_exp") >= 1000)
	{
		if (me->query("family/enter_time")>1344562838)
		{
			me->add("betrayer",1);
		}
	}
	me->expell_family("天龙寺");
	return 1;
}

void attempt_apprentice(object ob)
{
		int index;
        if((int)ob->query("betrayer")>=4)
        {
        command("say 你多次背信弃义，我怎可信你!\n");
        //command("say"+RANK_D->query_respect(ob)+"你多次残害黎民百姓，我怎可容你.\n");
        return;
        }
        if( !ob->query("family")&&ob->query("combat_exp")>5000&&!ob->query("reborn/chushi")&&time()>1307960807)  
	    {   
		    command ("say 本寺不收来路不明的高手。\n");
		    return;
	    }
        if((string)ob->query("gender")!="男性")
        {

        command ("say 本寺只收男弟子，佛门清净地，男女混住，成何体统？\n");
        //command("say"+RANK_D->query_respect(ob)+"你不男不女的，我怎可收你.\n");
        return;
        }

        if((int)ob->query("shen")<0)
        {
        command("say"+RANK_D->query_respect(ob)+"还是请回吧,做几件侠义善事后再来找我吧.\n");
        return;
        }
	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
	{
       		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
	return;		
	}	
        //command("say "+RANK_D->query_respect(ob)+"好吧,贫僧就收下你了!\n");
        if (ob->query("family/family_name")!="天龙寺")
        index=1;
		else
		index=2;
		command("recruit "+ob->query("id"));
        tianlong(ob,index);
		this_player()->set("title",GRN"天龙寺"NOR+RED"第十六代弟子"NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
		  
}
void do_answer(string arg)
{
	object me=this_player();
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        	command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
        	command("say "+RANK_D->query_respect(me)+"好吧,贫僧就收下你了!\n");
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
		me->set("title",GRN"天龙寺"NOR+RED"第十六代弟子"NOR);
//title系统记录玩家title by seagate@pkuxkx
	  me->set_title(TITLE_RANK, me->query("title"));
	}
return;
}
