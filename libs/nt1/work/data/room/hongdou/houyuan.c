// SN:_EccE?O_fi;`ileZ
// File(/data/room/hongdou/houyuan.c) of hongdou's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "²Ğ°®¾ÓºóÔº");
	set ("long", @LONG
Ò»Æ¬´äÂÌµÄÖñÁÖ£¬·Ç³£ÓÄ¾²£¬·ç¶ùÒ»Æğ¾ÍÄÜÌıµ½ÖñÒ¶É³É³×÷Ïì¡£
ÓÄÁÖÉî´¦×øÂä×ÅË¼İÕÍ¤£¬Í¤ÖĞ°Ú·Å×ÅÒ»¸öË®¾§ÆåÅÌ×À¡£ÅÔ±ßµÄÔÂÑÀºş
ÖĞ£¬ÊıÊ®Î²¿×È¸ÓãÓÆÏĞ×ÔÔÚµÄÓÎµ´¡£[2;37;0m
LONG );

	setup();

	set("exits", ([
                "south"  : __DIR__"dating",
	]));

        set("outdoors", "gumu");
        set("sleep_room", 1);

        set("room_owner", "ºì¶¹");
        set("room_name", "²Ğ°®¾Ó");
        set("room_id", "xiaohan");
        set("room_owner_id", "hongdou");
        set("room_position", "º®Ë®Ì¶");
}

void init()
{
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
