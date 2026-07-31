 inherit ROOM;
void create()
{
        set("short", "大松树上");
        set("long", @LONG
松树很高，你小心翼翼地往上爬，幸好松树也很密，到处是盘曲的丫枝，很容
易就找到歇脚的地方。从这里可以很清楚地看到直共寺的院子里的动静。寺院里的
几只藏马鸡正在堤上寻食，咯咯咯的叫声听的清清楚楚。
LONG
        );
        set("objects", ([
                
        ]) ); 
        set("exits", ([ 
                "down" : __DIR__"temple5",
        ]));
        set("coor/x",-1080);
        set("coor/y",170);
        set("coor/z",10);
        setup(); 
} 
void init(){ 
        add_action("do_climb","climb");
}  
int do_climb(string arg){ 
        object me,room;
        me=this_player();
        if (!arg || (arg!="pine" && arg!="松树")) 
                return 0; 
        room=find_object(__DIR__"pine2");
        if (!objectp(room)) room=load_object(__DIR__"pine2");
        message_vision("$N手脚并用，敏捷地继续向树顶爬去。\n",me);
        tell_room(room, this_player()->name() + "从树下爬了上来。\n");
        this_player()->move(room);
}    
