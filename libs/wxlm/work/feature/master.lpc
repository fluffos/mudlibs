// master.c

#include <dbase.h>

int can_learn_from() { return 1; }

int prevent_learn(object me, string skill)
{
	mapping fam;

	if (! me->is_apprentice_of(this_object()) &&
	    mapp(fam = me->query("family")) &&
	    fam["family_name"] == query("family/family_name"))
	{
		command("say 虽然你是我门下的弟子，可是并非我的嫡传弟"
			"子... 还是去找你师父学吧。");
		return 1;
	}

	return 0;
}

void attempt_detach(object me)
{
	if (! me->is_apprentice_of(this_object()))
	{
		command("say 边去，找你师傅。");
		return;
	}

	command("sigh");
	command("say 走吧走吧！你走吧！把你学到的武功留下！");

	me->skill_expell_penalty();
	me->unconcious();

	message_vision("$N将手掌粘在$n的背后，喃喃自语，"
		       "不知道在说些什么。\n", this_object(), me);
	me->add("detach/" + me->query("family/family_name"), 1);
	me->delete("family");
	me->set("title", "普通百姓");
}

