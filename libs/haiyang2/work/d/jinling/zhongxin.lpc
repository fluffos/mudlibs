//jinling  zhongxin。c
inherit ROOM;

void create()
{
        set("short", "中心广场");
        set("long", @LONG
这里是金陵市的市中心,连接着金陵城的主要街道。古都金陵历来是历史名
城。秦淮风光更是天下闻名。引得不少风流人事不远千里来此一游。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"beijie2",
           "south" : __DIR__"nanjie1",
           "west" : __DIR__"xijie1",
           "east" : __DIR__"dongjie1",



]));
set("objects",([
              "/d/hainan/npc/man1" : 2,
__DIR__"npc/protect2":1,
]));
 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
