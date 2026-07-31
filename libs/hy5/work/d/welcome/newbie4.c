// /d/welcome/welcome.c
// º£ÑóII
// ĞÇĞÇ(lywin) 2000/6/4

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "ĞÂÊÖÑµÁ·ÊÒ");
  set ("long", @LONG
[1;32mÈç¹ûÄãÊÇÒ»¸öĞÂÊÖ¾Íµ½ÕâÀïÀ´¿´Ò»¿´°É£¬¶ÔÄãÒÔºóµÄÓÎÏ·ÓĞºÜ´óµÄ°ïÖú
ÄãËùĞèÒªµÄÓÎÏ·ĞÅÏ¢£¬ÕâÀï¼¸ºõÈ«²¿¿ÉÒÔÕÒµ½!Á¼ºÃµÄ¿ªÊ¼ÊÇ³É¹¦µÄÒ»°ë¡£[2;37;0m
[1;33m¼üÈëhelp ÊÇÍêÈ«µÄ°ïÖúÏµÍ³[2;37;0m
[1;33m¼üÈëhelp newbieÊÇĞÂÊÖÖ¸ÄÏ[2;37;0m
[1;33m¼üÈëhelp aboutquestÊÇÈÎÎñÖ¸ÄÏ[2;37;0m
[1;33m¼üÈëhelp questlist ÊÇÃØÃÜÁĞ±í[2;37;0m
[1;33m¼üÈëhelp menpaiÊÇÃÅÅÉ½éÉÜ[2;37;0m
[1;33m¼üÈëhelp mapsÊÇµØÍ¼´óÈ«[2;37;0m
[1;33m¼üÈëhelp whatsnewÊÇĞÂÔöÄÚÈİ[2;37;0m
[1;33m¼üÈëhelp workÊÇÖ°ÒµÏµÍ³[2;37;0m
[1;33m¼üÈëhelp featureÊÇ²é¿´±¾ÓÎÏ·µÄÌØÉ«¡£[2;37;0m
[1;33m¼üÈëhelp shuoming4ÊÇ³£ÓÃÂ·¾¶[2;37;0m
[1;33m¼üÈëhelp dazaoÊÇ´òÔìÎäÆ÷[2;37;0m
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"newbie1",
  //"oldplayer" : "/d/city/kedian",
]));
  set("no_beg", 1);
  set("valid_startroom", "1");
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
