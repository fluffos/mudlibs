// Room: /u/zqb/tiezhang/shanmen.c

inherit ROOM;

void create()
{
	set("short", "É½ÃÅ");
	set("long", @LONG
    ÕâÀï¾ÍÊÇ½­ºşÉÏÎÅ·çÉ¥µ¨µÄ¡°ÌúÕÆ°ï¡±¡£×Ô´Ó¡°ÌúÕÆ¼ßºâÉ½¡±Ò»ÒÛ
½«ºâÉ½ÅÉ´òµÃÒ»õê²»ÕñÖ®ºó£¬°ïÖ÷ÌúÕÆË®ÉÏÆ¯µÄÃûÍ·ÍşÕğ½­ºş¡£ÕâÀïÊÇ½øÉ½
µÄ±Ø¾­Ö®Â·£¬ÇúµÄĞ¡Â·Í¨ÏòÉ½Àï¡£Â·µÄÒ»²àÁ¢×ÅÒ»¿éÅÆ×Ó(paizi) ¡£Á½ÅÔµÄ
Ê÷ÁÖÄÚ²»Ê±´«³öÒ»Ğ©ÏìÉù£¬ËÆºõÓĞÈËÔÚ°µÖĞ¼àÊÓ¡£
LONG	);
    set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shanlu-1",
  "southdown" : __DIR__"shanjiao",
"east": __DIR__"zhaigou3",
"west": __DIR__"zhaigou1",
]));
    set("objects", ([ /* sizeof() == 2 */
    __DIR__"npc/heiyi" : 2,
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "[31m¡°ÉÃÈëÕß--ËÀ¡± 
[0;37;0m",
]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

      
         
          if ((!myfam || myfam["family_name"] != "ÌúÕÆ°ï") && dir == "northup" && (int)me->query("combat_exp", 1) >= 10000 &&
                objectp(present("heiyi bangzhong", environment(me))))
        return notify_fail("ºÚÒÂ°ïÖÚ³éµ¶À¹×¡ÄãµÄÈ¥Â·£¬ËµµÀ£º¡°Äã²»ÊÇÌúÕÆ°ïµÜ×Ó£¬²»ÄÜÉÏÉ½£¡\n");

        return ::valid_leave(me, dir);
}
