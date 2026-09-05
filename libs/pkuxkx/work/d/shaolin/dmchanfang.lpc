// Room: /shaolin/dmchanfang.c
// fast 1997/9/22
inherit ROOM;
void create()
{
         set("short","达摩禅房");
set("long",@LONG
这是达摩老祖修行的地方，整个房间空荡荡的，屋子中间放着一个蒲团，
达摩老祖就坐在上面，禅房中静悄悄的，你不禁放轻了脚步，静静的站在
达摩老祖的身旁
LONG
);
set("outdoors", "shaolin");
set("exits",([
"south" : __DIR__"midao2",
               ]));
set("objects",([
      CLASS_D("shaolin") + "/damo" : 1,
]));
set("no_task",1);
setup();
replace_program(ROOM);
}
