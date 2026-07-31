// Room: /d/snow/herbshop1.c

inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", "ÃÜÊÒ");
        set("long", @LONG
ÕâÊÇÒ»¼ä¹âÏßÒõ°µµÄÃÜÊÒ£¬´ÓµØÉÏºñºñµÄ»Ò³¾¿´µÃ³öÀ´ÕâÀïºÜÉÙÓÐ
ÈË³öÈë£¬¿¿Î÷±ßµÄµØÉÏ·Å×ÅÒ»¸±½ÅÁÍ£¬Á¬×ÅÒ»ÌõÌúÁ´ÏâÔÚÇ½ÉÏ£¬²»ÖªµÀ
ÊÇÓÃÀ´ËøÊ²÷áÈË£¬ÄÏÃæµÄÇ½(wall)ÊÇÓÃºìÉ¼Ä¾×öµÄ£¬¸úÁíÍâÈýÃæµÄ»ÒÍÁ
Ç½±ÈÆðÀ´ÏÔµÃÓÐÐ©²»Ñ°³£¡£ÄÏ±±±ßÊÇØ¤°ïµÄÁ·¹¦·¿.º
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"chuchang",
               "north" : __DIR__"square",
               "south" : __DIR__"square2",
        ]));
        set("item_desc", ([
                "wall" : "Ò»¶Â°ß°þÁÜÀìµÄÇ½¡£\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_move", "push");
        add_action("do_move", "break");
}

int do_move(string arg)
{
        object paper, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="wall" )
        {
                if (!query("had_staffbook") && me->query("neili",)>200)
                {
                        message_vision(
"$NÔË×ãÄÚÁ¦ÃÍÏòÆÆÇ½ÅÄÈ¥£¬Ö»Ìý»©µÃÒ»ÕóÏì£¬Ç½¶¥ÂäÏÂÀ´Ò»±¾ÆÆÖ½...¡£\n", this_player());
message("channel:rumor", MAG"¡¾Ò¥ÑÔ¡¿Ä³ÈË£º"+this_player()->query("name")+"ÄÃµ½ÕÈ·¨Í¨½âÀ²¡£\n"NOR, users());
                        paper = new("/clone/book/staff_book");
                        paper->move(__FILE__);
                        set("had_staffbook", 1);
                        return 1;
                }
                message_vision(
"$NºÝºÝÒ»Í·×²ÔÚÇ½£¬ÑÛÇ°¶ÙÊ±ÏÊºìÒ»Æ¬...¡£\n", this_player());
                this_player()->receive_damage("qi",30);
                return 1;
        }
        return 0;
}


