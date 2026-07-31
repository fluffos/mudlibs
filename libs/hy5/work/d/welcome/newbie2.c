// Room: /d/welcome/newbie2
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "ĞÂÊÖÑµÁ·ÊÒ");
  set ("long", @LONG
ÏÖÔÚÎÒÃÇ¼ÙÉèÄãÒÑ¿´ÍêĞÂÊÖÖ¸ÄÏ£¬¹ØÓÚ³ÔºÈ°İÊ¦µÈÊÂÎÒÃÇ¾Í²»ÔÙ¶àËµ
£¬ÒªËµµÄÖ»ÊÇ¹ØÓÚº£ÑóµÄÒ»Ğ©·¢Õ¹·½Ïò¡£ÇëÄãÏÈÇë¿´¿´ÉíÉÏ´øµÄÄÇ±¾ÓÎÏ·
ÊØÔò£¬ÀïÃæ¼ÇÔØ×Å±¾ÓÎÏ·µÄÒ»Ğ©ÖØÒªÊØÔò£¬ÇëÒ»¶¨ÒªÅ¬Á¦ÅäºÏ£¬²»Òª¸ø´ó
¼Ò´øÀ´²»±ã¡£±¾ÓÎÏ·ÓÃ[1;33mhelp whatsnew[2;37;0mÀ´¼ÇÂ¼×î½üµÄ¸üĞÂĞÅÏ¢£¬ÇëÄãÃ¿´Î½ø
ÓÎÏ·À´Ê±Îñ±ØÒª¿´Ò»´Î£¬ÒÔÃâÒòÓÎÏ·µÄ¸üĞÂ¸øÄã´øÀ´ÒâÏë²»µ½µÄËğÊ§¡£
LONG);

  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"newbie3",
  //"oldplayer" : "/d/city/kedian",
]));
  set("no_beg", 1);
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
