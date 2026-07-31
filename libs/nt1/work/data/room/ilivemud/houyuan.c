// SN:L;:3:k\6HedZa4i[
// File(/data/room/ilivemud/houyuan.c) of ilivemud's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "×íÎÌÍ¥ºóÔº");
	set ("long", @LONG
ÕâÀïÊÇ×íÎÌÍ¥µÄºóÔº£¬ÖĞÑëÊÇÒ»¸öºÜ´óµÄÓÎÓ¾³Ø¡£ÀïÃæµÄË®Ó³ÕÕ
×ÅÀ¶Ìì°×ÔÆµÄÓ°×Ó¡£Ò»¿ÃÕÇ·ÅµÄÉ½²è»¨ÎüÒıÁËÃÛ·äºÍºûµûÔÚÖÜÎ§·ÉÎè£¬
ÖÜÎ§µÄ»¨ÆÔÖĞ²»Ê±´«À´¸÷ÖÖ·Ò·¼£¬Ê¹Äã¸Ğ¾õĞÄ¿õÉñâù£¬ÈçÁÙÏÉ¾³¡£[2;37;0m
LONG );

	setup();

	set("exits", ([
                "south"  : __DIR__"dating",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);

        set("room_owner", "°¬ÂíµÂ");
        set("room_name", "×íÎÌÍ¥");
        set("room_id", "zwt");
        set("room_owner_id", "ilivemud");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
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
