// room: dong-2.c
// zqb


inherit ROOM;
#include <ansi.h>
string look_bei();
void create()
{
        set("short", HIR"ÌìÈ»¶´Ñ¨"NOR);
        set("long", @LONG
    ÕâÊ¯¶´ÏµÌìÈ»Éú³É£¬½ÏÖ®ÍâÃæÈË¹¤¿ªÔäµÄÊ¯ÊÒ´óÁËÊ®À´±¶¡£·ÅÑÛÍû
È¥£¬¶´ÄÚ¹²ÓĞÊ®Óà¾ßº¡¹Ç£¬»ò×ö»òÎÔ£¬ÉñÌ¬¸÷ÓĞ²»Í¬£¬ÓĞµÄº¡¹ÇÉ¢¿ªÔÚµØ£¬
ÓĞµÄÈ´ÈÔ¾ßÍêºÃÈËĞÎ£¬¸üÓĞĞ©¹ÇÌ³ÁéÎ»Ö®Êô¡£Ã¿¾ßº¡¹ÇÖ®ÅÔ¶¼·Å×Å±øÈĞ£¬°µ
Æ÷£¬ÓÃ¾ß£¬Õä±¦µÈÎï¡£¶´¿Ú´¦Á¢×ÅÒ»×ùÊ¯±®(bei)¡£
LONG
        );
        set("exits", ([
            "out" : __DIR__"dong-3",
        ]));
        set("item_desc",([
        "bei"         :       (: look_bei :),
    ]));

        set("objects", ([
           
        __DIR__"obj/haigu" : 1,  
        __DIR__"obj/ycj" : 1,      
        ]));

        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}
string look_bei()
{
        return
        "\n"
"    Ì   ÉÃ¶¯ÊÒÄÚÎïÆ·Õß\n"    
        "\n"
RED"        ËÀÉËÄª¹Ö£¡    \n"NOR
        "\n";
}
void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
      object me;
      me=this_player();

      if ((int)me->query_temp("marks/baowu")) 
      {
      if ((int)me->query_str() < 30)
          return notify_fail("ÄãµÄÁ¦Á¿²»¹»£¬ÎŞ·¨½«Ê¯±®ÍÆ¿ª¡£\n");
      if (arg !="bei") 
          return notify_fail("ÄãÒªÍÆÊ²Ã´£¿£¿\n");
      write("ÄãÔúÏÂÂí²½£¬ÉîÉîµÄÎüÁË¿ÚÆø£¬½«Ê¯±®»º»ºµÄÏòÅÔÍÆ¿ª¡£\n");
      message("vision",me->name() + "Ë«°òÓÃÁ¦£¬Æø³Áµ¤Ìï£¬Ê¯±®»º»ºÏòºóÒÆ¿ª£¬ÏÂÃæÂ¶³öÒ»¸öºÚ¶´¶´µÄÈë¿Ú¡£\n", environment(me),({me}));
      set("exits/enter", __DIR__"taijie-1");
      remove_call_out("close_passage");
      call_out("close_passage", 5);
      return 1;
      }
      return notify_fail("ÕÒËÀ°¡£¡\n");
}


void close_passage()
{
      object room;

      if( !query("exits/enter") ) return;
      message("vision", "Ê¯±®·¢³öÂ¡Â¡µÄÉùÒô£¬»º»ºÒÆ»ØÔ­´¦¡£\n", this_object() );
      delete("exits/enter");
}


