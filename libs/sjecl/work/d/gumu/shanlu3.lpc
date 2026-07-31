// Room: /u/xdd/gumu/shanlu3.c
// Modify By River 98/08
#include <ansi.h>

inherit ROOM;

void create()
{
     set("short", YEL"山路"NOR);
     set("long", @LONG
继续南行，此处的山路显得稍有陡峭，路边松林里有一块石碑(shibei)，
远望过去，可见“长春”字样，正是全真七子之长春子丘处机有感苍生劳苦所
题词句。
LONG        );

     set("outdoors","古墓");

     set("exits", ([
         "eastup" : __DIR__"ztm",
         "northdown" : __DIR__"shanlu2",
     ]));

     set("item_desc", ([
             "shibei" : HIW"\n\t\t天苍苍兮临下土，胡为不救万灵苦？ \n"+
                           "\t\t万灵日夜相凌迟，饮气吞声死无语。 \n"+
                           "\t\t仰天大叫天不应，一物细琐枉劳形。 \n"+
                           "\t\t安得大千复混沌，免教造物生精灵。 \n"NOR,
     ]));

     set("coor/x",-10);
  set("coor/y",-10);
   set("coor/z",30);
   setup();
}
