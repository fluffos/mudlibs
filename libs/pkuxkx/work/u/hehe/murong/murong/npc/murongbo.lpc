//murongbo.c
//by hehe
//2003.3.13

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("慕容博",({"murong bo","murong","bo"}));
    set("title",RED"姑苏慕容"NOR+HIW"老爷子"NOR);
    set("nick","以彼之道 还施彼身");
	set("long", 
    "他就是天下号称以彼之道，还彼之身的姑苏慕容博。\n"
    "他脸上带着不可一世的笑容。\n");
    set("age", 57);      
	set("str", 40);
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("combat_exp", 11000000);
    set("shen_type", 1);
    set("attitude", "peaceful");
    set("max_jingli",8000);
	set("jingli",8000);
    set("neili",8000);
    set("max_neili",8000);
	set("jiali",100);
	set("score", 16000);

    set_skill("cuff", 350);
	set_skill("finger", 350);
	set_skill("sword", 350);
	set_skill("blade", 350);
	set_skill("parry",350);
	set_skill("dodge", 350);
	set_skill("force",350);
	
	set_skill("canhe-zhi",350);
	set_skill("murong-daofa",350);
	set_skill("murong-jianfa",350);
	set_skill("yanling-shenfa",350);
    set_skill("shenyuan-gong",350);
	set_skill("douzhuan-xingyi",350);

	map_skill("parry","douzhuan-xingyi");
	map_skill("finger","canhe-zhi");
	map_skill("sword","murong-jianfa");
	map_skill("blade","murong-daofa");
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");

	prepare_skill("finger","canhe-zhi");

	set_temp("apply/attack", 20);
    set_temp("apply/defense", 20);

    set("inquiry", ([
		"慕容博" : "慕容复是犬子，在江湖上也是小有名头！\n",
		"六脉神剑" : "我一直都想看一眼，可惜.....\n",
	]));           

	set("chat_chance",5);
    set("chat_msg",({
		"慕容博自言自语到：“谁都不会想到我会藏在这里，哈哈。”\n",
        "慕容博道：“只可惜在这里看不到六脉神剑”\n", 
	}) );

    setup();

	create_family("姑苏慕容" , 1, "庄主");
     
//	carry_object(__DIR__"obj/shoes1")->wear();
//    carry_object(__DIR__"obj/cloth")->wear(); 
}

void attempt_apprentice(object ob)
{
	object obj = this_object();
	object me = this_player();
    if((string)ob->query("family/family_name")!="姑苏慕容")
    {
        command("say "+RANK_D->query_respect(ob)+"我可是不轻易收徒弟的。\n");
		return;
    }
	else if(ob->query("family/master_id")=="murong fu")
	{
		if(ob->query("combat_exp")<1000000)
		{
			command("say "+RANK_D->query_respect(ob)+"要勤加练功啊！\n");
			return;
		}
		else
		{
			command("say 嗯，让我来看看考察考察你的功夫.....\n");
			message_vision(BLU "$n右手一把抓住$N的脉门，左手点向$N全身的要穴，$N大骇...\n" NOR,me,obj);
			message_vision(BLU "而后$n围着$N快速旋转起来，$N一动不动的任由摆布\n" NOR,me,obj);
			message_vision(BLU "大约有一杯茶的功夫，$n终于停下来了\n\n" NOR,me,obj);
			if((int)ob->query_skill("parry",1) <170)
			{
				command("say " + RANK_D->query_respect(ob) + "的招架功夫还有待提高！\n");
				return;
			}
			if((int)ob->query_skill("shenyuan-gong",1) < 160)
			{
				command("say " + RANK_D->query_respect(ob) + "在神元功上还得多下功夫！\n");
				return;
			}
			command("say 看来你的基本功很扎实，今后就跟着我好好学功夫吧！\n");	
			command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！\n");
			command("chat* haha ");
			command("chat 我“以施彼道 还施彼身”又收到一个可造之才！\n");
			command("chat 我们复兴大燕又多了一份力量！！！\n");
			command("recruit "+ob->query("id"));
			ob->set("title",HIW"以施彼道 还施彼身"NOR);
			return;
		}
	}
}

int accept_object(object me, object ob)
{
	me=this_player();

    if((string)me->query("family/family_name")!="姑苏慕容")
	{
		if(ob->query("name")=="六脉神剑剑谱") 
		{
       		command("yi");
			command("say 这正是我梦寐以求的，多谢你了 !");
			return 1;
		}
		else if(ob->query("name")=="家书")
		{
			command("bow");
			command("say 你给我带来了我儿慕容复的家书，太感谢你了!");
			return 1;
		}
	}
	else
	{
		if(ob->query("name")=="六脉神剑剑谱")
		{
			command("wa");
			command("say 这正是我梦寐以求的，多谢你了 !");
			me->set_temp("murong/jianpu",1);
			call_out("check",0,me);
			return 1;
		}
		else if(ob->query("name")=="家书")
		{
			command("bow");
			command("say 你给我带来了我儿慕容复的家书，太感谢你了!");
			me->set_temp("murong/jiashu",1);
			call_out("check",0,me);
			return 1;
		}
	}
}

void check(object me)
{
	object ob;
	me=this_player();
	command("hehe");

	if( me->query_temp("murong/paper") 
		&& me->query_temp("murong/jianpu")
		&& me->query_temp("murong/jiashu"))
	{
		command("say 这里有封回信，你帮我带给我儿慕容复！");
		me->delete_temp("murong/paper");
		me->delete_temp("murong/jianpu");
		me->delete_temp("murong/jiashu");
		ob=new("/d/murong/npc/obj/bfpaper");
		ob->move(me);
		me->set_temp("murong/huixin",1);
	}

}

