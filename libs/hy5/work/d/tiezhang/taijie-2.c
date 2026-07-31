// Room: /u/bobo/tiezhang/taijie-2.c

inherit ROOM;

void create()
{
        set("short", "Ê¯½×");
        set("long", @LONG
Ê¯½×µ½ÁËÕâÀï¾ÍÃ»ÓĞÁË£¬Í»È»ËÄÖÜÒ»Æ¬¹âÃ÷£¬ÖÜÎ§Ê¯±ÚÉÏµÄ»ğ°ÑÈ¼ÉÕÆğÀ´£¬
Äã¿´µ½ÃæÇ°¶şÉÈÍ­Æ¤°ü×ÅµÄ´óÃÅ(gate)½ô±Õ×Å¡££
LONG
        );

        set("exits", ([ 
"eastup" : __DIR__"taijie-1",
]));
        set("objects", ([
        "/d/feihu/npc/corpse" : 4,
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_open", "tui");
}

int do_open(string arg)
{
      object me;
      me=this_player();
      
      if(!arg || arg != "gate")
          return notify_fail("ÄãÒªÍÆÊ²Ã´£¿\n");
	if (objectp(present("flash corpse", environment(me))))
	   return notify_fail("¸½½üÓĞÔà¶«Î÷£¬Äã»¹ÓĞ¿Õ×öÕâ¸ö£¡£¡\n");

      if (arg == "gate")
      {
      if ((int)me->query_temp("marks/baowu")){
          write("ÄãÓÃÁ¦Ò»ÍÆ´óÃÅ£¬½ÅÏÂÒ»¸öà¥Çº£¬µøÁË½øÈ¥£¬´óÃÅËæºó¾Í¹ØÉÏÁË¡£\n");
          me->move(__DIR__"dashishi");
          me->delete_temp("marks/baowu",1);
          return 1;
          }
       }
       return notify_fail("ÄãÓÃ¾¡È«Á¦ÍÆ´óÃÅ£¬´óÃÅË¿ºÁ²»¶¯¡£ÄãÎŞÄÎµØÒ¡ÁËÒ¡Í·¡£\n");
}
