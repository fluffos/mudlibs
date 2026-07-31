inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "Ð¡ÎÝÀï");
        set("long",
"[1;32mÕâÊÇÒ»¼äÆÓËØµÄÐ¡Ä¾ÎÝ£¬ÎÝÖÐµÄ°ÚÉè¶¼ÊÇÐ©¼òµ¥±ØÒªµÄ¼Ò¾ß\n"
"¡£´°ÏÂÊÇÒ»ÕÅÐ¡¼¸£¬ÉÏÃæ·Å×ÅÒ»Ð©Ê³Îï¡£Ò»¸ö¾«Áé×åµÄÅ®×ÓÕýÔÚÎÝÖÐÃ¦Âµ\n"
"×ÅÊ²Ã´¡£\n"
); 
        set("objects", ([ 
            "/quest/tulong/npc/spiritgirl" : 1,
            "/quest/tulong/npc/kid" : 1,
          ]));        
        set("exits", ([ /* sizeof() == 4 */
           "east" : __DIR__"village",
   ]));

        setup();
//        replace_program(ROOM);

}

void init()
{
  add_action ("do_search","search"); 
}

int do_search (string arg)
{
  object who = this_player ();
  object where = this_object ();
  object hook;
 
        if (  present("hook", who) ) {
                return notify_fail("Äã²»ÊÇÒÑ¾­ÕÒµ½ÁËÂð£¿\n");
          }
  if (random(10))
  {
    message_vision ("$NËÄ´¦ËÑË÷ÁËÒ»·¬£¬Ê²Ã´Ò²Ã»ÓÐÕÒµ½¡£\n",who);  
  }
  else
  {
    hook = new ("/quest/tulong/obj/hook");
    message_vision ("$N°ÑÐ¡ÎÝµÄ´óÐ¡½ÇÂä¶¼ÕÒÁË¸ö±é£¬·¢ÏÖÁËÒ»¸öÐ¡¹³×Ó£¡\n",who,hook);
    hook->move(who);  
  }
  return 1;
}

