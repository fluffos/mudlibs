//By Pal
a
a
//新房间模板
#pragma save_binary

#include <ansi.h>
inherit ROOM;
int save();
int restore();
string query_save_file();
void create()
{
	set("short", "山庄大门");
	set("long", @LONG
这是一个新的房间，你可以对它进行装修。
LONG
	);
	set("valid_startroom",0);
	set("host","icer");//所有者
	set("roomvalue",0);//房间价值
	set("room_ok",1);//是否好的房间
	set("exits", ([
//房间出口
		]));
	set("objects", ([
//房间有的物品
		]));
	restore();
	setup();
}

void init()
{
	object link_ob;
	string id;
	link_ob=this_player()->query_temp("link_ob");
	id=link_ob->query("id");
	if( id==query("host") )
	{
		add_action("do_set_short","set_short");
		add_action("do_set_long","set_long");
		add_action("set_start","set_startroom");
		add_action("make_new_room","makeroom");
	}
}

string query_save_file()//.o文件放在/data/home/save/目录下，.c文件放在/data/home/file/目录下
{
        string str,*filename,host;
        str = file_name();
		host = query("host");
		filename = explode(str,"/");
		str=filename[sizeof(filename)-1];
        if( !stringp(str) || !stringp(host) ) return 0;
        return sprintf("/data/home/save/" + host[0..0] + "/" + host + "/" + str);
}

int save()
{
        string file;
		int result;
        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                return result;
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file,1))
        {
                return 1;
        }
        return 0;
}

string check_str(string str)
{ 
    str=replace_string(str,"\"","");
    str=replace_string(str,";","");
    str=replace_string(str,"\\","");
    str=replace_string(str,"/","");
    str=replace_string(str,"'","");
    str=replace_string(str,"`","");
    str=replace_string(str,",","");
    str=replace_string(str,"!","");
    str=replace_string(str,"~","");
    str=replace_string(str,"{","");
    str=replace_string(str,"}","");
    str=replace_string(str,"$","");
    str=replace_string(str,"&","");
    return str;
}

int set_start()//设置startroom
{
	if(query("valid_startroom"))
		set("valid_startroom",0);
	else
		set("valid_startroom",1);
	save();
	restore();
	return 1;
}

int do_set_short(string arg)
{
	if (!arg)
		return notify_fail("格式：set_short <描述>\n");
	arg=check_str(arg);
	set("short",arg);
	save();
	restore();
	return 1;
}

int do_set_long(string arg)
{
	if (!arg)
		return notify_fail("格式：set_long <描述>\n");
	arg=check_str(arg);
	set("long",arg+"\n");
	save();
	restore();
	return 1;
}

int make_new_room(string arg)//建设新房间,make_new_room direct
{
	return 1;
}
