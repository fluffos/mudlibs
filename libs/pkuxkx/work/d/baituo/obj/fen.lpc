inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "use");
}
void create()
{
        set_name("蛇胆粉", ({ "fen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "这是疗伤的『蛇胆粉』。\n");
                set("value", 2000);
        }
        setup();
}
int do_eat(string arg)
{
        object me = this_player();
        if (!arg||arg!="fen")
                return notify_fail("你要吃什么？\n");
        if ((int)this_player()->query("eff_jing") >=
            (int)this_player()->query("max_jing"))
                return notify_fail("你现在不需要蛇粉。\n");
        if(random(2)==0)
         {message_vision( "$N吃下一包蛇胆粉，觉得象是土豆粉，连呼上当￣￣\n" , me);
          destruct(this_object());
          return 1;
         }
        {
            int my_jing     = me->query("jing");
            int my_eff_jing = me->query("eff_jing");
            int my_max_jing = me->query("max_jing");
            if ((my_eff_jing+20)>=my_max_jing) me->set("eff_jing",my_max_jing);
                   else me->add("eff_jing",20);
                   my_eff_jing = me->query("eff_jing");
            if ((my_jing+30)>=my_max_jing)  me->set("jing",my_eff_jing);
                   else me->add("jing",30); 
        } 
        message_vision( "$N吃下一包蛇胆粉，顿觉真气上涌，精神好了些。\n" , me);
        destruct(this_object());
        return 1;
}
