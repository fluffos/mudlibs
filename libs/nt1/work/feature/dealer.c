// dealer.c 商人
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands
// Modified by Lonely for add pawn, redeem, check 3 commands

#pragma save_binary
#include <ansi.h>
#include <dbase.h>
#include <name.h>
#include <config.h>

string is_vendor_good(string arg)
{
        mixed goods;
        object ob;
        int i;

        goods = query("vendor_goods");
        if (mapp(goods))
                goods = keys(goods);

        if (arrayp(goods))
                for (i = 0; i < sizeof(goods); i++) 
		{
                        if (goods[i]->id(arg)) return goods[i];
			if (filter_color(goods[i]->name(1)) == arg)
				return goods[i];
		}
        return "";
}

int do_value(string arg)
{
        object ob;
        int value;
        mixed ns;

        if (! arg || ! (ob = present(arg, this_player())))
        {
                return notify_fail("你要估什么的价？\n");
        }
        
        if (ob->query("money_id"))
        {
                write(CYN + name() + "道：你没用过钱啊？\n" NOR);
                return 1;
        }

        if (ob->is_character())
        {
                write(CYN + name() + "道：这你也拿来估价？\n" NOR);
                return 1;
        }

        if (ob->query_amount())
                value = ob->query("base_value");
        else
                value = ob->query("value");

        if (ob->query("consistence"))
                value = value * ob->query("consistence") / 100;

        if (value < 1)
                write(CYN + name() + "道：" + ob->query("name") +
                      CYN "一文不值！\n" NOR);
        else
        if (ob->query("no_drop") || (ns = ob->query("no_sell")))
        {
                if (stringp(ns))
                {
                        write(CYN + name() + "道：" + ns + "\n" NOR);
                        return 1;
                }
                write(CYN + name() + "道：“这东西有点古怪，我可不好估价。”\n" NOR);
        } else
                write(CYN + name() + "道：“" + ob->query("name") + CYN "值" +
                        MONEY_D->price_str(value * 50 / 100) + "。”\n" NOR);
        return 1;
}

int do_pawn(string arg)
{
        object ob;
        string *pawns;
        int value;
        int amount;

        if (!living(this_object())) return 0;
        if (this_player()->query("family/family_name") == "丐帮") 
                return notify_fail("你是个穷叫化，当什麽东西！\n");
        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要典当什麽物品？\n");
        if (sscanf(base_name(ob),"/u/%*s"))
                return notify_fail(this_object()->name()+"一楞：这东西可不是凡间之物，小店怎消受得？！\n");
        if (ob->query("shaolin")) 
                return notify_fail(this_object()->name()+"惊呼：小的就一个脑袋，可不敢动少林的亩产！\n");
        if (ob->query("money_id"))
                return notify_fail("你要当「钱」？你脑瓜有毛病？\n");
        value = ob->query("value");
        if (! value)
                return notify_fail("这样东西不值钱。\n");
        if (value<100)
                return notify_fail("你当我这是垃圾店，什么乱七八糟的东西都往这塞？\n");
        if (ob->query("unique") || ob->query("no_drop") || ob->query("no_put") || ob->query("no_sell")) 
                return notify_fail("这么重要的东西你也敢拿来典当？\n");
        if (ob->query("no_pawn") || ob->query("replica_ob")) 
                return notify_fail("这样东西不能典当！\n");
        pawns = this_player()->query("pawns");
        if (sizeof(pawns)>5)
                return notify_fail(this_object()->query("name")+"说道：客官在本店典当的物品太多了，小店怕日后担当不起。\n");
        if (! amount = ob->query_amount()) amount = 1;
        // value *= amount;
        if (value<100)
                value = value * 50 / 100;
        else
                value = value / 100 * 50;
        MONEY_D->pay_player(this_player(), value);
        message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
        + MONEY_D->price_str(value) + "。\n", this_player());
        if (! pawns)
                this_player()->set("pawns",({ base_name(ob) }) );
        else {
                pawns += ({ base_name(ob) });
                this_player()->set("pawns",pawns );
        }
        destruct(ob);
        return 1;
}

int do_sell(string arg)
{
        object me;
        object ob;
        object nob;
        string my_id;
        int amount;
        int value;
        int res;
        int max_count;
        mixed ns;

        if (! arg)
                return notify_fail("你要卖什么？\n");

	if (sscanf(arg, "%s to %s", arg, my_id) == 2 && ! id(my_id))
		return 0;

        if (sscanf(arg, "%d %s", amount, arg) != 2)
                // not indicate the amount of the goods
                amount = 1;

        me = this_player();
        if (! (ob = present(arg, me)))
        {
                write("你身上没有这种东西啊！\n");
                return 1;
        }

        max_count = ob->query_amount();
        if (! max_count)
        {
                // not combined object
                if (amount > 1)
                {
                        write(ob->name() + "这种东西不能拆开来卖。\n");
                        return 1;
                }
                max_count = 1;
        } else
        {
                // is combined object
                if (amount > max_count)
                {
                        write("你身上没有这么多" + ob->name() + "。\n");
                        return 1;
                }
        }

        if (ob->query("money_id"))
        {
                write(CYN + name() + "道：“哈哈哈哈！你想卖「钱」？？”\n" NOR);
                return 1;
        }

        if (ob->is_character())
        {
                write(CYN + name() + "道：“哼！我这里做正经生"
                      "意，不贩卖这些！”\n" NOR);
                return 1;
        }

        if (ob->query("unique") || ob->query("no_pawn") || ob->query("replica_ob"))
        {
                write(CYN + name() + "摇摇头，道：“这种东西我"
                      "不识货，不敢要。”\n" NOR);
                return 1;
        }

        if (ob->query("no_drop") ||
            (ns = ob->query("no_sell")))
        {
                if (stringp(ns))
                {
                        command("say " + ns);
                        return 1;
                }
                write(CYN + name() + "摇摇头，道：“这种东西我"
                      "不识货，不敢要。”\n" NOR);
                return 1;
        }

        if (is_vendor_good(arg) != "") 
        {
                write(CYN + name() + "笑道：“我卖给你好不好？”\n" NOR);
                return 1;
        }

        if (ob->query("food_supply"))
        {
                write(CYN + name() + "不屑道：“嘿嘿，剩菜剩饭留给"
                      "您自己用吧。”\n" NOR);
                return 1;
        }
        
        if (ob->query("shaolin"))
        {
                write(CYN + name() + "惊道：“小的胆子很小，可"
                      "不敢买少林庙产。”\n" NOR); 
                return 1;
        }

        if (ob->query("mingjiao"))
        {
                write(CYN + name() + "忙摇头道：“小的只有一个脑袋，可"
                      "不敢买魔教的东西。”\n" NOR);
                return 1;
        }

        if (max_count > 1)
                value = ob->query("base_value") * amount;
        else
                value = ob->query("value");

        if (ob->query("consistence"))
                value = value * ob->query("consistence") / 100;

        if (value < 2)
                write(CYN + name() + "随手一扔，道：" + ob->query("name") +
                      CYN "一文不值！\n" NOR);
        else
	{
                if (max_count == amount)
                        res = ob->move(this_object());
                else
                {
                        nob = new(base_name(ob));
                        nob->set_amount(amount);
                        if (res = nob->move(this_object()))
                                ob->add_amount(-amount);
                        else
                                destruct(nob);
                }

                if (res)
                {
                        message_vision("$N卖掉了一" + ob->query("unit") +
                                       ob->query("name") + "给$n。\n",
				       this_player(), this_object());
                        MONEY_D->pay_player(this_player(), value * 50 / 100);
			ob->sold();
                } else
                        write(CYN + name() + "摇摇头，道：“对不起，"
                              "我现在不收货了。”\n" NOR);
        }
        return 1;
}

object find_player(string target)
{
        foreach (object player in users())
        {
                if (player->query("id") == target)   
                        return player;
        }
}

int do_check(string arg)
{
        string str, *ob;
        object me, obj;
        int i;

        if (! living(this_object())) return 0;
        me = this_player();
        if (arg)
        {
                if (wizardp(me)) 
                {
                        obj = find_player(arg);
                        if (! obj) obj = find_living(arg);
                        if (! obj) obj = present(arg, environment(me));
                } else
                        return 0;
        }
        if (! objectp(obj))  obj = me;
        if (! (ob = obj->query("pawns")))
        {
                write(this_object()->query("name")+sprintf("说道：%s并未在本店典当过任何物品。\n",obj==me?"你":obj->short(1)));
                return 1;
        }

        str = "\n"+((obj==me)?"你":obj->query("name"))+"在本店典当的物品如下:\n\n";
        for (i=0;i<sizeof(ob);i++)
        {
                if (file_size(ob[i]+".c") > 1)
                        str += sprintf("%-40s :%s \n",
                        ob[i]->short(),
                        MONEY_D->price_str(ob[i]->query("value")));
                else
                {
                        log_file("pawns_error",sprintf("%s 典当的%s已经不存在。\n",obj->short(1),ob[i]));
                        ob -= ({ob[i]});
                }
        }

        if (!ob || !sizeof(ob))
                obj->delete("pawns");
        else
                obj->set("pawns",ob);

        write(str);
        return 1;
}

int do_redeemp (string target) 
// 丽春院赎玩家（男、女） 
{ 
        object me,ob,dest; 
     
        me=this_player(); 
        ob=this_object(); 
        if(!target || target=="") 
                return notify_fail(ob->query("name")+"俯到你的耳边悄声问道：你要赎什么人？\n");
 
        if(!objectp(dest=find_player(target))) 
        //find_player() - 用名字寻找一个玩家 
                return notify_fail(HIR+"玩家("+target+")目前似乎不在线上！\n"+NOR);
 
        if( !dest->query("selled")) 
        // 是否要用condition来处理？时间长了没有人赎，就自动当妓女或者男妓？ 
                return notify_fail(ob->query("name")+"急道：你可别诬陷好人，我怎么会非法扣押玩家呢！\n");
 
        switch (MONEY_D->player_pay(me, dest->query("per") * 700)) 
        // switch (me->pay_money(dest->query("per") * 700, 0)) 
        { 
                case 0: 
                        return notify_fail("没钱还想赎人？信不信我把你给卖了！\n"); 
                case 2: 
                        return notify_fail("您的零钱不够了，银票又没人找得开。\n"); 
                default: 
                        message_vision(HIG+"$N从$n那里赎回了"+dest->query("name")+"。\n"+NOR, me, ob); 
                        dest->move(environment(ob)); 
                        dest->set("startroom",base_name(environment(ob))); 
                        dest->delete("selled"); 
                        message("vision", HIY+"只听见嗖的一声，一个遍体鳞伤的家伙从天花板上掉了下来！\n"+NOR, 
                                environment(dest), dest); 
                        tell_object(dest, "你被"+HIC+me->query("name")+NOR+"赎了出来。\n"); 
        } 
        return 1; 
} 

int do_redeem(string arg) 
{ 
        string *pawns,*new_pawns,ob; 
        object obj; 
        mapping all_id; 
        int i,j; 
        object me = this_player();
 
        if (!living(this_object())) return 0; 
        if (!(pawns = this_player()->query("pawns"))) 
                return notify_fail(this_object()->query("name")+"说道：客官并未在本店典当过任何物品。\n"); 
        for (i=0;i<sizeof(pawns);i++)
        { 
                ob=pawns[i];
                if (file_size(ob+".c")<1)      continue; 
                all_id=ob->parse_command_id_list(); 
                for (j=0;j<sizeof(all_id);j++)
                { 
                        if (all_id[j]==arg) 
                                break; 
                }
                if (j!=sizeof(all_id)) 
                        break; 
        } 
        if (j==sizeof(all_id)) 
                return notify_fail(this_object()->query("name")+"急了：你...你何时在小店典当过这东西？\n"); 
        /* 
                if (this_player()->can_afford(ob->query("value"),1)) 
                        this_player()->pay_money(ob->query("value"),0); 
                else 
                        return notify_fail("你的钱不够。\n"); 
        */ 
        switch (MONEY_D->player_pay(me, ob->query("value"))) 
        { 
                case 0: 
                        write(CYN + name() + "冷笑道：“穷光蛋，一边呆着去！”\n" NOR); 
                        return 1; 
                case 2: 
                        write(CYN + name() + "皱眉道：“您还有没有零" 
                              "钱啊？银票我可找不开。”\n" NOR); 
                        return 1; 
                default: 
                        new_pawns=({}); 
                        j=1; 
                        for(i=0;i<sizeof(pawns);i++)
                        { 
                                if (j==1 && ob==pawns[i]) 
                                { 
                                        j--; 
                                        continue; 
                                }
                                else new_pawns+=({pawns[i]}); 
                        } 
                        if (sizeof(new_pawns)) 
                                this_player()->set("pawns",new_pawns ); 
                        else 
                                this_player()->delete("pawns"); 
                        message_vision("$N从当铺里赎回一" + ob->query("unit") 
                                + ob->query("name") + "。\n", 
                                        this_player() ); 
                        obj=new(ob); 
                        if (!obj->move(this_player()))  obj->move(environment(this_player())); 
        }  
                return 1; 
} 


int do_list(string arg)
{
        mixed  goods;
        string *gks;
        object *obs;
        string msg;
        int i;

        mapping count;
        mapping price;
        mapping unit;
        string  short_name;
        string  prefix;
        string  *dk;

	if (arg && ! id(arg))
		return 0; // Don't notify_fail

        count   = ([]);
        unit    = ([]);
        price   = ([]);
        if (obs = all_inventory())
                for (i = 0; i < sizeof(obs); i++)
                {
                        if (obs[i]->query("equipped") ||
			    obs[i]->query("money_id") ||
			    obs[i]->is_character())
                                continue;
                        short_name = obs[i]->name(1) + "(" +
				     obs[i]->query("id") + ")";
                        if (obs[i]->query("base_unit"))
                                prefix = "base_";
                        else
                                prefix = "";
                        if (! undefinedp(unit[short_name]))
                        {
                                count[short_name] += (prefix == "" ? 1 : obs[i]->query_amount());
                                continue;
                        }
                        count += ([ short_name : (prefix == "" ? 1 : obs[i]->query_amount()) ]);
                        unit  += ([ short_name : obs[i]->query(prefix + "unit") ]);
                        price += ([ short_name : obs[i]->query(prefix + "value") ]);
                }
    
        goods = query("vendor_goods");
        if (arrayp(goods) || mapp(goods))
        {
                gks = mapp(goods) ? keys(goods) : goods;
                for (i = 0; i < sizeof(gks); i++)
                {
                        object gob;
                        call_other(gks[i], "???");
                        if (! objectp(find_object(gks[i])))
                        {
                                log_file("log", sprintf("No found vendor good:%s\n", gks[i]));
                                continue;
                        }
                        gob = find_object(gks[i]);
                        short_name = gob->name(1) + "(" +
				     gob->query("id") + ")";
                        if (! undefinedp(unit[short_name]))
                        {
                                count[short_name] = -1;
                                continue;
                        }
                        if (gob->query("base_unit"))
                                prefix = "base_";
                        else
                                prefix = "";
                        count += ([ short_name : -1 ]);
                        unit  += ([ short_name : gob->query(prefix + "unit") ]);
                        price += ([ short_name : (mapp(goods) && goods[gks[i]] > 0) ? goods[gks[i]]
                                                             : gob->query(prefix + "value") ]);
                }
        }

        msg = this_object()->name() + "目前出售以下物品：\n";
        dk = sort_array(keys(unit), 1);
        for (i = 0; i < sizeof(dk); i++)
        {
                int p;
                p = price[dk[i]];
                if (count[dk[i]] > 0) p = p * 12 / 10;
                msg += sprintf("%" + sprintf("%d", (30 + color_len(dk[i]))) +
                               "-s：每%s%s" CYN "(现货%s)\n" NOR, dk[i], unit[dk[i]], MONEY_D->price_str(p),
                               count[dk[i]] > 0 ? chinese_number(count[dk[i]]) + unit[dk[i]]
                                                : "大量供应");
        }

        write(msg);
        return 1;
}       

int do_buy(string arg)
{
        mapping goods;
        int     amount;
        int     value, val_factor;
        string  ob_file;
        string  banghui;
	object *obs;
        object  ob;
	string  my_id;
        string  start_room;
        object  room;
        object  me;
        mapping room_obmap;
	int i;
        int much;
        
        if (! arg)
                return notify_fail("你想买什么？\n");

	if (sscanf(arg, "%s from %s", arg, my_id) == 2 && ! id(my_id))
		return 0;

        me = this_player();
        if (! query("carried_goods"))
        {
                if (stringp(start_room = query("startroom")) &&
                    (room = find_object(start_room)) != environment())
                {
                        // I am not in start room.
                        message_vision("$N大叫一声：“不好，我怎么跑到这儿来了？”\n"
                                       "说罢头也不回的急急忙忙的溜走了。\n", this_object());
                        if (! objectp(room) ||
                            ! mapp(room_obmap = room->query_temp("objects")) ||
                            member_array(this_object(), values(room_obmap)) == -1)
                        {
                                destruct(this_object());
                        } else
                                this_object()->move(room);
                        return 1;
                }
        }

        if (sizeof(filter_array(all_inventory(me), (: ! $1->query("equipped") :))) >= MAX_ITEM_CARRIED)
        {
                write("你身上的东西太多了，先处理一下再买东西吧。\n");
                return 1;
        }

        if (sscanf(arg, "%d %s", amount, arg) != 2)
                // not indicate the amount of the goods
                amount = 1;

        if (amount < 1) 
        {
                write(CYN + name() + "疑惑的问道：“没见过这种买法，你到底想买几件呢？”\n" NOR);
                return 1; 
        }
        if (amount > 100)
        {
                write(CYN + name() + "忙道：“慢慢来，一次最多买一百件。”\n" NOR);
                return 1;
        }

        // no present or equipped
	ob = present(arg, this_object());
	if (! ob && arg[0] > 160)
	{
		for (i = 0; i < sizeof(obs = all_inventory()); i++)
			if (filter_color(obs[i]->name(1)) == arg)
			{
				ob = obs[i];
				break;
			}
	}

        if (! ob || ob->query("equipped"))
        {
                if ((ob_file = is_vendor_good(arg)) == "")
                {
                        write(ob ? "人家正用着啊，怎么会卖给你？\n"
                                 : "你想买什么？\n");
                        return 1;
                }
                ob = new(ob_file);
                if (amount > 1) ob->set_amount(amount);
                val_factor = 10;
                call_out("destruct_it", 0, ob);
        } else
        {
                if (ob->query_amount())
                {
                        object old_ob;
                        if (amount > ob->query_amount())
                        {
                                write("人家那里可没有这么多的" +
                                      ob->name() + "！\n");
                                return 1;
                        }
                        ob = new(base_name(old_ob = ob));
                        ob->set_amount(amount);
                        ob->set_temp("moved_from", old_ob);
                        call_out("destruct_it", 0, ob);
                }
                val_factor = 12;
        }

	if (ob->query("money_id"))
        {
		write(CYN + name() + "大笑道：“哈哈！你要买"
                      "钱？有意思！”\n" NOR);
                return 1;
        }

        if (query_temp("busy"))
        {
                write(CYN + name() + "不耐烦道：“没看见我这"
                      "儿正忙着么？”\n" NOR);
                return 1;
        }

        value = ob->query("value");

        if (value > 1000000000 || value * val_factor / val_factor != value)
        {
                write(CYN + name() + CYN "大惊失色道：这么大一笔生意？我"
                      "可不好做。\n" NOR);
                return 1;
        }
                
        value = value * val_factor / 10;

        if (mapp(goods = query("vendor_goods")) &&
            (int)goods[base_name(ob)] > 0)
        {
                value = goods[base_name(ob)];
                if (value * amount / amount != value)
                {
                        write(CYN + name() + CYN "大惊失色道：“这么大一笔"
                              "生意？我可不好做。”\n" NOR);
                        return 1;
                }
                value *= amount;
        }

        if (amount > 1 && ! ob->query_amount())
        {
                write(ob->name() + "只能一" + ob->query("unit") +
                      "一" + ob->query("unit") + "的买。\n");
                return 1;
        }

        if (stringp(banghui = me->query("bunch/bunch_name"))
        &&  banghui == (string)this_object()->query("bunch/bunch_name"))
                value = value * 2 / 3;
                
        if (me->query_skill("higgling", 1) > 99)
        {       
                if (value <= 0)
                        value = 1;
                        
                if (me->query_skill("higgling", 1) > 399)
                        value /= 2;
                else
                if (me->query_skill("higgling", 1) > 199)
                        value = value * 2 / 3;
                else
                if (me->query_skill("higgling", 1) > 99)
                        value = value * 5 / 6;
        }
                      
        if (value <= 0) value = 1;

        switch (MONEY_D->player_pay(me, value))
        {
        case 0:
                write(CYN + name() + "冷笑道：“穷光蛋，一边呆着去！”\n" NOR);
                return 1;
        case 2:
                write(CYN + name() + "皱眉道：“您还有没有零"
                      "钱啊？银票我可找不开。”\n" NOR);
                return 1;
        case 3:
                write(CYN + name() + "皱眉道：“您还有没有零"
                      "钱啊？钻石我可找不开。”\n" NOR);
                return 1;
        default:
                set_temp("busy", 1);
                
                if (ob->query_amount())
                        message_vision("$N从$n那里买下了" + ob->short() + "。\n",
			               me, this_object());
                else

                        message_vision("$N从$n那里买下了一" + ob->query("unit") + 
                	               ob->query("name") + "。\n",
			               me, this_object());

                if (me->query_skill("higgling", 1) > 99)		
                        switch (random(3))
                        {
                        case 0:
                                command("say 既然大家都是做买卖的，就给你打点折吧。");
                                break;
                        case 1:
                                command("say 也罢，既然是大老板光顾，就便宜点卖给你吧。");
                                break;
                        default:
                                command("say 呵呵。大老板又来采购么？那么就给你打点折吧。");
                                break;
                        }	               

                much = value / 3;
                if (much <= 0) much = 1;
                if (stringp(banghui == (string)this_object()->query("bunch/bunch_name")) &&
                    banghui != me->query("bunch/bunch_name"))
                        BUNCH_D->add_info_into_bunch(banghui, "npc_money", much);

                ob->move(me, 1);

                if (objectp(ob->query_temp("moved_from")))
                {
                        ob->query_temp("moved_from")->add_amount(-amount);
                        ob->delete_temp("moved_from");
                }
                
        }
        remove_call_out("enough_rest");
        call_out("enough_rest", 1 + random(3));

        return 1;
}

void destruct_it(object ob)
{
        if (! ob || environment(ob))
                return;
        destruct(ob);
}

void enough_rest()
{
        delete_temp("busy");
}

void reset()
{
	int i;
	object *obs;

	obs = all_inventory();
        for (i = 0; i < sizeof(obs); i++)
                if (i >= 100 || obs[i]->query_weight() >= 1000000)
                        destruct(obs[i]);
}
