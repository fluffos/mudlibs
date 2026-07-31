#define MYSHOP_DIR	"/clone/heixin_shop/"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,*all_file,file,price,type,*types;
	int i,yuan_bao,value;
	object ob;
	int amount;
	string banghui;

	all_file = list_dirs(MYSHOP_DIR);

	if(!sizeof(all_file))
		return notify_fail("商城中暂无商品出售。\n");

	if (! arg)
	{
		str = ZJOBLONG"你目前有"+me->query("yuan_bao")+"通宝，请选择您想购买的道具：\n"ZJOBACTS2+ZJMENUF(4,4,8,30);
		for(i=0;i<sizeof(all_file);i++)
		{
			file = MYSHOP_DIR+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			yuan_bao = file->query("yuanbao");
			price = yuan_bao + "通宝";
			str += sprintf("%s"ZJBR"%s:test look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		yuan_bao = file->query("yuanbao");
		price = yuan_bao+"通宝";
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "购买1个:test buy 1 "+file+ZJSEP"批量购买:test buy "+file+"\n";
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			write(INPUTTXT("你想买多少个"+file->query("name")+"？"ZJBR"请确认你的背包空间足够。","test buy $txt# "+file)+"\n");
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

		yuan_bao = file->query("yuanbao");
		
		if(!yuan_bao)
		{
			write (HIM"购买失败！！"NOR"\n");
			return 0;
		}

		if(yuan_bao)
		{		
			if(!me->query("yuan_bao")||me->query("yuan_bao")<(yuan_bao*amount))
			{
				write("你的通宝不足。\n");
				return 0;
			}
		
			me->add("yuan_bao",-yuan_bao*amount);
			log_file("pay/heixin_shop", sprintf("%s:%s(%s)消费%d通宝，从随身商城购买%d个%s(%s)。\n",
				ctime(time()),me->query("name"),me->query("id"),yuan_bao*amount,amount,file->query("name"),file->query("id")));
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