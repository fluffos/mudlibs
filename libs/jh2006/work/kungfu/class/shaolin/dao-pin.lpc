// Npc: /kungfu/class/shaolin/dao-pin.c

inherit NPC;
string ask_me();

void create()
{
	set_name("道品禅师", ({
		"daopin chanshi",
		"daopin",
		"chanshi",
	}));
	set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 18);
	set("con", 20);
	set("dex", 23);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp",80000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("yijin-jing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("finger", 51);
	set_skill("mohe-zhi", 51);
	set_skill("blade", 54);
	set_skill("xiuluo-dao", 54);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "mohe-zhi");
	map_skill("blade", "xiuluo-dao");
	map_skill("parry", "xiuluo-dao");

	prepare_skill("finger", "mohe-zhi");

	create_family("少林派", 39, "弟子");
        set("inquiry", ([
            "少林刀法" : (: ask_me :),
               	]));
        set("chandao_count",1);
	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

#include "/kungfu/class/shaolin/dao.h"

string ask_me()
{
 object ob;
 mapping fam;
 if (!(fam = this_player()->query("family")) || fam["family_name"] != "少林派")
 return RANK_D->query_respect(this_player()) + 
        	"与本派素无来往，不知此话从何谈起？";
       if (query("chandao_count") < 1)  
           return "你来晚了，那本书我已经给别人了。\n";
       ob=new("/d/shaolin/npc/obj/book-chandao");
       ob->move(this_player());
       add("chandao_count", -1);
       message_vision("道品从怀中掏出一本禅刀精义递给$N。\n",this_player());
       return "此书是我佛门刀法至宝，你要好好研究。";
}        
