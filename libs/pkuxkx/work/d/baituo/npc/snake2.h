void init()
{
        object ob;
        ::init();
	    add_action("convert","convert");
        if (interactive(ob = this_player()) &&
	    (ob->query("family/family_name") != "白驼山"
            && random(2)
                ))
      {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
int convert(string arg)
{
	object me = this_player();
	object ob;

	if (arg!="snake" && arg!="she") return 0;
	if (me->query("family/family_name") != "白驼山") 
		return notify_fail("你不能化蛇为杖。\n");

	return notify_fail(this_object()->name()+"不适合化为蛇杖。\n");

}
