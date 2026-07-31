 inherit ROOM;
void create()
{
        set("short", "龙门客栈废墟");
        set("long", @LONG
这儿有一片残垣断壁，几间东倒西歪的小土屋，没有门，没有窗，只是一个个
的窟窿，风吹过呜呜的响。屋檐下一面破碎的锦旗，拂去黄尘，依稀可以辨出“龙
门客栈“几个字，想来原是过往行商歇脚之处，不知为什么被废弃了。
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"qingtongxia",
                        ]));
        set("objects", ([
                __DIR__"npc/bandit" : 2,
        ]));
        set("outdoors", "eren"); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init() {
        
         add_action("do_around", "around");
} 
int do_around(){
        object me, room;
        
        me=this_player();
        if (!me->query_temp("eren/bandit_around"))      return 0;
        tell_object(me,"你紧追着马贼向废墟后跑去。\n");
        room = find_object(__DIR__"banditcamp1");
        if(!objectp(room)) 
                room = load_object(__DIR__"banditcamp1");
        me->move(room); 
        message("vision",me->query("name")+"向废墟后追去，绕了几圈也不见了。\n",this_object());
        return 1;
} 
