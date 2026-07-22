inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object who, string arg)
{
	mapping prop;
	string *datas;
	object me;
	object where = environment(who);
	int i;

	if( !arg || !where || !(me = present(arg,where)) || !me->query("ride/msg") )
        	return notify_fail ("你想从什么上下来？\n");
	if( me!=who->query_temp("ridee") )
        	return notify_fail ("你并没有"+me->query("ride/msg")+"在"+me->name()+"上。\n");
      	message_vision ("$N挺身从$n上跃下来。\n",who,me);
	me->set_temp("no_return",0);
	me->set_temp("rider",0);
	who->set_temp("ridee",0);          
	me->move(where);
	if( !me->is_pet() )
	{
	        who->add_temp("ride/dodge",-me->query("ride/dodge"));
        	who->add_temp("apply/dodge",-me->query("ride/dodge"));
        	return 1;
	}	
	prop = me->query("ride");
	if( prop && mapp(prop) )
	{
		datas = keys(prop);
		if( datas && arrayp(datas) )
		{
        		for(i=0;i<sizeof(datas);i++)
        		{
        			if( datas[i]=="msg" )
        				continue;
        			who->add_temp("ride/"+datas[i],-prop[datas[i]]);
        			who->add_temp("apply/"+datas[i],-prop[datas[i]]);
                        }       
                }
        }
	return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : dismount <坐骑名称>

这个指令可以让你从坐骑上下来。

HELP
);
  return 1;
}

