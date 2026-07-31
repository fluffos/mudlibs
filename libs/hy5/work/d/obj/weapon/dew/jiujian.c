       //jiujiani.c 
           //by dewbaby@skxy
 
#include <weapon.h>
#include <ansi.h>
       inherit SWORD; 

    void create()
       { 
          set_name(MAG"九剑妖魂"NOR,({"jiu jian","jiujian"})); 
           set_weight(4000); 
              if( clonep() ) 
            set_default_object(__FILE__);
              else { 
                      set("unit","柄"); 
                      set("value",4000); 
                      set("no_drop","1");
                      set("no_sell","1"); 
                      set("material","gold"); 
                      set("long",MAG"据说这是九天玄女的神剑，它周身散发着耀眼的光芒。\n"NOR); 
                      set("wield_msg",MAG"$N淡淡一笑，$n"MAG"已经被$N"MAG"握在手中。一道妖气瞬间包围了你。\n"NOR); 
                      set("unwield_msg",MAG"$N双眼微闭，眨眼间已将$n"MAG"插回腰间。\n"NOR); 
                      set("no_drop","还是不要丢吧，小心九天玄女要了你的小命！\n"); 
                    } 
          init_sword(900); 
           setup();
      } 

