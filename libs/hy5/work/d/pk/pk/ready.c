// Room: /d/pk/ready.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ÍÀÈË³¡ÐÝÏ¢ÊÒ");
	set("long", @LONG
ÕâÀïºÚºõºõµÄ£¬µØÉÏ»¹ÓÐÒ»Ð©Õ³ÂúÁËÑª¼£µÄ²¼Ìõ£¬Å¼È»Ò²¿´µÃµ½¶Ï
ÁËµÄ³¤½£¡¢¸Öµ¶Ê²Ã´µÄ¡£±±ÃæµÄÃÅ½ô½ôµÄËø×Å£¬ÀïÃæÉ¢·¢³öÒ»ÕóÕóÑªÐÈ
µÄÆøÎ¶¡£
[1;31mÔÚÕâÀï¿ÉÒÔÓÃduihuanÀ´¶Ô»»ÄãÍÀÈË´ó»áÖÐ»ñµÃµÃ½±Àø¡£
Èç¹ûÄãµÄ×ÔÔìÎäÆ÷»µÁË£¬¿ÉÒÔÓÃask ouye zi about ÐÞÀíÀ´Ãâ·ÑÐÞÀíÎäÆ÷
Èç¹ûÃ»ÊÂÁË£¬Äã¾Í¿ÉÒÔÓÃoutÀ´Àë¿ª³¡µØ
LONG
	);
	set("exits", ([
		"out" : "/d/city/wumiao",
	]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/ouyezi" : 1,
]));


        set("no_fight", 1);
	setup();
}

void init()
{
        add_action("do_start", "duihuan");
}

int do_start()
{
       object me;
       object room,npc,room2;
int a,b,c;
       me = this_player();       
       if (!userp(me))
          return notify_fail("·ÇÍæ¼Ò²»µÃÊ¹ÓÃ£¡\n");
       if (!me->query_temp("bwdhpk"))
          return notify_fail("ÄãÒ»¸öÍæ¼ÒÒ²Ã»ÓÐÍÀµ½£¡\n");
a=(int)me->query_temp("bwdhpk");
b=a*500;
c=a*300;
        me->add("combat_exp", b);
        me->add("potential",c);
message_vision(HIG"Ò»Õó¹â°üÎ§ÁË$N,$NÏûÊ§²»¼ûÁË¡£\n"NOR, me);
tell_object(me, "Äã±»½±ÀøÁË"+chinese_number(b)+"µã¾­ÑéÖµ£¡\n"+chinese_number(c)+"µãÇ±ÄÜ\n");
message("channel:chat", HIC"¡¾ÍÀÈËÕ½¿ö¡¿"HIR + " "+me->query("name")+"¹²ÍÀÈË:"+chinese_number(a)+"ÈË   "+HIG"ËùµÃ"+chinese_number(b)+"¾­ÑéºÍ"+chinese_number(c)+"µãÇ±ÄÜ\n"NOR,users() );
me->set_temp("bwdhpk",0);
me->delete_temp("bwdhpk");

           return 1;
 
}
