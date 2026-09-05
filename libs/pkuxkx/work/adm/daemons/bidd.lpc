///adm/daemons/auctiond.c :
// auctiond.c
// 拍卖系统
// Written by jjgod for hell. 01/10/01.

#include <ansi.h>

inherit F_DBASE;

int clean_up() { return 1; }
int is_container() { return 1; }
int query_max_encumbrance() { return 100000000000; }

#define auction_info    my["auction_info"]
//最高价格10万两黄金
#define MAX_PRICE       10000000
#define MAX_ITEMS		100

public  void   add_auction(object me, object ob, int money);
public  void   cancel_auction(object me);
public  string check_auction_info();
protected void   message_auction(string msg);
protected string check_auction(object ob);
protected string filter_color(string);
public void get_confirm_cancel_auction(string, object, int);
public void get_confirm_join_auction(string, object, string, int);
int get_good(object);
int check_good(object);
int count_lot_money(int);
void tonggao();

protected  int tick=0;
protected string current_id="";

void create()
{
    mapping my;
    seteuid(getuid());
    set("channel_id", "易东西");

    CHANNEL_D->do_channel(this_object(), "sys", "拍卖精灵已经启动。");
    my = query_entire_dbase();
    auction_info = ([ ]);
    set_heart_beat(1);
    remove_call_out("tonggao");
    call_out("tonggao", 2400);
}

void heart_beat()
{

    mapping my;
    string *id;
    int i, money, lot_money;
    object me;
    object ob;
    object obj;


    if(tick++ < 5) return;
    my = query_entire_dbase();

    if (! mapp(auction_info) || ! sizeof(auction_info))
        return;

    id = keys(auction_info);

	for(i = 0; i < sizeof(id);i++)
	{
  	    current_id=id[i];
        me = auction_info[current_id]["seller"];
        obj = auction_info[current_id]["goods"];
        ob = auction_info[current_id]["now"];

        if (!objectp(me))
        {
        	if (objectp(obj))
        	{
                message_auction(sprintf("%s(%s)不知所踪，他的%s归荣昌交易行所有了。",
                                        auction_info[current_id]["seller_name"],
                                        current_id,
                                        filter_color(obj->short()),)
                                );
            }

            if (objectp(ob))
            {
                ob->add("balance", ob->query_temp("auction/"+current_id));
                ob->delete_temp("auction/"+current_id);
            }

            destruct(obj);
	        map_delete(auction_info, current_id);
			continue;
        }

        if (!objectp(obj))
        {
            message_auction(sprintf("%s(%s)的拍卖品不见了，拍卖取消。",
                                    auction_info[current_id]["seller_name"],
                                    current_id,)
                            );

            if (objectp(ob))
            {
                ob->add("balance", ob->query_temp("auction/"+current_id));
                ob->delete_temp("auction/"+current_id);
            }

            map_delete(auction_info, current_id);
            continue;
        }

        if (!auction_info[current_id]["start_bid"]) continue;

        if (!objectp(ob) && auction_info[current_id]["start_bid"])
        {
            map_delete(auction_info[current_id], "now");
            auction_info[current_id]["start_bid"] = 0;
            auction_info[current_id]["value"] = auction_info[current_id]["base_value"];

            message_auction(sprintf("出价最高者失踪了，%s(%s)的%s重新开始拍卖，%s起拍!\n有意者请用paimai命令竞价。",
                                    me->name(1),
                                    current_id,
                                    filter_color(obj->short()),
                                    MONEY_D->money_str(auction_info[current_id]["value"]),)
                            );
            continue;
        }

        if (time() - auction_info[current_id]["time"] >= 3600*2 && !auction_info[current_id]["start_bid"])
        {
            message_auction(sprintf("%s(%s)的%s无人竞价，取消拍卖。",
                        me->name(1), current_id,
                        filter_color(obj->short())));
            map_delete(auction_info, current_id);
            tell_object(me,"请回荣昌交易行取回您的" + obj->short() + NOR + "。\n");
            obj->set("auction/result", "fail");
            continue;
        }

        if (time() - auction_info[current_id]["time"] >= 30 && auction_info[current_id]["start_bid"] )
        {
            auction_info[current_id]["state"] += 1;
            auction_info[current_id]["time"] = time();

            if(auction_info[current_id]["state"] < 5)
            {
                message_auction(sprintf("%s(%s)的%s，%s第%s次。",
                        me->name(1), current_id,
                        filter_color(obj->short()),
                        MONEY_D->money_str(auction_info[current_id]["value"]),
                        chinese_number(auction_info[current_id]["state"])));
            }

            if (auction_info[current_id]["state"] >= 5)
            {
                money = auction_info[current_id]["value"];
                message_auction(sprintf("%s(%s)的%s与%s成交了。",
                            me->name(1), me->query("id"),
                            filter_color(obj->short()),
                            ob->name()));

                // 交易完成
                //不直接交给买主，让买主到房间里去取。
                tell_object(ob,"交易成功！请到荣昌交易行去取你得货物！\n");
                tell_object(me, "荣昌交易行把" + obj->short() + "交人带给"
                        "了" + ob->name() + "。\n");

                ob->delete_temp("auction/"+current_id);
                lot_money = count_lot_money(money); 
                if (me->query("balance") < lot_money)
                {
                    me->add("balance",money-2*lot_money);
                    tell_object(me, "由于你的钱庄户头付不起佣金，所以从你拍卖所得中双倍扣除佣金"+MONEY_D->money_str(2*lot_money)+"。\n");
                }
                else
                {
                    me->add("balance",money-lot_money);
                    tell_object(me, "荣昌交易行从你拍卖所得中扣除了佣金"+MONEY_D->money_str(lot_money)+"。\n");
                }

                map_delete(auction_info, current_id);

                obj->set("auction/owner",ob->query("id"));
                obj->set("auction/result", "sucess");
                obj->move(this_object());
                continue;
            }
        }
	}
    tick=0;
}
// 添加一个拍卖品
public void add_auction(object me, object ob, int money)
{
    mapping my;
    string id, msg;

    my = query_entire_dbase();
    id = me->query("id");

    if (check_good(me)>=3)
    {
        tell_object(me, "你有太多东西在荣昌交易行没取走，不能添加新的拍卖品。\n");
        return;
    }

    if (mapp(auction_info[id]))
    {
        tell_object(me, "你正在拍卖别的东西，不能添加新的拍卖品。\n");
        return;
    }
    if (stringp(msg = check_auction(ob)))
    {
        tell_object(me, msg);
        return;
    }

    if(money > MAX_PRICE)
    {
        tell_object(me,"得罪，本行规模太小，不敢承接如此高额的报价。\n");
        return;
    }

    auction_info[id] = ([ "goods" : ob,
        "seller" : me,
        "seller_name" : me->name(1),
        "time"  : time(),
        "value" : money*100,
        "base_value" : money*100,
        "state" : 0, ]);

	tell_object(me, "你拿出" + ob->short() + NOR "交给荣昌交易行进行拍卖，如果拍卖成功你需要付出一定金额的佣金。\n");
	message_auction(sprintf("%s(%s)拍卖%s，%s起拍!有意者请用paimai命令竞价。", 
                            me->name(1), 
                            id, 
                            filter_color(ob->short()),
                            MONEY_D->money_str(money*100),)
                    );

    ob->set("auction/seller", id);
    ob->move(this_object());
    return;
}

  // 检测拍卖物品
protected string check_auction(object ob)
{
    string msg;
    if (! ob->query("value") && ! ob->query("base_value"))
        return "这玩意儿可不值钱哪。\n";
/*    if (ob->query("no_sell") || ob->query("no_drop"))
    {
        if (stringp(msg = ob->query("no_sell")))
            return msg;
        return "这个东西可不能卖了。\n";
    } */
    if (ob->query("gem_ob_autoloaded"))
    	return "这件东西取消自动加载之后方能拍卖！\n";
    if (ob->is_character())
        return "这你也拿来拍卖？\n";
    if (ob->query("money_id"))
        return "你没用过钱啊？\n";
    if (ob->query("food_supply"))
        return "吃的喝的等卖出去都馊了。\n";
    if(sizeof(all_inventory(ob)) > 0)
        return "把里面的东西取出来再拍卖吧，否则就吃亏了呀。\n";
}


// 取消拍卖物品
public void cancel_auction(object me)
{
    mapping my;
    string id;
    string name;
    object obj, other;
    int charge;

    id = me->query("id");
    my = query_entire_dbase();

    if (! mapp(auction_info[id]))
    {
        tell_object(me, "你没有在拍卖任何东西。\n");
        return;
    }

    if (objectp(other = auction_info[id]["now"]))
    {
    	charge=(auction_info[id]["value"]>100000)?auction_info[id]["value"]:100000;
    }
    else charge=100000;

    if (me->query("balance")<charge)
    {
        tell_object(me, "你的钱庄存款太少，不够支付手续费的。\n");
        return;
    }

    if (objectp(obj = auction_info[id]["goods"]))
    {
        name = filter_color(obj->short());
    }
    else name = "拍卖品";

    write("取消拍卖需要扣除的手续费为"+MONEY_D->money_str(charge)+"，你确认(yes/no)吗？");
    input_to((: get_confirm_cancel_auction :), me, charge);

    return;
}

public void get_confirm_cancel_auction(string re, object me, int charge)
{
    int newcharge;
    object obj, other;
    string id, name;
    mapping my;

    id = me->query("id");
    my = query_entire_dbase();

    if (! mapp(auction_info[id]))
    {
        tell_object(me, "你没有在拍卖任何东西。\n");
        return;
    }

    if (objectp(other = auction_info[id]["now"]))
    {
        newcharge=(auction_info[id]["value"]>100000)?auction_info[id]["value"]:100000;
    }
    else newcharge=100000;

    if (me->query("balance")<charge)
    {
        tell_object(me, "你的钱庄存款太少，不够支付手续费的。\n");
        return;
    }

    if (objectp(obj = auction_info[id]["goods"]))
    {
        name = filter_color(obj->short());
    }
    else name = "拍卖品";

    if (re != "yes")
    {
        tell_object(me, "你放弃了取消拍卖。\n");
        return;
    }
    else if (newcharge==charge && re=="yes")
    {
        if (objectp(other))
        {
            other->add("balance", other->query_temp("auction/"+id));
            other->delete_temp("auction/"+id);
            tell_object(other, "拍卖被"+me->name(1)+NOR "取消了，竞拍钱款返还到了你的钱庄户头。\n");
        }

        me->add("balance",-charge);
        tell_object(me, "你中途取消了拍卖，已从你的钱庄扣除"+MONEY_D->money_str(charge)+"作为手续费。\n");
        message_auction(sprintf("%s(%s)取消了拍卖他的%s。", me->name(1), id, name, ));

        if (objectp(obj)) obj->set("auction/result", "fail");
        map_delete(auction_info, id);
    }
    else
    {
        write("费用发生了变化，取消拍卖需要扣除的手续费为"+MONEY_D->money_str(newcharge)+"，你确认(yes/no)吗？");
        input_to((: get_confirm_cancel_auction :), me, newcharge);
    }
}


  // 查看拍卖物品
public string check_auction_info()
{
    mapping my;
    string msg, name;
    string *id;
    object ob;
    int i, number, tab1, tab2, tab3;
    my = query_entire_dbase();
    if (! mapp(auction_info) || ! sizeof(auction_info))
        msg = "目前没有任何正在拍卖的物品。\n";
    else
    {
        msg = "目前正在拍卖的物品有以下这些：\n";
        msg += HIC "≡" HIY "───玩家────────────物品──────────竞价者──────────价格───" HIC "≡\n" NOR;
        id = keys(auction_info);
        for (i = 0; i < sizeof(id); i++)
        {
            if (!objectp(auction_info[id[i]]["seller"]))
            {
                continue;
            }
            if (!objectp(ob = auction_info[id[i]]["goods"]))
            {
                continue;
            }
            if (!objectp(auction_info[id[i]]["now"]))
                 name = "无";
            else name = auction_info[id[i]]["now"]->name_id();

            tab1 = 22+sizeof(auction_info[id[i]]["seller"]->name(1))-sizeof(filter_color(auction_info[id[i]]["seller"]->name(1)));
            tab2 = 26+sizeof(ob->short())-sizeof(filter_color(ob->short()));
            tab3 = 22+sizeof(name)-sizeof(filter_color(name));
            msg += sprintf("  %-" + tab1+ "s %|" + tab2 +"s %|"+ tab3 + "s %16s\n" NOR,
                       auction_info[id[i]]["seller"]->name(1) + "(" + auction_info[id[i]]["seller"]->query("id") + ")",
                       ob->short(),
                       name,
                       MONEY_D->money_str(auction_info[id[i]]["value"]));
        }
        msg += HIC "≡" HIY "───────────────────────────────────────────────" HIC "≡\n" NOR ;
        msg += sprintf("目前共有%s件拍卖品。\n", chinese_number(sizeof(auction_info)));
    }

    if(number = check_good(this_player()))
    {
        msg += HIC "本行库存中现有" + chinese_number(number) +"件物品等着你来取回。\n" NOR ;
    }

    return msg;
}
  // 参与竞价
public void join_auction(object me, string name, int money)
{
    mapping my;
    object ob, obj;

    if (name==me->query("id"))
    {
        tell_object(me, "你不能竞拍自己的东西。\n");
        return;
    }

    if (check_good(me)>=3)
    {
        tell_object(me, "你有太多东西在荣昌交易行没取走，不能竞拍新的拍卖品。\n");
        return;
    }

    my = query_entire_dbase();

    if (! mapp(auction_info[name]))
    {
        tell_object(me, "这个人没有在拍卖什么东西。\n");
        return;
    }

    if(!objectp(ob = auction_info[name]["seller"]))
    {
        tell_object(me, "卖家已经不在了。\n");
        return;
    }

    if (!objectp(obj = auction_info[name]["goods"]))
    {
        tell_object(me, "这个人现在已经没有这个东西了耶。\n");
        return;
    }

    if (auction_info[name]["now"] == me)
    {
        tell_object(me, "好像上次出价的就是你吧。\n");
        return;
    }

    if(money > MAX_PRICE)
    {
        tell_object(me,"得罪，本行规模太小，不敢承接如此高额的报价。\n");
        return;
    }

    if (auction_info[name]["start_bid"]==0 && money < (auction_info[name]["value"])/100)
    {
        tell_object(me, sprintf("这个价人家恐怕不会要，您至少要出到%d两白银。\n",auction_info[name]["value"]/100));
        return;
    }

   if (auction_info[name]["start_bid"]==1 && to_int(money/0.11) < (auction_info[name]["value"])/10)
    {
        tell_object(me, sprintf("这个价人家恐怕不会要，您至少要出到%d两白银。\n",to_int(auction_info[name]["value"]*0.011) + 1));
        return;
    }

    if (me->query("balance")<money*100)
    {
        tell_object(me, "你的钱庄户头付不起钱，只好作罢。\n");
        return;
    }

    write("你的竞拍报价为"+MONEY_D->money_str(money*100)+"，你确认(yes/no)吗？");
    input_to((: get_confirm_join_auction :), me, name, money);

    return;

}

public void get_confirm_join_auction(string re, object me, string name, int money)
{
    mapping my;
    object ob, obj, other;

    if (re!="yes")
    {
        tell_object(me, "你放弃了出价竞拍。\n");
        return;
    }

    my = query_entire_dbase();

    if (check_good(me)>=3)
    {
        tell_object(me, "你有太多东西在荣昌交易行没取走，不能竞拍新的拍卖品。\n");
        return;
    }

    if (! mapp(auction_info[name]))
    {
        tell_object(me, "这个人没有在拍卖什么东西。\n");
        return;
    }

    if(!objectp(ob = auction_info[name]["seller"]))
    {
        tell_object(me, "卖家已经不在了。\n");
        return;
    }

    if (!objectp(obj = auction_info[name]["goods"]))
    {
        tell_object(me, "这个人现在已经没有这个东西了耶。\n");
        return;
    }

    if (auction_info[name]["start_bid"]==0 && money < (auction_info[name]["value"])/100)
    {
        tell_object(me, sprintf("这个价人家恐怕不会要，您至少要出到%d两白银。\n",auction_info[name]["value"]/100));
        return;
    }

    //至少要递增10%， 原有的算法导致溢出，所以改成对money*90而不是100
    if (auction_info[name]["start_bid"]==1 && to_int(money/0.11) < (auction_info[name]["value"])/10)
    {
        tell_object(me, sprintf("这个价人家恐怕不会要，您至少要出到%d两白银。\n",to_int(auction_info[name]["value"]*0.011) + 1));
        return;
    }

    if (objectp(other = auction_info[name]["now"]))
    {
        other->add("balance", other->query_temp("auction/"+name));
        other->delete_temp("auction/"+name);
        tell_object(other, "你的出价被人超过了，竞拍钱款返还到了你的钱庄户头。\n");
    }

    me->add("balance", -money*100);
    me->set_temp("auction/"+name, money*100);
    tell_object(me, "荣昌交易行从你的钱庄户头支走了竞拍钱款。\n");

    message_auction(sprintf("%s(%s)购买%s(%s)的%s，%s第一次。",
        me->name(), me->query("id"), ob->name(),
        name, filter_color(obj->short()),
        MONEY_D->money_str(money*100)));
    auction_info[name]["now"] = me;
    auction_info[name]["value"] = money*100;
    auction_info[name]["time"] = time();
    auction_info[name]["state"] = 1;
    auction_info[name]["start_bid"] = 1;
}



  // 发送拍卖信息
protected void message_auction(string msg)
{
    CHANNEL_D->do_channel(this_object(), "jy", msg);
}

string filter_color(string str)
{
    if(stringp(str))
    {
        str=replace_string(str,HIY,"");
        str=replace_string(str,HIB,"");
        str=replace_string(str,HIR,"");
        str=replace_string(str,HIW,"");
        str=replace_string(str,BLU,"");
        str=replace_string(str,RED,"");
        str=replace_string(str,YEL,"");
        str=replace_string(str,WHT,"");
        str=replace_string(str,BLK,"");
        str=replace_string(str,MAG,"");
        str=replace_string(str,HIC,"");
        str=replace_string(str,CYN,"");
        str=replace_string(str,GRN,"");
        str=replace_string(str,HIG,"");
        str=replace_string(str,HIM,"");
        str=replace_string(str,NOR,"");
    }
    return str;
}

int get_good(object ob)
{
    int give_ob=0;
    object* inv=all_inventory();
    if(arrayp(inv) && sizeof(inv) > 0)
    {
        for(int i=0;i<sizeof(inv);i++)
        {
            if(objectp(inv[i]) && inv[i]->query("auction/result")=="sucess" && inv[i]->query("auction/owner")==ob->query("id"))
            {
                tell_object(ob,"掌柜的将你竞得的"+inv[i]->short()+"交到了你的手里。\n");
                give_ob++;
                if(!inv[i]->move(ob)) inv[i]->move(environment(ob));
                inv[i]->delete("auction");
            }
            if(objectp(inv[i]) && inv[i]->query("auction/result")=="fail" && inv[i]->query("auction/seller")==ob->query("id"))
            {
                tell_object(ob,"掌柜的将你没有拍卖成功的"+inv[i]->short()+"交到了你的手里。\n");
                give_ob++;
                if(!inv[i]->move(ob)) inv[i]->move(environment(ob));
                inv[i]->delete("auction");
            }
        }
        if(!give_ob) tell_object(ob,"这里没有你的东西！\n");
        return 1;
    }
    tell_object(ob,"这里没有你的东西！\n");
    return 1;
}

int check_good(object me)
{
    int have_ob=0;
    object* inv=all_inventory();
    for(int i=0;i<sizeof(inv);i++)
    {
        if(objectp(inv[i]) && inv[i]->query("auction/result")=="sucess" && inv[i]->query("auction/owner")==me->query("id"))
        {
            have_ob++;
        }
        if(objectp(inv[i]) && inv[i]->query("auction/result")=="fail" && inv[i]->query("auction/seller")==me->query("id"))
        {
            have_ob++;
        }
    }
    return have_ob;
}

int count_lot_money(int money)
{
    int rest_money = 0, total_lot_money = 0;

/*    <100 5% 20 / 1
    <500 3% 20 / 2
    <1000 2% 30 / 2
    <5000 1.5% 30 / 3
    <10000 1% 40 / 3
    <20000 0.8% 40 / 4
    <30000 0.2% 50 / 4
    <50000 0.1% 50 / 5
    0.05% 100 / 10
*/
    rest_money = money;
    if (rest_money>500000000)
    {
        total_lot_money += (rest_money-500000000)/1000;
        rest_money = 500000000;
    }
    if (rest_money>300000000)
    {
        total_lot_money += (rest_money-300000000)/250;
        rest_money = 300000000;
    }
    if (rest_money>200000000)
    {
        total_lot_money += (rest_money-200000000)/200;
        rest_money = 200000000;
    }
    if (rest_money>100000000)
    {
        total_lot_money += (rest_money-100000000)/160;
        rest_money = 100000000;
    }
    if (rest_money>50000000)
    {
        total_lot_money += (rest_money-50000000)/120;
        rest_money = 50000000;
    }
    if (rest_money>10000000)
    {
        total_lot_money += (rest_money-10000000)/90;
        rest_money = 10000000;
    }
    if (rest_money>5000000)
    {
        total_lot_money += (rest_money-5000000)/60;
        rest_money = 5000000;
    }
    if (rest_money>1000000)
    {
        total_lot_money += (rest_money-1000000)/40;
        rest_money = 1000000;
    }
    total_lot_money += rest_money/20;

    return total_lot_money;
}

void tonggao()
{
    string msg;
    mapping my;

    my = query_entire_dbase();
    if (sizeof(auction_info))
    {
        msg = sprintf("目前共有%s件拍卖品正在进行拍卖，有意者请用paimai命令竞价。", chinese_number(sizeof(auction_info)));
        message_auction(msg);
    }

    remove_call_out("tonggao");
    call_out("tonggao", 2400);
}


