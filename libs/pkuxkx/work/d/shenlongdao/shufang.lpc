// room: shufang.c
// kiden 06-08-26
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string);

void create()
{
        set("short", "书房");
        set("long", @LONG
书房中竹书架上放着不少图书，四壁挂满了字画，看来陆先生是个风雅之士。
壁上有几幅字画，抬头看去，一张是山水，另一张画上有只白鹤，有只乌龟。
左壁上是陆先生临的几幅秦琅牙台刻石。还有一幅全是甲骨文，一个个字都如
蝌蚪一般，宛如五台山锦绣峰普济寺中石碣上所刻文字。
右边有个竹门，但被反扣住了，向窗外一望，下临深谷，实是无路可走。
LONG
        );

        set("exits", ([
                "west" : __DIR__"keting",
        ]));

        set("item_desc", ([
                "men" : "竹门被反锁住了，也许你可以震开(break)它！\n",
        ]) );
        set("objects", ([
            "/kungfu/class/shenlong/lu" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        if( !arg || arg!="men" ) 
         {
                write("你到底有没有想清楚你要干吗？\n");
                return 1;
         }
        message_vision("$N走到门前，拜出骑马蹲裆式，深吸一口气，双掌同时拍出，竹门被震开了。\n", this_player());
        message_vision("$N向前一探身，啊的一声惨叫，跌进了深谷。\n", this_player());
        this_player()->move(__DIR__"shengu");
        if (random(this_player()->query("dex"))>=0)
         {
        message_vision(HIC"$N从上边跌了下来，两手在空中胡乱的抓了几把，居然抓到一根长藤，$N顺着长藤一荡，跌在一堆枯枝上。\n"NOR, this_player());
        this_player()->unconcious();
         }
         else
         {
         message_vision(HIM"$N从上边跌了下来，一头栽在枯枝烂叶上，居然毫发无伤！哇靠，真是太神奇了！\n"NOR, this_player());
         }
        return 1;
}


