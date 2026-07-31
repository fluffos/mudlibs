// SN:65nG<1L:h6<\`lF4
// File(/data/room/zhang/dulewu.c) of zhang's room
// Create by LUBAN written by Doing Lu
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "ÕÅµ¼»ùµØÐ¡ÎÝ");
	set ("long", @LONG
Á½°Ù¸ö·¢Éä¾®¼ÜÔÚ´ËÒ»×ÖÅÅ¿ª£¬ÏóµÈ×ÅÄãµãÅÚ£¬Õæ¸öÊÇÕÅÈý·á´ó
µ¼ÑÝÃÜÄ±¡­¡­µÄµØ·½¡£[2;37;0m
LONG );

        set("objects", ([
                "/adm/npc/obj/xiang" : 1,
        ]));
	setup();

        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    

        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
    
        set("room_owner", "ÕÅÈý·á");
        set("room_name", "ÕÅµ¼»ùµØ");
        set("room_id", "zhang");
        set("room_owner_id", "zhang");
        set("room_position", "ËéÊ¯Ð¡µÀ");
}

void init()
{
        ::init();
        add_action("do_findbaby", "xunzhao");
}

int do_findbaby(string arg)
{
        object me = this_player(), baby;
        string file;

        if (! arg || (arg != "baby" && arg != "child") ||
            ! is_room_owner(me)) 
                return 0;

        if (! me->query("couple/child_id"))
                return notify_fail("ÄãÓÖ»¹Ã»ÓÐº¢×Ó£¬À´ÕâÀï´ÕÊ²Ã´ÈÈÄÖ°¡£¿\n");

        if (objectp(baby = find_living(me->query("couple/child_id")))
        &&  environment(baby) && baby->query("is_baby"))
                return notify_fail("ÄãÃÇµÄº¢×ÓÒÑ¾­ÅÜ³öÈ¥ÍæÁË£¬ºÃºÃËÄ´¦ÕÒÕÒ°É£¡\n");

        if (me->query("gender") == "Å®ÐÔ")
                file = read_file("/data/baby/" + me->query("id") + ".o");
        else file = read_file("/data/baby/" + me->query("couple/id") + ".o");

        if (stringp(file))
        {
                baby = new("/clone/user/baby");

                baby->load_baby(me);
                baby->move(environment(me));
                message_vision("ÄãºöÈ»¿´µ½´²µ×ÏÂ" +
                        ({"Ì½³öÒ»¿ÅÐ¡ÄÔ¹Ï", "Éì³öÒ»Ë«Ð¡½ÅÑ¾", "Éì³öÒ»Ö§Ð¡ÊÖ"})
                        [random(3)] + "£®£®£®\n", me);

        } else
        {
                tell_object(me, MAG "ÄãÃÇµÄº¢×Ó²»ÐÒØ²ÕÛÁË£¬Çë½Ú°§°É¡£\n" NOR);
                me->delete("couple/child_id");
                me->delete("couple/child_name");
        }
        return 1;
}      
