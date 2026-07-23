inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, link_ob;

	if (!arg) return 1;
	if (!(ob = LOGIN_D->find_body(arg))) return 1;
	link_ob = ob->query_temp("link_ob");
	if (link_ob)
		write(sprintf("%s link ob info:\nterminal_type=%O\nwindows_size=%O,%O\ntelnet_suboption=%O\n",
			arg, link_ob->query_temp("terminal_type"),
			link_ob->query_temp("window_size/x"),
			link_ob->query_temp("window_size/y"),
			link_ob->query_temp("telnet_suboption")
		));
	write(sprintf("%s ob info:\nterminal_type=%O\nwindows_size=%O,%O\ntelnet_suboption=%O\n",
		arg, ob->query_temp("terminal_type"),
		ob->query_temp("window_size/x"),
		ob->query_temp("window_size/y"),
		ob->query_temp("telnet_suboption")
	));
	return 1;
}
