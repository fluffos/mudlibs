//edit by rock 2008.9.22
// 自动生成：/make/equip/armor

#include <armor.h>
#include <ansi.h>
inherit WAIST;

// 函数：所属类别
int query_xy() { return 1 ; }

// 函数：构造处理
void create()
{
        set_name("布腰带",({"buyd"}));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                 set("level", 10);            //装备等级
                 set("unit", "双");           //量词
                 set("material", "leather");
                 set("value",800);             //价值
                 set("armor_prop/armor", 13); //物理防御
             }
        set("max_lasting",5700);   //耐久度

        setup();

        set("gender","男、女");    //限制性别
}

#include "/clone/shoufei/long/armor.h"