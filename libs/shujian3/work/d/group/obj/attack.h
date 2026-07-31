// attack.h
// by augx@sj  4/1/2002

int do_attack(string arg)
{
	object me = this_player() , env = environment(this_object()), ob;
	int t;

	if( !arg || !id(arg) || env==me ) return 0;

	message_vision("$N开始击打"+name()+"...\n",me);
	t = 15 + random(30);
	me->start_busy(t/2+1);
	env->set("attack",time()+t);
	env->set("attack_type","door");

	foreach ( ob in all_inventory(env) ) {
		if( !ob || !living(ob) || !userp(ob) ) continue;
		env->set_attack(ob);
	}

	call_out("attack_finish",t,env,me);
	return 1;
}

void attack_finish(object env,object me)
{
	if( !env ) return;
	env->set("attack",0);
	env->set("attack_type","");

	if( !me ) return;
	tell_room(env,me->name()+"攻击结束了。\n",({me}));
	tell_object(me,"你攻击结束了。\n");

	if( environment(me) != env ) return;
	GROUP_D->attack_room(this_object(),me);
}
                                                        