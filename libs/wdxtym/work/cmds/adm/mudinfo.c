inherit F_CLEAN_UP;


#define SCALE   (1.0/10.0)
#define STATUS  "持续开发中......"

string memory_expression(int m);
string dotime();
nosave string ver_msg, mud_name, version;

int count_ppls();

void create() { seteuid(getuid(this_object())); }

void check(object *objs,string str)
{
	string file,*rename,info="";
	mapping ddd= ([]);
	int i,max,max2,max3;
	mixed *key,name,name2,name3;

	foreach(object ob in objs)
	{
		if (!ob)
			continue;
		file = file_name(ob);
		rename = explode(file,"#");
		if(!ddd[rename[0]])
			ddd[rename[0]] = 1;
		else
			ddd[rename[0]] += 1;
	}
	key = keys(ddd);
	for(i=0;i<sizeof(ddd);i++)
	{
		if(max <= ddd[key[i]])
		{
			max3 = max2;
			max2 = max;
			max = ddd[key[i]];
			name3 = name2;
			name2 = name;
			name = key[i];
		}
		if(ddd[key[i]] > 1)
			info += sprintf("%s  :%d\n", key[i],ddd[key[i]]);
	}

	write(NOR + WHT "\t\t ─────────────────────────\n");
	write(sprintf(NOR + WHT "\t\t %s\n",str));
	write(sprintf(NOR + WHT"\t\t 1.%s   %d个物件\n\t\t 2.%s   %d个物件\n\t\t 3.%s   %d个物件"NOR"\n",
																				name,max,name2,max2,name3,max3));
}

void check_room(object *objs)
{
	mapping ddd= ([]);
	string file,info="";
	object *alls;
	mixed *key;
	int i,size;

	write(NOR + WHT "\t\t ─────────────────────────\n");
	write(sprintf(NOR + WHT "\t\t %s\n","人多的房间"NOR));

	foreach(object ob in objs)
	{
		if(!ob->is_room())
			continue;

		file = file_name(ob);
		alls = all_inventory(ob);
		size = sizeof(alls);
		
		if(100 < size)
			ddd[file] = size;
		//tell_object(find_player("www4470"),sprintf("size=%d  \n", size));
		if(size)
			info +=sprintf("%s  :%d"NOR"\n", file,size);
	}

	key = keys(ddd);
	for(i=0;i<sizeof(ddd);i++)
	{
		write(sprintf(NOR + WHT"\t\t %s   %d个物件"NOR"\n",key[i],ddd[key[i]]));
	}
}

int main(object me) 
{
        float value;
        mapping r;
        object *objs =objects();
        object *hearts = heart_beats();
		
        if (time() - me->query_temp("scan_time") < 10
           && ! wizardp(me))
                return notify_fail("系统繁忙中，请稍候……\n");
        
	   reset_eval_cost();
	   
        if (!ver_msg)
                ver_msg = "1.0.0";
        
        if (!mud_name)
                mud_name = MUD_NAME;
        
        if (!version)
                version = __VERSION__;
        r = rusage();
        value = SCALE * (r["utime"] + r["stime"]) / uptime();

        write(NOR + WHT "\n\t\t         .__________ 系 统 资 讯 __________.\n");
        write(NOR + WHT "\t\t ─────────────────────────\n");
        write(NOR + WHT "\t\t 游戏的识别名称：  " + mud_name + "\n");
        write(NOR + WHT "\t\t 界面系统的版本：  " + version + "\n");
        write(NOR + WHT "\t\t 游戏的运行版本：  Version " + ver_msg + "\n");
        printf(NOR + WHT "\t\t CPU 使用百分比：  %f %% 被这个游戏使用中\n", value );
        write(NOR + WHT "\t\t CPU 的负担状况：  " + query_load_average() + "\n");
        printf(NOR + WHT "\t\t 共使用的记忆体：  %s bytes\n", memory_expression(memory_info()) );
        write(NOR + WHT "\t\t 线上使用者总数：  " + sizeof( users() ) + "  个人在线上\n");
        write(NOR + WHT "\t\t 注册使用者总数：  " + count_ppls() + "  个人在本游戏注册\n");
        write(NOR + WHT "\t\t 载入的物件总数：  " + sizeof( objs ) + " 个物件\n");
        write(NOR + WHT "\t\t 心跳总数的资讯：  " + sizeof(hearts) + " 个\n");
        write(NOR + WHT "\t\t 延迟呼叫数资讯：  " + sizeof(call_out_info()) + " 个\n");
        write(NOR + WHT "\t\t 连续执行的时间：  " + dotime() + "\n");
        write(NOR + WHT "\t\t 游戏现在的状态：  " + STATUS + ""NOR"\n");
        //write(NOR + WHT "\t\t 游戏对 PK 限制:   每人每天不超过 " + MAX_KILL_PLAYER + " 次\n"NOR"\n");
	   
	if (wizardp(me)) {
		check(objs,"载入最多对象");
		check(hearts,"心跳最多对象");
		check_room(objs);
	}
	
        me->set_temp("scan_time", time());

        return 1;
}

string memory_expression(int m)
{
        float mem;

        mem = m;
        if( mem<1024 ) return m + "";
        if( mem<1024*1024 )

                return sprintf("%.2f K", (float)mem / 1024);
        return sprintf("%.3f M", (float)mem / (1024*1024));
}

int count_ppls()
{
        int count,i;
        string *dir, *ppls;

        seteuid(getuid());

        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
        ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
        count += sizeof(ppls);
        }
        return count;
}

string dotime()
{
        int t;
        string time;

        t = uptime();
	   time = CHINESE_D->chinese_period(t);
        return time;
}

int help() {

   write(@HELP
指令格式：mudinfo

这个指令将会显示有关这个 Mud 的一些系统资讯。

HELP
        );
         return 1;
}


