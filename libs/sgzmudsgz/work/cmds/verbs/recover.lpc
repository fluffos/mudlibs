// recover.c by fire on Jec 30 1997
// updated by tset on May 24, 1999

#include <mudlib.h>
#include <ansi.h>
inherit VERB_OB;
        
void do_recover()
{
        object who;
        int p_tmp;
        who=this_body();
        if(!wizardp(who))
        {
		write("你做不了这件事。\n");
                return;
        }
        p_tmp=this_body()->query_sg_max_hp();
        this_body()->set_cur_max_hp(p_tmp);
        this_body()->set_cur_hp(p_tmp);
        p_tmp=this_body()->query_sg_max_mp();
        this_body()->set_cur_max_mp(p_tmp);
        this_body()->set_cur_mp(p_tmp);
		this_body()->add_food(1000);
		this_body()->add_drink(1000);
        this_body()->simple_action(HIG+
                "$N运起天地神功；一瞬间，一切伤痛全化为无。\n"+NOR);
}
                 
void do_recover_str(string liv)
{
        object ob; 
        int p_tmp;
        if(!(wizardp(this_body()->query_userid())))
        {
		write("你做不了这件事。\n");
                return;
        }
        else
        {
                ob = present(liv, environment(this_body()));
                if (!ob) ob = find_body(liv);
                if (!ob) {
                        write("找不到此人。\n");
                        return;
                }
		if(!ob->is_living()) {
			write("物件好像是不知道伤痛的。\n");
			return;
		}
                p_tmp=ob->query_sg_max_hp();
                ob->set_cur_max_hp(p_tmp);
                ob->set_cur_hp(p_tmp);
                p_tmp=ob->query_sg_max_mp();
                ob->set_cur_max_mp(p_tmp);
                ob->set_cur_mp(p_tmp);
				ob->add_food(1000);
				ob->add_drink(1000);
                this_body()->simple_action(HIG+"$N运起天地神功；化解了"
                        +ob->query_name()+"的一切伤痛。\n"+NOR);
        }
}
        
mixed * query_verb_info()
{
    return ({ ({ "", "STR", }), ({  }) });
}
                        
