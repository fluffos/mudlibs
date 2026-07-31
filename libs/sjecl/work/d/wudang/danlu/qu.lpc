// qu.h
int do_haha(object ob, object obj);
int do_qu(string arg)
{
        string arg1, arg2;
        object obj, *inv, env, obj2;
        object me = this_object();
        object ob = this_player();
        int i, amount;
        if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
                return notify_fail("这里没有这样东西。\n");

        if (arg2!="lu")
                return notify_fail("这里没有这样东西。\n");

        if( !me->query("marks/open") )
        return notify_fail("丹炉的盖子没有打开。\n");
                
        if( ob->is_busy() )
                return notify_fail("你正在忙。\n");

        if( sscanf(arg, "%s from %s", arg, arg1)==2 ) {
                env = present(arg1, ob);
                if(!env) env = present(arg1, environment(ob));
                if(!env) return notify_fail("你找不到 " + arg1 + " 这样东西。\n");
                if(living(env) && (wiz_level(me) <= wiz_level(env)))
                        return notify_fail("你的巫师等级必须比对方高，才能搜身。\n");
        } else env = environment(ob);
        if (!wizardp(me) && env->query("no_get_arg1"))
                return notify_fail("光天化日的想抢劫啊？\n");

        if(sscanf(arg, "%d %s", amount, arg1)==2) {
                if( !objectp(obj = present(arg1, env)) )
                        return notify_fail("这里没有这样东西。\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分开拿走。\n");
                if( amount < 1 )
                        return notify_fail("东西的个数至少是一个。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("这里没有那么多的" + obj->name() + "。\n");
                else if( amount == (int)obj->query_amount() ) {
                        return do_haha(ob, obj);
                } else {
                        obj2 = new(base_name(obj));
                        obj2->set_amount( obj->query_amount() - amount);
                        obj->set_amount( amount );

                        if( ob->is_fighting() ) ob->start_busy(3);
                        if (do_haha(ob, obj)) {
                                obj2->move(env);
                                return 1;
                        }
                        obj2->move(env);
                        return 0;
                }
        }

        if(arg=="all") {
                if( ob->is_fighting() ) return notify_fail("你还在战斗中！只能一次拿一样。\n");
                if( !env->query_max_encumbrance() )     return notify_fail("那不是容器。\n");

                inv = all_inventory(env);
                if( !sizeof(inv) )
                        return notify_fail("那里面没有任何东西。\n");

                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
                        do_haha(ob, inv[i]);
                }
                write("Ok。\n");
                return 1;
        }

        if( !objectp(obj = present(arg, env)) || living(obj) )
                return notify_fail("你附近没有这样东西。\n");

        if( !wizardp(ob) && obj->query("no_get") ) {
                if (stringp(obj->query("no_get")))
                        return notify_fail(obj->query("no_get"));
                return notify_fail("这个东西拿不起来。\n");
        }
        
        return do_haha(ob, obj);
}
        
int do_haha(object ob, object obj)
{
        object old_env;
        int equipped;

        if( !obj ) return 0;
        old_env = environment(obj);

        if( obj->is_character() ) {
                if( living(obj) ) return 0;
        } else {
                if( !wizardp(ob) && obj->query("no_get") ) return 0;
        }

        if( obj->query("equipped") ) equipped = 1;
        if( obj->move(ob) ) {
                if( ob->is_fighting() ) ob->start_busy(1);
                if( obj->is_character() )
                        message_vision( "$N将$n扶了起来背在背上。\n", ob, obj );
                else
                        message_vision( sprintf("$N%s一%s$n。\n", 
                                old_env==environment(ob)? "捡起":
                                        (old_env->is_character() ?
                                                "从" + old_env->name() + "身上" + (equipped? "除下" : "搜出"):
                                                "从" + old_env->name() + "中拿出"),
                                obj->query("unit")), ob, obj);
                ob->start_busy(90);
                return 1;
        }
        else return 0;
}
