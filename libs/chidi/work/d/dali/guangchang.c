// Room: /d/dali/guangchang.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ19ÈÕ£¬±±¾©Ê±¼ä£º21Ê±28·Ö14Ãë¡£

inherit ROOM;

void create()
{
	set("short", "´óÀí³ÇÖĞĞÄ");
	set("long", @LONG
ÕâÀï¾ÍÊÇ´óÀí³ÇµÄ³ÇÖĞĞÄ£¬´óÀí³ÇµÄÖ÷Òª½ÖµÀ¶¼ÔÚÕâÀï½»»á£¬¿í¹ãµÄÂ·ÃæÔÚÕâÀï
ĞÎ³ÉÁËÒ»¸ö·½Ô°Ô¼Ê®ÓàÕÉµÄ¹ã³¡¡£¹ã³¡³ÊÁâĞÎ£¬Ò»È¦Î§µÄ¶¼ÊÇĞ¡··£¬ÒÕÈË£¬ºÍ¿´ÈÈÄÖ
µÄ¡£ÎõÎõÈÁÈÁµÄÈËÈºÖĞÒ²ÉÙ²»ÁËĞ©¸öÅÜ½­ºşµÄ£¬ÔÓË£Éù£¬½ĞÂôÉù´ËÆğ±Ë·ü¡£Ò»Ğ©ÔÚÖĞ
Ô­ÎÅËùÎ´ÎÅµÄĞÂÏÊÊÂÎïÁîÒ»Ğ©³õÈë½­ºşµÄÄêÇáÈËĞË·Ü²»ÒÑ¡£Î»ÓÚ¹ã³¡ÖĞĞÄÓĞÒ»¸ö²»´ó
²»Ğ¡µÄË®³Ø£¬Ò»¾Ş´óµÄÄÖÁúÊ¯ÖùËÊÁ¢Ë®³ØÖĞÑë£¬Ò»ãéãéµÄ¸ÊÈªË®´ÓÊ¯ÖùµÄÁú×ìÖĞÓ¿³ö£¬
·ÅÑÛÏòÊ¯ÖùÉÏ¿´È¥£¬Ö»¼ûÉÏÊé£º

                          [1;33m~   Ìì  ´ó  ~[2;37;0m

                          [1;33m~   ÏÂ  Àí  ~[2;37;0m

                          [1;33m~   Ì«  ÖĞ  ~[2;37;0m

                          [1;33m~   Æ½  ĞË  ~[2;37;0m

LONG
	);
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"paifang",
  "west" : __DIR__"xidajie1",
  "east" : __DIR__"dongdajie1",
  "south" : __DIR__"nandajie1",
        "up" : __DIR__"gongzuoshi",
]));

        set("objects", ([
                __DIR__"npc/dlxunbu" : 2,
                __DIR__"npc/liumangtou" : 1,
                __DIR__"npc/liumang" : 2,
        ]));
	setup();
        "/d/board/dali_b"->foo();
}

int valid_leave(object me, string dir)
{
	object tagob,thisob;

	thisob = this_object();

	if (wizardp(me))
		return 1;

	if (dir == "up")
	{
		if(!objectp( tagob = find_object( query("exits/"+dir) ) ))
		{
			tagob = load_object( query("exits/"+dir) );
		}

		if( sizeof(all_inventory(tagob)) > 25 )
		{
			return notify_fail("ÄÇ±ßÒÑ¾­ÈËÂúÁË£¡£¡\n");
		}
	}

	return ::valid_leave(me, dir);
}

