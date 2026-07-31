inherit ROOM; 
#include <ansi.h> 
void init();
int do_take(string arg);
int do_back(object me);

void create()
{ 
      set("short", "ÑİÎäÌ¨");
      set("long",
"[1;32mÕâÀï¿´ÉÏÈ¥ÏóÊÇÒ»¸ö±ÈÎä³¡£¬Ê®ÕÉ¼û·½µÄ³¡µØÉÏÕûÕûÆëÆëµØ\n"
"ÆÌ×ÅÒ»È¦²ÊÉ«Âêè§Ê¯£¬¼Ü×ÅÏãÑÌôÁÈÆµÄËÄ¸ö¾Ş´ó½ğÒøÍ­Ìú¶¦£¬³¡µØÖĞ¼ä»¹\n"
"ÆÌ×ÅÈíËÉµÄÆ¤ÈŞÖ¯½õÌº¡£ÔÚ³¡±ßÓĞÒ»¸öÊé¼ÜËÆµÄ°ÚÊÎ(shelf)£¬ÔÚËüÅÔ±ß\n"
"»¹ÓĞÒ»ÕÅ¾î²¯(note)¡£\n"
);
   set("exits",([
           "south" : __DIR__"xiuxishi",
]));
  set("objects",([
             "/quest/tulong/npc/shadow" : 1,
  ]));
  set("item_desc", ([
     "shelf" : "ÕâÊÇÒ»¸öÒ©¼Ü£¬ÀïÃæ·Å×ÅÒ»Ğ©½ğ´´Ò©£¬ËÆºõ¿ÉÒÔÄÃ³öÀ´(take jinchuang)¡£\n", 
      "note" : "ÓÂ¸ÒµÄÈË°¡£¬Èç¹ûÄãÃÇµÄ½Å²½µ½´ËÎªÖ¹£¬¾Í»ØÈ¥·²¼ä°É(back)¡£\n", 
  ]));
//  set("no_clean_up", 0);
  set("no_magic", 1);
	setup();
}

void init()
{
       // add_action("do_take", "take");
        add_action("do_back", "back");
      add_action("do_quit","hit");
      add_action("do_quit","kill");
      add_action("do_steal","steal");
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"£¬ÕâÀïÖ»ÄÜfight£¡\n");
        return 1;
}

int do_steal(string arg)
{
        write(this_player()->query("name")+"£¬²»ÒªÎª´Ë²»²ÅÖ®ÊÂ£¡\n");
        return 1;
}
int do_take(string arg)
{      
        object me=this_player();
        object ob;
        if(!arg || arg!="jinchuang")
          return notify_fail("ÄãÒªÄÃÊ²Ã´£¿\n");
        if( !me->query("fighter") )
          return notify_fail("Äã»¹Ã»±ÈÎä¾ÍÏëÄÃÒ©£¿\n"); 
       ob = new ("/clone/misc/jinchuang");   
       ob->move(me); 
  message_vision ("$N´ÓÌ¨ÉÏÄÃÆğ$n¡£\n",me,ob); 
        return 1;  
}

int do_back(object me)
{
        me=this_player();
        message_vision(HIC"$NµÄÉíÓ°ÏûÊ§ÔÚÒ»Õó¹âÃ¢ÖĞ¡£\n"NOR,me); 
        me->set("fighter",0);
        me->set_temp("m_success/³õ¼¶",0);  
        me->set_temp("m_success/»ÃÓ°",0);  
        me->set_temp("m_success/ÄõÁú",0);  
        me->move("/d/city/wumiao");
        return 1;
}

/*
int valid_leave(string dir)
{
              if((present("jinchuang yao", this_player())))
            return notify_fail("Çë²»Òª´ø×ßÕâÀïµÄ¶«Î÷¡£\n"); 
        if((present("budai", this_player())))
            return notify_fail("Çë·ÅÏÂ²¼´ü£¬ÕâÀïµÄ¶«Î÷²»ÄÜ´ø³öÈ¥£¬Ğ»Ğ»¡£\n"); 
    return ::valid_leave();

 }

*/
