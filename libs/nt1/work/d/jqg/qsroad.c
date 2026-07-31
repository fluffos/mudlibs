//qsroad.c 青石板路
inherit ROOM;
void create()
{
          set("short","青石板路");
	  set("long",@LONG
对于走惯了泥土路的人来说，眼前这条青石板倒是很有意思，又湿又滑。
在每块石板的间隙之中，长满了绿色的青苔。一只白鹤施施然地独足立于青石
板上，不时地用嘴梳理着自己的毛羽，神情煞是可爱。北面隐约看出是一座大
石屋。
LONG
);
          set("outdoors","绝情谷"); 
	  set("exits",([
              "eastup": __DIR__"shuitang",
              "north": __DIR__"shiwu",
          ]));
          setup();
	  replace_program(ROOM);
}
