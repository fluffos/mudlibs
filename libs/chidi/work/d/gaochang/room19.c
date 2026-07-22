inherit ROOM;
void break_b(object me);
void create()
{
    set("short", "独木桥");
    set("long", @LONG
这是一条宽约七寸的独木桥(bridge)，天风凛冽，吹的人衣襟头发齐飞，
只要一不留神，稍一失足，立刻便要粉身碎骨。两崖相隔，约有五十余丈，往
下看，峭壁如刀削，云卷雾涌，深不见底，投块石子下去，也听不到回声！
LONG
    );
    set("exits", ([ 
  "south" : __DIR__"room18",
  "north" : __DIR__"room20",
]));
        set("item_desc",([
    "独木桥":"    一条宽约七寸的独木桥，看来只能过一个人。\n",
    "bridge":"    一条宽约七寸的独木桥，看来只能过一个人。\n",
    ]));

    setup();
}
void init()
{
    object me=this_player();
    object room,*obj;
    int i;
    if (wizardp(me)) return;
    if (me->query("DIED")>2  && me->query("combat_exp")<10000 ) return;
    if (!room=find_object(__DIR__"room18"))
         room=load_object(__DIR__"room18");
// 判断桥的另一间房的OBJ
    obj=all_inventory(room);
    if (sizeof(obj))
    for (i=0;i<sizeof(obj);i++){
         if (obj[i]->is_character() && !obj[i]->is_corpse() ) 
        {
          break_b(me);
          room->break_b(obj[i]);
          return;
        }
     }
// 判断这间房的OBJ
    obj=all_inventory(this_object());
    if (!sizeof(obj)) return;
    for (i=0;i<sizeof(obj);i++){
         if (obj[i]==me) continue;
         if (obj[i]->is_character() && !obj[i]->is_corpse() ){
          break_b(me);
          break_b(obj[i]);
          return;
        }
     }
    
}
void down_die(object me)
{
    if (me)  me->die();
}
void break_b(object me)
{
    object room=find_object(__DIR__"room50");
    if (wizardp(me)) return;
    if (random(10)<5){
    if (!room)
      room=load_object(__DIR__"room50");
    message_vision("独木桥断了。$N惨嚎一声，掉下绝崖。\n",me);
    me->set_temp("die_for","掉下绝崖摔");
    me->move(room);
    message("vision",me->name()+"惨嚎一声，掉了下来。\n",room,({me}));
        if((int)me->query("qi")<1000) call_out("down_die",1,me);
        else {
    me->receive_damage("qi", 1000);
    me->receive_wound("qi", 1000);
    me->unconcious();
    }
    }else
    {
    if (!(room=find_object(__DIR__"room74")))
      room=load_object(__DIR__"room74");
    message_vision("危桥断了。$N惨嚎一声，掉下绝崖。\n",me);
    me->set_temp("die_for","掉下绝崖摔");
    me->move(room);
    message("vision",me->name()+"惨嚎一声，掉了下来。\n",room,({me}));
    }
}
