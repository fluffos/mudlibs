// piandian.c 偏殿
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "偏殿");
        set("long", @LONG
这里是大堂旁边的一个侧厅，也是接待重要客人的地方。厅不
大，只摆放着一张桌子和几把椅子。桌上摆放着一盆青山隐隐的盆
景，墙壁上挂着一些字画。一幅字(zi)挂在当眼处。
LONG
        );

		  set("item_desc",(["zi" : "
			
			安 仰 万 天
			得 天 灵 苍
			大 大 日 苍    常
			千 叫 夜 兮
			复 天 相 临    春
			混 不 凌 下
			饨 应 迟 土
			， ， ， ，
			免 一 引 胡    常
			叫 物 气 为    春
			造 细 吞 不    子
			物 琐 声 救    丘
			生 枉 死 万    处
			精 劳 无 灵    机
			灵 形 语 苦    
			。 。 .  ?     题
			
		\n",]));
        set("exits", ([
                "east" : __DIR__"nairongdian",
                "west" : __DIR__"xianzhentang",
                "north" : __DIR__"datang2",
                "south" : __DIR__"guangning",
        ]));
        set("objects", ([
                __DIR__"npc/shen" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
