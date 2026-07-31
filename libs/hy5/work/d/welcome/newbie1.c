// Room: /d/welcome/newbie1
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "ĞÂÊÖÑµÁ·ÊÒ");
  set ("long", @LONG
Èç¹ûÄã¶Ç×Ó¶öÁË¿ÉÒÔ(eat)£¬¿ÊÁË¿ÉÒÔ(drink)£¬µØÉÏÓĞ¶«Î÷Äã¿ÉÒÔ
(get)£¬µ±È»£¬Äã×îºÃ»¹ÊÇÈ¥Âò(buy),ÄãÒ²¿ÉÒÔ°ÑÄã²»ÓÃµÄ¶«Î÷µ±µô£¬
(sell),Èç¹ûÄãÀÛÁË£¬¿ÉÒÔË¯ÉÏÒ»¾õ(sleep)£¬µ±È»Äã±ØĞèÕÒµ½ÄÜË¯¾õµÄ
µØ·½¡£
º£ÑóµÄÈëÊÀÖ®Â·ÊÇÒ»Ìõ»ìãçÖ®Â·£¬ÕâÂ·Í¨ÏòµÄÊÇ¹î±äµÄ½­ºş£¬ÎªÁËÄã
ÄÜÔÚ½ñºóµÄ½­ºşÂ·ÉÏ¹ıµÃÒ»·«·çË³£¬½¨ÒéÄãÏÈ¿´Ò»±é[1;33mhelp newbie[2;37;0m£¬ÔÚÄÇ
ÀïÃæÏêÏ¸µÄ½âËµÁËÒ»¸öĞÂÊÖÔÚÄàÌ¶ÖĞµÄÉú´æÖ®µÀ¡£ÒªÈëÊÀ£¬¿´ËüÊÇ±Ø²»¿ÉÉÙ¡£
LONG);

  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"newbie2",
 // "oldplayer" : "/d/city/kedian",
]));
  set("no_beg", 1);
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
