inherit ROOM;
void create()
{
        set("short", "ÔÆÓêÖÛ´óÌü");
        set("long", @LONG
ºìÄ¾²Õ°å±»²ÁµÄÎÆÀí²¢ÏÖ¡£Ç½±ÚËÄÖÜ¹ÒÂúÁËµ±µØÃûÈËµÄÊé´ÊÌá»­¡£ÌüÖĞÒ»ÕÅ´óºì
µØÌº£¬×ãÓĞÎåÕÉ·½Ô²¡£¼¸¸öÉ´ÒÂëüëÊµÄÃîÁäÉÙÅ®ÕıÔÚËæ¸è¶øÎè¡£ÓĞµ½»°£º
[1;31m
                        ç­ÒÂÅû·÷Â¶Ó¯Ó¯£¬
                        µ­È¾ëÙÖ¬Ò»¶äÇá¡£
[2;37;0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"boat3",
  "south" : __DIR__"wting",
  "north" : __DIR__"eting",
  "westup"   : __DIR__"stairs",
]));

       set("objects", ([
        __DIR__"npc/dancer" : 3,
                        ]) );

        setup();
}
