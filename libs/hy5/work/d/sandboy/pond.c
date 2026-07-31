// Room: /d/sandboy/pond 
inherit ROOM; 
 
void create ()
{
  set ("short", "小池塘");
  set ("long", @LONG
淡绿色的浮萍点点在水面上,靠近岸的地方,一架老水车静静地立在那
里,东面是一望无际的金色田野,几条田埂穿插其间,向西去是一片青青草地.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/watercart.c" : 1,
]));
set("outdoors","/d/jiangnan");
  set("item_desc", ([ /* sizeof() == 1 */
  "水车" : "用脚踏动时,能把水从池塘中抽取到水田中.
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road1",
  "west" : __DIR__"turf",
]));

  setup();
}
void init()
{
   add_action("do_jump","jump");
}
int do_jump(string arg)
{
  object player;
  player=this_player();
if (!arg||(arg!="池塘"&&arg!="down")) return 0;
if (living(player)&&environment(player)==this_object())
      {
         write(player->name()+"噗通一声跳落池塘,溅起老高水花.\n");
         tell_room(__DIR__"inpond","有人如同一块大石般跳入水中.\n");
         player->move(__DIR__"inpond");
        return 1;
       }
 return 0;
}
