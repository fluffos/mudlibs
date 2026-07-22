// Room: /d/emei/qingyinge.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "清音阁" NOR);
	set("long", @LONG
这里是峨嵋山的清音阁。此阁位于牛心岭下，东有白龙江，西有黑龙江，
两江之水交汇于清音阁下。江上有拱桥两座，分夸黑龙白龙二江，这就是双飞
桥。两江合流处，有一数米高的黑褐色巨石傲然挺立，形似牛心，名之为「牛
心石」。桥边立有一石碑(shibei)。由此向西上，左行是黑龙江栈道，右路至
白龙洞，东去中峰寺。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([
  "northwest" : __DIR__"bailongdong",
  "southwest" : __DIR__"heilongjiangzd",
  "southeast" : __DIR__"zhongfengsi",
]));
	set("objects",([
		CLASS_D("emei") + "/jing-xian" : 1,
		"/d/emei/npc/dizi" : 1,
]));
	set("item_desc", ([
  "shibei" : "石碑刻有一诗曰：

　　　　　　　\t\t杰 然 高 阁 出 清 音，

              \t\t仿 佛 仙 人 下 抚 琴。

　　　　　　　\t\t试 向 双 溪 一 倾 耳，

              \t\t无 情 两 水 漱 牛 心。


\t   这就是“峨嵋十景诗”中专咏这“双桥清音”的诗\n",
]));
	setup();
}
void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
}
int do_jump(string arg)
{
	object me = this_player();

	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");

	if(!arg || arg == "" || arg != "牛心石")
	return notify_fail("你要跳什么？\n");
	
	if( arg == "牛心石") {
	     message_vision("$N往江心的牛心石跳了过去。\n", me);
             if(me->query_skill("dodge", 1)<30&&me->query_dex()<28){
                      message_vision(HIY"结果$N一脚踩空，掉了下去！\n"NOR, me);
                      me->move(__DIR__"shuitan");
                      message_vision(HIC"只听得扑通一声，$N从上面掉了下来，落进了大水潭中，咕嘟咕嘟喝了好几口水....\n"NOR, me);
                      me->unconcious();
                      me->set("water", 500);
                      return 1;
                      }
	     me->move(__DIR__"niuxinshi");
             me->add("jingli", -200);
	     message_vision("$N从清音阁跳了过来。\n", me);
             me->start_busy(1);
             }
	     return 1;
}
	
