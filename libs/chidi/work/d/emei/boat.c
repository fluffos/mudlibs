// Room: /d/emei/boat.c 小舟

inherit ROOM;
void create()
{
	set("short", "小舟");
	set("long", @LONG
一叶小舟，最多也就能载三、四人。一根长长的竹杆(bamboo)插在船尾，
看来可以用它来撑船前行。
LONG
	); 
       set("item_desc", ([
           "bamboo" : "这是一根用来划船(use)的竹竿。\n",
             ])) ;
	setup();
}
void init()
{
    add_action("do_use", "use");
    add_action("do_jump","jump");
}

int do_jump(string arg)
{
    object room;
    object me = this_player();
    if (arg != "out") return command("jump "+arg);
    if ( me->query_temp("used"))
      return notify_fail("你想找死吗？船没有到岸呢！\n");
    message_vision("$N“嗖”的一声从小舟里蹦了出来，跳在了湖岸上！\n",me);
    if(!(room = find_object(__DIR__"boat")))
         room = load_object(__DIR__"boat");
    room->delete_temp("person_inside");     
    if ( me->query_temp("from_taoyuan") && me->query_temp("arrive_taoyuan"))
     {
         me->move(__DIR__"sroad1");
         me->delete_temp("arrive_yanbohu");
         return 1;
     }
    if ( me->query_temp("from_yanbohu") && me->query_temp("arrive_yanbohu"))
     {    
        me->move(__DIR__"yanbohu");
        me->delete_temp("arrive_taoyuan");
        return 1;
    }
   
    if ( me->query_temp("from_taoyuan") )
    {
        me->move(__DIR__"yanbohu");
        return 1;
    }
    if ( me->query_temp("from_yanbohu") )
    {
        me->move(__DIR__"sroad1");
        return 1;
    }
   
}

int do_use(string arg)
{
    
    object room;
    object me = this_player();
    if ( me->query_temp("used"))
        return notify_fail("现在已经在划船了。\n");
    if (!arg || arg != "bamboo") 
        return notify_fail("你想使用什么？\n");
        
    message_vision("$N拿起竹竿，插入水面，撑船向湖中划去。\n",me);
    me->set_temp("used",1);    
    message_vision("这里是碧波荡漾的水面，水面上生长了许多荷花。随着船的不断前行，迎面有微风吹来，"
           "风动荷叶景色怡人，小舟慢悠悠的在荷花从中穿行着。\n",me);
    if ( me->query_temp("from_yanbohu")  )
   {
     if ( me->query_temp("arrive_yanbohu",1) )
     {
      me->start_call_out( (: call_other, __FILE__, "taoyuan", me :), 5);
      }
     else {
      me->start_call_out( (: call_other, __FILE__, "yanbohu", me :), 5);
   
     }
    return 1;
   }
   if ( me->query_temp("from_taoyuan"))
      {
       if ( me->query_temp("arrive_taoyuan",1) )
     {
      me->start_call_out( (: call_other, __FILE__, "yanbohu", me :), 5);
      }
     else {
      me->start_call_out( (: call_other, __FILE__, "taoyuan", me :), 5);
     }
    return 1;
   }
    return 1;  
}
void taoyuan(object me)
{
    object room;
    if( room = find_object(__DIR__"boat") )
    {
         message("vision","\n在恍惚间，小舟已经靠了岸。遥遥望去在远处有一座村庄，"
            "村人往来穿梭，四处炊烟袅袅。\n",room);
     }
     me->set_temp("arrive_taoyuan",1);
     me->delete_temp("from_yanbohu");
     me->set_temp("from_taoyuan",1);
     me->delete_temp("used");
}
void yanbohu(object me)
{
    object room;
    if( room = find_object(__DIR__"boat") )
    {
       message("vision","\n在恍惚间，小舟已经靠了岸。遥遥望去在远处成行的柳树排列有序，"
            "一条小道通向树林深处。\n",room);
     }
     me->set_temp("arrive_yanbohu",1);
     me->delete_temp("from_taoyuan");
     me->set_temp("from_yanbohu",1);
     me->delete_temp("used");
}
