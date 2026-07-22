// Room: luofenggang.c 落风岗

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "落风岗");
	set("long", @LONG
这里是个向阳的山冈，一面是几十丈高的陡坡，另一面是峡谷。陡坡上厚厚
的雪层被阳光照耀而渐渐融化，加上常年山风猛烈的吹拂，这里经常发生大大小
小的雪崩，平日这里轻易是没人来的。
LONG
	);
	set("exits", ([
		"east" : __DIR__"fengjiantai",
	]));

	set("coor/x",-310);
  set("coor/y",150);
   set("coor/z",10);
   setup();
}
void init()
{
//add_action("do_say","say");
        add_action("do_jump", "tiao");
        message_vision(HIW"“噗”的一声，一个小雪球砸在你头上，碎了开去。\n"NOR,this_player());
}
int do_say()
{
       object *ob,thisroom,room;
       int i;
       thisroom = find_object(__DIR__"luofenggang");
       room = find_object(__DIR__"xuegu");       
       message_vision(HIW"$N刚说出一个字，突然耳旁“轰隆隆”犹如万马奔腾，抬头望去，只见坡顶上
 大块大块的积雪势如奔雷滚将下来。\n\n"+HIR"雪崩了！\n\n"+
HIW"在这天地剧变之时，人人仿佛汪洋中的一叶小舟，无可抗拒......\n\n
飞奔的积雪象大浪一样把你推到在地......"NOR, this_player());
	ob = all_inventory(thisroom);
	for(i = 0; i < sizeof(ob); i++) {
		if (living(ob[i])) {
	tell_object(ob[i],HIW"你从山上滚落下去。\n"NOR);
	ob->move(__DIR__"xuegu");
	tell_room(room,HIW+ob[i]->name()+"从山上滚落下来，啪的一声重重摔在地上。\n"NOR,({ob[i]}));
 if(ob[i]->query("combat_exp")<200000)
	ob[i]->unconcious();
	   }
	}
	return 1;
}
int do_jump(string arg)
{
       object me,room;
       me = this_player();
       room = find_object(__DIR__"xuegu");       
       if (arg != "down" || !arg )
           return 0;
       message_vision(HIW"$N深吸口气，双臂伸展凌空跃起，犹如一只大鸟向谷底落了下去。\n"NOR, me);
	me->move(__DIR__"xuegu");
message_vision( HIW "$N从空中急速落下，嗤的一声扎入厚厚的雪堆，转眼爬了出来，竟然没有受伤！\n"NOR,me);
	return 1;
}
