// SN:8_@0K4^7n\6?Gkj[
// File(/data/room/xiaodongxi/huayuan.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "ºó»¨Ô°");
	set ("long", @LONG
°®µÄĞ¡ÎİµÄºó»¨Ô°¡£ÖÖ×ÅÒ»Ğ©²É×ÔÎåºşËÄº££¬ÓÄÁÖÇú¾¶µÄÆæ»¨Òì
²İ£¬ÓÅÑÅÇåĞÂ¡£ÖĞ¼äÓĞÒ»Ô°ºş£¬ÀïÃæÊıÊ®Î²¿×È¸Óã×ÔÔÚµÄÓÆµ´£¬ºş°¶
±ß£¬°Ú·Å×ÅÒ»¸öË®¾§ÆåÅÌ×À¡£Ğ¡Ì«±£ÓĞÊ±¶ÁÊéÁ·ÎäÆ£¾ëÁË£¬¾Íµ½ÕâÀï
ÉÔ×÷ĞİÏ¢£¬¹ÛÉÍ»¨²İ³æÓã£¬ÒÔâùÇé×ÔÀÖ£¬»òĞíÄÜÍ»·¢Áé¸Ğ¡£[2;37;0m
LONG );

	set("exits", ([
                "south"  : __DIR__"houyuan",
                "east"   : __DIR__"zhulin",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        set("room_key", "1 of xiaodongxi");
        setup();

        set("KEY_DOOR", ([
                "exit" : "west",
                "room" : __DIR__"jusuo",
        ]));
    
        set("room_owner", "Ã¼Ã¼");
        set("room_owner_id", "xiaodongxi");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}

void init()
{
        ::init();
        add_action("do_sit", "sit");
        this_player()->delete_temp("has_sit");
}

int do_sit(string arg)
{
        object me;

        me = this_player();
        if (me->query_temp("has_sit"))
        {
                message_vision("$N×øÔÚÄÇÀïÒ¡°¡Ò¡£¬ºÃ²»ã«Òâ¡£\n", me);
                return 1;
        }

        message_vision("$NÕÒÁËµÄµØ·½×÷ÁËÏÂÀ´£¬¿´ÉÏÈ¥ÇáËÉ¶àÁË¡£\n", me);
        me->set_temp("has_sit", 1);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("has_sit"))
        {
                message_vision("$Nµ§µ§³¾ÍÁ£¬Õ¾ÁËÆğÀ´¡£\n", me);
                me->delete_temp("has_sit");
        }

        return ::valid_leave(me, dir);
}
