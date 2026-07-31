// Room: /testmud/d/changan/gudi.c
// This is a room made by Wsl.

inherit ROOM;
int do_break(string arg);
int do_jump(string arg);
int do_enter(string arg);
void create()
{
        set("short", "谷底");
        set("long", @LONG
头顶几道阳光照在地上，脚下是一片很厚的草地，走在上面软绵
绵的，很是恰意，四周看上去高不可攀，怪石嶙峋，你心中不由一惊
，要不是这片厚厚的草堆垫着，在好的轻功也会摔得变成一堆肉泥。
LONG
);
        setup();
}
void init()
{
    add_action("do_break", "break");
    add_action("do_jump", "jump");
    add_action("do_enter", "enter");
}
int do_break(string arg)
{
    int n;
int i;
	object *inv;
	int sizeinv;
        object room;
    object me = this_player();
    if(!this_player()->query_temp("killer")) return 0;
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你背着人什么也做不了！\n");
      		
		}

    if(!this_player()->query_temp("killer")) return 0;
    if(this_player()->query_temp("break")) return 0;
    if( !arg || arg!="岩石" )
    {
        write("你要震碎什么！\n");
        return 1;
    }
    n = (int)me->query("neili");
    if (n >= 3000)
    {
        message_vision("$N气运丹田，双掌直向前方打出一道劲力。\n", this_player());
        message_vision("只见被$N打碎的岩石四出飞溅，中间的一块巨岩承受不了震动，\n", this_player());
        message_vision("掉落在草地上，发出巨大的响声。你惊喜的发现在岩石上方出现了一个洞。\n", this_player());
        this_player()->set_temp("break",1);
        this_player()->set("neili",0);
        remove_call_out("close");
        call_out("close", 5, me);
    }else{
        message_vision("结果只听一声闷哼，$N被自己的内力震得眼前一黑....\n", this_player());
        this_player()->set("neili",0);
        this_player()->unconcious();
    }
    return 1;
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if(!me->query_temp("break")) return 0;
        if(me->query_temp("climb")) return 0;
        if( !arg || arg!="碎岩" )
        {
        write("你想跳到什么地方去？\n");
        return 1;
        }
        if ((int)me->query_skill("dodge",1) > 100 ) {
        message_vision("$N一个纵身，跳上了岩石。\n", me);
        me->set_temp("climb",1);
        me->delete_temp("braek");
        }else{
        message_vision("$N施展轻功，向上跳去，但却怎么也跳不上去。\n", me);
        }
        return 1;
}
int do_enter(string arg)
{
    int n;
int i;
	object *inv;
	int sizeinv;
        object room;
    object me = this_player();
    if(!this_player()->query_temp("killer")) return 0;
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你背着人什么也做不了！\n");
      		
		}
        if(!me->query_temp("climb")) return 0;
        if( !arg || arg!="岩洞" )
        {
        write("你想去那啊？\n");
        return 1;
        }
        message_vision("$N恭了恭身体，钻进了岩洞里。\n", me);
        me->move("/d/changan/mudong0");
        message_vision("“隆隆”，洞口已经封死了。\n", me);
        return 1;
}
void close(object room)
{
    object me;
    me = this_player();
    message("vision","似乎有股神秘的力量将掉落的岩石又拉了上去。\n", room);
    me->delete_temp("braek");
    me->delete_temp("climb");
}

