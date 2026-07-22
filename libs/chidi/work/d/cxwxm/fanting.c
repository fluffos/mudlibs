// Room: /u/marry/obj/cxwxm/fanting.c
// marry 8,14
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", HIC"·¹Ìü"NOR);
        set("long",
"ÕâÊÇÒ»¼ä·Ç³£´óµÄ·¿¼ä£¬ÎÝ×ÓÀï°Ú·Å×ÅÊ®¼¸Ì×ºìÄ¾×ÀÒÎ£¬Ò»¸ù\n"
"´Ö´óµÄ"+RED"Öù×Ó"NOR+"Ö±Í¨ºÚºýºýµÄ·¿¶¥¡£ÄãÈç¹û¶öÁË¿ÉÒÔÏò³øÊ¦Òª( yao)·Ý\n"
"¡°ÑïÖÝ³´·¹¡±¡£\n\n"


);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dating",
]));

        setup();
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
       object me;
       object food;
       me=this_player();
       if (arg)  return notify_fail("ÎÒÃÇÕâÀïÖ»ÓÐ³´·¹¡£\n");
       if (food = present("fan", me)) return notify_fail("³ÔÍêÔÙËµ... ...\n");
       message_vision("Ò»¸ö·ÊÍ·´ó¶úµÄ³øÊ¦ÔÚÅÌ×ÓÖÐÌíÁËÐ©³´·¹£¬È»ºóµÝ¸øÁË$N¡£\n",me);
        food=new(__DIR__"obj/fan");
        food->move(me);
       return 1; 
}
int do_climb(string arg)
{
    int n;
        object me = this_player();

    if( !arg || arg!="Öù×Ó" )
        {
        write("ÄãÒªÉÏÄÄ¶ù£¿\n");
        return 1;
    }

    message_vision(
    "$N¿´ÁË¿´ËÄÏÂÎÞÈË£¬±ã×ßµ½´óÖù×ÓÇ°£¬ÔËÆðÈ«ÉíÇá¹¦£¬Ë³×ÅÖù×ÓÃÍµÄÍùÉÏÅÀ¡£\n", this_player());

        if ((me->query("family/family_name") == "³ÕÐÄÍýÏëÃÅ"))
        {
                me->move(__DIR__"longfeng");
                return 1;
        }

    n = (int)me->query("dodge");
    if (n >= 300)
        {
        message_vision(
                HIR "Ö»Ìý¡°Åé¡±µÄÒ»Éù£¬$NµôÔÚÁËµØÉÏ£¬Ò»¶¯²»¶¯ÁË¬....\n" NOR, this_player());
        set("exits/up", __DIR__"longfeng");
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else
        {
                message_vision(
                HIR "Ö»Ìý¡°Åé¡±µÄÒ»Éù£¬$NµôÔÚÁËµØÉÏ£¬Ò»¶¯²»¶¯ÁË¬....\n" NOR, this_player());
                this_player()->set("qi",1);
                this_player()->unconcious();
    }

    return 1;
}
