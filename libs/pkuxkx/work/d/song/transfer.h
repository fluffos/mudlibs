#include <ansi.h>
int start_pin(object me)
{
	int start_pin;
	start_pin=DASONG_D->jilu_pin(me)-3;
	if (me->query("song/pro")=="文")
	start_pin+=1;
	if (start_pin<1)
	start_pin=1;
	return start_pin;
}
mapping *suit_titles(object me)
{
	object ob=load_object("/d/song/record/positions");
	int start_pin;
	if (!me->query("song/pro"))
	return ({});
	if (DASONG_D->jilu_pin(me)<1||DASONG_D->jilu_pin(me)>9)
	return ({});
	start_pin=start_pin(me);
	if (start_pin>=1&&start_pin<=3)
	return DASONG_D->giveouts(ob,"give_titles",DASONG_D->upper_title());
	else if (start_pin>=4&&start_pin<=7)
	return DASONG_D->giveouts(ob,"give_mediate_titles",DASONG_D->lower_title());
	else
	return DASONG_D->lowest_title();
}
int choose_title(object me)
{
	int start_pin=start_pin(me);
	string msg,*titles=({});
	mapping *give_outs=suit_titles(me);
	int count=0;
	if (sizeof(give_outs)==0)
	return notify_fail("暂无你可以调任的官职。\n");
	msg="你可以申请调任的官职有：\n";
	for (int i=0;i<sizeof(give_outs);i++)
	{
		if (give_outs[i]["pin"]<start_pin)
			continue;
		else if ((stringp(give_outs[i]["owner"])&&give_outs[i]["owner"]!="")||((arrayp(give_outs[i]["owner"])||!give_outs[i]["owner"])&&give_outs[i]["vacancy"]<=0))
			continue;
		else if (give_outs[i]["no_promote"]||give_outs[i]["no_diaoren"])
			continue;
		else if (give_outs[i]["term"]&&time()-me->query("song/term/"+give_outs[i]["title"]+"/start_date")<5184000)
			continue;
		else if (give_outs[i]["credit"]>me->query("song/credit"))
			continue;
		else if (give_outs[i]["pro"]!=me->query("song/pro")&&give_outs[i]["pro"]!="兼")
			continue;
		else if (me->query("song/title")&&strsrch(me->query("song/title"),give_outs[i]["title"])!=-1)
			continue;
		else
		{
			count+=1;
			msg+=give_outs[i]["title"]+"▇";
			msg+=give_outs[i]["is_major"]?"正":"从";
			msg+=chinese_number(give_outs[i]["pin"])+"品\n";
			titles+=({give_outs[i]["title"]});
		}
		if (count>=5)
		break;
	}
	me->set_temp("song/lower_transfer_titles",titles);
	msg+="你希望任职(choose)的官职是？\n";
	tell_object(me,msg);
	return 1;
}
int pre_choose()
{
	object ob=this_object(),me=this_player();
	if (!me->query("song/pro"))
	return 0;
	if (me->query("song/pro")!=ob->query("pro_trans"))
	return notify_fail("这里不是"+me->query("song/pro")+"官申请变更职务的所在。\n");
	if (!arrayp(ob->query("pin_range")))
	return notify_fail("这里不是申请变更职务的所在。\n");
	if (member_array(DASONG_D->jilu_pin(me),ob->query("pin_range"))==-1)
	return notify_fail("这里不是你这个级别官员申请变更职务的所在。\n");
	if (time()-me->query("song/lowofficer_transfer")<604800)
	return notify_fail("你不久前刚刚申请过调职，需要在"+CHINESE_D->chinese_period(604800+me->query("song/lowofficer_transfer")-time())+"后才能再次申请。\n");
	me->set("song/lowofficer_transfer",time());
	return choose_title(me);
}

int do_choose(string arg)
{
	object me=this_player(),ob=load_object("/d/song/record/other");
	if (!arrayp(me->query_temp("song/lower_transfer_titles")))
	return 0;
	if (!arg)
	{
		tell_object(me,"你可以选择变更的官职有：\n");
		for (int i=0;i<sizeof(me->query_temp("song/lower_transfer_titles"));i++)
		{
			tell_object(me,me->query_temp("song/lower_transfer_titles")[i]+"■");
		}
		tell_object("\n");
		return 1;
	}
	if (member_array(arg,me->query_temp("song/lower_transfer_titles"))==-1)
	{
		tell_object(me,"你可以选择变更的官职有：\n");
		for (int i=0;i<sizeof(me->query_temp("song/lower_transfer_titles"));i++)
		{
			tell_object(me,me->query_temp("song/lower_transfer_titles")[i]+"■");
		}
		tell_object("\n");
		return 1;
	}
	me->delete_temp("song/lower_transfer_titles");
	tell_object(me,"你希望担任"+arg+"的职务，静候佳音吧。\n");
	return DASONG_D->title_pursue(me,arg);
}
int do_look(string arg)
{
	if (!arg&&this_player()->query("song/pro"))
	{
		"/cmds/std/look.lpc"->mudlook_room(this_player(),this_object(),0);
		tell_object(this_player(),"    "HBCYN+HIR"这里的衙门接受部分官员申请(apply)变更职务。\n"+NOR);
		return 1;
	}
	return 0;
}
void init()
{
	add_action("pre_choose","apply");
	add_action("do_choose","choose");
	add_action("do_look",({"look","l"}));
}
