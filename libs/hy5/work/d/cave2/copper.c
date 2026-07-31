 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "铜屋");
        set("long", @LONG
各式各样的兵器，还有各式各样的暗器。金铁之气，砭骨生寒，
森森的寒光，将四壁都照成了铁青色。枪，最长的长达丈八，最
短的才不过叁尺，剑，最大的宛如木桨，最小的竟宛如筷子。长
枪短剑，整齐地排列着，它们虽然没有生命，却又似蕴含着杀机，
令人胆寒的杀机！
    普天之下，所有的凶杀之器，只怕尽都在这屋里。 
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
