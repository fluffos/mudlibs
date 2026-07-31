inherit ITEM;
 
#include <ansi.h>
 
void create()
{
        set_name(HIG"万宝路香烟"NOR,({ "cigarette","xiang yan","yan" }) );
        set("long", "这是一包装精美的香烟。\n");
        set("unit", "包");
        set("number", 20);
        set("base_weight", 200);
}
 
void init()
{
        if( this_player()==environment() )
        add_action("do_smoking", "smoke");
}
 
int do_smoking(string arg)
{
        object ob,me;
        int jing,max_jing;
        jing = me->query("jing");
        max_jing = me->query("max_jing");
        if( !arg || (arg != "cigarette"&&arg !="xiang yan" && arg != "yan"))
                return notify_fail("你要抽甚麽呢? \n");
        if( this_object()->query("number") <=0)
        {
               destruct(this_object());
               return notify_fail("烟已经抽光了。\n");
         }
        
        message_vision( MAG
        "$N拿出了一根香烟，然后从怀中掏出一个美式防风打火机.....\n"+HIR
        "$N怡然自得的抽了起来，不时有几朵烟圈从口中冒了出来！\n" NOR,this_player
()
        ); //end_message_vision
        message_vision(WHT"这根香烟$N抽完了，$N随手一丢，说也奇怪地就不见了。
                                \n"NOR,this_player() );
        if (jing >= max_jing )
        return 1;
        this_player()->add("jing",5);
        this_object()->add("number", -1);
        return 1;
}
