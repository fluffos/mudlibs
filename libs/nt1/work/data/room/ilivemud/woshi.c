// SN:i0JJ?AV5bfKeQc>k
// File(/data/room/ilivemud/woshi.c) of ilivemud's room
// Create by LUBAN written by Doing Lu

#include <room.h>
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "×íÎÌÍ¥ÎÔÊÒ");
	set ("long", @LONG
Ö÷ÈËµÄÎÔÊÒ¿ÉÒÔÎÅµ½Ë¿Ë¿¹ë·¿µÄÎ¶µÀ¡£²àÃæÂäµØ´°ÅÔ±ßÒ»ÕÅ´ó´²£¬
ÉÏÃæÊÇkingsizeµÄÏ¯ÃÎË¼¡£´²ÉÏÕûÆëµÄ·Å×ÅÔ§ÑìÕíÍ·¡£´²±ßÊÇÖ÷ÈËµÄ
Êé×À£¬ÉÏÃæ·Å×ÅÒ»Ì¨Ö÷ÈËÓÃÀ´ÉÏmudµÄ±Ê¼Ç±¾µçÄÔ£¬ÆÁÄ»²»Í£µÄÉÁË¸×Å
»úÆ÷ÈËÔÚ¹¤×÷µÄÇé¾°¡£Êé×ÀÅÔÓÐÁ½¸ö¹ñ×Ó£¬ÉÏÃæ»¹ÓÐÒ»¸öÊé¼Ü¡£Õû¼ä
ÎÝ×ÓËäÈ»ÆÓËØ£¬µ«ÊÇ¿ÉÒÔËµÊÇÑùÑù¾ãÈ«£¬²¢²»;È±ÉÙÊ²Ã´¶«Î÷¡£[2;37;0m
LONG );

        set("objects", ([
                "/adm/npc/obj/xiang" : 1,
        ]));
	setup();

        set("exits", ([
                "west" : __DIR__"dating",
        ]));

        create_door("west", "Ä¾ÃÅ", "east", DOOR_CLOSED);
        
    
        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
    
        set("room_owner", "°¬ÂíµÂ");
        set("room_name", "×íÎÌÍ¥");
        set("room_id", "zwt");
        set("room_owner_id", "ilivemud");
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
