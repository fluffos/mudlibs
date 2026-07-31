inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short",HBYEL+HIW"ÉÌÒµ½ÖÄÏÒ»½Ö"NOR);        
set("long", 
"ĞÅ²½¶øĞĞ£¬²»Öª²»¾õÉÌÒµ½Ö¹ıÁËÒ»°ë£¬ĞĞ¹ıÒ»×ùÈı²ãµÄ
ÊĞÂ¥£¬ÑÛÇ°¸ü¼ÓÈÈÄÖ£¬ÈË³Æ¡°Ò»ÈÕÓĞÈıÊĞ¡±£¬ÕâÀï¸üÊÇÉÌÃ³
¾Û¼¯ÖĞĞÄ£¬·ÅÑÛ¿´È¥£¬¸÷¸öÆÌÃæ»¨¸ÚÑÒÃÅ¿²ÉÏ¶¼ÓĞÁ½µÀºÜÉî
µÄ³µÕŞÓ¡ºÛ£¬ÕâÀï³µË®ÂíÁúµÄÈÈÄÖ¸ü¿É¼ûÒ»°ß¡£

        [1;33mÓñ»Ê¸ó[2;37;0m -- ÉÌÒµ½ÖÄÏÒ»½Ö -- [1;33mÓ¢ĞÛÂ¥[2;37;0m 
" );
       set("outdoors", "player");
       set("no_fight",1);
        set("exits", ([
  "south" : __DIR__"nan2",
  "north" : __DIR__"nanqu",
  "west" : __DIR__"hangzhou_shop",
  "east" : __DIR__"foshan_shop",
        ]));
        set("objects", ([
        ]));
        setup();
        replace_program(ROOM);
}

void init()
{
        object me = this_player();
                tell_object(me, WHT "\n»¶Ó­¹âÁÙÑïÖİÉÌÒµ½Ö£¬ÏëÖªµÀÈçºÎ²Ù×÷"
                                "Çë(" HIC "help trade & help cmdtrade" NOR + WHT ")£¬×£Äã"
                                "¹ºÎïÓä¿ì¡£\n\n" NOR);

}
