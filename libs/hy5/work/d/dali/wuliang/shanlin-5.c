// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "É­ÁÖ");
	set("long", @LONG
ÕâÀïËÄÖÜÊÇÊÇ²ÎÌì¹ÅÄ¾£¬ÖĞ¼äÈ´ÓĞÒ»ÑÛÇåÈª£¬Äã²»ÓÉµÄ´óÏ²¹ıÍù¡£±±ÃæÊ÷
ÁÖÔ½·¢µÄ½ôÃÜ£¬ºÜÄÑÉîÈë¡£Ô 
LONG
	);
        set("outdoors", "´óÀí");

	set("exits", ([
            "east" : __DIR__"shanlin-4",
	    "north" : __DIR__"shanlin-6",
	]));

	setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"Å¿ÔÚÈª±ßÓÃÊÖÅõÁËÒ»Ğ©Ë®ºÈ¡£\n"
            , environment(me), ({me}) );
            write("ÄãºÈÁËÒ»¿ÚÇåÁ¹µÄÈªË®£¬¾õµÃÊæ·ş¶àÁË¡£\n");
        }
        else write("ºÈÄÇÃ´¶àµÄÁ¹Ë®£¬Äã²»ÅÂÉú²¡Âğ?\n");
        return 1;
}
