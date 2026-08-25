// condition poison.c 中毒
// group@sgz August 23, 1999
#include <ansi.h>
#include <mudlib.h>
#include <daemons.h>

void execute_con(int tid, int damage, int duration)
{
	object tt;

	tt = TROOP_D->find_troop( tid );

	if( !tt||!objectp(tt)||!tt->is_troop() ){
		SGSYS(sprintf("troop %O does not exist, ", tid));
		return;
	};
	
	WARAI_D->kill_troop(tid, damage);
	
	tell(all_inventory(tt),
	HIR"只见士兵们脸色发青，口吐白沫，正是中毒的迹象。"+NOR+"\n");
	WARAI_D->war_inf(TROOP_D->get_troops(tid,"task_id"),
	tt->query_id()[1]+"受中毒困扰，损失"+chinese_number(damage)+"人。","b");
	WARAI_D->clear_empty_troop(({tid}));
	return;
}
