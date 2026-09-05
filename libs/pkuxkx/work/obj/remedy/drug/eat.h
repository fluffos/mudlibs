void init()
{
	add_action("do_eat", ({"eat","fu"}));
}

int can_eat(object ob,string arg)
{
	if (!arg) return 0;
	if (member_array(arg,ob->parse_command_id_list())==-1) return 0;
	return 1;
}