// SN:[:hk^]9>FfNc8nQ9
// File(/data/room/god/huayuan.c) of god's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "ºó»¨Ô°");
	set ("long", @LONG
[1;32mÕâÊÇÔÆº£µÄºó»¨Ô°£¬ÖÖ×ÅÒ»Ğ©ÉÏµÛ²É×ÔÎåºşËÄº£¡¢ÃûÉ½´ó´¨µÄÆæ»¨Òì²İ£
¬
ÃÀÀö·Ç³£¡£ÉÏµÛÓĞÊ±¶ÁÊéÁ·ÎäÆ£¾ëÁË£¬¾Íµ½ÕâÀïÉÔ×÷ĞİÏ¢£¬¹ÛÉÍ»¨²İÒÔâù

Çé×ÔÀÖ£¬»òĞíÄÜÍ»·¢Áé¸Ğ£¬ÓĞËùÁìÎò¡£Î÷Ãæ¾ÍÊÇÍ¨ÍùÖ÷ÈË¾ÓËùµÄÌúÃÅ£¬¶«ÃæÔò

ÊÇÒ»Æ¬ÖñÁÖ¡£[2;37;0m
LONG );

	set("exits", ([
                "south"  : __DIR__"houyuan",
                "east"   : __DIR__"zhulin",
	]));

        set("outdoors", "unknow");
        set("sleep_room", 1);
        set("room_key", "1 of god");
        setup();

        set("KEY_DOOR", ([
                "exit" : "west",
                "room" : __DIR__"jusuo",
        ]));
    
        set("room_owner", "ÉÏµÛ");
        set("room_owner_id", "god");
        set("room_name", "ÔÆº£");
        set("room_id", "god");
        set("room_position", "ÃûÈËÌÃ");
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
