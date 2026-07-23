//dadi.c 任务使
// [lsg 1999/11/24]

inherit NPC;
#define QUEST_KILL __DIR__"quest"  
string ask_me();
#include <ansi.h>;
mixed rooms = ({
        ({
        "少林广场","王府路","华藏庵","有所不为轩","紫霄宫大门",
        "天微堂","日月坪","大雪山山谷","六和塔","全真教大门", 
        "墓门","桃花山庄正厅","神龙教大厅","独尊厅","星宿海", 
        "雪山寺山门","一品堂大院","昆仑派山门","燕子坞","五指堂", 
        "朱雀外门","青龙外门","白虎外门","玄武外门","天安门",
        "扬州武馆","福威镖局","玄妙观","灵隐寺","泉州南门",
        "灵州南门","诸葛亮殿","烟雨楼","南阳城","佛山南门",                
        "蛇骨塔","长安乐坊","衡阳西街","喜州城","葛鲁城", 
        "伊犁","山海关","老龙头","长白天池","天山脚下",
        "丽春院","涌泉寺","听雨轩","五老峰","紫金城",
        "松风观","终南山脚","抱子岩","白马潭","升仙坊",                
        "嘉应门","玄妙观","峻极禅院","侠义厅","萧家桥", 
        "凌霄内门","凌霄殿","桃花江东","五毒教大门","天心岩",
        "嘉峪关","丝绸之路","长白天池","黑风口","龙门峰",
        "南城","土窑馆","萧然居"," 铁木真部落","铁木真营帐",
        "蒙古草原","回族部落","小溪流","鳌拜府","王府井大街",
        "塘沽口","汝州城"," 永定门","山贼窝","草莓地",
        "长安乐坊","十字街头","长安城西门","乐府诗社","浣花溪",
        "蓉城酒楼","金牛武馆","锦城驿","南诏德化碑","剑川镇",
        "玉虚观","星云湖畔","鲁望镇","喜州城","太和街口",
        "葛鲁城","圣湖","忘忧谷","大雪山北麓","华严顶",
        "凌云梯","十二盘","佛山镇街","英雄会馆","北帝庙",
        "福威镖局","榕城驿","向阳巷老宅","终南山主峰","寒水潭",
        "太湖","南浔镇","净慈寺","胡庆余堂","保淑塔",
        "风雷堂","圣姑堂","青龙堂大厅","成德殿","平定州",
        "见性峰","大字岭","悬空寺","衡阳西街","刘府大院",
        "玄坛庙","打谷场","群仙观","莲花峰","莎萝坪",
        "五佛寺","古浪","黄河帮寨门","黄土高原","青城",
        "悦来客栈","归来客栈","太和殿","泰和殿","养心殿",
        "天师洞","松风观","泉州南门","神龙教大厅","峻极禅院",
        "嵩岳寺塔","万景山庄","沧浪亭","紫金庵","寒山寺",
        "玉皇顶","岱宗坊","桃花轩","般若台","清都瑶池",
        "澜沧江畔","武当玄岳门","遇真宫","紫霄宫门","朝天宫",
        "观景楼","望云台","安抚使衙门","玄武门外门","朱雀门外门",
        "日月洞","逍遥洞","雪山祭坛","雪山寺山门","观星台",
        "燕子坞","听香水榭","扬州武馆","丽春院","草堂寺",
        "终南山脚","普光寺","重阳宫大门","祝融殿","福严寺",
        "缥缈峰山脚","独尊厅","琴心小筑","昆仑山门","迎风酒店",
        "五指堂","中指峰","无名峰","拇指峰","太白酒楼",
        "燕京城门","赵王府","冰火岛海滩","灵獒宫","巴颜喀拉山",
        "响琴榭","居庸关","星星峡","暖阁","皇宫正门",
        }),
        });
int time_period(int timep,object me);
void create()
{
        set_name(HIR"指挥使"NOR, ({ "zhihuishi", "shi", "renwu"}));
        set("title", HIW"玩家帮派"NOR);
        set("gender", "男性" );
set_temp("no_kill",1);
set("no_get",1);
        set("age", 82);
        set("str", 900);
        set("int", 225);
        set("con", 230);
        set("dex", 250);
        set("per", 230);
        set("long", 
"一位的长老。专门负责给本派弟子各种任务.\n");
        set("combat_exp", 50000000);
        set("shen_type", 1);

        set("attitude", "peaceful");
        set("max_qi", 35000);
        set("max_jing", 10000);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jiali", 200);
        
        set_skill("force", 300);
        set_skill("zhemei-shou", 300);
        set_skill("unarmed", 500);
        set_skill("xiantian-qigong", 500);

         map_skill("unarmed","zhemei-shou");
       map_skill("force","xiantian-qigong");
        
        set("inquiry", ([
              "job"  : "本派弟子可以在我这用job来为本门做事。\n",       
                "练功" : (: ask_me :),
          "liangong" : (: ask_me :),
]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();

}
void init()
{
        add_action("do_work", "liangong");
        add_action("give_quest", "job");
}

int give_quest()
{
        mapping quest ;
        object me;
        int combatexp, timep;
        string room;
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
                if (me->is_busy())
                        return notify_fail("你正忙着呢。\n");
                if (this_object()->is_busy())
                        return notify_fail("我正忙着呢。\n");


        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你办事不利,等会再来!\n", this_object(), me);
                      return 1;
            }
        if (me->query("playerjob")==1)  
            {
                      message_vision("$N对着$n说:你身上的任务还没完成呢!\n", this_object(), me);
                      return 1;
            }
        if(combatexp<100000)
        {
tell_object(me,"\n指挥使说到，你的武功还不行....”\n");
             return 1;

        }

        if(me->query("questjob"))
        {
tell_object(me,"指挥使瞪了你一眼说道，你上一个任务还没完成呢!\n");
             
        }

if (random(2)==1
||me->query_temp("roomjob"))
{
        quest = QUEST_KILL->query_quest();
             tell_object(me,HIR"『"+quest["quest"]+HIC"』最近对我们不利，去教训他们一下。\n" NOR);

        me->set("questjob", quest["quest"]);
        me->set("playerjob", 1);
        return 1;
}
else {
	  room=rooms[0][random(205)];
          me->apply_condition("roomjob",8);
	  me->set_temp("roomjob",room);
	  tell_object(me,HIG"我听说在『"HIR+room+HIG"』，发生了一些江湖事件。\n"+
           "你赶快去『"HIY+room+HIG"』刺探(citan)一下吧。\n"+
           "路上多加小心。\n"NOR);
return 1;
}
}


int accept_object(object who, object ob)
{
        int bonus, exp, pot, score;
        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("questjob"))
             {
                  tell_object(who,"没找到？你真差劲，看来还是请别的弟子帮忙算了！\n");
                   who->apply_condition("menpai_busy",4+random(8));
                   who->set("questjob",0);
                    who->delete("questjob");
                   who->delete_temp("roomjob");
                   who->set("playerjob", 0);
                   return 1;
             }
       if ( ob->value() < 2000)
             {
tell_object(who,"指挥使看了看$P交上来的钱说道，太少了，这么点你也好意思拿出手！\n");
                   return 1;
             }
             else
             {

tell_object(who,"指挥使说道，好吧，这次就算了，下不为例。\n");
                   who->apply_condition("menpai_busy",4+random(8));
                   who->set("questjob",0);
                   who->delete("questjob");
                   who->delete_temp("roomjob");
                   who->set("playerjob", 0);
                  return 1;
             }
        }
        if(!who->query("questjob"))
        {
             tell_object(who,"指挥使说道：我没有叫你做事啊。\n");
             return 0;
        }

	if( userp(ob) ) {
        tell_object(who,"指挥使火冒三丈：这是什么？想鱼目浑珠呀，真是气死我了！\n");
        return 0;
        }

	if( !ob->is_character() ) {
        tell_object(who,"指挥使火冒三丈：这是什么？想鱼目浑珠呀，真是气死我了！\n");
        return 0;
        }

        if( ob->query("family/family_name") != who->query("questjob"))
        {
        tell_object(who,"指挥使说：这是什么？想鱼目浑珠呀，真是气死我了！\n");
        return 0;
        }

        else
        {
             tell_object(who,"指挥使高兴地说道：做得好，光大了本门。！\n");
             exp = 200 + random(200);
             pot = 150 + random(150);
             score = 10 + random(15);

             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"恭喜你扩大了本门的影响！\n"NOR);
             tell_object(who,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战经验，\n"+ chinese_number(pot) + "点潜能，\n"
               + chinese_number(score)+"点江湖阅历。\n"NOR);
             who->set("questjob", 0 );
             who->delete("questjob");
             who->set("playerjob", 0);
this_object()->start_busy(4);
who->start_busy(3);
	if( ob->is_character() ) {
       call_out("destroying", 0,ob);                              
	}
}
        return 1;
}
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "指挥使狞笑着说：我是无敌不死版！\n");
	command("hehe");
}

void die()
{
	unconcious();
}

void destroying(object ob)
{   
   destruct(ob);
}
int do_work()
{
        object me, ob, weapon;
        me=this_player();

if (me->query("qi") <30)
                return notify_fail("你的气不够了。");
if (me->query("jing") <30)
                return notify_fail("你的精不够了。");

        if (me->query_temp("player_working")) {
                if (me->is_busy())
                        return notify_fail("你正忙着呢。\n");

                tell_object(me, HIC"你和指挥使一招一式的对练了起来。\n"NOR);

                        message_vision(HIR"$N左一拳，右一掌，打的大汗淋漓。\n"NOR, me);
                        me->add("jing",-me->query("max_jing")/50);
                        me->add("qi", -me->query("max_qi")/50);
                        me->set_temp("working_times",me->query_temp("working_times")+1);
                        me->start_busy(1);

                if (me->query_temp("working_times")>=me->query_temp("player_working"))
                {
                        message_vision(HIC"指挥使对$N点点头，满意地说：“够了，够了，今天就练到这里吧。\n"NOR, me);
                        message_vision(HIG"指挥使对$N竖起大拇指：“你如此勤勉，将来必能成材。\n"NOR, me);
                        me->delete_temp("working_times");
                        me->delete_temp("player_working");
                        me->add("combat_exp", random(22)+18);
                        me->add("potential", random(12)+15);
                        me->start_busy(3);
                }
                return 1;
        }
        return 0;
}

string ask_me()
{
        object me;
        me=this_player();

        if (me->query_temp("player_working"))
                return "你不是和我练着吗。";

                if (me->is_busy())
                        return "你正忙着呢。";

        me->set_temp("player_working",random(20)+10);
        me->set_temp("working_times",0);
        return "好我就陪你练功(liangong)吧。";
}
