//made by hacky
// data: 1997.11.20
               
#include <ansi.h> 
#include <title.h>
inherit NPC; 
inherit F_MASTER;
void re_rank(object);   

void create()
{
	set_name("丘处机", ({ "qiu chuji" , "qiu" , "master" }));
	set("nickname", GRN"长春"NOR+BLU"真人"NOR); 
        set("title",HIB"全真派"NOR+GRN"真人"NOR);
	set("long",
	"他是全真教的第二代弟子，仙风道骨，颌下三缕长须，头戴一顶紫金冠，身穿\n"
	"一件八卦道袍，手执拂尘，看上去飘飘然宛如神仙中人，俨然是一位得道高人。\n");
	set("gender", "男性");
	set("apprentice_available", 50);
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 10000);

	set_skill("daoxue-xinfa",100);
	set_skill("sword",150);
        set_skill("quanzhen-jian",120);
	set_skill("tonggui-jian",150);
	set_skill("array", 150);
	set_skill("force", 100);
	set_skill("xiantian-gong", 100);
	set_skill("dodge", 100);
	set_skill("jinyan-gong", 100);
	set_skill("cuff", 120);
	set_skill("parry", 120);
        set_skill("tiangang-beidou",100);
        set_skill("yangxin-quan",100);
        set_skill("kongming-quan",100);
        set_skill("literate",80);

        map_skill("sword","tonggui-jian");
	map_skill("dodge","jinyan-gong");
	map_skill("parry","tonggui-jian");
	map_skill("force","xiantian-gong");
        map_skill("cuff","kongming-quan");
        map_skill("array","tiangang-beidou");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);
	set("inquiry", ([
        	"郭靖" :"靖儿是个好孩子，也没枉费我大哥一番苦心，他现在正在\n"
			"襄阳前线配合官兵抵挡蒙古大军。\n",
	        "杨康" :"哎，都怪我瞎了眼，收了这个甘心认贼作父的弟子，唉！\n",
	]) );
	setup();
/*        set("chat_chance", 10);
        set("chat_msg", ({
        	
        }) );
*/
	create_family("全真派", 2, "真人");
	carry_object(__DIR__"obj/robe")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本真人今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
     if((string)ob->query("family/family_name")!="全真派")
   {
    command ("say"+RANK_D->query_respect(ob)+"若想入我重阳宫，可先败尹志平。");
    return;
    }
     if((int)ob->query("score")<700)
    { command ("say 你自问是否对本门尽力了?");
    return;
    }
     if((int)ob->query("shen")<50000)
   {
    command ("say 学武之人，德义为先，希望"+RANK_D->query_respect(ob)+"多做些善事");
   return;
      }
     if((int)ob->query("combat_exp")<35000)
    {
    command ("say 你经验不够,还是先跟别人练几年再来拜我吧.");
     return;
    }
        
                command("smile");
                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
         
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoism");
        re_rank(ob);
        add("apprentice_availavble", -1);
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 25000 ) {
                student->set("title",HIB"全真派"NOR+YEL"弟子"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              student->set_title(TITLE_RANK, HIB"全真派"NOR+YEL"弟子"NOR);
                return ;
        } else if ( exp <= 50000 ) {
                student->set("title",HIB"全真派"NOR+YEL"道人"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              student->set_title(TITLE_RANK, HIB"全真派"NOR+YEL"道人"NOR);
                return ;
        } else if ( exp <= 75000 ) {
                student->set("title",HIB"全真派"NOR+GRN"道长"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              student->set_title(TITLE_RANK, HIB"全真派"NOR+GRN"道长"NOR);
                return ;
        } else  {
                student->set("title",HIB"全真派"NOR+GRN"真人"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              student->set_title(TITLE_RANK, HIB"全真派"NOR+GRN"真人"NOR);
                return ;
    }
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int my_max_qi;
	
	my_max_qi = me->query("max_qi");
	
	if( ( (int)me->query("qi")*100/my_max_qi ) <= 35 )
	{
		me->map_skill("sword", "tonggui-jian");  
		me->kill_ob(victim);
		command("say 今天"
	+RANK_D->qury_self_respect(me)+"跟你拼了。就是死也要赚个本，嘿嘿。\n");
	}
	call_out("check", 1, me, victim);
	return;
}

int check(object from, object to)
{
	int max;

	max = from->query("max_qi");	
	if( ( (int)from->query("qi")*100/max ) <=35 )
	{
		from->map_skill("sword", "tonggui-jian");
		from->kill_ob(to);
		command("say 今天"+RANK_D->qury_self_respect(to)+"跟你拼了。\n");		
		message("vision",
		"$N两眼血红，势如疯虎，显然是杀急了眼，不顾一切开始拼命了。\n",
		from,environment(from));
		return 1;
	}
	call_out("check", 1, from, to);
	return 1;
}
