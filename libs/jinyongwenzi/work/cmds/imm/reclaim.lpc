// reclaim.c

int main(object me, string arg)
{
	write("整理结果，共清除 " + reclaim_objects() + " 个变数。\n");
	if (me->id("yuj")) {
		object ob, *obs = objects();
		int mem = sizeof(obs);

		while (mem--) {
			ob = obs[mem];
			if (!environment(ob)
			&& clonep(ob)
			&& !interactive(ob)
			&& !ob->query_temp("body_ob")
			&& !ob->query_temp("link_ob")) {
				reset_eval_cost();
				write(sprintf("%O", ob));
				destruct(ob);
				write(" 已经被清除。\n");
				obs -= ({ 0 });
				mem = sizeof(obs);
			}
		}
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : reclaim

用处 : 将内存中的无用变量清除掉, 以减少内存的消耗。
HELP
	);
	return 1;
}
