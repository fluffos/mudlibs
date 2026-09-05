// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
void create()
{
	set("short", HIM"内东门司"NOR);
	set("long", @LONG
这里是内东门司，内廷的一个重要的职司。
LONG
	);
    //set("outdoors", "hangzhou");

	set("exits", ([
		//"south" : __DIR__"yudaoh2",
		"west" : __DIR__"qinrui",
		//"north" : __DIR__"yudao1",
		//"north" : __DIR__"yudao1",
		"east" : __DIR__"juntou",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    "/d/song/npc/neidong" : 1,
        ])); 
	setup();
}

void init()
{
	add_action("do_chakan","chakan");
	add_action("do_answer","write");
}
string get_number(object me,string type,string depart)
{
	int n=40+random(20);
	me->set_temp("songtasks/neidongmen/"+depart+"/"+type,n);
	return chinese_number(n);
}
int get_question(object me)
{
	string dep1,dep2,dep3,*deps=({"福宁宫","坤宁宫","东宫","御药房","内东门司","合同凭由司","管勾往来国信所","后苑造作所","军头引见司","翰林院"});
	string type,*types=({"火烛","檀香","布匹","烧炭","贡茶","钱钞"});
	dep1=deps[random(sizeof(deps))];
	deps-=({dep1});
	dep2=deps[random(sizeof(deps))];
	deps-=({dep2});
	dep3=deps[random(sizeof(deps))];
	type=types[random(sizeof(types))];
	me->set_temp("songtasks/neidongmen/answer",me->query_temp("songtasks/neidongmen/"+dep1+"/"+type)+me->query_temp("songtasks/neidongmen/"+dep2+"/"+type)+me->query_temp("songtasks/neidongmen/"+dep3+"/"+type));
	tell_object(me,"现在需要你填写的是，"+HBBLU+HIW+dep1+NOR+"、"+HBBLU+HIW+dep2+NOR+"和"+HBBLU+HIW+dep3+NOR+"总计共消耗"+HIR+U+type+NOR+"多少。\n");
	tell_object(me,HIC+"可以用write <数字>回答，比如write 185。\n"+NOR);
	return 1;
}

int do_answer(string arg)
{
	object me=this_player();
	int answer;
	if (!me->query_temp("songtasks/neidongmen/answer"))
	return 0;
	if (!arg||sscanf(arg, "%d",answer)!=1)
	{
		tell_object(me,"请用write <数字>格式回答。");
		return 1;
	}
	message_vision("$N在文书记录上写下了"+chinese_number(answer)+"，并签上了自己的名字。\n",me);
	if (answer!=me->query_temp("songtasks/neidongmen/answer"))
	{
		tell_object(me,"你算错了度支。\n");
		me->delete_temp("songtasks");
		tell_object(me,RED"大宋任务失败！\n"NOR);
		DASONG_D->task_finish(me,-5);
		return 1;
	}
	tell_object(me,"你计算对了这些度支。\n");
	me->add_temp("songtasks/neidongmen/correct_times",1);
	if (me->query_temp("songtasks/neidongmen/correct_times")>=3)
	{
		me->delete_temp("songtasks/neidongmen/answer");
		me->set_temp("songtasks/neidongmen/1/finish",1);
		tell_object(me,"用度计算完成，你可以复命了。\n");
		return 1;
	}
	else
	{
		tell_object(me,"继续计算其他的用度……\n");
		return get_question(me);
	}
}
int do_chakan()
{
	object me=this_player();
	string msg;
	string dep1="福宁宫",dep2="坤宁宫",dep3="东宫",dep4="御药房",dep5="内东门司",dep6="合同凭由司",dep7="管勾往来国信所",dep8="后苑造作所",dep9="军头引见司",dep10="翰林院";
	string type1="火烛",type2="檀香",type3="布匹",type4="烧炭",type5="贡茶",type6="钱钞";
	int n=14+random(3);
	if (me->query_temp("songtasks/neidongmen/task")!=1)
	return 0;
	if (me->query_temp("songtasks/neidongmen/1/finish"))
	{
		tell_object(me,"你的任务已经完成了。\n");
		return 1;
	}
	if (me->query_temp("songtasks/neidongmen/chakan_msg"))
	{
		tell_object(me,me->query_temp("songtasks/neidongmen/chakan_msg"));
		return 1;
	}
	msg=sprintf("%|"+n*11+"s\n",BMAG+BLK+"宫内各处用度明细\n"+NOR);
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n","",dep1,dep2,dep3,dep4,dep5,dep6,dep7,dep8,dep9,dep10);
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",type1,get_number(me,type1,dep1),get_number(me,type1,dep2),get_number(me,type1,dep3),get_number(me,type1,dep4),get_number(me,type1,dep5),get_number(me,type1,dep6),get_number(me,type1,dep7),get_number(me,type1,dep8),get_number(me,type1,dep9),get_number(me,type1,dep10),);
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",type2,get_number(me,type2,dep1),get_number(me,type2,dep2),get_number(me,type2,dep3),get_number(me,type2,dep4),get_number(me,type2,dep5),get_number(me,type2,dep6),get_number(me,type2,dep7),get_number(me,type2,dep8),get_number(me,type2,dep9),get_number(me,type2,dep10),);
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",type3,get_number(me,type3,dep1),get_number(me,type3,dep2),get_number(me,type3,dep3),get_number(me,type3,dep4),get_number(me,type3,dep5),get_number(me,type3,dep6),get_number(me,type3,dep7),get_number(me,type3,dep8),get_number(me,type3,dep9),get_number(me,type3,dep10),);
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",type4,get_number(me,type4,dep1),get_number(me,type4,dep2),get_number(me,type4,dep3),get_number(me,type4,dep4),get_number(me,type4,dep5),get_number(me,type4,dep6),get_number(me,type4,dep7),get_number(me,type4,dep8),get_number(me,type4,dep9),get_number(me,type4,dep10),);
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",type5,get_number(me,type5,dep1),get_number(me,type5,dep2),get_number(me,type5,dep3),get_number(me,type5,dep4),get_number(me,type5,dep5),get_number(me,type5,dep6),get_number(me,type5,dep7),get_number(me,type5,dep8),get_number(me,type5,dep9),get_number(me,type5,dep10),);
	msg+=sprintf("%-"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s%|"+n+"s\n",type6,get_number(me,type6,dep1),get_number(me,type6,dep2),get_number(me,type6,dep3),get_number(me,type6,dep4),get_number(me,type6,dep5),get_number(me,type6,dep6),get_number(me,type6,dep7),get_number(me,type6,dep8),get_number(me,type6,dep9),get_number(me,type6,dep10),);
	msg=replace_string(msg,type1,BRED+HIW+type1+NOR);
	msg=replace_string(msg,type2,BCYN+HIW+type2+NOR);
	msg=replace_string(msg,type3,BBLU+HIR+type3+NOR);
	msg=replace_string(msg,type4,HBWHT+BLK+type4+NOR);
	msg=replace_string(msg,type5,BGRN+YEL+type5+NOR);
	msg=replace_string(msg,type6,HBWHT+HIC+type6+NOR);
	me->set_temp("songtasks/neidongmen/chakan_msg",msg);
	tell_object(me,msg);
	get_question(me);
	return 1;
}