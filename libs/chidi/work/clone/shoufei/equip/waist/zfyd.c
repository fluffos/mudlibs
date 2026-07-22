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
        set_name("追风腰带",({"zfyd"}));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                 set("level", 45);            //装备等级
                 set("unit", "双");           //量词
                 set("material", "leather");
                 set("value",8750);             //价值
                 set("armor_prop/armor", 45); //物理防御
             }
        set("max_lasting",8850);   //耐久度

        setup();

        set("gender","男、女");    //限制性别
}

#include "/clone/shoufei/long/armor.h"