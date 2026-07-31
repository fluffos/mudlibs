#pragma save_binary
#include <dbase.h>
#include <login.h>
int prevent_learn(object me, string skill)
{
    int betrayer;
      if (me->query("family/family_name")!=this_object()->query("family/family_name")) return 1;
    if( betrayer = me->query("betrayer") )
    {
        if( me->query_skill(skill, 1) >= this_object()->query_skill(skill, 1) - betrayer * 20 ) {
            message_vision("$N神色间似乎对$n不是十分信任，也许是想起$p从前背叛师门的事情 ...。\n",
                this_object(), me );
            command("say 嗯 .... 师父能教你的都教了，其他的你自己练吧。");
            return 1;
        }
    }
    if( !me->is_apprentice_of(this_object())
    &&  (int)this_object()->query_skill(skill, 1) <= (int)me->query_skill(skill, 1) * 3 ) {
        command("hmm");
        command("pat " + me->query("id"));
        command("say 虽然你是我门下的弟子，可是并非我的嫡传弟子 ....");
        command("say 我只能教你这些粗浅的本门功夫，其他的还是去找你师父学吧。");
        return 1;
    }
    if (this_object()->query("jing")<50)
        command("exert regenerate");
    return 0;
}
