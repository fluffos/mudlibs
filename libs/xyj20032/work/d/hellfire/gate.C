#include <ansi.h>
inherit ROOM;
#include <banned.h> 
void create()
{
        set("short", HIY"寒冰地狱"NOR);
        set("long", @LONG

※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※※※  这就是入口了，没有一定的修为，最好还是不要乱闯哦。※※※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

LONG);
        set("exits", ([
                "down" : "/d/hellfire/hellfire1/in.c",
        ]));
        set("objects", ([
        ]));
        set("hellfireroom",1); 
        setup();
}

void init()
{
        add_action("do_quit",banned_action);  
        add_action("do_cast","cast");
        add_action("do_exert","exert");
}



int do_quit(string arg) 
{  
        write("你不能在这里用这条命令。\n");  
        if (wizardp(this_player())) write("巫师请参阅同一路径内的banned.h文档。\n");  
        return 1;  
}  

int do_cast(string arg) { 
        if(!arg) return 0; 
        if(arg !="transfer" )
                write("你不能在这里用这条命令。\n");   
        command("cast "+arg);   
        return 1;    
}

int do_exert(string arg) { 
        if(!arg) return 0;
        if(arg !="recover" && arg != "heal" && arg != "refresh") return 0;
        command("exert "+arg);  
}
int valid_leave(object me, string dir)
{
        object ridee;
        ridee=me->ride();

        if( dir=="down" && !userp(me))
                return 0;

        if (dir=="down") {
                if( me->query_temp("ridee") )
                        return notify_fail(WHT"你还是先从坐骑上下来吧。\n"NOR);
        }

        me->set_temp("hellfire_enter_time",time());
        return ::valid_leave(me, dir);
}
