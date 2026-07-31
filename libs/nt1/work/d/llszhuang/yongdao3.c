inherit ROOM;
#include <ansi.h>
int do_pick(string arg);
void create()
{
       set("short", "ÁøÂÌÉ½×¯");
        set("long",
"ÕâÊÇ×¯ÔºµÄÊ¯½×£¬Ê¯½×³ÊÏÖ³öÒ»ÖÖÆæÒìµÄËÀ»ÒÉ«¡£Ê¯½×ÅÔ±ßÊÇÒ»×ù¼Ù\n"
"É½£¬¼ÙÉ½Ê¯·ìÀïÃæ²å×ÅÒ»°Ñ¸Ö¹Õ£¬Ö±ÖÁÃ»±ú¡£¸Ö¹ÕÅÔ±ßÐ±ÒÐ×ÅÒ»¾ß÷¼÷Ã£¬\n"
"÷¼÷ÃÉÏµÄ°×·¢ÊÇÒø»ÒÉ«µÄ¡£\n"
);
        set("no_magic", "1");

        set("exits", ([ /* sizeof() == 2 */
          "north" : __DIR__"dynamic/jiuqu1",
          "southeast" : __DIR__"yongdao2",
        ]));

        set("item_desc", ([
                "¸Ö¹Õ": "ÕâÊÇÒ»°Ñ¾«¹âÉÁÉÁµÄ¸Ö¹Õ£¬ËäÒÑÀú¾­¶àÄê·çÓê£¬ÉÏÃæÈ´ºÁÎÞÐâº
Û\n",
        ]) );

        set("have_weapon",1);
        setup();
}
int init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
        object me,killer;
        int i;

        me = this_player();

        if( !arg || arg != "¸Ö¹Õ" )
                return 0;
        if( query("have_weapon") != 1 )
                return notify_fail("¸Ö¹ÕÒÑ¾­±»°Î×ßÁË¡£\n");

        i = me->query("neili");
        if( random(i)<2000 )
        {
                i -= 200;
                if( i<1 ) i = 1;
                me->set("neili",i);
                return notify_fail("ÄãÊ¹³ö³ÔÄÌµÄÁ¦ÆøºÝÃüÒ¡»Î×Å¸Ö¹Õ£¬¿É¸Ö¹ÕÎÆË¿²»
¶¯¡£\n");
        }
        me->add("neili",-1000);
        message_vision("$NÔË×ãÄÚÁ¦£¬°Ñ¸Ö¹Õ´Ó¼ÙÉ½Ê¯·ìÖÐ°ÎÁË³öÀ´¡£\n¿ÉÊÇ...\n"+BLU
"ºöÈ»Ò»ÕóÒõ·ç´µÆð...»¹..ÎÒ..Ãü..À´...\n"NOR,me);
        set("have_weapon",0);
        killer = new(__DIR__"npc/wraith");
        killer->move(this_object());
        killer->set_leader(me);
        killer->kill_ob(me);
        me->fight_ob(killer);
        return 1;
}

