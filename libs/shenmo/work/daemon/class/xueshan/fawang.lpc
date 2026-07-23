// /kungfu/class/xueshan/fawang.c  金轮法王
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        object ob;
        set_name("金轮法王", ({ "jinlun fawang", "fawang", "fawang" }));
        set("long",@LONG
他是雪山寺的护教法王。在雪山寺的地位仅次与掌门人鸠摩智。
身穿一件紫红袈裟，头带僧帽。
LONG
        );
        set("title", HIY "法王" NOR);
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 60);
        set("int", 60);
        set("con", 60);
        set("dex", 60);
        set("max_qi", 18000);
        set("max_jing", 18000);
        set("neili", 54500);
        set("max_neili", 54500);
        set("jiali", 100);
        set("combat_exp", 9500000);
        set("score", 200000);

        set_skill("necromancy", 380);
        set_skill("xiaowuxiang", 380);
        set_skill("force", 280);
        set_skill("longxiang", 380);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 380);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 380);
        set_skill("parry", 220);
        set_skill("cuff", 200);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 380);
        set_skill("lamaism", 250);
        set_skill("literate", 200);
        set_skill("hammer", 380);
        set_skill("riyue-lun", 380);
	set_skill("dashou-yin", 380);
        set_skill("staff", 380);
        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        set_skill("kwan-yin-spells", 380);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.riyue" :),
                (: perform_action, "hammer.lian" :),
                (: perform_action, "hammer.yuan" :),
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.riyue" :),
                (: perform_action, "hammer.lian" :),
                (: perform_action, "hammer.yuan" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}
	set("inquiry", ([
		"十三龙象袈裟" : "这是本门佛宝，不能轻易给你，这样吧帮我找一朵藏红花吧！\n",
	]));

        create_family("雪山寺", 2, "护教法王");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/jinlun")->wield();
        if (clonep()) {
                if (random(4)==0)
{
                ob = new(__DIR__"13jiasha");
                ob->set("jiasha/neili",13);
                ob->move(this_object());
                ob->wear();
}
}

        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        add_money("gold",1);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "男性") {
                command("say 修习密宗内功需要纯阳体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        if ((string)ob->query("class") != "bonze") {
                command("say 我佛门的清规戒律甚多。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        if ((string)ob->query("family/family_name") != "雪山寺")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                return;
                  }

        if ((int)ob->query_skill("lamaism", 1) < 80) {
                command("say 入我雪山寺，修习密宗心法是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "是否还应该多多钻研本门的心法？");
                return;
        }

        command("smile");
        command("nod");
        command("say 你就随我学习佛法吧！");
        command("recruit " + ob->query("id"));

        ob->set("title", HIY"活佛"NOR);
}
int accept_object(object ob, object obj)
{
       if(!ob||environment(ob)!=environment() ) return 0;
       
       if(!objectp(ob) ) return 0;
 
       if( !present(obj,ob) )
        { 
         say("你有吗？？\n");
         return 1;
        }  

        if(obj->query("id")=="zang honghua")
{
        if( present("shisan longxiang",this_object()) )
{
obj->set("no_get",1);
command("say 太好了，藏红花可是雪山一宝啊!");
command("remove shisan longxiang");
command("say 这件十三龙象袈裟就送给你护法之用吧。");
command("give shisan longxiang to "+ob->query("id"));
}
else command("say 老僧，身无长物，真不知道怎么谢谢你!");
        return 1;
}
}
