// 岳飞墓
// by male 02/9/3

#include <ansi.h>

inherit ROOM;

string look_mubei();

void create()
{
    set("short",HIC"岳  飞  墓"NOR);
   set("long", HIW@LONG
      这里就是宋朝名将岳飞的坟墓,你可以在这里凭吊(pingdiao)这一位民族英雄.
                           ■■■■■■■■■■■■
                         ■■■■■■■■■■■■□
                       ■■■■■■■■■■■■□□   
                       ■                    ■□□       
                       ■                    ■□□		
                       ■         宋         ■□□		
                       ■         岳         ■□□             
                       ■         鄂         ■□□             
                       ■         王         ■□□             
                       ■         墓         ■□□             
                       ■                    ■□□                         
                       ■                    ■□□		
                       ■                    ■□□		
                   ◇◇■                    ■□□ ◇◇◇◇	
                ◇◇◇ ■                    ■□ ◇◇◇◇◇
              ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇	
　 　       ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇◇◇
            ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇◇
　　        ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇

LONG NOR
    );

    set("exits", ([
    "northwest":__DIR__"mubian",
     "south":__DIR__"muqian",
    ]));
/*
    set("objects", ([
    "/kungfu/class/xiakedao/mujianfeng":1,
    ])  );
*/
    set("no_fullme_scan",1);
    set("item_desc",([
        "墓"        :    (: look_mubei :),
        "岳飞墓"        :    (: look_mubei :),
    ]));
    set("no_fight",1);
    set("no_steal",1);
    set("no_sleep",1);
        set("objects", ([

                __DIR__ + "npc/pingdiaozhe" : 5,
        ]));
    setup();
}
void init()
{
      add_action("do_pingdiao","pingdiao");
}

int do_pingdiao(string arg)
{
object me;
me=this_player();
if(me->is_busy()) return notify_fail("你不是正在凭吊么?\n");
if(me->query("jing")<50)
  return notify_fail("你的精不够!\n");
message_vision(HIW"$N站在墓前低下头凭吊岳王爷这一位民族英雄.....\n"NOR,me);
me->start_busy( 50);
me->add("jing",10);
call_out("end_pingdiao",30,me);
return 1;
}

void end_pingdiao(object me)
{
tell_object(me,HIW"你凭吊完毕,站起身来\n"+HIR"你感觉你的正气有所增加!\n"NOR);
me->start_busy(1);
me->add("shen",100);
}


string look_mubei()
{
    return "  还 我 河 山 !\n";
}
