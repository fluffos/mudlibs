// pk_manager.c
// by mudring@SanJie.

void change_choose(object who);
int main()
{
object o;
if (find_player("xtq")) 
o=find_player("xtq");
change_choose(o);
}
void change_choose(object who)
{
    int i;
    string *sname;
    mapping skill_status;

    if (!userp(who))    
        return;
        
    who->set("combat_exp",who->query("combat_exp")*4/3);
    who->set("daoxing",who->query("daoxing")*4/3);

    if (mapp(skill_status = who->query_skills()))
    {
        skill_status = who->query_skills();
        sname = keys(skill_status);

        for (i = 0; i < sizeof(skill_status); i++)
             who->set_skill(sname[i], skill_status[sname[i]]*4/3);
    }
}
