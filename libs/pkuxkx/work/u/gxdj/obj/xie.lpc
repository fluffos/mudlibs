#include <ansi.h>
#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("溜冰鞋", ({ "liubing xie", "xie" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "boots");
                set("armor_prop/dodge", 2);
                set("no_get",1);
                set("no_drop",1);
                set("no_steal",1);
        }
        setup();
}
void init()
{
        add_action("do_goto","goto");
}
int do_goto(string arg)
{
        if(!arg)
        return notify_fail("你想去哪儿？\n");
        if(arg=="wudang")
        {this_player()->move("/d/wudang/sanqingdian");
         return 1;}
        if(arg=="shaolin")
        {this_player()->move("/d/shaolin/guangchang1");
        return 1;}
        if(arg=="xingxiu")
        {this_player()->move("/d/xingxiu/riyuedong");
        return 1;}
        if(arg=="mingjiao")
        {this_player()->move("/d/mingjiao/xiuxishi");
        return 1;}
        if(arg=="huashan")
        {this_player()->move("/d/huashan/houhuayuan1");
        return 1;}
        if(arg=="guiyunzhuang")
        {this_player()->move("/d/guiyunzhuang/dating");
        return 1;}
        if(arg=="taohuadao")
        {this_player()->move("/d/taohuadao/dating");
        return 1;}
        if(arg=="emei")
        {this_player()->move("/d/emei/gate");
        return 1;}
        if(arg=="guang")
        {this_player()->move("/d/city/guangchang");
        return 1;}
}
