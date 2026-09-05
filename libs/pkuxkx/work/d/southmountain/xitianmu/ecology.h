// 生成的东西有些生态规律 Zine 2014/7/14
#include <ansi.h>
int gene_eco(string npc_file,string gene_area,int Limit)
{
	object npc,*npcs;
	int cur_no,future_no=1+random(2),i;
	if (time()==query("init_time"))
	{
		for (i=0;i<future_no;i++)
		{
			npc=new(npc_file);
			npc->move(MAP_D->random_room(gene_area,0));
		}
		return 1;
	}
	npcs=children(npc_file);
	npcs=filter(npcs,(: environment:));
	npcs=filter(npcs,(: environment($1)->query_location()==$2:),gene_area);
	cur_no=sizeof(npcs);
	set("current_no",cur_no);
	if (cur_no<1||cur_no>=Limit)
	return 1;
	future_no=cur_no*2;
	if (future_no>Limit)
	future_no=Limit;
	future_no-=cur_no;
	for (i=0;i<future_no;i++)
	{
		npc=new(npc_file);
		npc->move(MAP_D->random_room(gene_area,0));
	}
	return 1;
}
