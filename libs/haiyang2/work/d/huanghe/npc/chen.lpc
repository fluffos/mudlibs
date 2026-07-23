// chen.c
inherit NPC;
#include <ansi.h>;
#include <skill.h>
#include <weapon.h>
#include <combat.h>
void create()
{
        set_name( "陈玄风" ,({ "chen xuanfeng", "chen" }));
        set("title", "黑风双煞");
        set("nickname", HIY"铜尸"NOR);
        set("gender", "男性");
        set("age", 35);
        set("long",
            "此人是黄药师的二弟子，他浓眉大眼，背厚膀宽，躯体甚是壮健，只是\n"
            "面色微微泛黄。\n");
        set("attitude", "aggressive");
        set("str", 27);
        set("int", 32);
        set("con", 35);
        set("max_qi",5500);
        set("max_jing",5000);
        set("neili", 5500);
        set("max_neili", 25500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 1500000);

        set_skill("claw", 180);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("dodge", 140);
        set_skill("jiuyin-baiguzhao", 280);
        set_skill("bibo-shengong", 280);
        set_skill("anying-fuxiang", 280);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("claw", "jiuyin-baiguzhao");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "claw.zhua" :),
                (: perform_action, "claw.cuijin" :),
                (: perform_action, "claw.zhua" :),
        }) );

        create_family("桃花岛", 2, "被逐弟子");
        set("inquiry", ([
           "铜尸":     "江湖上的人都这么叫我的，你怕不怕？哈哈哈哈。",
           "东邪":     "那是我师父的绰号。",
           "西毒":     "那是与家师齐名的高手之一，是个老毒物，住在白驼山。",
           "南帝":     "段王爷已出家当和尚去了，法名叫一灯。",
           "北丐":     "北丐统领中原的丐帮，势力颇为强大。",
           "洪七公":   "洪七公武功高强，而且教会郭靖那小儿降龙十八掌，可恨！",
           "黄蓉":     "她是我师父的独女，最是刁蛮任性。",
           "梅超风":   "她是我的师妹，也是我的内室。",
           "陈玄风":   "不就是我么？你是白痴啊？",
           "黄药师":   "他是我师父。"]) );
        setup();
        carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}

void kill_ob(object me)
{
	object ob = this_object();
	if (environment(ob)->query("short") == "石洞" && !objectp(present("mei chaofeng", environment(ob)))) {
		command("say 想抢我的九阴真经？没那么容易！");
		message_vision(HIY"陈玄风向你急攻数招，夺路向外跑去。"NOR, me);
	        ob->add_temp("apply/attack", 200);
	        ob->add_temp("apply/damage", 200);
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
	        ob->add_temp("apply/attack", -200);
		ob->add_temp("apply/damage", -200);
		command("out");
		this_object()->set_temp("target", me->query("id"));
                this_object()->move("/d/huanghe/shamo1");
	}
        ::kill_ob(me);
}

void die()
{
	object ob = this_object(), me, obj;
	if (!ob->query_temp("target")) {
	        call_out("do_die", 1, ob);
		return;
	}
	if (environment(ob)->query("short") != "沙漠"){
	        call_out("do_die", 1, ob);
		return;
	}
	me = ob->query_temp("last_damage_from");
	if (me->query("id") != ob->query_temp("target")) {
		ob->revive(1);
		command("say 好，居然还有" + me->name(1) + "帮你，哼！");
		message_vision(HIY"陈玄风见形势不好，转身逃了！\n"NOR, me);
		destruct(ob);
		return;
	}
	ob->delete_temp("target");
	if (me->query("jiuyin/full") || present("jiuyin xiajuan", me) || (!me->query("jiuyin/xia") && me->query("jiuyin/xia-failed") > 2)) {
	        call_out("do_die", 1, ob);
		return;
	}
	if (me->query("jiuyin/xia") && !present("jiuyin xiajuan", me)) {
		obj = new ("/clone/book/jiuyin-xia");
		obj->move(me);
		message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"拿到九阴真经下卷啦。\n"NOR, users());
	        call_out("do_die", 1, ob);
		return;
	}
	message_vision(HIW"$N隐隐看到尸体的腹部刻了点东西，\n"NOR, me);
	if (me->query("kar") > 40 && random(20) == 0) {
		if(present("bishou", me)) {
			message_vision(HIW"顺手抽出匕首割下一小块皮来，仔细一看，尽是九阴真经下卷！\n"NOR, me);
			obj = new ("/clone/book/jiuyin-xia");
			obj->move(me);
			message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"拿到九阴真经下卷啦。\n"NOR, users());
			me->delete("jiuyin/xia-failed");
			me->set("jiuyin/xia", 1);
		} else {
			message_vision(HIW"可惜$N没有带上匕首，只好暂时做罢。\n"NOR, me);
			me->add("jiuyin/xia-failed", 1);
		}
	} else {
		message_vision(HIW"可惜$N并没在意。\n"NOR, me);
		me->add("jiuyin/xia-failed", 1);
	}
	call_out("do_die", 1, ob);
	return;
}

void do_die(object ob)
{
        :: die();
}
