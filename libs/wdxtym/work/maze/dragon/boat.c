inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "Óæ´¬ÖĞ");
        set("long",
"[1;32mÒ»Ò¶Ğ¡ÖÛÆ¯¸¡ÔÚºşÃæÉÏ£¬ËÄÖÜÈºÉ½»·ÈÆ£¬·ç¾°Ê®·ÖÓÅÃÀ¡£Ğ¡\n"
"ÖÛºÜĞ¡£¬½ö¿É³Ë×øÒ»ÈË£¬µ«½¨ÔìµÄÊ®·Ö¾«ÖÂ²¢ÇÒÀÎ¹Ì£¬ÖÛÉÏºá·Å×ÅÒ»¶Ô½¬¡£\n"
);
        set("objects",([
                ]));
 
        set("no_fight", 1);
        set("no_magic", 1);
	setup();
}   

void init()
{
   add_action("do_sail", "sail");
   add_action("do_dive", "dive");
}

int do_dive()
{
   object me, room;
   me = this_player();

   if(me->query_temp("marks/gateplace")) {
      message_vision("$NÕ¾ÆğÉíÀ´£¬ÉîÎüÒ»¿ÚÆø£¬Ò»¸öÃÍ×ÓÔúµ½ÁËºşÀï¡£\n\n", me);
      room = find_object(__DIR__"gongmen");
      if(!objectp(room))  room = load_object(__DIR__"gongmen");
      me->move(room);
      return 1;
   }
   return 0;
}

int do_sail()
{
   object me, land;
   int slvl;
   
   me = this_player();
   slvl = (int)me->query_str();
   land = find_object(__DIR__"lake2");
   if(!objectp(land))
      land=load_object(__DIR__"lake2");
   if (query("exits/up")) return 0;
   if(me->query_temp("m_success/Óã¹Ö")) {
      if(me->query_temp("marks/gateplace")) {
         message_vision("$NÇáÓ¯µØ»®×ÅĞ¡´¬£¬»º»ºµØ¿¿µ½ÁËºş±ß¡£\n",me);
         message("vision",me->name()+"ÇáÓ¯µØ»®×ÅĞ¡´¬£¬»º»ºµØ¿¿µ½ÁËºş±ß¡£\n",land); 
         me->delete_temp("marks/gateplace");
         set("exits/up", __DIR__"lake2");
         land->set("exits/down", __DIR__"boat"); 
         call_out("boat_leave", 10, land);
         return 1;
      }
      message_vision("$N³­Æğ´¬½¬ÇáÓ¯µØ°ÑĞ¡´¬»®ÏòºşµÄ¶«±±·½¡£\n", me);
      me->set_temp("marks/gateplace", 1);
      me->start_busy(3);
      return 1;
   }
   if(random(150) < slvl) {
      message_vision("Ğ¡´¬»º»ºµØ¿¿µ½ÁËºş±ß¡£\n", me);
      message("vision",me->name()+"»®×ÅĞ¡´¬£¬»º»ºµØ¿¿µ½ÁËºş±ß¡£\n",land); 
      set("exits/up", __DIR__"lake2");
      land->set("exits/down", __DIR__"boat"); 
      call_out("boat_leave", 10, land);
      return 1;
   }
   message_vision("$NÂşÎŞÄ¿µÄµÄÔÚºşÉÏ»®×ÅĞ¡´¬¡£ \n", me);
   return 1;
}

void boat_leave(object land)
{
   if (query("exits/up")) delete("exits/up");
   if (land->query("exits/down")) land->delete("exits/down");
   message("vision","Ò»ÕóÎ¢·ç·÷¹ı£¬Ğ¡´¬µ´ÀëÁË°¶±ß¡£\n",this_object()); 
   message("vision","Ò»ÕóÎ¢·ç·÷¹ı£¬Ğ¡´¬µ´ÀëÁË°¶±ß¡£\n",land); 
}

