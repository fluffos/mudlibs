inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "³ÐµÂµî");
        set("long",
"\n"
"                              A
                           s_O_O_O_s
                          /LLLLLLLLL\\                          
                         ||====||====||
                         ||====||====|| 
                       s________________s
                      /LLLLLLLLLLLLLLLLLL\\
                  ^^||=========||=========||^^  
               s________________________________s
               /LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\\
             ^^||=========||=========||=========||^^ 
    []==[]__[]__[]__[]||[]__[]||[]__[]||[]__[]__[]__[]_[]==[]
    []==[]__|__|__|__|__|_©³©¥©¥©¥©·_|__|__|__|__|__|__[]==[]
    []==[]_|__|__|__|__|__©§"HIY"³ÐµÂµî"NOR"©§__|__|__|__|__|__|_[]==[]
    []==[]__|__|__|__|__|_©»©¥©¥©¥©¿_|__|__|__|__|__|__[]==[]
    []==[]_|__|__|__|__|__/        \\__|__|__|__|__|__|_[]==[]
    []==[]__|__|__|__|__|_|        |_|__|__|__|__|__|__[]==[]
    []==[]_|__|__|__|__|__|        |__|__|__|__|__|__|_[]==[]
    []==[]__|__|__|__|__|_|        |_|__|__|__|__|__|__[]==[]\n\n"
);

        set("outdoors", "bianliang");
        set("no_fly",1);
        set("exits", ([
                "enter"    : __DIR__"diannei",
                "south"    : __DIR__"hgdadao6",
        ]));

        set("objects", ([
                __DIR__"npc/jinyiwei" : 3,   
        ]));
        setup();
}

int valid_leave(object me,string dir)
{
       object *env,room;
       int i;

       room=this_object();
       if( userp(me) && me->query("degree_jungong") < 8 )
       {
        me->apply_condition("tongji",100+me->query_condition("tongji"));
        env=all_inventory(room);
        for(i=0;i<sizeof(env);i++)
        if( env[i]->query("id") == "jinyi wei" )
          {
           env[i]->command("say "+"´óµ¨¿ñÍ½£¬¾ÓÈ»¸Òµ½¹¬ÖÐÀ´ÈöÒ°£¬ÊÜËÀ°É£¡\n");
           env[i]->kill_ob(me);
          } 
       }
       return ::valid_leave(me,dir);
}

