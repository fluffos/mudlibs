//Cracked by Roath
// gouhun.c
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
int success_adj, damage_adj;

success_adj = 150;
damage_adj = 160;
return notify_fail("暂未开放。\n");	
if( !target ) target = offensive_target(me);
if(me->query("family/family_name")!="阎罗地府") 
        return notify_fail("你不是地府弟子，不能使用这项技能！\n"); 
if( !target
 || !target->is_character()
 || target->is_corpse()
 || target==me 
 || !me->is_fighting(target) )
        return notify_fail("你要勾自己的魂？\n");
if((int)me->query("mana")<500 )
        return notify_fail("你的法力不够了！\n");
if((int)me->query("sen")<100 )
        return notify_fail("现在你自己就魂不守舍！\n");
me->add("mana", -250);
me->receive_damage("sen", 50);

if( random(me->query("max_mana")) < 50 ) {
        write("这次是鬼见鬼了！\n");
        return 1;
}

SPELL_D->attacking_cast(
        me, 
        target, 
        success_adj,    
        damage_adj,     
        "shen",         
        HIC "$N"HIC"对$n"HIC"阴阴地笑着：阎王叫你三更死，不敢留你到五更。。。\n" NOR,
            //initial message
        HIC "$n"HIC"受到$N"HIC"影响，显然有点魂不守舍了！\n" NOR, 
            //success message
        HIC "但是$n"HIC"神情专注，对$N"HIC"理都不理。\n" NOR, 
            //fail message
        HIC "但是$n"HIC"眼一瞪：光天化日之下，岂由恶鬼横行！\n" NOR, 
            //backfire initial message
        HIC "结果$n"HIC"反而有点魂不守舍了！\n" NOR
    );
me->start_busy(1);    
return 6;
}

int help(object me)
{
string str;
if ( !me )      return 0;
return notify_fail("暂未开放。\n");	
str = @LONG
        法术名称：阎罗勾魂
        法术所属：勾 魂 术
        法术效果：对敌人的心智给予强力的打击
                  冷却 6 秒
                  使完自身busy 1 秒
        法术条件：
                  法力500点，消耗150点
                  精神100点，消耗50点     
LONG;
me->start_more(str);
return 1;
}       
