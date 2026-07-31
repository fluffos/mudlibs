//Edit By Subzero
#include <weapon.h>
#include <ansi.h>
inherit CLUB;

void create()
{
        set_name(HIG"阿古施华亚"NOR, ({ "yueye spear","yueye","spear" }) );
        set_weight(50000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "杆");
     set("value", 50000);
     set("super",5);
        set("rumor",1);
        set("material", "iron");
        set("long",HIG "此矛原在突厥武神毕玄手中，重九十九斤，矛名‘阿古施华亚’，是突厥古语，意即月夜之狼，
毕玄年轻时仗之冲锋陷阵，纵横草原从无敌手，初出道之际已被誉为“没有人能把他从马背击
下来”，六十岁后弃矛不用。此矛观之除坚硬沉重外并无其它特异之处，但如想使用自如，除
高手外他人确实难以做到。
\n"NOR);
        set("wield_msg", HIW"$N"+HIW+"静立无言，心止如水，从背后洒然抽出月狼矛，任风吹剑舞，我自巍然不动。\n"NOR);
        set("unequip_msg", HIG"$N"+HIG+"旋风般转过身来，长袍扬起，竟就那么随意地收起手中的$n。\n"NOR);
   }
   init_club(800);
   setup();
}

int hit_ob(object me,object target)
{
   if(random(10)+random(10)>10){
    message_vision("$N手中的"+this_object()->name()+"发出一股真气，$n觉得内息一窒!\n",me,target);
if (userp(target))
{
	 target->add("neili",-target->query("neili")/10);
}
else
{
	 target->add("neili",-random(288));
}

    return 1;}
    return 1;
}
