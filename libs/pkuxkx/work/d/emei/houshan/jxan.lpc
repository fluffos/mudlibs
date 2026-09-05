// Room: /u/cuer/emei/jxan.c

inherit ROOM;

void create()
{
	set("short", "静修庵");
	set("long", @LONG
这里是静修庵，是灭绝师太静修的地方。这儿人迹罕
至是静修的好地方。在一片松林中，露出一扇小门，进去
就看见了一个仙风道骨的老师太，她就是峨嵋派的掌门--
--灭绝师太，后边小屋是一个扶持她的姑娘(enter door)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shandao3",
]));            

        set("objects", ([
            __DIR__"npc/miejue" : 1, 
            ]));
    set("valid_startroom", 1);
	setup();
}
void init()
{
        add_action("do_enter","enter");
        add_action("do_push","pushdown");
        add_action("do_pull","pullup");
}

int do_pull()
{
    object me=this_player();
    object *ob;
    
    if (me->query("id")!="zine")
    {
        return 0;
    }
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: TASK_D->place_belong(environment($1))==TASK_D->place_belong(this_object()) :) );
    message( "channel:" + "chat", "峨嵋山又恢复了宁静。\n", ob );
    this_object()->set("no_verify",0);
    return 1;
}

int do_push()
{
    object me=this_player();
    object *ob;
    
    if (me->query("id")!="zine")
    {
        return 0;
    }
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: TASK_D->place_belong(environment($1))==TASK_D->place_belong(this_object()) :) );
    message( "channel:" + "chat", "你忽然感觉脚下大地开始震颤，莫不是峨嵋山地震了？\n", ob );
    this_object()->set("no_verify",1);
    return 1;
}

int do_enter(string arg)
{
        object me = this_player();
        if(!arg || arg =="")
        return 0;
        if (arg =="door")
         {
         if (me->query_temp("marks/方"))
         {
         message_vision("$N走进了小屋。\n",me);
         me->move(__DIR__"xiaowu");
         message_vision("$N从屋外走了进来。\n",me);
         me->set_temp("marks/方",0);
         return 1;
         }
         else
         {
         write("没事别乱闯姑娘的闺房？\n");
        return 1;
         }
}
}
