// tang wuhuo.c 唐无火

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_fail();
string  ask_job();

string ask_jianxi();
string ask_finish();
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
        "东南角楼","东北角楼","西角楼",
        "东角楼","西南角楼","南角楼","西北角楼",
        }),
        });

void create()
{
	set_name("唐无火", ({ "tang wuhuo", "tang" }));
	set("nickname", HIW "不温不火" NOR);
	set("long", 
		"他是唐门第七代弟子中的杰出人物。处事为人八面玲珑，做事\n"
		"稳稳当当，脾气不急不燥。江湖人称“不温不火”唐大侠。\n"
		"他大约四十有余，笑容可掬，双目隐有精芒闪烁。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 98);
	set("int", 90);
	set("con", 90);
	set("dex", 92);
	
	set("qi", 30000);
	set("eff_qi", 30000);
	set("max_qi", 30000);
        set("jing", 30000);
	set("eff_jing", 30000);
	set("max_jing", 30000);
	set("neili", 80000);
	set("max_neili", 80000);
	set("jiali", 60);
	set("combat_exp", 6800000);
	set("score", 60000);

	set_skill("force", 200);
	set_skill("biyun-xinfa",320);
	set_skill("dodge", 200);
	set_skill("qiulinshiye", 280);
	set_skill("strike", 200);
	set_skill("unarmed",200);
	set_skill("biye-wu", 300);
	set_skill("parry", 200);
	set_skill("throwing", 280);
	set_skill("zhuihun-biao", 300);
	set_skill("literate", 100);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "zhuihun-biao");
	map_skill("throwing", "zhuihun-biao");
	
	create_family("唐门", 7, "弟子");
	set("class", "tangmen");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.lianhuan" :),
		(: perform_action, "strike.meng" :),
		(: perform_action, "strike.wandu" :),
		(: perform_action, "dodge.rain" :),
                (: perform_action, "dodge.wu" :),
	}) );
        set("inquiry", ([
   	    "做暗器"  : (: ask_jianxi :),
	    "job"  : (: ask_jianxi :),
   	    "护城"  : (: ask_job :),
	    "huchenjob"  : (: ask_job :),
            "huchenfail" : (: ask_fail() :),
            "护城失败" : (: ask_fail() :),
   	    "完成"  : (: ask_finish :),
	    "finish"  : (: ask_finish :),

        ]));
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	setup();
	carry_object("/d/tangmen/obj/gangbiao1")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 70) {
		command("say 唐门虽然以暗器为主，但还是要辅以内力。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在碧云心法上多下点功夫？");
		return;
	}
	if (ob->query_int() < 24) {
		command("say 唐门历来注重弟子的文学修为。");
		command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("say 唐门武学精深博大，你好好修习，将唐门发扬光大。");
	command("recruit " + ob->query("id"));
}

string ask_jianxi()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "唐门")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的？\n", this_object(), ob);
                      return  "快走。";
            }
    if ((int)ob->query_skill("biyun-xinfa",1) < 30 ) {
                      message_vision("$N对着$n大喝一声：你的本门内功太低了？\n", this_object(), ob);
                      return  "快走。";
    } 
     if ((int)ob->query_condition("guojob2_busy"))
        return  "你刚接过任务，等会再来。";

     if(ob->query_condition("tangmen_busy"))
        return  "你刚接过任务，等会再来。";

//     if(ob->query_condition("tangmen2_busy"))
//        return  "你刚接过任务，等会再来。";

	  if(ob->query("combat_exp")<10000)
      return  "你的功夫太差了。";
            if(ob->query_temp("tangmen"))
      return  "你不是正在干活啊!";

	  where=names[0][random(30)];
	  ob->set_temp("tangmen",1);
	  ob->set_temp("tangmenjob",where);
          ob->apply_condition("tangmen_busy",9);
if (!ob->query_skill("biyun-xinfa",1))
{
ob->apply_condition("tangmen_busy",9);
}
          obn=new(__DIR__"saozhou");
          obn->move(ob);
	  return    HIY"我刚得到消息，我们的弟子练功，需要暗器。\n"+
           "          你赶快去"+where+"做些暗器吧(zuogong)。\n"+
           "          可能有别的门派的人来闹事，多加小心。"NOR; 
}

string ask_finish()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
      if(!ob->query_temp("tangmen"))
      return  "我没叫你干过活啊!";

	  if(!ob->query_temp("tangmenok"))
      return  "你的活没干完啊!";
        ob->delete_temp("tangmen");
        ob->delete_temp("tangmenjob");
        ob->delete_temp("tangmenok");
        ob->add("combat_exp",50+random(150));
        ob->add("potential",25+random(100));
	  return    HIY"做得好，。\n"+
           "          我指点你二手功夫吧。\n"+
           "          你的经验和潜能增加了!"NOR; 
}


string ask_job()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "唐门")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的？\n", this_object(), ob);
                      return  "快走。";
            }
    if ((int)ob->query_skill("biyun-xinfa",1) < 30 ) {
                      message_vision("$N对着$n大喝一声：你的本门内功太低了？\n", this_object(), ob);
                      return  "快走。";
    } 
if ((int)ob->query_condition("guojob2_busy"))
        return  "你刚接过任务，等会再来。";

     if(ob->query_condition("tangmen2_busy"))
        return  "你刚接过任务，等会再来。";

//     if(ob->query_condition("tangmen_busy"))
//        return  "你刚接过任务，等会再来。";

     if(ob->query("combat_exp")<100000)
      return  "你的功夫太差了。";
        if (ob->query_temp("tmhw")) {
                command("kick " + ob->query("id"));
      return  "我不是给了你任务了吗？";
                }
        if (ob->query_temp("tmhwjob")) {
                command("kick " + ob->query("id"));
      return  "我不是给了你任务了吗？";
                }
      
	  where=names[1][random(7)];
	  ob->set_temp("tmhw",1);
	  ob->set_temp("tmhwjob",where);
          ob->apply_condition("tangmen2_busy",22);
if (!ob->query_skill("biyun-xinfa",1))
{
ob->apply_condition("tangmen2_busy",25);
}
          obn=new(__DIR__"ling");
          obn->set("usename",ob->query("name"));
          obn->move(ob);
	  return    RED"刚才守卫来报告，所谓的名门正派，居然来偷袭唐门。\n"+
           "          你赶快去"+where+"和护卫门一起护城(huchen)。\n"+
           "          如果真的有人来偷袭，消灭他们。"NOR; 
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query_temp("tmhwjob")) {
                command("sigh");
                command("say 这么点事，你都做不好，也罢，你去吧.");
          destruct(present("tm lingpai",me));
          me->apply_condition("tangmen2_busy",33);
       me->delete_temp("tmjob");
        me->delete_temp("tmhw");
        me->delete_temp("tmhwjob");
        return 1;
                }
}

