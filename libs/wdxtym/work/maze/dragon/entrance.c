inherit ROOM; 
#include <ansi.h> 

void create()
{
      set("short","Çà²İÆº");
      set("long",
"[1;32mËÉÁÙÓê¹ıÇà£¬»¨Ïò´ºÀ´ÃÀ¡£·çÖĞÓĞµ­µ­µÄÓÄÏã¡£Ô¶Ô¶¿É¼ûÉ½\n"
"ÉÏÏéÔÆÈğÈğ£¬²ÊÏ¼ÈçÁ·ºç¡£µØÉÏ»¹ÓĞÒ»¸öÈªÑÛ£¬µ«¿´ÆğÀ´ËÆºõÒÑ¾­¸ÉºÔÁË¡£\n"
);
      set("exits",([ 
           "north"  : __DIR__"spirit4",
      ]));
      set("objects",([
      ]));
      set("no_magic", 1);
	setup();
}

