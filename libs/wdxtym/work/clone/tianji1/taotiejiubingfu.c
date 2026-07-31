#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIM "饕餮九兵符" NOR, ({ "taotiejiubing fu" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "饕餮九兵可以将普通自造兵器升级(upd)为九兵武器，可直接在此基础上进行镶嵌上帝之眼操作。\n" NOR);
                set("unit", "张");
								set("no_get", 1);
				set("no_give", 1);
				set("no_shop", 1);
				set("no_drop", 1);
				set("max_buy",9);
				set("no_sell", 1);
				set("no_steal", 1);
                set("tianji1", 5);
        }
        setup();
}

void init()
{
        add_action("do_integrate", "upd");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string ownerid;

        if (! arg)
                return notify_fail("你要往什么道具上使用该圣符？\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("你身上和附近没有这样道具啊。\n");

        if( ob->query("magic/imbue_ok") )
                return notify_fail(name() + "已经是准10LVL以上兵器，没有这个必要吧。\n");

        if (!ob->is_weapon() && !ob->is_unarmed_weapon())
                return notify_fail("你只能在兵器上使用该圣符。\n");

        ownerid = ob->item_owner();

        ob->add("combat/MKS", 2100);
        ob->add("owner/"+ownerid, 21000000);
        ob->set("magic/imbue_ok", 1);
        ob->add("magic/blood", 21000);
        ob->save();

        tell_object(me, "你把" + name() + "盖在" + ob->name() + "上，然后口中念念有词，\n"
                        "只见圣符化作一道红光飞入" + ob->name() + "体内！\n");

        tell_object(me, HIC "你感受" + ob->name() + HIC"发生了不可言喻的变化。\n" NOR);

        destruct(this_object());
        return 1;
}