//商业系统控制器,系统重要参数

void create()
{
    seteuid(getuid());
}

#define MAX_SHOP_LEVEL 10

int get_max_shop_level()
{
	return MAX_SHOP_LEVEL;
}

//税率控制,千分比。这里是交易税，而不是盈利税。
//因为很难计算盈利
int get_tax(string type,int level)
{
	int tax = 0;
	if(type == "hockshop")
	{
		tax = 10;
	}
	return tax;
}