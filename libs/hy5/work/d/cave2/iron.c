 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "铁屋");
        set("long", @LONG
这铁屋特别大，特别高，四壁空空，什么也没有，一个人站在
里面，就好像站在旷野中似的。就在这空旷而阴森的屋子中央，
孤零零地站着两具骷髅，两具惨白色的骷髅，紧紧拥抱在一起。
死人的血肉已化，但骷髅至今犹屹立不倒。
五张矮几，几上居然还放着些笔墨、书册。
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
