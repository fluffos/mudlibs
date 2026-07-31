 // mind_beast.c
inherit NPC;
#include <ansi.h>
string horsedesc();
void create()
{
    set_name("黑骏马", ({ "black horse" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 3);
    //set("long", "一匹皮毛黑亮的野马，自由自在的撒蹄飞奔着，不知是否可以驯服（ｘｕｎｆｕ）。\n");
        set("long",(: horsedesc :));
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("max_jing", 3000);
                set("int",40);
        set("cor",80);
        set("str",50);
        set("attitude", "peaceful");
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "hoof"}) ); 
        set("chat_chance", 1);
        set("chat_msg", ({
     "黑骏马＂咴～～咴咴＂地仰天长了几声\n",
        }) );
        set("combat_exp", 3000000);
        set_temp("apply/attack", 300);
        set_temp("apply/armor", 100);
        set_temp("apply/dodge",300);
        set_temp("apply/damage",200);
        setup();
}
void init()
{
        add_action("do_xunfu","xunfu");
        add_action("do_ride","ride");
}
string horsedesc()
{
        object me;
   me = this_player();
        if (me ->query_temp("marks/驯服_黑骏马"))
        {       
                return "怒江无船无人，你只有骑上（ride）这野马跃过怒江！";
        }
        return "一匹皮毛黑亮的野马，自由自在的撒蹄飞奔着，不知是否可以驯服（ｘｕｎｆｕ）。\n";
} 
int do_xunfu(string arg)
{
        object me;
        if (arg != "黑骏马" && arg != "black horse" && arg != "野马")
        {       
                return 0;
        }
        me = this_player();
        if (me->query_temp("marks/驯服_黑骏马"))
        {
                return 0;
        }
        
        message_vision("$N长嘶一声，扬尾踏足，乱踢狂奔，硬是要把$n扔下来。。。 \n",this_object(),me);
        if ((me->query_skill("dodge",1)>=50 && me->query("cor")>=10 && me->query("kar")>=(10+random(10)))||me->query_skill("animal-training",1)>=80)
        {
        message_vision(HIC"$n紧紧抓住马鬃，无论$N如何撩蹄打撅，稳如泰山般附在马背。\n "NOR,this_object(),me);
        message_vision("$N终于安静了下来，驯服地喘着粗气。。\n$n满意地拍了拍$N的头，从马上跃了下来。\n",this_object(),me);
                if (!me->query("marks/驯服_野马"))
                {
                        me->add("potential",500);
                        me->add("score",100);
                        tell_object(me,"你被奖励了：\n五百点潜能\n一百点综合评价\n\n");
                        me->set("marks/驯服_野马",1);
                }
                me->set_temp("marks/驯服_黑骏马",1);
        }else
        {
                message_vision("$n终于不支，从$N背上摔了下来。\n",this_object(),me);
                me->unconcious();
        }
        return 1;
} 
int do_ride(string arg)
{
        object me;
        if (arg != "黑骏马" && arg != "black horse" && arg != "野马")
        {       
                return 0;
        }
        me = this_player();
        if (!me->query_temp("marks/驯服_黑骏马"))
        {
                return 0;
        }
        message_vision(HIC"$n骑上马背，仰天长啸一声，抱紧马颈，双腿夹紧马腹，用力一鞭$N。。 。\n\n"NOR,this_object(),me);
        if (random(10))
        {
                message_vision(HIW"$N凌空跃起，以一个动人心弦、超越了世间一切美态的姿势，颈后的黑鬃毛 
在山风中自由地飘扬，有若天马行空，在天空里划出一条美丽的弧线，再落下至 
远方的浓雾里。 \n"NOR,this_object(),me);
                me->move("/d/xizang/yuema");
                message_vision("$N宛若神祗，乘着黑骏马从天而降。\n",me);
                message_vision("$N跃下马背，黑骏马踏风而去。\n",me);
        }else
        {
        message_vision(RED"$N凌空跃起，竭尽全力往前跳，但终于力所不至，悲嘶一声，坠入怒江。\n"NOR,this_object());
                message_vision(RED"在坠落的一刹那，$N后背拱起，而后四蹄奋张，积最后一丝力量将$n弹上悬崖。\n",this_object(),me);
                if(random(10))
                {
                        me->unconcious();
                }else
                {
                        me->die();
                }
        }
        destruct(this_object());
        return 1;
} 
