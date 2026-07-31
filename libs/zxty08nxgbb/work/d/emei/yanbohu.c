// Room: /d/emei/yanbohu.c 烟波湖


inherit ROOM;

void create()
{
	set("short", "烟波湖");
	set("long", @LONG
这里是路的尽头，一池湖水挡住了去路。只见湖水荡漾，碧波粼粼，湖面
烟气浩淼。这里杏花夹径，绿柳垂湖，暖洋洋的春风吹在身上，当真是醺醺欲
醉。一阵风过，湖面的柳枝，随着一升一沉，不住摇动，点成一个个漪涟。在
湖边绿波上飘荡着一叶小舟(boat)。
LONG
	);

	set("exits", ([
                 "south":__DIR__"rongshulin2",
	]));
        set("item_desc", ([
           "boat" : "这是一只小舟，可以使用(jump)跳上去。\n",
             ])) ;
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
    me->set_temp("from_taoyuan",1);
    me->move(__DIR__"boat");
    return 1;
}
