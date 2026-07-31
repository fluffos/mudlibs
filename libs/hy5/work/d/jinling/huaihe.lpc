//jinling  huaihe.c
inherit ROOM;

void create()
{
        set("short", "秦淮河");
        set("long", @LONG
“锦绣十里春风来，千门万户临河开”，这里是金陵城的繁华地带，许多
豪门世家、权贵差不多都聚居于淮水两岸，许多名胜古迹、历史掌故、风流
韵事，都发生在它的身旁，被历代文人骚额吟颂传唱。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"huafang",
          "west" : __DIR__"dongjie1",


]));
     set("outdoors", "jinling");

        set("objects", 
        ([
              "/d/hainan/npc/man1" : 2,
        ]));

        setup();
        replace_program(ROOM);
}