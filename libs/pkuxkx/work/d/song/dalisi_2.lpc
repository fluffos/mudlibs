inherit "/d/song/song_extra_room";
#include <ansi.h>

void create()
{
        set("short", "宗卷室");
        set("long", 
"这里大理寺的宗卷室。\n"

        );
        set("exits", ([
                "out" : __DIR__"dalisi2",
                
                
        ]));
		set("at_hangzhou",1);
        //set("outdoors", "yingtianfu");
        setup();
   
}

void init()
{
	add_action("do_fuhe","fuhe");
	add_action("do_pifu","pifu");
}
int do_pifu(string arg)
{
	object me=this_player();
	if (!me->query_temp("songtasks/dalisi/fuhe"))
		return notify_fail("你尚未阅读宗卷，怎么批复？\n");
	if (!arg)
		return notify_fail("你要批复什么内容？\n");
	if (me->query_temp("songtasks/dalisi/1/finish"))
		return notify_fail("批复过赶紧回大理寺卿那里复命吧。");
	message_vision(HIC+"$N"+HIC+"在宗卷上挥笔写下了『"+HIR+arg+HIC+"』几个大字。\n"+NOR,me);
	if (arg!=me->query_temp("songtasks/dalisi/fuhe"))
	{
		me->add("song/credit",-2);
		me->delete_temp("songtasks");
		tell_object(me,RED+"你的批复内容被上峰打回了，你的大宋功勋下降了。\n"+NOR);
		return 1;
	}
	me->set_temp("songtasks/dalisi/1/finish",1);
	tell_object(me,HIC+"批复完成，回大理寺卿那里复命吧。\n"+NOR);
	return 1;
}
int show_case(object me,string msg)
{
	tell_object(me,"当下你心中已有了决断，\n");
	ANTIROBOT_D->mxpantirobot_ex(me,msg);
	tell_object(me,"快快批复(pifu <决断内容>)吧。\n"+HIW+"pifu 图片内容即可。"+NOR+"\n");
	return 1;
}
int do_fuhe()
{
	object me=this_player();
	string *msg1=({"复杂","清晰","简单","离奇","明白",});
	string *msg2=({"发回","重审","重判","轻判","开释",}),msg;
	if (me->query_temp("songtasks/dalisi/task")!=1)
	{
		return notify_fail("没有大理寺卿的许可，不许擅自接触大理寺的宗卷。\n");
	}
	if (me->query_temp("songtasks/dalisi/fuhe"))
	{
		return notify_fail("没有大理寺卿的许可，不许擅自接触大理寺的宗卷。\n");
	}
	msg="案情"+msg1[random(sizeof(msg1))]+"建议"+msg2[random(sizeof(msg2))];
	me->set_temp("songtasks/dalisi/fuhe",msg);
	message_vision("$N打开了一份宗卷，细细查阅……\n",me);
	call_out("show_case",2,me,msg);
	return 1;
}