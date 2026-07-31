// Room: /d/pingan/pingankezhan
inherit ROOM;

void create ()
{
  set ("short", "古村客栈");
  set ("long", @LONG
这儿是古村中最有名的小客栈，说是最有名但也不大，只有小小的几个
店面，一个和气的店小二站在柜台前面，他笑脸相迎每一个来往的客人。因
为这儿的人没有高低贵贱，人人都是靠自己的劳动过活。不劳动是可耻的行
为。店铺前挂了一个小小的招牌（paizi）。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "本店急需工作人员，有意者请向小二打听[工作]的事。
",
]));

 set("roomif","$botten#工作|完工:ask xiao er about job|give panzi to xiao er$#");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"chufang",
"west" : __DIR__"tingtang",
  "south" : __DIR__"fight",
]));
  set("pingan", 1);
  set("chatroom",1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("no_dazuo", 1);
  set("no_kill", 1);
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}
