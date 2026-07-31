#include <ansi.h>

#define MYSHOP_DIR	"/clone/menpai/"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,*all_file,file,price,type,*types;
	int i,gongxian,value;
	object ob;
	mixed today;
	int amount;

	all_file = list_dirs(MYSHOP_DIR);

	if(!sizeof(all_file))
		return notify_fail("商城中暂无商品出售。\n");
	
	if (! arg)
	{
		str = ZJOBLONG"你目前有"+me->query("gongxian")+"贡献，请选择您想兑换的道具：\n"ZJOBACTS2+ZJMENUF(3,4,8,32);
		for(i=0;i<sizeof(all_file);i++)
		{
			file = MYSHOP_DIR+all_file[i];
			if(file_size(file)<0) continue;
			gongxian = file->query("gongxian");
			if(gongxian)
			{
				gongxian = gongxian;
				if(gongxian<1) gongxian = 1;
			}
			price = gongxian?(gongxian+"贡献"):((file->query("gongxian")));
			str += sprintf("%s"ZJBR"%s:mpsd look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		gongxian = file->query("gongxian");
			if(gongxian)
			{
				gongxian = gongxian;
				if(gongxian<1) gongxian = 1;
			}
		price = gongxian?(gongxian+"贡献"):((file->query("gongxian")));
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "兑换1个:mpsd buy 1 "+file+ZJSEP"批量兑换:mpsd buy "+file+"\n";
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			if(file_size(file)<0||strsrch(file,MYSHOP_DIR)!=0)
				return notify_fail(HIM"没有这个道具！！"NOR"\n");

			write(INPUTTXT("你想兑换多少个"+file->query("name")+"？"ZJBR"请确认你的背包空间足够。","mpsd buy $txt# "+file)+"\n");
			return 1;
		}

		if(file_size(file)<0||strsrch(file,MYSHOP_DIR)!=0)
			return notify_fail(HIM"没有这个道具！！"NOR"\n");
		if(amount<1)
			return notify_fail(HIM"你要买多少个？？"NOR"\n");
		if(amount>999)
			return notify_fail(HIM"你要买多少个？？"NOR"\n");
		if(!file->query_amount()&&amount>10)
			return notify_fail(HIM"不可叠加物品一次最多买10个！！"NOR"\n");

		gongxian = file->query("gongxian");
			if(gongxian)
			{
				gongxian = gongxian;
				if(gongxian<1) gongxian = 1;
			}
		if(!value=file->query("base_value"))
			value = file->query("value");
		if(!gongxian&&!value)
			return notify_fail(HIM"兑换失败！！"NOR"\n");

		if(gongxian)
		{
			if(!me->query("gongxian")||me->query("gongxian")<(gongxian*amount))
				return notify_fail(HIM"你的贡献不足!!"NOR"\n");
			me->add("gongxian",-gongxian*amount);
			log_file("pay/mpsd", sprintf("%s:%s(%s)使用了%d贡献，从贡献商城兑换%d个%s(%s)。\n",
				ctime(time()),me->query("name"),me->query("id"),gongxian*amount,amount,file->query("name"),file->query("id")));
			me->add("zjvip/gongxian_used",gongxian*amount);
		}
		else
		{
			if(!MONEY_D->player_pay(me, value * amount))
				return notify_fail(HIM"你的门派贡献没那么多了！！"NOR"\n");
			log_file("pay/mpsd", sprintf("%s:%s(%s)消费%s，从随身商城兑换%d个%s。\n",
				ctime(time()),me->query("name"),me->query("id"),MONEY_D->money_str(value*amount),amount,file->query("name")));
		}
		if(file->query_amount())
		{
			ob = new(file);
			ob->set_amount(amount);
			write("你从商城中成功兑换到"+ob->short()+"。"NOR"\n");
			ob->move(me,1);
		}
		else
		{
			for(i=0;i<amount;i++)
			{
				ob = new(file);
				ob->move(me,1);
			}
			write("你从商城中成功兑换到"+amount+ob->query("unit")+ob->short()+"。"NOR"\n");
		}
		if(file->query("max_buy"))
		{
			me->add("buy_max/"+file->query("id"),amount);
		}
		return 1;
	}
	else
		return notify_fail(HIM"你想干什么？？"NOR"\n");

	return 1;
}

int help(object me)
{
     write(@HELP

随身商城。

HELP
    );
    return 1;
}
