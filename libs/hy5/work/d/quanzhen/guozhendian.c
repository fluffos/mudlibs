// guozhendian.c 过真殿
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "过真殿");
        set("long", @LONG
这里是大堂旁边的一个侧殿，也是接待重要客人的地方。殿不
大，只摆放着一张桌子和几把椅子。桌上摆放着一盆青山隐隐的盆
景，墙壁上挂着一些字画。从这里往北，好象有一座四层的小塔。
一幅字(zi)挂在当眼处。
LONG
        );
		  set("item_desc",(["zi" : "

		金 过 先 大
		锁 膝 从 道  全
		关 徐 涌 初  真
		穿 徐 泉 修  大
		下 至 脚 通  道
		鹊 尾 底 九  歌
		桥 闾 冲 窍
		， ， ， ,
		重 泥 涌 九
		楼 丸 泉 窍
		十 顶 升 原
		二 上 起 在
		降 回 渐 尾
		宫 旋 至 闾
		室 急 膝 穴
		.  .  .  .

\n",]));

        set("exits", ([
                "south" : __DIR__"datang3",
                "west" : __DIR__"cetang",
                "north" : __DIR__"cundaota1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
