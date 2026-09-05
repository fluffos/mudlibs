
int chopping(object me)
{
    object ob;
    if (base_name(environment(me))!=me->query_temp("rynewbiejob/zhulou/pi_place"))
    {
        tell_object(me,"不知道你怎么梦游到这里的，三心二意什么也做不成。\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/zhulou/pi_degree")<5+random(4))
    {
        me->add_temp("rynewbiejob/zhulou/pi_degree",1);
        me->add_busy(random(2));
        message_vision("$N使劲把竹身上的裂纹扩大。\n",me);
        call_out("chopping",1,me);
		return 1;
    }
    me->delete_temp("rynewbiejob/zhulou/start_pi");
    me->delete_temp("rynewbiejob/zhulou/pi_degree");
    message_vision("一棵大竹子轰然倒下，$N满意的摆了个很帅的造型。\n",me);
    ob= new("/d/riyuejiao/obj/bamboo");
    ob->move(this_object());
    return 1;
}

int do_pi()
{
	object me = this_player();
	object kd=present("kan dao",me);
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
    if (!me->query("rynewbiejob/zhulou/start"))
    {
        return 0;
    }
    if (me->query_temp("rynewbiejob/zhulou/start_pi"))
    {
        message_vision("$N给自己鼓劲，加油！加油！加油！\n",me);
        return 1;
    }
	if(present("kan dao", me)&&(kd->query("equipped")))
		{
				message_vision("$N大喝一声，使出吃奶的力气劈向一根竹子。\n", me);
				me->add_busy(random(2));
                me->set_temp("rynewbiejob/zhulou/pi_place",base_name(this_object()));
                me->set_temp("rynewbiejob/zhulou/start_pi",1);
                me->set_temp("rynewbiejob/zhulou/pi_degree",0);
                call_out("chopping",1,me);
				return 1;
		}
	else
		{
			tell_object(me,"以你的功力，看来徒手是砍不断竹子的。\n");
			return 1;
		}
}



