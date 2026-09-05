// sample master.c code
// xiake island master.c
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

#include <no1master.h>

int ask_kungfu();
int ask_liuhedao();
string ask_rongr();
void consider();
void heal();
string ask_for_leave();

void create()
{
        set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
        set("nickname", GRN "九指神丐" NOR);
        set("title",MAG "丐帮" NOR + YEL "第十七代" NOR+ MAG "掌门" NOR);
        set("gender", "男性");
        set("age", 75);
        set("long", "他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
        set("attitude", "peaceful");
        
        set("str", 50);
        set("int", 34);
        set("con", 40);
        set("dex", 34);
        set("leiting", 1);
        set("chat_chance", 2);
        set("chat_msg", ({
                "洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",
                "洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",
                "洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
//              (: random_move :),
                                (: heal :),
        }));
      set("inquiry", ([
             "青竹林" : "东北西北东西北。\n",
             "丐帮" : "东北西北东西北。\n",
             "拜师" : "你可以去广场下面的树洞找裘万家。\n",
             "武功" : (: ask_kungfu :),
             "功夫" : (: ask_kungfu :),
             "绝招" : (: ask_kungfu :),
             "打狗棒" : (: ask_kungfu :),
             "读书写字":"我们丐帮都是大老粗，不过你可以去桃花岛找蓉儿学。",
             "黄蓉"   : (:ask_rongr:),
             "蓉儿"   : (:ask_rongr:),
             "六合刀"   : (:ask_liuhedao:),
             "脱离帮派" : (: ask_for_leave :),

      ]));
//        set("inquiry", ([
//            "出师" : (: fight_start :),
//        ]));


        set("qi", 15000);
        set("max_qi", 15000);
        set("per", 38);
        set("jing", 13000);
        set("max_jing", 13000);
        set("neili", 16000);
        set("max_neili", 16000);
        set("jiali", 450);
        set("no_nuoyi",1);
        
        set("combat_exp",11000000);
        set("score", 200000);
         
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );
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
		set_temp("apply/armor", 500);
		set_temp("apply/damage", 400);
        create_family("丐帮", 17, "帮主");
        set("shen_type",1);set("score",100000);setup();
		
		setup_no1master();
        carry_object(__DIR__"yuzhu_zhang")->wield();
		carry_object("/d/gaibang/obj/cloth")->wear();
        carry_object(__DIR__"jiaohuaji");
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

void init()
{
        add_action("do_leave",  "leave");
        ::init();
}

string ask_for_leave()
{
	object me;

	me = this_player();

	if( (string)me->query("family/family_name") != "丐帮")
		return "你非我丐帮弟子，脱离帮派的事情我作不得主。";

	me->set_temp("pending/leave_gaibang", 1);
  return "如果" + RANK_D->query_respect(me) + "真想离我丐帮而去，就请下决心(leave)吧！";
}

int do_leave()
{
	object me = this_player();
	
	if (me->query_temp("pending/leave_gaibang") != 1)
		return 0;
	message_vision("$N对$n说道：「从此你就不再是我丐帮帮众了，请好自为之！」\n",this_object(), me );
	tell_object(me,HIR "你决定叛出丐帮门下！\n" NOR);
	me->delete_temp("pending/leave_gaibang");
  me->expell_family("丐帮");
	if (me->query("combat_exp") >= 1000)
		me->add("betrayer",1);
	return 1;
}	

int accept_object(object who, object ob)
{

        object me=this_player();
        mapping myfam;
        if (ob->query("food_supply") <= 0)
                return 0;
        if ((string)ob->query("id") != "jiaohua ji") {
                command("say 老叫化对" + (string)ob->query("name") + "没什么兴趣……");
                return 0;
        }
        if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
                command("say 老叫化现在饱得很。");
                return 0;
        }
        command("say 啊……这正是我想吃的叫化鸡呀！");
        if (!(myfam = this_player()->query("family")) || myfam["family_name"] == "丐帮" )
        {       
                if (random(me->query("kar")) < 8)
                {
                        say("也许是你机缘不足，洪七公心情正坏，咕噜了几句就没再理你。\n");
                        return 1;
                }
                command("say 既然你如此孝顺，我就教你这招「雷霆降龙」。");
                if (me->query_skill("strike",1)/2 + me->query_skill("xianglong-zhang", 1) >=135)
                {
                        say("你听了洪七公的讲解，学会了这一招。\n");
                        me->set("leiting",1);
                        return 1;
                }
                else
                {
                        say("由于你的降龙十八掌等级不够，对洪七公的讲解没有听懂。\n");
                        return 1;
                }
        }
        else
        {       command("say 我可没法报答你呀");
                return 1;
        }
        return 1;
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(2) )
        {
            case 0:
            command("wield zhu");
            command("perform staff.chan " + target->query("id"));
            command("unwield zhu");
             break;
            case 1:
            command("perform strike.leiting " +target->query("id"));
             break;
             }
}
void heal()
{
        object ob=this_object();
        
        if (ob->query("bihua"))
                return;
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("exert lifeheal");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                ob->set("water",ob->max_water_capacity() );
                ob->set("food",ob->max_food_capacity() );
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

int ask_kungfu()
{
        object me;
        me=this_player();
        if(me->query("family/family_name") !=  "丐帮")
        {
        return 0;
        }
        if(me->query("family/master_name") != "洪七公")
        {
        command("look "+me->query("id"));        
        command("say 我的绝招只传授给我的弟子！");
        return 1;
        }
        if (((me->query("dagou-bang/tiao"))) && (me->query("dagou-bang/zhuan"))  )
        {
        command("pat "+me->query("id")); 
        command("say 你已经学会了啊！");
        return 1;        
        }
        if ((int)me->query_condition("learn_dagoubang") > 0 )
        {
        command("bored "+me->query("id"));
        say("洪七公斜了你一眼说道：你怎么老问啊，你烦不烦啊！\n");
        command("say 你还是为丐帮做点什么吧！");      
        return 1;  
        }        
        if (random(me->query("score")+(me->query("kar"))) < 1800)
        {
        command("goaway");
        say("洪七公斜了你一眼说道：你自问对丐帮尽忠了吗？你是不是应该做些什么呢。\n");
        say("也许是你机缘不足，洪七公心情正坏，咕噜了几句就没再理你。\n");
        me->apply_condition("learn_dagoubang",60);
        return 1;
        }
        command("haha hong qigong");        
        command("pat "+me->query("id"));
        me->set("dagou-bang/tiao",1);
        me->set("dagou-bang/zhuan",1);
        command("say 你对丐帮如此尽力，真是辛苦你了，我就把打狗棒法的绝学教给你。");
        command("say 我这就把打狗棒的绝招传授给你!");
        say("你学会了打狗棒的挑字诀和转字决！\n");
        return 1;
}
string ask_rongr()
{
	      object me=this_player();
        if(me->query("family/family_name") !=  "丐帮")
           return "我哪里知道？";
        command("say 听说蓉儿回到了桃花岛，和她的靖哥哥住在清啸亭的小木屋里面(enter door)。");
        command("pat "+me->query("id"));
        me->set_temp("marks/洪七公",1);
        return "去找她学点读书写字吧。";
}

int ask_liuhedao()
{
    object me = this_player();
    if(me->is_busy())
    {
        write("你自己正忙着呢。\n");
        return 1;
    }

    if(me->query("family/family_name") != "丐帮" || me->query("family/master_id") != "hong qigong")
    {
        command("kick "+me->query("id"));
        command("say 吃老叫花子一脚！");
        return 1;
    }

	if (me->query("liuhedao_score") < me->query("score"))
	{
		me->start_busy(5);
	//	me->set("liuhedao_score",me->query("score"));
		command("say 你自问对丐帮做了多少事吗？");
		return 1;
	}
	else
	{
		if(wizardp(me) || (random(me->query("score")) > 50000 && random(me->query("kar")) > 30 && random(50) == 1 ))
		{
			me->set("liuhe-zhidian",1);
			command("haha");
			command("say 既然你为我丐帮出了这么大的力，老叫花子就指点你一招六合刀的功夫吧。");
			command("say 这六合刀乃是我丐帮最入门的功夫，但其中同样隐含着武学奥妙。");
			command("say 我丐帮的功夫刚猛无匹，六合刀也不例外。你使这路刀法时，必须要把天地六合尽皆放在胸中，方能发挥出这刀法的十成威力。");
			write("你听了洪七公的话，顿有所悟，掌握了六合归虚的真谛。\n");
			return 1;
		}
		me->start_busy(5);
		me->set("liuhedao_score",me->query("score"));
		command("say 你自问对丐帮做了多少事吗？");
		return 1;
	}
}
#include "/kungfu/class/masterdie.h"
