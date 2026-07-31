#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "镶锲符咒" NOR, ({ "xiangqie fuzhou", "fuzhou", "fu" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("long", "一张使用后可让你的自铸武器永久增加一个镶锲孔的符咒，你重新铸另外一把武器时，\n该镶锲孔仍然存在。只能使用3次{use fuzhou}\n");
              set("no_put",1);
              set("no_sell",1);
              set("ty_gift", 1);
              set("no_get", 1);
              set("no_give", 1);
              set("no_drop",1); 
              set("tianya_money",5);
              set("unit", "张");      }
}

void init()
{
        add_action("do_eat", "use");
}

int do_eat(string arg)
{
        object me;

        if (! id(arg))
                return notify_fail("你要使用什么？\n");

        me = this_player();
         
        if (!me->query("weapon"))
                return notify_fail("你还没有自铸武器！\n");
        if (me->query("weaponqie")>2)
                return notify_fail("你的自铸武器只能增加四个镶锲孔！\n");

        message_vision("$N口中念念有词，拿起" + this_object()->name() +
                       "贴在$N的自铸武器上面。\n", me);


                tell_object(me, HIG "恭喜你！你的自铸武器增加了一次镶锲金属的机会。\n");
                me->add("weaponqie", 1);

        destruct(this_object());
        return 1;
}


