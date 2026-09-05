#include <ansi.h>
void init()
{
    add_action("do_zhai","zhai");
}

int do_zhai()
{
    object me=this_player(),arrow;
    object ob=this_object();
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!ob->query("arrow")||!ob->query("arrow_file"))
    {
        tell_object(me,ob->query("name")+"上并没有任何箭可以取下。\n");
        return 1;
    }
    arrow=new(ob->query("arrow_file"));
    arrow->move(me);
    message_vision("$N从"+ob->query("name")+"上取下了一只"+arrow->query("name")+"。\n",me);
    ob->delete("arrow");
    ob->delete("arrow_file");
    ob->add("arrow_assist",-(int)ob->query("extra_assist"));
    return 1;
}
