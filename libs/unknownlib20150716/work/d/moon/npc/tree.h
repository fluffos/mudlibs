#include <ansi.h>

string damage_msg(object who)
{
int r;  
string str;     
r = who->query_temp("apply_kee")*100/who->query_temp("apply_max_kee");
if ( who==this_object() )
        {
        if( r>=100 )    str = HIG "看起来生机勃勃，没有什么异常。"NOR;
        else if( r>95 ) str = HIG "似乎有些萎靡，但是仍然十分有生机。"NOR;
        else if( r>90 ) str = HIY "看起来可能需要浇水了。"NOR;
        else if( r>80 ) str = HIY "枝叶招展之间似乎有点不太灵光，但是仍然有些生机。"NOR;
        else if( r>60 ) str = HIY "枝叶一阵颤抖，看起来状况并不太好。"NOR;
        else if( r>40 ) str = HIR "好似垂头丧气一般，看来需要好好休养了。"NOR;
        else if( r>30 ) str = HIR "枝干上出现了一道可怕的裂痕，正在勉力支撑着不倒下去。"NOR;
        else if( r>20 ) str = HIR "变得黯淡无光,似乎马上要倒下了。"NOR;
        else if( r>10 ) str = RED "枝干上的裂痕变得越来越大，眼看就要断倒在地。"NOR;
        else            str = RED "发出可怕的“咯吱”声，随时都可能折断在地。"NOR;
        }
else    {       
        if( r==100 )    str = HIG "看起来充满活力，一点也不累。"NOR;
        else if( r>95 )         str = HIG "似乎有些疲惫，但是仍然十分有活力。"NOR;
        else if( r>90 )         str = HIY "看起来可能有些累了。"NOR;
        else if( r>80 )         str = HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。"NOR;
        else if( r>60 )         str = HIY "气喘嘘嘘，看起来状况并不太好。"NOR;
        else if( r>40 )         str = HIR "似乎非常疲惫，看来需要好好休息了。"NOR;
        else if( r>30 )         str = HIR "已经一副头重脚轻的模样，正在勉力支撑着不倒下去。"NOR;
        else if( r>20 )         str = HIR "看起来已经力不从心,马上要支持不住了。"NOR;
        else if( r>10 )         str = RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。"NOR;
        else            str = RED "已经陷入半昏迷状态，随时都可能摔倒晕去。"NOR;
        }
return NOR"( $n"+str+" )\n";    
}
