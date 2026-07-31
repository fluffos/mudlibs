// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder
inherit ROOM;
void init();
int throw(string);
void create()
{
        set("short", "»ğÉ½¿Ú");
        set("long", @LONG
Ç°·½ÒÑ¾­Ã»Â·ÁË,Ô¶´¦ÊÇ»ğÉ½¿Ú.
LONG );
set("exits", ([
//                 "north" : __DIR__"hroad4",        
          //        "east" [D: __DIR__"road8",
                 "south"  : __DIR__"hroad3",
        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
}
void init()
{
   add_action("do_reng","reng");
}
int do_reng(string arg)
{
  object me;
me = this_player();
if(!arg||arg!="teng")
{
write("ÈÓÊ²Ã´!\n");
return 1;
}
if(!present("chang teng",me))
{
write("ÄãÄÄÀ´µÄ³¤ÌÙ!\n");
return 1;
}
if(random(5)<2)
{
write("Äã·ÜÁ¦Ò»ÈÓ,½«³¤ÌÙÏò»ğÉ½¿Ú·½Ïò,
ÓÉÓÚ»ğÉ½µÄÈÈÁ¦,³¤ÌÙ±»¿¾¸ÉÁË.\n");
me->set_temp("kao_teng",1);
return 1;
}
write("ÄãÈÔ²»ÁËÄÇÃ´Ô¶,ÔÚÀ´Ò»±é!\n");
return 1;
}
