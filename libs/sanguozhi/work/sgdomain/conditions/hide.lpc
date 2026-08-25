// condition hide.c 隐藏
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
	
	if (duration <= 3)
	{ tell(all_inventory(tt),
	  HIR"隐藏时间已过，队伍显身。"+NOR+"\n");
	  if (TROOP_D->get_troops(tt, "qibing"))
		TROOP_D->set_troops(tt,"qibing", 0);
	  if (TROOP_D->get_troops(tt, "maifu"))
                TROOP_D->set_troops(tt,"maifu", 0);
	}	
	return;
}
