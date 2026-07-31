 inherit ROOM;
void create()
{
        set("short", "塞口");
        set("long", @LONG
这里是中原入西域的必经之路，大批的商人鸵队都一定要从这里经过，
形成了这里的畸形路容。向西你可以看到一段破旧的长城，上面好象还
有被土炮轰过的痕迹，向北是一家小店庄。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"sandroad",
  "west" : __DIR__"oldgreatwall",
 "north" : __DIR__"jadestore", 
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/trader" : 1,
                __DIR__"npc/trader2" : 2,
        ]) ); 
        set("coor/x",-1030);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}     
