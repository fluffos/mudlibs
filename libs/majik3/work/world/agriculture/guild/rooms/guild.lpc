/*
 * Inheritable Guild Object
 * Coders : Namhas, Madrid
 *
 * Recoded : Dranil
 *
 * Check out help-file in: /open/dranil/guild.txt
 *
 */

#define MORE_OB "/obj/more"
#define COST_TUNE 2

inherit ROOM;

string guild;
string guild_desc;
string guildmaster;

string *titles = ({});

mapping avail_skills = ([]);
mapping req_skills = ([]);

int hidden_info;

string train_message;
mapping train_message_skills=([]);
string custom_advance;

int query_skill_max(string, int);
int query_skill_req(string, int);
string query_skill_train_msg(string);
string query_advance_msg();
string query_skill_rank(int);

create_room()
{
    THOB->create_guild();
}

init ()
{
    ::init();
    THOB->init_guild();
}


// functions to be used with add_action

do_join()
{
    if(THIS->query_guild_level(guild))
    {
        write("You are already a member.\n");
        return 1;
    }

    THIS->add_guild(guild);
    THIS->set_guild_title(guild, titles[0]);
    write(query_advance_msg());
    return 1;
}

int
do_advance()
{
    string foo, bar;
    int my_level;

    my_level=THIS->query_guild_level(guild);

    if(!my_level)
    {
        write("You are not a member of the guild.\n");
        return 1;
    }

    if(my_level == sizeof(titles))
    {
        write("You have reached the last level of the guild.\n");
        return 1;
    }

    for (int i=0; i < sizeof(req_skills); i++)
    {
        foo = keys(req_skills)[i];
        bar = replace_string(foo," ","_");
        if(THIS->query_skill_chance(bar) < query_skill_req(foo, my_level+1))
        {
            write("You dont have the requirments to advance.\n");
            return 1;
        }
    }


    THIS->set_guild_level(guild, my_level+1);
    THIS->set_guild_title(guild, titles[my_level]);
    write(query_advance_msg());
    return 1;

}

do_train(string what)
{
    string what_now;
    int my_level, amount, j;
    object gm;

    my_level = THIS->query_guild_level(guild);
    if(my_level == 0)
    {
        write("You are not a member of the guild, you must join first.\n");
        return 1;
    }
    if(!what || what=="")
    {
        show_train();
        return 1;
    }

    if(query_skill_max(what) < 0)
    {
        write("You cannot train that skill.\n");
        return 1;
    }

    what_now = replace_string(what," ","_");
    if(THIS->query_skill_base(what_now) >= query_skill_max(what,my_level))
    {
        write("You may not advance that skill any further on this level "+
          "of the guild.\n");
        return 1;
    }
    j = THIS->add_skill(what_now);
    if(j == -2) {
        write("Sorry but that skill is not yet implemented.\n");
        return 1;
    }

    gm=present(guildmaster);
    if (!gm)
    {
        write("But the guildmaster is not here!\n");
        return 1;
    }
    amount=THIS->query_advance_exp(what_now) + 
      THIS->query_skill_exp(what_now);

    if(!THIS->pay(gm, amount * COST_TUNE, 0))
    {
        write("But you don't have enough money!\n");
        return 1;
    }    

    THIS->add_skill_exp(what_now, amount/2 + random(amount/2) );
    write(query_skill_train_msg(what) );
    return 1;
}

do_info ()
{
    object more_ob = clone_object(MORE_OB);
    string buf = "";
    string buf2;
    string *k;
    int max_level;

    if (!hidden_info || THIS->query_guild_level(guild) == sizeof(titles))
        max_level = sizeof(titles);
    else
        max_level = THIS->query_guild_level(guild) + 1;

    buf += "Name: ^c1"+guild+"^c0\n\n";
    buf +=wrap( guild_desc +"\n\n");
    for (int i=0; i<max_level; i++)
    {
        buf += sprintf ("^c1%s^c0:\n", capitalize(titles[i]) );
        buf2 = "";

        k=keys(req_skills);
        for (int j=0;j<sizeof(k);j++)
        {
            if(req_skills[k[j]][i]>0)
                buf2 += sprintf ("    %-20s %-15s\n",capitalize(k[j]),query_skill_rank(req_skills[k[j]][i]));
        }
        if (buf2 != "")
        {
            if(!i)
                buf += "  Joining requirements:\n";
            else
                buf += "  Required skills:\n";
            buf += buf2;
            buf2 = "";
        }


        k=keys(avail_skills);
        for (int j=0;j<sizeof(k);j++)
        {
            if(avail_skills[k[j]][i]>0)
                buf2 += sprintf ("    %-20s %-15s\n",capitalize(k[j]),query_skill_rank(avail_skills[k[j]][i]));
        }
        if (buf2 != "")
        {
            buf += "  Allows training of the following skills:\n";
            buf += buf2;
        }
    }

    if(max_level != sizeof(titles) && max_level != THIS->query_guild_level(guild) )
        buf += "\nThe guild-information is restricted. To see "
        + "information about next levels, you have to advance a level.\n";

    write_file("/data/misc/info.txt",buf,1);
    more_ob->more("/data/misc/info.txt");
    rm("/data/misc/info.txt");
    return 1;
}

// Functions for setting up the guild

string
set_guild (string str)
{
    return guild = str;
}

string
set_guild_desc(string str)
{
    return guild_desc=str;
}

string*
set_titles(string *str)
{
    titles = ({});
    return titles = str;
}

int set_hidden_info()
{
    return hidden_info = 1;
}


string
set_guildmaster(string str)
{
    return guildmaster=str;
}

int *
add_avail_skill (string skill, int *percents)
{
    return avail_skills[skill] = percents;
}

int *
add_req_skill (string skill, int *percents)
{
    return req_skills[skill] = percents;
}

string
set_default_train_msg(string str)
{
    return train_message=str;
}


string
set_skill_train_msg(string skill, string message)
{
    return train_message_skills[skill] = message;
}

string
set_custom_advance_msg(string str)
{
    return custom_advance = str;
}


// Miscellaneuos functions used by other functions

int
show_train()
{
    string *skills;
    mapping skillz=([]);
    int my_level;
    string skilli;
    int prossa;

    my_level=THIS->query_guild_level(guild);

    if(!my_level)
    {
        write("You are not a member of the guild.\n");
        return 1;
    }

    skills=keys(avail_skills);
    for(int i=0;i<sizeof(skills);i++)
    {
        for(int j=0;j<my_level;j++)
        {
            skilli=skills[i];
            prossa=avail_skills[skills[i]][j];
            if (member_array(skilli,keys(skillz))==-1 || skillz[skilli]<prossa)
                skillz[skilli]=prossa;
        }
    }
    skills=sort_array(keys(skillz),0);
    message("0","Available skills on this guild-level:\n",THIS);
    for (int i=0; i<sizeof(skillz);i++)
    {
        skilli= skills[i];
        prossa= skillz[skilli];
        message("0",sprintf("%-20s %15s\n", capitalize(skilli), query_skill_rank(prossa)), THIS);
    }

    return 1;
}

int
query_skill_max(string skill, int level)
{
    int prossa;
    if (member_array(skill,keys(avail_skills))==-1)
        return -1;

    for(int i=0;i<level;i++)
    {
        if (prossa<avail_skills[skill][i])
            prossa = avail_skills[skill][i];
    }
    return prossa;
}

int
query_skill_req(string skill, int level)
{
    int prossa=-1;

    for(int i=0;i<level;i++)
    {
        if (prossa < req_skills[skill][i])
            prossa = req_skills[skill][i];
    }
    return prossa;
}

string
query_skill_train_msg(string skill)
{
    if (member_array(skill, keys(train_message_skills)) >= 0)
    {
        return train_message_skills[skill];
    }
    else if (sizeof(train_message) > 0)
    {
        return replace_string(train_message, "[skill_name]",capitalize(skill) );
    }

    return "You work hard with '" + capitalize(skill)
    + "' and feel very good after the training.\n";
}

string
query_advance_msg()
{
    string buf="";

    if (THIS->query_guild_level(guild) == 1)
        buf = "You join the guild.\n";

    if (sizeof(custom_advance) > 0)
    {
        buf+=replace_string(custom_advance, "[title]",
          capitalize(titles[THIS->query_guild_level(guild)-1]) );
    }
    else
    {
        buf+="You are now "+
          capitalize(titles[THIS->query_guild_level(guild)-1]) + ".\n";
    }
    return buf;
}

string query_skill_rank(int chance)
{
    switch (chance)
    {
    case 0:
        return "non-existent";
    case 1..6:
        return "hopeless";
    case 7..13:
        return "pathetic";
    case 14..20:
        return "terrible";
    case 21..27:
        return "poor";
    case 28..34:
        return "incompetent";
    case 35..41:
        return "mediocre";
    case 42..48:
        return "fair";
    case 49..55:
        return "good";
    case 56..62:
        return "competent";
    case 63..69:
        return "excellent";
    case 70..76:
        return "great";
    case 77..83:
        return "superb";
    case 84..90:
        return "excuisite";
    case 91..97:
        return "awesome";
    default:
        return "legendary";
    }
}


