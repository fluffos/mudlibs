// SN:Eibi=G\K?ec[PPe8
// File(/data/room/hongdou/woshi.c) of hongdou's room
// Create by LUBAN written by Doing Lu

#include <room.h>
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "²Ð°®¾ÓÎÔÊÒ");
	set ("long", @LONG
ÕâÊÇºì¶¹µÄÎÔÊÒ£¬ÊÕÊ°µÃ¸É¾»Õû½à¡£ÄÏ´°ÏÂÊÇÒ»ÕÅºìÄ¾´ó´²£¬´²
±ßÓÐÒ»¸ö¹ñ×Ó£¬»¹ÓÐÒ»¸öÊé¼Ü¡£Õû¼äÎÝ×ÓËäÈ»ÆÓËØ£¬µ«¿ÉÒÔËµÊÇÑùÑù
¾ãÈ«£¬²¢²»È±ÉÙÊ²Ã´¶«Î÷¡£[2;37;0m
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
    
        set("room_owner", "ºì¶¹");
        set("room_name", "²Ð°®¾Ó");
        set("room_id", "xiaohan");
        set("room_owner_id", "hongdou");
        set("room_position", "º®Ë®Ì¶");
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
