// item: /d/xingxiu/obj/fire.c
// Jay 3/17/96

inherit ITEM;

void create()
{
        set_name("麻绳", ({"ma sheng", "sheng"}));
        set_weight(380);
        set("is_sheng_xx",1);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "这是一卷麻绳，尾端被打上活扣，似乎准备系(ji)住什么东西。\n");
                set("unit", "卷");
                set("value", 1);
        }
}

void init()
{
    add_action("do_ji","ji");
}

int do_ji(string arg)
{
    object ob,me=this_player();
    if (!arg)
    {
        tell_object(me,"你要系什么？\n");
        return 1;
    }
    if (!present(arg,me))
    {
        tell_object(me,"你身上并没有"+arg+"啊！\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    ob=present(arg,me);
    if (!ob->query("is_tiegou_xx"))
    {
        tell_object(me,"系上"+ob->query("name")+"似乎并不合适。\n");
        return 1;
    }
    message_vision("$N把$n系在"+this_object()->query("name")+"上，做成了一副飞抓。\n",me,ob);
    destruct(ob);
    ob=new(__DIR__"zhua");
    ob->move(me);
    destruct(this_object());
    return 1;
}
