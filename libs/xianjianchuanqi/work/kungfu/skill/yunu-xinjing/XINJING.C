// xinjing.c 
// By River
#include <ansi.h>
inherit F_CLEAN_UP;

string *bbonuss=({
"apply/strength","apply/constitution","apply/attack","apply/damage","apply/speed"
});

string *gbonuss=({
"apply/dexerity","apply/intelligence","apply/dodge","apply/armor","apply/defense","apply/parry",
});

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

int exert(object me, object target)
{
        int skill;
        string bonus,picture;

        if( ! me->is_fighting() && me->query("gender") =="男性" )
                return notify_fail("你只能在战斗中使用「心经」字诀。\n");
        if( target != me )
                return notify_fail("你只能自己体会十二少和十二多之妙处。\n");

        if((int)me->query("neili") < 350 ) 
                return notify_fail("你的内力不够。\n");

        if((int)me->query_temp("xinjing")) 
                return notify_fail("你已经在运功中了。\n");

        if((int)me->query_skill("yunu-xinjing",1 ) < 51)
                return notify_fail("你的玉女心经等级不够，还不能体会十二少和十二多之妙处。\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("你现在不能使用「心经」字诀。\n");

        if(me->query("gender")=="无性")
                return notify_fail("你无根无性，阴阳不调，难以领会高深的玉女心经神功。\n");

        skill = (int)me->query_skill("yunu-xinjing", 1);        
        me->add("neili", -(200+ random(200)));
        if( me->query("gender") == "男性")
        bonus = bbonuss[random(sizeof(bbonuss))];
        if( me->query("gender") == "女性")
        bonus = gbonuss[random(sizeof(gbonuss))];
        picture = pictures[random(sizeof(pictures))];
        message_vision(HIY"$N屏气凝神，口中默念"HIW"「"+picture+"」"HIY"的玉女心经正反要诀。\n" NOR, me);
        me->add_temp(bonus, skill/5);
        me->set_temp("xinjing/bonus", bonus);
        me->set_temp("xinjing/eff", skill/5);
        call_out("remove_effect", 1, me, skill/3);
        if( me->is_fighting() && userp(me)) me->start_busy(2);
        me->start_exert(1,"「心经」字决");
        return 1;
}

void remove_effect(object me, int count)
{       
        int amount;
        if( objectp(me) && me->query_temp("xinjing/eff")){   
           if (count-- > 0 ){
                call_out("remove_effect", 1, me, count);
                return;
           }
           amount = me->query_temp("xinjing/eff");
           me->add_temp(me->query_temp("xinjing/bonus"), - amount);
           me->delete_temp("xinjing");
           tell_object(me, HIW"你的玉女心经「心经」字决运功完毕，将内力收回丹田。\n"NOR);
        }
}
