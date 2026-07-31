inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "崖下");
        set("long",@LONG
抬头看去，只见飞流直下三千尺的瀑布带着轰鸣之声，从上而下奔腾而下，激起层层飞沫。
轰隆隆的水声中隐约传来一阵悠扬的琴声。
    脚下一条幽深小径，朝前延伸，重叠丛林深处好似伫立数栋草庐。
    峭壁之上，相隔数丈便有一个小坑，看来可以借力飞上(jump)崖顶。
LONG
        );
        set("exits", ([
                "north" : __DIR__"caolu",
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
	if( me->is_busy() )
		return err_msg("你现在正忙着呢。\n");
	
	if( me->query("family/family_name")=="蜀山派" )
	{
		if( random(me->query_skill("dodge"))<100 )
			hm = 1;
		if( me->query_skill("jiefeng",2)>200 )
			hm = 0;
	}
	else
	{
		if( random(me->query_skill("dodge"))<150 )
			hm = 1;
		if( me->query_skill("jiefeng",2)>250 )
			hm = 0;
	}
	message_vision("$N抬头朝崖上小心的望了望，深吸一口气，脚尖点地，纵身跃起！\n\n",me);
	if( hm==1 )
	{
		tell_object(me,"糟糕！你一口真气不畅，落脚没站住，如断线风筝从半空一个倒栽葱跌了下去！\n\n");
		message("vision",me->name()+"一口真气不畅，落脚没站住，如断线风筝从半空一个倒栽葱跌了下去！\n\n",environment(me),me);
		me->start_busy(3);
		me->receive_wound("kee",300);
		COMBAT_D->report_status(me,1);
	}
	else
	{
		me->move(__DIR__"feipu");
		message_vision("$N脚下连连借力，宛如一只大雁从崖下跃了上来。\n\n",me);
	}
	return 1;
}
	
									