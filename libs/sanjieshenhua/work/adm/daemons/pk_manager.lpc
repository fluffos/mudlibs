// pk_manager.c
// by mudring@SanJie.

void change_choose(object who)
{
    int i;
    string *sname;
    mapping skill_status;

    if (!userp(who))    
        return;

    log_file("users/CHANGE_CHOOSE", sprintf("%s-%s exp %d dx %d change choose lost 1/4 data\n",
              who->get_name(), who->get_id(), who->get_exp(), who->get_dx()));
        
    who->set("combat_exp", who->get_exp() / 4 * 3);
    who->set("daoxing", who->get_dx()/4*3);

    if (mapp(skill_status = who->query_skills()))
    {
        skill_status = who->query_skills();
        sname = keys(skill_status);

        for (i = 0; i < sizeof(skill_status); i++)
             who->set_skill(sname[i], skill_status[sname[i]]*3/4);
    }
}
