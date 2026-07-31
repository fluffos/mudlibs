// Room: home.c
#include "ansi.h"

inherit ROOM;
string short;
string long;

void create()
{
short=read_file(__DIR__"short.txt");
long =read_file(__DIR__"long.txt");
set("wiz_only",1);
            set("short",short);
set("long",long);

//        set("no_die", 1);

        set("exits", ([
              "west":  "/d/emei/sroad1",
                "ct" : "/d/city/guangchang",
        ]));
        setup();
}

void init()
{
object me,ob;
        me=this_player();
     if( (me->query("id")=="melodies"))
        {
        write(WHT"\n欢迎主人回家！\n"NOR);
                if( (me->query("id")=="xuer")&&
					present("melodies",environment(me)) )
                        {
                        if(!(ob=find_player("melodies")) )
                                return;
                        else
                                {
                                ob->command("kiss xuer");
                                ob->command("ce 欢迎雪儿回家");
                                }
                        }
        } else
        {
        write(HIR"欢迎"+me->query("name")+"来雪儿和麦芽儿的家中作客\n"NOR);
        if(!present("melodies",environment(me))&&
                          (ob=find_player("melodies")) )
                {
            tell_object(ob, query("short") + "告诉你：来客人了，是" +
                                                  me->query("short")+
                                               "("+me->query("id")+")\n");
                write("麦芽儿正在闲逛，一会儿会回来的，您先请坐。\n");
                if(present("xuer",environment(me)) )
                        {
                        message_vision(
           "\n麦芽儿给$N打了个电话，叮咛$N道：好好招待客人哟...\n",
                                                  find_player("xuer"));
                        }
                }
        else if(!find_player("melodies"))
                {
                write("麦芽儿不在家，请随便。\n");
                }


        }
}
