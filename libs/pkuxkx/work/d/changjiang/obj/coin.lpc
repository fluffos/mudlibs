//奥运纪念币 Zine dec 7 2010 ,铜雀台
#include <ansi.h>
inherit F_SAVE;
inherit ITEM;
#define MAX_NUM 18
#define COIN "/data/business/olympic_coin/"+query("serial_num")
string query_save_file()
{
	return COIN;
}
int check_valid();
void create()
{
	set_name(HIY"奥运纪念金币"NOR, ({ "olympic coin","coin","jin bi","bi"}));
	set_weight(1000);
    set("value",10000);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一枚奥运纪念金币。\n");
			set("unit", "枚");
		}
	setup();
	check_valid();
}

int check_valid()
{
	int num;
	string *coins=get_dir("/data/business/olympic_coin/"+"*");
	set("coins",coins);
	num=sizeof(coins)+1;
	if (num>MAX_NUM)
	{
		destruct(this_object());
		return 1;
	}
	set("serial_num",num);
	save();
	return 1;
}