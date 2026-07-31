 inherit ROOM;
void create()
#include <command.h>
{
        set("short", "小湖");
        set("long", @LONG
溪水到这里会成了一个小小的湖泊。四周群山环绕，湖边树木成阴。
小鸟的叽喳声从林间传出。微风吹过，清凉宜人。湖水呈深蓝色，湖面
虽不大，可湖水却深不可测。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"river",
]));
        set("item_desc", ([
                "lake": "你可以从这里潜（ｄｉｖｅ）到湖底。\n",
                "water" : "你可以从这里潜（ｄｉｖｅ）到湖底。\n",
                "湖水" : "你可以从这里潜（ｄｉｖｅ）到湖底。\n"
        ]) ); 
        set("outdoors","fengyun");
        set("coor/x",180);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",180);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",180);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",180);
        set("coor/y",-30);
        set("coor/z",20);
        setup();
} 
void init()
{
        add_action("do_dive", "dive");
} 
int do_dive()
{
   object *inv,me;
        object bottom;
        int i;
        string  objname; 
        me = this_player();
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                objname = (string)inv[i]->query("name");
                if( objname != "油皮袋" && objname != "芦苇")
                        DROP_CMD->do_drop(me, inv[i]);
        }
        message_vision("$N脱光了所有衣服，一个猛子扎入湖水中．\n",me);
        bottom = load_object(__DIR__"bottom");
        if(bottom) me->move(bottom);
        return 1;
}     
