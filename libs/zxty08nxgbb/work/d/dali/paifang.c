// Room: /d/dali/paifang.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ18ÈÕ£¬±±¾©Ê±¼ä£º21Ê±23·Ö37Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33mÅÆ·»[2;37;0m");
	set("long", @LONG
ÄãÀ´µ½ÁËÒ»×ùÅÆ·»Ö®Ç°£¬ÅÆ·»ÉÏÌá×ÅËÄ¸ö½ğ±Ê´ó×Ö¡¸[1;33mÊ¥µÀ¹ã´È[2;37;0m¡¹¡£
Ï¦ÑôÕÕÔÚ»ÆÍß¹¬µîµÄÁğÁ§ÍßÉÏ£¬½ğ±Ì»Ô»Í£¬ÁîÈËÄ¿ÎªÖ®ìÅ¡£Ç°ÃæÊÇÒ»×ù
¹¬µî£¬¹¬ÃÅÉÏĞ´×Å¡¸[1;33mÊ¥´È¹¬[2;37;0m¡¹Èı¸ö´ó×Ö¡£
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guangchang",
  "north" : __DIR__"huanggong1",
]));

        set("objects", ([
                __DIR__"npc/shiwei" : 2,
        ]));

	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
    if(dir=="north")
    {
     if( this_player()->query("combat_exp")>256000 )
        {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("shi wei", environment(me))) &&
                   living(present("shi wei", environment(me))))
                    return notify_fail("[1;33m½ğ¼×´øµ¶ÊÌÎÀ[2;37;0mÉÏÇ°µ²×¡Äã£¬ÀÊÉùËµµÀ£ºÕâÎ»" +
                        RANK_D->query_respect(me) + "Çë·ÅÏÂ±øÈĞ¡£\n"
                        "Äã¿ÉÒÔ½ø¹¬£¬µ«²»µÃÊÖ³Ö±øÈĞ¡£\n");
        return ::valid_leave(me, dir);
        }
     else
     {
         if(objectp(present("shi wei", environment(me)))&&living(present("wei", environment(me))))
            return notify_fail("[1;33m½ğ¼×´øµ¶ÊÌÎÀ[2;37;0mÀ¹×¡ÄãÂîµÀ£º¡°ÄãÒÔÎªÄãÊÇË­°¡£¿Ò»¸öÑ°³£°ÙĞÕ£¬ÄÑµÀ»¹Ïë½ø¹¬½ú¼û»ÊÉÏ£¿£¡\nÄãÕâ" + RANK_D->query_rude(me) +"¿ì¸øÎÒ¹öÔ¶µã¶ù£¬²»È»±ğ¹ÖÎÒ²»¿ÍÆø£¡¡±\n");
      }
    }   
return ::valid_leave(me, dir);
}


