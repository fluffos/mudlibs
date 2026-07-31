// update.c
#include <runtime_config.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

private int update_player(object me);

int main(object me, string file)
{
	int i;
	object obj,env, *inv;
	string str,err,dir;
	string *tmp,*files;
	string bin_file;
	

	if (! SECURITY_D->valid_grant(me, "(wizard)"))
		return 0;
	//if (me->query("id") != "z110614_1") return 0;
	seteuid(geteuid(me));
	env = environment(me);

	tmp = explode(base_name(env),"/");
	tmp -= ({tmp[sizeof(tmp)-1]});
	dir = "/"+implode(tmp,"/")+"/";

	if (! file )
	{
		str = ZJOBLONG"请选择你要重新编译的物件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		str += "本区物件:updatee objh"ZJSEP"重要物件:updatee objs"ZJSEP"clone/0:updatee sword"ZJSEP"clone/zi:updatee zi"ZJSEP
		"clone/good:updatee unarmed"ZJSEP"本区NPC:updatee npch"ZJSEP"公共NPC:updatee npcs"ZJSEP"clone/aaa:updatee aaa"ZJSEP"clone/vip:updatee vip"ZJSEP"clone/gift:updatee gift"ZJSEP"clone/vip2:updatee vip2"ZJSEP"clone/tianji1:updatee tianji1"ZJSEP"clone/shizhe:updatee shizhe";
		write(str+"\n");
		return 1;
	}
	else if (file=="objh")
	{
		str = ZJOBLONG"请选择你要重新编译的物品：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs(dir+"obj/");
		if(!sizeof(files))
			return notify_fail("本区没有可用标准物件。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = dir+"obj/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	else if (file=="objs")
	{
		str = ZJOBLONG"请选择你要重新编译的物品：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/baowu/");
		if(!sizeof(files))
			return notify_fail("该文件暂时没有物品。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/baowu/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}

	else if (file=="npch")
	{
		str = ZJOBLONG"请选择你要重新编译的NPC：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs(dir+"npc/");
		if(!sizeof(files))
			return notify_fail("本区没有可用标准NPC。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = dir+"npc/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	
	else if (file=="sword")
	{
		str = ZJOBLONG"请选择你要重新编译的clone/0里的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/0/");
		if(!sizeof(files))
			return notify_fail("暂时没有clone/0里面的文件。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/0/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	
	
	else if (file=="zi")
	{
		str = ZJOBLONG"请选择你要重新编译的物品：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/zi/");
		if(!sizeof(files))
			return notify_fail("暂时没有clone/zi里面的文件。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/zi/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
	return 1;
	}
	
	else if (file=="unarmed")
	{
		str = ZJOBLONG"请选择你要重新编译good里的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/good/");
		if(!sizeof(files))
			return notify_fail("暂时没有good文件物品。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/good/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}

	else if (file=="aaa")
	{
		str = ZJOBLONG"请选择你要重新编译的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/aaa/");
		if(!sizeof(files))
			return notify_fail("暂时没有aaa文件物品。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/aaa/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	
	else if (file=="shizhe")
	{
		str = ZJOBLONG"请选择你要重新编译的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/shizhe/");
		if(!sizeof(files))
			return notify_fail("暂时没有shizhe文件物品。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/shizhe/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	
	else if (file=="vip2")
	{
		str = ZJOBLONG"请选择你要重新编译的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/vip2/");
		if(!sizeof(files))
			return notify_fail("暂时没有vip2文件物品。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/vip2/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	
	else if (file=="tianji1")
	{
		str = ZJOBLONG"请选择你要重新编译的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/tianji1/");
		if(!sizeof(files))
			return notify_fail("暂时没有vip2文件物品。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/tianji1/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	else if (file=="vip")
	{
		str = ZJOBLONG"请选择你要重新编译的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/vip/");
		if(!sizeof(files))
			return notify_fail("暂时没有vip文件物品。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/vip/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	else if (file=="gift")
	{
		str = ZJOBLONG"请选择你要重新编译的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/gift/");
		if(!sizeof(files))
			return notify_fail("暂时没有gift文件物品。\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/gift/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":update "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	if (! file) file = me->query("cwf");


	if ((obj = present(file, environment(me))) && playerp(obj) ||
	    (obj = find_player(file)) && playerp(obj))
		return update_player(obj);

	if (file == "me")
		return update_player(me);
	else
	{
		file = resolve_path(me->query("cwd"), file);
		if (! sscanf(file, "%*s.c")) file += ".c"; 
	}

	if (file_size(file) == -1)
		return notify_fail("没有这个档案。\n");

	me->set("cwf", file);

	if (obj = find_object(file))
	{
		if (obj == environment(me))
		{
			if (file_name(obj) == VOID_OB)
				return notify_fail("你不能在 VOID_OB 里重新编译 VOID_OB。\n");
			inv = all_inventory(obj);
			i = sizeof(inv);
			while (i--)
				if (playerp(inv[i]) || inv[i]->is_chatter() ||
				    inv[i]->query_temp("owner"))
					// 玩家、聊天魂魄、有主的物品或人物
					inv[i]->move(VOID_OB, 1);
				else    inv[i] = 0;
		}

		{
			// 如果是版本发布的服务器，则删除
			// VERSION_D 的 bin 代码，因为在没有
			// VERSION_D 的时候 driver 是不予编译的。
			bin_file = "/binaries" + base_name(obj) + ".b";
			rm(bin_file);
		}
		seteuid(getuid());
		destruct(obj);
	}

	if (obj) return notify_fail("无法清除旧程式码。\n");

	str=("重新编译 " + file + "：");
	err = catch(call_other(file, "???"));
	if (err)
		str += (sprintf( "发生错误：\n%s\n", err));
	else
	{
		str += ("成功！\n");
		if ((i = sizeof(inv)) && (obj = find_object(file)))
			while (i--)
				if (inv[i]) inv[i]->move(obj, 1);
	}
	write(str);
	log_file("update", sprintf("%s："+me->query("id")+" "+str,ctime(time()) ));
	return 1;
}

private int update_player(object me)
{
	object env, link_ob, obj;
	object *ob, *dob;
	mapping equip;
	int i;

	if (me->is_chatter())
		return notify_fail("你不能更新聊天ID。\n");

	if (wiz_level(me) > wiz_level(this_player()))
		return notify_fail("你没有权限更新这个人物。\n");

	seteuid(getuid());
	env = environment(me);

	// First, create the new body.
	link_ob = me->query_temp("link_ob");
	if (! link_ob)
	{
		link_ob = new(LOGIN_OB);
		link_ob->set("id", me->query("id"));
		if (! link_ob->restore())
		{
			write("找不到该玩家的存盘数据。\n");
			return 1;
		}
		if (interactive(me))
			link_ob->set_temp("ip_number", query_ip_number(me));
	}

	if (link_ob->query("id") != getuid(me))
	{
		write (sprintf("连接对象的ID(%s)和用户的ID(%s)不相同，不能"
		       "更新该玩家。\n", link_ob->query("id"), getuid(me)));
		return 1;
	}

	obj = LOGIN_D->make_body(link_ob);
	if (! obj) return 0;

	// Save the data and exec the player to his/her link object.
	ob = all_inventory(me);
	equip = ([ ]);
	for (i = 0; i < sizeof(ob); i++)
		equip += ([ ob[i] : ob[i]->query("equipped") ]);
	ob->move(VOID_OB);
	me->save();
	if (interactive(me))
		exec(link_ob, me);
	destruct(me);

	// Restore new body and exec to it via enter_world in LOGIN_D
	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);
	dob = all_inventory(obj);
	for (i = 0; i < sizeof(dob); i++)
		destruct(dob[i]);

	write("身体更新完毕。\n\n");
	obj->move(env);
	ob->move(obj);

	if (! interactive(obj))
		destruct(link_ob);

	for (i = 0; i < sizeof(ob); i++)
	{
		if (equip[ob[i]] == "worn")
			ob[i]->wear();
		if (equip[ob[i]] == "wielded")
			ob[i]->wield();
	}
	obj->write_prompt();

	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : update <档名|here|me|玩家名>
 
这个指令可以更新档案, 并将新档的内容载入记忆体内. 若目标为
'here' 则更新所在环境. 若目标为 'me' 则更新自己的人物. 若目
标为玩家则可更新玩家物件.
 
HELP
    );
    return 1;
}
