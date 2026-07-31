// Room: /u/jpei/thd/bookroom.c
// 增加得到jiugong tu的难度 Modified by Numa 19990921

inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
这里是黄药师读书的地方。窗明几净，一尘不染。一张古意盎然的书案放
在房间正中，案上摆着几本翻开了的线装书籍。
LONG
        );

        set("exits", ([
                "west" : __DIR__"shilu",
        ]));

        set("item_desc", ([
                "书案" : "一张古意盎然的书案，上面散乱的放着几本书。\n",
                "shuan" : "一张古意盎然的书案，上面散乱的放着几本书。\n",
        ]));

        setup();
}

void init()
{
        object me = this_player();
  	
  	if (me->query_temp("thd/tupu"))
        {
                add_action("do_fan","fan");
                add_action("do_fan","zhao");
                return;
        }
}

int do_fan(string arg)
{
        object me = this_player();
 	mapping fam;
        object ob;
        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        
        if (!(fam = me->query("family")) 
           || fam["family_name"] != "桃花岛")
        	return notify_fail(RANK_D->query_respect(me) + "不是本派弟子，到这里来瞎翻什么？\n");
        
        if (!arg)
                return notify_fail("什么？\n");
	
	if (arg=="shuan" || arg == "书案")
	{
        	ob = unew(__DIR__"obj/tupu");
                
		if(!clonep(ob))
                	return notify_fail("你来晚了，九宫八卦图解已经被人拿走了。\n");
        	if(clonep(ob) && ob->violate_unique()){
           		destruct(ob);
                	return notify_fail("你来晚了，九宫八卦图解已经被人拿走了。\n");
                }
                write("你仔细的翻了翻书案，找到了一本关于奇门八卦的书!\n");
                write("你如获至宝，赶忙捡了起来。\n");
                ob->move(me);
                me->delete_temp("thd/tupu");
                return 1;
        }
}
