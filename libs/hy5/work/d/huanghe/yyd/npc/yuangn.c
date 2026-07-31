// yuangn.c 袁冠男
// zly 99.6.22

#include <ansi.h>
inherit NPC;
string ask_yyd();

void create()
{
        object ob;
        set_name("袁冠男", ({ "yuan guannan", "yuan", "guannan"}));
        set("gender", "男性");
        set("unique", 1);
        set("age", 22);
        set("long", "他是一个英俊的少年书生，手中轻轻摇着折扇。\n");
        set("attitude", "friendly");
        set("shen", 150000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);

        set("qi", 33900);
        set("max_qi", 33900);
        set("jing", 33900);
        set("max_jing", 33900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 350);

set_skill("huanhe-dao", 380);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 350);
set_skill("wuyu-quan", 350);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 350);
set_skill("sword", 350);
set_skill("club", 380);
set_skill("bawang-qiang", 380);
//map_skill("sword", "sumi-jian");
map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.huan" :),
                	(: perform_action, "blade.kuang" :),
                		(: perform_action, "blade.leitingpili" :),
                			(: perform_action, "blade.shiwanshenmo" :),
                				(: perform_action, "blade.tiandirenmo" :),
                					(: perform_action, "blade.xueyu" :),
                						(: perform_action, "blade.baoxue" :),
                						(: perform_action, "blade.baoxue" :),                							
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

        set("chat_chance", 3);
        set("chat_msg", ({
            "袁冠男长声吟到：“黄金逐手快意尽，昨日破产今朝贫，丈夫何事空啸傲？不知烧却头上巾......”\n",
            "袁冠男纵声长吟：“天子重英豪，文章教尔曹，万般皆下品，唯有读书高......”\n", 
        }) );

        set("inquiry", ([
//           "夫妻刀法"  : (: ask_yyd :),
        ]));

        setup();
        if (clonep()) {
                ob = new(__DIR__"obj/yuan");
                //ob = new("/clone/weapon/gangdao");
                ob->move(this_object());
                ob->wield();
        carry_object(__DIR__"obj/changpao")->wear();        
        add_money("gold",1);
   }
}

/*string ask_yyd()
{
        object me=this_player();
        if(me->query_skill("blade", 1) <120)
                return "你先把刀法的基础打好再说吧。\n";
        if(me->query("fuqi"))
                return "咦，你不是已经学到了夫妻刀法了吗？\n";
        if(me->query_temp("mb"))
                return "咦，我不是刚才告诉你了吗？\n";
        me->set_temp("mb",1);
        command("hmm");
        command("whisper "+me->query("id")+" 听师父师母说，教他们刀法的高僧圆寂在极南的小岛上。");
        return "这夫妻刀法，是当年一位高僧传给我的师父的，你如果真有信心和毅力，就去找那位高僧吧！\n";
}
*/
void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 who->set_temp("book145",1);
	::die();
}                                                                        