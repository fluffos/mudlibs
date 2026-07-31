#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIW "上帝之心" NOR, ({ "god_xin", "xin" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "上帝之心可以将十级兵器的魔力进行进一步的强化（jiamo）。\n" NOR);
                set("unit", "块");
				set("no_get", 1);
				set("no_give", 1);
				set("shop", 1);
				set("no_drop", 1);
				set("no_sell", 1);
				set("no_steal", 1);
                set("dajif", 399);
        }
        setup();
}

void init()
{
        add_action("do_integrate", "jiamo");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string ownerid;
		int i;

        if (! arg)
                return notify_fail("你要往什么道具上使用上帝之心？\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("你身上和附近没有这样道具啊。\n");

        if( ob->query("magic/power")<10 )
                return notify_fail(ob->name() + "连十级武器都不是，还想晋升。\n");
		if( ob->query("magic/power")>500)
                return notify_fail(ob->name() + "已经是无上神器了。\n");

        if (!ob->is_weapon() && !ob->is_unarmed_weapon())
                return notify_fail("你只能在兵器上使用上帝之心。\n");
		i=5+random(15);
        ownerid = ob->item_owner();

        ob->add("magic/power", i);
        ob->save();

        tell_object(me, "你把" + name() + "盖在" + ob->name() + "上，然后口中念念有词，\n"
                        "只见上帝之心化作一道金光飞入" + ob->name() + "体内！\n");

        tell_object(me, HIC "你感受" + ob->name() + HIC"发生了不可言喻的变化。魔力+"+i+"\n" NOR);

        destruct(this_object());
        return 1;
}