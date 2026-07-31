// xiang.c 

#include <ansi.h> 

inherit ITEM;
inherit F_NOCLONE; 
inherit F_OBSAVE; 

#define TO_STORE(x, y) (["name" : ob->query("name"), "id" : ob->query("id"), "file" : base_name(ob), "amount" : x, "sign" : y])

int is_item_make() { return 1; } 

int do_store(string arg);
int do_take(string arg);
int do_view(string arg);
int store_item(object me, object obj, int amount);
int store_data(object me, object ob, int sn);

int clean_up() { return 1; }

void create()
{
        set_name(HIY "漫游传送包" NOR, ({ "cruise ob", "cruise" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {          
                set("long", "一个四周边缘环绕着神秘光环的漫游传送包，据说"
                            "可以将东西无限制的存（store）进去,不会"
                            "丢失，且无论什么时候都可以取（take）出"
                            "来，最关键是还可以使用它将物品漫游到其他站。");
                                
                set("unit", "个");
                set("no_sell", 1);
        }
        setup();
        ::restore();
}

void init() 
{
        add_action("do_view", ({ "view", "cha" }));
        add_action("do_store", ({ "store", "cun" }));
        add_action("do_take",  ({ "take",  "qu"  }));    
}

int do_view(string arg)
{
        object me;
        mixed ob_name_real_len;
        string msg, ob_name;
        mapping *store;

        me = this_player();

        if (! id(arg))
                return notify_fail("你要查看什么？\n");
        
        store = query("store");
                
        if (! store || sizeof(store) < 1)
                return  notify_fail("你目前没有存放任何物品在漫游传送包里。\n");     

        msg = HIW "\n目前你存放的物品有：\n编号  物品                                      数量\n"
                  "──────────────────────────\n" NOR;
              
        for (int i = 0; i < sizeof(store); i++) 
        {
                ob_name = filter_color(store[i]["name"] + "(" + store[i]["id"] + ")"); 
                ob_name_real_len = color_len(store[i]["name"] + "(" + store[i]["id"] + ")");
                msg += sprintf("[%2d]  %-" + (36 + ob_name_real_len) + "s     %5d\n", 
                               i + 1, store[i]["name"] + "(" + store[i]["id"] + ")",  
                               store[i]["amount"]);
                if (store[i]["amount"] == 0)
                        store[i] = 0;
        }
        msg += HIW "──────────────────────────\n" NOR;
        this_player()->start_more(msg);
        store -= ({ 0 });
        set("store", store);
        return 1;
}        

int do_take(string arg)
{
        object me, ob;
        int i, j, sn, amount, amount1;
        mapping data;
        string *ks;
        mapping *store;
        mapping *data_dbase;
        mapping *temp_dbase;
                
        me = this_player();

        if (! arg || sscanf(arg, "%d %d", amount, sn) != 2) 
                return notify_fail("格式错误，请用 take 数量 编号 来取回物品。\n");

        if (amount < 1 || amount > 2000) 
                return notify_fail("每次取物品的数量不得小于一同时也不能大于两千。\n");
                
        if (sn < 1) return notify_fail("你要取第几号物品？\n");
        
        store = query("store");
        if (! store || sizeof(store) < 1 || sn > sizeof(store)) 
                return notify_fail("你的漫游传送包里没有存放这项物品。\n");        
                
        if (amount > store[sn-1]["amount"]) 
                return notify_fail("这样物品你没有那么多个。\n");

        ob = new(store[sn-1]["file"]);
        if (me->query_encumbrance() + ob->query_weight() * amount > me->query_max_encumbrance()) 
        {
                tell_object(me, "你的负重不够，无法一次取出这么多物品。\n");
                destruct(ob);
                return 1;
        }

        store[sn-1]["amount"] -= amount;

        if (ob->query_amount()) 
        {
                if (store[sn-1]["amount"] == 0) 
                {
                        store[sn-1] = 0;
                        store -= ({ 0 });
                }
                ob->set_amount(amount);
                ob->move(me);
                set("store", store);
                save();
                                
                message_vision("$N从漫游传送包里取出一" +
                                ob->query("unit") + ob->query("name") + "。\n", me);
                return 1;
        }
        
        destruct(ob);
        
        amount1 = amount;
        
        data_dbase = query("data_dbase");   
        temp_dbase = query("temp_dbase");                  
        while (amount1--) 
        {
                ob = new(store[sn-1]["file"]);
                if (data_dbase && sizeof(data_dbase) > 0)
                {
                        for (i = 0; i < sizeof(data_dbase); i++)
                        {
                                if (data_dbase[i]["sign"] == store[sn-1]["sign"])
                                {
                                        data = data_dbase[i];
                                        ks = keys(data);
                                        for (j = 0; j < sizeof(ks); j++) 
                                        {
                                                if (ks[j] == "sign") continue;                            
                                                ob->set(ks[j], data[ks[j]]);
                                        }                                        
                                        data_dbase[i] = 0;
                                }
                        }
                        data_dbase -= ({ 0 });
                }
                if (temp_dbase && sizeof(temp_dbase) > 0)
                {
                        for (i = 0; i < sizeof(temp_dbase); i++)
                        {
                                if (temp_dbase[i]["sign"] == store[sn-1]["sign"])
                                {
                                        data = temp_dbase[i];
                                        ks = keys(data);
                                        for (j = 0; j < sizeof(ks); j++) 
                                        {
                                                if (ks[j] == "sign") continue;                            
                                                ob->set_temp(ks[j], data[ks[j]]);
                                        }
                                        temp_dbase[i] = 0;
                                }
                        }
                        temp_dbase -= ({ 0 });  
                }   
                
                if(ob->short() != store[sn-1]["name"] + "(" + store[sn-1]["id"] + ")") 
                { 
                        amount1++;
                        destruct(ob);
                        continue;
                }                           
                ob->move(me);
        }

        message_vision("$N从漫游传送包里取出" + chinese_number(amount) + 
                        ob->query("unit") + ob->query("name") + "。\n", me);
                                
        if (store[sn-1]["amount"] == 0) 
        {
                store[sn-1] = 0;
                store -= ({ 0 });
        }
        set("store", store);
        set("data_dbase", data_dbase);
        set("temp_dbase", temp_dbase);
        save();
        return 1;
}

int do_store(string arg)
{
        int i, amount;
        string item;
        object me, ob1, ob2, *inv;
        mapping *store;

        me = this_player();

        if (! arg) return notify_fail("你要存放什么东西？\n");
        
        store = query("store");
        if (store && sizeof(store) > 200)
                return notify_fail("漫游传送包最多只能存入两百个格子，现在漫游传送包已经满了。\n");
                
        if (sscanf(arg, "%d %s", amount, item) == 2) {

                if(! objectp(ob1 = present(item, me)))
                        return notify_fail("你身上没有这样东西。\n");

                /*
                if (! inherits(ITEM, ob1) && ! inherits(COMBINED_ITEM, ob1))
                        return notify_fail("对不起，你不能存放该物品。\n");
                */
                if (inherits(F_SILENTDEST, ob1))
                        return notify_fail("对不起，你不能存放该物品。\n");

                if (member_array(ITEM + ".lpc", deep_inherit_list(ob1)) == -1 &&
                    member_array(COMBINED_ITEM + ".lpc", deep_inherit_list(ob1)) == -1)
                        return notify_fail("对不起，你不能存放该物品。\n");

                if(member_array(MONEY+ ".lpc", deep_inherit_list(ob1)) != -1)
                        return notify_fail("要存钱请去钱庄吧。\n");

                if(base_name(ob1) == "/clone/misc/corpse" ||
                   base_name(ob1) == "/clone/misc/head" ||
                   base_name(ob1) == "/clone/misc/part")
                        return notify_fail("漫游传送包不保存" + ob1->query("name") + "，请你自己妥善处理。\n");

                if (sscanf(base_name(ob1), "/data/%*s"))
                        return notify_fail("漫游传送包不保存" + ob1->query("name") + "，请你自己妥善处理。\n");
                        
                if (! ob1->query_amount())
                        return notify_fail(ob1->name() + "不能被分开存放。\n");

                if (amount < 1)
                        return notify_fail("东西的数量至少是一个。\n");

                if (amount > ob1->query_amount())
                        return notify_fail("你没有那么多的" + ob1->name() + "。\n");

                else 
                if (amount == (int)ob1->query_amount())
                        return store_item(me, ob1, amount);

                else 
                {
                        ob1->set_amount((int)ob1->query_amount() - amount);
                        ob2 = new(base_name(ob1));
                        ob2->set_amount(amount);
                        if(! store_item(me, ob2, amount)) 
                        {
                                ob2->move(me);
                                return 0;
                        }
                        return 1;
                }
        }
 
        if (arg == "all") 
        {

                inv = all_inventory(me);

                for(i = 0; i < sizeof(inv); i++) 
                        do_store(inv[i]->query("id"));

                return 1;
        }

        if(! objectp(ob1 = present(arg, me)))
                return notify_fail("你身上没有这样东西。\n");

        if (member_array(ITEM + ".lpc", deep_inherit_list(ob1)) == -1 &&
            member_array(COMBINED_ITEM + ".lpc", deep_inherit_list(ob1)) == -1)
                return notify_fail("对不起，你不能存放该物品。\n");      

        if(member_array(MONEY + ".lpc", deep_inherit_list(ob1)) != -1)
                return notify_fail("要存钱请去钱庄吧。\n");

        if(base_name(ob1) == "/clone/misc/corpse")
                return notify_fail("漫游传送包不保存" + ob1->query("name") + "，请你自己妥善处理。\n");

        if (sscanf(base_name(ob1), "/data/%*s"))
                return notify_fail("漫游传送包不保存" + ob1->query("name") + "，请你自己妥善处理。\n");

        if (ob1->query_amount()) 
                return do_store(ob1->query_amount() + " " + arg);

        store_item(me, ob1, 1);
        return 1;
}

int store_item(object me, object ob, int amount)
{
        object obj;
        int i, n, sn;
        mapping *store;

        if (ob->query("unique") || ! clonep(ob) || 
            ob->query("id") == "pass")
        {
                tell_object(me, "这样物品不能储存在漫游传送包里的。\n");
                return 1;
        }

        if(sscanf(base_name(ob), "/data/%*s"))
        {
                tell_object(me, "这样物品不能储存在漫游传送包里的。\n");
                return 1;
        }

        switch((string)ob->query("equipped")) 
        {
        case "worn":
                tell_object(me, ob->name() + "必须先脱下来才能存放。\n");
                return 1;
        case "wielded":
                tell_object(me, ob->name() + "必须先解除装备才能存放。\n");
                return 1;
        }

        if (! objectp(ob)) 
        {
                error("no this object!\n");
                return 1;
        }
        
        if (sizeof(all_inventory(ob))) 
        {
                tell_object(me, "请你先把" + ob->query("name") + "里面的东西先拿出来。\n");
                return 1;
        }
        
        store = query("store");
        if (! store) store = ({});
        
        n = sizeof(store);

        obj = new(base_name(ob));
        if (ob->query("startroom"))
                ob->delete("startroom");

        if (! ob->query_amount()) 
        { 
                if (! compare_mapping(ob->query_entire_temp_dbase(), obj->query_entire_temp_dbase()) || 
                    ! compare_mapping(ob->query_entire_dbase(), obj->query_entire_dbase()))
                {                        
                        sn = time() + random(99999999);
                        store += ({TO_STORE(amount, sn)});
                        set("store", store);
                        store_data(me, ob, sn);
                        save();
                
                        message_vision("$N存入" + chinese_number(amount) + ob->query("unit") + 
                                        ob->query("name") + "到漫游传送包里。\n", me);             
                        destruct(ob);
                        destruct(obj);
                        return 1;
                } 
        }
        destruct(obj);        
        for (i = 0; i < n; i++) 
        {
                if (store[i]["id"] == ob->query("id") && 
                    store[i]["name"] == ob->query("name") && 
                    store[i]["file"] == base_name(ob)) 
                {
                        store[i]["amount"] += amount;
                        
                        message_vision("$N存入" + (amount > 1 ? "一" : chinese_number(amount)) +
                                        ob->query("unit") + ob->query("name") + "到漫游传送包里。\n", me);                               
                        destruct(ob);
                        set("store", store);
                        save();
                        return 1;
                }
        }

        store += ({TO_STORE(amount, 0)});
        set("store", store);
        save();

        message_vision("$N存入" + (amount > 1 ? "一" : chinese_number(amount)) +
                        ob->query("unit") + ob->query("name") + "到漫游传送包里。\n", me);           

        destruct(ob);
        return 1;
}

int store_data(object me, object ob, int sn)
{
        mapping data;
        mapping *data_dbase;
        mapping *temp_dbase;

        data_dbase = query("data_dbase");
        if (! data_dbase) 
                data_dbase = ({});
        data = ob->query_entire_dbase();
        data += ([ "sign" : sn ]);
        data_dbase += ({data});
        set("data_dbase", data_dbase);
        
        temp_dbase = query("temp_dbase");
        if (! temp_dbase)
                temp_dbase = ({});
                
        data = ob->query_entire_temp_dbase();
        
        if (! data) return 1;
        
        data += ([ "sign" : sn ]);        
        temp_dbase += ({data});
        set("temp_dbase", temp_dbase);
        return 1;
}

int receive_summon(object me)
{
        object env;

        if ((env = environment()) && env == me)
        {
                write(name() + "不就在你身上嘛？你召唤个什么劲？\n");
                return 1;
        }

        if (env == environment(me))
        {
                message_vision(HIG "只见地上的" + name() +
                               HIG "化作一道光芒，飞跃至$N" HIW
                               "的掌中！\n\n" NOR, me);
        } else
        {
                if (env)
                {
                        if (env->is_character() && environment(env))
                                        env = environment(env);

                        message("vision", HIG "突然" + name() + HIG "化作一道"
                                HIG "光芒消失了！\n\n" NOR, env);

                        if (interactive(env = environment()))
                        {
                                tell_object(env, HIM + name() +
                                                 HIM "忽然离你而去了！\n" NOR);
                        }
                }

                message_vision(HIG "一道光芒划过，只见$N"
                               HIG "掌中多了一个$n" HIG "！\n\n" NOR,
                               me, this_object());
        }

        move(me, 1);
        if (environment() != me)
                return 1;

        return 1;
}

int hide_anywhere(object me)
{
        if (me->query("jingli") < 100)
        {
                tell_object(me, "你试图令" + name() +
                            "遁去，可是精力不济，难以发挥它的能力。\n");
                return 0;
        }
        me->add("jingli", -100);

        message_vision(HIM "$N" HIM "轻轻一旋" + name() +
                       HIM "，已然了无踪迹。\n", me);
        save();
        destruct(this_object());
        return 1;
}
int remove()
{
        save();
}

// 接受存盘数据的接口函数
int receive_dbase_data(mixed data)
{
        if (! mapp(data))
                return 0;                

        if (data["store"])
                set("store", data["store"]);
        
        if (data["data_dbase"])
                set("data_dbase", data["data_dbase"]);
        
        if (data["temp_dbase"])
                set("temp_dbase", data["temp_dbase"]);
                
        return 1;
}

// 进行保存数据的接口函数
mixed save_dbase_data()
{
        mapping data;
        object  user;

        data = ([ ]);
        
        if (query("store"))
                data += ([ "store" : query("store") ]);

        if (query("data_dbase"))
                data += ([ "data_dbase" : query("data_dbase") ]);
                
        if (query("temp_dbase"))
                data += ([ "temp_dbase" : query("temp_dbase") ]);

        return data;
}

