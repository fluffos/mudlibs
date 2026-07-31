 inherit ROOM;
void create()
{
        set("short", "百兵库");
        set("long", @LONG
快活王志在天下，暗中征召天下豪杰，铸造百兵以供沙场之用，这间百兵库本
是古楼兰的长史府，十分庞大宏伟，现被快活王改造为兵器库，但见室中壁上、桌
上、架上、柜中。几间，尽皆列满兵刃，式样繁多，十之八九都是名剑名刀，或长
逾丈寻，或短仅数寸，有的铁锈斑驳，有的寒光逼人，不禁让人眼花缭乱。 
LONG
        ); 
        set("exits", ([ 
                "east" : __DIR__"southstrt",
        ]));
        set("objects", ([
                __DIR__"obj/sword" : 1,
                __DIR__"obj/blade" : 1,
                __DIR__"obj/axe" : 1,
                __DIR__"obj/hammer" : 1,
                __DIR__"obj/spear" : 1,
                __DIR__"obj/whip" : 1,
                __DIR__"obj/staff" : 1,
       ]) );
        set("indoors", "loulan"); 
        set("coor/x",-1010);
        set("coor/y",180);
        set("coor/z",-100);
        setup();
}  
