// /include/pet.h
// by bor @DA, 3/11 2003

int do_mount(string arg)
{
        object me = this_player();

	if( !arg || !id(arg)) return 0;

	if(me->query("id") != this_object()->query("owner")) {
		message_vision("$N偷偷摸摸地走近$n, 被$n一脚踢了下去。\n", me, this_object() );
		return 1;
	}

	message_vision("$N一跃而坐上$n, 四平八稳的骑着。\n", me, this_object() );

	if( me->query("list/pet")) {
		if( me->query("list/pet/damage") ) {
			me->add_temp("apply/damage", me->query("list/pet/damage"));
		}
		if( me->query("list/pet/armor") ) {
			me->add_temp("apply/armor", me->query("list/pet/armor"));
		}
		if( me->query("list/pet/kee") ) {
			// charge 时，扣 apply/kee, 直到 0, 要 feed bean 时，请dismount 在 feed
			me->add_temp("apply/kee", me->query("list/pet/kee"));
		}
		me->set_temp("riding_pet", 1);
	}
	this_object()->move("/d/special/no_reborn_room.lpc");
	return 1;
}

int do_feed(string arg)
{
	object me = this_player(), ob, pet_ob;
	string food, who;

	if(!arg) return notify_fail("指令格式: feed <某物> to <某坐骑>\n");
	if( sscanf(arg, "%s to %s", food, who)!= 2 ) return notify_fail("指令格式: feed <某物> to <某坐骑>\n");
	if( !objectp( ob = present(food, me) ) ) return notify_fail("你身上没有此物品。\n");
	if( !ob->is_bean() ) return notify_fail("你身上没有任何可以替坐骑补充体力的马豆 !!\n");
	if( !objectp( pet_ob = present(who, environment(me)) ) ) return notify_fail("你附近没这头坐骑 !!\n");
	if( pet_ob->query("owner")!=me->query("id") ) return notify_fail("这头坐骑根本不甩你, 东张西望地走来走去。\n");
	ob->direct_move(pet_ob);
	pet_ob->force_me("eat bean");
	return 1;
}
