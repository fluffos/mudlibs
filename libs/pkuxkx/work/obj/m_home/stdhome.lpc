#pragma save_binary
#include <ansi.h>
inherit ROOM;

string* access_set=({
		"no_learn",
		"no_study",
		"no_magic",
		"no_spells",
		"no_exercise",
		"no_meditate",
		"no_respirate",
		"no_fight",
});
string out="/d/playerhomes/phomes";
string check_str(string str);
string query_save_file();
int save();
int restore();
void create()
{
        set("short", "标准新房");
        set("long", @LONG

一切都设置好了，只等一些室内装修。 
LONG
        );

   set("valid_startroom",1);
   set("host","wlwsII");
   set("sleep_room", 1);
   set("exits", ([
        "out": out,
		]));
                                              
        setup();
}

void init()
{
	object me,invitation,host;
    string id,owner1,owner2;

	me=this_player();
	id=me->query("id");
	if (sscanf(query("host"),"%s&%s",owner1,owner2) != 2)
	{
		tell_object(this_player(),"这个房间出了问题，尽快通知巫师！\n");
		return;
	}
        if (id!=owner1 && id!=owner2 && !wizardp(me))
	{
		if (!host=present(owner1,this_object()))
		{
			if(!host=present(owner2,this_object()))
			{
				tell_object(me,HIY"主人不在家，您还是呆会儿再来吧。\n"NOR);
				tell_room(out,me->query("name")+"失望地走了出来。\n",({me}));
				me->move(out);
				return;
			}
		}
		if (invitation=present("home qing tie",me))
		{
			if (invitation->query("host")!=query("host"))
			{
				message_vision(HIW"$N一推门，一脸茫然的走了进来。\n"NOR,me,host);
				message_vision(HIR"$N高声喝道：“你是谁？怎么闯入了私人地方？请快离开！”。  \n"NOR,host,me);
				message_vision(HIY"$N飞起一脚，正好踢中$n的屁股 ,$n一个踉跄跌出了门，连忙跑掉了。  \n"NOR,host,me);
				me->receive_damage("kee",5);
				me->move(out);
				return;
			}
			else 
				destruct(invitation);
		}
		else
		{
			message_vision(HIW"$N一推门，一脸茫然的走了进来。\n"NOR,me,host);
				message_vision(HIR"$N高声喝道：“你是谁？怎么闯入了私人地方？请快离开！”。  \n"NOR,host,me);
				message_vision(HIY"$N飞起一脚，正好踢中$n的屁股 ,$n一个踉跄跌出了门，连忙跑掉了。  \n"NOR,host,me);
					me->receive_damage("kee",5);
			me->move(out);				
			return;
			}
	}
	tell_room(this_object(),me->query("name")+"拉开门，走了进来。\n",({me}));
	if (id==owner1 || id == owner2)
	{
		add_action("do_set_short","set_short");
		add_action("do_set_long","set_long");
		add_action("do_set_property","set_property");
		add_action("do_unset_property","unset_property");
		add_action("do_query_property","query_property");
		add_action("do_kickout","kickout");
	}
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
int do_set_property(string arg)
{
	int i;
	if (!arg)
		return notify_fail("格式：set_property <房间属性>\n");	
	arg=check_str(arg);
	if (member_array(arg,access_set)==-1)
	{
		tell_object(this_player(),"你可以设置以下房间属性：\n");
		for (i=0;i<sizeof(access_set);i++)
			tell_object(this_player(),access_set[i]+"\n");
		return 1;
	}
	set(arg,1);
	save();
	restore();
	return 1;
}
int do_unset_property(string arg)
{
	int i;
	if (!arg)
		return notify_fail("格式：unset_short <房间属性>\n");
	arg=check_str(arg);
	if (member_array(arg,access_set)==-1)
	{
		tell_object(this_player(),"你可以取消以下房间属性：\n");
		for (i=0;i<sizeof(access_set);i++)
			tell_object(this_player(),access_set[i]+"\n");
		return 1;
	}
	set(arg,0);
	save();
	restore();
	return 1;
}
int do_query_property()
{
	int i;
	for (i=0;i<sizeof(access_set);i++)
	{
		if (query(access_set[i]))
			tell_object(this_player(),access_set[i]+"    YES\n");
		else
			tell_object(this_player(),access_set[i]+"    NO\n");		
	}
	return 1;
}
int do_kickout(string arg)
{
	object obj;
	string temp;
	if (!arg || !obj=present(arg,this_object()))
		return notify_fail("你要把谁赶出家门？\n");
	message_vision(HIW"$N怒气冲冲的对$n说：“现在你是这里不受欢迎的人，请你立即出去。”\n"NOR,this_player(),obj);
	message_vision(HIR"$N飞起一脚，正踢中$n的屁股，$n腾云驾雾搬飞出门外。\n"NOR,this_player(),obj);
	obj->move(out);
	temp=sprintf("%s狼狈的跑了出来，还不时回头张望，似乎怕谁追来。\n",obj->query("name"));
	tell_room(out,HIG+temp+NOR);
	return 1;

}
string query_save_file()
{
        string str;

        str = query("host");
        if( !stringp(str) ) return 0;
        return sprintf("/data/home/" + str[0..0] + "/" + str);
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
        if(restore_object(file))
        {
                return 1;
        }
        return 0;
}
