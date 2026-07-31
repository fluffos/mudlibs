 inherit ROOM;
void create()
{
        set("short", "李家庄");
        set("long", @LONG
这儿是李大娘的庄院。漆黑的大门紧闭，两边是三丈高墙，墙上倒插着锋刀。
门外没有人，门里亦听不到任何的声响，整个庄院沉浸在一种莫名的神秘阴森之中。
庄院占地极广，完全独立，周围并没有接连房屋，树都没有一棵，却横跨一条溪流。
溪流之上亦是高墙，出入口都装上铁栅。
LONG
        );
        set("exits", ([ 
                "northwest": __DIR__"eroad2",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([  
                "door": "大门关的死死的，里面没有一丝动静。\n",
                "大门": "大门关的死死的，里面没有一丝动静。\n",
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}   
void init() {
        add_action("do_knock","knock");
        add_action("do_push","push");
}  
int do_knock(string arg) {
        
        if (arg=="door" || arg =="大门" || arg =="门"){
                message_vision("$N蓬蓬地敲了几下，大门里一丝回音也没有。\n",this_player());
                return 1;
        }
        return 0;
}  
int do_push(string arg) {
        
        if (arg=="door" || arg =="大门" || arg =="门") {
                message_vision("$N用力推了推门，大门纹丝不动。\n",this_player());
           return 1;
        }
        return 0;
}    
