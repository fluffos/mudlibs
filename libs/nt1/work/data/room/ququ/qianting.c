// SN:5>Y\i2MB2OW:4jIn
// File(/data/room/ququ/qianting.c) of ququ's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "ÌìÖ®Çù³²Ç°Í¥");
	set ("long", @LONG
µØÉÏÇ½ÉÏÅÀÂúÁËÃÜÃÜÂéÂéµÄÇù£¬°×É­É­µÄ¹ÇÍ·ÔÚÇù¶ÑÖĞÈôÒşÈôÏÖ,
Õâ¾ÍÊÇÇùÖ®³²¡£[2;37;0m
LONG );

	set("exits", ([
                "south"  : __DIR__"dayuan",
                "east"   : __DIR__"zuowei",
                "west"   : __DIR__"youwei",
	]));

        set("objects", ([
                "/d/room/roomnpc/laopu" : 1,
        ]));

        set("outdoors", "unknow");
        set("no_sleep_room", 1);
        set("gate", "close");
        setup();

        ob = present("saodi laopu", this_object());
        ob->set("coagents", ({
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 1" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 1" ]),
        }));

        set("room_owner", "ÌìÇù");
        set("room_name", "ÌìÖ®Çù³²");
        set("room_id", "quququ");
        set("room_owner_id", "ququ");
        set("room_position", "ÃûÈËÌÃ");
}

void init()
{
        add_action("do_push", "push");
        add_action("do_close", "close");
}

int do_push()
{
        object ob;
        object me;
        object room;

        if (query("gate") == "open")
                return notify_fail("´óÃÅ¿ª×ÅÄØ£¬Äã»¹ÍÆÊ²Ã´£¿\n");

        me = this_player();
        ob = present("saodi laopu", this_object());
        if (me && (! ob || ! living(ob) || ob->is_owner_permit(me)))
        {
                message_vision("$NÓÃÁ¦Ò»ÍÆ´óÃÅ£¬¾ÍÌı¼û´óÃÅ¡°Ö¨Ñ½Ñ½¡±µÄ¿ªÁË¡£\n",
                               me);
        } else
        if (me && ! ob->is_owner(me))
        {
                message_vision("$NÉìÊÖÀ¹×¡$n£¬¿Í¿ÍÆøÆøµÀ£º¡°¶Ô²»Æğ£¬ÕâÎ»" +
                               RANK_D->query_respect(me) + "»¹ÊÇÇë»Ø"
                               "°É£¡¡±\n", ob, me);
                return 1;
        } else
        if (ob && living(ob))
        {
                message_vision("$nÁ¬Ã¦ÅÜÉÏÇ°À´£¬¶Ô$NµÀ£º¡°Ö÷ÈËºÎ±ØÇ×"
                        "ÀÍ£¬ÎÒÀ´°É£¡¡±\n$n×ßÉÏÇ°È¥£¬ÓÃÁ¦½«´óÃÅ¡°Ö¨Ñ½"
                        "Ñ½¡±µÄÍÆ¿ªÁË¡£\n", me, ob);
        } else
        {
                message("vision",  "´óÃÅ¡°Ö¨Ñ½Ñ½¡±µÄ±»ÈË´ò¿ªÁË¡£\n",
                        this_object());
        }

        room = get_object(__DIR__"zoudao");
        message("vision", "´óÃÅ¡°Ö¨Ñ½Ñ½¡±µÄ±»ÈËÍÆ¿ªÁË¡£\n", room);
        set("gate", "open");
        set("exits/north", __DIR__"zoudao");
        room->set("exits/south", __FILE__);
        room->set("gate", "open");
        remove_call_out("do_close");
        call_out("do_close", 10, 0, 1);
        return 1;
}

int do_close(string arg, int n)
{
        object ob;
        object me;
        object room;

        if (query("gate") == "close")
                return notify_fail("´óÃÅ¹Ø×ÅÄØ£¬Äã»¹ÔÙ¹ØÒ»±é£¿\n");

        me = this_player();
        ob = present("saodi laopu", this_object());
        if (! n && me && (! ob || ! living(ob)))
        {
                message_vision("$NÓÃÁ¦Ò»À­´óÃÅ£¬¾ÍÌı¼û´óÃÅ¡°Ö¨Ñ½Ñ½¡±µÄ¹ØÉÏÁË¡£\n",
                               me);
        } else
        if (! n && me && ! ob->is_owner(me))
        {
                message_vision("$N×ßÉÏÇ°È¥£¬ÓÃÁ¦ºÏÉÏ´óÃÅ¡£\n", me);
        } else
        if (! n && me && ob->is_owner(me))
        {
                message_vision("$nÁ¬Ã¦ÅÜÉÏÇ°À´£¬¶Ô$NµÀ£º¡°Ö÷ÈËºÎ±Ø"
                        "Ç×ÀÍ£¬ÎÒÀ´°É£¡¡±\n$n×ßÉÏÇ°È¥£¬ÓÃÁ¦ºÏÉÏ´óÃÅ¡£\n",
                        me, ob);
        } else
        if (ob && living(ob))
        {
                message("vision", ob->name() + "×ßÉÏÇ°È¥£¬ÓÃÁ¦ºÏÉÏ´óÃÅ¡£\n",
                        this_object());
        } else
        {
                message("vision", "´óÃÅ¡°Ö¨Ñ½Ñ½¡±µÄ±»ÈË¹ØÉÏÁË¡£\n",
                        this_object());
        }

        room = get_object(__DIR__"zoudao");
        message("vision", "´óÃÅ¡°Ö¨Ñ½Ñ½¡±µÄ±»ÈË¹ØÉÏÁË¡£\n", room);
        set("gate", "close");
        delete("exits/north");
        room->delete("exits/south");
        room->set("gate", "close");
        return 1;
}

string long()
{
        string msg;
        msg = "    ";
        if (present("lao jiaren"))
                msg += "Ò»ÀÏ¼ÒÈËÂıÂıµÄ»ÓÎè×ÅÉ¨°Ñ£¬´òÉ¨×ÅÂäÒ¶¡£";

        if (query("gate") != "open")
                msg += "Ïò±±ÍûÈ¥£¬ÓĞÒ»ÉÈ´óÃÅ½ô½ôµÄ¹Ø±Õ×Å¡£";
        else
                msg += "´óÃÅ³©¿ª£¬Ô¶Ô¶ÍûÈ¥£¬ÒşÈ»¿É¼ûÓ­¿ÍÌü¡£";

        return query("long") + sort_string(msg, 60, 0);
}

int valid_leave(object me, string dir)
{
        object ob;

        ob = present("saodi laopu", this_object());
        if (dir != "north" || ! objectp(ob) || ! living(ob))
                return ::valid_leave(me, dir);

        if (ob->is_owner(me))
        {
                message_vision("$NÍäÑü¶Ô$nµÀ£º¡°Çë½ø£¡¡±\n", ob, me);
                return ::valid_leave(me, dir);
        }

        if (ob->is_owner_permit(me))
        {
                message_vision("$N¶Ô$nµÀ£º¡°¼´È»ÊÇÖ÷ÈËµÄÅóÓÑ£¬µ«½øÎŞ·Á¡£¡±\n",
                               ob, me);
                return ::valid_leave(me, dir);
        }

        message_vision("$NÉìÊÖÀ¹×¡$n£¬µÀ£º¡°·ÇÇëÄªÈë£¡¡±\n", ob, me);
        return 0;
}
