// che.c 

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
        ob->move(__DIR__"che1", 1);
        write("\n大车赶上了大路，窗外大路两旁绿柳成荫，郁郁葱葱，风吹木叶，阳光满地。\n"
"远山青绿，湖水湛蓝。青绿远山倒映在湛蓝的湖水中，蓝翠如绿，绿浓如蓝。\n"
"\n暮色渐渐浓了，夕阳也已慢慢消失，但路旁山坡上的枫叶却依然多彩而艳丽。\n"
"远处的青山，亦渐渐隐没在浓浓的暮色里，像极了一幅经已褪色的精美画卷。\n\n");
}

void init()
{
       object ob = this_player();
       call_out("run", 10, ob);
}
