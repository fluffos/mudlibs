 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "崖底");
        set("long", @LONG
石头是黑色的，浪似乎也是黑色的，浪头打到崖底的石头上溅起朵朵白色的水
花，你用尽力气也挣脱不了浪头的束缚，只感觉到浪底的水流似乎比较平稳。大自
然的力量还是人力所无法抗衡的。
LONG
        );
    set("outdoors","shenshui");
    set("coor/x",190);
    set("coor/y",12310);
    set("coor/z",-70);
    setup();
} 
void init(){
        if(interactive(this_player())){
                call_out("do_flush",30,this_player());
        }
        add_action("do_dive", "dive");
} 
void do_flush(object me)
{
        object room; 
        if(!me || environment(me) != this_object()) {
                        return;
        }
        tell_object(me,"\n突然一个大浪把你卷了出去！\n\n");
        room = find_object(__DIR__"ocean1");
        if(!objectp(room)) room= load_object(__DIR__"ocean1");
        me->move(room);
 
}  
int do_dive(){
        object me, obj; 
        me = this_player();
        message_vision("$N一个猛子扎入了水中。\n", me);
        obj = find_object(__DIR__"midsea");
           if(!objectp(obj)) {
                obj = load_object(__DIR__"midsea");
        }
        me->move(obj);
        message("vision", me->name() + "沉入你身边的水中。\n", environment(me), me);
        return 1;
}       
