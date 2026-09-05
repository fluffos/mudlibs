#include <security.h>

#define SAVEFILE "obj/wiz/jobs/jobs"

string *job_titles;
string *job_descriptions;

string *p_names;
mixed *p_titles;

void reset(int x)
{
  if(x) return;
  
  if(!restore_object(SAVEFILE))
  {
    job_titles=({});
    job_descriptions=({});
    p_names=({});
    p_titles=({});
  }
}

void save_me()
{
  save_object(SAVEFILE);
}

int query_index(string nm)
{
  return member_array(nm,p_names);
}

int query_name(string nm)
{
  return query_index(nm) > -1;
}

void add_job_title(string t, string d)
{
  if(!query_ip_name(this_player()) ||
     (int)this_player()->query_level() < ELDER)
  {
    return;
  }
  if(member_array(t, job_titles) == -1)
  {
    job_titles += ({ t });
    job_descriptions += ({ d });
    save_me();
  }
}

void delete_job_title(string t)
{
  int i;
  
  if(!query_ip_name(this_player()) ||
     (int)this_player()->query_level() < ELDER)
  {
    return;
  }
  if((i=member_array(t, job_titles)) > -1)
  {
    job_titles -= ({ t });
    job_descriptions -= ({ job_descriptions[i] });
    save_me();
  }
}

void change_job_description(string t, string d)
{
  int i;
  if((i=member_array(t, job_titles)) > -1)
  {
    job_descriptions[i] = d;
    save_me();
  }
}  

int valid_job_title(string t)
{
  return member_array(t, job_titles) > -1;
}

string * query_job_titles()
{
  return job_titles;
}

string * query_p_names()
{
  return p_names;
}

string * query_p_titles()
{
  return p_titles;
}

string query_description(string t)
{
  int i;
  if((i = member_array(t, job_titles)) > -1)
  {
    return job_descriptions[i];
  }
}

mixed query_titles(string nm)
{
  int i;
  
  if((i = query_index(nm)) > -1)
  {
    return p_titles[i];
  }
}

int add_title(string nm, string t)
{
  int i;
  
  if(!query_ip_name(this_player()) ||
     (int)this_player()->query_level() < ELDER)
  {
    return 0;
  }
  
  if(!valid_job_title(t))
  {
    return 0;
  }
  
  if((i=query_index(nm)) == -1)
  {
    p_names  += ({ nm });
    p_titles += ({ ({ t }) });
  }
  else
  {
    p_titles[i] += ({ t });
  }
  
  save_me();
  return 1;
}

int delete_title(string nm, string t)
{
  int i;
  
  if(!query_ip_name(this_player()) ||
     (int)this_player()->query_level() < ELDER)
  {
    return 0;
  }
  
  if((i=query_index(nm)) > -1)
  {
    p_names -= ({ nm });
    p_titles = a_delete(i, p_titles);
    save_me();
    return 1;
  }
}

int query_prevent_shadow()
{
  return 1;
}