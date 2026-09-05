int cmd_ok_edit(string str)
{
string str1, str2;
  object ob;
  if(!str) return 0;
 
  if(sscanf(str,"%s %s",str1,str2) < 2) return 0;
  ob = find_player(str1);
  if(!ob) return 0;
  ob->patch_ok_edit(str2);
  write("Ok.\n"); return 1;
}
