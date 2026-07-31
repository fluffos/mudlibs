// shanxia.c By River 98/09

inherit ROOM;
#include <ansi.h>
int get_object(object ob);
void create()
{
        set("short", HIG"终南山下"NOR);
        set("long", @LONG
这里是终南山下，四周一片清寂，只闻泉声鸟语，杳无人迹。四下里山石
嶙峋，树木茂密，隐蔽之处甚多。在不远处的灌木丛中，隐隐约约的好象有个
小山洞(dong)。
LONG
        );

        set("item_desc", ([
           "dong" : HIB"一个黑乎乎的小洞，不知道通向哪里？\n"NOR,
        ]));

        set("outdoors","古墓");

        set("exits", ([
                "northwest" : __DIR__"xiaolu3",
                "enter" : __DIR__"dongkou",
        ]));
    
        set("coor/x",0);
  set("coor/y",10);
   set("coor/z",0);
   setup();
}
