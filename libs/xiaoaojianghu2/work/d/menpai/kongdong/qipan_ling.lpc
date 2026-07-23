//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","棋盘岭");
	set("long",@LONG
这里巨石甚多，形状怪异，崖上大石怪突，洞穴奇特，内有石室，石门，石
床，石凳等，传为上古鲁真人修炼之所，道士赵真人曾临崖边，与一仙人对弈，
仙人予一棋子令吞，即成仙去，今岭上还有下棋石之遗迹。
LONG);
	set("exits",
	([
          "east" : __DIR__"shanmen",
	"west" : __DIR__"zixiao_ya",
          	]));
          	set("need_clean", "崆峒派");
        set("outdoors","kongdong");
        setup();
        //place_program(ROOM);
}
