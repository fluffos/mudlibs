//Cracked by Roath
// Room: /d/xiyou/nanhai/pool
inherit ROOM;

void create ()
{
  set ("short", "池塘边");
  set ("long", @LONG

池塘四周紫竹环绕，而塘边的空地上还长着几丛洁白的牡丹。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhulin15",
]));

  set("objects", ([ /* sizeof() == 1 */
//  "/d/wizz/cigar/npc/laoda" : 1,
  "/d/qujing/wuzhuang/npc/ludongbin" : 1,
]));

        set("no_fight", 1); 
        set("no_magic", 1); 
  setup();
}
