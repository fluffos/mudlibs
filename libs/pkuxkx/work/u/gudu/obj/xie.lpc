#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("溜冰鞋", ({ "xie" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("armor_prop/dodge", 2);
                set("no_get",1);
                set("no_drop",1);
                set("no_steal",1);
                set("value", 6000);
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
        {this_player()->move("/d/wudang2/sanqing");
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
        if(arg=="xkbook")
        {this_player()->move("/d/xiakedao/study_room");
        return 1;}
        if(arg=="task")
        {this_player()->move("/u/gudu/taskroom");
        return 1;}
        if(arg=="obj")
        {this_player()->move("/u/gudu/collectroom");
        return 1;}
        if(arg=="wd")
        {this_player()->move("/d/wudang/sanqingdian");
        return 1;}
        if(arg=="quanzhen")
        {this_player()->move("/d/quanzhen/gongmen");
        return 1;}
        if(arg=="guiyun")
        {this_player()->move("/d/guiyunzhuang/dating");
        return 1;}
        if(arg=="taohua")
        {this_player()->move("/d/taohuadao/dating");
        return 1;}
        if(arg=="emei")
        {this_player()->move("/d/emei/gate");
        return 1;}
        if(arg=="city")
        {this_player()->move("/d/city/guangchang");
        return 1;}
        if(arg=="dali")
        {this_player()->move("/d/dali/restroom");
        return 1;}
        if(arg=="jiaxing")
        {this_player()->move("/d/quanzhou/nanhu");
        return 1;}
        if(arg=="quanzhou")
        {this_player()->move("/d/quanzhou/zhongxin");
        return 1;}
        if(arg=="quanzhen")
        {this_player()->move("/d/quanzhen/sanqingdian");
        return 1;}
        if(arg=="gumu")
        {this_player()->move("/d/gumu/ceshi3");
        return 1;}
        if(arg=="xiangyang")
        {this_player()->move("/d/xiangyang/xycenter");
        return 1;}
        if(arg=="taishan")
        {this_player()->move("/d/taishan/yuhuang");
        return 1;}
        if(arg=="lingzhou")
        {this_player()->move("/d/lingzhou/nanmen");
        return 1;}
        if(arg=="pingxi")
        {this_player()->move("/d/pingxiwangfu/zhengting");
        return 1;}
        if(arg=="lingjiu")
        {this_player()->move("/d/lingjiu/damen");
        return 1;}
        if(arg=="pker")
        {this_player()->move("/d/pker/zonghengfu");
        return 1;}
        if(arg=="xkdss")
        {this_player()->move("/d/xiakedao/shishi1");
        return 1;}
        if(arg=="gaibang")
        {this_player()->move("/d/city/gbxiaowu");
        return 1;}
}

string query_autoload()
{
        return query("name");
}

void autoload()
{}


