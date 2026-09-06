/**
 **  The Help Keywords Database
 **
 **  v. 0.8 [tune] 05-Jun-97  -  creation
 **     0.9 [tune] 06-jun-97  -  small change to automatically
 **                              update the keywords mapping,
 **                              tiny bug fix
 **
 **  This is a database to manage cross-referencing help keywords -
 **  multiple keywords can now point to a single help file.
 **  The keywords and file paths are maintained in a separate file,
 **  KEYWORDS_FILE.
 **
 **  If you change this file, be sure to first xload then call
 **  update_server(). If you update the keywords file, no need to
 **  manually call update_server() now.
 **
 **  Theoretically, this could be extended for managing other kinds
 **  of help files, too. Let me know if you're interested.
 **/
 
#include <daemons.h>

#define KEYWORDS_FILE     DAEMONPATH "help/help_keywords"
#define HELP_SERVER       KEYWORD_D
#define FILE               1
#define KEYWORD            0
 
mapping keywords; 

public int update_server();

void create()
{
  if(sizeof(explode(object_name(this_object()), "#")) > 1) // i.e. a clone
  {
    CHANNEL_D->SendTell( "error", object_name(this_object()),
			 "Cloning help server is not possible",1);
    destruct(this_object());
  }
  
  seteuid(getuid(this_object()));
   
  if(file_date(object_name(this_object())+".o") < file_date(KEYWORDS_FILE))
  {
    if(!update_server())  // if there was a problem loading the file
      raise_error("Help keywords database is empty!");
  }
  else
    restore_object(HELP_SERVER);
}

/*---------------------- QueryKeyword -----------------------------
 * 
 *  This function checks if a keyword is contained in the database
 *  mapping.
 *
 *  Argument: a keyword string 
 *  Returns: the full file path if found, 0 if not found
 *-----------------------------------------------------------------------*/

public mixed QueryKeyword(string kw)
{
  if(!kw)
    return 0;
  
  return keywords[kw];
}

/*------------------------ update_server ----------------------------------
 *
 *  This function reads in the keywords file, parses out the lines and 
 *  stores the keywords & file names in the global mapping keywords.
 *
 *  It's slower than storing the keywords directly in the server, but
 *  has the advantage of an easily editable keywords database.
 *
 *  This should only be called when the keywords database has been edited;
 *  otherwise the server will use the keywords stored in the save_object()
 *  file.
 *
 *  Returns: 1 on success, 0 if a problem appears.
 *-----------------------------------------------------------------------*/

public int update_server()
{
  int at_end;           // are we at the end of the file?
  int line_nr;          // file line nr to read
  mixed s;              // line read in
  string *strs;

  line_nr = 1;
  strs = ({});
  at_end = 0;
  
  if(file_size(KEYWORDS_FILE) <= 0) // no keywords database
  {
    raise_error("Can't find help keywords file. Help daemon aborting");
    return 0;
  }
  
  keywords = ([ ]);  // empty out mapping in case we delete old entries
  
  for(s = read_file(KEYWORDS_FILE, line_nr, 1); at_end == 0; line_nr++)
  {
    s = read_file(KEYWORDS_FILE, line_nr, 1);
    
    if(s == 0)
    { 
      at_end = 1;
      break;
    }

    if (s[<1] == '\n')  // to get rid of trailing \n
      s = s[0..<2];
    
    if(sizeof(regexp( ({ s }), "^//" ))) // line begin with a comment?
      continue;
        
    if(sizeof(s) <= 0)
      continue;
    
    strs = explode(s, ":");  // break into pieces
    
    if(sizeof(strs) != 2)    // oops, too many pieces
    {
      //raise_error(
      // "Too many arguments in line " + s + 
      // " in help keywords file. Aborting");
      //return 0;
      continue;
    }
    
    if( file_size(strs[FILE]) <= 0 )  // does the help file exist?
    {
      raise_error(
       "Non-existant help file in keywords database: '"+ strs[FILE]+"'\n");
      return 0;
    }
    
    keywords[strs[KEYWORD]] = strs[FILE];  // add this keyword to mapping
        
  } // while
   
  save_object(HELP_SERVER);
  return 1;
}
  
    
    
    
    
    
    
