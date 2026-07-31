
// Book: /d/new_taohua/obj/ninebook.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.


inherit ITEM;
int do_read(string);
void create()
{
        set_name("九阴真经",({ "ninebook","book" }));
        set_weight(100); 
	set("no_get",1);
	set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "一本刺了字的人皮，上面写着一些神秘武功的心法。\n");
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
        switch( random(3) )
        {
            case 0:
                if ( (lvl=(int)me->query_skill("cuixin-zhang", 1)) < 180)
                {          
                        if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("cuixin-zhang", me->query("int")/3);
                        write("你研读九阴真经，似乎对摧心掌有点心得。\n");
                        me->set_temp("stone_learned",1);
                }
        break;
            case 1:
                if ( (lvl=(int)me->query_skill("ninemoon-zhua", 1)) < 180)
                {       if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("ninemoon-zhua", me->query("int")/3);
                        write("你研读九阴真经，似乎对九阴白骨爪有点心得。\n");
                        me->set_temp("stone_learned",1);
                }
        break;
            case 2:
                if ( (lvl=(int)me->query_skill("yihun-dafa", 1)) < 180)
                {       if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("yihun-dafa", me->query("int")/10);
                        write("你研读九阴真经，似乎对移魂大法有点心得。\n");
                }
        break;
        }

        return 1;
}
