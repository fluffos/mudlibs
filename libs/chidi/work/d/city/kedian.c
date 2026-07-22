// Room: /city/kedian.c
// YZC 1995/12/04 
inherit ROOM;
void create ()
{
  set ("short", "[36mÓĞ¼ä¿ÍÕ»[2;37;0m");
  set ("long", @LONG
ÕâÊÇÑïÖİ³Ç±¾µØÒ»¼Ò¼ÛÇ®µÍÁ®µÄ¿ÍÕ»£¬ÉúÒâ·Ç³£ĞËÂ¡¡£ÍâµØÓÎ¿Í¶à
Ñ¡ÔñÕâÀïÂä½Å£¬Äã¿ÉÒÔÔÚÕâÀï´òÌıµ½µ±µØµÄ·çÍÁÈËÇé¡£µêĞ¡¶şÀïÀïÍâÍâ
Ã¦µÃÍÅÍÅ×ª£¬½Ó´ı×ÅÄÏÇ»±±µ÷µÄ¿ÍÈË¡£½ÇÂäÀï¼¸Î»½­ºşÈËÎï´ò°çµÄ´óºº
ÕıÎ§×ÅÒ»ÕÅ×À×Ó²»ÖªµÀÔÚÉÌÁ¿Ê²Ã´,¿ÍµêµÄÖ÷ÈË´Ó²»Â¶Ãæ£¬Ëû¾¿¾¹ÊÇË­£¬
ÓĞ¸÷ÖÖ¸÷ÑùµÄ²Â²â¡£Ç½ÉÏ¹Ò×ÅÒ»¸öÅÆ×Ó(paizi)¡£
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "Â¥ÉÏÑÅ·¿£¬Ã¿Ò¹Ò»Á½°×Òø¡£
",
]));
  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shashoulou",
  "up" : __DIR__"kedian2",
  "west" : __DIR__"beidajie1",
     "south" : __DIR__"huadian",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer" : 1,
  __DIR__"npc/shizhe" : 1,
  __DIR__"npc/neixishizhe" : 1,
]));
       set("have_quest", 1);   
  set("no_clean_up", 1);
   set("no_fight",1);
  set("no_fight_npc",1);
  set("no_sleep_room", 1);

  setup();
}
int valid_leave(object me, string dir)
{
          if (!userp(me))         return ::valid_leave(me, dir);
        if (present("xiao er",environment(me))){
        if ( !me->query_temp("rent_paid") && dir == "up" )
        return notify_fail("µêĞ¡¶şÒ»ÏÂµ²ÔÚÂ¥ÌİÇ°£¬"+HIW"°×ÑÛ"NOR+"Ò»·­£ºÔõ÷á×Å£¬Ïë°××¡°¡£¡\n");
        if ( me->query_temp("rent_paid") && dir == "west" )
        return notify_fail("µêĞ¡¶şÅÜµ½ÃÅ±ßÀ¹×¡£º¿Í¹ÙÒÑ¾­¸¶ÁËÒø×Ó£¬Ôõ÷á²»×¡µê¾Í×ßÁËÄØ£¡
ÅÔÈË»¹ÒÔÎªĞ¡µêËÅºò²»ÖÜÄØ£¡\n");
        }
        return 1;
}

