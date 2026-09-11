// condition fake.c 迷惑
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
	  HIR"迷惑解除。"+NOR+"\n");
	  if (TROOP_D->get_troops(tid, "fake"))
		TROOP_D->set_troops(tid,"fake", "");
	}	
	return;
}
