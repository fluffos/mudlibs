 inherit ROOM;
void create()
{
        set("short", "幽灵山庄");
        set("long", @LONG
这是一个死人的世界。放眼四望，一片空蒙，什么都看不见。左
面有一间灰白色的小木屋，在这迷雾般的白云里，一定要很注意才看
得到。
LONG
        );
        set("exits", ([
                "north" : __DIR__"house",
                "west" : __DIR__"bridge",
                "east" : __DIR__"groad1",
        ]));
        set("coor/x",-1170);
        set("coor/y",-100);
        set("coor/z",-20);
        setup();
} 
int valid_leave(object me, string dir){
        if(dir == "west" && me->query("family/family_name")!="幽灵山庄"){
                me->set_temp("marks/know_ghost", 1);
        }
        return 1;
} 
