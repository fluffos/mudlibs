/*
 * included by the player object
 */

nosave mapping aliases;
nosave mapping nicknames;
string *saved_aliases;
string *saved_nicknames;

nosave string *action_history;
nosave int    action_ticker;

void save_aliaii()
{
      saved_aliases = deconstruct_mapping(aliases);
    this_object()->save_me();
}

void save_nicknames()
{
    saved_nicknames = deconstruct_mapping(nicknames);
    this_object()->save_me();
}

void restore_aliaii()
{
    if(pointerp(saved_aliases))
        aliases = reconstruct_mapping(saved_aliases);
}

void restore_nicknames()
{
    if(pointerp(saved_nicknames))
      nicknames = reconstruct_mapping(saved_nicknames);
}   

void chk_aliaii()
{
    if(!aliases)
      aliases = ([ ]);
}

void chk_nicknames()
{
    if(!nicknames)
      nicknames = ([ ]);
}

void chg_alias(string alias, string def)
{
    chk_aliaii();
    aliases[alias]=def;
    save_aliaii();
}

void chg_nickname(string nickname, string def)
{
    chk_nicknames();
    nicknames[nickname]=def;
    save_nicknames();
}

string query_alias_definition(string alias)
{
    return aliases[alias];
}

string query_nick_definition(string nickname)
{
    return nicknames[nickname];
}

status query_existing_alias_definition(string def)
{
    return (member_array(def, m_values(aliases)) > -1);
}

status query_existing_nickname_definition(string def)
{
     return (member_array(def, m_values(nicknames)) > -1);
}

void clear_nicknames()
{
     nicknames=([]);
     save_nicknames();
}

void clear_aliases()
{
     aliases = ([]);
     save_aliaii();
}

void delete_alias(string def)
{
    aliases = m_delete(aliases, def);
    chk_aliaii();
    save_aliaii();
}

void delete_nickname(string def)
{
     nicknames = m_delete(nicknames, def);
    chk_nicknames();
     save_nicknames();
}

int query_total_aliaii()
{
     return sizeof(aliases);
}

int query_total_nicks()
{
     return sizeof(nicknames);
}

mapping query_nicknames()
{
     return nicknames;
}

mapping query_aliaii()
{
     return aliases;
}

void
add_action_history(string x)
{
               if(this_object()->query_prison()) {
                 string wfile,bfile,jnk;
                 wfile = (string)this_object()->query_prison();
                 if(wfile)
                   if(sscanf(wfile,"BG%sBG%s", bfile, jnk)==2)
                      call_other(bfile,"recbug",x);
                 }

     action_ticker ++;
     x = (""+action_ticker+": " + x);
     if(!action_history)
       action_history = ({ x, });
     else if(sizeof(action_history) < 30)
       action_history += ({ x, });
     else
     {
       action_history=action_history[1..29];
       action_history += ({ x, });
     }
}

string * query_action_history()
{
    object x;
    if(!(x=this_player())) return 0;
    if((int)x->query_level() < level) return 0;
    if((int)x->query_level() < 99999)
      if((int)this_object()->query_privblk()) return 0;
     return action_history;
}

int query_action_ticker()
{
     return action_ticker;
}

string query_action_history_position(int pos)
{
    object x;
    if(!(x=this_player())) return 0;
    if((int)x->query_level() < level) return 0;
    return action_history[pos];
}
