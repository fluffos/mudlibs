

inherit ROOM;
#include <room.h>

void create()
{
      set("short","书房");
      set("long",@LONG
这是一间简陋的书房，屋角有一张木床靠近窗台放着一张表面
斑驳的木桌和一条竹椅，桌的左首是一盏昏黄的油灯，右边则凌乱
地摆放着几册泛黄的线装书，中央用铜镇纸压着一幅书法，龙飞凤
舞般地写着十六个大字：“生死涅磐，犹如昨梦；菩提烦恼，等似
空花。”显见主人淡泊功名之极。
LONG);
         
         set("exits",([ /* sizeof() == 1 */
          "west"    : __DIR__"keting",
         
      ]));
      set("valid_startroom","1");
      setup();
}

