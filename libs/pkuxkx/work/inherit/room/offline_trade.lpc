//Zine 2011.09.20
//离线交易，可支持非autoload的随机武器，宝石，以及各种非no_sell,no_store,no_pawn类物品。
//可按卖家id或商品类型查询商品
//修正一些bug，增加非鹿鼎山解谜玩家无法交易宝石，随机准备。ZINE 2013/08/07
//食物类不允许离线交易了
#include <ansi.h>
#include <math.h>
#include "/d/xinfang/store_limit.h"
inherit F_SAVE;
inherit ROOM;
void create();
#define OFFLINE_TRADE "/data/business/offline_trade"+this_object()->query("no")
string query_save_file()
{
	return OFFLINE_TRADE;
}
int restore_itself()
{
	restore();
	this_object()->init_store();
}
#define MAX_CONSIGN 6 //允许最大寄售数量
#define MAX_PRICE 1000000 //寄售最大价格，10000 gold
#define MIN_PRICE 5 //寄售最小价格，5 silver
#define MAX_ITEMS 250 //同时寄售最大商品数
#define ADV_COST 1000000 //广告费用
#define TAX 3//交易税 3%
#define PENALTY 0 //撤销交易罚金 10%
#define OFF_PENALTY 0 //下架取回手续费 15%
#define CHANGE_PRICE_PENALTY 4 //指定价格手续费 4%
#define LINE   HIY"━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR//间隔
int buy_guwan(object ob,object me,int index,int flag);//在售古玩
int buy_gem(object ob,object me,int index,int flag);//下架古玩
int store_item(object ob,object me,int sale,int flag,string user);
void init()
{
        add_action("do_query", "query");
        add_action("do_retrieve", "quhui");
        add_action("do_sell", "sell");
        add_action("do_retrieve", "shu");
        add_action("do_buy", "buy");
        add_action("do_list", "list");
        add_action("do_getmoney","getmoney");
        add_action("do_getmoney","tikuan");
        add_action("do_post","post");
        add_action("do_xsell","xsell");
        add_action("do_renounce","renounce");
        add_action("do_changeprice","changeprice");
}



int do_changeprice(string arg)
{
    object me=this_player();
    int afford,index,newprice,fine;
    if( !arg || sscanf(arg, "%d to %d", index,newprice)!=2 )
        return notify_fail("指令格式：changeprice <物品编号> to <新价格>\n");
	restore_itself();
    if (query("goods/"+index))
        return notify_fail("你指定了一个不存在的物品编号。\n");
    if (query("goods/"+index+"/ownerid")!=me->query("id"))
        return notify_fail("这样物品的主人并不是你，不能指定它的价格。\n");
    if (newprice<MIN_PRICE||newprice>MAX_PRICE)
        return notify_fail("新指定价格大于最高价或低于最低价，请重新指定！\n");
    if (newprice==query("goods/"+index+"/price"))
        return notify_fail("新指定价与原价相同，请重新指定。\n");
    if (query("goods/"+index+"/price_changed"))
        return notify_fail("所有寄售物品在上架期间最多指定一次价格。\n");
    fine=query("goods/"+index+"/price")*CHANGE_PRICE_PENALTY;
    if( !(afford = me->can_afford(fine)) )  
        return notify_fail("你没有足够的钱支付指定价格的手续费。\n");
    if( afford == 2 )
        return notify_fail("你没有足够的零钱，而银票在这里是无法流通的。\n");
    me->start_busy(1);
    MONEY_D->player_pay(me,fine);
	set("goods/"+index+"/price",newprice);
	set("goods/"+index+"/price_changed",1);
    message_vision("$N支付了"+MONEY_D->money_str(fine)+"后，重新核定了"+query("goods/"+index+"/objectname")+"的价格为"+MONEY_D->money_str(newprice*100)+"。\n",me);
	save();
    return 1;
}
int do_renounce(string arg)
{
	object me=this_player();
	int index,*sub_index=({});
	restore_itself();
	if (!sizeof(query("seller/"+me->query("id")+"/old_goods/number_pool")))
	return notify_fail("你只能放弃你寄售过且下架的物品。\n");
	if( !arg || sscanf(arg, "%d", index)!=1 )
	return notify_fail("指令格式：renounce <物品标号>\n");
	if (query("seller/"+me->query("id")+"/old_goods/"+index+"/ownerid")!=me->query("id"))
	return notify_fail("指令格式：这个编号的物品并不属于你名下。\n");
	if (arrayp(query("seller/"+me->query("id")+"/old_goods/number_pool")))
	sub_index=query("seller/"+me->query("id")+"/old_goods/number_pool");
	if (query("seller/"+me->query("id")+"/old_goods/number_pool/"+index))
	sub_index-=({index});
	set("seller/"+me->query("id")+"/old_goods/number_pool",sub_index);
	if (!sizeof(sub_index))
	delete("seller/"+me->query("id")+"/old_goods/number_pool");
	tell_object(me,"你放弃了第"+index+"号物品："+query("seller/"+me->query("id")+"/old_goods/"+index+"/objectname")+"的权利，物品充公！\n");
	delete("seller/"+me->query("id")+"/old_goods/"+index);
	save();
	return 1;
}

int do_post(string arg)
{
	object me=this_player();
	int afford,i,flag=0;
	for (i=1;i<=5;i++)
	if (!query("adv/"+i))
	{
		flag=i;
		break;
	}
	if (!flag)
	return notify_fail("现在这里五个广告位置全满，无法再接纳新的广告了。\n");
	else
	{
		if( !(afford = me->can_afford(ADV_COST)) )  
		return notify_fail("这里的广告位置"+MONEY_D->money_str(ADV_COST)+"租用一天，你身上的钱不够。\n");
		if( afford == 2 )
		return notify_fail("你没有足够的零钱，而银票在这里是无法流通的。\n");
		if (!arg)
		return notify_fail("你的广告内容是什么？\n");
		if (strwidth(arg)>60)
        return notify_fail("你的广告太长了，精简点吧。\n");
		else
		{
			restore_itself();
			me->start_busy(1);
			MONEY_D->player_pay(me,ADV_COST);
			set("adv/"+flag+"/content",arg+"\t"+me->query("name")+"发布");
			set("adv/"+flag+"/author",me->query("id"));
			set("adv/"+flag+"/time",time());
            tell_object(me,"录入广告成功，将在一天内滚动播出。\n");
            tell_object(me,"你的广告内容为『"+arg+"』\n");
            tell_object(me,HIR+BLINK+"如出现政治、色情内容，发布广告人将受到处罚。\n"+NOR);
			save();
            return 1;
		}
	}
}

int remove_adv()
{
	for (int index=1;index<6;index++)
	if (time()-query("adv/"+index+"/time")>3600*24)
	delete("adv/"+index);
}

int advtisement()
{
	string system_adv,adv;
	int flag=0,num,*pool=({}),*system_pool=({});
	restore_itself();
	if (sizeof(query("goods")))
	{
		for (num=0;num<MAX_ITEMS;num++)
		{
			if (query("goods/"+num+"/target_user"))
			continue;
			if (query("goods/"+num))
			system_pool+=({num});
		}
		if (sizeof(system_pool))
		{
			num=system_pool[random(sizeof(system_pool))];
			system_adv=query("goods/"+num+"/ownername")+HIY+"("+query("goods/"+num+"/ownerid")+")在"+query("short")+"出售"+query("goods/"+num+"/objectname")+HIY+"("+query("goods/"+num+"/id")+")，只要"+MONEY_D->money_str(query("goods/"+num+"/price")*100)+"，机不可失，时不再来！"+NOR;
			set("adv/0",system_adv);
			pool+=({0});
		}
    }
	for (int i=0;i<6;i++)
	if (query("adv/"+i))
	{
		pool+=({i});
		flag+=1;
	}
	if (!sizeof(pool))
	return 1;
	num=pool[random(sizeof(pool))];
	adv=query("adv/"+num+"/content");
	CHANNEL_D->do_channel(this_object(), "jy", HIY + "玩家广告："+adv, -1);
	if (flag<5)
	CHANNEL_D->do_channel(this_object(), "jy", HIY + "玩家广告现有少量位置出租，可在"+query("short")+"使用post <内容>发布广告，费用"+MONEY_D->money_str(ADV_COST)+"/天。", -1);
	return 1;
}

int serial_number()//生成流水号，避免重复
{
	return 100000*(1+random(9))+10000*(1+random(9))+1000*(1+random(9))+100*(1+random(9))+10*(1+random(9))+(1+random(9));
}

int dest_goods()
{
	int index,number,*number_pool=({});
	string owner;
	restore_itself();
    for (index=0;index<MAX_ITEMS;index++)
    {
		if (query("goods/"+index+"/ownername")&&time()-query("goods/"+index+"/entry_time")>3600*24*7)
		{
			//CHANNEL_D->do_channel(this_object(), "jy", HIY + query("goods/"+index+"/ownername")+HIY+"("+query("goods/"+index+"/ownerid")+")的"+query("goods/"+index+"/objectname")+HIY+"在"+query("short")+"寄卖超过七日，无人问津，现已下架，请卖主速来取回。" NOR, -1);
			owner=query("goods/"+index+"/ownerid");
            number=serial_number();
            if (query("seller/"+owner+"/old_goods/number_pool"))
			number_pool=query("seller/"+owner+"/old_goods/number_pool");
			number_pool+=({number});
			set("seller/"+owner+"/old_goods/number_pool",number_pool);
			set("seller/"+owner+"/old_goods/"+number,query("goods/"+index));
			delete("goods/"+index);
		}
	}
	advtisement();
	remove_adv();
	save();
	remove_call_out("dest_goods");
	call_out("dest_goods",3600);
	return 1;
}

int gen_gem(object ob,string gemtype,int gemlv)
{
	int *ranges=({4500,5500,8500,9500,9900,9950,9990,9999});
    ob->set_level(ranges[gemlv-1],ranges[gemlv-1],gemtype);
    return 1;
}

int do_getmoney()
{
	object me=this_player();
	int money;
	restore_itself();
	if (!query("seller/"+me->query("id")))
	{
		tell_object(me,"你在"+query("short")+"并未卖出一件物品，所以无款可提。\n");
		return 1;
	}
	if (query("seller/"+me->query("id")+"/credit")<=0)
	{
		tell_object(me,"你在"+query("short")+"的款项已经结清了。\n");
		return 1;
	}
	money=query("seller/"+me->query("id")+"/credit");
	MONEY_D->pay_player(me,money);
	set("seller/"+me->query("id")+"/credit",0);
	message_vision("$N在榷场提的交易所得"+MONEY_D->money_str(money)+"。\n",me);
	me->save();
	save();
    return 1;
}

int do_query(string arg)
{
	object me=this_player();
	int fine,count=0,* sub_index=({}),index,flag=0;
	string *others=({}),msg="你寄卖的物品有：\n";
	restore_itself();
	if (arg=="-me"||arg=="-myself"||!arg)
	{
		for (index=0;index<MAX_ITEMS;index++)
		{
			if (query("goods/"+index+"/ownerid")!=me->query("id"))
			continue;
			else
			{
				flag=1;
				if ((int)query("goods/"+index+"/ori_price")>(int)query("goods/"+index+"/price"))
				fine=query("goods/"+index+"/ori_price")*PENALTY;
				else
				fine=query("goods/"+index+"/price")*PENALTY;
				msg+="["+index+"]\t"+query("goods/"+index+"/objectname")+"\t赎回金额："+MONEY_D->money_str(fine)+"\n";
			}
		}
		if (flag==0)
		msg="这里并无你寄卖的物品。\n";
		if (query("seller/"+me->query("id")+"/credit")>0)
		msg+="你在这里还有"+MONEY_D->money_str(query("seller/"+me->query("id")+"/credit"))+"交易所得尚未提取，可以使用提款(tikuan)命令。\n";
		if (arrayp(query("seller/"+me->query("id")+"/old_goods/number_pool")))
        {
			msg+=LINE;
			msg+="以下是你下架的物品，请尽快取回！\n";
			sub_index=query("seller/"+me->query("id")+"/old_goods/number_pool");
			for (index=0;index<sizeof(sub_index);index++)
			{
				if (query("seller/"+me->query("id")+"/old_goods/"+sub_index[index]+"/ori_price")>query("seller/"+me->query("id")+"/old_goods/"+sub_index[index]+"/price"))
				fine=query("seller/"+me->query("id")+"/old_goods/"+sub_index[index]+"/ori_price")*OFF_PENALTY;
				else
				fine=query("seller/"+me->query("id")+"/old_goods/"+sub_index[index]+"/price")*OFF_PENALTY;
				msg+="["+sub_index[index]+"]"+query("seller/"+me->query("id")+"/old_goods/"+sub_index[index]+"/objectname")+"\t赎回金额："+MONEY_D->money_str(fine)+"\n";
			}
			msg+="以上物品你可用quhui<物品编号>取回，也可使用renounce<物品编号>，"+HIR+"彻底放弃"+NOR+"该物品所有权。\n";
        }
		msg+=LINE;
		msg+="如需查询有哪些玩家在寄售物品，请用query -others指令。\n";
    }
	else if (arg=="-others"||arg=="-players")
	{
		msg="在这里寄卖物品的玩家有：\n";
		for (index=0;index<MAX_ITEMS;index++)
		{
			if (member_array(query("goods/"+index+"/ownerid"),others)==-1)
            {
				if (!stringp(query("goods/"+index+"/ownerid")))
				continue;
				if (query("goods/"+index+"/ownerid")==me->query("id"))
				continue;
				else
				{
					others+=({query("goods/"+index+"/ownerid")});
					flag=1;
					msg+=query("goods/"+index+"/ownerid")+"\t";
					count+=1;
					if (count%5==0)
					msg+="\n";
					msg+="\n";
				}
			}
		}
		if (flag==0)
		msg="这里并无其他玩家寄卖的物品。\n";
		msg+="如需查询自己正在寄售的物品，请用query -me指令。\n";
	}
	else
	{
		msg="如需查询有哪些玩家在寄售物品，请用query -others指令。\n";
		msg+="如需查询自己正在寄售的物品，请用query -me指令。\n";
	}
	tell_object(me,msg);
	return 1;
}
int my_goods_number(object me)
{
	int count;
	for (int i=0;i<MAX_ITEMS;i++)
	if (query("goods/"+i+"/ownerid")==me->query("id"))
	count+=1;
	count+=sizeof(query("seller/"+me->query("id")+"/old_goods"));
	return count;
}
int stock_check1(object me)
{
	if( me->is_busy() )
	{
		tell_object(me,"你现在正忙着呢。\n");
		return 0;
	}
	restore_itself();
	if (my_goods_number(me)>=MAX_CONSIGN) 
	{
		tell_object(me,"榷场是公共场合，每人最多可以寄存"+chinese_number(MAX_CONSIGN)+"件物品。\n");
		return 0;
	}
	if (my_goods_number(me)>=trade_limit(me)) //暂时每人只让寄卖3件物品，以防玩家把这里当成仓库
	{
		tell_object(me,"现在你最多可以寄卖"+chinese_number(trade_limit(me))+"件物品，如果要寄卖更多，把你家里或者榷场存的东西清一清吧。\n");
		return 0;
	}
	return 1;
}
object stock_check2(string ob_name,int sale,object me)
{
	object ob;
	if (!ob=present(ob_name, me))
	{
		tell_object(me,"你身上并无"+ob_name+"这样东西。\n");
		return 0;
	}
	restore_itself();
	if (sizeof(query("goods"))>=MAX_ITEMS)
	{
		tell_object(me,"这里的寄售的东西实在太多了，你去别处看看吧。\n");
		return 0;
	}
	if (sale>MAX_PRICE&&!wizardp(me))
	{
		tell_object(me,MONEY_D->money_str(MAX_PRICE*100)+"以上的交易还是通过拍卖实现吧。\n");
		return 0;
	}
	if (sale<MIN_PRICE&&!wizardp(me))
	{
		tell_object(me,"最低成交价是"+MONEY_D->money_str(MIN_PRICE*100)+"。\n");
		return 0;
	}
	if (ob->is_gems()&&!me->query("ludingshan"))
	{
		tell_object(me,"本店对于宝石以及随机装备离线交易服务只提供给解开鹿鼎山任务的玩家。\n");
		return 0;
	}
	if (ob->query("no_sell_in_playershop")&&ob->query("is_guwanzihua"))
	{
		tell_object(me,"本店只交易真迹，不提供赝品离线交易服务。\n");
		return 0;
	}
	if (ob->query("gem_ob_autoloaded"))
	{	
		tell_object(me,"AUTOLOAD的随机武器不能被离线交易！\n");
		return 0;
	}
	if( ob->query("no_store")&&!ob->is_gems()&&!ob->query("is_guwanzihua"))
	{
		tell_object(me,"这样东西不能被离线交易！\n");
		return 0;
	}
	if (ob->is_character())
	{
		tell_object(me,"活物不能被离线交易！\n");
		return 0;
	}
	if( ob->query("no_pawn")&&!ob->is_gems()&&!ob->query("is_guwanzihua"))
	{
		tell_object(me,"这样东西不能被离线交易！\n");
		return 0;
	}
	if ( ob->query("food_supply") || ob->query("drink_supply") || (ob->query("name")=="清心散"))
	{
		tell_object(me,"这样东西不能被离线交易！\n");
		return 0;
	}

	if( ob->query("no_drop"))
	{
		tell_object(me,"这样东西不能离开你。\n");
		return 0;
	}
	message_vision("$N把身上的" + ob->query("name") + "放在"+query("short")+"处寄卖。\n",me);
	me->start_busy(1);
	return ob;
}
int do_xsell(string arg)
{
	object ob,me=this_player();
	string ob_name,user;
	int sale;
	if (stock_check1(me)==0)
	return 1;
	if( !arg || (sscanf(arg, "%s to %s for %d",ob_name,user,sale) !=3 ) )
	return notify_fail("离线交易指令格式：daishou <物品名> to <玩家id> for <金额>，交易的单位是两白银。\n");
	if (user==me->query("id"))
	return notify_fail("指定卖给自己？不卖就好了啊！\n");
	if (objectp(ob=stock_check2(ob_name,sale,me)))
	return store_item(ob,me,sale,1,user);
	return 1;
}


int do_sell(string arg)
{
	object ob,me=this_player();
	string ob_name;
	int sale;
	if (stock_check1(me)==0)
	return 1;
	if( !arg || (sscanf(arg, "%s for %d",ob_name,sale) !=2 ) )
	return notify_fail("离线交易指令格式：daishou <物品名> for <金额>，交易的单位是两白银。\n");
	if (objectp(ob=stock_check2(ob_name,sale,me)))
	return store_item(ob,me,sale,0,0);
	return 1;
}
string add_color(string list)
{
	list=replace_string(list,"名称",HBYEL+HIM+"名称"+NOR);
	list=replace_string(list,"卖家",HBRED+HIG+"卖家"+NOR);
	list=replace_string(list,"买家",HBRED+HIW+"买家"+NOR);
	list=replace_string(list,"孔数",HIR+"孔数"+NOR);
	list=replace_string(list,"售价",HIY+"售价"+NOR);
	return list;
}
string detail_list(string list,string para,string arg,string type,object me)
{
	int index,prop=0,holes=0;
	string ob_name,seller_name,buyer_name,tmp,tmp_buyer;
	if (para!="/wea")
	{
		list += "┌──┬──────────┬──────┬──────┬──────────────┐\n";
		list +=sprintf("│%4s│%|20s│%|12s│%|12s│%|28s│\n", "编号","名称","卖家","买家","售价" );
	}
	else
	{
		list += "┌──┬──────────┬──────┬──────┬──────────────┬──┬──┐\n";
		list +=sprintf("│%4s│%|20s│%|12s│%|12s│%-28s│%4s│%4s│\n", "编号", "名称","卖家","买家","售价",type,"孔数");
	}
	list =add_color(list);
	for(index=0;index<MAX_ITEMS;index++)
	{
		if (!query("goods/"+index+para))
		continue;
		if (stringp(arg)&&query("goods/"+index+"/skill_type")!=arg&&query("goods/"+index+"/armor_type")!=arg)
		continue;
		ob_name = query("goods/"+index+"/objectname");
		seller_name=query("goods/"+index+"/ownerid");
		if (stringp(query("goods/"+index+"/target_user")))
		{
			buyer_name=HIW+query("goods/"+index+"/target_user")+NOR;
			if (member_array(SECURITY_D->get_status(seller_name),({"(admin)","(arch)","(wizard)","(apprentice)"}))!=-1)
			{
				if (member_array(SECURITY_D->get_status(me->query("id")),({"(admin)","(arch)","(wizard)","(apprentice)"}))==-1&&me->query("id")!=query("goods/"+index+"/target_user"))
				buyer_name=HIR+"巫师赠予"+NOR;
			}
		}
		else
		buyer_name="任意玩家";
		tmp_buyer = COLOR_D->uncolor(buyer_name);
		tmp = COLOR_D->uncolor(ob_name);
		if (para!="/wea")
		{
			list += "├──┼──────────┼──────┼──────┼──────────────┤\n";
			list += sprintf("│%4d│%|20s│%|12s│%|12s│%-28s│\n",index,tmp,seller_name,tmp_buyer,MONEY_D->money_str(100*(int)query("goods/"+index+"/price")) );
		}
		else
		{
			list += "├──┼──────────┼──────┼──────┼──────────────┼──┼──┤\n";
			if (query("goods/"+index+"identified"))
			{
				if (query("goods/"+index+"identified")>1)
				{
					if (query("goods/"+index+"/skill_type")&&query("goods/"+index+"/weapon_prop/damage"))
					prop=query("goods/"+index+"/weapon_prop/damage");
					if (query("goods/"+index+"/armor_type")&&query("goods/"+index+"/armor_prop/armor"))
					prop=query("goods/"+index+"/armor_prop/armor");
				}
				if (query("goods/"+index+"/forge/max"))
				holes=query("goods/"+index+"/forge/max");
				list += sprintf("│%4d│%|20s│%|12s│%|12s│%-28s│%4d│%4d│\n",index,tmp,seller_name,tmp_buyer,MONEY_D->money_str(100*(int)query("goods/"+index+"/price")),prop,holes);
			}
			else
			list += sprintf("│%4d│%|20s│%|12s│%|12s│%-28s│%4s│%4s│\n",index,tmp,seller_name,tmp_buyer,MONEY_D->money_str(100*(int)query("goods/"+index+"/price")),"??","??");
		}
		list = replace_string(list, tmp, ob_name);
		list = replace_string(list, tmp_buyer,buyer_name);
	}
	if (para!="/wea")
	list +="└──┴──────────┴──────┴──────┴──────────────┘\n";
	else
	list +="└──┴──────────┴──────┴──────┴──────────────┴──┴──┘\n";
	return list;
}

int do_list(string arg)
{
	string list,para,type;
    object me=this_player();
    string *weapon = ({"sword", "blade", "staff", "whip", "axe", "spear", "hammer", "halberd", "throwing", "dagger"});
    string *armor = ({"armor", "boots", "cloth", "hands", "head", "shield", "surcoat", "waist", "wrists", "finger", "neck"});
	restore_itself();
    if(sizeof(query("goods") )== 0 )
    return notify_fail("目前没有任何物品寄卖。\n");
    list = "下列这些东西正在寄售：(请使用命令 buy <物品编号> 来购买)\n\n";
    if (stringp(arg) && (member_array(arg, weapon) != -1 || member_array(arg, armor) != -1))
    {
        para="/wea";
		if(member_array(arg, weapon) != -1)
		type = "伤害";
		else 
		type = "防御";
        list += "┏" + HBGRN"所有"+arg+"列表"NOR + "┓\n";
        list =detail_list(list,para,arg,type,me);
    }
    else if(stringp(arg) && arg == "gem")
    {
		para="/gem";
        list += "┏" + HBGRN"所有宝石列表"NOR + "┓\n";
        list =detail_list(list,para,0,0,me);
    }
    else if (stringp(arg) && arg == "guwan")//古玩
    {
		para="/guwan";
        list += "┏" + HBGRN"所有古玩列表"NOR + "┓\n";
        list =detail_list(list,para,0,0,me);
    }
    else if (stringp(arg) && arg == "zihua")//字画
    {
		para="/zihua";
        list += "┏" + HBGRN"所有字画列表"NOR + "┓\n";
        list =detail_list(list,para,0,0,me);
    }
    else //list all
    {
		para="/objectname";
        list += "┏" + HBGRN"所有寄售物品列表"NOR + "┓\n";
		list =detail_list(list,para,0,0,me);
        list +=HIY+"list 寄售物品列表可加参数如下，gem、武器护具(同荣宝斋，如sword)、zihua、guwan，格式：list sword。\n"+NOR;
    }
    me->start_more(list);
    return 1;
}

void deposit(object ob,int index,string *paras)
{
	for (int i=0;i<sizeof(paras);i++)
	set("goods/"+index+"/"+paras[i],ob->query(paras[i]));
}
void withdraw(object ob,int index,string save_path,string *paras)
{
	for (int i=0;i<sizeof(paras);i++)
	ob->set(paras[i],query(save_path+paras[i]));
}
string query_save_path(int index,object me)
{
	if (index<MAX_ITEMS)
	return "goods/"+index;
	else
	return "seller/"+me->query("id")+"/old_goods/"+index;
}
int do_retrieve(string arg)
{
	int afford,flag=0,index,ob_price,fine,*sub_index=({});
	string ob_file,ob_id,ob_ownerid,save_file,save_path;
	object ob,me= this_player();
	restore_itself();
	if (!sizeof(query("goods"))&&!sizeof(query("seller/"+me->query("id")+"/old_goods/number_pool")))
	return notify_fail(query("short")+"里并没有被任何人寄放的物品。\n");
	if( !arg || sscanf(arg, "%d", index)!=1 )
	return notify_fail("指令格式：quhui <物品标号>\n");
	if (index<MAX_ITEMS)//在售商品
	flag=1;
	save_path=query_save_path(index,me);
	ob_file=query(save_path+"/object");
	ob_id=query(save_path+"/id");
	ob_ownerid=query(save_path+"/ownerid");
	ob_price=query(save_path+"/ori_price")*100;
	if (ob_ownerid!=me->query("id"))
	return notify_fail("这样物品并非是你寄存的。\n");
	fine=max(({query(save_path+"/ori_price"),query(save_path+"/price")}))*OFF_PENALTY;
	if( !(afford = me->can_afford(fine)) )  
	return notify_fail("你没有足够的钱来赎回。\n");
	if( afford == 2 )
	return notify_fail("你没有足够的零钱，而银票在这里是无法流通的。\n");
	me->start_busy(1);
	MONEY_D->player_pay(me,fine);	
	ob = new(ob_file);
	if (!flag)//还原下架商品
	{
		if (query("seller/"+me->query("id")+"/old_goods/number_pool"))
		sub_index=query("seller/"+me->query("id")+"/old_goods/number_pool");
		sub_index-=({index});
		set("seller/"+me->query("id")+"/old_goods/number_pool",sub_index);
		if (!sizeof(sub_index))
		delete("seller/"+me->query("id")+"/old_goods/number_pool");
	}
	if (ob->query("is_guwanzihua"))
	buy_guwan(ob,me,index,flag);
	if (ob->is_gems())
	buy_gem(ob,me,index,flag);
	ob->set_name(query(save_path+"/objectname"),({ob_id}));
	ob->move(me);
	delete(save_path);
	save();
	me->save();
	message_vision("$N赎回了$n。\n", me, ob);
	return 1;
}
int do_buy(string arg)
{
	int index,ob_price,afford,gemlv,owner_income;
	string ob_ownerid,ob_file,ob_id,save_file;
	object ob,me=this_player();
	if(me->is_busy() )
	return notify_fail("你正忙着呢。\n");
	restore_itself();
	if(sizeof(query("goods")) == 0  )
	return notify_fail(query("short")+"今天还没有人来寄卖东西。\n");
	if( !arg || (sscanf(arg, "%d",index) !=1 ))  
	return notify_fail("指令格式：buy <物品编号>\n");
	if (query("goods/"+index+"/target_user")&&query("goods/"+index+"/target_user")!=me->query("id"))
    return notify_fail("这件商品被物主指定了买主，买主不是你！\n");
	if (!query("goods/"+index))
	return notify_fail("这个编号的商品不存在！\n");
	ob_ownerid=query("goods/"+index+"/ownerid");
	ob_file=query("goods/"+index+"/object");
	ob_id=query("goods/"+index+"/id");
	ob_price=query("goods/"+index+"/price")*100;
	if (ob_ownerid==me->query("id"))
    return notify_fail(HIR+"你来捣乱的吗？自己寄售的东西还要自己买回去？\n"+NOR);
	if( !(afford = me->can_afford(ob_price)) )  
	return notify_fail("你没有足够的钱来购买这样物品。\n");
	if( afford == 2 )
	return notify_fail("你没有足够的零钱，而银票在这里是无法流通的。\n");
	me->start_busy(1);
	MONEY_D->player_pay(me,ob_price);
	add("buyer/"+me->query("id")+"/buybonus",ob_price/100);
	if (ob_price>=5000000)
	CHANNEL_D->do_channel(this_object(), "jy", HIY + me->query("name")+HIY+"("+me->query("id")+")大手笔花了"+MONEY_D->money_str(ob_price)+"，购得"+query("goods/"+index+"/objectname")+HIY+"一件。" NOR, -1);
	owner_income=ob_price-ob_price*TAX/100;
	ob = new(ob_file);
	if (ob->query("is_guwanzihua"))
	buy_guwan(ob,me,index,1);
	if (ob->is_gems())
    buy_gem(ob,me,index,1);
	ob->set_name(query("goods/"+index+"/objectname"),({ob_id}));
	ob->move(me);
	add("seller/"+ob_ownerid+"/credit",owner_income);
	delete("goods/"+index);
	save();
	me->save();
	message_vision("$N以"+MONEY_D->money_str(ob_price)+"的价格在"+query("short")+"购得一件$n。\n", me, ob);
	return 1;
}
int buy_gem(object ob,object me,int index,int flag)
{
	string save_path;
	if (flag)
	save_path="goods/"+index;
	else
	save_path="seller/"+me->query("id")+"/old_goods/"+index;
	if (ob->is_gem())
	{
		gen_gem(ob,query(save_path+"/material"),query(save_path+"/level"));
	}
	else
	{
		if(query(save_path+"/skill_type"))
		//withdraw(ob,index,save_path+"/",({"skill_type","weapon_prop/damage","weapon/min_dam","weapon/max_dam","weapon/damage"}));
		withdraw(ob,index,save_path+"/",({"skill_type","weapon_prop"}));
		if(ob->query("armor_type")) 
		//withdraw(ob,index,save_path+"/",({"armor_type","armor_prop/armor","armor/min_def","armor/max_def","armor/armor"}));
		withdraw(ob,index,save_path+"/",({"armor_type","armor_prop"}));
		withdraw(ob,index,save_path+"/",({"forge","level","base_weight","weight","rigidity","max_rigidity","value","long","identified"}));
	}
	return 1;
}

int buy_guwan(object ob,object me,int index,int flag)
{
	string save_path;
	if (flag)
	save_path="goods/"+index;
	else
	save_path="seller/"+me->query("id")+"/old_goods/"+index;
    if (query(save_path+"/unidentified"))
	return 1;
    else
	{
		ob->set("itemlist",query(save_path+"/itemlist"));
        ob->set("identified",1);
        ob->set("guwan_jiandinged",1);
        ob->rename();
        return 1;
    }
}

int store_item(object ob,object me,int sale,int flag,string user)
{
	int value,holes,index,i;
	string gemtype,type;
	restore_itself();
	for (i=0;i<MAX_ITEMS;i++)//获得释放的编号
	{
		if (!query("goods/"+i))
		{
			index=i;
			break;
		}
	}
	if (ob->query("is_guwanzihua"))
	{
		set("goods/"+index+"/guwan_zihua", 1);
		if (ob->query("guwan"))
		set("goods/"+index+"/guwan", 1);
		else
		set("goods/"+index+"/zihua", 1);
		if (ob->query("identified"))
		{
			set("goods/"+index+"/itemlist",ob->query("itemlist"));
			set("goods/"+index+"/identified",1);
		}
		else
		set("goods/"+index+"/unidentified",1);
		deposit(ob,index,({"value","name"}));
	}
	if (ob->is_gems())
	{
		if (!ob->is_gem())
		{
			if(ob->query("skill_type"))
			//deposit(ob,index,({"skill_type","weapon_prop/damage","weapon/min_dam","weapon/max_dam","weapon/damage"}));
			deposit(ob,index,({"skill_type","weapon_prop"}));
			if(ob->query("armor_type")) 
			//deposit(ob,index,({"armor_type","armor_prop/armor","armor/min_def","armor/max_def","armor/armor"}));
			deposit(ob,index,({"armor_type","armor_prop"}));
			deposit(ob,index,({"forge","level","base_weight","weight","rigidity","max_rigidity","value","long","identified"}));
			set("goods/"+index+"/wea",1);//武器铠甲
		}
		else
		{
			deposit(ob,index,({"level","material"}));
			set("goods/"+index+"/gem",1);//宝石
		}
		if(ob->query("equipped"))
		ob->unequip();
		ob->set("owner_id", me->query("id"));
		ob->set("savetime", time());
		ob->save();
	}
	set("goods/"+index+"/object", base_name(ob));
	set("goods/"+index+"/objectname", ob->query("name"));
	set("goods/"+index+"/id", ob->query("id"));
	set("goods/"+index+"/ownername", me->query("name"));
	set("goods/"+index+"/ownerid", me->query("id"));
	set("goods/"+index+"/price", sale);
	set("goods/"+index+"/ori_price", sale);
	set("goods/"+index+"/entry_time",time());
	if (flag==1&&user)//定向交易，只有id为user内容的玩家才能购买。
	set("goods/"+index+"/target_user",user);
	save();
	me->save();
	destruct(ob);
	return 1;
}