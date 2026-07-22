// /d/xiakedao/shiroom14.c 侠客岛 石室14
inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
这里光线黯淡，水珠时而从头顶的石壁上滴下，略略有些霉气把
石室照得明亮。壁上刻得有图有字。右侧一位老乞丐正在对着独自石
壁(wall)练拳，拳劲十足。
LONG );
        set("exits", ([
                "north" : __DIR__"shihole4",
        ]));
        set("item_desc", ([
                "wall" : @WALL
这面墙的字迹却与众不同，几个大字「五岳倒为轻」刻在正中。在大
字的比划中间，是密密的一段段小注，深浅不一。远远看去，却又颇
似图画。识得一行注是：象曰：山下有泽，损，君子以惩忿窒欲。
WALL
        ]));
        set("objects", ([
                __DIR__"master/hong"   : 1,
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


