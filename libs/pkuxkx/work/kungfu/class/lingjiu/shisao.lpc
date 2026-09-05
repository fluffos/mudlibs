// NPC shisao.c   石嫂不收徒，准备让她分配任务
#include <ansi.h>
inherit NPC;

#include "/new_quest/qzhongli.h"
#include "/new_quest/quest.h"
//定义任务用的函数
int ask_fail();
string  ask_job();
string ask_saoxue();
string ask_finish();
string ask_xiashan();

//设置任务地点的short
mixed names = ({
        ({
        "小路","缥缈峰山脚","断魂崖","百丈涧","仙愁门",
        "山路","松林","青石大道","缥缈峰山脚","断魂崖",
        }),
//备用任务用人物名，可能以后的开放用
        ({
         "宋兵","流氓","偏将","裨将","佐将","小贩","男孩","郭芙","老先生",
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
        set_name("石嫂", ({ "shi sao", "shi", "sao" }));
        set("long",
            "她是「灵鹫宫」九天九部中朱天部的首领.\n");
        set("title", "朱天部首领");
        set("gender", "女性");
        set("age", 30);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 20);
        set("int", 25);
        set("con", 30);
        set("dex", 30);

        set("qi", 1800);
        set("max_qi", 1800);
        set("jing", 1400);
        set("max_jing", 1400);
        set("neili", 950);
        set("max_neili", 950);
        set("jiali", 50);

        set("combat_exp", 95000);
        set("score", 1000);
        set_skill("force", 95);
//      set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 95);
        set_skill("hand",100);
        set_skill("strike", 100);
        set_skill("sword",100);
        set_skill("blade",100);

        set_skill("changhen-jian",120);
        set_skill("zhemei-shou",130);
        set_skill("liuyang-zhang",150);


        set_skill("lingbo-weibu",160);
        set_skill("bahuang-gong", 150);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "lingbo-weibu");
//      map_skill("unarmed", "liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword", "changhen-jian");
		prepare_skill("strike","liuyang-zhang");

        create_family("灵鹫宫",3,"首领");
        set("inquiry", ([
//对应上面设的函数,考虑有的玩家没有GB输入，采用E文和GB两种
   					"扫雪"  : (: ask_saoxue :),
					"job"  : (: ask_saoxue :),
   					"完成"  : (: ask_finish :),
					"finish"  : (: ask_finish :),
        				"quest":   (: ask_quest() :),
        "cancelquest":   (: ask_cancel() :),
        "取消任务":   (: ask_cancel() :),
                                        "下山" : (: ask_xiashan() :),
                                        "护卫"  : (: ask_job :),
                                        "huwei"  : (: ask_job :),
					"fail" : (: ask_fail() :),
					"护卫失败" : (: ask_fail() :),
					"放弃" : (: ask_fail() :)
                        ]));
        setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/liuyedao")->wield();
        add_money("silver",40);
}

string ask_xiashan()
{
        object ob=this_player();

        if( ob->query("family/family_name") != "灵鹫宫")
                return "你不是本门弟子，问我做什么？";
        if( ob->query_skill("dodge") > 50 )
                return "你的功夫已经够高啦，不要再为这么初级的问题麻烦我了。";
        ob->set_temp("lingjiu/ask下山",1);
        return "你去铁索桥那里，有本门弟子带你下山。放心吧！";
}
string ask_saoxue()
{     
	object ob,obn;
       string where;
	ob=this_player();
	  
//不让别的门派的人做
        if( ob->query("family/family_name") != "灵鹫宫")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的奸细？\n", this_object(), ob);
                      return  "快走。";
            }
         if  ((int)ob->query("family/generation") == 3 || ob->query("score") > 1000)
{
               tell_object(ob,RANK_D->query_respect(ob) + "已是灵鹫宫首领，不必再扫雪了！\n");
                return "你还是做护卫任务吧。\n";
}
         if  ((int)ob->query("family/generation") == 2 || ob->query("score") > 1500)
{
               tell_object(ob, RANK_D->query_respect(ob) + "已是灵鹫宫总管，不必再扫雪了！\n");
                return "你还是做护卫任务吧。\n";
}
//设定每次任务时间，防止机器人过快任务，控制成长速度
     if(ob->query_condition("ljjob_busy"))
        return  "你刚接过任务，等会再来。";
//太差的不给
	  if(ob->query("combat_exp")<10000)
      return  "你的功夫太差了。";
//上次任务没完成
            if(ob->query_temp("lingjiu/saoxue"))
      return  "你不是正在干活啊!";

//取随机地点
          where=names[0][random(sizeof(names[0]))];
//玩家身上加任务标记
            ob->set_temp("lingjiu/saoxue",1);
//玩家身上加任务地点标记
	  ob->set_temp("lingjiujob",where);
            ob->apply_condition("ljjob_busy",8);
//防止高EXP玩家，用别门派任务骗EXP.
if (!ob->query_skill("bahuang-gong",1))
{
 ob->apply_condition("ljjob_busy",20);
}
//给任务道具
          obn=new(__DIR__"saozhou");
          obn->move(ob);
	  return    WHT"我刚得到消息，外面雪下的太大，把路给堵了。\n"+
           "          你赶快去"HIG+where+WHT"扫一下雪吧(saoxue)。\n"+
           "          可能有别的门派的人来挑衅，多加小心。"NOR; 
}

string ask_finish()
{     
	object ob,obn;
       string where;
	ob=this_player();
	  
//没有要过任务
        if(!ob->query_temp("lingjiu/saoxue"))
      return  "我没叫你干过活啊!";
//上次任务没有结束??
	  if(!ob->query_temp("lingjiuok"))
      return  "你的活没干完啊!";
//删除上次任务标志
        ob->delete_temp("lingjiu");
        ob->delete_temp("lingjiujob");
        ob->delete_temp("lingjiuok");
//奖励
        ob->add("combat_exp",10+random(120));
        ob->add("potential",10+random(40));
        ob->add("score",random(10)+1);
	  return    HIW"做得好，。\n"+
           "          我指点你二手功夫吧。\n"+
           "          你的忠诚度增加了。\n"+
           "          你的经验和潜能增加了!"NOR; 
}


string ask_job()
{     
	object ob,obn;
       string where;
	ob=this_player();
//同上	  
/*
        if( ob->query("family/family_name") != "灵鹫宫")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的奸细？\n", this_object(), ob);
                      return  "快走。";
            }

*/
     if(ob->query_condition("ljjob2_busy"))
        return  "你刚接过任务，等会再来。";

     if(ob->query("combat_exp")<250000)
      return  "你的功夫太差了。";
     if(ob->query("mud_age") < 86400)
      return  "你年龄尚小，作这种任务未免太危险了。";
    if (ob->query("combat_exp") > 1000000)
	     return "你的经验已经够高了，不敢劳您护卫。";
	 if (ob->query("antirobot/deactivity") > 4)
	 {
		 return "我看你魂不守舍，心不在焉，实在不能让我放心。你的心思飞到哪里去了？";
	 }
     if (time()-ob->query("huwei_last_time")<180+random(10))//加入3分钟cd时间 By Zine Nov 10 2010
     {
         return "你刚做完任务，等会再来。";
     }
     if (ob->query_temp("ljhw")) {
                command("kick " + ob->query("id"));
      return  "我不是给了你任务了吗？";
                }
     if (ob->query_temp("ljhwjob")) {
                command("kick " + ob->query("id"));
      return  "我不是给了你任务了吗？";
                }
     if (ob->query("antirobot/deactivity") > 2) message("vision",HIR"石嫂满脸狐疑的嘟囔着：“怎么老是你！我看你是机器人吧。”\n"NOR,ob);
        
      
//          where=names[0][sizeof(names[0])];
          where=names[0][random(sizeof(names[0]))];
	  ob->set_temp("ljhw",1);
	  ob->set_temp("ljhwjob",where);
          ob->apply_condition("ljjob2_busy",5);
          ob->set("huwei_last_time",time());
	if (!ob->query_skill("bahuang-gong",1))
	{
 		ob->apply_condition("ljjob2_busy",10);
	}
//以上代码同上
//给任务道具
          obn=new(__DIR__"ling");
//防止任务道具，互相交换使用
          obn->set("userid",ob->query("id"));
          obn->move(ob);
	  return    "我刚得到消息，所谓的名门正派，来了几个人挑战我派。\n"+
           "          你赶快去"+where+"护卫一下吧(huwei)。\n"+
           "          如果真的有人来挑战，消灭他们。"; 
}

int ask_fail()
{
        object me = this_player();
//         int sc = random(36)+5;
//         int rep = random(900) + 100;
         int sc = random(12)+1;
         int rep = random(300) + 33;

        if (me->query_temp("ljhwjob")) {
                command("sigh");
                command("say 这么点事，你都做不好，也罢，你去吧.");
//删除任务道具，并去除身上的标记。
       destruct(present("lj lingpai",me));
        me->delete_temp("ljhw");
        me->delete_temp("ljhwjob");
        if (me->query("family/family_name") == "灵鹫宫")
        {
          me->add("score",-sc);
         tell_object(me,"你对灵鹫宫的忠诚度降低了"+chinese_number(sc)+"点。\n");
        }
        else 
        {
        me->add("repute", - rep );
        tell_object(me,"你的武林声望降低了"+chinese_number(rep)+"点。\n");
        }
        return 1;
                }
}

