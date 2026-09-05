#include <ansi.h>
mapping *products(object me)
{
	return SMITH->smith(me);
}
int main(object me, string arg)
{
	mapping *products=products(me);
	string lu_msg,msg="你可打造的装备有：\n";
	if (!arg)
	{
		for (int i=0;i<sizeof(products);i++)
		{
			msg+=HBCYN+HIW+products[i]["name"]+NOR;
			if (i==sizeof(products)-1)
			msg+="。\n";
			else
			msg+="、";
		}
		write(msg);
		return 1;
	}
	else
	{
		for (int i=0;i<sizeof(products);i++)
		if (products[i]["name"]==arg)
		{
			write("『"+HIC+arg+NOR+"』温度需要："+products[i]["temperature"]+"|基础失败概率："+products[i]["fail_possibility"]+"%|开始等级："+U+(products[i]["maker_level"])+NOR+" 级|锤炼次数："+U+(products[i]["hammer_require"])+NOR+" 次。\n");
			write("随着锻造术级别的提升，锻造"+arg+"的失败概率下降；随着材料的提升，锻造"+arg+"的失败概率升高。\n");
			return 1;
		}
	}
	write("『"+arg+"』并不存在，或你并未掌握打造这种装备的方法。\n");
	return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : smith
用这个指令可以查询你可以打造的所有装备。
smith <装备>
用这着指令可以查询你需要打造装备的具体细节。
HELP
);
        return 1;
}

