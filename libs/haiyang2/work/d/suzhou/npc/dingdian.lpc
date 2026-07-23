 // by Xiaoyao

inherit NPC;
#include <ansi.h>
void destroying(object, object);

void create()
{
        set_name("丁典", ({ "ding dian", "ding" }));
        set("long", "这人满脸虬髯，头发长长的直垂至颈，衣衫破烂不堪，简直如同荒山中的野人。\n");
        set("gender", "男性");
        set("age", 35);
        set("unique", 1);
set("no_get",1);
        set_skill("unarmed", 520);
        set_skill("dodge", 520);
        set_skill("parry", 530);
        set_skill("force", 550);
	set_skill("taixuan-gong", 850);
        set_skill("shenzhao-jing", 380);
        map_skill("dodge","taixuan-gong");
        map_skill("force","taixuan-gong");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed","taixuan-gong");
        set("max_neili",80000);
        set("neili",80000);
        set("max_qi",36800);
        set("max_jing",36800);
        set("jing",36800);
        set("qi",36800);
        set("eff_jingli",38000);
        set("jingli",38000);
        set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
        set("combat_exp", 9900000);
        set("shen_type", 1);
        setup();
        carry_object("/clone/armor/cloth")->wear();
}

int accept_object(object me, object obj)
{
        if ((string)obj->query("id")=="lu juhua") {
        message("vision",me->name()+"给丁典一盆绿菊花。\n",environment(me),
            ({me}));
        if(!this_object()->query("book_count")) {
		command("say 我已经托人给霜华捎话了，不劳您大驾了。");
		return 0;
	}
	if (present("shenzhao jing", me)) {
		command("say 你身上不是有着神照经吗？");
		return 0;
	}
        command("touch "+me->query("id"));
        command("say 这位"+RANK_D->query_respect(me)+"是霜华派你来捎话的吧,嗨！我们可是苦命的鸳鸯。");

	if (!present("shenzhao jing", me)) {
		if (me->query("szj/passed")) {
		        new("/clone/book/shenzhao-jing")->move(me);
	        	message_vision("$n递给$N一本神照经。\n", me, this_object() );
		        command("say 这位"+RANK_D->query_respect(me)+"真是太感谢你了,这本内功心法希望你能好好珍惜。");
			this_object()->set("book_count", 0);
		} else if ((int)me->query("szj/failed") < 4 && me->query("kar") > 40 && !random(30)) {
		        new("/clone/book/shenzhao-jing")->move(me);
	        	message_vision("$n递给$N一本神照经。\n", me, this_object() );
		        command("say 这位"+RANK_D->query_respect(me)+"真是太感谢你了,这本内功心法希望你能好好珍惜。");
			this_object()->set("book_count", 0);
			me->delete("szj/failed");
			me->set("szj/passed", 1);
		} else {
			command("sigh "+me->query("id"));
			command("say 我身无长物，实在没什么可以给你的了。");
			if (me->query("szj/failed") < 5)
				me->add("szj/failed", 1);
		}
	}
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), obj);
        return 1;
        }
        return 0;
}

void destroying(object me,object obj)
{
        destruct(obj);
        return;
}
