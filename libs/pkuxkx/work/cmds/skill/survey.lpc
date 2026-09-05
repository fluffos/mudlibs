// profession职业系统 by Vast@pkuxkx 2009-06
// survey.c 查询命令

#include <ansi.h>

int main(object me, string arg)
{
	mapping profs, stuff;
	string file, type, *list, msg, *mat;
	object env, food, *all_mat;
	int sk, i, j, k, n, *num, time;
	
	if(!arg) return notify_fail("你要查询什么？\n");

	if(!mapp(profs = me->query_profs()) )
		return notify_fail("你并不会任何职业技能！\n");
		
	n = sizeof(profs);
	for(i = 0; i < n; i++)
	{
		list = values(profs)[i];
		type = keys(profs)[i];
		if(member_array(arg, list) != -1)
			break;
		if(i == n)
			return notify_fail("你并不会做" + to_chinese(arg) + "啊！\n");
	}
	
	file = PROFESSION_D(type + "/" + arg);
	
	stuff = file->query_stuff();
	if(!mapp(stuff)) return notify_fail("错误！\n");
		
	mat = keys(stuff);
	num = values(stuff);	
	
	msg = sprintf(GRN"┌%-24s"+ BBLK + GRN "───────────┐\n"NOR, "【" + to_chinese(arg) + "】材料清单：");
	
	for(i = 0; i < sizeof(stuff); i++)
		msg += sprintf("│%-20s        -       %2d  %2s    │\n", mat[i]->short(), num[i], mat[i]->query("unit"));

	msg +=  sprintf(GRN"└───────────────────────┘\n"NOR); 
	write(msg);
	me->start_busy(1);	
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : survey [食物英文名称]

使用此命令可以查询制作某种食物所需要的原料

相关命令: professions(prof), cook, 
HELP
	);
	return 1;
}