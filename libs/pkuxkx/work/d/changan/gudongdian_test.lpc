
// By Zine古董店
#define MAX_ITEMS 10//最大储量
#define EXCHANGE_RATE 5//手续费 5%
inherit ROOM;
inherit F_SAVE;
#include <ansi.h>
#define GUDONGDIAN "/data/business/gudongdian"+this_object()->query("shop_no")
string query_save_file()
{
        return GUDONGDIAN;
}

void create()
{
        set("short", "古董店");
        set("long", 
"这里是一家古董店，古董商帮人鉴定古董发财以后，在这里开了一家店，挂\n起了一面招牌(paizi)。\n"

        );
        set("item_desc", ([
		"paizi" : "这是一面招牌，上面写着：代客存放(cun)古玩字画。需要时可随时取(qu)回，手续费古玩估值百分之"+chinese_number(EXCHANGE_RATE)+"。\n", 
	]));
        set("shop_no",1);
        set("exits", ([
                "out" : __DIR__"dongshi",
                
        ]));
        set("no_task",1);
        set("objects", ([
		__DIR__"npc/gudongshang" : 1,
        ]));
        setup();
        restore();
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
}

nosave object shop=this_object();

int change_save_format(object me)
{
    if (me->query("guwan_store"))
    {
        shop->set("guwan_store/"+me->query("id"),me->query("guwan_store"));
        me->delete("guwan_store");
        shop->save();
    }
    return 1;
}

void init()
{
    object me=this_player();
    add_action("do_cun","cun");
    add_action("do_qu","qu");
    add_action("do_list","list");
    add_action("do_blacklist","blacklist");
    change_save_format(me);
}

int do_blacklist(string arg)
{
    object me=this_player();
    if (!wizardp(me))
    {
        return 0;
    }
    if (!arg)
    {
        tell_object(me,"你要把谁加入古董交易黑名单？\n");
        return 1;
    }
    tell_object(me,"你将加入"+arg+"此店的黑名单。\n");
    shop->add("blacklist/"+arg,1);
    if (shop->query("blacklist/"+arg)>=2)
    {
        tell_object(me,arg+"已被彻底禁止在此店交易！\n");
    }
    shop->save();
    return 1;
}

int do_list()
{
    object me=this_player();
    int index,rate;
    string msg,id=me->query("id");
    if (!sizeof(shop->query("guwan_store/"+id)))
    {
        msg="你在本店没有寄存任何古董。\n";
    }
    else
    {
        msg="你在本店寄存的古董包括：\n";
        for (index=0;index<MAX_ITEMS;index++)
        {
            if (!shop->query("guwan_store/"+id+"/"+index))
            continue;
            rate=(int)shop->query("guwan_store/"+id+"/"+index+"/value")*EXCHANGE_RATE/100*(1+shop->query("blacklist/"+id));//黑名单交易费用上升
            msg+= sprintf("│"+HIW+"编号"+NOR+"：[%1d]│"+HIY+"物品"+NOR+"：%-20s│"+HIR+"赎回价格"+NOR+"：%-32s│\n", index, shop->query("guwan_store/"+id+"/"+index+"/name"), MONEY_D->money_str(rate) );
        }
    }
    tell_object(me,msg);
    return 1;
}

int do_cun(string arg)
{
    object ob,me=this_player();
    int index,posi,flag=0;
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (shop->query("blacklist/"+me->query("id"))>=2)
    {
        tell_object(me,"你之前有严重欺诈行为，被彻底禁止在本店交易！\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要存放什么古董？\n");
        return 1;
    }
    if (!present(arg,me))
    {
        tell_object(me,"现在你身上并无这样东西。\n");
        return 1;
    }
    ob=present(arg,me);
    if (!ob->query("is_guwanzihua"))
    {
        tell_object(me,"我这里只能代存古玩字画，其他东西去当铺吧。\n");
        return 1;
    }
    for (index=0;index<MAX_ITEMS;index++)
    {
        if (!shop->query("guwan_store/"+me->query("id")+"/"+index))
        {
            posi=index;
            break;
        }
        else
        {
            flag+=1;
        }
    }
    if (flag>=10)//一人只许存10件古玩字画
    {
        tell_object(me,"您在这里已经寄存了至少十件古玩字画了，再存小店就不敢收了。\n");
        return 1;
    }
    if (ob->query("identified"))
    {
        shop->set("guwan_store/"+me->query("id")+"/"+posi+"/itemlist",ob->query("itemlist"));
        shop->set("guwan_store/"+me->query("id")+"/"+posi+"/identified",1);
    }
    else
    {
        shop->set("guwan_store/"+me->query("id")+"/"+posi+"/unidentified",1);
    }
    shop->set("guwan_store/"+me->query("id")+"/"+posi+"/value",ob->query("value"));
    shop->set("guwan_store/"+me->query("id")+"/"+posi+"/name",ob->query("name"));
    if (ob->query("guwan"))
    {
        shop->set("guwan_store/"+me->query("id")+"/"+posi+"/type","guwan");
    }
    else
    {
        shop->set("guwan_store/"+me->query("id")+"/"+posi+"/type","zihua");
    }
    shop->save();
    message_vision("$N把$n寄存在古董店。\n",me,ob);
    destruct(ob);
    return 1;
}

int get_back(object me,object ob,int index)
{
    int afford,payment=(int)shop->query("guwan_store/"+me->query("id")+"/"+index+"/value")*EXCHANGE_RATE/100*(1+shop->query("blacklist/"+me->query("id")));//黑名单交易费用上升
    if( !(afford = me->can_afford(payment)) )
    {
        tell_object(me,"你没有足够的钱来赎回"+ob->query("name")+"。\n");
        destruct(ob);
        return 1;
    }
    if( afford == 2 )
    {
        tell_object(me,"你没有足够的钱来赎回"+ob->query("name")+"。\n");
        destruct(ob);
        return 1;
    }
    me->start_busy(1);
    shop->delete("guwan_store/"+me->query("id")+"/"+index);
    shop->save();
    MONEY_D->player_pay(me,payment);
    message_vision("$N付出了"+MONEY_D->money_str(payment)+"后，赎回了寄存的$n。\n",me,ob);
    ob->move(me);
    return 1;
}

int do_qu(string arg)
{
    object ob,me=this_player();
    int index,i;
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if( !arg || sscanf(arg, "%d", index)!=1 )
    return notify_fail("指令格式：qu <物品标号>\n");
    if (!sizeof(shop->query("guwan_store/"+me->query("id"))))
    return notify_fail("你并没有在这里寄存任何古董。\n");
    if (index<0||index>MAX_ITEMS)
    return notify_fail("错误的物品编号，请用list查询自己寄存的古董。\n");
    if (!shop->query("guwan_store/"+me->query("id")+"/"+index))
    return notify_fail("错误的物品编号，请用list查询自己寄存的古董。\n");
    if (shop->query("guwan_store/"+me->query("id")+"/"+index+"/type")=="guwan")
    {
        ob=new("/d/guiyunzhuang/obj/guwan");
    }
    else
    {
        ob=new("/d/guiyunzhuang/obj/zihua");
    }
    if (shop->query("guwan_store/"+me->query("id")+"/"+index+"/unidentified"))
    {
        get_back(me,ob,index);
        return 1;
    }
    else
    {
        ob->set("itemlist",shop->query("guwan_store/"+me->query("id")+"/"+index+"/itemlist"));
        ob->set("identified",1);
        ob->set("guwan_jiandinged",1);
        ob->rename();
        get_back(me,ob,index);
        return 1;
    }
}