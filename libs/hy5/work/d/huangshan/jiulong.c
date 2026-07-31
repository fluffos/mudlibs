 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "九龙瀑");
        set("long", @LONG
峰回路转，眼前景色又是一变，一道瀑水自天都，峰玉屏诸峰，然后在香炉，
罗汉两峰的悬崖九折而下，一折一潭，九瀑九潭，因此得名。每逢大雨之后，瀑水
从天而降，流而复折，折而复聚，悬于千仞绝壁，宛如九龙飞舞，姿态曼妙。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"mroad1",
//  "up" : AREA_SHENSHUI"midao1",
  "northwest" : __DIR__"zhulin",
]));
    set("item_desc", ([
        "绝壁": "这里虽然陡峭无比，但石壁突兀不平，你可以试着从这（cliff）爬（climb）上去。\n",
        "cliff": "这里虽然陡峭无比，但石壁突兀不平，你可以试着从这（cliff）爬（climb）上去。\n",
    ]) );
    set("outdoors", "huangshan");
    set("coor/x",-550);
    set("coor/y",-480);
        set("coor/z",20);
        setup();
}  
void init(){
        add_action("do_climb","climb");
}  
int do_climb(string arg){
        object me;
        me= this_player();
        if(!arg || arg != "cliff"){
                return 0;
        }       
        if (me->query_temp("jiulong_climb")) {
                tell_object(me,"你已经在试着爬了。\n");
                return 1;
        }
        message_vision("$N抓住绝壁上突出的石块，向上小心爬去！\n", me);
   me->start_busy(2);
        call_out("arrive", 2, me);
        me->set_temp("jiulong_climb",1);
        return 1;
}   
int arrive(object me){
        int i;
        object room;
        if (me->is_ghost())     return 1;
        i = me->query_skill("dodge",1);
        if(i < 30){
                message_vision("$N一失手，从上面掉了下来！\n",me);
                me->receive_wound("qi",100);
        }else if (i < 50 && !random(5)){
                message_vision("$N一失手，从上面掉了下来！\n",me);
                me->receive_wound("qi",100);
        }else {
                room=find_object("/d/huangshan/pond");
                if(!objectp(room)) 
                        room = load_object("/d/huangshan/pond"); 
                me->move(room);
                me->delete_temp("jiulong_climb");
                message_vision("$N慢慢地爬了上来。\n",me);
        }       
        return 1;
}
