inherit ROOM;
#include <ansi.h> 

void create ()
{
  set ("short", "ÇàÄ¾ÁÖ³ö¿Ú");
  set ("long", HIG @LONG
Í»È»ÎŞÊı¿Ã²ÎÌì´óÊ÷ÖĞ³öÏÖÁËÒ»ÌõĞ¡¾¶£¬ËÆºõÊÇ³ö¿Ú£¡¬
LONG);

  set("exits", ([
      ]));

  set("no_magic", 1);
	setup();
}

int valid_leave (object me, string dir)
{
  me->set("startroom","/d/city/wumiao");
  me->set_temp("lost_in_greenyard",0);
  me->set_temp("out_of_greenyard",0);
  return 1;
}

