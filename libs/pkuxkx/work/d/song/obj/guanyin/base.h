//官印
//create by zine 29/3/2011
inherit F_MORE;
#include <ansi.h>
#include <title.h>
#include "/d/song/obj/guanyin/tasks.h"
#include "/d/song/obj/guanyin/backup.h"
#include "/d/song/obj/guanyin/senior_officer.h"
#include "/d/song/obj/guanyin/privilege.h"
#include "/d/song/obj/guanyin/settings.h"
#define VER 19 //版本号，用来确定所有人的官印都是最新的
#define PROMOTE_LIST 4//官职号

int dest()
{
    if (this_object())
    destruct(this_object());
}
int ver()
{
	return this_object()->query("version");
}
int is_guanyin()
{
	return 1;
}
void init()
{
    object belong=environment(this_object());
	add_action("do_reward","reward");
	add_action("do_yes","yes");
	add_action("do_no","no");
	add_action("do_refuse","refuse");
	add_action("do_accept","accept");
	add_action("do_zheng","zheng");
    add_action("do_yayun","yayun");
	add_action("do_xiu","xiushan");
	add_action("do_recruit","recruit");
	add_action("do_look","look");
    add_action("do_zhao","zhao");
    add_action("do_qing","qing");
	add_action("do_qing","yaoqing");
	add_action("do_tongzhi","notice");
	add_action("do_zhishou","zhishou");
	add_action("do_wait","wait");
	add_action("do_jiejian","yinjian");
	add_action("do_song","song");
    if (belong&&!userp(belong))
    {
        call_out("dest",1);
        return;
    }
	if (!belong->query("song/pro"))
    {
        call_out("dest",1);
        return;
    }
	if (belong->query("song/pro")!=this_object()->query("pro"))
	{
		call_out("dest",1);
        return;
	}
}
int do_song(string arg)
{
	int count=0;
	string cmd="",*commands=({});
	if (!arg)
	return notify_fail("大宋命令格式song <命令>，可用song -cmds查询现有所有大宋命令。\n");
	if (arg=="-cmds")
	{
		commands=DASONG_D->all_command();
		write("大宋可用指令：\n");
		for (int k=0;k<sizeof(commands);k++)
		{
			write(commands[k]+" ");
			count+=1;
			if (count%6==0)
			{
				write("\n");
			}
		}
		write("\n具体命令帮助，可用song <命令> -h获得。\n");
		return 1;
	}
	DASONG_D->find_command(arg);
	if (DASONG_D->warning())
	{
		write("大宋命令参数里包含命令保留关键字，可能造成大宋命令失败！\n");
	}
	cmd=DASONG_D->get_cmd();
	arg=DASONG_D->get_parameter();
	if (cmd=="")
	{
		return notify_fail("并无此条大宋命令，可用song -cmds查询现有所有大宋命令。\n");
	}
	if( stringp(cmd) 
		&& call_other(cmd, "main", this_player(), arg))
	return 1;
}
int check_in()
{
	object me=environment(this_object());
	if (!me)
	return 1;
	me->set_temp("song_identification",this_object());
	if (PROMOTE_LIST>me->query("song/promote_list_update"))//官职列表的变化
	{
		me->set("song/promote_list_update",PROMOTE_LIST);
		me->set("song/last_promote_credit",-1);
	}
	if (me->query("song/changes/jue")<1)
	{
		me->add("song/changes/jue",1);
		DASONG_D->reset_my_jue(me);
	}
	record(me);
	back_me_up(me);
	get_unique_position(me);
	force_suikao(me);
	DASONG_D->set_me_duty(me);
	DASONG_D->position_me(me);
	check_me_in(me);
	DASONG_D->if_give_jue(me);
	return 1;
}
mapping * get_upper_title()
{
	return DASONG_D->upper_title();
}