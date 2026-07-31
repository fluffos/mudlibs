// 后院 houyuan.c
// zly 1999.06.10
 
inherit ROOM; 

void close_gate();
int do_jump(string arg);
int do_unlock(string arg);

void create() 
{ 
        set("short", "后院");
        set("long", @LONG
你走进后院，迎面是一个假山水池(chi)，池中立着一块巨大无比
的假山，假山那里好象有一块可以落脚的地方，水池的两旁种满了各
种各样的花草。南面是萧府的大厅。北面好象有个小门(door)。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ 
            "south" : __DIR__"dating",
]));

        set("item_desc", ([
            "chi" : "池塘上一些荷叶漂在上面。\n",
            "door" : "那是一扇竹门，门好象锁着，那是通向后山的必经之路。\n",
        ]));
        set("objects", ([
             __DIR__"npc/zuo" : 1,

        ]));
        //set("objects", ([
         //__DIR__"npc/xiaoyaozi":1,
         //__DIR__"npc/changcf":1,
         //__DIR__"npc/huajy":1,
         //__DIR__"npc/gaiyiming":1,
        //]));

        setup();
}

void init()
{
        
        add_action("do_jump", "jump");
        add_action("do_jump", "tiao");
        add_action("do_unlock", "unlock");
        add_action("do_unlock", "kai");
}

int do_jump(string arg)
{
        object me = this_player();
        if (arg == "chi") {

	if ( objectp(present("zuo tianxiong", environment(me))) )
{
		message("vision", me->name() + "被卓天雄拦住。\n",
                                environment(me), ({me}) );
		write("卓天雄拦在了水池前。\n");
		return 1;
}		
                if (me->query_skill("dodge", 1) >= 120) {
                        message("vision", me->name() + "吸了口气，纵身向对面跃去。\n",
                                environment(me), ({me}) );
                        write("你吸了口气，纵身向对面跃去。\n");
                        me->move(__DIR__"shitou");
                        message("vision", "只见人影一闪，" + me->name() +  "纵身跃了过来。\n",
                                environment(me), ({me}) );
                        
                        return 1;
                }
                else {
                        message("vision", me->name() + "纵身向对面跃去，只听“扑通”一声，" + me->name() + "摔入池中，狼狈的爬了回来。\n",
                                environment(me), ({me}) );
                        write("你纵身向对面跃去，只听“扑通”一声，你摔入池中，狼狈的爬了回来。\n");
                        me->receive_damage("qi",80);
                        return 1;
                }
        }
        return 0;
}

int do_unlock(string arg)
{
        object room;
        object me = this_player();
        object ob;

        if (arg == "door") {
        if (query("exits/north"))
                return notify_fail("门已经是开着了。\n");

        if (!(ob = present("hong yaoshi", this_player())))
                return notify_fail("你不会撬锁。\n");
        message_vision(
        "$N用一把钥匙打开了小门，可是钥匙却断了.\n", this_player());
        destruct(ob);

       if(!( room = find_object(__DIR__"shulin")) )
                room = load_object(__DIR__"shulin");
       if(objectp(room))
        {
                set("exits/north", __DIR__"shulin");
                message_vision("$N使劲把门打了开来。\n",this_player());
                room->set("exits/south", __FILE__);
                message("vision","外面有人把门打开了。\n",room);
                remove_call_out("close_gate");
                call_out("close_gate", 10);
        }
        return 1;
     }
}

void close_gate()
{
        object room;

        if(!( room = find_object(__DIR__"shulin")) )
                room = load_object(__DIR__"shulin");
        if(objectp(room))
        {
                delete("exits/north");
                message("vision","只听乒地一声，竹门自动关了起来。\n",this_object());
                message("vision","你脑海中闪过一个念头：糟糕！进不去了！\n" ,
                         this_object());
                room->delete("exits/south");
                message("vision","只听乒地一声，竹门自动关了起来。\n",room);
                message("vision","你脑海中闪过一个念头：完了！出不去了！\n" ,
                        room );
        }
}
