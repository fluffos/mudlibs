 inherit ROOM;
void create()
{
    set("short", "大牢内");
        set("long", @LONG
石墙围成的院落很大，灰黑色的院墙是平常院墙的三四倍之高，给人一种压抑
的感觉。院子里堆满了巨大的石料，有不少的犯人正在忙碌的加工石料。院子中立
了一块告示牌（ｓｉｇｎ）。院子的东边是一座巨大阴森的石头建筑，向西则是出
狱的大门。
LONG
        );
    set("exits", ([ /* sizeof() == 3 */
       "west" : __DIR__"dayu",
    ]));
    set("objects", ([
        __DIR__"npc/yuzu" : 1,
    ]) );
        set("item_desc", ([
            "sign": "凡来此的犯人必须工作（ｗｏｒｋ）二十次方可出去。\n",
            "告示牌" : "凡来此的犯人必须工作（ｗｏｒｋ）二十次方可出去。\n",
        ]) ); 
    set("no_magic", 1);
    set("no_fight", 1);
    set("no_spells", 1);
    set("no_fly",1);
    set("outdoors", "jinan");
    set("coor/x",60);
    set("coor/y",1880);
    set("coor/z",0);
        setup();
} 
void init(){
        add_action("do_work", "work");
    if(!wizardp(this_player()) && this_player()->query("marks/有伤风化")){
            "/cmds/std/look"->look_room(this_player(),this_object());
            this_player()->set("startroom", __FILE__);
            add_action("do_quit","quit");
    }
} 
int do_work(){
        object me;
   int i, gin, sen;
        me = this_player();
        i = me->query_temp("jail_work");
        gin = me->query("jing");
        sen = me->query("qi");
        if(me->is_busy()) return notify_fail("你的动作还没有完成，不能工作。\n");
        message_vision("$N辛苦的工作累的要死\n", me);
        if(me->query("jing") > 1){
                me->add("jing",-(gin/10));
        }
        if(me->query("qi") > 1){
                me->add("qi",-(sen/10));
        }       
        me->start_busy(2);
        me->set_temp("jail_work", i+1);
        return 1;        
} 
int valid_leave(object me, string dir){
        object obj;
        
        if(obj = present("yu zu", this_object())) {
                if(dir == "west" ) {
                        if(me->query("marks/有伤风化") && me->query_temp("jail_work") < 20){
                                return notify_fail("狱卒喝道：“站住，还没有作完工就想走？”\n");
                        } else if(me->query_temp("探监")){
                                me->delete_temp("探监");
                        } else if(me->query("marks/有伤风化")){
                                me->delete("marks/有伤风化");
                        } 
                        me->delete_temp("jail_work");
                }
                if(dir == "east"){
                        if( me->query("marks/有伤风化")){
                                return notify_fail("狱卒嘿嘿笑道：“怎么样？想坐牢吗？”\n");
                        } else if(!me->query_temp("探监")) {
                                return notify_fail("狱卒说道：“牢房重地，闲人莫如。”\n");
                        } 
                }
        }
        return 1;
}
int do_quit(){
        "/cmds/usr/quit"->main(this_player(),"");
        return 1;
}       
