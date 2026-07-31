// Room: shiliang.c 石梁
// arnzh 97/1/24
inherit ROOM;
void create()
{
    set("short", "崖底");
    set("long", @LONG
这里是舍身崖底，地势险峻，你没想到自己居然，敢跳下来。
LONG
    );
    set("exits", ([
        "up" : __DIR__"shijie62",
    ]));
    
    
    setup();
    replace_program(ROOM);
}
