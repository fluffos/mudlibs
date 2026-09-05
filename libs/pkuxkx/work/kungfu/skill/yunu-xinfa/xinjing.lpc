// xinjing.c 
// 统一古墓内功，男女都可以使用，非女性效果略差。 by jpei 10102008
// modified by whuan 2008-10-12,略微优化一下代码
#include <ansi.h>
inherit F_CLEAN_UP;
string *pictures=({
    HIY"少思、"YEL"少念、"HIC"少欲、"HIR"少事、"HIB"少语、"MAG"少笑"HIW,
    YEL"少愁、"CYN"少乐、"HIG"少喜、"HIR"少怒、"HIY"少好、"RED"少恶"HIW,
    HIC"多思"HIG"则"HIW"神怠，"HIB"多念"MAG"则"HIY"精散"HIW,
    HIR"多欲"YEL"则"BLU"智损，"MAG"多事"RED"则"HIG"形疲"HIW,
    HIB"多语"CYN"则"RED"气促，"HIR"多笑"HIC"则"BLU"肝伤"HIW,
    MAG"多愁"YEL"则"HIR"心慑，"RED"多乐"BLU"则"HIY"意溢"HIW,
    HIW"多喜"HIG"则"HIY"忘错"MAG"昏乱，"HIC"多怒"HIR"则"HIB"百脉"HIG"不定"HIW,
    HIG"多好"RED"则"BLU"专迷"HIG"不治，"HIW"多恶"HIB"则"MAG"焦煎"CYN"无宁"HIW
});

int exert(object me)
{
        int skill, level;
        string picture;

        if((int)me->query("neili") < 200 ) 
                return notify_fail("你的内力不够。\n");
        if((int)me->query_temp("xinjing")) 
                return notify_fail("你已经在运功中了。\n");
        if((int)me->query_temp("powerup"))
        		return notify_fail("你已经在运功中了。\n");
        if((int)me->query_skill("yunu-xinfa",1 ) < 120)
                return notify_fail("你的玉女心法等级不够，还不能体会十二少和十二多之妙处。\n");
        if( me->query_skill_mapped("force") != "yunu-xinfa")
                return notify_fail("你现在不能使用「心经」字诀。\n");
        if (me->query("family/family_name") != "古墓派" && me->query("chushi/last_family") != "古墓派")
        	      return notify_fail("你已不是古墓弟子，心有杂念，无法再体会到「心经」字诀。\n");  
        //if( me->query("gender") != "女性" )
                //return notify_fail("你不是女性，如何能领悟玉女心法的「心经」字诀。\n");
                
        skill = (int)me->query_skill("force");
        level = 5;
        if ( (int)me->query_skill("yunu-xinfa",1) > 600) level = 3;
        else if ( (int)me->query_skill("yunu-xinfa",1) > 400) level = 4;
        else level = 5;

        picture = pictures[random(sizeof(pictures))];
        message_vision(HIY"$N屏气凝神，口中默念"HIW"「"+picture+"」"HIY"的玉女心法正反要诀。\n" NOR, me);

        me->add_temp("apply/attack", (int)(skill/(level+1))); 
        me->add_temp("apply/dodge", (int)(skill/(level+1)));
        me->add_temp("apply/intelligence", me->query("int"));
        me->add_temp("apply/damage", me->query("str")*(6-level)); //控制在先天str封顶在150
        if( me->query("gender") == "女性" )
        {
                me->add_temp("apply/dexerity", me->query("dex"));       
                me->set_temp("active_force_buffer/yunu-xinfa.xinjing/effect5", "后天身法+"+me->query("dex")+"点");    //效果描述5
        }
        me->add("neili", -100);
        me->set_temp("xinjing", 1); 
        me->set_temp("powerup", 1);
        
        me->set_temp("active_force_buffer/yunu-xinfa.xinjing/name", "心经");                                  //buff名称
        me->set_temp("active_force_buffer/yunu-xinfa.xinjing/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/yunu-xinfa.xinjing/effect1", "攻击命中+"+(skill/(level+1))+"级");   //效果描述1
        me->set_temp("active_force_buffer/yunu-xinfa.xinjing/effect2", "轻功技能+"+(skill/(level+1))+"级");   //效果描述2
        me->set_temp("active_force_buffer/yunu-xinfa.xinjing/effect3", "后天悟性+"+me->query("int")+"点");    //效果描述3
        me->set_temp("active_force_buffer/yunu-xinfa.xinjing/effect4", "攻击伤害+"+(me->query("str")*(6-level))+"点");    //效果描述4

        me->start_call_out(__FILE__, "remove_effect_xinjing", skill/level, me, skill, level);

        if( me->is_fighting() && userp(me)) me->start_busy(3);
        
        return 1;
}
 
void remove_effect_xinjing(object me, int skill, int level)
{ 
        if(!me || !objectp(me) || !userp(me)) return;	      
        me->add_temp("apply/attack", -(int)(skill/(level+1))); 
        me->add_temp("apply/dodge", -(int)(skill/(level+1)));
        me->add_temp("apply/intelligence", -me->query("int"));
        me->add_temp("apply/damage", -me->query("str")*(6-level)); //控制在先天str封顶在150        
        if( me->query("gender") == "女性" )
                me->add_temp("apply/dexerity", -me->query("dex"));
        me->delete_temp("xinjing");
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/yunu-xinfa.xinjing");
        tell_object(me, HIW"你的玉女心法「心经」字诀运功完毕，将内力收回丹田。\n"NOR);
}
