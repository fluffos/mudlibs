// SN:J8NVT65`5Sm;4Qih
// File(/data/room/xiaodongxi/woshi.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

#include <room.h>
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "ÎÔÊÒ");
	set ("long", @LONG
ÇÉÑÅ±ðÖÂµÄÎÔ·¿¡£Ò»½øÃÅ¾ÍÎÅµ½Ò»ÖÖÓÆÓÆµÄÇåÏã£¬Ô²×¶ÐÍµÄÎÝ¶¥
¼âÏâÇ¶×ÅÒ»¿ÅÃÀÀöµÄÒ¹Ã÷Öé£¬±ÚÉÏ¹Ò×ÅÒ»·ù¹¤±ÊÊËÅ®Í¼¡£ÄÏ´°ÏÂ°Ú·Å
×ÅÒ»ÕÅÐÄÐÍµÄº®±ù´²£¬ÒþÔ¼ÖÐÊÍ·Å×ÅË¿Ë¿µÄº®Æø¡£Ò»Ï®µ­×ÏÉ«µÄÉ´ÕÊ
ÇáÂ£×ÅÐ¡´²£¬Î¢·çÇáÇá·÷¹ý£¬×ÏÉ´Ò²Ëæ·ç·ÉÎè¡£Í¸¹ý¾«ÃÀµÄµñ»¨Ë®¾§
´°ÒÀÏ¡¿ÉÒÔ¿´µ½Ô¶´¦µÄÖñÁÖ¡£[2;37;0m
LONG );

        set("exits", ([
                "down" : __DIR__"jusuo",
        ]));

        set("objects", ([
                "/adm/npc/obj/xiang" : 1,
        ]));

        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
        setup();
    
        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄÐ¡ÎÝ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ð¡µÀ");
}

void init()
{
        add_action("do_findbaby", "xunzhao");
}

int do_findbaby(string arg)
{
        object me = this_player(), baby;
        string file;

        if (! arg || (arg != "baby" && arg != "child") ||
            ! is_room_owner(me)) 
                return 0;

        if (! me->query("couple/child"))
                return notify_fail("ÄãÓÖ»¹Ã»ÓÐº¢×Ó£¬À´ÕâÀï´ÕÊ²Ã´ÈÈÄÖ°¡£¿\n");

        if (objectp(baby = find_living(me->query("couple/child")))
        &&  environment(baby) && baby->is_baby())
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
                me->delete("couple/child");
                me->delete("couple/child_name");
        }
        return 1;
}      
