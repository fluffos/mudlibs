#include <ansi.h>

#define MYSHOP_DIR	"/clone/vip2/shimen"

inherit F_CLEAN_UP;

mapping mtypes = ([
	"商城":"。。。",
]);

int main(object me, string arg)
{
	string str,*all_file,file,price,type,*types;
	int i,yuanbao,value;
	object ob;
	int amount;

	all_file = list_dirs(MYSHOP_DIR);

	if(!sizeof(all_file))
		return notify_fail("商城中暂无"HIG"绑定"NOR"类商品出售。。\n");

	if (! arg)
	{
	 str = ZJOBLONG"你目前有"+me->query("gongxian")+"师门贡献，请选择您想购买的"HIG"绑定"NOR"类道具：\n"ZJOBACTS2+ZJMENUF(4,4,8,37); 	
		for(i=0;i<sizeof(all_file);i++)
		{
			file = MYSHOP_DIR+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			yuanbao = file->query("yuanbao");
			price = yuanbao?(yuanbao+"师门贡献"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s"ZJBR"%s:myshop2 look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if(arg=="type")
	{
		str = ZJOBLONG"你目前有"+me->query("yuanbao")+"师门贡献，请选择您想购买的道具类别：\n"ZJOBACTS2+ZJMENUF(4,4,8,37);
		types = sort_array(keys(mtypes),(:strcmp:));
		for(i=0;i<sizeof(types);i++)
		{
			str += sprintf("%s:myshop2 type %s"ZJSEP,types[i],types[i]);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"type %s",type)==1)
	{
		if(!mtypes[type])
			return notify_fail("商城中暂无"HIG+type+NOR"类商品出售。\n");
		all_file = list_dirs(MYSHOP_DIR+mtypes[type]+"/");
		if(!sizeof(all_file))
			return notify_fail("商城中暂无"HIG+type+NOR"类商品出售。\n");
		str = ZJOBLONG"你目前有"+me->query("yuanbao")+"师门贡献，请选择您想购买的"HIG+types[i]+NOR"类道具：\n"ZJOBACTS2+ZJMENUF(4,4,8,37);
		for(i=0;i<sizeof(all_file);i++)
		{
			file = MYSHOP_DIR+mtypes[type]+"/"+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			yuanbao = file->query("yuanbao");
			price = yuanbao?(yuanbao+"师门贡献"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s"ZJBR"%s:myshop2 look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		yuanbao = file->query("yuanbao");
		price = yuanbao?(yuanbao+"师门贡献"):(MONEY_D->money_str(file->query("value")));
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "购买1个:myshop2 buy 1 "+file+ZJSEP"批量购买:myshop2 buy "+file+"\n";
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			if(file_size(file)<0||strsrch(file,MYSHOP_DIR)!=0)
				return notify_fail(HIM"没有这个道具！！"NOR"\n");
			write(INPUTTXT("你想买多少个"+file->query("name")+"？"ZJBR"请确认你的背包空间足够。","myshop2 buy $txt# "+file)+"\n");
			return 1;
		}

		if(file_size(file)<0||strsrch(file,MYSHOP_DIR)!=0)
			return notify_fail(HIM"没有这个道具！！"NOR"\n");

		if(file->query("no_shop"))
			return notify_fail(HIM"已下架商品，无法购买！！"NOR"\n");
		if(amount<1)
			return notify_fail(HIM"你要买多少个？？"NOR"\n");
		if(!file->query_amount()&&amount>10)
			return notify_fail(HIM"不可叠加物品一次最多买10个！！"NOR"\n");
		else if(amount>999)
			return notify_fail(HIM"一次最多买999个！！"NOR"\n");

		yuanbao = file->query("yuanbao");
		if(!value=file->query("base_value"))
			value = file->query("value");
		if(!yuanbao&&!value)
			return notify_fail(HIM"购买失败！！"NOR"\n");

		if(yuanbao)
		{
			if(!me->query("gongxian")||me->query("gongxian")<(yuanbao*amount))
				return notify_fail(HIM"你的点券不足！！"NOR"\n");
			me->add("gongxian",-yuanbao*amount);
			log_file("pay/myshop2", sprintf("%s:%s(%s)消费%d点券，从随身商城购买%d个%s(%s)。\n",
				ctime(time()),me->query("name"),me->query("id"),yuanbao*amount,amount,file->query("name"),file->query("id")));
			me->add("zjvip/yuanbao_used",yuanbao*amount);
		}
		else
		{
			if(!MONEY_D->player_pay(me, value * amount))
				return notify_fail(HIM"你的钱没那么多了！！"NOR"\n");
			log_file("pay/myshop2", sprintf("%s:%s(%s)消费%s，从随身商城购买%d个%s。\n",
				ctime(time()),me->query("name"),me->query("id"),MONEY_D->money_str(value*amount),amount,file->query("name")));
		}
		if(file->query_amount())
		{
			ob = new(file);
			ob->set_amount(amount);
			write("你从商城中成功购买到"+ob->short()+"。"NOR"\n");
			ob->move(me,1);
		}
		else
		{
			for(i=0;i<amount;i++)
			{
				ob = new(file);
				ob->move(me,1);
			}
			write("你从商城中成功购买到"+amount+ob->query("unit")+ob->short()+"。"NOR"\n");
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
