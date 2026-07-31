// SN:A4Tc>GeE?i:a@UhR
// File(/data/room/lingling/woshi.c) of lingling's room
// Create by LUBAN written by Doing Lu

#include <room.h>
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "ôáÇä¾ÓÎÔÊÒ");
	set ("long", @LONG
[1;36mÕâÊÇÒ»¼ä¿í³¨ÊæÊÊµÄºÀ»ª¿Í·¿£¬´²±ßµÄÐ¡²è¼¸ÉÏ°ÚÊÎÖø¹ÅÀÏ
    µÄ»¨Æ¿£¬ÉÏÃæ²åÂúÁËÐÂÏÊÃÀÀöµÄ»¨Æ¿£¬´Ó»¨Æ¿ÖÐÆ®³öÕóÕóÇå
    µ­µÄÜÔÀò»¨Ïã¡£ÅÔ±ß»¹ÓÐÒ»Ãæ»­ÆÁ£¬»­ÖÐµÄÂí¶ùèòèòÈçÉú£¬
    ÓÐÖøÒ»¹ÉÍòÂí±¼ÌÚµÄºÀ·ÅÆøÂõ£¬Ò²Òò´ËÊ¹µÄÕâ¸ö·¿¼äÈáÖÐ´ø
    ¸Õ£¬ÓÐÒ»ÖÖÆæÃîµÄÔÏÎ¶³ä³âÔÚÕû¸ö·¿¼äÖÐ¡£[2;37;0m
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
    
        set("room_owner", "Ä½ÈÝôá");
        set("room_name", "ôáÇä¾Ó");
        set("room_id", "ling");
        set("room_owner_id", "lingling");
        set("room_position", "É½Â·");
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
