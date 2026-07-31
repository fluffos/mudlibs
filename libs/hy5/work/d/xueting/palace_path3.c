
inherit ROOM;

void create()
{
        set("short", "迷茫风雨路");
        set("long", @LONG
山势在这里渐渐升高，周围的景象在浓雾中若隐若现。浓雾中
的水气几乎浸透了你的衣裳，将你溶入冰冷的四周。这…到底是人
间通往天堂的路，还是通往地狱之门？
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"palace_path4",
  "westdown" : __DIR__"palace_path2",
]));
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}

