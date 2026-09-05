//Mud eXtension Protocol
//please refer to MXP standard at
//http://www.zuggsoft.com/zmud/mxp.htm

#include "ansi.h"

#define MXP_OPEN_TAG CSI"0z"
#define MXP_SEC_TAG CSI"1z"
#define MXP_LOCK_TAG CSI"2z"

void PostDetect(object arg);

int DetectMxpClient(object ob)
{
	write("即将开始检测你的客户端对MXP的支持程度。如果5s中之内没有反应，代表你使用的客户端完全不支持MXP,请按回车进入普通模式。\r\n");
	write("推荐使用Zmud,CMud和MushClient。请访问http://www.pkuxkx.com/学习如何配置MXP客户端。\r\n");

	write(MXP_SEC_TAG"<SUPPORT>\r\n");

	input_to("RecvClientVer",1,ob);
	return 1;
}

int RecvClientVer(string input,object ob)
{
	int i = 0;
	int pos = -1;
	string* tags;

	if(strwidth(input) == 0)
	{
		write("你的客户端不支持MXP功能，使用普通文本模式。\r\n");
		PostDetect(ob);
		return 0;
	}

	input[0] = '';
	pos  = strsrch(input,MXP_SEC_TAG);

	if(strsrch(input,MXP_SEC_TAG) != 0)
	{
		write("你的客户端不支持MXP功能，使用普通文本模式。\r\n");
		PostDetect(ob);
		return 0;
	}
	input = lower_case(input);
	pos = strsrch(input,"<supports");
	if(pos == -1) 
	{
		write("你的客户端未能正确的支持MXP功能，使用普通文本模式。\r\n");
		PostDetect(ob);
		return 0;
	}
	input = input[pos+strwidth("<supports")..<0];
	input = replace_string(input,">","");
	tags = explode(input,"+");
	for(i = 0;i < sizeof(tags); i++)
	{
		tags[i]=replace_string(tags[i]," ","");
		ob->set_temp("MXP/"+tags[i],1);
	}
	write("你的客户端支持MXP。\r\n");
	PostDetect(ob);
	return 1;
}

int SendImage(object user,string name,int width,int height,string align,string url)
{
	string mxpcmd;
	if(!userp(user) || (user->query_temp("MXP/image") != 1 && user->query_temp("MXP/img") != 1) || user->query("env/mxp_image") != 1)
	{
		return 0;		
	}

	if(user->query_temp("MXP/image") == 1)
	{
		mxpcmd = sprintf(MXP_SEC_TAG"<image FName=%s ",name);

		if(strwidth(url) > 0)
		{
			mxpcmd = mxpcmd+"url=\""+url+"\" ";
		}
		if(width > 0)
		{
			mxpcmd = mxpcmd+sprintf("W=%d ",width);
		}
		if(height > 0)
		{
			mxpcmd = mxpcmd+sprintf("H=%d ",height);
		}

		align = lower_case(align);
		if(strwidth(align) > 0 && (align == "left" || align == "right" || align == "top" || align == "middle" || align == "bottom"))
		{
			mxpcmd = mxpcmd+"align="+align+" ";
		}
		mxpcmd = mxpcmd + ">\r\n";
	}
	else
	{
		//mush client
		mxpcmd = sprintf(MXP_SEC_TAG"<img src=\"%s%s\">\r\n",url,name);
	}
	tell_object(user,mxpcmd);
	return 1;
}

int SendSound(object user,string name,int volume,string url)
{
	string mxpcmd;
	if(userp(user) && user->query("env/mxp_sound") == 1)
	{
		if(user->query_temp("MXP/music") == 1)
		{
			mxpcmd = sprintf(MXP_SEC_TAG"<music FName=%s ",name);
			if(volume > 0)
			{
				mxpcmd = mxpcmd+sprintf("v=%d ",volume);
			}
			if(strwidth(url) > 0)
			{
				mxpcmd = mxpcmd+"url="+url+" ";
			}

			mxpcmd = mxpcmd + ">\r\n";
		}
		else
		{
			mxpcmd = sprintf("!!MUSIC(%s ",name);
			if(volume > 0)
			{
				mxpcmd = mxpcmd+sprintf("V=%d ",volume);
			}
			if(strwidth(url) > 0)
			{
				mxpcmd = mxpcmd+"U="+url+" ";
			}
			mxpcmd = mxpcmd + ")\r\n";
		}
		tell_object(user,mxpcmd);
	}
	else
	{
		return 0;
	}
	return 1;
}

int StopSound(object user)
{
	string mxpcmd;
	if(userp(user) && user->query("env/mxp_sound") == 1)
	{
		if(user->query_temp("MXP/music") == 1)
		{
			mxpcmd = MXP_SEC_TAG"<music FName=Off>\r\n";
		}
		else
		{
			//zmud 4.62 compitable
			mxpcmd = "!!MUSIC(Off)\r\n";
		}
		tell_object(user,mxpcmd);
	}
	else
	{
		return 0;
	}
	return 1;
}

int SendText(object user,string text,int size,string color)
{
	if(!userp(user) || (user->query_temp("MXP/H") != 1))
	{
		return 0;		
	}
	return 1;

}
