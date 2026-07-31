// /d/yuehou/miao.c

inherit ROOM;

void create()
{
        set("short", "岳王庙");
        set("long", @LONG
这里是岳王庙。相传当年岳飞带兵来到这里，解救了当地的
百姓于辽人的统治，百姓为了纪念他因此建了这座庙。岳王庙的
香火常年不断，很多人都到这里来求平安，听说非常灵验。
LONG
        );

       set("exits", ([
                "east"             : __DIR__"tupo2",
]) );

       set("light_up", 1);

       setup();
       replace_program(ROOM);
}

