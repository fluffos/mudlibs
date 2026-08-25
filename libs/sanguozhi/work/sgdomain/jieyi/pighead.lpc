// created by ice on Jul 21 1999
#include <ansi.h>
inherit OBJ;
inherit M_GETTABLE;
void setup()
{
  set_id("pighead", HIY+"猪头"+NOR);
  set_long("一只用作祭品的猪头。");
  set_in_room_desc("一只用作祭品的"+HIY+"猪头"+NOR+"，端端正正地放在盘子里。");
     set_can_drop(0);
     set_can_drop("祭品都敢到处乱丢？\n");
     set_can_give(0);
  set_gettable(0);
  set_gettable("喂喂喂，祭祀的供品也要拿，不怕天谴吗？\n");
  set_unit("只");
	call_out("dest",100);
}
void dest()
{
       write("你突然看到地下伸出一只手，将盘子及里面盛的%^H_YELLOW%^猪头%^RESET%^一把就抓到地底下去了。\n");
       destruct(this_object());
}
