// Room: /d/beijing/zijin/taihedian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"太和殿"NOR);
	set("long",
HIC"这里就是人们俗称的“金銮殿”，重檐四阿庑殿顶，彩画双龙合玺大点
金。殿内共有六根蟠龙金漆柱，居中约两米高的平台上设有一张楠木金漆雕
龙宝座，座上放置髹金龙椅，椅后竖髹金雕龙屏风。宝座左右有对称的宝象、
角端、仙鹤、香筒等制品。殿顶正中为穹隆圆顶，又称藻井，井内巨龙蟠卧，
口衔宝珠，叫轩辕镜。镜下正对宝座。地面上铺着金砖，整个宫殿被映照得
金碧辉煌，华丽无比。
    在九阶白玉的台阶上， 皇上坐在金色的龙椅(chair) 上，俯视众臣。
四名带刀侍卫小心的注意任何可能发生的情况。 群臣匍俯在地，三呼 “万
岁！ 万岁！万万岁！”。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"zhonghedian",
  	"south" : __DIR__"guang1",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
  	"chair" : "这是一张宽大红木龙椅， 椅背上雕着九龙戏珠的图案。你仔细一看，这颗珠子竟然是夜明珠。\n",
	]));
	set("objects", ([ /* sizeof() == 1 */
//  	"/d/beijing/npc/long" : 1,
  	"/d/beijing/npc/kangxi" : 1,
        "/d/beijing/npc/suoetu" : 1,
	]));
//	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
