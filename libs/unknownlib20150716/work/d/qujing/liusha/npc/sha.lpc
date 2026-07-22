//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
          set_name("妖怪", ({"yao guai","yao","guai"}));
          set("long","他本是卷帘大将，因蟠桃会失手打破玻璃盏，被贬到下界。\n");
          set_level(90);
          set("gender", "男性");
          set("age", 23);

          set("force_factor",20);
          set("env/wimpy",70);
          set_skill("unarmed", 900);
          set_skill("dodge", 900);
          set_skill("force", 900);
          set_skill("parry", 900);
          set_skill("staff", 900);
          set_skill("spells", 900);
          set_skill("buddhism",900);
          set_skill("jienan-zhi", 900);
          set_skill("lotusforce", 900);
          set_skill("lotusmove", 900);
          set_skill("lunhui-zhang", 900);
          map_skill("spells", "buddhism");
          map_skill("unarmed", "jienan-zhi");
          map_skill("force", "lotusforce");
          map_skill("staff", "lunhui-zhang");
          map_skill("parry", "lunhui-zhang");
          map_skill("dodge", "lotusmove");

         setup();
        carry_object("/d/qujing/liusha/obj/staff")->wield();
}

void die()
{
	object me = this_object();
	message_vision ("\n忽然天上传来玉帝的声音。\n",me);
  	message_vision ("\n你发现$N早已消失的无影无踪．\n",me);
	destruct(this_object());
 	return;
}
void unconcious ()
{
  die ();
}
