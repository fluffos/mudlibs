// fanting
// by kiden
// 侠客岛读石壁的人享用
// modified by iszt
// 有人说不够吃……加上yao
inherit ROOM;
#include <ansi.h>
string* names = ({
        "/d/shaolin/obj/mala-doufu",
        "/d/shaolin/obj/bocai-fentiao",
        "/d/shaolin/obj/shanhu-baicai",
        "/d/shaolin/obj/liuli-qiezi",
});
void create()
{
        set("short", HIC"俠客岛石室"NOR);
        set("long",HIM @LONG
这里是石室内就餐的地方。很多高手到了这里，流连忘返，不愿意离开
石室。岛主见此，就特意让侠客岛弟子在这里安置了一个就餐的地方。在这
里就餐的人也是匆匆忙忙，恨不得少停留一刻。桌上的饭菜很简单，旁边还
有一个水缸，可以用来装水和喝水。如果吃不够还可以要(yao)些干粮。
LONG NOR
        );
        set("exits", ([
                "south" : __DIR__"shishi1",
        ]));
        set("resource/water", 1);
        set("objects",([
                "/d/shaolin/obj/qingshui-hulu" : 2,
                names[random(sizeof(names))]: 2,
                names[random(sizeof(names))]: 2,
                names[random(sizeof(names))]: 2,
        ]));
        setup();
}

void init()
{
        add_action("do_yao", "yao");
        add_action("do_drink", "drink");
}

int do_yao(string arg)
{
        object ob;
        ob = new ("/clone/food/ganliang");
        ob->set("value",0);
        ob->move(this_player());
        message_vision("$N向一旁的侠客岛弟子要了一块干粮带在身上。\n", this_player());
        return 1;
}
int do_drink(string arg)                                                          
{                                                                                 
        int current_water;                                                        
        int max_water;                                                            
        object me;                                                                
        me = this_player();                                                       
        if(arg)                                                                   
                return 0;                                                         
        current_water = me->query("water");                                       
        max_water = (int)me->max_water_capacity();                                
        if (current_water<max_water) {                                            
                me->add("water", 120);                                             
                message("vision", me->name()+"拿起水瓢，从水缸里面舀起一瓢水，咕噜咕噜的就喝了下去。\n",
                        environment(me), ({me}) );                                
                write("你就着水缸大喝了几口水。\n");                      
        }                                                                         
        else write("你已经不渴了，还是别喝了。\n");                   
        return 1;                                                                 
}                                                                                 
