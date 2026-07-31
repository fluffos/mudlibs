// Room: /d/new_taohua/lshfroom.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;
int do_open(string);
int do_close(string);
void create()
{
        set("short", "陆乘风居");
        set("long", @LONG
       屋内陈设简朴，较特别处在于门楣上钉着八片铁片，排作八卦形状，
却又不似寻常的八卦那么排列整齐，疏疏落落，歪斜不称。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
//  "south" : __DIR__"yonglu6",
]));
       

        setup();
}
void init()
{
        add_action("do_open","open");
	add_action("do_close","close");
	add_action("do_read","read");
}
int do_close(string arg)
{
         object ob;
         switch (arg)
         {
         case "door":
         case "门":
             if(!query("exits/south")) return notify_fail("门已经是关的了");
             message_vision("$N将门关上,却发现门后有一个铁八卦。\n",this_player());
             delete("exits/south");
             return 1;
         default: return notify_fail("你要关什么？\n"); 
         }
         

}
int do_open(string arg)
{
         object ob;
         switch (arg)
         {
         case "door":
         case "门":
             if(query("exits/south")) return notify_fail("门已经是开的了\n");
             message_vision("$N将门打开\n",this_player());
             set("exits/south",__DIR__"yonglu6");
             return 1;

         default: return notify_fail("你要开什么？\n"); 
         }
         

}
int do_read(string arg)
{
        int lvl,exp;
        object me,where;
        me=this_player();
        where = environment(me);            

        if ( !arg && arg!="bagua" && arg!="八卦" && !query("exits/south"))
                return notify_fail("什么？\n");
	 
        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
        if (me->query("gin")<100) return notify_fail("你的精力不够了。\n");
        me->add("gin", (-1)*random(100));

        message_vision("$N正专心研读八卦。\n", me);
        exp=me->query("combat_exp")*10;
	lvl=100;
        switch( random(2) )
        {
            case 0:
                if ( (lvl=(int)me->query_skill("luoying-zhang", 1)) < 101)
                {          
                        if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("luoying-zhang", me->query("int")*10);
                        write("你研读八卦，似乎对落英神剑掌有点心得。\n");
                        me->unconcious(); 
                        me->set("no_get", 1);
                        me->set("no_get_from", 1); 
                        where->set("no_fight", 1);

                }
        break;
            case 1:
                if ( (lvl=(int)me->query_skill("lanhua-shou", 1)) < 101)
                {       if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("lanhua-shou", me->query("int")*10);
                        write("你研读八卦，似乎对兰花拂穴手有点心得。\n");
                        me->unconcious();
                        me->set("no_get", 1);
                        me->set("no_get_from", 1); 
                        where->set("no_fight", 1);
                }
        break;
        }

        return 1;
} 
