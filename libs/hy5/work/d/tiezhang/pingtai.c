// Room: /u/zqb/tiezhang/pingtai.c

inherit ROOM;
string look_ditu();
void create()
{
	set("short", "[34mÉ½¼äÆ½Ì¨[0;37;0m");
	set("long", @LONG
    ÕâÀïÊÇÉ½¼äµÄÒ»¿éÆ½µØ¡£É½ÊÆÔÚÕâÀï¿ªÊ¼·ÖÖ§£¬´£Á¢ÔÚÃæÇ°µÄÓĞ 
Îå×ù¸ßËÊÈëÔÆµÄÉ½·å£¬ĞĞËÆÈËµÄÎåÖ¸£¬¡°ÌúÕÆÉ½¡±Ö®ÃûÓÉ´Ë¶øµÃ¡£Îå·åËäÍ¬ 
´¦´ËÉ½£¬µ«Ä´Ö¸·åÖ®ĞÛÎ°£¬Ê³Ö¸·åÖ®ÏÕ¾ş£¬ÖĞÖ¸·åÖ®¸ßËÊ£¬ÎŞÃû·åÖ®ÆæÀö£¬ 
Ğ¡Ö¸·åÖ®ĞãÃÀ£¬Ôò¸÷ÓĞÌØÉ«£¬¸÷ÉÃÊ¤³¡¡£ÔÚÆ½Ì¨Ò»²àµÄ´óÊ¯ÉÏ£¬¿Ì×ÅÒ»¸±µØ
Í¼(ditu)¡£
LONG	);
	set("item_desc", ([ 
        "ditu" : (: look_ditu :),
]));
	set("exits", ([ 
  "westup" : __DIR__"shanlu-5",
  "northeast" : __DIR__"shangu-1",
  "eastup" : __DIR__"sslu-1",
  "southdown" : __DIR__"shanlu-4",
  "northwest" : __DIR__"hclu",
  "northup" : __DIR__"shanlu-6",
]));
    set("objects", ([ 
    __DIR__"npc/huiyi" : 3,
    ]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	
}

string look_ditu()
{
    return
    "\n"
    "############################\n"
    "#          ÖĞÖ¸·å          #\n"
    "#            ||            #\n"
    "#    ÎŞÃû·å  ||  Ê³Ö¸·å    #\n"
    "#         \\ || //         #\n"
    "#          \\||//          #\n"
    "# Ğ¡Ö¸·å====Æ½Ì¨====Ä´Ö¸·å #\n"
    "############################\n";
    "\n";
}
