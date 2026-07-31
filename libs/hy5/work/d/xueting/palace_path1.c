
inherit ROOM;

void create()
{
        set("short", "赤峰路 ");
        set("long", @LONG
路往东面的山峰和西面的山脚伸展。东方的浓雾之中耸立着一
座暗红色的奇峰，直插云霄。云中有几头苍鹰在低低的盘旋遨翔，
仿佛将行人当作了猎物。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"palace_path2",
  "west" : __DIR__"work",
]));
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}

