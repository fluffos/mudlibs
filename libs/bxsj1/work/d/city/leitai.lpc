// leitai.c 扬州擂台前广场
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","擂台前广场");
        set("long",@long
这里是扬州擂台前面的一个大型广场，有许多人正在擂台上比武，到处
是人山人海，如果你也想试试身手，那么就请上擂台比试比试吧。
long);
        set("exits",([
              "tiandi" : "/d/wizard/lt",
              "fengyun" : "/d/wizard/lt1",
              "longhu" : "/d/wizard/lt2",
              "southeast" : __DIR__"guangchangbei",
//                "west" : "/cmds/leitai/bwdh/view1",
//                "east" : "/cmds/leitai/bwdh/view4",
        ]));
        set("outdoors", "扬州");
        set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   setup();
}                                         

int valid_leave(object me,string dir)
{
        object *ob;
        int i;       
        
        if(me->query_condition("killer") > 0 && dir != "southeast")
        	return notify_fail(HIW"\n通缉犯不得进入擂台重地！\n\n"NOR);
        ob = deep_inventory(me);
        i = sizeof(ob);
        while (i--)
        if ((ob[i]->is_character() || ob[i]->query("unique")) && dir != "southeast")
          	return notify_fail(HIW"\n你不得带人或带宝物进入擂台重地。\n\n"NOR);
        return ::valid_leave(me, dir);
}
