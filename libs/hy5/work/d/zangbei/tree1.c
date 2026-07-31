 inherit ROOM;
#include <ansi.h> 
string view(string room);
string *rooms = ({__DIR__"e_wall1",__DIR__"e_wall2",__DIR__"e_wall3",__DIR__"w_wall1",
                __DIR__"w_wall2",__DIR__"w_wall3",__DIR__"village",__DIR__"v_gate" });
                
void create() 
{
        set("short", "茂密的大树上");
        set("long", @LONG
你使出吃奶的劲，终于上到了树顶。这树很高，也很密，人躲在里面遮的严严
实实。从树纹上看，这棵榕树起码有上千年了，树冠如华盖，足有数十米见方，无
数儿臂粗细的气根从树干上垂到地面，又再次入土生根，真可谓独木成林。拨开树
叶往南面看去，依稀看见有个寨子，这里倒是侦察（ｓｃｏｕｔ）的好地方。
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"forest4",
        ]));
        set("objects", ([
        ]) );
        set("item_desc", ([
                "树干":  "树干连着树干，有的甚至通到了寨子的上方。\n",
                "trunk": "树干连着树干，有的甚至通到了寨子的上方。\n",
                "气根": "树干连着树干，有的甚至通到了寨子的上方。\n",
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init(){ 
        add_action("do_jump","jump");
        add_action("do_scout","scout");
}  
int do_jump(string arg) {
        
        object me;
        
   me=this_player();
        if (arg=="down" || arg == "ladder" || arg== "寨子") {
                if (me->query_temp("zangbei/treejump_1"))
                        return notify_fail("你正在空中了，无处着力。\n");
                message_vision("$N顺着树干悄悄地爬到寨墙上方，一纵身向下跳去。\n\n",me);
                call_out("pass_river",6,me);
                me->start_busy(3);
                me->set_temp("zangbei/treejump_1",1);
                return 1;
        }
        tell_object(me,"你要往哪儿跳？\n");
        return 1;
}  
int pass_river(object me) {
        object room;
        string room_name;
        if (!objectp(me) || me->is_ghost()) return 0;
        room_name=rooms[random(sizeof(rooms))];
        room=find_object(room_name);
        if (!objectp(room)) room=load_object(room_name);
        tell_object(me,"你在半空中一个回旋，轻巧地落下。\n");
        message("vision",me->name()+"从空中跳了下来。\n",room);
        me->move(room);
        me->delete_temp("zangbei/treejump_1");
        return 1;
} 
int do_scout(){
        object me;
        me = this_player();
        message_vision(HIG"$N拨开树枝，小心翼翼地向外眺望。\n"NOR, me);
        tell_object(me, view(rooms[random(sizeof(rooms))]));
        return 1;
} 
string view(string room) {
        int i;
        object *inv,env;
        mapping exits;
        string roomdesc, str, *dirs;
        
        env = find_object(room); 
   if(!env) env=load_object(room); 
        
        str = "你可以清楚地看到。。。\n\n";
        
        // room descriptions.
        str += sprintf( "%s\n    %s \n    %s",
                        env->query("short"),
                        env->query("long"),
                        env->query("outdoors")? NATURE_D->outdoor_room_description() : "" ); 
        // all things in the room.
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("no_shown") ) {
                        continue;
                }
                str += "  " + inv[i]->short() + "\n";
        }
        return str;
} 
