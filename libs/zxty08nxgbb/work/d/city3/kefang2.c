inherit ROOM;

#define KEFANG  "/d/city3/kedian2"

int doing(object me);
int halt_do(object me);
void update_user(object user);
void do_touch(object me,object obj);
void do_make(object me,object obj);
void do_kiss(object me,object obj);
void do_hug(object me,object obj);
void do_tuo(object me,object obj);
void create()
{
        set("short", HIY "黄玫瑰" NOR);
        set("long", @LONG
屋子布置的精致富丽，当中一张红木案，案上两只花瓶，瓶里插着几
枝黄玫瑰。花瓶旁铺着几张信筏，放着些笔墨砚石，未入此处，清新的花
香已沁人心裨。南边有扇窗子(window)，景色宜人。一张绣榻放在墙角，
两只金钩轻搭纱帐。房间虽不大，但是给人清新舒适的感觉。
LONG
        );
        set("exits", ([ 
  "out" : __DIR__"kedian2",
]));
    set("item_desc", ([
        "window" : 
"    往下望是川流不息的人群，阳光下，流动的人群象微风中的彩带, 城中
的房屋连绵不断，索碎的小路象细小的银蛇，蜿蜒盘旋在灰色的房屋之间。
窗户正下方是一株郁郁葱葱的大榕树。\n", 
])); 

        set("sleep_room", "1");
                setup();
}
void init()
{
    add_action("do_sleep", "sleep");
    add_action("do_open","open");
    add_action("do_close","close");
}
int do_sleep(object arg){
    int doing_cost;
    object obj,me,where;

    me=this_player();
    where = environment(me);
    if(!arg || !objectp(obj = present(arg, environment(me)))){
         return 0;
    }

    if (me->query("gender")=="无性"){
        tell_object(me,"唉!你无根无性，今生今世都没这个能力了！\n");
        return 1;
    }
    if( !obj->is_character() ){
        tell_object(me,"看清楚一点呀！。\n");
        return 1;
    }

    if((string)obj->query("gender") == (string)me->query("gender")){
        tell_object(me,"你不怕" + RED"AIDS"NOR + "吗？\n");
        return 1;
    }
    if (obj->query("gender")=="无性"){
        tell_object(me,"唉!"+obj->name()+"无根无性，今生今世都没这个能力了！\n");
        return 1;
    }

    if (me->is_busy() || me->query_temp("pending/doing")){
        tell_object(me,"你现在正忙着呢。\n");
        return 1;
    }

    if( (int)me->query("qi") < 100 ){
        tell_object(me,"你现在的气太少了。\n");
        return 1;
    }
    if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 ){
        tell_object(me,"你现在精不够！\n");
        return 1;
    }
    if( userp(obj))
      if ((object)obj->query_temp("asking_who")!=me ) {
        message_vision("\n$N向$n含情脉脉的看着,象是向$n示爱 \n", me,obj);
        me->set_temp("asking_who", obj);
        obj->set_temp("asked_who",me);
        tell_object(obj, MAG "如果你愿意和对方....，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 sleep 指令。\n" NOR);
        write(HIY "由于对方是由玩家控制的人物，你必须等对方同意才能继续。\n" NOR);
        return 1;
     }else{
      if (me->query("gender")=="男性")
        message_vision("\n$N向$n点了点头。\n", me,obj);
      else
        message_vision("\n$N羞涩地看了$n一眼，涨红了脸，微微地点了点头。\n", me,obj);
     }
     me->delete_temp("asking_who");
     obj->delete_temp("asked_who");

    if (userp(obj)){
    if (me->query("gender")=="男性"){
      message_vision("\n$N温柔地抱起$n，$n的身体在$N怀里轻轻颤动了一下。\n$N用热唇轻轻的给了$n一吻。\n", me,obj);
    }else{
        message_vision("\n$N主动地搂着$n，$n也张开双臂，把$N紧紧地搂在怀里。\n$N用热唇轻轻的给了$n一吻。\n", me,obj);
    }
    }else{
        message_vision("\n$N一见$n就象是着魔似的，二话不说就将$n抱住... ... ... ...  \n", me,obj);
    }
    me->set_temp("doing_with",obj);
    doing_cost=50;
    me->set_temp("make_cost",doing_cost);
    me->set_temp("doing_cost",doing_cost);
    me->start_busy((: doing :), (:halt_do:));

    obj->set_temp("doing_with",me);
    doing_cost=random(obj->query("jing"));
    obj->set_temp("make_cost",doing_cost);
    obj->set_temp("doing_cost",doing_cost);
    obj->start_busy((: doing :), (:halt_do:));

    return 1;
}
int doing(object me)
{
    object obj;
    int doing_cost;
    int exp_gain =random(30);
    int doing;
    if (!me) return 1;
    doing_cost = (int)me->query_temp("doing_cost");
    obj=(object)me->query_temp("doing_with");
    if (doing_cost < 1)
        return 0;
    me->add("combat_exp", exp_gain);
    doing_cost--;
    me->set_temp("doing_cost", doing_cost);

    me->add_temp("time_count",1);
    if (living(me))
        me->add("jing", -random(10));
    else{ me->add("jing", 1); me->set_temp("unconcious",1);}
    if (!obj || !present(obj, this_object())){
        me->start_busy(0);
        return 0;
    }
    doing=doing_cost*100/me->query_temp("make_cost");
    if (obj->query("gender")!="男性")
        if (doing<95 && !me->query_temp("pending/tuo")){ do_tuo(me,obj); me->set_temp("pending/tuo",1);}
        else if (doing<80 && !me->query_temp("pending/hug")){ do_hug(me,obj); me->set_temp("pending/hug",1);}
        else if (doing<60 && !me->query_temp("pending/kiss")){ do_kiss(me,obj); me->set_temp("pending/kiss",1);}
        else if (doing<30 && !me->query_temp("pending/touch")){ do_touch(me,obj); me->set_temp("pending/touch",1);}
        else if (doing<15 && !me->query_temp("pending/make")){ do_make(me,obj); me->set_temp("pending/make",1);}
    if (doing_cost > 0)
        return 1;
    if (me->query_temp("unconcious"))
    {
        message_vision("由于精力消耗过度，$N再也支持不住，晕倒在$n面前。\n", me,obj);
        me->unconcious();
    }   
    me->add("make_loves",1);
    obj->add("make_loves",1);
    obj->start_busy(0);
    me->delete_temp("doing_with");
    obj->delete_temp("doing_with");
    me->delete_temp("time_count");
    me->delete_temp("unconcious");
    me->delete_temp("make_cost");
    me->delete_temp("pending");
    update_user(me);
    update_user(obj);
    return 1;
}
int halt_do(object me)
{
    return 1;
}
void do_tuo(object me,object obj)
{
    object ob;
    message_vision(BOLD "$N脱下自己的衣带，光着身子钻进被窝。\n" NOR, me);
     foreach (ob in all_inventory(me)){
        if (!ob->id("marry ring")){
        if ( ob->query("no_drop") || (!ob->vaule() && !ob->query("value")) )
            destruct(ob);
        else
            ob->move(this_object());
      }
      }
        message_vision(BOLD "$N轻轻解开$n的衣带，露出了洁白的肌肤。\n" NOR, me,obj);
     foreach (ob in all_inventory(obj)){
        if (!ob->id("marry ring")){
        if ( ob->query("no_drop") || (!ob->vaule() && !ob->query("value")) )
            destruct(ob);
        else
            ob->move(this_object());
      }
      }
}
void do_hug(object me,object obj)
{
        message_vision("$N紧紧抱住了$n，$n觉得一片温馨。\n", me ,obj);
        
}
void do_kiss(object me,object obj)
{
    message_vision("$N吻遍了$n的每一寸肌肤!\n", me,obj);
}
void do_touch(object me,object obj)
{
        message_vision("$N抚摸着$n柔柔的身体!\n", me,obj);
}
void do_make(object me,object obj)
{
    message_vision( 
     HIM "  月光穿过窗户，轻撒在床前....... \n" NOR,me,obj);
}
void update_user(object user)
{
    object cloth,*ob;
    int i;

    if (!userp(user)){
      ob=all_inventory(this_object());
      for (i=0;i<sizeof(ob);i++){
          if (ob[i]->is_character() ) continue;
          if (ob[i]->move(user)){
              message_vision("$N拣起一"+ob[i]->query("unit")+ob[i]->query("name")+"。\n" NOR, user);
              ob[i]->wear();
          }
      }
         return;
    }
    if (wizhood(user) == "(player)") {
        if (user->query("shen")>10000)
            cloth = new("/clone/misc/red_cloth");
        else if (user->query("shen")<-10000)
            cloth = new("/clone/misc/black_cloth");
        else if (user->query("gender")!="女性")
            cloth = new("/clone/misc/cloth");
        else    cloth = new("/clone/misc/pink_cloth");
        cloth->move(user);
        cloth->wear();
        if (user->query("age")<18){
            cloth = new("/clone/misc/site");
            cloth->move(user);
        }
    }else{  if (user->query("gender")!="女性")
                cloth = new("/clone/misc/baipao");
        else    cloth = new("/clone/misc/color_cloth");
        cloth->move(user);
        cloth->wear();
    }
    UPDATE_D->check_user(user);
}

int do_open(string arg)
{
    object room;
    if (!arg || arg!="door")
        return notify_fail("你要打开什么？\n");
    room=find_object(KEFANG);
    if (!room)
        room=load_object(KEFANG);
    set("exits", ([   "out" : __DIR__"kedian2",]));
    if (room->query("exits/2"))
        return notify_fail("门已经打开了。\n");
    room->set("exits/2",base_name( this_object() ));
    message_vision("$N轻轻地把房门打开了。\n",this_player());
    message("vision","依耶一声，有人把"+this_object()->name()+"的房门打开了。\n",room);
    return 1;
}
int do_close(string arg)
{
    object room;
    mapping exits;
    if (!arg || arg!="door")
        return notify_fail("你要关上什么？\n");
    room=find_object(KEFANG);
    if (!room)
        room=load_object(KEFANG);
    delete("exits");
    if (!room->query("exits/2"))
        return notify_fail("门已经关闭了。\n");
    exits=room->query("exits");
    map_delete(exits,"2");
    message_vision("$N轻轻地把房门关上了。\n",this_player());
    message("vision","依耶一声，有人把"+this_object()->name()+"的房门关上了。\n",room);
    return 1;
}
void reset()
{
    object room;
    string arg;
    ::reset();
    if (NATURE_D->outdoor_room() )
        return;
    room=find_object(KEFANG);
    if (!room)
        room=load_object(KEFANG);
    set("exits", ([   "out" : __DIR__"kedian2",]));
    room->set("exits/2",base_name( this_object() ));

    room=find_object("/d/city3/kedian");
    if (!room)
        room=load_object("/d/city3/kedian");
    message_vision("小二气冲冲地跑了进来：大白天的，还睡什么觉？\n");
    arg="";
    foreach (object ob in all_inventory()){
    if( ob && ob->is_character() && !ob->is_corpse() )
         arg+=ob->name();
         ob->move(room);
     }
     if (arg!=""){
         message("vision","小二拽着"+arg+"扯出门外。\n",this_object());
         message("vision","小二拽着"+arg+"扔了出来。\n",room);
     }
}

