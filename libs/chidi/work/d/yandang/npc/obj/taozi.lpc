#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("弥猴桃", ({ "taozi" }) );
        set("long", "一种野生的水果。\n");
        set("unit", "颗");
        set("weight", 100);
        set("value", 5000);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
         ob=this_player();
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");
if( living(this_player()) ==0 ) return 0;
        ob->set("food",((int)ob->query("str")-10)*10+200);
        ob->set("water",((int)ob->query("str")-10)*10+200);

        write("[1;33m你吃下一颗弥猴桃，只觉得齿颊留芳,回味无穷！\n[0;37m");

        message("vision", HIY + ob->name() + 
"你吃下一颗弥猴桃，只觉得齿颊留芳,回味无穷！\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
