 inherit ROOM;
void create()
{
        set("short", "穿山洞");
        set("long", @LONG
方圆丈许的山洞还留着人工斧凿的痕迹。涓涓的细流顺着洞
壁往下流，发出潺潺的水声。洞势渐缄升高，借着从出口处透入
的天光，你发现脚下的石级居然是汉白玉雕成的。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"secret_road",
  "west" : __DIR__"another_sky",
]));
        set("coor/x",-1210);
        set("coor/y",30);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}    
