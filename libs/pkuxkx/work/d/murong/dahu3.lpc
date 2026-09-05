//dahu3.c
//by hehe
//2003.3.5

#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "太湖");
        set("long",@LONG
你不禁起了戒心，暗暗记忆小舟的来路，以备回出时不致迷路，
可是一眼望去，满湖荷叶、菱叶、芦苇、茭白，都是一模一样，
兼之荷叶、菱叶在水面飘浮，随时一阵风来，便即变幻百端，
就算此刻记得清清楚楚，霎时间局面便全然不同。
LONG);   
        set("no_task",1);
        setup();
}
void init()
{       
        object ob=this_player();
        if(!userp(ob)){
        ob->move("/d/murong/hubian1");
        return;
        }
}
