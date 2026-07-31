inherit ROOM;

void create()
{
  set("short","寺庙");
  set("long",@LONG
这里是无名之山的无名之庙。正中供奉着如来三宝，左右各是
文殊、普贤菩萨。一群青衣小和尚们正在佛像前的地上诵经。
缕缕香烟与梵唱交错在一起，仰视佛祖拈花浅笑的面容，令人顿
时生起几分脱俗之感。
LONG);
  set("outdoors","yinju");
set("exits",([
   "north"  : __DIR__"dadian",
  "east"  : __DIR__"shiliang",
        ]));
  setup();
}