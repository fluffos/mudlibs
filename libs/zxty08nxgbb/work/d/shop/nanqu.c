inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short",HBGRN+WHT"ÉÌÒµ½ÖÄÏÇø"NOR);
        set("long", 
"ÈÆ¹ıĞ¡ºş£¬ÑÛÇ°Ò»ÁÁ£¬Çà×©Â·Ãæ±ÊÖ±Í¨ÏòÇ°·½£¬Á½ÅÔµñ
Áº»­¶°µÄÉÌÒµÆÌÃæÈÃÄãÑÛÇ°Ò»ÁÁ£¬ÕâÀïĞĞÈËÎõÀ´ÈÁÍù£¬ÉõÊÇ
·±»ª£¬´®´®µÆÁı¸ß¹Ò£¬ÒşÒş»¹ÄÜÌıµ½ËãÅÌàèàèÀ²À²µÄ²¦´òÉù
ºÍ»ï¼ÆµÄÓ­¿ÍËÍ¿ÍµÄ³ªÅµ£¬ÕæÊÇºÃ²»ÈÈÄÖ¡£

                   [1;36mÊ®[2;37;0m          [1;36mÁ½[2;37;0m                               
                   [1;36mÊ¡[2;37;0m          [1;36m½­[2;37;0m
                   [1;36mÍ¨[2;37;0m          [1;36mÃû[2;37;0m
                   [1;36máé[2;37;0m          [1;36mµØ[2;37;0m
                   [1;36mÈË[2;37;0m          [1;36mË×[2;37;0m
                   [1;36mê£[2;37;0m          [1;36m·±[2;37;0m
                   [1;36m¼¯[2;37;0m          [1;36m»ª[2;37;0m

"
 );
       set("outdoors", "player");
       set("no_fight",1);
        set("exits", ([
                "north"  : "/d/wizard/fightroom5",
  "south" : __DIR__"nan1",
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
