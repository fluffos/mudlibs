// Modify By River 98/12
inherit ROOM;
void create()
{
	set("short", "Ê¯Îİ");
	set("long", @LONG
ÑÛÇ°ÊÇÒ»¸öÊ¯Îİ¡£ÕâÊ¯ÎİÄ£ÑùÉõÊÇÆæ¹Ö£¬ÒÔÒ»¿éÇ§°Ù½ïÖØµÄ´óÊ¯Æö³É£¬°¼
°¼Í¹Í¹£¬ÍğÈ»ÊÇÒ»×ùĞ¡É½£¬¶´¿Ú±»Ò»¿é»¨¸Ú¾ŞÑÒ£¨yan)·â×¡£¬ÑÒ±ßµ½´¦Â¶³ö¿Õ
Ï¶£¬ÓĞµÄÖ»Á½Èı´ç¿í£¬ÓĞµÄÈ´ÓĞ³ß¿í¡£° 
LONG
	);
        set("outdoors", "´óÀí");

	set("exits", ([
		"south" : __DIR__"muwu1",
	]));

        set("item_desc", ([
            "yan" : "ÕâÊÇÒ»¿éÌØ±ğ´óµÄÑÒÊ¯£¬¶Â×¡ÁËÃÅ¿Ú£¬Ê¹ÈËÎŞ·¨½øÈëÎİÄÚ¡£\n",
        ]));

        setup();
}

void init()
{
        add_action("do_tui", "tui");
        add_action("do_tui", "push");
}

int do_tui(string arg)
{
        int i;
        i = this_player()->query("neili");
        if( !arg || arg!="yan" ) 
           return notify_fail("ÄãÒªÍÆÊ²Ã´£¿\n");        
          message_vision("$NÕ¾ÔÚÃÅÇ°£¬°ÑË«ÕÆ·ÅÔÚÑÒÉÏ£¬ÉîÉîµÄÎüÁËÒ»¿ÚÆø£¬Ë«±ÛÒ»·¢¾¢£¬´óºÈÒ»Éù¡°¿ª¡±¡£\n", this_player());
        if (i>=800) {
          message_vision("$NÖ»ÌıÒ»ÕóºäÏì£¬´óÊ¯»º»ºµÄÒÆ¿ªÁË£¡\n", this_player());
          set("exits/enter", __DIR__"muwu3");
          this_player()->add("neili",-800);
          remove_call_out("close");
          call_out("close", 5, this_object());
          }
        else {
          message_vision("$NÈ´¼û´óÊ¯ÎÆË¿²»¶¯£¬¿´À´$NµÄÄÚÁ¦»¹²»¹»¡£\n", this_player());
          this_player()->set("neili",0);
          }
    return 1;
}

void close(object room)
{
         message("vision","´óÊ¯»º»ºÒÆ¶¯£¬°ÑÊ¯ÎİÔÙ´Î·â×¡ÁË¡£\n", room);
         room->delete("exits/enter");
}
