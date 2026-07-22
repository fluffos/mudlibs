// add.h
#include <ansi.h>
int do_hehe(object me, object obj, object dest);
int do_add(string arg)
{
        string arg1, arg2;
        object obj, dest, *inv, obj2;
        object ob = this_player();
        object me = this_object();
        int i, amount;
        dest = present("dan lu", environment(ob));

        if( ob->is_busy() ) 
                return notify_fail("你正忙着呢。\n");

        if( ob->is_fighting() )
                return notify_fail("你正在战斗中！\n");

        if(!arg || sscanf(arg, "%s in %s", arg1, arg2)!=2)
                return notify_fail("请用<add 药材名 in lu>来把物品放进丹炉。\n");

        if (arg2!="lu")
                return notify_fail("请用<add 药材名 in lu>来把物品放进丹炉。\n");

        if( !me->query("marks/open", 1) )
        return notify_fail("丹炉的盖子没有打开。\n");

        if( objectp(obj = present(arg1, ob)) && !obj->query("make/drug", 1) ) // 如果此物品没有make/drug的属性，不能放进丹炉
                return notify_fail(obj->name()+"不能用来做为制药的原料。\n");

        if( !dest || living(dest) )
                return notify_fail("这里没有这样东西。\n");

        if(sscanf(arg1, "%d %s", amount, arg1)==2) {
                if( !objectp(obj = present(arg1, ob)) )
                        return notify_fail("你身上没有这样东西。\n");
                if( objectp(obj = present(arg1, ob)) && !obj->query("make/drug", 1) )
                        return notify_fail("这种东西不能用来做为制药的原料。\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分开。\n");
                if( amount < 1 )
                        return notify_fail("东西的数量至少是一个。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("你没有那么多的" + obj->name() + "。\n");
                else if( amount == (int)obj->query_amount() )
                        return do_hehe(ob, obj, dest);
                else {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        if (do_hehe(ob, obj2, dest)) return 1;
                        obj2->move(ob);
                        return 0;
                }
        }

        if(arg1=="all") {
                inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++)
                        if( inv[i] != dest || !(inv[i]->query("make/drug", 1)) )
                                return notify_fail("这种东西不能用来做为制药的原料。\n");
                        do_hehe(ob, inv[i], dest);
                write("Ok.\n");
                return 1;
        }
        if(!objectp(obj = present(arg1, ob)))
                return notify_fail("你身上没有这样东西。\n");

        return do_hehe(ob, obj, dest);
}

int do_hehe(object ob, object obj, object dest)
{
        object me;
        me = present("dan lu", environment(ob));
        if (!wizardp(ob) && obj->query("no_drop"))
                return notify_fail(stringp(obj->query("no_drop"))?
                        obj->query("no_drop"):"这样东西无法离开你。\n");

        if (obj == dest) return notify_fail("把你放进你的身体？\n");
        if( obj->move(dest) ) {
                message_vision( sprintf("$N将一%s%s放进%s。\n",
                        obj->query("unit"), obj->name(), dest->name()),
                        ob );
                return 1;
        }
        return 0;
}