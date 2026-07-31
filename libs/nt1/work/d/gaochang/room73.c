// Room: /d/gaochang/room73.c
// This is a room made by roommaker. write by Fan. :)
#include <ansi.h>
inherit ROOM;
#include <room.h>
void init();
int do_pull(string arg);
void create()
{
        set("short", "°µÊÒ");
        set("long", @LONG
ËÄÖÜºÚºÚµÄ£¬Î¨ÓĞÃÜÊÒÖĞÑëÒşÒşÍ¸³öÒ»µã[5m[31mºì¹â[2£»37£»0m
(hongguang)¡£
LONG );
    set("exits", ([ 
        "up" : __DIR__"room36",
]));
        setup();
}
void init()
{
    object *obj;
    obj=children(__DIR__"obj/wolfblade");
    set("blade",1);
    if (sizeof(obj)>1)  set("blade",0);
    if (query("blade")){ 
        set("long", "ËÄÖÜºÚºÚµÄ£¬Î¨ÓĞÃÜÊÒÖĞÑëÒşÒşÍ¸³öÒ»µã"+BLINK+RED+"ºì¹â"+NOR+"(hong guang)¡£\n");
        set("item_desc",(["hong guang":"Äã·¢ÏÖºì¹â¾ÓÈ»À´×Ô²åÔÚµØÉÏµÄÒ»°Ñµ¶¡£\n",]));
        add_action("do_pull", "pull");
    }else{
        delete("item_desc");
        set("long", "ËÄÖÜºÚºÚµÄ£¬Ê²Ã´Ò²Ã»ÓĞ¡£\n");
    }
}
int do_pull(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (query("blade"))
        if( arg=="µ¶" || arg=="blade") {
             ob=new(__DIR__"obj/wolfblade");
             if (!ob->move(me)) ob->this_object();
             message_vision("$N°Î³öÒ»°Ñ"+RED+"ÑªÀÇ"+NOR+"É²Ê±ºì¹âÏûÊ§ÁË£¬ËÄÖÜ±äµÃºÚºÚµÄ¡£\n",me);
             set("long", "ËÄÖÜºÚºÚµÄ£¬Ê²Ã´Ò²Ã»ÓĞ¡£\n");
             delete("item_desc");
             set("blade",0);
             return 1;
        }
        return 0;
}

