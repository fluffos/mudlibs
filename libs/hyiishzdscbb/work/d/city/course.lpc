// Room: bedroom.c
// Date: Sep.6 1997

#include <room.h>
inherit ROOM;

void create()
{
      set("short", "猫窝");
      set("long", @LONG
这里真是好棒的一间爱的小屋，竹藤扎就的窗外是一轮静静
的小湖，湖畔的柳枝条儿点着湖面一圈圈四散漫开。靠东是一张
电动大床，床头小柜上插满了九百九十九朵艳丽的红玫瑰，映在
对面的穿花大镜，真是满室春风。
    这里属于小猫和蒙面奇侠的二人世界。
LONG );
      set("exits", ([ /* sizeof() == 1 */
          "east": __DIR__"jiaowai1",
      ]));
      set("valid_startroom","1");

      set("no_fight", 1);
//      set("no_clean_up", 0);
      set("sleep_room", 1);
      setup();
      create_door("east", "垂花小门", "west", DOOR_CLOSED);
}
