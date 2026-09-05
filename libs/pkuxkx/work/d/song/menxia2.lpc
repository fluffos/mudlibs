// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
//#include "baoxiao.h"
void create()
{
	set("short", "门下省官厅");
	set("long", @LONG
这里门下省的官厅，几个给事中正在文件上署名，东西两面分别是两间耳房。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"south" : __DIR__"menxiacourt",
		"north" : __DIR__"menxia3",
		"west" : __DIR__"menxia4",//吏部
		"east" : __DIR__"menxia5",//礼部
	]));
	set("yamen_id","门下省");
	setup();
}

void init()
{
    add_action("do_baodao","baodao");
}

int spec(object me)
{
    string *special=({"风水","贪婪","文曲","突击","群战","鼓舞"});
    string *specialmark=({"fengshui","tanlan","wenqu","tuji","qunzhan","guwu"});
    int n;
    n=random(sizeof(special));
    me->set("song/special",specialmark[n]);
    tell_object(me,"听了官员的述说，你不禁觉得匪夷所思，官场居然有这么多潜规则。\n");
    tell_object(me,HIW"恭喜，你获得大宋官员的特技——【"+special[n]+"】\n"NOR);
    message( "channel:" + "baowei",HIR + "【大宋】" + me->query("name")+HIR+"大人资质非凡，悟出"+special[n]+"特技！\n"NOR,users());
}

int do_baodao()
{
    object me=this_player();
    message_vision("$N大声喊道：“报到！”\n",me);
    if (!DASONG_D->get_my_pin(me))
    {
        tell_object(me,"“报到？”官员满脸嘲讽地看着你，“报你大头，你哪来的呀？”\n");
        return 1;
    }
    if (me->query("song/special"))
    {
        tell_object(me,"你不是早就来报到过了吗？又来？\n");
        return 1;
    }
    else
    {
        tell_object(me,"官员道：大人您来了，我们做一点记录，马上就好。\n");
        message_vision(HIG"在等待的过程中，$N和官员们随意攀谈起来……\n"NOR,me);
        me->add_busy(5);
        remove_call_out("spec");
        call_out("spec",4,me);
        return 1;
    }
}