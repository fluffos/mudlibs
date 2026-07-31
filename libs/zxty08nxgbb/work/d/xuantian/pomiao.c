// xuantian/enter   by:pipip
inherit ROOM;
int do_say(string arg);
void create()
{
        set("short", "破庙");
        set("long", @LONG
这是一座多年未有人来过的破庙，一眼望去灰蒙蒙的尽是灰尘。
奇怪的是庙中的一副字画(zihua)竟然是干净异常，与别的地方
形成了鲜明的对比。
LONG 
        );
        set("exits", ([
                "north" : "/d/city3/shudao3"
        ]));
        set("item_desc",([
                "zihua" : "天马行空破流星，摧心销魂化无形。\n"
        ]));
        setup();
}
void init()
{
        add_action("do_say", "han");
}
int do_say(string arg)
{
        if( !arg || arg=="" ) return 0;
        if( arg=="天马行空破流星"
        ||  arg=="摧心销魂化无形") 
        {
                write(HIC"这位朋友既然来到此处，不如进来看看吧。\n");
                message("vision", "你眼前的地板突然下陷，竟然是道暗门。\n", this_player());
                set("exits/down", "d/xuantian/room1");
                remove_call_out("close");
                call_out("close", 5, this_object());
                return 1;
        }
}
void close(object room)
{
        message("vision","只见地板又出现了，暗门不见了。\n", room);
        room->delete("exits/down");
}       


