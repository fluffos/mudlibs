 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "二祖庵");
        set("long", @LONG
正如初祖庵是禅宗初祖达摩修行之地，二祖庵是后世佛徒最为尊
崇向往的胜地，当年二祖在此坐化，坐化之时满室异香，留下舍利
子数颗，为后世传宗之宝，二祖庵翠柏浓郁，仙风阵阵，让人心旷
神怡，由此向南下山，便是莲花寺。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"talin",
  "southdown" : __DIR__"lianhua",
]));
        set("coor/x",-220);
        set("coor/y",400);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}      
