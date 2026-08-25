/* March 96, Andy@entropy.demon.co.uk
   Patch for preventing reload object on files it shouldn't be used on
   simply place......
          int query_prevent_reload_object() { return 1; }
   .... in said object
*/

void reload_object(object ob)
{
if(ob->query_prevent_reload_object())
  {
  log_file("DodgyReloads","File:"+file_name(ob) +
                " From:"+file_name(previous_object())+"\n");
  return ;
  }
efun::reload_object(ob);
}
