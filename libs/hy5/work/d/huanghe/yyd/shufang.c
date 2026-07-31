// 书房 shufang.c
// zly 1999.06.10
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "书房");
        set("long", @LONG
这里是萧府的书房，房中书架上整整齐齐地堆放着很多书。书架上
一尘不染，显然是主人经常翻阅书籍。书橱里摆着几件精巧的玉器，显
得玲珑剔透，光彩照人。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ 
            "west" : __DIR__"dating",
]));

        setup();
        replace_program(ROOM);
}
