inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "ÁúÌ¶Èë¿Ú");
        set("long",
"[1;32mÇ°·½¾ÍÊÇÁúÌ¶£¬½øÈ¥Ç°ÇëÈýË¼¡£Èç¹ûµ½´ËÖ¹²½£¬»¹À´µÃ¼°¡£\n"
"ÈçÒª»ØÍ·£¬Çë¼üÈëback¡£ÔÚÎ÷Ãæ£¬ÓÐÒ»¸öÏòÏÂµÄÍ¨µÀ£¬¿´À´ËÆºõÏàµ±Éî¡£\n"
);

        set("exits", ([ 
              "north" : __DIR__"dragoncave", 
              "westdown" : __DIR__"spirit7", 
           ]));

        set("no_magic", 1);
	setup();
}

void init()
{
        add_action("do_back", "back");
}

int do_back(object me)
{
        me=this_player();
        message_vision(HIC"$NµÄÉíÓ°ÏûÊ§ÔÚÒ»Õó¹âÃ¢ÖÐ¡£\n"NOR,me); 
        me->set_temp("mark/diary", 0);
        me->set_temp("m_success/³õ¼¶",0);  
        me->set_temp("m_success/»ÃÓ°",0);  
        me->set_temp("m_success/ÄõÁú",0);  
        me->move("/d/city/wumiao");
        return 1;
}

