#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "斧劈石");
        set("long", @LONG
仰望峰巅，古松奇石参差，半棵焦黑的树下立有一块巨石，高一长有余，长数
丈，拦腰裂为三断，如同斧劈。传说乃沉香劈山救母之处。石下与峰头之间有一空
洞，可容一人伏身爬入。
LONG
        );
    set("exits", ([ 
        "southup" : __DIR__"lianhua",
        ]));
     set("objects", ([
                __DIR__"npc/hawk" : 1,
                        __DIR__"npc/hawktrainer" : 1,
       ]) ); 
    set("outdoors", "huashanfy"); 
    set("coor/x",-640);
    set("coor/y",-92);
    set("coor/z",75);
        setup();
    //replace_program(ROOM);
} 
void init()
{
        add_action("do_chop","chop");
} 
int do_chop(string arg)
{
        object me,*inv,weapon;
        object hawk,chain,hawktrainer;
        int i;
        hawk = present("hawk",this_object());
        if (!hawk || this_object()->query("item_desc") == 0 )
        {
                return 0;
                //need to give them hint here?
                //return notify_fail("你要砍断什么？\n");
   }
        
        if(!arg || (arg != "chain" && arg != "铁链") ) 
        {
                return notify_fail("你要砍断什么？\n");
        }
        me=this_player();
        
        if (hawktrainer = present("hawk trainer",this_object()))
        { 
        message_vision(RED"$N对$n大吼一声：想打我猎鹰的主意！你活得不耐烦了！ \n"NOR,
                       hawktrainer,me);
        hawktrainer->kill_ob(me);
        me->start_busy(2);
        return 1;
    } 
        inv = all_inventory(me);
        for (i=0;i<sizeof(inv);i++ )
        {
                if (objectp(inv[i]) && inv[i]->query("weapon_prop") && inv[i]->query("equipped"))
                { 
                        weapon = inv[i];
                        message_vision("$N用尽全力，将手中的"+weapon->name()+"猛力向铁链挥去。。。。\n",me);
                        //weapon->set("weapon_prop",0);
                        //weapon->save();
                        me->reset_action();
                        if (weapon ->query("rigidity")>=2000)
                        {
                                hawk->set("marks/chained",0);
                                this_object()->set("item_desc",0);
                                message_vision("铁链应声而断！\n",me);
                                chain = new(__DIR__"npc/obj/chain");
                                chain->move(this_object());
                                return 1;
                        }
                        message_vision("只听见”铛“的一声，$N手中的"+weapon->name()+"被弹了开去，而铁链纹丝不动！\n",me);
                        me->start_busy(2);
                        return 1; 
                }
        }
   return notify_fail("你要用什么砍断铁链 \n");
}    
