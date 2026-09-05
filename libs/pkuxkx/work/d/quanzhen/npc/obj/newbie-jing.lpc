#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( HIC"道童的道德经"NOR, ({ "daotong's jing", }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一册道童誊抄的道德经。\n");
                set("value", 1);
                set("material", "paper");
              
            }
}

void init()
{
    add_action("do_get","get");
}

int do_get(string arg)
{
    object ob=this_object();
    object me=this_player();
    if (arg=="daotong's jing")
    {
        if (me->query_temp("qznewbiejob/task3/type")=="找书")
        {
        message_vision("$N拣起了一本$n。\n",me,ob);
        remove_call_out("dest");
        ob->move(me);
        return 1;
        }
        else
        {
            tell_object(me,"这本书根本乱七八糟，不值一看！\n");
            return 1;
        }
    }
    
}