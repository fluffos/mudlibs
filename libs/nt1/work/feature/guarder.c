// guarder.c

#include <ansi.h>

int is_guarder() { return 1; }

int permit_pass(object ob, string dir)
{
        object *inv;
        string fam_name;
        string my_fam;
        string born_fam;
        string msg;
        int i;

        if (! living(this_object()))
                return 1;

        notify_fail("看来" + this_object()->name() + "不打算让你过去。\n");
        fam_name = ob->query("family/family_name");
        my_fam   = (string) this_object()->query("family/family_name");
        born_fam = (string) ob->query("born_family");
        if (born_fam == my_fam && fam_name && fam_name != my_fam)
        {
	        if (stringp(msg = this_object()->query("guarder/refuse_home")))
	                message_vision(msg + "\n", this_object(), ob);
                else
                        message_vision("$N冷冷的看了看$n，道：你既然已经入了" +
                                       fam_name + "，还来我们" + my_fam +
                                       "干什么？\n", this_object(), ob);
                return 0;
        }

        if (my_fam != fam_name && my_fam != born_fam)
        {
	        if (stringp(msg = this_object()->query("guarder/refuse_other")))
	                message_vision(msg + "\n", this_object(), ob);
	        else
                        message_vision("$N伸手拦住$n，道：对不起，不是我们" + my_fam +
                                       "人不得入内！\n", this_object(), ob);
                return 0;
        }

        inv = deep_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
        {
                if (! playerp(inv[i])) continue;
                if ((string) inv[i]->query("family/family_name") != fam_name)
                {
	                if (stringp(msg = this_object()->query("guarder/refuse_carry")))
	                        message_vision(msg + "\n", this_object(), ob);
	                else
                                message_vision("$N对$n喝道：你背的是谁？还不快快放下！\n",
                                               this_object(), ob);
                        return 0;
                }
        }

        return 1;
}

void kill_enemy(object ob)
{
        mixed result;

        mapping *co;
        string startroom;
        object room;
        object coagent;
        object me;
        int i;
        int flag;

        me = this_object();
        if ((int)ob->query("combat_exp") < (int)me->query("combat_exp") / 2)
                return;

        if (!pointerp(co = me->query("coagents")))
                return;

        if (sizeof(co) < 1)
                return;

        if (base_name(environment(me)) != (string)me->query("startroom"))
                return;

        message_vision(random(2) ? HIW "\n$N大声喊道：大家快来帮忙啊！\n\n" NOR :
                                   HIW "\n$N喝道：不好！有人挑上门来了！\n\n" NOR, me);

        if (me->is_master() && me->is_killing(ob->query("id"))) 
                me->master_accept_kill(ob); 

        flag = 0;
        for (i = 0; i < sizeof(co); i++)
        {
                if (! mapp(co[i])) continue;

                startroom = co[i]["startroom"];
                if (! objectp(room = find_object(startroom)))
                {
                        result = catch(room = load_object(startroom));
                        if (! objectp(room))
                        {
                                if (wizardp(this_object()))
                                        write(sprintf("Error to load object:%s\nCatch message:%s\n\n",
                                              startroom, result));
                                continue;
                        }
                }

                if (! objectp(coagent = present(co[i]["id"], room)) &&
                    ! objectp(coagent = present(co[i]["id"], environment())) ||
                    ! coagent->is_coagent() ||
                    coagent == this_object())
                        continue;

                flag += (int)coagent->start_help(environment(), me, ob);
        }

        if (! flag)
                message_vision("结果没有一个人出来 :)\n", me);
}

int check_enemy(object ob, string type)
{
        mapping myfam;
        object me;

        me = this_object();
        myfam = ob->query("family");
        if (! mapp(myfam) || ! myfam ||
                myfam["family_name"] != me->query("family/family_name"))
        {
                if (type == "fight")
                {
                        message_vision("$N对$n摇摇头道：我现在没空。\n\n", me, ob);
                        return 0;
                } else
                {
                        message_vision("$N大喝道，好你个" + RANK_D->query_rude(ob) +
                                       "，活得不耐烦了！来这里撒野？\n", me, ob);
                        me->kill_ob(ob);
                }
        } else
        switch (type)
        {
        case "hit":
        case "kill":
                message_vision("$N两眼一瞪，喝道：" + ob->query("name") +
                               "，你是要造反吗？\n", me, ob);
                me->kill_ob(ob);
                break;

        case "fight":
		if (ob->is_apprentice_of(me))
			message_vision("$N一瞪$n，怒道：你给我好好练功去！\n", me, ob);
		else
                	message_vision("$N对$n摇摇头道：找你的师傅比划去。\n\n", me, ob);
                return 0;
        }

        return 1;
}
