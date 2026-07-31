inherit ROOM; 
#include <ansi.h> 
void init();
int do_move(string arg);
int do_enter(object me);

void create()
{ 
      set("short", "°×É°Ì¨");
      set("long",
"[1;32m°×É°Ì¨Ô¼ÓÐÒ»ÕÉ¼û·½£¬ÉÏÃæÓÐÏ¸É³ÆÌ¾Í£¬Õû¸öÌ¨Ãæ·Ç³£µÄÆ½\n"
"Õû¡£Ì¨ÖÐÑëÓÐÒ»¿é´óÊ¯Í·(stone)£¬¶Â×¡ÁËÈªÑÛ¡£\n"
);
  set("exits",([
      "east" : __DIR__"spirit4",
  ]));
  set("item_desc", ([
      "stone" : "Õâ¿éÊ¯Í·¿´ÆðÀ´²»ËãÌ«´ó£¬ÄãÓ¦¸Ã¿ÉÒÔ°á¶¯(move)Ëü¡£\n",
  ]));
//  set("no_clean_up", 0);
  set("no_magic", 1);
	setup();
}

void init()
{
        add_action("do_move", "move");
        add_action("do_enter", "enter");
}

int do_move(string arg)
{      
        object room; 
        object me=this_player();
        if(!arg || arg!="stone")
          return notify_fail("ÄãÒªÒÆ¶¯Ê²Ã´£¿\n");
        if((int)me->query_str()>25)
                {
message_vision(HIC"$NÓÃÁ¦ÍÆ¿ª´óÊ¯Í·£¬ÈªË®ÓÖ¿ªÊ¼Á÷ÁË³öÀ´£¡ËÆºõ¿ÉÒÔÇ±ÏÂÈ¥(enter)¡£\n"NOR,this_player() ); 
message_vision(HIC"Ò»Ö»Ð¡¾«Áé³öÏÖÔÚ$NÃæÇ°£¬Ëµ£ºÐ»Ð»Äã½â¿ªµÚ¶þ¸ö·âÓ¡£¬ÇëÄã¼ÌÐøÇ°½ø°É¡£\n"NOR,this_player() ); 
                this_player()->set_temp("m_success/³õ¼¶",1);
                set("move_stone",1);
        if(!( room = find_object(__DIR__"entrance")) )
                room = load_object(__DIR__"entrance");
        if(objectp(room)) 
            {                room->set("exits/down", __DIR__"spirit3");
                message("vision","ÈªÑÛÖÐÓÖÓ¿³öÁËÈªË®¡£\n",room);
            }                }
        else
                message_vision("$NÊ¹³ö³ÔÄÌµÄÁ¦ÆøÒ²Å²²»¶¯Ê¯Í·£¬Ö»ºÃã¬ã¬µØ·ÅÆúÁË¡£\n", this_player());    
        return 1;       
}

int do_enter(object me)
{
        object room;
        object where;
        me=this_player();
        where=environment(me); 
       if(!where->query("move_stone"))
          return notify_fail("ÄãÒª½øÄÄÈ¥£¿\n");        if(!( room = find_object(__DIR__"spirit5")) )
          room = load_object(__DIR__"spirit5");
        message_vision("$N¡°¹¾ßË¡±Ò»Éù£¬Ìø½øÈªË®ÖÐ¡£\n",me); 
        set("move_stone",0);        me->move(room);
        return 1;
}


