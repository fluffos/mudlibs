// ruanweijia.c 
// by dream

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIY "软猬甲" NOR,({"ruanwei jia","jia"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","件");
                set("long","布满倒刺的甲胄，是桃花岛的宝物,穿上他能将受到的伤害降底一半。\n");
        set("value",5000);
                set("material","armor");
                set("armor_prop/armor", 10);
        }
        setup();
}

mapping armor_action(object me,object target,int damage)
{
        string msg="";
        mapping foo=([]);
        int dam;
        if(objectp (target->query_temp("weapon")))      {
                msg+=HIW"只听“铛”的一响，"+
                this_object()->query("name")+"将$w的伤害卸去了大半！\n"NOR;
                damage/=2;
                if(damage<=0)   damage=0;
        }
        foo["msg"]=msg;
        foo["damage"]=damage;
        return foo;
}

