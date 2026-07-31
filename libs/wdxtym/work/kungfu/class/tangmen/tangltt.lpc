// tangltt

#include <ansi.h>
#include "tangmen.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER; 
inherit F_COAGENT;  

string ask_me();
mixed ask_th1();
mixed ask_th2();
mixed ask_th3(); 
mixed ask_th4(); 
mixed ask_ql(); 
mixed ask_by1(); 
mixed ask_by2(); 
mixed ask_wu(); 

void create()
{
        set_name("唐老太太", ({ "tang laotai", "tang" }));
        set("nickname", HIW "霹雳夫人" NOR);
        set("long", 
                "她就是唐门第二代掌门唐老太太，在她的经营下，\n"
                "唐门在江湖中声名更加显赫。\n"
                "她大约七十有余，一头银发，红光满面。\n");
	set("gender", "女性");
	set("age", 72);
        set("class", "tangmen");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 8000);
        set("max_jingli", 1500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("max_jing",2000);
        set("jiali", 100);
        set("combat_exp", 2400000);
        set("level", 55);
        set("shen",3000);
        set("score", 7000);

        set_skill("force", 280);
        set_skill("throwing", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("literate", 280);
        set_skill("hand", 280);
        set_skill("sword", 280);
        set_skill("boyun-suowu", 280);
        set_skill("biyun-xinfa", 280);
        set_skill("qiulin-shiye", 280);
        set_skill("wuzhan-mei", 280);
        set_skill("poison", 280);
        set_skill("medical", 280);
        set_skill("medical", 280);
        set_skill("tangmen-throwing", 208);
        set_skill("tangmen-poison", 280);
        set_skill("tangmen-medical", 280);        
        
        map_skill("force", "biyun-xinfa");
        map_skill("throwing", "tangmen-throwing");
        map_skill("dodge", "qiulin-shiye");
        map_skill("parry", "wuzhan-mei");
        map_skill("sword", "wuzhan-mei");
        map_skill("hand", "boyun-suowu");
        map_skill("poison", "tangmen-poison");
        map_skill("medical", "tangmen-medical");
        
        prepare_skill("hand", "boyun-suowu");
        
        create_family("唐门世家", 2, "掌门");
	set("inquiry", ([
                "大闹唐门" : (: ask_me :),	 
                "唐花"     : (: ask_th1 :),
                "心有千千结"     : (: ask_th2 :), 
                "散花天女"     : (: ask_th3 :),
                "七子钢镖"     : (: ask_th4 :), 
                "随风而舞"     : (: ask_ql :), 
                "云雾暗点"     : (: ask_by1 :), 
                "回梦"         : (: ask_by2 :), 
                "流花掠影"     : (: ask_wu :),       
	]));
	
        set_temp("apply/damage", 100);  
        set_temp("apply/unarmed_damage", 100);  
        set_temp("apply/armor", 200);          

        set("master_ob", 4);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/tangmen/obj/feidao")->wield();
        carry_object("/d/tangmen/obj/fhshi")->wield();
        carry_object("/d/tangmen/obj/tiejili")->wield();
        carry_object("/d/tangmen/obj/feidao")->wield();
        carry_object("/d/tangmen/obj/fhshi")->wield();
        carry_object("/d/tangmen/obj/tiejili")->wield();
        carry_object("/d/tangmen/obj/qinglianzi")->wield();
        carry_object("/d/tangmen/obj/qinglianzi")->wield();
        set_temp("handing", carry_object("/d/tangmen/obj/jili"));          
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))  
                return;
                        
        if ( (string)ob->query ("family/family_name") != "唐门世家" || 
             (int)ob->query ("combat_exp") < 600000) 
	{
        	command("say 你还是先拜唐缺为师，学些唐门的基本工夫吧！\n");
                return;
        }

        if ((int)ob->query_skill("biyun-xinfa", 1) < 150) 
        {
                command("say 唐门虽然以暗器为主，但还是要辅以内力。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在碧云心法上多下点功夫？");
                return;;
        }
        if ((int)ob->query("dex") < 30)
        {
                command("say “你的身法太差了，不要误了自己啊！”\n");
                return;    
        }
        if ((int)ob->query("int") < 25) {
                command("say 唐门历来注重弟子的文学修为。");
                command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
                command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
                return;
        }

        command("say 好吧，从今天起你就是我的关门弟子了。\n");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        object me;
        me = this_player();
        if (me->query_temp("marks/闹"))
        {
                command("say 你想帮唐方那个死丫头打探消息吗？看我不劈了你");
                command("hit " + me->query("id"));
                return "看来老太婆非得教训你一下不可。\n";
        }
        if (me->query_temp("marks/萧"))
        {
                command("angry " + this_player()->query("id"));
                command("say 难道你想像萧秋水一样来个大闹唐门吗？\n");
                command("heng " + this_player()->query("id"));
                command("say 唐方那个死丫头！\n");
                this_player()->set_temp("marks/闹", 1);
                me->delete_temp("marks/萧");
                return"萧秋水已被我关起来了！她别想再见到这个混小子了！\n";
        }
        else
        {       
                return "瓜娃子，你说啥子？老太婆听不懂哦！\n";
        }


}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "历练" :
        case "历炼" :
        case "锻炼" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;
        default:
                return 0;
        }
}

mixed ask_th1()
{
	object me;

	me = this_player();
	if (me->query("can_perform/tangmen-throwing/hua"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们唐家的人，打听我的武功想要干什么？";

	if (me->query_skill("tangmen-throwing", 1) < 180)
		return "就你这点本事？等你把唐门暗器练过180级再来找我吧！";

	tell_object(me, HIG "你学会了唐花。"NOR"\n");
	me->set("can_perform/tangmen-throwing/hua", 1);
	return 1;
}
mixed ask_th2()
{
	object me;

	me = this_player();
	if (me->query("can_perform/tangmen-throwing/qian"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们唐家的人，打听我的武功想要干什么？";

	if (me->query_skill("tangmen-throwing", 1) < 140)
		return "就你这点本事？等你把唐门暗器练过140级再来找我吧！";

	tell_object(me, HIG "你学会了心有千千结。"NOR"\n");
	me->set("can_perform/tangmen-throwing/qian", 1);
	return 1;
}
mixed ask_th3()
{
	object me;

	me = this_player();
	if (me->query("can_perform/tangmen-throwing/san"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们唐家的人，打听我的武功想要干什么？";

	if (me->query_skill("tangmen-throwing", 1) < 160)
		return "就你这点本事？等你把唐门暗器练过160级再来找我吧！";

	tell_object(me, HIG "你学会了散花天女。"NOR"\n");
	me->set("can_perform/tangmen-throwing/san", 1);
	return 1;
}
mixed ask_th4()
{
	object me;

	me = this_player();
	if (me->query("can_perform/tangmen-throwing/biao"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们唐家的人，打听我的武功想要干什么？";

	if (me->query_skill("tangmen-throwing", 1) < 120)
		return "就你这点本事？等你把唐门暗器练过120级再来找我吧！";

	tell_object(me, HIG "你学会了七子钢镖。"NOR"\n");
	me->set("can_perform/tangmen-throwing/biao", 1);
	return 1;
}
mixed ask_ql()
{
	object me;

	me = this_player();
	if (me->query("can_perform/qiulin-shiye/wu"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们唐家的人，打听我的武功想要干什么？";

	if (me->query_skill("qiulin-shiye", 1) < 100)
		return "就你这点本事？等你把秋林拾叶练过100级再来找我吧！";

	tell_object(me, HIG "你学会了随风而舞。"NOR"\n");
	me->set("can_perform/qiulin-shiye/wu", 1);
	return 1;
}
mixed ask_by1()
{
	object me;

	me = this_player();
	if (me->query("can_perform/boyun-suowu/dian"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们唐家的人，打听我的武功想要干什么？";

	if (me->query_skill("boyun-suowu", 1) < 120)
		return "就你这点本事？等你把拨云锁雾练过120级再来找我吧！";

	tell_object(me, HIG "你学会了云雾暗点。"NOR"\n");
	me->set("can_perform/boyun-suowu/dian", 1);
	return 1;
}
mixed ask_by2()
{
	object me;

	me = this_player();
	if (me->query("can_perform/boyun-suowu/meng"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们唐家的人，打听我的武功想要干什么？";

	if (me->query_skill("boyun-suowu", 1) < 160)
		return "就你这点本事？等你把拨云锁雾练过160级再来找我吧！";

	tell_object(me, HIG "你学会了回梦。"NOR"\n");
	me->set("can_perform/boyun-suowu/meng", 1);
	return 1;
}
mixed ask_wu()
{
	object me;

	me = this_player();
	if (me->query("can_perform/wuzhan-mei/liu"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们唐家的人，打听我的武功想要干什么？";

	if (me->query_skill("wuzhan-mei", 1) < 120)
		return "就你这点本事？等你把五展梅练过120级再来找我吧！";

	tell_object(me, HIG "你学会了回梦。"NOR"\n");
	me->set("can_perform/wuzhan-mei/liu", 1);
	return 1;
}

