#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "²ÝÆº");
        set("long",
"[1;32mÕâÊÇÒ»Æ¬±ÌÂÌµÄ²ÝÆº£¬²ÈÉÏÈ¥¾õµÃÒì³£µÄÈáÈíÎÂºñ£¬²ÝÆºÒ»\n"
"Ö±ÑÓÉìµ½Ð¡ºÓÅÏ£¬ÇàÇà²Ý¸ùÒ²½þÈëºÓË®Ö®ÖÐ¡£ºÓÃæÉÏµãµãË¸½ð,²¨ÎÆÇÇáÇ\n"
"áµ´Ñú¡£²ÝÆºµÄÄÏÃæ£¬Ò»¿Ã¸ß´óµÄÎàÍ©Ê÷£¬Ö¦¸ÉÐ±Éì£¬Á½¸ù¹ÅÌÙ´Ö´ÖÍì¾ÍÒ\n"
"»¸öÇïÇ§(qiuqian)£¬Ò»ÅÉÏçÍÁÆøÏ¢¡£Äã¶ÙÊ±±»ÕâÀïµÄÃÀ¾°ÃÔ×¡ÁË£¬ÍüÁËÈ\n"
"¥×·ÄÇÖ»Ð¡¾«Áé¡£\n"
);
        set("exits", ([ 
        ]) );

        set("item_desc", ([
        "qiu qian": "ÇïÇ§ÏµÓÃ¹ÅÌÙÍì¾Í£¬ËäÈ»¼òÂª£¬È´±ðÓÐÇéÈ¤¡£Äã¿ÉÒÔÊÔ×Åµ´µ´(swing)¿´¡£\n",
        "tree": "¸ß´óµÄÎàÍ©Ê÷°Ñ²ÝÆºµÄ±±·½ÕÚµÄÑÏÑÏÊµÊµ¡£\n",
        ]) );
        
        set("no_magic", 1);
	setup();
}

void init()
{
   add_action("do_swing", "swing");
     add_action("do_north", "beifang"); 
   add_action("do_north", "n");
}

int do_north(string arg)
{
   object me;

   me = this_player(); 

 if(me->query_temp("marks/marble"))
   {
message_vision(HIW"$NÈÆ¹ýÎàÍ©Ê÷£¬²¦¿ª²Ý´Ô£¬ºöÈ»Ò»Õó¿ñ·ç´µ¹ý£¬°Ñ$N´µÁË¸öõÔõÄ¡£\n"NOR,me ); 
message_vision(HIW"·çÖÐ´«³öÒ»¸öÉùÒô£ºÓÂ¸ÒµÄÈË£¬Ð»Ð»Äã½â¿ªµÚÒ»¸ö·âÓ¡£¬½Ó×Å×ßÏÂÈ¥°É¡£\n"NOR,me );
message("channel:chat", HBMAG"¡¾¾«ÁéÉñ½ç¡¿"+me->query("name")+"³É¹¦½â¿ªµÚÒ»¸ö·âÓ¡!\n"NOR,users());
      me->move(__DIR__"spirit5");
    me->set_temp("marks/marble", 0);
                me->set_temp("m_success/³õ¼¶",1);
   return 1;
   }
   else 
   tell_object(me, "ÄÇÀïÃ»ÓÐ³öÂ·¡£\n\n");
   return 1;
}

int do_swing(string arg )
{
        object me;
        me = this_player();

        if(!arg || arg != "ÇïÇ§" && arg != "qiu qian" ) return 0;       
        switch (random (7)) {
                case 0:
message_vision(HIG"$NÅÀµ½ÇïÇ§ÉÏ£¬ÂýÂýµØ¿ªÊ¼µ´ÆðÇïÇ§£¬Ô½µ´Ô½¸ß¡£\n"NOR, me);
                break;
                case 1:
message_vision(HIG"ÇïÇ§Ô½µ´Ô½¸ß£¬$N²»ÓÉµÃ½ô½ô×¥×¡¹ÅÌÙ¡£\n"NOR, me);
tell_object(me, "ÄãÖ»¾õµÃ·ç´Ó½Åµ×ÂÓ¹ý£¬ÈËËÆºõÒª³Ë·ç·ÉÈ¥¡£\n");
                break;
                case 2:
message_vision(HIG"ÇïÇ§Ô½µ´Ô½¸ß£¬$N²»ÓÉµÃ½ô½ô×¥×¡¹ÅÌÙ¡£\n"NOR, me);
message("vision", me->name()+"ËÆºõ¿´µ½ÁËÊ²Ã´¶«Î÷£¬´Ò´ÒµØ´ÓÇïÇ§ÉÏÌøÁËÏÂÀ´¡£\n", environment(me), me);
  tell_object(me, "ÄãºöÈ»·¢ÏÖÇ°ÃæÓÐÊ²Ã´·¢³öÒ«ÑÛµÄ¹â£¬¹âÒ»ÉÁ¼´Ê§¡£ËÆºõ¿ÉÒÔÍù±±(beifang)¡£\n");
                me->set_temp("marks/marble", 1);
                break;
                case 3:
message_vision(HIR"ÇïÇ§Ô½µ´Ô½¸ß£¬$NÒ»²»ÁôÉñ´ÓÇïÇ§ÉÏµôÁËÏÂÀ´¡£\n"NOR, me);
tell_object(me, "£¢Åé£¡£¢ÄãÖØÖØµØË¤ÔÚÊ÷¸ùÉÏ£¬Æ¨¹ÉºÃÍ´Å¶£¡ \n");
                me->receive_damage("qi",25);   
                me->receive_damage("jing",20);   
                break;
                case 4:
message_vision(HIR"ÇïÇ§Ô½µ´Ô½¸ß£¬$NÒ»²»ÁôÉñ´ÓÇïÇ§ÉÏµôÁËÏÂÀ´¡£\n"NOR, me);
tell_object(me, "£¢Åé£¡£¢ÄãÖØÖØµØË¤ÔÚÊ÷¸ùÉÏ£¬Æ¨¹ÉºÃÍ´Å¶£¡ \n");
                me->receive_damage("qi",30);   
                me->receive_damage("jing",20);   
                break;
                case 5:
message_vision(HIR"ÇïÇ§Ô½µ´Ô½¸ß£¬$NÒ»²»ÁôÉñ´ÓÇïÇ§ÉÏµôÁËÏÂÀ´¡£\n"NOR, me);
tell_object(me, "£¢Åé£¡£¢ÄãÖØÖØµØË¤ÔÚÊ÷¸ùÉÏ£¬Æ¨¹ÉºÃÍ´Å¶£¡ \n");
                me->receive_damage("qi",50);   
                me->receive_damage("jing",20);   
                break; 
                case 6:
message_vision(HIR"ÇïÇ§Ô½µ´Ô½¸ß£¬$NÊÖÒ»»¬£¬´ÓÇïÇ§ÉÏµôÁËÏÂÀ´¡£\n"NOR, me);
tell_object(me, "£¢Åé£¡£¢ÄãÖØÖØµØË¤ÔÚÊ÷¸ùÉÏ£¬Æ¨¹ÉºÃÍ´Å¶£¡ \n");
                me->receive_damage("qi",40);   
                me->receive_damage("jing",10);   
                break;        }
        return 1;
}

