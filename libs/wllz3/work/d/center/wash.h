
int do_wash()
{
	object me;
	int wait;
	me = this_player();
	wait = random( 60 - (int)(me->query("con"))) * 2;
	if ( wait <= 20) wait = 21;
	if( me->query_temp("be_wash") > 10 + random(10)){
		message_vision(HIR"$N一声惊叫：“啊！”，不小心把皮搓破了。\n"NOR,me);
		me->unconcious();
		me->delete_temp("be_wash");
		return 1;
	}
	if( me->query_temp("wash")) {
		if(query("women"))
			message_vision("$N一边搓背，一边唱着：上冲冲下洗洗，左搓搓右揉揉，我家的浴缸，好好坐～\n",me);
		else
			message_vision("$N一边搓背，一边唱着：洗白白，搓白白，我左搓右搓上搓下搓 . . . \n",me);
		me->add_temp("be_wash",1);
		return 1;
	}
	message_vision(HIW"$N噗嗵一声跳进浴池，立刻激起一道水花。\n"NOR,me);
	tell_object(me,"你感到全身无比的舒泰. . . .\n");
	me->set_temp("wash",1);
	call_out("curehimup", wait, me);
	return 1;
}
void curehimup(object me)
{
	int qi,jing;
	qi=(int)me->query("max_qi");
	jing=(int)me->query("max_jing");
	if( me && environment(me) == this_object()){
	tell_object(me,HIW"过了好一阵子，你的精神已经恢复了！\n"NOR);
	me->set("eff_qi",qi);
	me->set("eff_jing",jing);
	me->set("qi",qi);
	me->set("jing",jing);
	me->delete_temp("wash");
	}
	return;
}
