
#include <ansi.h>


inherit NPC;
int do_tell(string);
int do_chat(string);
int do_rumor(string);
int do_drop(string);


void create()
{
        set_name("警卫", ({ "guard" }));
        set("long", "他是一个年轻的警卫，面色严肃，目光冰冷让人不寒而立。\n");
        set("nickname", "铁面无私");
        set("gender", "男性");
     
        set("age", 27);
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 17);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 90);
        set_skill("force", 80);
        set_skill("dodge", 100);
        set_skill("whip",130);
        set_skill("taiji-shengong",50);
        map_skill("force", "taiji-shengong");
        set("jiali",50);

        set("combat_exp", 95000);

        set("max_qi", 500);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

       
        setup();
        set("chat_chance", 10);


        carry_object("/d/wizard/obj/gun")->wield();
        carry_object("/d/wizard/obj/jingfu")->wear();

}

void init()
{
        ::init();
        add_action("do_chat","chat");
      add_action("do_chat","chat*");
      add_action("do_chat","rumor*");
        add_action("do_chat","rumor");
        add_action("do_chat","tell");
        add_action("do_chat","hslj");
        add_action("do_chat","act");
        add_action("do_chat","baowei");
        add_action("do_drop","do");
      add_action("do_chat","vote");
      add_action("do_chat","quit");
        add_action("do_drop","drop");

}




int do_chat(string target)
{
        object me;

        me = this_player();
       
         

write("警卫喝道：你已经被剥夺了政治权利，少说为妙。\n" );
    return 1;
         }
int do_drop(string target)
{
        object me;

        me = this_player();
       
         

write("警卫喝道：你已经被剥夺了政治权利，此指令无效。\n" );
      return 1;   
      }
   void unconcious()
{

}
void die()

{

}

