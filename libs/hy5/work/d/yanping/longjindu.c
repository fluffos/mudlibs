// Room: /d/yanping/yanjindu.c
// Date: Sep 28, 2002  Winder

#include <ansi.h>
inherit ROOM;

void create()
{

  set("short", "龙津渡");
  set("long", @LONG
延平又称剑津、剑浦、南剑州，均源于晋时雌雄宝剑“双剑化龙”
的历史典故：〖晋书·张华传〗载“（雷焕）遣使送一剑与华，留一自
佩，…，华诛，失剑所在。焕卒，子华为州从事，持剑行经延平，剑忽
自子腰间坠水，使人没水取之，不见剑，但见两龙各长数丈，蟠萦有文
章，没者惧而返。须叟，光彩照水，波浪惊沸，于是剑失。”此处便是
化龙之处，双溪在汇成闽江 (river)，汹涌东去。
LONG );
  set("exits", ([
    "northwest" : __DIR__"yanfumen",
//  "to" : "/d/fuzhou/matou",
  ]));
  set("no_clean_up", 0);
  set("outdoors", "yanping");
  set("coor/x", 1530);
  set("coor/y", -6200);
  set("coor/z", 10);


  setup();
}
