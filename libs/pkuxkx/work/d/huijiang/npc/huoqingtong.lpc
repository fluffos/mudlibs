// huoqingtong.c 霍青桐

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("霍青桐", ({ "huo qingtong", "huo","qingtong" }));
        set("long", 
"这女郎秀美中透着一股英气，光采照人，当真是丽若春梅绽雪，神如
秋蕙披霜，两颊融融，霞映澄塘，双目晶晶，月射寒江。腰插匕首，
长辨垂肩，一身鹅黄衫子，头戴金丝绣的小帽，帽边插了一根长长的
翠绿羽毛，旖旎如画。\n");
        set("nickname", HIG"翠羽"HIY"黄衫"NOR);
        set("gender", "女性");
        set("class", "swordsman");
        set("age", 18);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 30);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("combat_exp", 600000);
  set("book_count",1);
        set_skill("literate", 120);
        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("hand", 120);
        set_skill("claw", 120);
        set_skill("yunlong-xinfa", 120);
        set_skill("yunlong-shengong", 120);
        set_skill("yunlong-jian", 120);
        set_skill("yunlong-shenfa", 120);
        set_skill("yunlong-shou", 120);
        set_skill("yunlong-zhua", 120);

        map_skill("dodge", "yunlong-shenfa");
        map_skill("force", "yunlong-shengong");
        map_skill("hand", "yunlong-shou");
        map_skill("parry", "yunlong-shou");
        map_skill("claw", "yunlong-zhua");
        map_skill("sword", "yunlong-jian");

        prepare_skill("hand","yunlong-shou");
        prepare_skill("claw","yunlong-zhua");
        set("env/wimpy", 60);
          set("inquiry", ([
      "书剑恩仇录" : "不错，《书剑恩仇录》的确在我这，不过你要先帮我找回《古兰经》。\n",
      "书剑" : "不错，《书剑恩仇录》的确在我这，不过你要先帮我找回《古兰经》。\n",
      "古兰经" : "这是我们的镇教之宝，可惜被人偷走，据说在关外。\n",
      "香香公主" : "她是我的小妹子。\n",
      "陈家洛" : "...\n",
     ]) );  

        setup();
        carry_object("/d/reborn/jinyong/obj/sj_cuiyu")->wear();
        carry_object("/d/reborn/jinyong/obj/sj_huangshan")->wear();
        carry_object("/d/reborn/jinyong/obj/sj_shortsword")->wield();
}

int accept_object(object who, object ob)
{
        object obj;
        who = this_player();

        if( base_name(ob) != "/d/reborn/jinyong/obj/gljing" )
                return 0;

        say("这就是我们的镇教之宝，您居然给了找了回来，太感激了。\n");
        command("wa");
        
        obj = new("/d/reborn/jinyong/obj/sjecl");

        obj->move(this_player());

        message_vision("霍青桐从怀里拿出一" + obj->query("unit") + obj->query("name") + "交给$N。\n", this_player());

        say("霍青桐说道：这是多年前一位故人留在我这里的书，今天送于大侠您。\n");
        who->delete_temp("sj3");
        call_out("do_destroy", 1, ob);
        return 1;
}

void do_destroy(object ob)
{
        destruct(ob);
}

