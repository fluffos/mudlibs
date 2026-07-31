//shanlu1.c
inherit ROOM;

void create()
{
  set("short","白驼蛇场");
	set("long", @LONG
这是白驼山庄所建的蛇场，从蛇谷捕捉来的毒蛇都在此饲养，四
周围以丈许来高的灰色圆墙，墙脚砌成圆弧形，光滑无缝。场里建了
许多蛇窝，由白驼山庄中的蛇奴负责管理，许多剧毒的怪蛇就是在此
杂交而得。
LONG
	);
  set("exits",([
      "east" : "/d/baituo/caomeide",
     ]));
  set("outdoors", "baituo");
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

