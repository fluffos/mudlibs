 inherit __DIR__"no_killing_place";
void create()
{
    set("short", "小河东岸");
    set("long", @LONG
四周的草坪修剪得很整齐，沿着河岸生长着一些水生植物，有浮萍，水仙，还
有几丛芦苇。不远处的草坪上错落有致地摆着一些微型亭台楼阁还有山石树木，再
过去就是一座白墙粉瓦的小庭院。几棵修竹从粉墙上探出头随风云摇动，四周静悄
悄的，偶尔能听到河西传来的狗叫声。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"bridge",
        ]));
 
        set ("no_magic", 1);
    set("outdoors","taoyuan");
    set("coor/x",260);
    set("coor/y",-40);
    set("coor/z",0);
    setup();
        replace_program( __DIR__"no_killing_place");
}  
