 // Room: /d/shaolin/shandao3.c
inherit ROOM; 
void create()
{
        set("short", "山道");
        set("long", @LONG
这是一条笔直的山路向上方延伸，一直隐没于云雾之中，山
道的左面是一片翠竹林，小鸟的鸣叫声和风吹过竹林的沙沙声交
织成美丽的大自然的旋律。右面是陡峭的山崖。路上经常能看到
几个僧人来来往往，向上一直走就是著名的少林寺了。
LONG
        ); 
        set("outdoors", "shaolin"); 
        set("exits", ([ /* sizeof() == 3 */
        "northup" : __DIR__"shandao2",
        "west" : __DIR__"zhulin/entry",
        "southdown" : __DIR__"shandao4",
])); 
        setup();
        replace_program(ROOM);
}     
