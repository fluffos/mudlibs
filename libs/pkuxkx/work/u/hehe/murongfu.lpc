//by hehe
//2003.3.13

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_bo();

void create()
{
	set_name("慕容复", ({ "murong fu", "murong","fu" }));
	set("long",
	"他就是有“南慕容”之称的慕容复\n"
    "他看起来三十多岁，风流倜傥，果然名不虚传。\n");
    set("gender", "男性");
    set("age", 30);      
	set("title",RED"姑苏慕容"NOR + HIW"少庄主"NOR);
	set("str", 35);
    set("int", 35);
    set("con", 35);
    set("dex", 35);
    set("combat_exp", 2000000);
    set("shen_type", 1);
    set("attitude", "peaceful");
	set("max_qi",3000);
    set("max_jing",3000);
    set("neili",5000);
    set("max_neili",5000);
	set("jiali",60);
	set("score", 12000);

    set_skill("cuff", 250);
	set_skill("finger", 250);
	set_skill("sword", 250);
	set_skill("blade", 250);
	set_skill("parry",250);
	set_skill("dodge", 250);
	set_skill("force",250);
		
	set_skill("canhe-zhi",250);
	set_skill("murong-daofa",250);
	set_skill("murong-jianfa",250);
	set_skill("yanling-shenfa",250);
    set_skill("shenyuan-gong",250);

	map_skill("finger","canhe-zhi");
	map_skill("sword","murong-jianfa");
	map_skill("blade","murong-daofa");
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
        
    set_temp("apply/attack", 20);
    set_temp("apply/defense", 20);

	create_family("姑苏慕容" , 2, "弟子");
     
    carry_object(__DIR__"obj/shoe")->wear();
    carry_object(__DIR__"obj/red_silk")->wear();
    carry_object(__DIR__"obj/skirt1")->wear();

    set("inquiry", ([
		"慕容博" : (: ask_bo :),
		"六脉神剑" : "家父一直想研读一下六脉神箭,可惜我没能帮他达成这个心愿。\n",
		"王语鄢" : "她是我表妹，我挺喜欢她的，可是.........\n",
	]));           

    set("chat_chance",5);
    set("chat_msg",({
		"慕容复自言自语到：“我一定要继承父志，复兴大燕。”\n",
        "慕容复道：“哪里可以借到兵哪？”\n", 
	}) );
	set("paper_count", 1);
	setup();
}

void attempt_apprentice(object ob)
{
   if((string)ob->query("family/family_name")!="姑苏慕容")
    {
		command("say "+RANK_D->query_respect(ob)+"要想拜派,可先拜我派四大庄主。\n");
		return;
    }

	if((int)ob->query_skill("parry",1) <100)
	{
		command("say " + "我派“斗转星移”对招架要求比较高，这位" + 
		RANK_D->query_respect(ob) + "还是多下点功夫吧");
		return;
	}
	if((int)ob->query_skill("shenyuan-gong",1) < 80)
    {
		command("say " + RANK_D->query_respect(ob) + "对我派内功的修为还不够，还需要多加练习!");
		return;
    }
	command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
    command("recruit "+ob->query("id"));
	command("chat* haha");
	ob->set("title",RED"姑苏慕容"NOR + HIB"总管"NOR);
	      
}

string ask_bo()
{
	object me;
	object ob;
	me= this_player();

	if( me->query("family/family_name")!="姑苏慕容")
	{
		return"这位" + RANK_D->query_respect(me) + "与本派素无来往，询问此事是何道理？";
	}
	else 
	{
		if( me->query("family/master_id")=="murong bo")
		{
                         return" 你已经拜了家父为师了!他老人家还好吗?\n";
			if( query("paper_count") > 0)
			{
				return "他老人家最近在什么地方，你给我捎封信给他把!\n";
				add("paper_count",-1);
				ob = new("/d/murong/npc/obj/fbpaper");
				ob->move(me);
				me->set_temp("marks/paper",1);
			}
			else
			{
				return "你见到老爷子我就放心了，你下去吧！";
			}
		}
		else
		{
			return" 家父已经在几年前病逝了，你就不要多问了，你下去吧!";
		}
	}
}
