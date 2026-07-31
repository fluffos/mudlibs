inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "É½¹È");
        set("long",
"[1;32m´Ë´¦ÓĞĞ©Ï¡ÊèµÄÊ÷Ä¾£¬ÑÛÇ°´£Á¢×ÅÒ»×ùÇ§²ãµş´ä¡¢ÍòÀïµã²Ô\n"
"µÄÉ½·å£¬Î§³ÉÒ»´¦ÓÄ¹È£¬ÖĞÓĞÒ»ãüÇåÌ¶£¬ÈªË®´Ó·å¼ä±¼Á÷¶øÏÂ£¬ÅçÖéĞ¹Óñ£¬\n"
"Ö±ÈëÇåÌ¶£¬»¹ÓĞ¼¸Ö»Ğ¡¾«ÁéÕıÔÚÌ¶±ß·ÉÎè¡£´Ë´¦¿ÕÆøÇåÁ¹ÊªÈó£¬ÇßÈËĞÄ·Î£¬\n"
"ËÄÖÜÈ´¿´²»¼ûÈÎºÎÃ÷ÏÔµÄ³öÂ·£¬¿´À´£¬ÄãÖ»ºÃËÄ´¦×ª×ª(around)¿´ÁË¡£\n"
); 
        set("exits", ([
        ]) );

        set("objects", ([
//        "/quest/tulong/npc/spirit1": 4,
        ]) );

        set("no_magic", 1);
	setup();
}
void init()
{
   add_action("do_west", "xifang");
   add_action("do_catch", "catch");
   add_action("do_around", "around");

}

int do_around(string arg)
{
   object me, room;

   me = this_player(); 
   if (random(20)<10)
   { 
   tell_object(me, "Äã×ªÀ´×ªÈ¥£¬Ò²Ã»ÕÒµ½³ö¿Ú£¬ÄãÃÔÁËÂ·£¡£¡\n\n");
   room = find_object(__DIR__"liechang");
   if(!objectp(room)) room=load_object(__DIR__"liechang");
   me->move(room);
   return 1;
   }
   else  
     tell_object(me, "Äã·¢ÏÖÎ÷±ßËÆºõÓĞÌõÂ·(xifang)¡£\n\n");
return 1;}

int do_catch(string arg)
{
   object spirit, me, room;

   me = this_player();
   if(!arg || arg != "Ğ¡¾«Áé" && arg != "spirit" ) return 0;
   spirit = present("spirit", this_object());
   if(!objectp(spirit)) return 0;

   switch ( random (7)) {
   case 0:
      message_vision("$NÏòÇ°Ò»ÆË£¡Ğ¡¾«ÁéÍùááÒ»ÉÁ£¬$NÂäÁË¸ö¿Õ¡£ \n", me); 
      break;
   case 1:
      message_vision("$NÏòÓÒÒ»ÆË£¡Ğ¡¾«ÁéÏò×óÒ»ÉÁ£¬$NÂäÁË¸ö¿Õ¡£ \n", me); 
      break;
   case 2:
      message_vision("$NÏò×óÒ»ÆË£¬Ğ¡¾«ÁéÏòÓÒÒ»ÉÁ£¬$NÂäÁË¸ö¿Õ¡£\n", me); 
      break;
   case 3:
      message_vision("$N×óÆËÓÒµ²½ô½ôµØ¸ú×ÅĞ¡¾«Áé£¬ÉîÅÂÒ»×ªÑÛ¾Í²»¼ûÁË¡­¡­\n", me);
   break;
   case 4:
      message_vision("$NºÏÉíÆËÉÏ£¬Ğ¡¾«ÁéÏòÅÔ±ßÒ»»Î¶ã¿ªÁË$N£¬$NÊÕÊÆ²»×¡Ë¤ÁË¸ö×ì¿ĞÄà¡£  \n", me);
   break;
   case 5:
      message_vision("$NõæÊÖõæ½ÅµØ³¯Ğ¡¾«ÁéÃş¹ıÈ¥£¬Ïë´ÓºóÃæ×¥×¡Ëü£¬Ğ¡¾«Áé»úÁéµØÏòÇ°Ò»³å£¬$NÃ»³É¹¦¡£\n", me);
   break;
   case 6:
      message_vision("$NÍùÇ°Ò»ÆË£¬Ğ¡¾«ÁéÏòÇ°Ò»³å£¬´Ó$NµÄÊÖ±ß·É¿ìµÄ·ÉÁË¹ıÈ¥¡£ \n", me); 
      message_vision("$Nµ÷Í·±ãÏòĞ¡¾«ÁéÌÓÅÜµÄ·½Ïò×·È¥¡­¡­\n", me); 
      message_vision("\nĞ¡¾«ÁéÈı×ªÁ½×ª£¬Ù¿µØÒ»ÏÂ²»¼ûÁË×ÙÓ°¡£\n\n", me); 
      message("vision", me->name() + "½ô½ô¸ú×ÅĞ¡¾«ÁéÙ¿µØÒ»ÏÂÒ²²»¼ûÁË×ÙÓ°¡£\n", environment(me), me);
      room = find_object(__DIR__"outlet2");
      if(!objectp(room)) room=load_object(__DIR__"outlet2");
      me->move(room);
      destruct(spirit);
      break;
   }

   return 1;
}

int do_west(string arg)
{
        object me;
        object room;
        me = this_player();
        message_vision("$NÍùÎ÷±ßµÄÊ÷ÁÖ×ßÈ¥ . \n", me);

        room = load_object(__DIR__"spirit3");
        if(room) me->move(room);

        return 1;
}

