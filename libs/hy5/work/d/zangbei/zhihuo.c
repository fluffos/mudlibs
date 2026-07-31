 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "巨岩");
        set("long", @LONG
赤土河的南岸有一块巨大的岩石，如鹰展翅俯瞰河水，藏语称为“知火扎郎”，
意为“大喝一声，挡不住了”，是传说中贡嘎日松贡的门神。河边用片石堆成的嘛
呢堆比比皆是，每年萨嘎达娃，当地人都要绕石转山，在河里沐浴更衣。河的北岸
房屋鳞次栉比，是一个边远小城。河的南岸循山势而上，是著名的海子山。
LONG
        );
        set("exits", ([ 
                "southup":  __DIR__"echu",
        ]));
        set("item_desc", ([
                "river":        "水流湍急，但是不深，你可以试着涉过去(wade)。\n",
                "赤土河":       "水流湍急，但是不深，你可以试着涉过去(wade)。\n",
        ]) );
        
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
void init() {
        add_action("do_wade","wade");
        remove_call_out("greeting");
        call_out("greeting", 4, this_player());
}  
void greeting(object me)
{
        object ob;
        ob=this_object();
        if( !me || environment(me) != this_object() ) return;
        message_vision(CYN"\n\n对岸嘻嘻哈哈地传来洗衣妇人们的说笑声，随着河水哗哗地飘向远方。。。\n\n"NOR,me);
        
} 
int do_wade(string arg) {
        
        object me;
        
        me=this_player();
        if (!arg || arg == "小河" || arg== "river") {
                if (me->query_temp("zangbei/wade_2"))
                        return notify_fail("你已经在河水中央了。\n");
                message_vision("$N脱下靴子走入河水中，艰难地向对岸涉去。\n\n",me);
                call_out("pass_river",6,me);
                me->start_busy(3);
                me->set_temp("zangbei/wade_2",1);
                return 1;
        }
        tell_object(me,"你要做什么？\n");
        return 1;
}  
int pass_river(object me) {
        object room;
        if (!objectp(me) || me->is_ghost()) return 0;
        room=find_object(__DIR__"bank");
        if (!objectp(room)) room=load_object(__DIR__"bank");
        tell_object(me,HIG"你终于走到了赤土河的对岸。\n"NOR);
        message("vision",HIG""+me->name()+"水淋淋地从河里走了上来。\n"NOR,room);
        me->move(room);
        me->delete_temp("zangbei/wade_2");
        return 1;
}
