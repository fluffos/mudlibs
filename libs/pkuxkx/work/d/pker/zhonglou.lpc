//Made by goodtaste

inherit ROOM;
void create()
{
        set("short", "效忠楼");
        set("long", @LONG
这里是杀手帮的效忠楼，当中一块大匾，“效忠楼”三字龙飞凤舞气势,非凡
按杀手帮的规矩，每个入门弟子都必须在此宣誓(swear)永远忠于帮主,方可
入门.
LONG
        );
       
        set("exits", ([
                "south" : __DIR__"guangchang",
                "north" : __DIR__"shijie4",
                ]));
          set("objects", ([
             __DIR__"npc/langhuitou" : 1,
           ]));
        setup();
}


void init()
{
   add_action("get_swear","swear");
}


int get_swear(string arg)
{
   object me=this_player();
   if(!arg||arg!="我将永远忠于帮主，若有悖逆，天诛地灭!!")
   { 
     write("你以为这是什么地方，居然开这样的玩笑，小心项上人头!\n");
     return 1; 
   }
    write("你既然已经发誓忠于我帮，现在可以进去了\n");        
    me->set_temp("swear",1);
   return 1;
}



int valid_leave(object me, string dir)
{
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);   
	if (!wizardp(me) &&dir == "north"&&(me->query_temp("swear")!=1))
                return notify_fail("你没有发誓忠于帮主，就不能进去!（swear 我将永远忠于帮主，若有悖逆，天诛地灭!!）\n");
        if(!me->query_temp("face_zhu")&&!me->query("pker")&&dir == "north")
                return notify_fail("没有得到梁总管的允许，你不能进去!!\n"); 
        if( me->query("pker") && !me->query("accomplish2") && (dir == "north") )
                return notify_fail("浪回头拦住了你：帮主的命令，完成任务前你不能见他!!\n");
	return ::valid_leave(me, dir);
}



