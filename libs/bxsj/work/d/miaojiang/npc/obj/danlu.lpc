//danlu.c 丹炉 
//是为了quest制作的，无法炼制其他药类
//开炉、加药、加水、关炉、点火、扇风、熬药、灭火、取药
//成功率100%

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
int do_hehe(object me, object obj, object dest);
int do_haha(object ob, object obj);

void create()
{
       set_name(HIR"丹炉"NOR, ({ "dan lu", "lu", "yao lu" }) );
       set_weight(3000000);
       set_max_encumbrance(2000);

       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "个");
               set("no_get", "丹炉对你来说太重了。\n");
               set("no_get_from", 1);
               set("long", "这是一个用来炼丹制药的丹炉。\n"NOR);
               set("value", 100000000);
               set("no_get",1);                 
               set("no_give",1);
               set("no_put",1);
               set("no_drop",1);           
               set("max_liquid", 100);
               set("material", "iron");
               set("marks/open", 0);
       }
       setup();
}
                   
int is_container() { return 1; }

void init()
{
        add_action("do_open", "open"); // open lid
        add_action("do_add",   "add"); // add xxx in lu
        add_action("do_pour", "pour"); // pour water
        add_action("do_close", "close"); // clone lid
        add_action("do_fire", "dianhuo"); // fire
        add_action("do_burn", "burn"); // burn coal  
        add_action("do_aoyao", "aoyao"); // aoyao
        add_action("do_miehuo", "miehuo"); // mie huo
        add_action("do_qu", "qu"); // qu yao from lu
        add_action("do_action", "put"); //forbid these two commands
}

int do_action(string arg)
{
        write("请用(add 药材名 in lu)命令向丹炉内添加药材。\n");
        write("请用(qu 药材名 from lu)命令从丹炉内拿出药材。\n");
        return 1;
}
int do_open(string arg)
{
        object me, ob;
        me = this_object();
        ob = this_player();
        
        if( ob->is_busy() ) 
                return notify_fail("你正忙着呢。\n");

        if( ob->is_fighting() )
                return notify_fail("你正在战斗中。\n");
        if( !arg || arg == "" || arg != "lu")
                return notify_fail("你要打开什么？\n");

        if( me->query("marks/open") )           // 判断丹炉盖子打开还是关上的。
                return notify_fail("丹炉的盖子已经是打开的了。\n");

        if( me->query("marks/doing") 
         || me->query("marks/aoyao")
         || me->query("marks/fired"))           // 如果有人正在炼丹，不能开盖子。
              {
                message_vision(RED"\n$N突然手尖一阵巨痛，手指被火燎了一下。\n"NOR,ob);
                return 1;
              }

    if( arg == "lu" )
        {
                message_vision("$N把丹炉的盖子打开。\n", ob);
                me->set("marks/open", 1);       // 如果打开盖子加此标记。
                return 1;
        }

}
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

        if( !me->query("marks/open") )   return notify_fail("丹炉的盖子没有打开。\n");

        if( objectp(obj = present(arg1, ob)) && !obj->query("make/drug") ) // 如果此物品没有make/drug的属性，不能放进丹炉
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

        if (obj == dest) return notify_fail("把你放进你的身体？\n");
        if( obj->move(dest) ) {
                message_vision( sprintf("$N将一%s%s放进%s。\n",
                        obj->query("unit"), obj->name(), dest->name()),
                        ob );
                return 1;
        }
        return 0;
}
int do_pour(string arg)
{
        string hehe, what;
        object me, ob, obj;
        me = this_object();
        ob = this_player();
        if( !arg
        ||  sscanf(arg, "%s to %s", hehe, what) != 2)
                return notify_fail("请用<pour 容器 to lu>来把水放进丹炉。\n");

        if( ob->is_busy() ) 
                return notify_fail("你正忙着呢。\n");

        if( ob->is_fighting() )
                return notify_fail("你正在战斗中！\n");

        if( !me->query("marks/open") )
                return notify_fail("丹炉的盖子没有打开。\n");

        if( !objectp( obj = present(hehe, ob)))   // 如果你身上的物品的ID不对，不能往丹炉里加水。
                return notify_fail("你身上没有"+hehe+"，如何往丹炉里加水？\n");
                
        if( !obj->query("liquid/type"))           // 如果你身上的物品不是盛水的器皿，不能往丹炉里加水。
                return notify_fail(obj->name()+"不是盛水的器皿！\n");

        if( !obj->query("liquid/remaining") )     // 判断你身上盛水的器皿中是否还有水。
                return notify_fail(obj->name() + "里面已经一滴不剩了。\n");

        message_vision("$N将一些"+ obj->query("liquid/name") +"从"+ obj->name() +"倒进丹炉。\n", ob);
        obj->add("liquid/remaining", -1);
        me->add("liquid/remaining", 1);
        me->set("liquid/name", obj->query("liquid/name"));
        return 1;
}
int do_close(string arg)
{
        object me, ob;
        me = this_object();
        ob = this_player();
        
        if( ob->is_busy() ) 
                return notify_fail("你正忙着呢。\n");

        if( ob->is_fighting() )
                return notify_fail("你正在战斗中。\n");

        if( !arg || arg == "" || arg != "lu")
                return notify_fail("你要关什么？\n");

        if( !me->query("marks/open") )      // 判断此时丹炉的盖子是打开还是关上的
                return notify_fail("丹炉的盖子没有打开。\n");

    if( arg == "lu" )
        {
          message_vision("$N轻手轻脚的将丹炉的盖子盖上。\n", ob);
          me->delete("marks/open");           // 如果有人把丹炉的盖子关上，那么去掉此标记。
          return 1;
        }

}
int do_fire(string arg)
{
        object obj;
        object me = this_object();
        object ob = this_player();
        object *inv;
        inv = deep_inventory(me);

        if( ob->is_busy() ) 
                return notify_fail("你正忙着呢。\n");

        if( ob->is_fighting() )
                return notify_fail("你正在战斗中。\n");

        if( me->query("marks/open") )
                return notify_fail("丹炉的盖子没有盖上。\n");
        
        if( !objectp( obj = present("fire", ob)))   // 判断玩家身上是否有火折。
                return notify_fail("你需要一个火折。\n");
                
        if( (int)ob->query("neili")  <= 1000 )
                return notify_fail("你的内力不够，点着了火也拉不动风箱。\n");           
                
        if( (int)ob->query("max_neili")  <= 1500 )
                return notify_fail("你的内力不够，点着了火也拉不动风箱。\n");                           

        if( me->query("marks/fired"))
                return notify_fail("柴火已经点起来了。\n");   
                
        if( !me->query("liquid/name") )
                return notify_fail("丹炉里没有水。\n");  
                
        if( !sizeof(inv)) 
                return notify_fail("丹炉里面什么都没有。\n");
                
        message_vision(HIR"\n$N点燃一堆柴火，火苗渐渐地大了起来。\n"NOR, ob);
        //destruct(obj);
        me->set("marks/fired", 1);
        me->set("marks/doing", 1);  
        //ob->set_temp("doing", 1);
        remove_call_out("do_check");
        call_out("do_check", 300);//没有参数ob,药成功不成功和玩家无关
        return 1;
}

void do_check()
{
        object me = this_object();
        if ( (int)me->query("marks/doing") > 0) 
        {
           remove_call_out("do_failed");
           call_out("do_failed",0);
        }
        return;
}

int do_burn(string arg)
{
        object me, ob;
        me = this_object();
        ob = this_player();

        if( ob->is_busy() ) 
                return notify_fail("你正忙着呢。\n");

        if( ob->is_fighting() )
                return notify_fail("你正在战斗中。\n");

        if( me->query("marks/open") )
                return notify_fail("丹炉的盖子没有盖上。\n");

        if( !me->query("marks/fired") )
                return notify_fail("丹炉内还没有生火，你怎么能够使柴火燃烧起来？\n");

        if( me->query("marks/burned"))
                return notify_fail("丹炉里的火焰已经很大了，不用再加大火力了。\n");

        if( !arg || arg =="" || arg != "lu")
                return notify_fail("你要燃烧什么东西？\n"); 
                
        if( (int)ob->query("neili")  <= 1000 )
                return notify_fail("你的内力不够，点着了火也拉不动风箱。\n");           
                
        if( (int)ob->query("max_neili")  <= 1500 )
                return notify_fail("你的内力不够，点着了火也拉不动风箱。\n");                           

        message_vision(HIC"\n$N使劲地拉动风箱，丹炉里冒出阵阵青烟。\n"NOR, ob);
        remove_call_out("do_ready");
        call_out("do_ready", 2);
        me->set("marks/burned", 1);
        ob->add("neili", -1000);
        ob->add("jingli", -500);
        ob->start_busy(3);
        return 1;
}

void do_ready()
{
        object me = this_object();
        message_vision(HIW"\n火势渐渐大了起来，一股浓重的草药味道扑鼻而来。应该熬药了。\n"NOR, me);
        remove_call_out("do_confirm");
        call_out("do_confirm", 15);
        return;
}

void do_confirm()
{
        object me = this_object();

        if( me->query("marks/aoyao") ) 
        {
                remove_call_out("confirm");
                remove_call_out("ready");
                message_vision(HIR"\n药快熬好了，赶紧灭火吧！\n"NOR, me);
                remove_call_out("do_check");
                call_out("do_check", 70);
                me->set("marks/aoyao_done", 1);
        }
        else 
        {
                message_vision(HIY"一股焦糊味道扑鼻而来。\n"NOR, me);
                remove_call_out("do_failed"); 
                call_out("do_failed", 1);
        }
        return;
}
void do_failed()
{
        object me = this_object();
        object *obj;
        int i;
        obj = deep_inventory(me);
        if( !sizeof(obj) )      return;
        for(i=0; i<sizeof(obj); i++) {
        destruct(obj[i]);
        }
        message_vision("丹炉里面一片焦黑，$N什么丹药也没练出来。\n", me);
        remove_call_out("do_ready");
        remove_call_out("do_confirm");
        me->delete("marks/aoyao_done");
        me->delete("marks/aoyao");
        me->delete("marks/open");
        me->delete("marks/fired");
        me->delete("marks/doing");
        me->delete("liquid/remaining");
        me->delete("liquid/name");
        me->delete("marks/burned");
        return;
}

int do_aoyao(string arg)
{
    object me, ob;
    me = this_object();
    ob = this_player();

    if( ob->is_busy() ) 
            return notify_fail("你正忙着呢。\n");

    if( ob->is_fighting() )
            return notify_fail("你正在战斗中。\n");

    if( me->query("marks/open")) 
            return notify_fail("丹炉的盖子没有盖好。\n");

    if( !me->query("marks/burned") ) 
            return notify_fail("火势还不旺盛。\n");               

    message_vision(HIY"\n$N使劲全身的力气，不断的搅拌丹炉内的药汤，累的满身是汗。\n"NOR, ob);
    me->set("marks/aoyao", 1);
    ob->start_busy(2);
    return 1;
}

int do_miehuo(string arg)
{
        object me, ob;
        object *inv;
        me = this_object();
        ob = this_player();
        inv = deep_inventory(me);
        if( ob->is_busy())
                return notify_fail("你正忙着呢。\n");
        if( ob->is_fighting())
                return notify_fail("你正在战斗。\n");
        if( !sizeof(inv))
                return notify_fail("炉子里面没有东西。\n");
        if( me->query("marks/open") )
                return notify_fail("炉子正开着呢，瞎灭什么火？\n");
        if( !me->query("marks/doing") && !me->query("marks/fired") )
                return notify_fail("炉子还没点火！\n");
        if( !me->query("marks/aoyao_done") )
                return notify_fail("你还没熬完药呢！\n");

        message_vision("\n$N把丹炉内的柴火渐渐地熄灭了。\n", ob);
        remove_call_out("do_drug");
        remove_call_out("do_check");
        remove_call_out("do_ready");
        remove_call_out("do_confirm");
        remove_call_out("do_failed");
        call_out("do_drug", 3 , me);
        me->delete("marks/aoyao");
        me->delete("marks/fired");
        me->delete("marks/burned");
        me->delete("marks/doing");
        ob->start_busy(4);
        return 1;

}

void do_drug()
{
        int a, b, i, c, d, e;
        object *inv;
        object me = this_object();
        inv = deep_inventory(me);

        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        if( sizeof(inv))
        {
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->query("id") == "qixing haitang")
                        {
                                a = a+1;
                         }
                        if( inv[i]->query("id") == "lanse yaohua")
                        {
                                b = b+1;
                         }
                        if( inv[i]->query("id") == "zang honghua")
                        {
                                c = c+1;
                         }
                        if( inv[i]->query("id") == "jinyin hua")
                        {
                                d = d+1;
                         }
                        if( inv[i]->query("id") == "ren shen")
                        {
                                e = e+1;
                         }
                }

// ok
                if( a>= 1   
                && b >= 1
                && c >= 1
                && d >= 1
                && e >= 1 )
                {
                 remove_call_out("do_ok");
                 call_out("do_ok", 0);
                }
                else
                {
                remove_call_out("do_failed"); 
                call_out("do_failed", 1);
                }
        }
        return;
}

void do_ok()
{       
        object me = this_object();
        object jieyao;
        object *obj;
        int i;
        obj = deep_inventory(me);
        if( !sizeof(obj) )      return;
        for(i=0; i<sizeof(obj); i++) {
        destruct(obj[i]);
        }
        me->delete("liquid/remaining");
        me->delete("liquid/name");   
        jieyao=new("/d/miaojiang/npc/obj/jieyao");
        jieyao->move(me);
        return;
}
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

        if( !wizardp(ob) && obj->query("no_get") && obj->query("id")!="jie yao") {
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
                if( !wizardp(ob) && obj->query("no_get") && obj->query("id")!="jie yao") return 0;
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
                ob->start_busy(9);
                  if(obj->query("id")=="jie yao") obj->set("owner",ob->query("id"));
                return 1;
        }
        else return 0;
}
