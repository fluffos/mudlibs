// Room: /d/emei/qianfoan.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "千佛庵" NOR);
	set("long", @LONG
此处是洪椿坪千佛庵。山间小坪坝，四面层峦叠障，峰环岭护；两侧深谷
幽岚，溪涧玲叮。坪上古木扶疏，亭亭如盖，山阴沁透，白雾飘游，极为幽静
清凉。此处常见雨雾霏霏，林中迷迷蒙蒙，乃山中雾气所为。正所谓「山行本
无雨，空翠湿人衣」。这就是誉为奇观的「洪椿晓雨」。此处殿美景幽，气象
新异，令人心醉。沿途南上是「九十九道拐」，北下经黑龙江栈道至清音阁。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"jiudaoguai1",
  "north" : __DIR__"heilongjiangzd2",
  "enter" : __DIR__"qianfoandd",
]));
	set("no_clean_up", 0);

	setup();
}
