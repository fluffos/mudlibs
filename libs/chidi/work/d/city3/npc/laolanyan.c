// bye enter

inherit BHNPC;
string query_save_file() { return DATA_DIR + "npc/老烂眼"; }

void create()
{
        set_name("老烂眼", ({ "lao lanyan", "lao"}));
        this_object()->init_bhnpc();
  set("area_name","成都广场");
 set("area_file","/d/city3/guangchang.c");
   set("ziyuan","瓷器");
    set("kaifa",21);
 set("jizhi",35);
        set("gender", "男性");
        set("age", 25);
        set("long", "他这群小烂眼的头目，看来在小烂眼心目中还有点威信。\n");
        
        set("combat_exp", 10000);
        set("shen_type", -1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 5);

}
#include <die.h>
