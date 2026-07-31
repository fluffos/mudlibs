#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("小还丹", ({ "da huandan","huandan" }) );
        set("long", "一颗用道法炼制的小还丹。\n");
        set("unit", "粒");
        set("weight", 90);
        set("value", 10000);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return 0;
        
        ob=this_player();
        if( living(this_player()) ==0 ) return 0;
        ob->set("jing",(int)ob->query("eff_jing"));
        ob->set("qi",(int)ob->query("eff_qi"));


        write("你吞下一颗小还丹，觉得饥饿劳累一扫而空！\n");

        message("vision", HIY + ob->name() + 
"吞下一颗小还丹,精神一爽.\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}