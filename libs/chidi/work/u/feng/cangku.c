//仓库系统 NPC
//edit by rock
//2008年9月27日

#include <ansi.h>
#include <command.h>
inherit NPC;

#define ITEM_ITEM_D "/adm/obj/equip"

int set_password();
void check_pwd(string key,object me,int rest);
int open_cangku();
int close_cangku();
int do_look();
int do_cun();
int do_qu();
int do_cun_cangku(string arg,object me,int index);
string query_save(object me);

void create()
{
	set_name("仓库管理员", ({ "cangku","ku" }) );
        set("title",HIM"优秀物品保管"NOR);
	set("age", 55);
	set("long", "一位满脸笑荣的老头。\n");
	
	set("str", 32);
	set("dex", 36);
	set("wildness", 2);

	set("inquiry", ([
		"存"        : (: do_cun :),
		"取"        : (: do_qu :),
		"设定密码"  : (: set_password :),
		"打开仓库"  : (: open_cangku :),
		"关闭仓库"  : (: close_cangku :),
		"查看仓库"  : (: do_look :),
	]));

	set("no_kill",1);

	setup();
}

//仓库开关密码
int set_password()
{
	object me;
	int me_key;

	me = this_player();

	me_key = me->query("cangku/password"); 

	if(me_key)
	{
		tell_object(me,"已经有密码,是否重设?(yes|no)\n");
		input_to("check_pwd",me,1);
		return 1;
	}
	else
	{
		tell_object(me,"请输入密码:\n");
		input_to("check_pwd",me,0);
		return 1;
	}
	return 0;
}

void check_pwd(string key,object me,int rest)
{
	int password,flag;

	switch(rest)
	{
		//重设密码
		case 1 :
			key = lower_case(key);
			if(key == "yes")
			{
				tell_object(me,"请输入旧密码:\n");
				input_to("check_pwd",me,2);
			}
			else
			{
				tell_object(me,"已经取消。\n");
				return;
			}
			return;
		case 2 :
			password = to_int(me->query("cangku/password"));
			flag = to_int(key);
			if(password != flag)
			{
				tell_object(me,"密码不对,无法重设新密码。\n");
				return;
			}
			else
			{
				tell_object(me,"输入正确，请输入新密码:\n");
				input_to("check_pwd",me,0);
				return;
			}
			break;
		//打开仓库
		case 3 :
			password = to_int(me->query("cangku/password"));
			flag = to_int(key);
			if(password != flag)
			{
				tell_object(me,"密码错误，仓库打开失败。\n");
				return;
			}
			tell_object(me,"你的仓库已经打开。\n");
			me->set_temp("cangku/lock",1);
			return;
		//关闭仓库
		case 4 :
			me->delete_temp("cangku/lock");
			return;
	}
	//设置密码
	tell_object(me,"密码设置成功。\n");
	me->set("cangku/password",to_int(key));
	me->save();
}

//打开仓库
int open_cangku()
{
	object me= this_player();
	
	if(me->query_temp("cangku/lock"))
	{
		tell_object(me,"仓库正处于打开状态。\n");
		return 1;
	}
	if(me->query("cangku/password"))
	{
		tell_object(me,"请输入仓库密码:");
		input_to("check_pwd",me,3);
		return 1;
	}
	else
	{
		tell_object(me,"您的仓库没有上锁。\n");
		return 1;
	}
	return 0;
}


//关闭仓库
int close_cangku()
{
	object me = this_player();

	if(!me->query("cangku/password"))
	{
		tell_object(me,"您的仓库没有上锁。\n");
		return 1;	
	}
	if(!me->query_temp("cangku/lock"))
	{
		tell_object(me,"仓库正处于关闭状态。\n");
		return 1;
	}
	check_pwd("",me,4);
	return 1;
}

//查看仓库物品
int do_look()
{
	int password;
	object me = this_player();
	password = to_int(me->query("cangku/password"));
	
	if(!me->query_temp("cangku/lock") && password)
	{
		tell_object(me,"你的仓库尚未打开，无法查看物品。\n");
		return 1;
	}
	do_cun_cangku("",me,3);
	return 1;
}

//把物品放进去
int do_cun()
{
	int password;
	object me = this_player();
	password = to_int(me->query("cangku/password"));
	//仓库是否开着。
	if(!me->query_temp("cangku/lock") && password)
	{
		tell_object(me,"你的仓库尚未打开，无法存取物品。\n");
		return 1;
	}
	//输入存放物品
	tell_object(me,"请输入你要存的物品ID:\n");
	input_to("do_cun_cangku",me,1);
	return 1;
}

//存取物品
int do_cun_cangku(string id,object me,int index)
{
	object item;
	string fileName,writeFile,meFile,*meFilePach,temp,temp2;
	string item_name,item_id,item_file,prop,item_prop;
	int i,size,ckSize;

	if(!id || !me ) return 1;
	
	switch(index)
	{
		//存入物品
		case 1 :
			item = present(id,me);
			if(!item)
			{
				tell_object(me,"你身上没有这件物品。\n");
				return 1;
			}
			else
			{
				if(item->query("id") == "gold" ||
				   item->query("id") == "silver" ||
				   item->query("id") == "coin" ||
				   item->query("id") == "jin sha" ||
				   item->query("id") == "red pocket" ||
				   item->query("id") == "cash" ||
                                   item->query("id") == "budai" ||
                                   item->is_npc() ||
				   item->query("no_save") ||
				   item->query("no_put") ||
				   item->query("no_give") ||
				   userp(item))
				{
					tell_object(me,"抱歉，这件物品不能存取。\n");
					return 1;
				}
				temp = file_name(item);
				if(sscanf(temp,"%s#%s",fileName,temp2) != 2)
				{
					fileName = temp;
				}
				
				if(!fileName)
				{
					tell_object(me,"Error: 找不到文件，请联系巫师。\n");
					return 1;
				}
				//找到玩家的 仓库数据 然后改写 储存。
		
				writeFile = query_save(me);
				if(!writeFile) return 1;
		
				meFile = read_file(writeFile);
				if(meFile) meFilePach = explode(meFile,"\n");
		
				ckSize = to_int(me->query("cangku\ckSize"));
				if(!ckSize)
				{
					ckSize = 10;
					me->set("cangku\ckSize",ckSize);
				}
		
				size = sizeof(meFilePach);
				
				if(size >= ckSize)
				{
					tell_object(me,"对不起，你存放的东西太多了。\n");
					return 1;
				}
				assure_file(writeFile);
				prop = ITEM_ITEM_D->query_save_prop_string_2(item);
				write_file(writeFile,sprintf("name:%s$id:%s$pach:%s$prop:%s\n",item->query("name"),item->query("id"),fileName,prop));
				tell_object(me,sprintf("你将%s存入了仓库。\n",item->query("name")));
				me->save();
				destruct(item);
			}
			return 1;
		//取出物品
		case 2 :
				writeFile = query_save(me);
				if(!writeFile) return 1;
		
				meFile = read_file(writeFile);
				if(!meFile)
				{
					tell_object(me,"你仓库里没有任何东西。\n");
					return 0;
				}
				meFilePach = explode(meFile,"\n");
				
				size = sizeof(meFilePach);
				
				for(i=0;i<size;i++)
				{
					if(sscanf(meFilePach[i],"name:%s$id:%s$pach:%s$prop:%s",item_name,item_id,item_file,item_prop) != 4 )
					{
						tell_object(me,"Error: 物品档案出错，请与巫师联系。\n");
						continue;
					}
					if(id == item_id)
					{
						item = new(item_file);
						if(!item)
						{
							tell_object(me,"Error: 物品档案出错，请与巫师联系。\n");
							return 0;
						}
						meFilePach[i] = "";
						break;
					}
				}
				if(!item)
				{
					tell_object(me,"对不起，你仓库里没有这件物品。\n");
					return 1;
				}
				//初始化文件
				write_file(writeFile,"",1);
				//把变量还给item
				ITEM_ITEM_D->set_prop_baseon_string(item,item_prop);
				//重写文件
				for(i=0;i<size;i++)
				{
					if(meFilePach[i] == "") continue;
					write_file(writeFile,sprintf("%s\n",meFilePach[i]));
				}
				
				tell_object(me,sprintf("你从仓库取出了%s。\n",item->query("name")));
				item->set("master",me->query("id"));  //记录上使用者 提供特殊物品需求
				item->move(me);
				me->save();
			return 1;
			//察看仓库
		case 3 :
				writeFile = query_save(me);
				if(!writeFile) return 1;
		
				meFile = read_file(writeFile);
				if(!meFile)
				{
					tell_object(me,"你仓库里没有任何东西。\n");
					return 0;
				}
				meFilePach = explode(meFile,"\n");
				
				size = sizeof(meFilePach);
				if(!size)
				{
					tell_object(me,"你仓库里没有任何东西。\n");
					return 0;
				}

				tell_object(me,"你仓库里有:\n");
				tell_object(me,"--------------------------------------\n");
				for(i=0;i<size;i++)
				{
					if(sscanf(meFilePach[i],"name:%s$id:%s$pach:%s$prop",item_name,item_id,item_file,item_prop) != 4 )
					{
						tell_object(me,"Error: 物品档案出错，请与巫师联系。\n");
						continue;
					}
					tell_object(me,sprintf("%d: %s(%s)\n",i+1,item_name,item_id));
				}
				tell_object(me,"--------------------------------------\n");
				return 1;
	}
	return 0;
}

//把物品取出来
int do_qu()
{
	int password;
	object me = this_player();
	password = to_int(me->query("cangku/password"));
	//仓库是否开着。
	if(!me->query_temp("cangku/lock") && password)
	{
		tell_object(me,"你的仓库尚未打开，无法存取物品。\n");
		return 1;
	}
	tell_object(me,"请输入你要存的物品ID:\n");
	input_to("do_cun_cangku",me,2);
	return 1;
}

//查找存盘地址
string query_save(object me)
{
	string id;

	if(!me) return 0;

	id = me->query("id",1);
	if( !id ) id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "cangku/%c/%s.z", id[0], id);
}
