// Room: /d/huizhu/xinxin
inherit ROOM;

void create()
{
  set ("short", "星星峡");
  set ("long", @LONG
转眼之间,石壁越来越近,一字排开,直伸出去,山石间云雾弥漫
似乎其中别有天地，再奔近时，忽觉峭壁中间露出一条缝来,那便
是甘肃和回疆之间的交通孔道星星峡。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xianei",
  "northeast" : __DIR__"shamo",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
