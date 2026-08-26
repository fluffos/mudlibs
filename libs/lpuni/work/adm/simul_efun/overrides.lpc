//overrides.c

//Tacitus @ LPUniversity
//08-APR-05
//Simul-efuns

//Last edited on December 21st, 2005 by Tacitus

int exec( object to, object from )
{
     if(isMember(query_privs(previous_object()), "admin")) return efun::exec(to, from);
     else return 0;    
}

void destruct(object ob)
{
     ob->remove();
     if(ob) efun::destruct(ob);
}

void shutdown( int how )
{
     if(file_name(previous_object()) == "/adm/daemons/shutdown_d") efun::shutdown(how);
}

void set_privs(object ob, string privs)
{
     string name;
     
     if(isMember(query_privs(previous_object()), "admin") || ob = master()) efun::set_privs(ob, privs);
     sscanf(file_name(ob), "/home/%*s/%s/%*s", name);
     if(name == privs) efun::set_privs(ob, privs);
}

 