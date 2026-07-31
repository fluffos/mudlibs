#include <ansi.h>
inherit ROOM;
string script();
void create()
{
        set("short", "书库");
        set("long", @LONG
这里是大学士殷正廉保存他平生收集各种文献的所在。更有他年轻时撰写的数
本武功心得。房间收拾得干净整洁，满屋的书架上堆满了书籍，当中有张不大的藤
制方桌，上面放着一叠手稿。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"shufang",
        ]));

        set("no_fight", 1);
        set("no_magic", 1);
    set("coor/x",40);
    set("coor/y",1870);
        set("coor/z",0);
        setup();
} 
