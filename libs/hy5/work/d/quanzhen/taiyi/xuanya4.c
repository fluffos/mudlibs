//Cracked by Kafei
// road: /zhongnan/xuanya4.c
// by sdong 08/98

inherit ROOM;
#include <ansi.h>
int do_climb(string arg);

void create()
{
		  set("short",HIW"崖顶"NOR);

		  set("long",@LONG
崖顶是个巨大的平台，积满了皑皑白雪。正中立着一块石碑，上面似乎刻着一首
词(ci)。站在崖顶往四周望去，但见平烟茫茫，一望无尽的沙漠消失在天边，说不尽
的潇潇之意，几只巨大的黑雕在空中来回盘旋。
LONG);

		  set("item_desc",(["ci" : "


		念奴娇。塞外怀古

			 董晓

    大风东去，霜灭尽，千里华树碧草。巨崖凌空，看
河山，潇潇一片。神雕击风，声振云霄，盘旋万里独雄。
塞外秋漠，千里人烟灭。

    遥想范公当年，旌旗百万，雄风镇西关。银枪铁骑，
儒将不减英风，叱诧间，胡虏胆丧心裂。故人安在？斯地
羌笛犹鸣。人生纵短，此身莫徘徨。


\n",]));

		  set("exits",([
	"east": __DIR__"fengdong",
	"west": __DIR__"bingdong",
							 ])
			  );
	  set("cost",4);
set("outdoors", "quanzhen");
	  setup();
}

void init()
{
	add_action("do_climb", "climb");
}


int do_climb(string arg)
{
	object me = this_player();
	int gain,cost;

	if(me->is_busy())
		return notify_fail("你还在忙着呢。\n");

	if(arg != "down" )
		return notify_fail("那个方向没法爬。\n");

	cost = ( 300-me->query_dex()*me->query_skill("dodge")/20 )/10;
	if ( cost<10 )cost = 10;
	cost *= 2;

	if( me->query("jing") < 30)
		return notify_fail("你累的实在爬不动了。\n");

	me->add("jing",-cost);
	gain = me->query("con",1)*2;
	gain *= 2;

	if ( me->query_skill("dodge") > 300 ) gain /= 2;

	me->improve_skill( "dodge",random( gain ) );
	if( me->query_skill( "jinyan-gong",1) > 0 )
		me->improve_skill( "jinyan-gong",random( gain ) );


	message_vision( HIY"\n$N在悬崖上攀藤附葛，小心谨慎的爬下去。\n"NOR, me);
	me->move(__DIR__"xuanya3");
	message_vision( HIY"\n$N爬了下来。\n"NOR, me);
	return 1;
}




