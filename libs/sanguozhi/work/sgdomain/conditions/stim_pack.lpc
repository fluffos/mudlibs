// A simple condition stim_pack.c 兴奋剂
// Flee@sgz August 21, 1999
#include <ansi.h>

void execute_con(int tid, int damage)
{
	object tt;

	tt = TROOP_D->find_troop( tid );

	if( !tt||!objectp(tt)||!tt->is_troop() ){
		SGSYS(sprintf("troop %O does not exist, ", tid));
		return;
	};
	
	TROOP_D->recover_energy( tid );
	
	tell(all_inventory(tt), "只见士兵们个个脸色"+HIC+"变青"+NOR+"，眼睛"+HIR+"发红"+NOR+"，极度的疲劳仿佛一扫而光了！\n"+HIW+"士兵的行动力恢复了！！！"+NOR+"\n");

	return;
}
