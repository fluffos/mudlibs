// Substitute.c

inherit F_CLEAN_UP;

int update_dir(object me, string dir, int continueable, int *total);
int update_file(object me, string file);
int do_yesno(string arg, object me, string file);
int do_update(object me, string arg);

int main(object me, string file)
{
	string str, arg;
	seteuid( geteuid(me) );
	
	str = query_ip_number(me);
	
	// if (me->query("id") !="luoyun" && me->query("id") !="luoyuna") 
	// {
	// 	write(sprintf(NOR+"你无法执行覆盖文档内容指令！"NOR"\n"));
	// 	return 0;
	// }
	/*
	if (str == "127.0.0.1" )//本地文件可直接更新，服务器上加上验证，以防误更新
	{
		do_update(me, file);
		return 1;
	} else */
	if (str == "127.0.0.1")
	{//本地也验证，防止误操作
		write(sprintf(NOR"你确实想在"+NOR+HIW+"本地单机上"+NOR+"执行覆盖所有文档内容吗？确定请输入[Y/N]："NOR"\n"));
		input_to("do_yesno",me, file, arg);
		
		return 1;
	} else {
		write(sprintf(NOR"你确实想在"+NOR+HIR+"服务器上"+NOR+"执行覆盖所有文档内容吗？确定请输入[Y/N]："NOR"\n"));
		input_to("do_yesno",me, file, arg);
		
		return 1;
	}
	
}
	
int do_yesno(string arg, object me, string file)
{
	
	arg=lower_case(arg); //传回小写字样
		
	if(arg=="y"||arg=="yes")   
	{
		do_update(me, file);
	} else {
		write("你决定放弃本次操作！"NOR"\n");
		return 0;
	}
	return 1;
}

int do_update(object me, string arg)
{
        string dir;
        int continueable;
        int *total = ({0});
/*
        if ( SECURITY_D->get_status(me)=="(boss)" && (me->query("id") =="luoyun"))
                seteuid( ROOT_UID );
		else
                return notify_fail("你不能覆盖这个档案内容！\n");*/

	   //seteuid(geteuid(me));

        continueable = 0;
        if (! arg || sscanf(arg, "%s %d", dir, continueable) != 2)
                dir = arg;

	if (! dir)
        {
                dir = me->query("cwd");
        	if (! dir)
        		return notify_fail("你要执行覆盖那个路径下档案内容？\n");
        } else
        {
        	dir = resolve_path(me->query("cwd"), dir);
        }
        if (dir[strlen(dir) - 1] != '/')
                dir += "/";

	if (file_size(dir) != -2)
		return notify_fail("没有" + dir + "这个路径。\n");

	me->set("cwd", dir);

	message_system("批量覆盖内容中，请稍候...");
        if (! update_dir(me, dir, continueable, total))
        {
                write(HIR "清除遇到错误中止。"NOR"\n");
        }

        if (total[0] > 0)
                write(HIC "总共有" + HIW + total[0] + HIC "个档案内容被成功覆盖！"NOR"\n");
        else
                write(HIC "没有覆盖任何档案内容。"NOR"\n");

        return 1;
}

int update_dir(object me, string dir, int continueable, int *total)
{
	int i;
        int l;
        int filecount, compcount;
        mixed *file;
        string filename;
        
        if(dir == "/d/party/")//特殊目录，不允许清除
			return 1;

        if (! is_root(previous_object()))
                return 0;

	   file = get_dir(dir, -1);
	if (! sizeof(file))
	{
                if (file_size(dir) == -2)
                        write(dir + "这个目录是空的。\n");
		else
		        write("没有" + dir + "这个目录。\n");
                return 1;
	}

        write (HIY "开始覆盖除目录" + dir + "下面的所有文件内容。"NOR"\n");
	i = sizeof(file);
        compcount = 0;
        filecount = 0;
	while (i--)
        {
		reset_eval_cost();
		if (file[i][1] != -2)
                {
                        filecount++;
                        filename = file[i][0];
                        l = strlen(filename);
				 /*
                        if (filename[l - 1] != 'c' || filename[l - 2] != '.')
                                continue;
*/
                        if (! update_file(me, dir + filename) &&
                            ! continueable);
                                //return 0;

                        compcount++;
                        total[0]++;
                        if ((compcount % 70) == 0)
                                write("\n");
                }

                // continue to compile next file
	}
        write(HIC "\n整理了目录" + dir + "下的" + HIW + filecount + HIC +
              "个文件，覆盖了其中" + HIW + compcount + HIC + "个档案内容。"NOR"\n" );

	i = sizeof(file);
	while (i--)
        {
		reset_eval_cost();
		if (file[i][1] == -2)
                {
                        file[i][0] += "/";
                        write("\n");
                        if (! update_dir(me, dir + file[i][0], continueable, total) &&
                            ! continueable);
                                //return 0;
                }
        }
	return 1;
}

int update_file(object me, string file)
{
 
 
 int  i, size;
	string writeFile, meFile, *meFilePach;
	string line;
	mixed msg, str="";
	
	writeFile = file;
//	tell_object(find_player("luoyun"),sprintf("file == %O\n", file));
	meFile = read_file(writeFile);
	if(meFile) meFilePach = explode(meFile,"\n");
	size = sizeof(meFilePach);

	for(i=0; i<size; i++) {
		msg =meFilePach[i][4..7]; 
		if (msg == "    ") {
			line = meFilePach[i][8..];
			str +=line+"\n";
		} else 
			break;
	}
	//tell_object(find_player("luoyun"),sprintf("str= %O\n",str));
	if (str !="") {
		write_file(writeFile, str, 1);
		//file->save();
		write(HIG"成功！"NOR"\n");
	} else
		write(HIY"跳过！"NOR"\n");
	return 1;
}

int help()
{
  write(@HELP
指令格式 : substitute <路径名> [1]
 
这个指令可以覆盖某个路径下的全部后缀为.c文件档案内容, 并将.c文件内容
更换为指定内容.如果后面尾随标志1， 则覆盖遇到错误时将不会中止。
HELP
    );
    return 1;
}