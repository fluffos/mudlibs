//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "飞瀑");
        set("long",@LONG
在你面前是飞流直下三千尺的瀑布，见到这么长的瀑布，
你不由想去试试挥剑断水！
瀑下传来一阵悠扬的琴声，叫人忍不住想跳下(jump)一瞅究竟。
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"houshan",
        ]));
       set("objects", 
        ([ //sizeof() == 1
            __DIR__"npc/qingmu" : 1,
        ]));
        set("outdoors", "shushan" );
        setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump()
{
	int hm = 0;
	object me = this_player();
	if( me->query("family/family_name")=="蜀山派" )
	{
		if( random(me->query_skill("dodge"))<250 )
			hm = 1;
		if( me->query_skill("jiefeng",2)>300 )
			hm = 0;
	}
	else
	{
		if( random(me->query_skill("dodge"))<390 )
			hm = 1;
		if( me->query_skill("jiefeng",2)>350 )
			hm = 0;
	}
	message_vision("$N伸头踮脚朝崖下小心的望了望，深吸一口气，纵身跃下！\n\n",me);
	me->move(__DIR__"yaxia");
	if( hm==1 )
	{
		tell_object(me,"糟糕！凌空而下，你一口真气不畅，如断线风筝从半空一个倒栽葱跌了下去！\n\n");
		message("vision","一道人影从半空中大头朝下摔了下来！\n",environment(me),me);
		me->unconcious();
	}
	else
	{
		tell_object(me,"你凌空而下，宛如一只飞燕从半空一个轻轻松松落了下来！\n\n");
		message("vision","一道人影从半空中飞落而下，稳稳当当的落在地上！\n",environment(me),me);
	}
	return 1;
}