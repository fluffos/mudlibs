// by dubei
inherit NPC;
#include <ansi.h>
void create()
{
	int age = 20 + random(20);
	set_name("武馆门卫", ({ "men wei", "menwei", "wei" }));
	set("gender", "男性");
	set("age", age);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set("apply/attack", 30);
	set("apply/defense", 30);
	set("apply/damage", 35);
	set("combat_exp", 150+age*10);
	set("shen_type", 1);
	setup();
	add_money("silver", 3+age/10);
        carry_object("clone/cloth/cloth")->wear();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	}
	
void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
//                  if ( ob->query("combat_exp") < 10000)  
//       command("say 这位" + RANK_D->query_respect(ob)+"，武功这么差，怎么闯江湖呢？\n");
       if ( ob->query("combat_exp") > 10000  && ob->query("combat_exp") < 80000 ){ 
         command("say 你武功已有根基，武馆已经无法再帮助你提高了，这位" + RANK_D->query_respect(ob)+"你我也算是有缘一场。\n");
       if (ob->query("enter_wuguan",1) ) ob->delete("enter_wuguan");
           command("say 我听说最近郭府正在广招天下英雄抵抗蒙古，你如前去投奔，一定对你有所帮助。如果你还不清楚就看看"CYN"(help guojob)"NOR"。\n");
            message_vision("$N听罢朗声一笑，抖起精神，准备步出武馆。心想从此纵然江湖险恶，自己也要立志创一番天下！\n", ob);
}
      if ( ob->query("combat_exp") > 100000)  
       command("say 这里只收留江湖新手，武功高强就不要再回来了！");
}

