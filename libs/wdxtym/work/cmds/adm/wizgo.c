// goto.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i;
	object obj;
	object env;
	string *dirs,msg,name;
	
	if (! SECURITY_D->valid_grant(me, "(immortal)"))
		return 0;

	if (! arg)
	{
		msg = ZJOBLONG"请选择目标区域：\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		dirs = sort_array(MAP_D->query_all_map_zone(),(: strcmp :));
		for(i=0;i<sizeof(dirs);i++)
		{
			msg += MAP_D->query_map_short(dirs[i])+":wizgo /d/"+dirs[i];
			if(i<(sizeof(dirs)-1)) msg += ZJSEP;
		}
		write(msg+"\n");
		return 1;
	}

	if(file_size(arg)==-2)
	{
		msg = ZJOBLONG"请选择目标场景：\n"ZJOBACTS2+ZJMENUF(3,3,10,33);
		dirs = sort_array(list_dirs(arg+"/"),(: strcmp :));
		for(i=0;i<sizeof(dirs);i++)
		{
			if(file_size(arg+"/"+dirs[i])<0||dirs[i][strlen(dirs[i])-2..strlen(dirs[i])-1]!=".c") continue;
			name = dirs[i][0..<3];
			msg += (arg+"/"+name)->short()+ZJBR+name+":wizgo "+arg+"/"+dirs[i];
			if(i<(sizeof(dirs)-1)) msg += ZJSEP;
		}
		write(msg+"\n");
		return 1;
	}

	obj = find_player(arg);
	if (! obj) obj = find_living(arg);
	if (! obj || ! me->visible(obj))
	{
		arg = resolve_path(me->query("cwd"), arg);
		if (! sscanf(arg, "%*s.c") ) arg += ".c";
		if (! (obj = find_object(arg)))
		{
			if (file_size(arg)>=0)
				obj = load_object(arg);

			if (! obj)
				return notify_fail("没有这个玩家、生物、或地方。\n");
		}
	}

	if (environment(obj))
		obj = environment(obj);
	else
	{
		if (obj->is_character())
			obj = 0;
	}

	if (! obj) return notify_fail("这个物件没有环境可以 wizgo。\n");

	if (wiz_level(obj) > wiz_level(me))
		return notify_fail("你找死啊。\n");

	if ((env = environment(me)) == obj)
		return notify_fail("你在原地乱蹦什么？\n");

	if (obj == me)
		return notify_fail("好厉害！你想钻到自己身体里面？\n");

	if (obj->query("no_goto"))
		return notify_fail("你无法到达那个地方。\n");

	if (me->query("gender") == "女性" )
		tell_object(me, HIG "你化作清风而去。"NOR"\n");
	else
		tell_object(me, HIY "你化作长虹而去。"NOR"\n");
		
	if (env && ! me->query("env/invisible"))
	{
		if (! stringp(msg = me->query("env/msg_out")))
			msg = "只见一阵烟雾过後，$N的身影已经不见了。";

		msg = replace_string(msg, "$N", me->name() + HIM);
		message("vision", HIM + msg + ""NOR"\n", env, ({ me, env }));
	}

	if (! me->query("env/invisible"))
	{
		if (! stringp(msg = me->query("env/msg_in")))
			msg = "$N的身影突然出现在一阵烟雾之中。";
		msg = replace_string(msg, "$N", me->name());
		if (! obj->is_character())
			message("vision", HIM + msg + ""NOR"\n", obj, ({ me, obj }));
	}

	me->set_magic_move();
	if (! me->move(obj))
	{
		msg = HIM "你的遁术失败了。"NOR"\n";
		tell_object(me, msg);
		message("vision", HIM "突然" + me->name() + "一个跟头"
				  "摔倒在地上。"NOR"\n", obj, ({ me }));
		return 1;
	}
	else
		msg = HIM "你到了地方，落下遁光，收住身形。"NOR"\n";

	if (environment(me) != obj)
		return 1;

	tell_object(me, msg);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : wizgo [-i] <目标>
 
这个指令会将你传送到指定的目标. 目标可以是一个living 或房间
的档名. 如果目标是living , 你会被移到跟那个人同样的环境.
如果有加上 -i 参数且目标是 living, 则你会被移到该 living 的
的 inventory 中.
 
HELP );
	return 1;
}
