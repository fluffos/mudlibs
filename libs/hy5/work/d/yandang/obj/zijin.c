inherit ITEM;
void create()
{
        set_name("紫金活络丹", ({ "zijindan","zijin","dan" }) );
        set("long", "海南养生堂出品的丹药,有活血通气之效.\n");
        set("unit", "粒");
        set("weight", 100);
        set("value", 1000);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");
if( living(this_player()) ==0 ) return 0;
        ob=this_player();
        ob->set("qi",(int)ob->query("max_qi"));
        ob->set("eff_qi",(int)ob->query("max_qi"));
        ob->set("neili", (int)ob->query("max_neili"));
tell_object(ob,"你吞下一颗紫金活络丹,觉得气力充沛.\n");
        destruct(this_object());
return 1;
}
