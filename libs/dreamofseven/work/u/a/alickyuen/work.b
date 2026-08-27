#include <ansi.h>

inherit ROOM;
void welcome(object ob,int i);

void create()
{
        set("short", "禁閉室");
        set("long",@LONG
這裡是供給袁世凱大人發呆、構想、休息的地方，在這裡你只看
到一個板子，上面寫著：『請勿打擾，馬上離開！』的字句。
LONG);
        set("valid_startroom", 1);
        set("no_kill", 1);
        set("no_fight", 1);
        set("exits",([
             "east" : "/d/wiz/hall1.c",
        ]));
        setup();
}
void init()
{
        object me;
        me=this_player();
//        if(me->query("id") != "alickyuen" && wiz_level(me) < 4 && userp(me) )
        if(me->query("id") != "alickyuen" )
                welcome(me,1);
         else welcome(me,2);
}
void welcome(object ob,int i)
{
        if( i == 1 )
        {
                ob->move(__DIR__"workroom3");
                tell_object(ob,RED"『請勿打擾，馬上離開！』\n"NOR);
        }
        else 
        {
//                ob->set("nickname",RED"禁閉中"NOR);
                tell_object(ob,YEL"『歡迎光臨！』\n"NOR);
        }
        return;
}

