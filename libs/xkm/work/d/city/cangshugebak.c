//Cracked by Roath
//  cangshuge 藏书阁
// modified by aln

inherit ROOM;


void create()
{
	set("short", "白鹿藏书阁");
	set("long", @LONG
这是一个非常宽畅的楼阁，一排又一排的书架(shujia)上整整齐齐地摆满了
书，令人目不暇给。樟木香味夹着墨香扑鼻而来，这里就是白鹿书院的藏书阁，
收藏着许多武学经典，武林中人，千万不可错过在此一睹为快的良机。
LONG
	);
       set("item_desc", ([
                "shujia" : "上面放着几本百家姓和千字文,你想要先向朱熹师付说一声。\n",
        ]));

	set("exits", ([
		"down" : __DIR__"shuyuan",
	]));

	set("cost", 0);

        set("no_fight", "1");
        set("no_steal", 1);
        set("no_sleep_room", "1");

	setup();
}


int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "你是来读书还是来练功啊？\n");
        return 1;
}

void init()
{
     add_action("do_qu","na");
}


int do_qu(string arg)
{ 
    object me,ob;
    string item,from;
    me = this_player();
    
     if ( !arg )
          return notify_fail("命令格式： na book from shujia \n");     

     sscanf(arg, "%s from %s", item,  from);

     if(from!="shujia")
          return notify_fail("命令格式： na book from shujia \n");     

     if (present("shu", this_player()))
	return notify_fail( "身上不是有书吗？怎么还会要拿，留点给别人呀？\n");
		
     if (present("shu", environment(me)))
	return notify_fail( "地上不是有本书吗？你不会捡呀。\n");
            
     if(item!="book")
          return notify_fail("你想拿什么？\n");     
        
    if (!me->query_temp("na/zhu",1)) 
        return notify_fail("不向人家要，你想偷书呀？\n");
                      
     if (me->query_skill("literate",1) >= 60 )
       {  ob = new("/d/city/obj/qzw");
         ob->move(me);
         me->delete_temp("na");
         return notify_fail("你从书架里拿出一本千字文书。\n");
       } else
	{ ob = new("/d/city/obj/bjx");
     	ob->move(me);
     	me->delete_temp("na");
     	return notify_fail("你从书架里拿出一本百家姓书。\n");
         }
}