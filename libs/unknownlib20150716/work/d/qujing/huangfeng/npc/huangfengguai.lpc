//Cracked by Roath
 

inherit NPC;
#include <ansi.h>

void create()
{
          set_name("黄风怪", ({"huangfeng guai","yao guai","guai"}));
          set("long","一个身高六丈的妖怪，手中执一把三股叉。\n");
          set_level(95);
          set("gender", "男性");
          set("age", 50);
          set("force_factor", 80);

          set_skill("unarmed",950);
          set_skill("dodge",950);
          set_skill("force",950);
          set_skill("parry",950);
          set_skill("fork",950);
          set_skill("spells",950);
  
          set_skill("mihouxinjing",950);
          set_skill("wuxing-quan",950);
          set_skill("dragonforce",950);
          set_skill("fengbo-cha",950);
          set_skill("dragonstep",950);
          set_skill("puti-zhi",950);
          map_skill("spells", "mihouxinjing");
          map_skill("unarmed","wuxing-quan");
          map_skill("force", "dragonforce");
          map_skill("fork", "fengbo-cha");
          map_skill("parry","fengbo-cha");
          set("class","dragon");
          setup();
          add_money("gold", 10);
         carry_object("/d/qujing/huangfeng/obj/fork")->wield();
}

void die ()
{
  object ob = this_object();
  message_vision(HIM"只见黄风怪摔倒在地，现了本形。原来是只黄毛貂鼠！\n"NOR,ob);
  message_vision(HIM"天上传来灵吉菩萨的声音：孽畜！还不跟我回去伏法。\n"NOR,ob);
  destruct (ob); 
}

void unconcious ()
{
  die ();
}
