// Room: /d/dzd/pubu.c

#include <ansi.h>
inherit __DIR__"dzd_room";

void create()
{
	set("short","瀑布");
	set("long",@LONG
一条巨大的水帘从山上飞流而下，形成一个瀑布。犹如一串高挂在深山老林中的珍珠
项链，又像一幅素绢挂在悬崖前。那飞溅的水露，在山前飘扬，百米之内白蒙蒙一片，常
年飘忽不散，天晴之日，五彩缤纷，光彩夺目，使人如入浑沌迷蒙仙境。透过水雾，隐隐
可看见一个洞口。
LONG
	);
	set("outdoors","大智岛");
	set("exits",([
		"east" : __DIR__"senlin6",	
		"south" : __DIR__"xiliu3",
		"southwest" : __DIR__"caodi3",
	]));
}

void init()
{
	::init();
	add_action("do_tiao","tiao");
}

int do_tiao(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if(!arg || arg == "" || arg!="pubu")
		return notify_fail("你想往哪儿跳？\n");

	message_vision(HIC"$N纵身提气，朝着瀑布的方向飞跃而去！\n"NOR, me);
        if ( me->query_dex() < 40 || me->query("neili") < 2000 ){
          write(HIR"\n你忽然感觉水势甚急，自己无法运气和水流相抗，被激流挤压的左摇右幌。\n"NOR);
          tell_room(environment(me), HIR"\n只听见「砰」的一声，"+me->name()+"犹如稻草一般被瀑布湍急的水流给反弹了出来。\n"NOR, ({ me }));
          me->unconcious();
          return 1;
        }

        me->move(__DIR__"rukou");
        message_vision(HIW"\n$N纵身提气，跃进了瀑布之中，使了个「千斤坠」身法，气沉下盘，稳稳站住。\n"NOR, me);
        return 1;
}
	