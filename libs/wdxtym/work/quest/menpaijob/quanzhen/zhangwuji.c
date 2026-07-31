//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
#include "teamjob.c"
void greeting(object ob);
void create()
{
    seteuid(getuid());
    set_name("张无忌", ({ "zhang wuji", "zhang", "wuji" }));
    set("long", "明教教主张无忌，统领天下十万教众，豪气干云，叱咤千秋，\n"
               +"「九阳神功」、「乾坤大挪移」独步天下，是江湖中不世出的\n"
               +"少年英雄。\n");
    set("title",HIG "明教"HIM"教主"NOR);
    set("gender", "男性");
    set("age", 20);
    set("shen_type",1);
    set("attitude", "friendly");
    set("class", "fighter");

    set("per", 28);
    set("str", 36);
    set("int", 36);
    set("con", 30);
    set("dex", 30);

    set("qi", 4050);
    set("max_qi", 4050);
    set("jing", 4050);
    set("max_jing", 4050);
    set("neili", 18000);
    set("max_neili", 18000);
    set("jiali", 120);

    set("combat_exp", 9900000);
    set("score", 455000);
    
    set_skill("force", 250);
    set_skill("unarmed", 200);
    set_skill("dodge", 200);
    set_skill("parry", 220);
    set_skill("hand",200);
    set_skill("sword",250);
    set_skill("blade", 200);
    set_skill("cuff", 250);
    set_skill("jiuyang-shengong", 300);
    set_skill("qiankun-danuoyi", 300);
    set_skill("qishang-quan", 300);
    set_skill("shenghuo-shengong", 300);
    set_skill("taiji-quan",150);
    set_skill("taiji-jian",150);
    set_skill("taiji-dao",150);
    set_skill("shenghuo-ling",300);

    map_skill("force", "shenghuo-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "qishang-quan");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","shenghuo-ling");
    map_skill("blade","taiji-dao");

    create_family("明教",34, "教主");

    set("chat_chance",2);
    set("chat_msg",({
 "张无忌愤然说道“大丈夫当以国为家, 捐躯沙场, 抗元大业未成, 同辈仍需努力!”\n",
        "张无忌叹道“人生失一知己, 生亦何欢, 死亦何忧, 敏儿, 你在哪里?”\n",
        "张无忌道“我教兄弟听了: 生于乱世, 当克己为公, 行侠仗义, 荡寇驱魔!”\n",
//        	(: random_move :)
    }));

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),                
                (: command("unwield ling") :),
                (: command("unwield ling") :),
                (: command("wield ling") :),
                (: command("wield ling") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
    set("inquiry",([
	  "明教" :     "明教正在编写之中，请君稍候。\n",
          "金毛狮王" : "那是我义父谢大侠的职司。\n",
          "谢逊" :     "他就是我义父的大号。\n",
          "张翠山" :   "你想找我父亲有事麽? \n",
          "殷素素" :   "我妈是明尊座下紫微堂主。\n",
          "张三丰" :   "我太师父近来可好? \n",
          "赵敏" :     "人生失一知己, 生亦何欢, 死亦何忧, 敏儿, 你在哪里?\n",
          "小昭" :     "小昭我可一直念着她的好处。\n",
          "周芷若" :   "找她就去峨嵋山, 别来烦我。\n",
		 "job"  : (: ask_jianxi :),
    ]));
    setup();
    carry_object("/d/mingjiao/obj/yitianjian");
    carry_object("/clone/book/shenghuo-ling")->wield();
//    	carry_object("/d/mingjiao/obj/jiaozhumingpao")->wear();
    add_money("silver",70);
}

void init()
{
	object ob;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000)
	{
//      command("say
	command("wield yitian jian");
	command("hit"+(string)ob->query("id"));
        command("unwield yitian jian");
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say 魔从心起，于武学不利，其道必诛，劝君放下屠刀，立地成佛.");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say 这位朋友，人行江湖，言行当正，切务走进邪魔歪道.");
	}
	else if((int)ob->query("shen")>=0)
	{
		command("say 光明正道任人走，劝君多加保重.");
	}
	else if((int)ob->query("shen")>10000)
	{
		command("say 大侠在上，受无忌一礼，大侠它日必为武林翘楚.");
	}
	return;
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say 你的悟性太低了，不适合学习我的功夫。");
		return 0;
	}
	if((string)ob->query("gender")=="无性")
	{
		command("say 你阳气不足，习我功夫恐将走火如魔。");
		return 0;
	}
	if((int)ob->query("shen") <= 15000)
	{
		command("say 你应当多作些行侠仗义的事，以修身心。");
		return 0;
	}
	command("say 好，我就收下你这位好徒弟！");
	command("say 你的职司就是本教的光明使者。");
	command("recruit " + ob->query("id"));
	ob->set("title", HIR"明教使者"NOR);
	return;
}

int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
    {
        message_vision("武林中人最忌争强斗狠，你不是我的对手，回去吧。\n",ob);
        return 0;
    }
    message_vision("张无忌一拱手说道：这位"+RANK_D->query_respect(ob)+
	"，在下领教了。\n", ob);
    return 1;
}

int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("你没有这件东西。");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say 你拿个快死的人来骗我？");
       return 0;
       }
   if(obj->query("id") == "lingqi" && me->query("mjjob") == 1)
   {
       command("nod "+(string)me->query("id"));
       command("say 干得好！\n");
       remove_call_out("destroying");
       call_out("destroying", 5, obj, ob, me);                       
       return 1;
       }
    if(me->query("mjjob") == 0 ){
       command("hehe "+(string)me->query("id"));
       command("say 不错啊，但这活我没叫你干啊。");
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say 我要钱干什么?");
       return 0;
       }
   else return 0;       
}

void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot;
   kar = random(me->query("kar")) * 15;
   if (kar > 400) kar = 400;
   exp = 550 + kar;
   pot = 350 + kar;

   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N对$n说道：你这次做得极为出色！我就指点你两手功夫吧.\n"NOR,ob, me);
                  message_vision(HIC "\n由于$N成功的消灭了五大门派的人马，被奖励：\n"
                + chinese_number(exp) + "点实战修为，\n"
                + chinese_number(pot) + "点潜能，\n"
                + chinese_number(50) + "点评价作为答谢。\n" NOR, me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("score",50);
                ckiller=3;
   	        me->apply_condition("mingjiaojob",0);
                ob->apply_condition("mingjiaojob",0);
//
//                me->delete("quest");
                me->delete("mjjob");
   return;      
}