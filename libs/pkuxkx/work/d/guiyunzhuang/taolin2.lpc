// taolin1.c
// By Pingpang 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "桃花林");
    set("long", @LONG
你在这片桃林里可以闻到一股扑鼻的桃花的香气.
桃林里芳香四溢，似乎有毒，你好像混混欲睡。
LONG
    );
     set("exits", ([
        "west" : __DIR__"jiashan",
          ]));
     set("no_task",1);
                            
      setup();
}
void init()
{       
        object ob;
        ob=this_player();
        if(userp(ob)&&!wizardp(ob)&&!ob->query_temp("guiyun_taolin")) //iszt@pkuxkx, 2006-09-24
        {
        ob->set_temp("guiyun_taolin",1);
        ob->unconcious();
        message_vision(YEL"$N难以抑制住桃花香气，混混然的倒在地上。\n"NOR,ob);
        return;
        }
}
void unconcious()
{
}
