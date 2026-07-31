//bye mei 
inherit ROOM;
int do_yell(string arg);
int do_diancai(object me);
int do_sit(object me);
void create()
{
        set("name", "银杏酒楼");
        set("short", "银杏酒楼二楼");
        set("long", @LONG
你坐在成都最豪华的酒楼上，看着楼下的凡人忙忙碌碌，
心情很是愉快，所谓“对酒当歌，人生几何”，还犹豫什么，
来几斤上好的花雕酒吧！墙上挂着价格牌子(paizi)。
LONG
        );

        set("item_desc", ([
                "paizi" : "本店欢迎客人点菜。需要点菜，请叫(yell)小二。\n",
        ]));

        set("exits", ([
                "down" : __DIR__"jiulou1",
        ]));
        set("objects", ([
                  __DIR__"obj/chair" : 4,
                  __DIR__"obj/table" : 1,
        ]));

        setup();
}
void init()
{
    this_player()->delete_temp("dian");
    add_action("do_yell", "yell");
}
int do_yell(string arg)
{
    if( !arg || arg=="" ) return notify_fail("你想叫小二吗？");
    if ( this_player()->query_temp("rode/type")!="sit" )
        return notify_fail("你还是先坐下再说。\n");
    if( arg=="xiao er" ) arg = "小二";
    if( (int)this_player()->query("neili") < 300 )
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
            this_player());
    else if( (int)this_player()->query("neili") > 600 )
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
            "了出去。\n", this_player());
    else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
            this_player());
    if( arg=="小二"){
        call_out("do_diancai", 3,this_player());
        return 1;
        } else
        message_vision("楼面四周传来一阵回声：“" + arg +
            "～～～”\n", this_player());
    return 1;
}
int do_diancai(object me)
{
    object ob,xiaoer,room;
   if (!me || environment(me)!=this_object() ) return 1;
 
    xiaoer=find_living("xiao gouzi");
    if ( !xiaoer || !environment(xiaoer)){
          tell_object(me,"小二都死了，还点什么菜！\n");
          return 0;
    } else {
        if (!present("xiao gouzi", this_object() )){
                message("vision",xiaoer->name()+"吆喝一声，“来了！”\n，急急忙忙地跑开了。\n",environment(xiaoer));
                xiaoer->move(this_object());
                message("vision",xiaoer->name()+"急急忙忙地跑了过来。\n",this_object());
         }else
        tell_object(me,xiaoer->name()+"不是在你旁边吗？\n");
    }
    call_out("do_zuo", 5,me,xiaoer);
    return 1;
}
int do_zuo(object me,object xiaoer,object ob)
{
   if (!me || environment(me)!=this_object()|| !xiaoer || environment(xiaoer)!=this_object() ) return 1;
    if( me->query_temp("rode/type") != "sit" ) { 
         message_vision("$N用袖子把凳子使劲搽了搽，道：客官请坐下来点菜吧！\n", xiaoer); 
         } else {
         if(!present("cai dan", me)){
            message_vision("$N说道：这位客官想吃点什么？这有张菜单，点好了请吩咐小的。\n",xiaoer); 
            ob = new(__DIR__"obj/caidan");
            ob->move(me);    
            message_vision("$N从怀里拿出一本菜谱，交给了$n。\n",xiaoer,me);
              } else 
            message_vision("$N笑眯眯地对$n说道：这位客官想吃点什么？\n",xiaoer,me);
            return 1;              
            }
         return 1;                
}
int valid_leave(object me,string dir)
{
    if ( dir=="down" && me->query_temp("rode/type")=="sit" && !wizardp(me)){
       return notify_fail("你必须先站(stand)起来才能走路。\n");
    }
    return 1;
}

