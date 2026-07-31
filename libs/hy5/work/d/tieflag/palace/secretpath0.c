 inherit ROOM;
void create()
{
        set("short", "秘道");
        set("long", @LONG
这是一条长长的甬道，甬道两旁嵌有铜灯。甬道斜斜地伸如地下，不知
有多长，也不知伸向何处，但两壁铜灯俱都擦得极为光亮，显见此地经常有
人行走。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"secretpath1",
  "west" : __DIR__"kengdi",
])); 
        set("coor/x",230);
        set("coor/y",-40);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}    
