// xiaosong.c 宋青书
#include <ansi.h>
inherit NPC;
int ask_me(object me);
void create()
{
        set_name("宋青书", ({ "song qingshu", "song" }));
        set("long",
                "他就是宋远桥的儿子宋青书。\n"
                "他今年二十岁，乃是武当第三代中出类拔萃的人物。\n");
        set("gender", "男性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 25);
        set("int", 28);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 30);
        set("combat_exp", 80000);
        set("score", 10000);
        set_skill("force", 60);
        set_skill("taiji-shengong", 60);
        set_skill("dodge", 80);
        set_skill("tiyunzong", 80);
        set_skill("unarmed", 80);
//      set_skill("taiji-quan", 50);
        set_skill("parry", 80);
        set_skill("sword", 70);
        set_skill("taiji-jian", 80);
//      set_skill("taoism", 30);
//      set_skill("literate", 40);
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        set("inquiry",([
                "莫声谷" : (: ask_me :),
                ]) );
        create_family("武当派", 3, "弟子");
        set("shen_type",-1);
set("score",5000);
setup();
        carry_object("/d/wudang/obj/songsword")->wield();
}
int ask_me(object me)
{	
        int i;
        object *obj;
        if ((int)this_player()->query_temp("xiaosong"))
            {   command("say 再说废话也没用，去死吧！\n");
		return 1;
	    }
        if ((int)this_player()->query_temp("witness"))
        {       
        message("vision",HIY"宋青书目露凶光，厉声喝道：“你，你都知道了！”\n"NOR,environment(me),me);
        me->delete_temp("witness");
        me->set_temp("xiaosong",1);
        obj = all_inventory(environment());
        for(i=sizeof(obj)-1; i>=0; i--) {
                if( !userp(obj[i]) ) continue;
                kill_ob(obj[i]);
                obj[i]->fight(this_object());
        }
        command("say 既然都知道了，就别想活着出这间屋子。\n");
	return 1;
	}
	command("sigh");
        command("say 他是我七叔，可惜被奸人暗害了，唉。。。\n");
	return 1;
}
