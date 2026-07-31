//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i,j,all,page;
	object *inv, bao,ob;
	mapping count;
	mapping equiped;
	mapping unit;
	mapping ids;
	mapping itype;
	string *text,pops,short_name;
	
	string str,sss;
	string *dk=({});

	if( !arg )
	{
		page = 1;
	}
	else if(sscanf(arg,"%d %s",page,arg)!=2)
	{
		page = 1;
	}

	if (wizardp(me) && arg)
	{
		ob = find_player(arg);
		if (! ob) ob = find_living(arg);
		if (! ob) ob = present(arg, environment(me));
		if (! ob) return notify_fail("没有这个玩家。\n");
	}

	if (! ob) ob = me;

	inv = all_inventory(ob);
	if (! sizeof(inv))
	{
		write(ZJOBLONG+((ob == me) ? "你共有"HIY+ob->query("yuanbao")+"灵石"NOR"，"HIY+ob->query("jifeng")+"点券"NOR"。目前你身上没有任何东西。\n" : ob->query("yuanbao")+"身上没有携带任何东西。\n"));
		return 1;
	}
	for (i = 0; i < sizeof(inv); i++)
	{
		//short_name = inv[i]->query("name");
		short_name = inv[i]->query("name")+ZJBR+inv[i]->query("id");
		if(inv[i]->query_amount())
			short_name = inv[i]->query_amount() + inv[i]->query("base_unit") + short_name;

		sss = short_name;
		if (inv[i]->query("equipped"))
			sss = HIG"■"NOR+sss;
		if (inv[i]->query("no_give")||inv[i]->query("no_drop"))	
		    sss = HIW"√"NOR+sss;	
		if (inv[i]->query("tejia"))	
		    sss = HIG"特价"NOR+sss;			    	
		else sss = " "+sss;

		dk += ({ sss + ":look " + file_name(inv[i]) });
	}
	text = sort_array(dk, 1);

	str = ZJOBLONG+sprintf("%s共有"HIY"%d灵石，%d点券，"HIC"%d天机点。"NOR+ZJBR"身上带著下列这些东西(%d件，负重 %d%%)：\n",
		      (ob == me)? "你" : ob->name(),ob->query("yuanbao"),ob->query("jifeng"),ob->query("tianji1"),sizeof(text),
		      (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance());

	str += ZJOBACTS2+ZJMENUF(3,3,8,33);

	all = sizeof(text)/30;
	if(sizeof(text)%30) all += 1;
	if(page<1) page = 1;
	if(page>all) page = all;
	j = (page-1)*30;
	i = page*30;
	if (i >= sizeof(text)) i = sizeof(text);
	i--;
	if(all>1)
		str += "上一页:inventory "+(page-1)+" "+ob->query("id")+ZJSEP"下一页:inventory "+(page+1)+" "+ob->query("id")+ZJSEP"我的储物袋:look chuwu dai"" "+ZJSEP;
	str += implode(text[j..i], ZJSEP);
	write(str+"\n");
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: inventory
 
可列出你(你)目前身上所携带的所有物品。
 
注 : 此指令可以 " i " 代替。

HELP );
	return 1;
}