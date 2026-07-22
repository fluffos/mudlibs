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
        set_name("玉露腰带",({"yul"}));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                 set("level", 30);            //装备等级
                 set("unit", "双");           //量词
                 set("material", "leather");
                 set("value",8000);             //价值
                 set("armor_prop/armor", 17); //物理防御
             }
        set("max_lasting",5550);   //耐久度

        setup();

        set("gender","男、女");    //限制性别
}

#include "/clone/shoufei/long/armor.h"