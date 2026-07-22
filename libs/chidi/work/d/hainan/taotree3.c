// Room: /d/hainan/taotree3
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "ÌÒ»¨ÁÖ");
  set ("long", @LONG
Ò»Æ¬Ñ¤ÀÃµÄÌÒ»¨ÁÖ,ÕýÖÐÓÐÒ»¸ö´óÀíÊ¯Æö³ÉµÄË®³Ø,ËÄ±ßÊÇÂÌÒð²ÝµØ, 
°×É«µÄÕôÆû´ÓË®³ØÖÐÃ°³öÀ´,°ÑÕâµØ·½ÅªµÃÃÉÃÉëÊëÊ,¿´À´ÊÇ[31mÎÂÈª[37mÁË,ÔÚ°× 
ÎíÖÐ,ËÆºõÓÐ¼¸¸öñºñ»ÉíÓ°. 
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "ÎÂÈª" : "ÃÉÃÉµÄÎíÆøÁýÕÖ×ÅÎÂÈªË®³Ø,¿´À´Ï´¸öÔèÊÇ¸öºÃÖ÷Òâ!
Ïë×Å,Äã¶¼¿ìÈÌ²»×¡ÒªÌøÏÂÈ¥ÁË(jump down)!
",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ziyun.c" : 1,
]));
  set("outdoors", "/d/hainan");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"outtree2",
  "south" : __DIR__"taotree1",
]));

  setup();
}
void init()
{
    add_action("do_jump", "jump");
}

int do_jump(string sss)
{object ob;
 ob=this_player();
  if (sss!="down") return 0;
  message_vision("$N·É¿ìµØÍÑµôÒÂ·þ,àÛÍ¨Ò»ÉùÌøÏÂÁË"+RED+"ÎÂÈª!\n"+NOR,ob);
  tell_room("/d/hainan/wenquan.c",ob->query("name")+"ÌøÁËÏÂÀ´,½¦ÆðÒ»Æ¬Ë®»¨!\n");
  ob->move("/d/hainan/wenquan.c");
return 1;
}
