//edit by rock 2008.9.22
// 自动生成：/make/equip/armor

#include <armor.h>
#include <ansi.h>
inherit ARMOR;

// 函数：所属类别
int query_xy() { return 1 ; }

// 函数：构造处理
void create()
{
        set_name("星辰战袍",({"xczpao"}));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                 set("level", 120);            //装备等级
                 set("unit", "件");           //量词
                 set("material", "armor");
                 set("value",71500);             //价值
                 set("armor_prop/armor", 275); //物理防御
             }
        set("max_lasting",37500);   //耐久度

        setup();

        set("gender","女性");    //限制性别
}

#include "/clone/shoufei/long/armor.h"