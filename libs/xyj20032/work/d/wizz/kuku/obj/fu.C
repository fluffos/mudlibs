// Created by kuku@sjsh 2003.10.21  装备鉴定符

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("鉴定符", ({"jianding fu","fu"}));
        set("unit", "张" );
        set_weight(10);
        set("long",@long
这是用来鉴定武器和护具的灵符，指令(identify xxx) 。
long );
        set("no_sell","掌柜的摇摇头说：这宝贝小店不敢收。\n");
        set("no_put",1);
        set("value",25000); 
        setup();
}

void init()
{
        add_action("do_identify","identify");
}

int do_identify(string arg)
{
        object diablo_obj,ob,me;        
        me = this_player();
        ob = this_object();

        if(!arg )
                return notify_fail("你要鉴定什么？\n");
        
        diablo_obj=present(arg,me);

        if(!diablo_obj)
                return notify_fail("你身上有这样东西吗？\n");
                
        if (!diablo_obj->query("skill_type") && !diablo_obj->query("armor_type") )
                return notify_fail("这样东西需要鉴定吗？\n");

        if (!diablo_obj->query("Is_Diablo_Obj"))
                return notify_fail("这样东西需要鉴定吗？\n");

        if(diablo_obj->query("Is_Diablo_Obj")){
                if(diablo_obj->query("lvl")<3)
                        return notify_fail("这样东西需要鉴定吗？\n");
        }

        if(diablo_obj->query("equipped"))
                return notify_fail("你必须卸下它才能鉴定。\n");

        if (me->is_busy())
                return notify_fail("你还是等有空的时候再说吧。\n");
                
        if(diablo_obj->query("identification"))
                return notify_fail("这样东西已经鉴定过了。\n");

        message_vision (CYN"\n$N将符咒贴在"+diablo_obj->query("name")+"上，一道若隐若现的灵光瞬间流过"+diablo_obj->query("name")+"。\n"NOR, me );
        diablo_obj->finish_identify();
        me->start_busy(5);
        destruct(ob);
        return 1;
}
