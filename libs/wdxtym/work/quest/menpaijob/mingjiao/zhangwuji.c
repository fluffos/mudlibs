//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
int ask_job2();
int ask_fail2();

mixed jobs = ({
        ({
"我锐金旗在教内负责采矿炼铁，最近上等精铁快用完了，需要采集铁矿",
"你来的正好，兄弟们演练阵法，巨木不够了，你去树林里砍些树干扛回来",
"咱们厚土旗负责挖地道，将来会有大用场。你去跟弟兄们一起将地道挖深点",
"我洪水旗在教内负责制造毒水，最近冰水快用完了，你去碧水寒潭取些水来",
"兄弟们辛辛苦苦炼出来一些精铁，你去用它好好打造火枪",
        }),
        ({
         "小昭","杨逍","范遥","殷天正","谢逊","冷谦","彭莹玉","周颠","张中",
	"说不得","庄铮","闻苍松","唐洋","辛然","颜垣","殷野王","殷素素",
	 "李天垣","程嘲风","高山王","常金鹏","白龟寿","封弓影","胡青牛","庄铮",
	 "闻苍松","唐洋","辛然","颜垣","庄铮","闻苍松","唐洋","辛然",
        }),
        });
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
    set("str", 86);
    set("int", 86);
    set("con", 80);
    set("dex", 80);

    set("qi", 19050);
    set("max_qi", 19050);
    set("jing", 19050);
    set("max_jing", 19050);
    set("neili", 38000);
    set("max_neili", 38000);
    set("jiali", 120);

    set("combat_exp", 9900000);
    set("score", 455000);

    set_skill("force", 250);
    set_skill("unarmed", 250);
    set_skill("dodge", 250);
    set_skill("parry", 250);
    set_skill("hand",250);
    set_skill("sword",250);
    set_skill("blade", 250);
    set_skill("cuff", 300);
    set_skill("strike", 300);
    set_skill("qingfu-shenfa", 380);
    set_skill("hanbing-mianzhang", 380);
    set_skill("sougu", 380);
    set_skill("jiuyang-shengong", 390);
    set_skill("qiankun-danuoyi", 380);
    set_skill("qishang-quan", 380);
    set_skill("shenghuo-shengong", 380);
    set_skill("taiji-quan",150);
    set_skill("taiji-jian",150);
    set_skill("taiji-dao",150);
    set_skill("shenghuo-ling",380);
set("jiuyangok",1);
    map_skill("force", "jiuyang-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "jiuyang-shengong");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","jiuyang-shengong");
    map_skill("blade","jiuyang-shengong");

    create_family("明教",34, "教主");

    set("chat_chance",2);
    set("chat_msg",({
 "张无忌愤然说道“大丈夫当以国为家, 捐躯沙场, 抗元大业未成, 同辈仍需努力!”\n",
        "张无忌叹道“人生失一知己, 生亦何欢, 死亦何忧, 敏儿, 你在哪里?”\n",
        "张无忌道“我教兄弟听了: 生于乱世, 当克己为公, 行侠仗义, 荡寇驱魔!”\n",
//        	(: random_move :)
    }));

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.can" :),
                (: perform_action, "sword.hua" :),
                (: perform_action, "unarmed.hun" :),
                (: perform_action, "unarmed.jiu" :),
                (: perform_action, "unarmed.ri" :),
                (: perform_action, "unarmed.pi" :),
                (: perform_action, "unarmed.po" :),
                (: command("unwield ling") :),
                (: command("exert shield") :),
                (: command("wield ling") :),
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
                "练兵" : (: ask_job2() :),
                "mjjob" : (: ask_job2() :),
                "不练兵了" : (: ask_fail2() :),
                "fail" : (: ask_fail2() :),


    ]));
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);
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
   if(obj->query("id") == "ling qi" && me->query("mjjob") == 1
   && obj->query_temp("host")==me->query("id"))
   {
       command("nod "+(string)me->query("id"));
       command("say 干得好！\n");
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);
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
   if (kar > 450) kar = 450;
   exp = 500 + kar;
   pot = 400 + kar;

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
		//destruct(present("ling qi",ob));
   	        me->apply_condition("mingjiaojob",0);
//
//                me->delete("quest");
                me->delete("mjjob");
   return;
}

int ask_job2()
{

        object me = this_player();
        object ob;
string skl,tar;

        skl = me->query_skills();

        if( me->query("family/family_name") != "明教")
           {
                      message_vision("$N对着$n说道。这种事可以有劳别人带行？\n", this_object(), me);
                      return 1;
            }

        if ( !skl ) {
                tell_object(me, "你去学一些本事先吧！\n");
                return 1;
                }

if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N对着$n说:现在没有任务,你等会再来吧!\n", this_object(), me);
                      return 1;
            }
        if ((int)me->query_condition("mj2_busy"))
            {
                      message_vision("$N对着$n摇了摇头说：你刚要过任务,等会再来!\n", this_object(), me);
                      return 1;
            }

        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say 你的潜能太少了!!");
                return 1;
        }

        if (me->query_temp("mj2job")) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {

tar = jobs[1][random(sizeof(jobs[1]))];
skl = jobs[0][random(sizeof(jobs[0]))];
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "  我教目的在与反抗元兵，现在正在练兵  ?");
                command("say " + me->query("id") + " 『" + skl  + "』！" NOR);
                command("say " + me->query("id") + "  我教『" + tar  + "』正在做这件事，你去协助(xiezhu)他吧！" NOR);
        me->delete_temp("mjjob2");
                me->set_temp("mj2job", tar);
                ob = new(__DIR__"ling");
                ob->set("usename",me->query("name"));
                ob->move(me);
                command("say " + me->query("id") + "  这个五行旗，你拿好，凭这个去做吧！" NOR);
                return 1;
               }
}

int ask_fail2()
{
        object me = this_player();

        if (me->query_temp("mj2job")) {
                command("sigh");
                command("say 这么点事，你都做不好，也罢，你去吧.");
                me->apply_condition("mj2_busy", 5 +
                        (int)me->query_condition("mj2_busy"));

me->delete_temp("mj2job");
me->delete_temp("mj2skl");
me->delete_temp("mj2jobs");
                return 1;
                }
}
