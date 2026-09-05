// Room: guanzhan.c 草原
// created by Zine 30 Aug 2010

inherit ROOM;
#include <ansi.h>
#include "/d/menggu/shediao_bonus.h"

void create()
{
	set("short", HIY"草原战场"NOR);
	set("long", @LONG
一望无际的草原，和天边连成一片。
LONG
	);
    set("real_dark",1);
	set("exits", ([
		
	]));
	set("no_robber",1);
	set("outdoors", "menggu_e");
	setup();
}

void init()
{
	object me= this_player();
    if (!me->query_temp("lpjob/gz_init"))
    {
        me->set("shediaoquest/dmfy",1);
        me->set_temp("lpjob/gz_init",1);
        tell_object(me,CYN"你忙牵了小马小羊，走上一个土山，钻在灌木丛里，躲好后再探出头来。\n"NOR);
        tell_object(me,CYN"只见远处尘土蔽天，无数车马奔驰而至，东一队，西一队，不计其数。\n"NOR);
        call_out("guanzhan2", 6, me);
    }
	
	return;
}

int guanzhan2(object me)
{
    tell_object(me,CYN"你这时不再害怕，看得很是开心。\n"NOR);
	tell_object(me,CYN"忽然数十支号角齐声吹动，一阵急鼓，进攻的军士大声欢呼：“铁木真大汗来啦，大汗来啦！”\n"NOR);
	call_out("guanzhan3", 6, me);
	return 1;
}

int guanzhan3(object me)
{
    tell_object(me,CYN"他便是蒙古部落的酋长铁木真。\n"NOR);
	tell_object(me,CYN"敌兵齐声欢呼，密密麻麻的兵马争先恐后向土山涌来，都不去理会四下退开的蒙古兵卒。”\n"NOR);
	call_out("guanzhan4", 6, me);
	return 1;
}

int guanzhan4(object me)
{
    tell_object(me,CYN"铁木真站在土山高处，凛然不动。\n"NOR);
	tell_object(me,CYN"蒙古兵渐渐后退。\n"NOR);
	call_out("guanzhan5", 6, me);
	return 1;
}

int guanzhan5(object me)
{
    tell_object(me,CYN"者勒米奔上土山，叫道：“大汗，孩儿们抵挡不住啦！”\n"NOR);
	tell_object(me,CYN"铁木真怒道：“挡不住？你夸甚么英雄好汉？”\n"NOR);
	call_out("guanzhan6", 6, me);
	return 1;
}

int guanzhan6(object me)
{
    tell_object(me,CYN"者勒米脸上变色，冲入敌阵，杀开一条血路。\n"NOR);
	tell_object(me,CYN"又战良久，西南角上敌军中忽有一名黑袍将军越众而出，箭无虚发，接连将蒙古兵射倒了十余人。\n"NOR);
	call_out("guanzhan7", 6, me);
	return 1;
}

int guanzhan7(object me)
{
    tell_object(me,CYN"黑袍将军已冲近土山，弓弦响处，一箭正射在铁木真颈上。\n"NOR);
	tell_object(me,CYN"铁木真牵过一匹马来，奋力上鞍，叫道：“大家牢牢守住了！”\n"NOR);
	call_out("guanzhan8", 6, me);
	return 1;
}

int guanzhan8(object me)
{
    tell_object(me,CYN"铁木真见敌势少衰，叫道：“举纛，吹号！”\n"NOR);
	tell_object(me,CYN"不到半个时辰，大军已被冲得土崩瓦解，大股歼灭，小股逃散。\n"NOR);
	call_out("guanzhan9", 6, me);
	return 1;
}

int guanzhan9(object me)
{
    tell_object(me,CYN"那黑袍将军骑了一匹黑马，落荒而走。\n"NOR);
	tell_object(me,CYN"数十名蒙古健儿大呼追去。那黑袍将军箭无虚发，当者落马，一口气射倒了十余人。\n"NOR);
	tell_object(me,CYN"你躲在树丛中遥遥望见，小心灵中对那黑袍将军好生钦仰。\n"NOR);
	call_out("goback", 6, me);
	tell_object(me,HIR"你目睹这场大战，再无心放羊，骑着小马，赶着小羊回到郭靖家。\n"NOR);
    return 1;
}

int goback(object me)
{ 
    int e_reward;
	me->delete_temp("lpjob");
	me->move(__DIR__"guojingjia");
	me->set("shediaoquest/dmfy/endtime",time());
	e_reward=bonus(me,500);
    me->add("combat_exp",e_reward);
	user_record(me,e_reward,"dmfy");
    tell_object(me,HIC"完成射雕主线任务【大漠风云】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
	return 1;
}

