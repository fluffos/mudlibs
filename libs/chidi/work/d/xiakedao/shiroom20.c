// /d/xiakedao/shiroom20.c 侠客岛 石室20

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
进得门来，便觉阵阵有形无质的气浪逼人，功力稍差之人似乎要
站立不稳。几位老者正在场中互较内功，身上衣衫高高蓬起。几名旁
观者均背靠石壁(wall)而立，神色紧张。
LONG );
        set("exits", ([
                "east"  : __DIR__"shihole5",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「煊赫大梁城」几个大字。下方图案极为简单，绘了
一团烈焰腾空而起，远观却又似混沌太极之形。一行注解写在图案正
中：刚不可久，柔不可守。图外亦注：《光武纪》：气佳哉！郁郁葱
葱然。
WALL
        ]));
        set("objects", ([
                __DIR__"master/du-nan"   : 1,
                __DIR__"master/du-e" : 1,
                __DIR__"master/du-jie" : 1,
                __DIR__"master/ai-laozhe" : 1,
                __DIR__"master/gao-laozhe" : 1,
        ]));
  set("no_fight_npc", 1);
        set("no_clean_up", 0);
       //  set("no_fight", 1);
        set("no_beg", 1);
        setup();
}
void init()
{
  add_action("discmds",({"ansuan","attack","sha","array","touxi","kill","steal","fight","hit","yun","cast"}));
        add_action("do_study","think");
        add_action("exert","exert");
}
int discmds()
{ 
   tell_object(this_player(),"大胆！在侠客岛也敢胡来？！\n");
    return 1;
}
int exert(string arg)
{
  object me=this_player();
   if( !arg ||arg=="roar" || arg=="maxsuck" || arg=="suck"|| arg=="jinglisuck"|| arg=="jingsuck"||arg=="neilisuck"||arg=="qisuck") 
  {
   message_vision(HIY"大胆！在侠客岛也敢胡来？！\n"NOR,me);
        return 1;
   }
   else
  "/cmds/skill/exert.c"->main(this_player(),"");
  }
#include "/d/xiakedao/shiroom.h"


