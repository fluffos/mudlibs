
// Book: /d/new_taohua/obj/ninebook2.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
inherit ITEM;
int do_read(string);
void create()
{
        set_name("九阴真经（上卷）",({ "nine book","book" }));
        set_weight(100);
        set("no_get",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "一卷纸卷，上面写着一些道家养气的心法。\n");
                }

}
void init()
{
        add_action("do_read", "read");
}



int do_read(string arg)
{
        int lvl,exp;
        object me;
        me=this_player();

        if ( !arg && arg!="book" && arg!="ninebook" )
                return notify_fail("什么？1 \n");

        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
        if (me->query("sen")<100) return notify_fail("你的精力不够了。\n");
        me->add("sen", (-1)*random(100));

        message_vision("$N正专心研读九阴真经。\n", me);
        exp=me->query("combat_exp")*10;
        lvl=180;
        if (me->query("readed")) 
        {
          if ( (lvl=(int)me->query_skill("yihun-dafa", 1)) < 180)
                {       if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("yihun-dafa", me->query("int")/3);
                        write("你研读九阴真经，似乎对移魂大法有点心得。\n");
                }   
          return 1;
         }     

        switch( random(2) )
        {
            case 0:
                
                {
                        write("你研读九阴真经，突然发现上面有一些梵文。\n");
			write(RED "斯里星，昂依纳得。\n" NOR);
			write(RED "斯热确虚，哈虎文钵英。\n" NOR);
		
                }
        break;

            case 1:
                if ( (lvl=(int)me->query_skill("yihun-dafa", 1)) < 180)
                {       if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("yihun-dafa", me->query("int")/3);
                        write("你研读九阴真经，似乎对移魂大法有点心得。\n");
                }
        break;
        }

        return 1;
}
