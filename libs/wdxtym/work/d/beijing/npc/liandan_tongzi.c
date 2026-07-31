// liandan_tongzi.c

#include <ansi.h>

inherit NPC;

mixed ask_caiyao();

void create()
{
	set_name("小童", ({"xiao tong", "xiao", "tong"}));
	set("gender", "男性");
	set("age", 12);
	set("long",
		"这是炼丹房中的掌管药材的童子。他年纪不大，但看起来显得少年老成。\n");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 21);
	set("int", 22);
	set("con", 23);
	set("dex", 22);
	set("qi", 600);
	set("max_qi", 600);
	set("jing", 400);
	set("max_jing", 400);
	set("neili", 1200);
	set("max_neili", 1200);;

	set("combat_exp", 300000);

	set("inquiry", ([
		"采药" : (: ask_caiyao :),
	]) );
	set("caiyao", 12);

	setup();
}

mixed ask_caiyao()
{
        int k;
	object me = this_player();

	switch (me->query_temp("caiyao"))
	{
	case 1:
		return "叫你去采药，还呆在这干嘛！";

	case 2:
		return "药采来了？还不快给我！";
	}

	switch (me->query_temp("liandan"))
	{
	case 1:
		// 已经打听过了练丹的消息了
		break;

	case 2:
		return "药材已经准备好，可以去了。";

	case 3:
		return "你不是在里面炼药吗？怎么出来了。";

	case 4:
		return "还是先去复命吧。";

	default:
		return "你又不炼药，要药材干什么？";
	}

	message_vision(CYN "小童对$N" CYN "说道：好吧，那你去城西的林子里挖几样新鲜的草药来。"NOR"\n", me);
	me->set_temp("caiyao", 1);
	add("caiyao", -1);
	if(objectp(present("cao yao",me))) {

            call_out("do_lian1", 5, me);
           }
      else {
            me->move("/d/beijing/ximenwai");
            tell_object(me,ZJFORCECMD("n")+ZJFORCECMD("cai yao"));
           }
/*
k=random(8);
if (k==0) tell_object(me,ZJFORCECMD("s"));
else if (k==1) tell_object(me,ZJFORCECMD("s")+ZJFORCECMD("w"));
else if (k==2) tell_object(me,ZJFORCECMD("s")+ZJFORCECMD("s"));
else if (k==3) tell_object(me,ZJFORCECMD("s")+ZJFORCECMD("e"));
else if (k==4) tell_object(me,ZJFORCECMD("n"));
else if (k==5) tell_object(me,ZJFORCECMD("n")+ZJFORCECMD("w"));
else if (k==6) tell_object(me,ZJFORCECMD("n")+ZJFORCECMD("n"));
else if (k==7) tell_object(me,ZJFORCECMD("n")+ZJFORCECMD("e"));
tell_object(me,ZJFORCECMD("cai yao"));
*/
	return 1;
}

int accept_object(object me, object ob)
{
	int exp,pot;

	if (me->query_temp("caiyao") < 1)
		command("say 我什么时候叫你拿这个给我的？");
	else
	if (me->query_temp("caiyao") == 1)
		command("say 是谁帮你找的东西来敷衍我，别以为我小就好骗。");
	else
	if (ob->query("id") != "cao yao")
		command("say 你欺我小啊？拿这种东西骗我。");
	else
	{
		command("say 好吧，让我来给你加工。"NOR"\n");
		destruct(ob);
	      call_out("do_lian3", 5, me);
            return 1;
	}
}

void do_lian1(object me)
{
	if (! objectp(me))
		return;
            write("你翻了翻口袋，正好发现有几株不知名草药。"NOR"\n");
		//command("say 加工好了，现在你可以去丹房炼丹了。");
		me->set_temp("caiyao", 2);

            tell_object(me,ZJFORCECMD("give 1 cao yao to xiao tong"));

}
void do_lian3(object me)
{
	if (! objectp(me))
		return;

		command("say 草药已经加工好了，现在你可以去丹房炼丹了。");
		me->delete_temp("caiyao");
		me->set_temp("liandan", 2);

            tell_object(me,ZJFORCECMD("n")+ZJFORCECMD("n")+ZJFORCECMD("liandan"));

}
