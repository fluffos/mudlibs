mapping hist = ([ ]);

do_sort (mixed a, mixed b)
{
  if (a > b)
    return 1;
  else if (a == b)
    return 0;
  else 
    return -1;
}

int
main (string str)
{
  string header;
  int *k;

  restore_object ("/data/misc/hist");

  if (!str || !THIS->query_security())
    {
      k = keys (hist);

      if (k)
        {
          k = sort_array (k, "do_sort");
          
          for (int i=0;i<sizeof(k);i++)
            {
              if (k[i] < time()-(60*60*48))
                continue;

              write (sprintf ("%s ^cy%s^c0:\n%s",
                ctime (k[i]), capitalize(hist[k[i]][0]),
                capitalize(wrap (hist[k[i]][1], THIS->query_columns()-4, 4))));
            }
          return 1;
        }
      else
        {
        write ("No changes since "+ctime(time()-(60*60*24))+".\n");
        }
/*
      write ("--\n");
      tail ("/CHANGES");
      write ("--\n");
      return 1;
        }*/
    }

  if (strlen(str) < 10)
    {
      write ("Too short line.\n");
      return 1;
    }
  else
    {
      header = ctime(time())[4..15] + " " + THIS->query("name") + ": ";
      if (strlen(str) < (78-strlen(header)))
        write_file ("/CHANGES", header + str + "\n");
      else {
        write_file ("/CHANGES", header + str[0..(78-strlen(header))] + "\n");
        write_file ("/CHANGES", wrap(repeat_string(" ", strlen(header)) + str[(79-strlen(header))..], 78, strlen(header)) + "\n");
        write_file ("/CHANGES", "\n");
      }
      rm ("/www/changes.html");
      write_file ("/www/changes.html", read_file("/data/html/header.html"));
   
      write_file ("/data/html/hist.html",
        "<dt><em>"+ctime(time())+"</em>:<strong> "
      + capitalize(THIS->query("name"))+"</strong>\n"
      + "<dd> "+str+" <p>\n");

      write_file ("/www/changes.html", read_file("/data/html/hist.html"));
      write_file ("/www/changes.html", read_file("/data/html/footer.html"));
      write ("CHANGES database and HTML pages updated. Thanks.\n");

      if (!hist)
        hist = ([ ]);

      hist[time()] = ({ THIS->query_name(), str });
      save_object ("/data/misc/hist");

      shout ("The world seems to be slightly different.\n");
    }

  return 1;
}

query_author ()
{
  return "namhas";
}

query_synopsis ()
{
  return "hist [message]";
}

query_help ()
{
  return "This command shows you the last changes made to the Majik. It "
       + "recommended that you read hist every time you log in to get " 
       + "some idea what new features are added in.";
}
