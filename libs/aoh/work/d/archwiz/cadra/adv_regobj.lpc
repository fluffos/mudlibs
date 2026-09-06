/*
* Register of all adventurers-guilds
*
* 14jun94 [t]	Creation
*
* [t] Thragor
*/

#define SAVEFILE "/d/archwiz/common/log/adv_guilds"

string *regarr;

void create()
{
 if (is_clone(this_object()))
 {
  destruct(this_object());
  return;
 }
 regarr = ({});
 seteuid(getuid());
 restore_object(SAVEFILE);
 regarr = order_alist(regarr)[0];
}

void register(mixed ob)
{
 string name;
 if (stringp(ob)) name = ob;
 else name = blueprint(ob);
 if (assoc(name,regarr)==-1)
 {
  regarr = order_alist(regarr+({name}))[0];
  save_object(SAVEFILE);
 }
}

void remove_entry(mixed ob)
{
 string name;

 if (stringp(ob)) name = ob;
 else name = blueprint(ob);
 regarr = order_alist(regarr-({name}))[0];
 save_object(SAVEFILE);
}

string *query_reg_array() { return regarr+({}); }
