// edmission.c
//  created by fuyo@xajh2 98-11-17 11:33  整理并获取O数据来组织任务数据库
//             fuyo@xajh2 98-12-8 16:28 98-12-15 17:54
//	       fuyo@xajh2 98-12-16 14:26	

#include <combat.h>

inherit F_CLEAN_UP;

#define MISSION_D "/adm/daemons/missiond"
#define O_DATA "mission/"

int get_mission_data_from_file(string dir);
int save_mission_data_from_file(string file);

int main(object me, string arg)
{
	int i,num;
	string arg1,arg2;
	string file,dir;
	mapping qmm;
	string party,temp;
	
	seteuid(getuid(me));

	if ( this_player()->query("id") !="fuyo" )
	{
		write("对不起，这个命令暂时不可随意使用！请向 fuyo 垂询!\n");
		return 1;
	}

	if ( !arg )
		return notify_fail("指令格式: edmission [-c <path>|-a <file_name>] .\n");
	i = sscanf(arg,"%s %s",arg1,arg2);


	if (arg1 == "-c")  // 用来从某个目录下收集原始数据到 /log/obj.data和 /log/char.data
	{
		if ( arg2=="." )			
		        dir=me->query("cwd");
		else
			dir = resolve_path(me->query("cwd"), arg2)+"/";	

		return get_mission_data_from_file(dir);
	}
	
	if ( arg1 == "-a" )   //从整理后的数据文件里读数据存入任务数据库
	{
		if ( i==2)
		{
			file = resolve_path(me->query("cwd"), arg2);
			if( file_size(file)==-1 )
				return notify_fail("没有"+file+"这个档案。\n");
			return save_mission_data_from_file(file);
		}
	}
		
	if ( arg1 == "-qo" )
	{
		write("任务系统-寻物篇查询：\n");
		if ( arg2 == "all" )
		{
			qmm = MISSION_D->query_obj_all();
			if ( !mapp(qmm) )
				return notify_fail("没有数据! \n");						
			write(sprintf("%O",qmm));
			write("\nOK!\n");
			return 1;
		}
		else if ( arg2 == "level" )
		{
			qmm = MISSION_D->query_obj_all_by_level();
			if ( !mapp(qmm) )
				return notify_fail("没有数据! \n");						
			write(sprintf("%O",qmm));
			num=0;
			for ( i=0;i<sizeof(qmm);i++)
				num+=values(qmm)[i];
			write(sprintf("\n共有%d条任务记录!\n",num));
			write("OK!\n");
			return 1;
		}
		else 
		{
			if (sscanf(arg2,"/d/%s/%s",party,temp)==2)
			{
				qmm = MISSION_D->query_obj_mission(party,arg2);
				if ( !mapp(qmm) )
					return notify_fail("没有数据! \n");						
				write(sprintf("%O",qmm));
				write("OK!\n");
				return 1;
			}
		}

		return notify_fail("没有数据! \n");						
	}
	
	if ( arg1 == "-qc" )
	{
		write("任务系统-杀人篇查询：\n");
		if ( arg2 == "all" )
		{
			qmm = MISSION_D->query_char_all();
			if ( !mapp(qmm) )
				return notify_fail("没有数据! \n");						
			write(sprintf("%O",qmm));
			write("\nOK!\n");
			return 1;
		}
		else if ( arg2 == "level" )
		{
			qmm = MISSION_D->query_char_all_by_level();
			if ( !mapp(qmm) )
				return notify_fail("没有数据! \n");						
			write(sprintf("%O",qmm));
			num=0;
			for ( i=0;i<sizeof(qmm);i++)
				num+=values(qmm)[i];
			write(sprintf("\n共有%d条任务记录!\n",num));
			write("OK!\n");
			return 1;
		}
		else 
		{
			if (sscanf(arg2,"/d/%s/%s",party,temp)==2)
			{
				qmm = MISSION_D->query_char_mission(party,arg2);
				if ( !mapp(qmm) )
					return notify_fail("没有数据! \n");						
				write(sprintf("%O",qmm));
				write("OK!\n");
				return 1;
			}
		}

		return notify_fail("没有数据! \n");						
	}
	if ( arg1 == "-del" )
	{
		write("删除任务记录:\n");
		if (this_player()->query("id")!="fuyo")
		{	
			write("对不起，这个指令请慎用！\n");
			return 1;
		}
						
		if (sscanf(arg2,"/d/%s/%s",party,temp)==2)
		{
			qmm = MISSION_D->query_obj_mission(party,arg2);
			if (mapp(qmm))
			{
				write(sprintf("%O",qmm));
 				if ( MISSION_D->delete_obj_mission(party,arg2))
					write("DELETE OK!\n");
				else
					write("DELETE FAILS!\n");
				return 1;
			}

			qmm = MISSION_D->query_char_mission(party,arg2);
			if ( !mapp(qmm) )
					return notify_fail("没有数据! \n");						
			write(sprintf("%O",qmm));
			if ( MISSION_D->delete_char_mission(party,arg2))
				write("DELETE OK!\n");
			else
				write("DELETE FAILS!\n");
			return 1;
		}	
		else 
		{
			if ( MISSION_D->delete_party_mission(arg2))
				write("Party"+arg2+"data DELETE OK!\n");
			else
				write("Party"+arg2+"data DELETE Fails!\n");
			return 1;
		}			

		return notify_fail("没有数据! \n");
	}											

			
			
	return notify_fail("指令格式: edmission [-c <path>|-a <file_name>] \n");						

}

int save_mission_data_from_file(string file)
{
	string buff;
	int line=1;
	int count=0;
	string id,cname,filename,party;
	int value,no_drop,no_get;
	int exp,ap,fp,shen;
	int level;
	mapping odata;
	string temp;
	
	buff=read_file(file,1,1);

	if(sscanf(buff,"mission obj data file  --%*s"))
	{
		line = 1;
		while((buff=read_file(file,++line,1))!="End data"&&buff)
		{
			if(sscanf(buff,"**%*s")) continue;
			if(sscanf(buff,"%s-%s-%d-%d-%d-%s-(%d)\n",
				id,cname,value,no_drop,no_get,filename,level)!=7)
				return notify_fail("data file line "+line+" format error!\n");
			odata=([]);
			odata["id"]=id;
			odata["cname"]=cname;
			odata["value"]=value;
			odata["no_drop"]=no_drop;
			odata["no_get"]=no_get;
			odata["filename"]=filename;
			odata["bonus"]=100;
			if ( sscanf(filename,"/d/%s/%s",party,temp) !=2 )
				return notify_fail("data file line "+line+" format error!\n");

			write(sprintf("%d  ",++count));
			MISSION_D->add_obj_data_mission(party,filename,level,odata,1);

		} 
		return 1;
	}

	if(sscanf(buff,"mission char data file  --%*s"))
	{
		line = 1;
		while((buff=read_file(file,++line,1))!="End data"&&buff)
		{
			if(sscanf(buff,"%s**%s**%d**%d**%d**%d**%s-(%d)\n",
				id,cname,exp,ap,fp,shen,filename,level)!=8)
				return notify_fail("data file line "+line+" format error!\n");
			odata=([]);
			odata["id"]=id;
			odata["cname"]=cname;
			odata["exp"]=exp;
			odata["ap"]=ap;
			odata["fp"]=fp;
			odata["shen"]=shen;
			odata["filename"]=filename;
			odata["bonus"]=100;
			if ( sscanf(filename,"/d/%s/%s",party,temp) !=2 )
				return notify_fail("data file line "+line+" format error!\n");

			write(sprintf("%d  ",++count));
			MISSION_D->add_char_data_mission(party,filename,level,odata,1);

		} 
		return 1;
	}
	
	return notify_fail("data file format error.\n");
}

int get_mission_data_from_file(string dir)
{

	string tdest,err;
	string* files;
	object obj;
	object weapon;
	string skill_type;
	int attack_points, dodge_points, parry_points;
	int ap,fp;
	mapping buf;
	string party,temp;
	string char_file,obj_file;

	if ( sscanf(dir,"/d/%s/%s",party,temp) !=2 )
		return notify_fail("在这个目录下不合适做这样的操作!\n");
        files=get_dir(dir+"*.c");
       	if( !sizeof(files))
        {
       	        if (file_size(dir) == -2) {
               	        write ("这个目录是空的。\n");
                       	return 1;
                }
       	        else
               	{
                       	write ("没有这个目录。\n");
                        return 1;
     	        }
        }
	
	obj_file  = O_DATA+party+".obj.data";
	char_file = O_DATA+party+".char.data";
	
	log_file(obj_file,sprintf("mission obj data file  -- %s\n",
					ctime(time())));
	
	log_file(char_file,sprintf("mission char data file  -- %s\n",
					ctime(time())));

	for ( int i=0 ; i < sizeof(files) ; i++ )
	{
		tdest=dir+files[i];
		if( strsrch( tdest,".c")==-1)
		continue;
		write("重新编译 " + tdest + "：");
		err = catch( call_other(tdest, "???") );
		if (err)
		{
			printf( "发生错误：\n%s\n", err );
			continue;
		}
		write("成功！\n");
		if ( !objectp(obj=find_object(tdest)) ) continue;
		if ( stringp(obj->query("id")))
		{
			if ( obj->is_character() )
			{
				if( objectp(weapon = obj->query_temp("weapon")) )
				skill_type = weapon->query("skill_type");
			else
				skill_type = "unarmed";
				attack_points = COMBAT_D->skill_power(obj, skill_type, SKILL_USAGE_ATTACK);
			parry_points = COMBAT_D->skill_power(obj, skill_type, SKILL_USAGE_DEFENSE);
			dodge_points = COMBAT_D->skill_power(obj, "dodge", SKILL_USAGE_DEFENSE);
			ap = attack_points/100 + 1;
			fp = (dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1;
			log_file(char_file,sprintf("%s**%s**%d**%d**%d**%d**%s-(   )\n",
				obj->query("id"),
				obj->query("name"),
				obj->query("combat_exp"),
				ap,
				fp,
				obj->query("shen"),
				tdest));
			buf=([]);
			buf["id"]=obj->query("id"),
			buf["name"]=obj->query("name"),
			buf["combat_exp"]=obj->query("combat_exp"),
			buf["attach_point"]=ap;
			buf["defend_point"]=fp;
			buf["shen"]=obj->query("shen");
			}
			else 	
				log_file(obj_file,sprintf("%s-%s-%d-%d-%d-%s-(   )\n",
					obj->query("id"),
					obj->query("name"),
					obj->query("value"),
					obj->query("no_drop")?1:0,
					obj->query("no_get")?1:0,
					tdest));
		}
	}
	log_file(char_file,"End data");
	
	log_file(obj_file,"End data");

	return 1;
}				
	
		
int help(object me)
{
	write(@HELP
指令格式：-c [ 目录名 | . ]   	用来从某个目录下收集原始数据到 /log/obj.data和 /log/char.data
	  -a [ 数据文件名 ]   	从整理后的数据文件里读数据存入任务数据库 /data/missiond.o
	  -qo [ all | level | obj_filename ]	寻物系统查询		  
	  -qc [ all | level | npc_filename ]	杀人系统查询		  	
	  -del[ filename		删除任务记录
HELP
	);
	return 1;
}
		
		
		


