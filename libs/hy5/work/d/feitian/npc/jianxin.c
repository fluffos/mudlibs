// jianxin.c
// 青云(diabio)版权所有
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_fail();
string  ask_job();
string ask_me();
string ask_dao();
string ask_give();
mixed names = ({
        ({
        "扶风湖","潇潇暮雨楼","丹青阁","墨池","天星亭",
        "刑堂","兵器库","精益堂","藕香小榭","藕香湖牌坊",
        "魁星楼","祭祖厅","千里居","梅园","展梅阁",                
        "练武场","断木亭","挂剑堂","无眠阁","照壁", 
        "留剑堂","翡翠长廊","东南角楼","东北角楼","西角楼",
        "东角楼","西南角楼","南角楼","西北角楼","千里居",
        }),
        ({
        "神古活心流","神古活心流大门","牛肉馆",
        "瀑布","落人村","长乐屋","神户南门",
        }),
        });

void create()
{
        set_name( "绯村剑心" ,({ "jian xin", "xin" }));
        set("nickname", HIW"拔刀齊"NOR);
              set("title", HIR"前维新志士"NOR);
        set("gender", "男性");
        set("age", 26);
        set("long",
            "他就是飞天御剑流三十六代掌门、杀人者拔刀齐。他面色\n"
            "清秀，一副万人迷的模样，左脸有一快长长的十字刀疤。一\n"
            "你也许会想不到他曾经是维新时期让人闻风丧胆的杀人者\n"
            "拔刀齐，一手飞天御剑流使的出神入化。\n");
        set("attitude", "peaceful");
        set("str", 47);
        set("int", 42);
        set("con", 45);
        set("per", 45);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
        set("qi",16000);
        set("eff_jing",15000);
        set("jing",15000);
        set("eff_qi",16000);
        set("max_qi",16000);
        set("max_jing",15000);
        set("neili", 20000);
        set("max_neili", 25000);
        set("jiali", 50);
        set("shen",5000000);

        set("combat_exp", 6000000);

        set_skill("unarmed", 250);
        set_skill("force", 260);
        set_skill("parry", 280);
        set_skill("dodge", 250);
                set_skill("cuff",280);
        set_skill("blade", 320);
        set_skill("literate", 250);
        set_skill("xuanhualiu-quanfa", 250);
        set_skill("feitian-yujianliu",320);
        set_skill("wuxing-dun", 320);
        set_skill("shayi-xinfa", 320);
        set_skill("shayi", 320);
//        set_skill("bearart", 1100);
       

        map_skill("force", "shayi-xinfa");
        map_skill("parry", "feitian-yujianliu");
        map_skill("blade", "feitian-yujianliu");
        map_skill("dodge", "wuxing-dun");
        map_skill("unarmed", "xuanhualiu-quanfa");
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("飞天御剑流", 6, "掌门");
        set("book_count",1);
        set("inquiry", ([
           "逆刃刀": (: ask_me :),
           "铸刀": (: ask_dao :),
           "逆刃刀真打": (: ask_give :),
           "十刃":     "那是志志奇召集的十大高手。",
           "九头龙闪": "这是本门除了天翔龙闪外的最高剑决,如没有扎实的根底别轻易尝试。你想试试(accept test)？\n",
           "逆刃刀": (: ask_me :),
   	    "维新"  : (: ask_job :),
	    "shirenjob"  : (: ask_job :),
            "jobfail" : (: ask_fail() :),
            "任务失败" : (: ask_fail() :),
            ]));
        setup();
      carry_object("/clone/cloth/cloth")->wear();
      carry_object(__DIR__"obj/shoes")->wear();
          carry_object(__DIR__"obj/nirendao")->wield();
}

void attempt_apprentice(object ob)
{
        	if ((int)ob->query_skill("huoxinliu-jianfa", 1) < 180) {
		command("say 你的活心流剑法太低了，还未能领悟活心二字如何学习我的武功呢。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把活心流剑法先提高了在来吧？");
		return;
        }
	if ((int)ob->query_skill("shayi-xinfa", 1) < 120) {
		command("say 你的杀意心法太低,恐怕控制不了杀意。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把杀意心法先提高了在来吧？");
		return;
	}
	if ((int)ob->query_skill("aikido", 1) < 120) {
		command("say 你的空手道太低。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把空手道先提高了在来吧？");
		return;
	}
	if ((int)ob->query_skill("wuxing-dun", 1) < 120) {
		command("say 你的五行遁太低。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把五行遁先提高了在来吧？");
		return;
	}
    if ((int)ob->query_skill("shayi", 1) < 120)
    {
        command("say 剑法之道在于杀意。");
        command("say " + RANK_D->query_respect(ob) +
            "你的杀意太低了？");
        return;
    }
	if ((int)ob->query("shen") < 200000) {
		command("say 飞天御剑流是救人之剑！如果被邪魔外道学到将会危害武林。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if (ob->query_int() < 30) {
		command("say 飞天御剑流之道全靠一个悟字。");
		command("say 你的悟性这么低如何领悟飞天御剑流呢。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("chat 飞天御剑流是拯救乱世所创的剑法。");
       command("chat " + RANK_D->query_respect(ob) + "希望你能将飞天御剑流发扬光大。");
	command("recruit " + ob->query("id"));
	ob->set("title",HIR"【飞天御剑流】"HIW"维新志士"NOR);
       ob->set("class", "yujianliu");
}

string ask_me()
{
        object me=this_player();
        me->set_temp("tmark/刀",1);
        return("这是小生决定不在杀人后找名师铸到一把逆刃刀，希望以后只靠刀救人而不是杀人\n");
}

string ask_dao()
{
        object me=this_player();
        if(me->query_temp("tmark/刀")==1) {
                me->add_temp("tmark/刀",1);
                return("当年我的逆刃刀是找,素有杀人奇剑之称的真平郎所铸的。\n");
        }
        else {
                me->set_temp("tmark/刀",0);
                return("日本到处都有铸刀的地方啊？\n");
        }
}

string ask_give()
{
        object ob,me=this_player();
        if(me->query_temp("tmark/刀")==2) {
                me->set_temp("tmark/刀",1);
                if(query("book_count")>0) {
                        ob=new(__DIR__"obj/nirendao");
                        ob->move(me);
                        add("book_count",-1);
                        return "好吧，你就带着他去找真平朗去吧。\n"
                                                        +"绯村剑心给你把一把逆刃刀。\n";
                }
                else
                        return("你来晚了，逆刃刀已经被我给人。\n");
        }
        else {
                me->set_temp("tmark/刀",0);
                return  RANK_D->query_respect(me) +
                        "不是想跟我较量较量吧？\n";
        }
}
void init()
{
        ::init();
        add_action("do_accept", "accept");
}
int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {
	if((string)this_player()->query("family/family_name") != "飞天御剑流") 
		{
			command("say 你不是本门中人如何学习飞天御剑流。\n");
			return 1;
		}

	else if(this_player()->query("feitian-yujianliu")>150)
		{
			command("say 你先把剑法练好了在来找我吧。\n");		return 1;}
	else if(this_player()->query("shen")<-50000)
		{
			command("say 如此绝学教给了你也是危害人间！\n");		return 1;}
	else if(this_player()->query("dex")<30)
		{
			command("say 你身法太差，体会不到九头龙闪。\n");
		return 1;}
	else if(this_player()->query("combat_exp")<1000000)
		{
			command("say 你实战经验太差，我不能教你？。\n");
		return 1;}


	
                say("\n绯村剑心点了点头，说道：很好，我试你三招，这是第一招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("绯村剑心叹了口气，说道：连小生第一招都撑不过，真是太自不量力....\n");
                 this_player()->die();
	       return 1;
		}
                say("\n绯村剑心说道：不错，这是小生的第二招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("绯村剑心叹了口气，说道：功力差距太远了....\n");
                this_player()->die();     
	   return 1;
                }
                say("\n绯村剑心说道：小生第三招来了....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("绯村剑心叹道：可惜，功力还是有所欠缺....\n");
                       this_player()->die();
 return 1;
                }
                
say("\n绯村剑心笑道：小生就把飞天御剑流至高剑决传授给你了，希望你不要用来胡作非为！\n\n");
                this_player()->set("feitian/jiu",1);
	return 1;
        }
        return 0;
}
void kill_ob(object me)
{
	command("say 小生并不想杀人，你何必苦苦相逼呢？！。\n");
	::kill_ob(me);
}


string ask_job()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "飞天御剑流")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的奸细？\n", this_object(), ob);
                      return  "快走。";
            }

     if(ob->query_condition("feitian2_busy"))
        return  "你刚接过任务，等会再来。";

     if(ob->query("combat_exp")<500000)
      return  "你的功夫太差了。";

        if (ob->query_temp("fthw")) {
                command("kick " + ob->query("id"));
      return  "小生不是给了你任务了吗？";
                }
        if (ob->query_temp("fthwjob")) {
                command("kick " + ob->query("id"));
      return  "小生不是给了你任务了吗？";
                }
      
	  where=names[1][random(7)];
	  ob->set_temp("fthw",1);
	  ob->set_temp("fthwjob",where);
          ob->apply_condition("feitian2_busy",8);
if (!ob->query_skill("shayi-xinfa",1))
{
ob->apply_condition("feitian2_busy",16);
}
          obn=new(__DIR__"ling");
          obn->set("usename",ob->query("name"));
          obn->move(ob);
	  return    HIM"志志雄的手下要与维新党人做对！要喑杀维新党人\n"+
           "          你赶快去"+where+"和守卫一段时间(shouwei)。\n"+
           "          如果真的有人来的话，帮小生消灭他们。"NOR; 
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query_temp("fthwjob")) {
                command("sigh");
                command("say 这么点事，你都做不好，也罢，你去吧.");
          destruct(present("ft lingpai",me));
          me->apply_condition("feitian2_busy",6);
       me->delete_temp("ftjob");
        me->delete_temp("fthw");
        me->delete_temp("fthwjob");
        return 1;
                }
}
