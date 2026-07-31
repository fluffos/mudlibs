 inherit ROOM;
#include <ansi.h>
string *roomname= ({"gold", "silver", "copper", "iron","tin", "center", }); 
void create()
{
        set("short", "八角型的屋子");
        set("long", @LONG
这里竟是个八角型的屋子，那八面墙，有的是铁，有的是钢，有的是
石板，竟还有一面像是金子。屋子里，没有桌子，没有橱子．因为在地底，
所以也没有蛛网、积尘，空气也不知是哪里进来的。屋子里只有绞盘，大
大小小、形状不同的机关绞盘，有的是铁铸，有的是石造，自然，也有的
是金子的。屋子中央有个高高的铜环。
LONG
        );
        set("no_magic",1);
        set("exits", ([ 
                        ]));
        set("item_desc", ([
                "金绞盘": "一个纯金制成的机关绞盘(goldwheel)，似乎可以转动（turn）。\n",
                "银绞盘": "一个纯银制成的机关绞盘(silverwheel)，似乎可以转动（turn）。\n",
                "铁绞盘": "一个纯铁制成的机关绞盘(ironwheel)，似乎可以转动（turn）。\n",
                "铜绞盘": "一个纯铜制成的机关绞盘(copperwheel)，似乎可以转动（turn）。\n",
                "锡绞盘": "一个纯锡制成的机关绞盘(tinwheel)，似乎可以转动（turn）。\n",
                "铜环": "铜环(ring)吊得很高，拉起来（pull）很费力。\n",
                "石绞盘": "一个石质的绞盘，不过好像已经卡住了。\n",
                "木绞盘": "一个木质的绞盘，不过好像已经朽掉了。\n",
                "绞盘": "一个个大大小小、形状不同的机关绞盘，有铁铸(ironwheel)，
银的(silverwheel)，铜的(copperwheel)，锡的(tinwheel)，
金的(goldwheel)，还有土塑的(earthwheel)，石刻的(stonewheel)，
和木打的(woodwheel)。\n",
                "goldwheel": "一个纯金制成的机关绞盘(goldwheel)，似乎可以转动（turn）。\n",
                "silverwheel": "一个纯银制成的机关绞盘(silverwheel)，似乎可以转动（turn）。\n",
                "ironwheel": "一个纯铁制成的机关绞盘(ironwheel)，似乎可以转动（turn）。\n",
                "copperwheel": "一个纯铜制成的机关绞盘(copperwheel)，似乎可以转动（turn）。\n",
                "tinwheel": "一个纯锡制成的机关绞盘(tinwheel)，似乎可以转动（turn）。\n",
                "ring": "铜环吊得很高，拉起来（pull）很费力。\n",
                "stonewheel": "一个石质的绞盘，不过好像已经卡住了。\n",
                "woodwheel": "一个木质的绞盘，不过好像已经朽掉了。\n",
                "wheel": "一个个大大小小、形状不同的机关绞盘，有铁铸的(ironwheel)，
银的(silverwheel)，铜的(copperwheel)，锡的(tinwheel)，
金的(goldwheel)，还有石刻的(stonewheel)和木打的(woodwheel)。\n",
                "jiaopan": "一个个大大小小、形状不同的机关绞盘，有铁铸的(ironwheel)，
银的(silverwheel)，铜的(copperwheel)，锡的(tinwheel)，
金的(goldwheel)，还有石刻的(stonewheel)和木打的(woodwheel)。\n",
                ]) );
        
        set("objects", ([
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init()
{
        add_action("do_turn", "turn");
        add_action("do_pull", "pull");
} 
int do_pull(string arg) 
{
        if (arg != "ring" && arg !="铜环") {
                write("你要拉什么？\n");
                return 1;
                }
        message_vision(YEL"$N拼命一使力，铜环突然完全落了下来。\n"NOR,this_player());
        call_out("flood_them",6);
        this_player()->start_busy(3);
        return 1;
} 
int do_turn(string arg)
{
        object obj;
        object me, room;
        string room_name;
        
        if (arg == "woodwheel" || arg =="stonewheel"
                || arg == "石绞盘" || arg == "木绞盘") {
                write("这个绞盘好像坏了，转不动。\n");
                return 1;
        }
        
        if (arg == "绞盘")
                return notify_fail("你要转哪个绞盘？\n"); 
        
        if(!arg || (arg!="goldwheel" && arg != "tinwheel" 
                && arg!="copperwheel" && arg!="ironwheel" && arg!="silverwheel"
                && arg!="金绞盘" && arg != "锡绞盘" 
                && arg!="铜绞盘" && arg!="铁绞盘" && arg!="银绞盘"))            
                        return notify_fail("你要转什么？\n");
                
        switch (arg) {
                        case "金绞盘": arg="goldwheel";break; 
                        case "锡绞盘": arg="tinwheel";break;
                        case "铜绞盘": arg="copperwheel";break;
                        case "铁绞盘": arg="ironwheel";break;
                        case "银绞盘": arg="silverwheel";break;
                        default: break;
                }
                if (sscanf(arg, "%swheel", room_name)!= 1) 
                        return notify_fail("你要转什么？\n");                   
                room=find_object(__DIR__+room_name);
                if(!objectp(room)) 
                        room = load_object(__DIR__+room_name);
                if (query("exits/"+room_name)) 
                        return notify_fail("这绞盘控制的门已经是开着的了。\n");
                message_vision("随着$N转动绞盘，石壁开始旋转起来，露出了一扇门。\n",this_player());
                delete("exits");
                set("exits/"+room_name,__DIR__+room_name);
                return 1;
        
} 
int flood_them() {
        object room, *inv,ob,exit_room;
        int i,j;
        exit_room=find_object(__DIR__"river1");
        if(!objectp(exit_room)) 
                exit_room = load_object(__DIR__"river1"); 
        for (i=0;i<sizeof(roomname);i++){
                room=find_object(__DIR__+roomname[i]);
           if(!objectp(room)) 
                        room = load_object(__DIR__+roomname[i]); 
        message("vision",HIG"只听“轰隆隆”一连串大震，就好像山崩地裂似的，整整一面土墙，
突然问完全崩溃！一股洪水，有如排山倒海一般倒灌了进来！\n\n"NOR,room);
                inv = all_inventory(room);
                for(j=0;j<sizeof(inv);j++){
                        ob = inv[j];
                        if (!userp(ob))continue;
                        message_vision(HIG"一声惊叫，$N身不由己地被水流冲了下去。\n\n"NOR,ob);
                        message("vision",HIG"水里又飘下一个人来。\n"NOR,exit_room);
                        ob->start_busy(2);
                        ob->move(exit_room);
                }
        }
        return 1;
}  
void reset()
{
        ::reset();
        delete("exits");
        
}       
