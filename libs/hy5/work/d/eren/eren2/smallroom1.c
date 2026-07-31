 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "小石室");
        set("long", @LONG
每间洞室都很整洁，甚至可以说都很华丽，而且还都有张很柔软、很
舒服的床。墙上贴着一条横幅，上面龙飞凤舞地写着几个字：
        无牙门下士，可杀不可辱
        
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"mouseroom2",           
                        ]));
        set("objects", ([
                __DIR__"npc/mice1" : 1,
                __DIR__"npc/mice2" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
