// SN:3CS1m3`4\?VQ^I@E
// File(/data/room/lingling/houyuan.c) of lingling's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "ôáÇä¾ÓºóÔº");
	set ("long", @LONG
[1;36mÄã×ß³öÁËÄ¾ÎİÀ´µ½ºóÔº£¬Ò»Õó»¨ÏãÍ»È»ÆË±Ç¶øÀ´£¬ÑÛÇ°¾¡ÊÇ
    ²»Ôø¼û¹ıµÄÆæ»¨Òì¹û£¬¸÷ÖÖÑÕÉ«¶¼ÓĞ£¬Îå²ÊçÍ·×¡£»ğºìµÄÑı
    µûÔÚ»¨´Ô¼ä´©Ëó£¬¸üÌíÁË¼¸·ÖÃÀ¸Ğ£¬ÕâÊ±²»½ûÈÃÈËÒÉ»ó£¬Õâ
    Æ¬ÃÀÀöµÄ»¨Ô°µ½µ×ÊÇË­ÔÔÖÖµÄ£¿[2;37;0m
LONG );

	setup();

	set("exits", ([
                "south"  : __DIR__"dating",
	]));

        set("outdoors", "hangzhou");
        set("sleep_room", 1);

        set("room_owner", "Ä½Èİôá");
        set("room_name", "ôáÇä¾Ó");
        set("room_id", "ling");
        set("room_owner_id", "lingling");
        set("room_position", "É½Â·");
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
