// che1.c 

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY"车厢内"NOR);
        set("long", @LONG
干净舒服的车厢里，整洁的座位上铺着红色的锦缎。车前老车夫正在用力
地赶着马车，马行颠簸，但坐在车内，却并不感觉震荡。透过的车窗你能够欣
赏窗外优美的景色。
LONG
        );
        set("no_fight",1);

        setup();
}

void run(object ob)
{
        if (environment(ob) == this_object())
        ob->move(__DIR__"che2", 1);        
}

void init()
{
       object ob = this_player();
       call_out("run", 15, ob);
}
