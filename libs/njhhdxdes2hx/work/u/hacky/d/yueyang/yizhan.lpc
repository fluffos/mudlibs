#include <ansi.h>
#define BASE_MONEY 1000

inherit ROOM;

string *make_msg = ({
    HIG "车夫长鞭一甩, 马车上了大道.\n\n" NOR,
    HIG "马车越跑越快.\n\n" NOR,
    HIG "马车越跑越快.\n\n" NOR,
    HIG "马车越跑越快.\n\n" NOR,
    HIG "马车越跑越快.\n\n" NOR,
    HIG "车子在大道上飞驰, 你在车上昏昏欲睡.\n\n" NOR,
    HIG "车夫说: 快到了, 醒一醒!\n\n" NOR,
});

mapping yizhan=([
		"quanzhou"  : "/d/quanzhou/yizhan",
		"suzhou"    : "/d/suzhou/yizhan",
		"jingcheng" : "/d/jingcheng/yizhan",
		"yiyunzhen" : "/d/cloud/yizhan",
	                  ]);

mapping time=([
		"quanzhou"  : 2,
		"suzhou"    : 2,
		"jingcheng" : 4,
		"yiyunzhen" : 7,
	                  ]);
                          
void create()
{
	set("short","驿站");
	set("long", @LONG
    这里是本地的驿站，有钱人可以从这里雇车去往外地。墙上有一块牌子(paizi). 
还有一个车老板坐在旁边等生意。
LONG
	);

	set("exits", ([
                "north" :__DIR__"dongdajie1",
	]));
	
	
        set("objects",([
                "/d/yueyang/npc/chefu" : 1,
        ]));

	
	setup();
}

void init()
{       

        add_action("do_qu", "qu");
	add_action("do_look","l");
	add_action("do_look","look");

}

 
int do_qu(string arg)
{
        object who,che;
	string *zhan;
	int i,flag=0;
	         
        who=this_player();

	zhan=keys(yizhan);
	i=sizeof(zhan);
	while(i--)
	{
		if(arg==zhan[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)  return notify_fail(YEL"不去这个地方\n"NOR);

	if ( !(che=find_object(__DIR__"che"))) che=clone_object(__DIR__"che");
	if (che->query("youren"))	
	{
		return notify_fail("马车已经出去了,请等一会儿。\n");
	}

	switch (MONEY_D->player_pay(who, BASE_MONEY*time[arg]) )
	{
	case 0:
		return notify_fail("车夫鄙夷地对你说道：“穷光蛋，一边呆着去！”\n");
	case 2:
		return notify_fail("车夫赔笑道：“您的零钱不够了，银票又没人找得开。”\n");
	default:
		tell_object(who, "车夫笑眯眯地说道:我这就为你准备马车。\n");
	}

	message_vision(HIR "车夫驾着一辆马车来到$N的跟前,说道:请上车!!\n" NOR,who);
 	who->move(__DIR__"che");
	che->set("youren",1);
	tell_object(who, make_msg[0]);
       	remove_call_out("gozhan");
	call_out( "gozhan", time[arg], who, 1, arg,che);

       	return 1;

}

int gozhan(object who, int stage,string arg,object che)
{
	int len;

	len=sizeof(make_msg);

	tell_object(who, make_msg[stage]);
	if( ++stage < len )
	{
		call_out( "gozhan", time[arg], who, stage ,arg,che);
	        return 0;
	} 

	tell_object(who,HIG "到站了!\n" NOR);
        if (who->move(yizhan[arg]))
	{
		che->delete("youren");
		return 1;
	}

	who->move(VOID_OB);
	return notify_fail("车夫晕晕乎乎把你带到一个陌生的地方。\n");
}               

int do_look(string arg)
{
	string *zhan,str;
	object who;
	int i;

	if(arg=="paizi")
	{
		zhan=keys(yizhan);
		who=this_player();
		i=sizeof(zhan);

		tell_object(who,"现有车直达(qu)全国如下地方:\n\n");
		while(i--)
		{
			str=sprintf("%12s   需纹银:%4d两\n",zhan[i],time[zhan[i]]*BASE_MONEY/100);
			tell_object(who,str);
		}
		return 1;
	}

	return 0;
}