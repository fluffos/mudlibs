// experimental
#include <mudlib.h>
#include <sanguo.h>

inherit CMD;

private void main(string arg)
{
    object who;
    string skill;
    int wuli, zhimou, meili, value;
    int i, size;
    if (!arg)
    {
        write("use skills\n");
        return;
    }
    if (sscanf(arg, "%d %d %d", wuli, zhimou, meili) != 3)
    {
      if (sscanf(arg, "%s %d", skill, value) != 2)
      {
        write("use mdskill wuli zhimou meili\n");
        return;
      }
    }
// only can set yourself
// only for wiz
    who = this_body();
    if (!(wizardp(who->query_userid())))
    {
        printf("only wiz can use");
        return;
    }
// set skills only
    if (!skill)
    {
        who->set_sg_skill("sk_wuli", wuli, 0);
        who->set_sg_skill("sk_zhimou", zhimou, 0);
        who->set_sg_skill("sk_meili", meili, 0);
        return;
    }
//    u = users();
            write("ind set skill\n");
        who->set_sg_skill(skill, value, 0);
        return;
}
