void disp_object(object ob);
int main(string str)
{
    object ob;
    if(!str)
    {
	write("Disp what?\n");
	return 1;
    }

    if (str == "here")
      ob = environment(THIS);
    else if (str == "me")
      ob = THIS;
    else
      {
    ob=(find_player(str) || find_living(str) || find_object(str));
    if(!ob)
	ob=present(str, environment(this_player()));
    if(!ob)
    {
	write("Could not find such thing.\n");
	return 1;
    }
     }
    disp_object(ob);
    return 1;
}

void disp_object(object ob)
{
    object *all;
    string buf="";
    string sh;

    sh = ob->query_short();

    if (!sh || sh == "")
      sh = "<invisible>";

    buf += sprintf("%-78s\n",
             sh[0..77]);

    buf += sprintf("%-78s\n",
             "OBJ("+file_name(ob)+")"[0..77]);

    if (ENV(ob))
      buf += "ENV("+file_name(ENV(ob))+")\n";
    else
      buf += "NO ENVIRONMENT\n";

    if (ENV(ob))
      all = all_inventory(ENV(ob));

    if (ob && all)
      all -= ({ all[member_array(ob, all)] });

    if (sizeof(all)>0)
      {
        buf += "\nSEES:\n";

        for (int i=0;i<sizeof(all);i++)
          {
          sh = all[i]->query_short();

          if (!sh || sh == "")
            sh = "<invisible>";

          sh = replace_string (sh, "\n", "");
          sh = replace_string (sh, "\t", "");
          sh = replace_string (sh, "\r", "");

          sh = sh[0..36];

          buf += sprintf ("%2d %-37s %-37s\n",
                   i+1, "OBJ("+file_name(all[i])+")"[0..36], sh);
          }
      }

    all = all_inventory(ob);

    if (sizeof(all)>0)
      {
        buf += "\nCONTAINS:\n";

        for (int i=0;i<sizeof(all);i++) {
          sh = all[i]->query_short();

          if (!sh || sh == "")
            sh = "<invisible>";
       
          sh = replace_string (sh, "\n", "");
          sh = replace_string (sh, "\t", "");
          sh = replace_string (sh, "\r", "");

          sh = sh[0..36];

          buf += sprintf ("%2d %-37s %-37s\n",
                   i+1, "OBJ("+file_name(all[i])[0..36]+")", sh);
        }
      }

  message ("0", buf, THIS);
}
