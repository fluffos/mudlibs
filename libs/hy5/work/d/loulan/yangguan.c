 inherit ROOM;
void create()
{
        set("short", "玉门关外沙漠");
        set("long", @LONG
照着道上的黄沙，大地间仿佛已成了一片凄迷的暗黄色，也不知从哪里传来了
一阵苍凉的歌声，“一出玉门关，两眼泪不干”，道旁一块风化了的石碑上隐约可
以看出『玉门关』三个古篆大字。
LONG
        ); 
        set("exits", ([ 
                "southeast" : __DIR__"mirage",
                "northwest" : __DIR__"kongquehe",
                "southwest" : "/d/qilian/yumenguan",
                "west" : "/d/eren/yangguan",	
        ]));
        set("outdoors", "loulan");
        set("coor/x",-950);
        set("coor/y",110);
        set("coor/z",0);
        setup();
}  
