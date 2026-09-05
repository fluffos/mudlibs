inherit "/obj/clean";

void reset(status x)
{
  if(x) return;
  set_no_clean(1);
}

void set_root_dir(string x);
string query_root_dir();
string query_dir(string type);
status query_prevent_shadow();
string * query_guild_wizards();
status query_guild_wizard(string name);
status valid_access(object po, object tp);
status add_guild_wizard(string gw);
status delete_guild_wizard(string gw);

int query_prevent_shadow() { return 1; }
object load_me() { return this_object(); }
