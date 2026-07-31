inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short",HBGRN+WHT"ÉÌÒµ½Ö±±Çø"NOR);
        set("long", 
"ÈÆ¹ıĞ¡ºş£¬ÑÛÇ°Ò»ÁÁ£¬Çà×©Â·Ãæ±ÊÖ±Í¨ÏòÇ°·½£¬Á½ÅÔµñ
Áº»­¶°µÄÉÌÒµÆÌÃæÈÃÄãÑÛÇ°Ò»ÁÁ£¬ÕâÀïĞĞÈËÎõÀ´ÈÁÍù£¬ÉõÊÇ
·±»ª£¬´®´®µÆÁı¸ß¹Ò£¬ÒşÒş»¹ÄÜÌıµ½ËãÅÌàèàèÀ²À²µÄ²¦´òÉù
ºÍ»ï¼ÆµÄÓ­¿ÍËÍ¿ÍµÄ³ªÅµ£¬ÕæÊÇºÃ²»ÈÈÄÖ¡£

                   [1;33mÊ®[2;37;0m          [1;33mÁ½[2;37;0m                               
                   [1;33mÊ¡[2;37;0m          [1;33m½­[2;37;0m
                   [1;33mÍ¨[2;37;0m          [1;33mÃû[2;37;0m
                   [1;33máé[2;37;0m          [1;33mµØ[2;37;0m
                   [1;33mÈË[2;37;0m          [1;33mË×[2;37;0m
                   [1;33mê£[2;37;0m          [1;33m·±[2;37;0m
                   [1;33m¼¯[2;37;0m          [1;33m»ª[2;37;0m

"
 );
       set("outdoors", "player");
       set("no_fight",1);
        set("exits", ([
                "south"  : "/d/wizard/fightroom5",
  "north" : __DIR__"bei1",
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
                                "Çë(" HIY "help trade & help cmdtrade" NOR + WHT ")£¬×£Äã"
                                "¹ºÎïÓä¿ì¡£\n\n" NOR);

}
