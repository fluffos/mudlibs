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
 //          "/quest/tulong/npc/hunter": 1, 
//          "/quest/tulong/npc/spirit1": 3,
 //          "/quest/tulong/obj/kaolu": 1,
        ]) );

        set("no_magic", 1);
	setup();
}
void init()
{
   add_action("do_west", "west");
   add_action("do_around", "around");

}

int do_around(string arg)
{
   object me, room;

   me = this_player(); 
   if (random(20)<10)
   { 
   tell_object(me, "Äã×ªÀ´×ªÈ¥£¬Ò²Ã»ÕÒµ½³ö¿Ú£¬ÄãÃÔÁËÂ·£¡£¡\n\n");
   room = find_object(__DIR__"spirit0");
   if(!objectp(room)) room=load_object(__DIR__"spirit0");
   me->move(room);
   return 1;
   }
   else  
   tell_object(me, "Äã·¢ÏÖÎ÷±ßËÆºõÓĞÌõÂ·(west)¡£\n\n");
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

