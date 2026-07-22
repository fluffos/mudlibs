// pingju.c 支票

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("货物凭据", ({"good check"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这是一张取货的货物凭据。\n");
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_drop", 1);
                set("no_put", 1);
        }
        setup();
}

void init()
{
        add_action("do_chakan", "kan");
}

int do_chakan(string arg)
{
        object me=this_player();
        object ob=this_object();

        if ( arg=="good check" )
        {
                if ( !me->query_temp("merchant/chaomai/given") )
                        return notify_fail("你没有向胡子要任务，你怎么会有这张凭据。\n");
                message_vision("$N查看凭据。\n", me);
                tell_object(me, "凭据上写着：\n凭此单张可取"+WHT+chinese_number(me->query_temp("merchant/chaomai/now_goods"))+NOR+"个单位的"+HIW+me->query_temp("merchant/chaomai/name")+"。\n"NOR);
                return 1;
        }
        return 0;
}

