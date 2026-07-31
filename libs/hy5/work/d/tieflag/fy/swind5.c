 inherit ROOM;
void create()
{
        set("short", "南门北");
        set("long", @LONG
到处都散发着安祥宁静的气氛。街道西边的普生堂远近驰名，听说当年皇上游
览风云城时被刺，身受重伤，幸亏是普生的灵丹妙药才令皇上起死回生。堂中的金
匾就是御赐的。普生堂的对面是南宫钱庄。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sgate",
  "north" : __DIR__"swind4",
  "east" : __DIR__"nanbank",
  "west" : __DIR__"pusheng",
]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-50);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
