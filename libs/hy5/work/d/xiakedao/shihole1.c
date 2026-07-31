// /d/xiakedao/shihole1.c 侠客岛 石洞1

inherit ROOM;

int do_learn(string arg);
void create()
{
        set("short", "石洞");
        set("long", @LONG
这里依次是六个石洞，各自通向四句诗的石室。后人研习「侠客
行」武功，悟出六句总纲，也分别刻在这里。此洞一色青布帷幔，侍
立的弟子均是青衣长剑。正面壁上，粗隶刻着前四句诗的总纲「一剑
飞鸿」。
LONG );
        set("exits", ([
                "out"   : __DIR__"neiting",
                "enter" : __DIR__"shihole2",
                "north" : __DIR__"shiroom01",
                "south" : __DIR__"shiroom02",
                "east"  : __DIR__"shiroom03",
                "west"  : __DIR__"shiroom04",
        ]));
        set("objects", ([
                __DIR__"npc/wangwu": 1,
                __DIR__"npc/xdizi2": 2,	
        ]));
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        int i;
        object *inv;
        me = this_player();
        if(dir!="out")
        {
           if( me->query("weiwang")>=20 || me->query("family/family_name") =="侠客岛")
           {
                inv = all_inventory(me);
                for(i=sizeof(inv)-1; i>=0; i--)
                   if(inv[i]->query("weapon_prop") && ((string)inv[i]->query("equipped")=="wielded"))
                       if(objectp(present("wang", environment(me))) &&
                           living(present("wang", environment(me))))
                         return notify_fail("王五上前挡住你，朗声说道：这位" +
                             RANK_D->query_respect(me) + "里面是本岛重地，不准比试武功。你可以进去，但不得手持兵刃。\n");
                return ::valid_leave(me, dir);
           }
           else
           {
                   if(objectp(present("wang wu", environment(me)))&&
                   living(present("wang", environment(me))))
                     return notify_fail("王五拦住你说道：里面是本岛重地，只有各派掌门及著名的侠客才能进去。\n" + RANK_D->query_rude(me) +"你还是回去吧。\n");
           }
        }
        return ::valid_leave(me, dir);
}

