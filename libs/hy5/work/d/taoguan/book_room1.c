 inherit ROOM;
void create()
{
        set("short", "经楼");
        set("long", @LONG
这里是灵心观中收藏书籍的地方, 四周的书架上堆了满满的书。
有些书已经旧的纸张都泛黄了, 摸一摸可能就会散掉甚至变成飞灰。
你再仔细的看了看, 发现这里都只是些寻常的修道的书籍, 似乎没有
什麽特别的。角落里有一座小小的木梯通往二楼。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"book_room2",
  "south" : __DIR__"stoneroad2",
]));
        set("no_clean_up", 0); 
        set("coor/x",-40);
        set("coor/y",2140);
        set("coor/z",80);
        setup();
} 
