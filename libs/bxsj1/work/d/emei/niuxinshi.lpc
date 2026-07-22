// niuxinshi.c
// 牛心石

#include <ansi.h>
inherit ROOM;
int dazuo(object me);
int halt_dazuo(object me);
void create()
{
        set("short", HIY "牛心石" NOR);
        set("long",@long
你落脚处乃是块黑褐色的巨石，黑龙白龙二江在此和流。水拍牛心，
浪花飞溅，声震山谷。你立于此，眼望两江之水从脚下奔腾而过，不由心
魂飞荡，两腿发软，不可自持。
long);
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_jump", "tiao");
        add_action("do_dazuo", "lianneili");
}

int do_jump(string arg)
{
        object me = this_player();
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n");

        if(!arg || arg == "" || arg != "back")
        return notify_fail("你要跳什么？\n");
        
        if( arg == "back") {
              me->move(__DIR__"qingyinge");
              me->receive_damage("jingli", 200);
              message_vision("$N从牛心石跳了过来。\n", me); 
              me->start_busy(2);
              return 1; 
        }
}


int do_dazuo(string arg)
{     
        int qzdazuo_cost,neili_limit;
// mapping fam;
        object me;
        me = this_player();   

        neili_limit = me->query_skill("force")* 8 + me->query("combat_exp", 1) /1000;

        if( me->query("family/family_name") != "峨嵋派" )
        return notify_fail("你看着眼前浪花飞溅，声震山谷，不由得有一丝惧意。\n");
   
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( !stringp(me->query_skill_mapped("force")) )
        return notify_fail("你必须先用 enable 选择你要用的特殊内功。\n");

        if( !arg || !sscanf(arg, "%d", qzdazuo_cost))
                return notify_fail("你要花多少气练功？\n");

        if (qzdazuo_cost < 10)
        return notify_fail("你无法控制内息运行到如此精细的程度！\n");

        if (me->query("max_qi") > 1000 && qzdazuo_cost < me->query("max_qi")/5)
                return notify_fail("你至少需要"+chinese_number(me->query("max_qi")/5)+"点的气来打坐！\n");

        if( (int)me->query("qi") < qzdazuo_cost )
                return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
                return notify_fail("你现在精不够，无法控制内息的流动！\n");

        if ((int)me->query("max_neili") >= neili_limit)
                return notify_fail("在此地修练已经对你没什么大作用了！\n"); 
                
        write(HIW"你暗运临济十二庄，气聚丹田，一股真气在四肢百脉中流动。\n"NOR);

        me->set_temp("pending/exercise", 1);
        me->set_temp("pending/qzdazuo", 1);
        me->set_temp("qzdazuo_cost", qzdazuo_cost);
        message_vision(HIW"$N盘膝坐下五心向天，开始运功打坐。\n"NOR,me); 
        me->start_busy((: dazuo :), (: halt_dazuo:));
        return 1;
}

int dazuo(object me)
{
        int qzdazuo_cost = (int)me->query_temp("qzdazuo_cost");
        int neili_gain = 1 + (int)me->query_skill("force") / 10
                * (1 + (int)me->query_skill("force") / 100);    

        if (neili_gain > qzdazuo_cost) neili_gain = qzdazuo_cost;
        me->add("neili", neili_gain *3/2);
        me->set_temp("qzdazuo_cost", qzdazuo_cost -= neili_gain);
        me->receive_damage("qi", neili_gain);

        if (qzdazuo_cost > 0) return 1;

        me->delete_temp("pending/exercise");
        me->delete_temp("pending/qzdazuo");
        message_vision(HIY"过了片刻，$N已与这大自然融合在一起，精神抖擞的站了起来。\n"NOR, me);  

        if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
                return 0;

        if ((int)me->query("max_neili") >= (me->query_skill("force")* 8 
          + me->query("combat_exp", 1) /1000)){
                write("你的内力修为已经达到了此地所能帮助你的极限。\n"); 
                me->set("neili", (int)me->query("max_neili"));
                return 0;
        }
        me->add("max_neili", 1);
        me->set("neili", (int)me->query("max_neili"));
        write("你的内力修为增加了！！\n");   
        return 0;
}

int halt_dazuo(object me)
{
    if ((int)me->query("neili") > (int)((int)me->query("max_neili") * 2))  
        me->set("neili", (int)((int)me->query("max_neili") * 2));     
        message_vision(HIW"$N长出一口气，将内息急速退了回去，站了起来。\n"NOR, me);
        me->delete_temp("pending/qzdazuo");
        me->delete_temp("pending/exercise");
        return 1;
}

void reset()
{
        object *ob;
        int i;
        
        ob = all_inventory(this_object());
        
        for(i=0; i<sizeof(ob); i++) {
                if( userp(ob[i]) ) continue;
                ob[i]->reincarnate();
                if( !ob[i]->return_home() ) destruct(ob[i]);
        }       
        
}
