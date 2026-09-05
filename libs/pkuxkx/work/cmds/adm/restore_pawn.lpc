//根据/d/private/id[0]/id 下的数据恢复荣宝斋装备

#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object pl;
	string* datas;
	string directory;
	int i;
	string basename;
	object gem;
	string ssavetime;
	int savetime;
	mixed* stat_info;
	
	
	if (!arg)
			  return notify_fail("你想恢复谁的荣宝斋装备？\n");
	if(!objectp(pl=find_player(arg)))
		return notify_fail("此玩家不在线。\n");
	directory = "/d/private/"+arg[0..0]+"/"+arg+"/";
	if( file_size(directory) == -1 )
			return notify_fail(arg+"在荣宝斋没当东西。\n");	
	datas = get_dir(directory);
	for(i=0;i<sizeof(datas);i++)
	{
		stat_info = stat(directory+datas[i]);

		basename = read_file(directory+datas[i],1,1);
		basename = replace_string(basename,"#","");
		basename =  replace_string(basename,"\n","");
		gem = new(basename);
		gem->set("owner_id",arg);
		ssavetime = replace_string(datas[i],arg,"");
		ssavetime = replace_string(ssavetime,".o","");
		sscanf(ssavetime,"%d",savetime);
		gem->set("savetime",savetime);
		gem->restore();
		gem->set_name(gem->query("name"),({gem->query("id")}));
	/*	if(gem->query("sockets/max") == 3 || gem->query("forge/max") == 3)
		{
			pl = this_player();
			
			gem->move(pl);
		}
		else if((gem->query("sockets/max") == 2 || gem->query("forge/max") == 2) && ( (gem->query("ring/armor") >= 49 && gem->query("necklace/armor") < 50)  || (gem->query("necklace/armor") >= 49 && gem->query("ring/armor") < 50) ) )
		{
			pl = this_player();
			
			gem->move(pl);

		}*/
		if(gem->query("weapon/damage") >= 220)
		{
			pl = this_player();
			
			gem->move(pl);

		}
	}
	return 1;       
}
int help(object me)
{
  write(@HELP
指令格式 : restore <玩家id>
 
此指令可让你把玩家的荣宝斋装备恢复。适用于通过restore命令恢复了备份档案，导致和/d/private下的数据对应不上的情况
因为荣宝斋在玩家身上存放了索引，在/d/private存放的具体数据。restore了玩家数据，就不匹配了。这个命令清楚玩家身上的
索引信息和/d/private下的数据文件，变成实际的物品，交给玩家自己处理。
HELP
    );
    return 1;
}
