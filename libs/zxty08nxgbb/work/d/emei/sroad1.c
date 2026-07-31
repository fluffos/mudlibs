// Room: /d/emei/sroad1.c  

inherit ROOM;

void create()
{
	set("short", "南村口");
	set("long", @LONG
这里有一处小村落，村口处长满了桃树，此时正是桃花盛开的季节，带
露的桃花在阳光照射下娇艳无比，远远望去红云一片，姹紫嫣红。在村中错
落有秩的分布着许多房屋，正面一条碎石路，往北通向村子的中心，在村口
处有一木牌上写着三个字『桃源村』。
LONG
	);

        set("exits", ([
              "north":__DIR__"sroad2",
              "east":"/d/emei/user-room/melodies/home",
	]));
        set("outdoors", "emei");
	setup();
}
void init()
{
    add_action("do_jump", "jump");
}

int do_jump(string arg)
{
    object me = this_player();
    object room;
    if (arg != "boat") return command("jump "+arg);
    if(!(room = find_object(__DIR__"boat")))
         room = load_object(__DIR__"boat");
     if(objectp(room))
    {

      if((int)room->add_temp("person_inside") > 0 )
    {
       return notify_fail("小舟已经座满人了，你等下一次吧！\n");        
     } 
   else {
        room->add_temp("person_inside",1);
     }
   } 
   
    message_vision("$N解开了绳索，跳上了小舟！\n",me);
    me->set_temp("from_yanbohu",1);
    me->move(__DIR__"boat");
    return 1;
}
