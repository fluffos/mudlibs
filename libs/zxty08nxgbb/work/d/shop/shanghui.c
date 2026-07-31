inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short",BYEL+HIW"ÑïÖİ³Ç×ÜÉÌ»á"NOR);        
set("long", 
"Ì¤Èë×ÜÉÌ»á£¬Äã¾¹±»ÑÛÇ°¾°ÏóÏÅ×¡£¬ÉÌ»á×°ÊÎËä²»¼°»Ê
¹¬µÄºÀ»ª£¬µ«Ò²¼¸½üÉİ³Ş£¬ÈÃÄã²»µÃ²»¾ªÌ¾£¬ÑïÖİ¹ûÈ»ÊÇÉÌ
ÒµÍú³Ç¡£

   [1;33mÂÃµêµÆÁı£¬ÕĞÍùÀ´Ö®¹ı¿Í£»ÆÌÃæÕĞÅÆ£¬À¿¾­ÉÌÖ®ÊĞ¼Ö[2;37;0m


" );
       set("no_fight",1);
        set("exits", ([
  "down" : "/d/wizard/fightroom5",
  "up" : __DIR__"shanghui2",

        ]));
        set("objects", ([
        "/d/shop/npc/huangzhen": 1, 
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

