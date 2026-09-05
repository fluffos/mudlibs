//murongbo.c
//by hehe
//2003.3.13

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int auto_perform();

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
    set("combat_exp", 15000000);
    set("shen_type", 1);
    set("attitude", "peaceful");
    set("max_jingli",10000);
        set("jingli",10000);
    set("neili",10000);
    set("max_neili",10000);
     set("max_qi",10000);
     set("qi",10000);
        set("jiali",200);
	set("score", 16000);

    set_skill("cuff", 500);
        set_skill("finger", 500);
        set_skill("sword", 500);
        set_skill("blade", 500);
        set_skill("parry",500);
        set_skill("dodge", 500);
        set_skill("force",500);
	set_skill("literate",350);
        set_skill("canhe-zhi",500);
         set_skill("strike",500);
         set_skill("xingyi-zhang",500);
        set_skill("murong-daofa",500);
        set_skill("murong-jianfa",500);
        set_skill("yanling-shenfa",500);
    set_skill("shenyuan-gong",500);
        set_skill("douzhuan-xingyi",500);

	map_skill("parry","douzhuan-xingyi");
	map_skill("finger","canhe-zhi");
	map_skill("sword","murong-jianfa");
	map_skill("blade","murong-daofa");
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
         map_skill("strike","xingyi-zhang");

	prepare_wskill("sword","murong-jianfa");
	prepare_wskill("blade","murong-daofa");

	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");

	set_temp("apply/attack", 20);
    set_temp("apply/defense", 20);

    set("inquiry", ([
                 "慕容复" : "慕容复是犬子，在江湖上也是小有名头！\n",
		"六脉神剑" : "我一直都想看一眼，可惜.....\n",
	]));

	set("chat_chance",5);
    set("chat_msg",({
		"慕容博自言自语到：“谁都不会想到我会藏在这里，哈哈。”\n",
        "慕容博道：“只可惜在这里看不到六脉神剑”\n",
	}) );
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
			 (: auto_perform :),
              }));
    setup();

	create_family("姑苏慕容" , 1, "庄主");

      carry_object("/d/murong/npc/obj/shoes1")->wear();
      carry_object("/d/murong/npc/obj/cloth")->wear();
}

void init()
{
object me = this_player();
object ob = this_object();
/*
if (userp(me) && !wizardp(me) && me->query("id") != ob->query("player") && me->query("family/master_id") != "murong bo")
{
message_vision(HIC"$N见有人过来，大叫不妙：“多年苦心经营，岂可毁于一旦！” 说罢翻身而去，立刻不见了踪影。\n"NOR,ob);
destruct(ob);
return;
}
if (userp(me) && me->query("id") == ob->query("player") && me->query("family/family_name") != "姑苏慕容")
{
kill_ob(me);
}
*/
}
void destroy(object ob)
{
	destruct(ob);
	return;
}
void attempt_apprentice(object ob)
{
object link_ob;
	object obj = this_object();
	object me = this_player();
        string name, new_name;
link_ob=me->query_temp("link_ob");
if(!link_ob) return;
name=link_ob->query("name");
    if((string)ob->query("family/family_name")!="姑苏慕容")
    {
        command("say "+RANK_D->query_respect(ob)+"还是请回吧，老夫可是不轻易收徒弟的。\n");
		return;
    }
	else if(ob->query("family/master_id")=="murong fu")
	{
		if(ob->query("combat_exp")<1000000)
		{
			command("say "+RANK_D->query_respect(ob)+"江湖经验欠缺，还要继续磨练啊！\n");
			return;
		}
                else if(ob->query("score") < 1500)
                {
                        command("say "+RANK_D->query_respect(ob)+"对我派贡献还不够。\n");
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
			command("haha ");
           new_name = "慕容" + name[0..3];
           ob->set("name", new_name);
           command("say 从今以后你就叫做" + new_name + "，希望你能把慕容功夫发扬光大！");
			command("chat 我“以彼之道 还施彼身”又收到一个可造之才！\n");
			command("chat 我们复兴大燕又多了一份力量！！！\n");
			command("recruit "+ob->query("id"));
			ob->set("title",HIW"以彼之道 还施彼身"NOR);
			return;
		}
	}
}

int accept_object(object me, object ob)
{
	me=this_player();

    if((string)me->query("family/family_name")!="姑苏慕容")
	{
		if(ob->query("id")=="liumai-shenjian jianpu")
		{
       			command("yi");
			command("say 这正是我梦寐以求的，多谢你了 !");
			call_out("destroy",1,ob);
			return 1;
		}
		else if(ob->query("id")=="jia shu")
		{
			command("bow");
			command("say 你给我带来了我儿慕容复的家书，太感谢你了!");
			call_out("destroy",1,ob);
			return 1;
		}
	}
	else
	{
		if(ob->query("id")=="liumai-shenjian jianpu")
		{
			command("wa");
			command("say 这正是我梦寐以求的，多谢你了 !");
			me->set_temp("murong/jianpu",1);
			call_out("destroy",1,ob);
			call_out("check",0,me);
			return 1;
		}
		else if(ob->query("id")=="jia shu")
		{
			command("bow");
			command("say 你给我带来了我儿慕容复的家书，太感谢你了!");
			me->set_temp("murong/jiashu",1);
			call_out("destroy",1,ob);
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
int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");
	object *inv;
	int i;

	command("exert powerup");
	command("perform finger.canshang");

	if ( !objectp(target) ) return 0;

	if (me->query("qi") < me->query("eff_qi"))
 	command("exert recover");
 	if (me->query("jing") < me->query("eff_jing"))
	command("exert regenerate");

         switch( random(5) )
        {
            case 0:
            command("perform parry.xingyi " + target->query("id"));
             break;
            case 1:
            command("perform finger.dianxue " + target->query("id"));
            break;
            case 2:
            inv = all_inventory(environment(me));
            for(i = 0;i < sizeof(inv);i++)
            {
                if (inv[i]->is_character() && inv[i] != me && inv[i] != target) return 1;
            }
		command("exert roar");
            break;
            case 3:
            command("perform strike.xingdian " + target->query("id"));
            break;
            case 4:
            command("perform strike.riyue " + target->query("id"));
            break;
	 }

	return 1;
}
