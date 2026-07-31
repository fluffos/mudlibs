inherit ROOM; 
#include <ansi.h> 
void create()
{
   set("short", "³ØÌÁ");
   set("long",
"[1;32mÕâÊÇ´ÓÈýÇåºþÒýÀ´µÄÒ»¸öÐ¡Ð¡µÄ³ØÌÁ£¬Ò»×ùÐ¡¹°ÇÅºá¿çÔÚ³Ø\n"
"ÌÁÉÏ¡£ÌÁË®±ÌÂÌ£¬ÉÏÃæÓÐ¼¸¶äÊ¢¿ªµÄË¯Á«£¬·Ûºì£¬½à°×£¬¶ì»Æ£¬³ÄÍÐ×Å±Ì\n"
"ÂÌµÄÒ¶×Ó£¬Æ¯¸¡ÔÚÐ¡³ØÌÁÉÏ£¬É·ÊÇÈÇÈËÏ²°®¡£Ò»¿Ã´¹Áø°ëºáÔÚÌÁ±ß£¬ÁøË¿\n"
"Ëæ·çÆ®Îè¡£¼¸¿éÌ«ºþÊ¯(stone)É¢ÂäµØ·ÅÔÚ³ØÌÁ±ß¡£\n"
);
   set("exits", ([ /* sizeof() == 4 */
      "southeast" : __DIR__"lake1",
   ]));
   
   set("item_desc", ([
      "Ì«ºþÊ¯": "¼¸¿éÁáççµÄÌ«ºþÊ¯£¬É¢ÂäµØ·ÅÔÚ³ØÌÁ±ß£¬Ê¯Í·µÄÒ»²¿·Ö±»ÂñÔÚÁËÍÁÏÂ¡£\n",
      "stone": "¼¸¿éÁáççµÄÌ«ºþÊ¯£¬É¢ÂäµØ·ÅÔÚ³ØÌÁ±ß£¬Ê¯Í·µÄÒ»²¿·Ö±»ÂñÔÚÁËÍÁÏÂ£¬¿´ÆðÀ´ÂñµÃ²»Éî£¬Ó¦¸ÃÄÜ¹»ÍÆ(push)µÃ¶¯¡£\n",
      "´¹Áø": "´¹ÁøÔÚ²»Ô¶´¦µÄ³ØÌÁ±ß£¬Õû¸öÁøÊ÷ºáÔÚ³ØÌÁÉÏ¡£\n",
      "tree": "´¹ÁøÔÚ²»Ô¶´¦µÄ³ØÌÁ±ß£¬Õû¸öÁøÊ÷ºáÔÚ³ØÌÁÉÏ¡£\n",
      "Ë¯Á«": "°ë¿ªµÄË¯Á«ÏóË¯ÃÎÖ®ÖÐµÄÃÀÈË£¬Æ¯¸¡ÔÚ±ÌÂÌµÄ³ØÌÁÉÏ¡£\n",
      "flower": "°ë¿ªµÄË¯Á«ÏóË¯ÃÎÖ®ÖÐµÄÃÀÈË£¬Æ¯¸¡ÔÚ±ÌÂÌµÄ³ØÌÁÉÏ¡£\n",
   ]) );
      set("no_magic", 1);
	setup();
}

void init()
{
   add_action("do_push", "push");
}

int do_push(string arg)
{
   object me, qiuyin, where;
  
   me = this_player();
        where=environment(me); 
   if(where->query_temp("marks/moved")) return notify_fail("Ê¯Í·ËÆºõ±»ÈËÍÆ¹ý£¬ÒÑ¾­ËÉ¶¯ÁË¡£\n");
   if (!arg || arg != "stone" && arg != "Ê¯Í·") 
      return notify_fail("ÄãÒªÍÆÊ²Ã´ ? \n");
   message("vision",me->name()+"ÉìÊÖÍÆÁËÍÆÌ«ºþÊ¯£¬Ê¯±ßµÄÍÁËÉ¶¯ÁË£¬Â¶³öÁËÒ»ÌõÅÖÅÖµÄòÇò¾¡£\n", me);
   qiuyin = new("/quest/tulong/obj/qiuyin");
   qiuyin->move(where);
   where->set_temp("marks/moved", 1); 
   return 1;

}

