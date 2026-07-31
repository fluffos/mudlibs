// linghu.c 令狐冲
#include <ansi.h>

inherit NPC;
int ask_lingshan();
int ask_feng();
void create()
{
        set_name("令狐冲",({"linghu chong","linghu","chong"}));
                set("long",
                "华山派掌门人岳不群的大弟子，\n"
                "他今年二十多岁。\n");
        set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
        set("gender", "男性");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        set("max_kee", 800);
        set("max_gin", 500);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 50);
        set("combat_exp", 50000);
        set("score", 10000);
        set_skill("force",80);
        set_skill("huashan-neigong", 80);
        set_skill("dodge", 80);
        set_skill("huashan-shenfa", 80);
        set_skill("huashan-jianfa", 60);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("dugu-jiujian",60);
        set_skill("literate", 80);
        set_skill("cuff", 90);
	set_skill("poyu-quan", 90);

	map_skill("cuff", "poyu-quan");
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");

        prepare_skill("cuff", "poyu-quan");

        create_family("华山派",19,"弟子");

        set("inquiry", ([
                "田伯光" : "他要我跟他下山去见仪琳。\n",
                "岳灵珊" : (: ask_lingshan :),
                "风太师叔" : (: ask_feng :),
        ]) );
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/bluerobe")->wear();
}
int ask_lingshan()
{ mapping myfam;
        if (!(myfam = this_player()->query("family"))
            || myfam["family_name"] != "华山派")
   {
      say("令狐冲说：你问我小师妹干什么？\n");
      return 1;
   }
  else
   {
      say("令狐冲说：她是我的小师妹呀。你怎么会不知道呢？\n");
        set("chat_chance", 10);
        set("chat_msg", ({
        "令狐冲低头自言自语说：小师妹已经几天没来了。\n",
        "令狐冲低头自言自语说：小师妹知道我学了风太师叔的剑法应该替我高兴吧。\n",
        "令狐冲低头自言自语说：小师妹现在又和林平之在一起吧。咳！\n",
        }) );
      this_player()->set_temp("marks/珊1", 1);
    return 1;
   }
}

int ask_feng()
{
  if ((int)this_player()->query_temp("marks/珊1")) {
     say("令狐冲说：风太师叔在山洞中，可他平时不愿见华山弟子。\n");
     this_player()->set_temp("marks/风1", 1);
     return 1;
  }
  else {
     say("令狐冲说：风太师叔是前辈高人，已隐居多年，没人知道他在哪里。\n");
     return 1;
  }
}
