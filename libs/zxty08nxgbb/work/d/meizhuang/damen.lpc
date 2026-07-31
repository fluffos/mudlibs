// edit by daniel@jhfy.nh 2002
#include <room.h>
#include <ansi.h>
inherit ROOM;
int do_say(string arg);
void create()
{
    set("short", HIY"梅庄"NOR);
    set("long", @LONG
穿过一大片梅林,走上一条青石板大路,来到一座朱门
白墙的大庄院外,行到近处,见大门外写着"梅庄"两个大字,
旁边署着"虞允文题"四字。墙角浩然屹立着一块石牌(pai)。
LONG
    );
   set("item_desc", ([
   "pai" : "江南四友居处。\n",
        ]));
   set("outdoors", "meizhuang" );
   set("objects", ([
   ]));
   set("exits", ([
   "south" : __DIR__"meilin1",
        ]));
   setup();
        call_other("/d/meizhuang/obj/board", "???");

}
void init()
{
         add_action("do_say", "say");
}
int do_say(string arg)
{
        if( !arg || arg=="" ) return 0;
        if( arg=="江南四友")
        {
                write("只听里面有人应了声：请进来吧。\n");
                message("vision", "大门慢慢的打开了。\n", this_player());
                 set("exits/north", __DIR__"tianjing");
                remove_call_out("close");
                call_out("close", 5, this_object());
                return 1;
        }
}
void close(object room)
{
        message("vision","只见大门乒地关上了。\n", room);
        room->delete("exits/north");
}       


