// hehongyao.c
// 何红药
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_fail();
string  ask_job();

string ask_jianxi();
string ask_finish();
mixed names = ({
        ({
        "村东口","桃花江东岸","江边小路","桃花峪","五毒山路",
        "小村口","万毒窟外","万毒窟","路边小店","山边小路",
        "黄土大道","黑森林","上山小路","虎穴","虎穴深处",                
        "天心岩","狼窝","卧龙岗上","腾蛟亭","栖凤亭", 
        "练毒室","百毒窟外","松树林","百毒窟","千毒窟",
        "千毒窟外","百毒窟","五毒教大门","瀑布","草地",
        }),
        ({
         "宋兵","偏将","裨将","佐将","小贩","男孩","郭芙","老先生",
		 "小孩","书店老板","武三通","穷汉","铁匠","朱子柳","店小二","宋兵",
		 "静玄师太","静照师太","宋远桥","莫声谷","陆乘风","韩宝驹","黄药师","余沧海",
		 "殷野王","胡青牛","尹志平","小龙女","刘承风","欧阳锋","白衣少女","九翼道人",
		 "阿紫","玉磬子","玉音子","岳夫人","岳不群","令狐冲","玄苦大师","清善比丘",
		 "独臂神尼","庄夫人","双儿","吴六奇","木婉清","萧远山","李沅芷","向问天",
		 "曲洋","黑白子","程瑶迦","程瑶迦","沐剑屏","天柏道人","本尘","本观",
		 "天山童姥","韦一笑","谢逊","澄坚","陆乘风","张翠山","宋青书","玄贞道长",
		 "石破天","苏星河","逍遥子","朱丹臣","简长老","封不平",
        }),
        });

void create()
{
        set_name("何红药", ({ "he hongyao", "he" }));
        set("nickname", HIG "疤面丐婆" NOR);
        set("long",@LONG
他就是五毒教的长老，教主的姑姑何红药。随然是教主的长辈，但功夫却是一块跟
上代教主学的。据说她曾经被立为教主继承人，但后来犯下大错，所以被罚到此处
看守圣地，以赎前罪。她穿着一身破旧的衣衫，满脸疤痕，长得骨瘦如柴，双目中
满是怨毒之色。
LONG
        );
        set("title","五毒教长老");
        set("gender", "女性");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 19000);
        set("max_jing", 19000);
        set("neili", 14000);
        set("max_neili", 14000);
        set("jiali", 100);
        set("combat_exp", 6500000);
        set("score", 500000);
        set("inquiry", ([
   	    "任务"  : (: ask_jianxi :),
	    "job"  : (: ask_jianxi :),
   	    "完成"  : (: ask_finish :),
	    "finish"  : (: ask_finish :),
   	    "迎击"  : (: ask_job :),
	    "attackjob"  : (: ask_job :),
            "attackfail" : (: ask_fail() :),
            "迎击失败" : (: ask_fail() :),
        ]));

        set_skill("force", 280);
        set_skill("wudu-shengong", 320);
        set_skill("dodge", 190);
        set_skill("wudu-yanluobu", 280);
        set_skill("unarmed", 160);
        set_skill("qianzhu-wandushou", 280);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("wudu-goufa", 380);
        set_skill("poison", 260);
        set_skill("literate", 80); 
        set_skill("finger",160);
        set_skill("shedu-qiqiao",360);
//      set_skill("hammer", 100);
//      set_skill("jinshe-chui", 150 );
//      set_skill("huoyan-dao", 200);
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
         set("chat_chance_combat", 90);
         set("chat_msg_combat", ({
                (: perform_action, "finger.sandu" :),
                (: perform_action, "sword.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "finger.sandu" :),
                (: perform_action, "dodge.snake" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),		
        }) );


        map_skill("finger","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//      map_skill("hammer", "jinshe-chui");
//      map_skill("strike","huoyan-dao");

        create_family("五毒教", 11, "长老");
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        setup();

        carry_object("d/wudujiao/npc/obj/jiandao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("d/wudujiao/npc/obj/wuxing");

        add_money("gold",10);
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "无性") {
                                 command("say 这位公公不要开玩笑了。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是快去伺候皇上吧！");
                return;
                  }

                  if ((int)ob->query("shen") > -10000) {
                                 command("say 做我五毒教弟子必须心狠手辣。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "心慈手软，可惜与我教没有缘分啊！");
                return;
                  }

        if ((string)ob->query("family/family_name") != "五毒教")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "不是本教弟子，还是请回吧！");
                return;
                  }

        if ((int)ob->query_skill("poison", 1) < 100) {
                command("say 我五毒教弟子以毒杀人，修习毒技是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "是否还应该多多钻研本门的绝学？");
                return;
        }
        if ((int)ob->query_skill("wudu-shengong", 1) < 100) {
                command("say 你的五毒神功还学的不够啊。");
                return;
        }

          command("chat 嘿嘿嘿嘿！！！！！");
          command("chat 该当我五毒教发扬光大，称霸武林指日可待了。");
          command("chat 嘿嘿嘿嘿！！！！！");
          command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title","五毒教护法");
       return;
}

string ask_jianxi()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "五毒教")
           {
                      message_vision("$N对着$n大喝一声：本教弟子才能做任务。你是哪来的？\n", this_object(), ob);
                      return  "快走。";
            }

    if ((int)ob->query_skill("wudu-shengong",1) < 30 ) {
                      message_vision("$N对着$n大喝一声：你的本门内功太低了？\n", this_object(), ob);
                      return  "快走。";
    } 

	  if(ob->query("combat_exp")<10000)
      return  "你的功夫太差了。";
      if(ob->query_temp("wudujiao"))
      return  "你不是正在干活啊!";
if ((int)ob->query_condition("guojob2_busy"))
        return  "你刚接过任务，等会再来。";
     if(ob->query_condition("wdj_busy"))
        return  "你刚接过任务，等会再来。";


     if(ob->query_condition("wdj_busy"))
        return  "你刚接过任务，等会再来。";
      
	  where=names[0][random(30)];
	  ob->set_temp("wudujiao",1);
	  ob->set_temp("wudujiaojob",where);
          ob->apply_condition("wdj_busy",8);
if (!ob->query_skill("wudu-shengong",1))
{
ob->apply_condition("wdj_busy",12);
}

          obn=new(__DIR__"saozhou");
          obn->move(ob);
	  return    HIW"我刚得到教主命令，需要毒物，来制造暗器。\n"+
           "          你赶快去"+where+"捉一些来吧(zuoduwu)。\n"+
           "          可能有正派的人来挑兴，看到了就给我杀了。"NOR; 
}

string ask_finish()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
      if(!ob->query_temp("wudujiao"))
      return  "我没叫你干过活啊!";

	  if(!ob->query_temp("wudujiaook"))
      return  "你的活没干完啊!";
        ob->delete_temp("wudujiao");
        ob->delete_temp("wudujiaojob");
        ob->delete_temp("wudujiaook");
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
	  
        if( ob->query("family/family_name") != "五毒教")
           {
                      message_vision("$N对着$n轻轻一笑：本教弟子才能做任务。你是哪来的？\n", this_object(), ob);
                      return  "快走。";
            }
    if ((int)ob->query_skill("wudu-shengong",1) < 30 ) {
                      message_vision("$N对着$n大喝一声：你的本门内功太低了？\n", this_object(), ob);
                      return  "快走。";
    } 
if ((int)ob->query_condition("guojob2_busy"))
        return  "你刚接过任务，等会再来。";
     if(ob->query_condition("wdj2_busy"))
        return  "你刚接过任务，等会再来。";

     if(ob->query("combat_exp")<100000)
      return  "你的功夫太差了。";
        if (ob->query_temp("wdhw")) {
                command("kick " + ob->query("id"));
      return  "我不是给了你任务了吗？";
                }
        if (ob->query_temp("wdhwjob")) {
                command("kick " + ob->query("id"));
      return  "我不是给了你任务了吗？";
                }
      
	  where=names[0][random(30)];
	  ob->set_temp("wdhw",1);
	  ob->set_temp("wdhwjob",where);
          ob->apply_condition("wdj2_busy",22);
if (!ob->query_skill("wudu-shengong",1))
{
ob->apply_condition("wdj2_busy",25);
}

          obn=new(__DIR__"ling");
          obn->set("usename",ob->query("name"));
          obn->move(ob);
	  return    RED"我刚得到消息，五岳剑派，有计划要来偷袭本教。\n"+
           "          你赶快去"+where+"迎击一下吧(yingji)。\n"+
           "          如果真的有人来偷袭，消灭他们。"NOR; 
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query_temp("wdhwjob")) {
                command("sigh");
                command("say 这么点事，你都做不好，也罢，你去吧.");
          me->apply_condition("wdj2_busy",30);
destruct(present("wd lingqi",me));
       me->delete_temp("wdjob");
        me->delete_temp("wdhw");
        me->delete_temp("wdhwjob");
        return 1;
                }
}

