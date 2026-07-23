// wei.c

inherit NPC;
//inherit F_SKILL;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
	set_name("韦小宝", ({ "wei xiaobao", "wei", "xiaobao" }));
	set("title", HIC"大清国抚远大将军"HIY"一等鹿鼎公"NOR);
	set("gender", "男性");
	set("age", 18);
	set("str", 20);
	set("int", 30);
	set("con", 30);
	set("dex", 20);
	set("per", 28);
	set("long", 
"这位少年将军头戴红顶子，身穿黄马褂，眉花眼笑，贼忒兮
兮，左手轻摇羽扇，宛若诸葛之亮，右手倒拖大刀，俨然关
云之长，正乃韦公小宝是也。见你看着他，“哈哈哈”，仰
天大笑三声，学足了戏文中曹操的模样，你顿时忍不住凑个
趣，问一句：“将军为何发笑？”\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");
        set("max_qi", 2500);
        set("max_jing", 1000);
        set("neili", 500);
        set("max_neili", 500);
	set("jiali", 50);

        set_skill("force", 20);
        set_skill("parry", 20);
        set_skill("hand", 20);
        set_skill("dodge", 20);
        set_skill("shenxing-baibian", 20);
        set_skill("yunlong-shengong", 20);
        set_skill("qianye-shou", 90);

        map_skill("force", "yunlong-shengong");
        map_skill("parry", "qianye-shou");
        map_skill("dodge", "shenxing-baibian");
        map_skill("hand", "qianye-shou");
        prepare_skill("hand", "qianye-shou");
        set("inquiry", ([
            "天地会"  : "别烦我！\n",
            "陈近南"  : "那是我师父！\n",
            "茅十八"  : "就是那十八个毛虫啊？他还没死吧！\n",
            "独臂神尼": "那是我美貌尼姑师父！\n",
            "韦春芳"  : "我娘做婊子生意越来越差了，现在改行作老鸨了！\n",
            "康熙"    : "那是我皇帝师父！\n",
            "小玄子"  : "那是我皇帝师父！\n",
            "小桂子"  : "别提这个名字了，我怕怕！\n",
            "阿珂"    : "她是我明媒正娶的大老婆！\n",
            "双儿"    : "你认识她？大功告成，亲个嘴儿！\n",
            "曾柔"    : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
            "方怡"    : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
            "苏荃"    : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
            "沐剑屏"  : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
            "建宁公主": "这个骚娘皮，亲厚不及双儿、美貌不及阿珂、武功不
及苏荃、机巧不及方怡、天真纯善不及沐剑屏、温柔斯文不及曾柔，
差有一日之长者，不过横蛮泼辣而已！\n",
        ]) );

	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}

void init()
{
        add_action("give_quest", "quest");
}

int give_quest()
{
        mapping quest ;
        object me,ob;
        int j, combatexp, timep,factor,num;
        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                        "2000000"

        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
        if(combatexp<10000)
        {
message_vision("韦小宝对$N哼了一声道：“辣块妈妈，东西还没长齐想干嘛？”\n",me);
             return 1;
        }
	if(combatexp>1000000)
        {
message_vision("韦小宝对$N哼了一声道：“你武功太高了，已经没有适合给你的任务了。”\n",me);
             return 1;
        }
        if(combatexp>500000)
{
        combatexp = (int) (me->query("combat_exp")*2);
}

        if ((int)me->query_condition("hxsd_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你办事不利,等会再来!\n", this_object(), me);
                      return 1;
            }

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
message_vision("韦小宝对$N笑道：说你不行吧，还不服气？\n", me);
message_vision("韦小宝瞟了$N一眼说道：你要是没本事，就拿点儿钱买就得了。\n",me);
                   return 0;
             }
             else
             {
message_vision("韦小宝对着$N叹了一口气：没关系去拿别的也成。\n", me);
                   me->add("qi",-(int)(me->query("qi")/10));
                   me->delete("songxin");
             }
        }

        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];
        quest = QUESTW_D(tag)->query_quest();
        timep = quest["time"];

 //       while (quest["quest_type"] == "杀")
 //       {
 //       quest = QUEST_D(tag)->query_quest();
 //       timep = quest["time"];
 //       }

        time_period(timep, me);
        if(quest["quest_type"]=="杀")
             tell_object(me,"先替我把『"+quest["quest"]+HIW"』抓回来，我想看看他长得啥模样。\n" NOR);
        else
             tell_object(me,"找到『"+quest["quest"]+HIW"』给我，我会好好谢你。\n" NOR);
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];

        me->set("quest", quest);
//                   if (ob = present("xin", this_player()))
//                   {
//                   destruct(ob);     
//                   }
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIW "韦小宝吩咐道：给你在" + time + "内");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("quest"))
             {
                   message_vision("韦小宝笑道：那我可就不客气了。\n",who);
                   return 1;
             }
             if (who->query("songxin"))
             {
                   message_vision("你这家伙，明明是接的送信任务，怎么到我这儿来取消？银子没收！\n",who);
                   return 1;
             }
             else
             if ( ob->value() < 2000)
             {
message_vision("韦小宝一双尖针般的眼睛直盯着$N：这点钱可不够我们的开销！\n", who);
                   return 1;
             }
             else
             {
message_vision("韦小宝笑道：那好，咱们买卖不成仁义在。想要好处再找我吧！\n",who);
                   who->set("quest",0);
                                      who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   who->apply_condition("menpai_busy",5);
                   who->apply_condition("hxsd_busy",1+random(5));
                   return 1;
             }
        }

        if(!(quest =  who->query("quest")))
        {
             tell_object(who,"韦小宝说道：这不是我想要的。\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
             tell_object(who,"韦小宝说道：这是什么东西？我叫你办的事你就这样糊弄我？！\n");
             return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"韦小宝说道：真是废物！你没有在指定的时间内回来！\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"韦小宝赞许地点头说道：不错！差使办得还不错！\n");
             exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"])+20;
             pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"])+10;
             score = quest["score"]/2 + random(quest["score"]);
             factor=who->query("quest_factor");
             destruct(ob);

             if (factor)
             {
                  exp=exp*factor/10;
                  pot=pot*factor/10;
                  score=score*factor/10;
             }
             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             if( bonus > 100000) bonus = 100000;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战经验，"+ chinese_number(pot) + "点潜能，"
               + chinese_number(score)+"点江湖阅历。\n"NOR);
             who->set("quest", 0 );
             tell_object(who,HIW"恭喜你完成一个差使！\n"NOR);
             return 0;
        }
        return 1;
}
