
inherit ROOM;

void create()
{
        set("short", "日朝园");
        set("long", @LONG
看门，只见正门五间，上面筒瓦泥鳅脊；那门栏窗阁俱是
细雕花样，并无朱粉涂饰；一色水磨群墙，白石台阶，凿成西
番莲花样；左右雪白粉墙，下面虎皮石砌成纹理。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"palace_front",
  "westdown" : __DIR__"palace_path4",
]));
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}

