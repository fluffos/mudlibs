// item: /d/xingxiu/npc/obj/fire.c

// Yom 24/12/03
#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
    add_action("do_bless","bless");
}

void create()
{ 
                
       set_name(HIG"七夕许愿树"NOR,({"bless tree","tree"}))
;
        set_weight(9999999);
           set("no_get",1);
        set_max_encumbrance(0);
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("unit","棵");
           set("long",HIG"一颗茂盛的许愿树，挂着缤纷的许愿带，你可以对着它许愿（Bless）。\n"NOR);
                                                  
        }
        
}

int do_bless()
{
     object me= this_player();
     if (me->query("gift/06772"))
     {
        tell_object(me,"你不是许过愿了吗？许太多愿会不灵的! \n");
        return 1;
     }
         message_vision(HIW"$N跪下来，虔诚地对着许愿树许愿。祝愿北侠玩家天天开心快乐，幸福美满！\n" + NOR,me);
    if(random(50)>48)
    {
     me->add("kar",1);
     me->set("gift/06772/kar",1);
        tell_object(me,"也许是你的诚心感动了上天，冥冥之中你觉得你的福缘有所增加。\n");
               message( "channel:" + "chat",HIR + "【谣言】"+HIB"听说" + me->query("name") +HIB"许愿感动上天，提高福缘！\n"NOR,users());
    }
    else if (random(50)>40)
    {
     me->add("per",1+random(3));
     me->set("gift/06772/per",1);
               message( "channel:" + "chat",HIR + "【谣言】"+HIB"听说" + me->query("name") +HIB"许愿感动上天，提高容貌！\n"NOR,users());
        tell_object(me,"也许是你的诚心感动了上天，冥冥之中你觉得你的容貌有所增加。\n");
    }
    else
    {
        tell_object(me,"也许是你不够诚心，什么事情都没有发生。\n");
     me->set("gift/06772",1);
    }
}

