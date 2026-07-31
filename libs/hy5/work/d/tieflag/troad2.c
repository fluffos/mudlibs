 inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
这里的灌木更高了些，几乎使你分不清前方的道路。一不小心就被树枝挂到了手脚，
往前走又不知通往哪里，你不禁产生了退缩之心。
LONG                                         
        );
        set("exits", ([
  "south" : __DIR__"troad1",
  "west" :  __DIR__"troad3",  
  "east" :  __DIR__"troad4",
])); 
        set("outdoors","tieflag");      
        set("coor/x",170);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",0);
        set("coor/z",20);
        setup();
}
int valid_leave(object who,string dir)
{
        if(userp(who) && random(3))
        {
                who->move(this_object());
                return notify_fail(""); 
        }
        return 1;
}    
