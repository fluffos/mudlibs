/*
 *  Cleans out player files that are out-of-date.
 *  Basically, the file can be wiped if the player is no longer around.
 *  BEFORE USE: make sure your cloned copy has your permissions on it,
 *  in other words, copy the file to your directory and then clone from
 *  there. That should allow you to clean your own files.
 */

inherit "obj/clean";


string name, lastime;
int level;
string *FAKERS;


id(str)
{
  return str == "pclean" || str == "cleaner";
}



short() { return "A pclean object"; }


long()
{
  write("Use this device to clean obselete player files.\n"+
        "Usage: pclean [-commit] <path>.\n");
}


get() { return 1; }
query_weight() { return 1; }
query_value() { return 0; }


init()
{
  if (this_player()->query_level() > 20)
  {
    add_action("main", "pclean");
  }
}


/* Determines whether a player exists or not.
   Input:  the real name of a player
   Output: -2  usage error
           -1  player banished
            0  player not found
            1  player active
            2  player inactive
            3  player is fake
 */
int playerExists(string str)
{
  level=0;
  name=0;
  lastime=0;

  if (!str)
  {
    /* Usage Error */
    return -2;
  }

  if (!restore_object("pfiles/"+extract(str,0,0)+"/"+lower_case(str)))
  {
     if (restore_object("players/inactive_saved/"+lower_case(str)))
     {
       return 2;
     }
     if (restore_object("banish/"+lower_case(str)))
     {
       if (file_size("/banish/"+lower_case(str)) < 25)
       {
         FAKERS = ({ "sagan", "shardak" });
         if(member_array(str,FAKERS) != -1)
         {
             return 3;
         }
       }
       /* Player Banished */
       return -1;
     }
  }

  if (!name)
  {
    /* No Such Player */
    return 0;
  }

  return 1;
}


string categorizePlayer(string str, int searchType)
{
  object bb;

  if (!str)
  {
    return "";
  }

  if (searchType == -1)
  {
    return "banished";
  }
  else if (searchType == 0)
  {
    return "non-existant";
  }
  else if (searchType == 1 || searchType == 2)
  {
    bb = find_player(str);
    if (bb)
    {
      return "logged on since: " + (string)bb->query_lastime();
    }
    else
    {
      return "last called at: " + lastime;
    }
  }
  else if (searchType == 3)
  {
    return "faker player";
  }

  return "";
}


status main(string str)
{
  string pname, path;
  string *files, *fileName, *resultArray, *sortedResults;
  int i, searchType, resultCount;
  status purge;
  purge=0;

  if (!str)
  {
    write("Usage: pclean [-commit] <path>.\n");
    return 1;
  }

  if (sscanf(str, "-commit %s", path))
  {
    write("\n[[[Non-existant and banished player files will be purged]]]\n");
    purge=1;
  }
  else
  {
    path=str;
  }

  if (file_size(path) != -2)
  {
    write("Path is not a directory.\n");
    return 1;
  }

  files = get_dir(path + "/*");
  resultArray = allocate(sizeof(files));
  resultCount = 0;

  for (i=0; i < sizeof(files); i++)
  {
    if (files[i] != "." && files[i] != "..")
    {
      fileName=explode(files[i], ".");
      if (sizeof(fileName) == 2)
      {
        /* make sure we're dealing with a <playerName>.o file */
        if (fileName[1]=="o")
        {
          pname = fileName[0];
          searchType = playerExists(pname);
          if (searchType == -1 || searchType == 0)
          {
            if (purge)
            {
              if (!rm(path + "/" + files[i]))
              {
                resultArray[resultCount] = "RM FAIL   (" + pad(level, 4) + ") " + pname + " ===> ";
              }
              else
              {
                resultArray[resultCount] = "REMOVED   (" + pad(level, 4) + ") " + pname + " ===> ";
              }
            }
            else
            {
                resultArray[resultCount] = "OBSELETE  (" + pad(level, 4) + ") " + pname + " ===> ";
            }
          }
          else
          {
            resultArray[resultCount] = "fine      (" + pad(level, 4) + ") " + pname + " .... ";
          }
          resultArray[resultCount] += categorizePlayer(pname, searchType);
          resultCount++;
        }
      }
    }
  }

  write("\nStatus    Lvl   Player\n");
  write("--------------------------------------\n");
  sortedResults = sort_array(resultArray, "sortFunction", this_object());
  for (i=0; i < sizeof(sortedResults); i++)
  {
    if (sortedResults[i])
    {
      write(sortedResults[i] + "\n");
    }
  }

  return 1;
}


int sortOrder(string arg)
{
  int order, pLevel;
  string tmp1, tmp2;

  order = 0;
  pLevel = 0;

  if (!arg)
  {
    return 0;
  }

  if (extract(arg, 0, 3) == "fine")
  {
    order = 0;
  }
  else if (extract(arg, 0, 7) == "OBSELETE" || extract(arg, 0, 7) == "REMOVED")
  {
    order = 200000;
  }
  else if (extract(arg, 0, 6) == "RM FAIL")
  {
    order = 400000;
  }

  if (sscanf(arg, "%s (%d%s", tmp1, pLevel, tmp2) == 3)
  {
    order -= pLevel;
  }
  
  return order;
}


status sortFunction(string arg1, string arg2)
{
  int order1, order2;

  order1 = sortOrder(arg1);
  order2 = sortOrder(arg2);

  if (order1 > order2)
  {
    return 1;
  }

  return 0;
}

