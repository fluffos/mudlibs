// condition confuse.c 混乱
// group@sgz August 23, 1999
#include <ansi.h>
#include <mudlib.h>
#include <daemons.h>

void execute_con(int tid, int damage, int duration)
{
	object tt;
	int mora, mora1;

	tt = TROOP_D->find_troop( tid );
	
	if( !tt||!objectp(tt)||!tt->is_troop() ){
		SGSYS(sprintf("troop %O does not exist, ", tid));
		return;
	};
	mora1 = -random(4) -1;
	TROOP_D->add_morale(tid,mora1);	
	
	if (duration <=1)
	tell(all_inventory(tt),
        HIG"混乱慢慢平复了。"+NOR+"\n");
	else {
	tell(all_inventory(tt),
	HIR"只见士兵们一片混乱，士气降低。"+NOR+"\n");
	WARAI_D->kill_troop(tid,damage);	
	WARAI_D->war_inf(TROOP_D->get_troops(tid,"task_id"),
	tt->query_id()[1]+"受混乱困扰，逃跑"+chinese_number(damage)+"人。","b");
	WARAI_D->clear_empty_troop(({tid}));
	}	
return;
}
