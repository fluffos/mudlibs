//edit by rock 2008.9.22
// 自动生成：/make/equip/armor

#include <armor.h>
#include <ansi.h>
inherit NECK;

// 函数：所属类别
int query_xy() { return 1 ; }

// 函数：构造处理
void create()
{
        set_name("铁项链",({"txl5"}));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                 set("level", 20);            //装备等级
                 set("unit", "串");           //量词
                 set("material", "neck");
                 set("value",8000);             //价值
                 set("armor_prop/armor", 28); //物理防御
                 set("pp",26);
             }
        set("max_lasting",4800);   //耐久度

        setup();

        set("gender","男、女");    //限制性别
}

#include "/clone/shoufei/long/armor.h"