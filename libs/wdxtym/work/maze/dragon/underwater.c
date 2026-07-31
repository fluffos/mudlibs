inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "Ì¶ÏÂ");
        set("long",
"[1;32mÌ¶Ë®ºÜÉî£¬±ùÁ¹µÄÌ¶Ë®½şµÃÄã¹ÇÍ·¶¼·¢Âé£¬Ò»Ö»ËæÄãÒ»¿ì¶ù\n"
"µôÏÂÀ´µÄĞàÄ¾Ò»ÆğÒ»·ü£¬ÔÚË®ÖĞµ´Ñú¡£Ò»ÏßÌì¹â´ÓÄãÍ·¶¥ÉÏÉäÏÂÀ´£¬ÄÇÑù\n"
"Î¢Èõ£¬Äã¶¼²»ÖªµÀ»¹ÓĞÃ»ÓĞÉú»¹µÄ»ú»á¡­¡­²»¹ı£¬»¹ÊÇÏë·¨×ÓÍùÉÏÅÀ(cli\n"
"mb)°É¡£\n"
);
        set("no_magic", 1);
	setup();
}

void init()
{
   add_action("do_climb", "climb");
   if(interactive(this_player()))
   call_out("do_flush",60,this_player());
}

int do_climb(string arg)
{
   object me, room;

   me = this_player();
   if(me->is_busy())
        return notify_fail("ÄãÏÖÔÚÃ»¿Õ£¡\n");
   switch (random(3)) {
   case 0:
      message_vision("$NÊÖ½Å²¢ÓÃµØÍùÉÏÅÀ£¬²ÅÅÀµ½Ò»°ë£¬Ò»Ê§ÊÖÓÖË¤ÁËÏÂÀ´¡£\n", me);
      me->receive_damage("jing",20);
        me->start_busy(5);
      break;
   case 1:
      message_vision("$NÊÖ½Å²¢ÓÃµØÍùÉÏÅÀ£¬ÑÛ¿´¿ìµ½Í·ÁË£¬½á¹ûÒ»Ê§ÊÖÓÖË¤ÁËÏÂÀ´¡£\n", me);
      me->receive_damage("jing",40);
        me->start_busy(5);
      break;
   case 2:
      if(!arg || arg != "ÉÏ" && arg != "up" ) return 0;
     room = find_object(__DIR__"spirit9");
     if(!objectp(room)) room=load_object(__DIR__"spirit9");
      me->move(room);
      message_vision("$N»ëÉíÊªÁÜÁÜµØ´ÓË®ÖĞÅÀÁËÉÏÀ´¡£\n", me);
      break;
   }
   return 1;
}

void do_flush(object me)
{
   object room;

   if(!me || environment(me) != this_object())
   return;
   tell_object(me,"\nÄãÍ»È»·¢¾õÌ¶ÀïµÄË®¾ÓÈ»ÔÚÁ÷¶¯£¡\n\n");
   tell_object(me,"Ë®Á÷ºÃÏó´ø×ÅÄã´ÓÌ¶µ×µÄÒ»¸ö°µµÀÀïÓ¿³ö¡­¡­\n");
   tell_object(me,"ÄãÏİÈëÒ»Æ¬ÍêÈ«µÄºÚ°µÖ®ÖĞ£¬ĞÄÖĞ³äÂúÁË¿Ö¾å¡­¡­\n\n");
    room = find_object(__DIR__"lake");
    if(!objectp(room)) room= load_object(__DIR__"lake");
   me->move(room);
   tell_object(me,"²»ÖªµÀ¹ıÁË¶à¾Ã£¬ÄãÑÛÇ°Ò»ÁÁ£¬±»Ë®Á÷´ø³öÁËºşÃæ¡£\n\n");
}


