#define MAXBTS 5
#include <localtime.h>

int join_bts(int flag)
{
	object where, *inv;
	int lp;

//flag 为 1表示是郭靖本人调用本函数	
	if(flag)
		return sizeof(query("bwlist"));

//flag 不为0表示是蒙古兵调用本函数	
	where=find_object("/d/xiangyang/sfdating");
	if (!objectp(where))
		return 0;
	
	inv=all_inventory(where);
	for(lp=0;lp<sizeof(inv);lp++)
	{
		if (inv[lp]->query("id")=="guo jing")
			return sizeof(inv[lp]->query("bwlist"));
	}
	
	return 0;
}

int now_hour()
{
	mixed *tm=localtime(time());
	int hour=tm[LT_HOUR];
	
	return hour;
}