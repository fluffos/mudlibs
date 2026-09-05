//专门反机器人的，不可滥用
//Jason 2009/11/08，加入MXP支持，在Mud中直接显示验证图片。
//mxp在pkuxkx的第一个应用。也是唯一在线download的应用
//其他应用应该尽量使用本地包。

#include <mxp.h>
#include <mudlib.h>

#define MXP_SERVICE_STATUS_FILE "/log/mxp_service_status"

int is_stopped = 0;
int last_fullme_time = 0;

int check_timeout();
//string* chdict = ({});
//int dict_size = 0;
void create()
	
{
	
	string line;
	int i = 0;
    seteuid(getuid());
    last_fullme_time = time();
    remove_call_out("check_timeout");
    call_out("check_timeout",10);
    // remove_call_out("check_mxp_service");
    // call_out("check_mxp_service",60);
}

string basedir = "/adm/etc/fullme_dict/";

//protected function
int filter_dir(mixed item)
{
	if(stringp(item) && item != "." && item != ".." && item[0] != '_'  && item[0] != '.')
	{
		if(file_size(basedir+item) > 0) return 1;
	}
	return 0;
}

string load_dict()
{
	string dictdir;
	string* dictdirs;

 	dictdirs = get_dir(basedir+"fullme_dict_*.txt");

	if(arrayp(dictdirs))
	{
		dictdirs = filter_array(dictdirs,"filter_dir",this_object());


		dictdir = dictdirs[random(sizeof(dictdirs))];
		return basedir + dictdir;
		
	}

	return "";
}

//产生一个随机字符串，来自字典
string generaterandomcode()
{
	int filesize = 0;  
	string dict_filename;
  string* dict = ({"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R",
        "S","T","U","V","W","X","Y","Z"});
  string code = "";
    
  int size = 4;	
  dict_filename = load_dict();
	
	filesize = file_size(dict_filename);
	filesize = filesize/8*8;
	if(filesize == 0)
	{
		code = code + dict[random(sizeof(dict))];
		code = code + dict[random(sizeof(dict))];
		code = code + dict[random(sizeof(dict))];
		code = code + dict[random(sizeof(dict))];
	}
	else
	{
		code = read_bytes(dict_filename,random(filesize/8)*8,8);
		code = replace_string(code," ","");
	}       
	return code;	
}

//把code写入临时文件，从web访问这个文件，将会以图片的方式显示，当然包括适当的
//干扰，玩家必须在mud里输入这个字符串。
string* generatewebimgcode(string code,int diff)
{
	string* ret = ({});
	string filename;	
    //generate uid and create file with those name, with the code inside under /web/antirobot
    //理论上这个文件名可能重复，不过概率不高。没找到guid的lpc算法。
    filename = sprintf("%d%d",time(),random(1000000));
    //if(diff)
	if(1)
    {
        write_file("/web/antirobot/"+filename,"#"+code,1);
    }
    else
    {
        write_file("/web/antirobot/"+filename,code,1);
    }
    // code = "一二三四五";
	// filename = "";
    ret += ({code,filename});
    return ret;
}

//diff == 1, 增加扭曲，模糊等干扰。用于fullme
//diff == 0，清晰。用于任务信息
string* mxpantirobot_ctrl(object user,string code,int diff)
{
	string* info;
	string MUD_HOST;
    mapping block_msg;

//    if(user->query("id") == "newbiec" || user->query("id") == "lurenc") 
//    {
//        code = "一二三四五";
//    }
    if (file_size("/adm/etc/fake_fullme")>=0)
    {
        tell_object(user, "图片内容显示："+code+"\n"+NOR);
        info = ({code});
        return info;
    }

	info = generatewebimgcode(COLOR_D->uncolor(code),diff);//有些地名是带ansi代码的，在图片中本身也没有显示，就去掉ansi代码吧。Zine 2013/4/13
	//info = ({code});
	if(user->query_temp("MXP/image") != 1)
	{
		tell_object(user,"你的客户端不支持MXP,请直接打开链接查看图片。\n");
	}
	else
	{
		if(user->query("env/mxp_image") != 1)
		{
			tell_object(user,"请设置mxp_image参数为一，否则你不能从客户端直接看到图片。\r\n");
		}
	}
		
	if(user->query("env/edu") == 1)
	{
	//	MUD_HOST = MUD_EDU_WEB;
	}
	else
	{
	//	MUD_HOST = MUD_WEB;
	}
    //图片信息不被 刺目 等效果block
    block_msg = user->query_temp("block_msg");
    if(mapp(block_msg))
    {
        user->delete_temp("block_msg");
    }
    
    tell_object(user,HIR"请注意，忽略验证码中的红色文字。\n"NOR);
    tell_object(user,"请输入：  "+code+"\r\n");  //直接显示文字
	
/*	tell_object(user,"http://39.107.244.133/robot.php?filename="+info[1]+"\r\n");*/
    
    tell_object(user,"\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
    
 	//SendImage(user,info[1]+".jpg",500,100,"left","http://39.107.244.133/zmud/");

	if(mapp(block_msg))
    {
        user->set_temp("block_msg",block_msg);
    }    
	return info;    
}
string* mxpantirobot_ex(object user,string code)
{
    return mxpantirobot_ctrl(user,code,0);
}

string* mxpantirobot(object user)
{
	return mxpantirobot_ctrl(user,generaterandomcode(),1);
}
//检查/web/antirobot下的所有文件，凡是创建时间超过1分钟的都删除掉
int check_timeout()
{
    int lasttime;
    string* files = get_dir("/web/antirobot/",-1);
    
    for(int i=0;i<sizeof(files);i++)
    {
        lasttime = files[i][2];    
        if(time() - lasttime > 180)
        {
            rm("/web/antirobot/"+files[i][0]);
        }
    }
    remove_call_out("check_timeout");
    call_out("check_timeout",10);    
    return 1;
}

#if 0
int check_mxp_service() 
{ 
    is_stopped = 0; 
    return 0; 
    if (file_size(MXP_SERVICE_STATUS_FILE) >= 0) 
    {
        is_stopped = 0;
    } else 
    {
        is_stopped = 1;
    }
    remove_call_out("check_mxp_service"); 
    call_out("check_mxp_service", 10);    
    return 0;
}

int stopped() 
{ 
    return is_stopped;
}
#endif

void last_fullme(int time)
{
    last_fullme_time = time;
}

int fullme_invalid()
{
    if ( (time()-last_fullme_time)<3600 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int stopped()
{
	return fullme_invalid();
}

void same_as_fullme(object me)
{
	if(!userp(me)) return;
    last_fullme(time());

    /* 放宝石的条件之一 */
    if ((int)me->query("combat_exp")-(int)me->query("statistics/fullme/last_fullme_exp")>1000)
    {
        me->add("statistics/fullme/total_fullme_times",1);
    }
    me->set("statistics/fullme/last_fullme_exp",(int)me->query("combat_exp"));
    me->set("antirobot/deactivity",0);
    me->set("antirobot/last_deactivity_time",time());

    if (me->query("antirobot/deactivity")>=4 || !me->query("antirobot/seg_first_activity_time"))
    {
        me->set("antirobot/seg_first_activity_time",time());
    }
    if (time()-me->query("antirobot/last_activity_time")>3600*5)
    {
        me->set("antirobot/total_activity_time", 0);
        me->set("antirobot/pic_fullme_times", 0);
        me->set("antirobot/hand_fullme_times", 0);
    }
    if (time()-me->query("antirobot/last_activity_time")>3600*5 || !me->query("antirobot/first_activity_time"))
    {
        me->set("antirobot/first_activity_time",time());
        me->set("antirobot/first_activity_exp", me->query("combat_exp"));
    }
    me->set("antirobot/last_activity_time", time());
    me->add("antirobot/pic_fullme_times", 1);
    TOPTEN_D->topten_checkonetype(me, "fullme");
}


