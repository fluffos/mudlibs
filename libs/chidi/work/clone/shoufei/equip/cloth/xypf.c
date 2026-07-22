//edit by rock 2008.10.15
// 自动生成：/make/equip/cloth

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

// 函数：所属类别
int query_xy() { return 1 ; }

// 函数：构造处理
void create()
{
        set_name("逍遥披风",({"xypf"}));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                 set("level", 65);            //装备等级
                 set("unit", "件");           //量词
                 set("material", "cloth");
                 set("value",32500);             //价值
                 set("armor_prop/armor", 154); //物理防御
             }
        set("max_lasting",21000);   //耐久度

        setup();

        set("gender","男性");    //限制性别
}

#include "/clone/shoufei/long/armor.h"