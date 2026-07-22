// /d/xiakedao/shiroom15.c 侠客岛 石室15
inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
这里酒气浓重，地上抛弃了不少酒袋或葫芦。东侧两人说话已经
含糊不清，兀自向嘴里不停倒酒，踉跄地模仿石壁(wall)上的图案。
距二人丈许外一个女子掩鼻而立，面带厌恶之色。
LONG );
        set("exits", ([
                "west"  : __DIR__"shihole4",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「眼花耳热後」几个大字。下面刻的是鲁智深醉闹山
门的故事，画中的胖和尚大醉如泥，惟妙惟肖。空中又绘着无数落叶，
随风飞舞。
WALL
        ]));
        set("no_clean_up", 0);
  set("no_fight_npc", 1);
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


