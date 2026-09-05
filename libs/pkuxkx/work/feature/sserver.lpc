// sserver.c

//inherit F_CLEAN_UP;

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
	int sz;
	object focus;
	object *enemy;

// 让NPC可以通过定义 choose_offensive_target() 函数来自主确定他的攻击目标  lordstar 20180511
	if (!userp(me) && objectp(focus = me->choose_offensive_target()))
		return focus;
// 增加设置焦点目标的功能，有焦点目标时，只攻击焦点目标。by lordstar 20171108
	focus = me->query_temp("focus_target");
	if ( objectp(focus) && environment(focus)==environment(me) && me->visible(focus) && me->is_fighting(focus) )
		return focus;
	
	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}
