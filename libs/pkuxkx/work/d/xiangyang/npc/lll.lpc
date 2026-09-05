#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
        set_name(MAG"程灵素"NOR, ({
                "cheng lingsu",
                "cheng",
                }));
        set("long",
                "她是药王的高徒，妙手回春，有起死回生之神功。\n"
        );


        set("gender", "女性");
        set("attitude", "friendly");
        set("age",20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 150);
        set("max_neili", 150);
        set("combat_exp", 1000);
        set("score", 1000);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("strike", 30);
        set_skill("parry", 40);
        set_skill("literate", 100);
        set("inquiry", ([
                "救人"     : (: ask_me :),
                "治病"     : (: ask_me :),
                "治病救人"   : (: ask_me :)
        ]));

        setup();

//        carry_object("/d/shaolin/obj/changjian")->wield();
//        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}


void init()
{	
	object me, ob;

	me = this_object();

	::init();
	if( objectp(ob = present("lie hu", environment())) )
	{
		remove_call_out("repairing_1");
		call_out("repairing_1", 5, me, ob);
	}
}

int repairing_1(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

        command("say 哎呀，伤得这么重啊！我来看看。\n");
	
	remove_call_out("repairing_2");
	call_out("repairing_2", 2+random(3), me, ob);

	return 1;
}

int repairing_2(object me, object ob)
{      object mee=this_player();
	if ( !present(ob, environment()) ) return 1; 
                write(
"他的伤如果再早几天治，还是有救的。现在病已入骨，纵使扁雀重生，华佗再世，
怕也难了。不过还有一线希望：我早年听恩师说过，有一种奇药，采天地之精华，
集日月之灵气，有起死回生之神效，或许还救得他的性命。只是此药配方极其难得，
是以从古至今也未曾有人配得几颗，这位"+ RANK_D->query_respect(mee) + "如能采全,
当可成就功德一件，配置此药需要：\n"+
         HIY"千年灵芝、黑熊熊胆、新鲜麝香、白虎虎骨\n"NOR +
         "以"+HIG"上古玄冰"NOR+"做药引，方可配成啊！\n
"NOR);        

		command("follow none");

		message_vision(GRN "\n道果禅师气鼓鼓地走了。\n" NOR, me);
		me->move("/d/shaolin/guangchang3");

		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	

	return 1;
}
	
int repairing_3(object me, object ob)
{
	command("say 唔，原来如此，我来修修看吧！");
	message_vision(GRN "\n他接着从怀里掏出一大堆工具来，打开木人的身体，摆弄了几下。\n\n" NOR, me);

	remove_call_out("repairing_4");
	call_out("repairing_4", 3+random(3), me, ob);

	return 1;
}

int repairing_4(object me, object ob)
{
	if( random(2) == 0 ) 
	{		
		command("say 好，修好了！");
		ob->delete("damaged");
		ob->set("fight_times", 0);	
		message_vision(GRN "\n木人的身体吱吱地扭动了几下，恢复了正常站立的姿态。\n\n" NOR, me);
	}
	else 
		message_vision(GRN "\n道果禅师叹了口气，说道：看来不行，这木人损坏得太厉害了，没法子修了！\n" NOR, me);

	command("say 好，那我走了！");
	command("wave");
	command("follow none");

	message_vision(GRN "\n道果禅师走了出去。\n" NOR, me);
	me->move("/d/shaolin/guangchang3");

	remove_call_out("do_back");
	call_out("do_back", random(15), me);

	return 1;
}

int do_back(object me)
{
	me->move("/d/shaolin/twdian");
	return 1;
}

string ask_me()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "少林派")
		return RANK_D->query_respect(ob) + 
		"与本派素无来往，不知此话从何谈起？";

	command("say 木人打坏了是吧？ 好吧，我跟你去看看。");
	command("follow " + ob->query("id"));

	return "我们走罢！\n";
}