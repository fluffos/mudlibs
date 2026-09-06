/*--------------------------------------------------------------------------
 * /std/player/bin/who.c  --  The man command.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 * [Softbyte 15jan1998]  V1.0 Index search for manfiles
 *--------------------------------------------------------------------------
 */

/**
  @author Softbyte
  @version V1.0
*/
/** @synopsis
  man <topic>
  man <section> <topic>
  man <section> list
  man <section> <regexp> list
  man <section> init
  man <filename> new
*/
/** @description
  'man <topic>' displays the doc file to the given topic or keyword.
  'man <section> <topic>' shows only the topics of the given section
  'man <section> <regexp> list' lists the contents of the assiociated
    section which contain the given regexp.
  'man <section> list' lists the contents of the assiociated section
  'man <section> init' reinmitialises the given section. This is needed
    if you create a NEW manfile in this section.
  'man <filename> new' will reindex or index the given file, this adding
    its keywords and alias to the database.
  The command given without any argument lists the available topic
  groups.

  The argument is treated without regard to casing or special
  characters, i.e.  'man P_LONG' and 'man plong' are identical.
  If for one topic several different doc files exist, the command
  displays a menu with the possible choices. The user may now select
  one of the choices by entering its number or the pathname displayed.
  Entering 'q' or 'quit' cancels the menu.

<!- begin index ->
  Using the manual index mode 'man <filename> new' will scan the file
  for special HTML comments, which MUST start at the beginning of a
  line.
  Sections can be assigned to keywords with the following construction:
  <!- begin keyword ->
    ...
  <!- end ->
  A man call to keyword will then show the text in between the 'begin'
  and 'end'.

  <!- alias keyword existingkeyword ->
  Assigns a new keyword to an existing keyword. This is done recursively,
  so please try to avoid endless loops! In which file(s) the alias are
  defined doesn't matter

<!- end ->
*/

/** @example
  man :              Display all topic groups available.

  man efun list :    Display the names of all doc files for efuns

  man std set list : Display the names of all doc files for std which
                     contain the string 'set'

  man std ^set list: Display the names of all doc files for std which
                     begin wth the string 'set'

  man man :          Displays the doc file for the man-command
                     (equivalent to 'more /doc/w/man')

  man P_LONG :       Display the doc file for the P_LONG property
  man plong  :       ditto

  man helpdir drop : Displays the doc file for the command 'drop'
  man applied drop : Displays the doc file for the lfun 'drop'
  man drop :         Displays a menu to select beneath one of the two
                     docfiles mentioned above.

  man /doc/std/food new : Creates a new index file for this man file
*/

/** @todo
  - Automatically indexing all manfiles
  - Time check on the indexed files
*/
/** @see
  ls(w), ed(w), more(w), cat(w), type(w)
*/


#include <daemons.h>
#include <msgclass.h>


/* Select a given man topic out of a menu */
void man_select(string str,mixed *n_data)
{
  int no;
  string fname;
  int line1,line2;

  if (!str || str == "" || str=="q" || str=="x" || str=="quit")
  {
    msg_write(CMSG_GENERIC,"Aborted...\n");
    return;
  }

  no=atoi(str);
  if (!intp(no) || no<1 || no>sizeof(n_data))
  {
    msg_write(CMSG_ERROR,
    "Please choose a number between 1.."+sizeof(n_data)+" or 'q' for quit.\n");
    input_to("man_select",0,n_data);
    return ;
  }
  no--;

  fname=n_data[no][0];
  line1=n_data[no][1];
  line2=n_data[no][2];

  /* 4: MORE_NOHTML */
  if (line1>0)
  {
    MORE->more(fname,4,0,0,({line1+1,line2+1}));
  }
  else
  {
    MORE->more(fname,4,0,0,0);
  }

}

void show_keys(string section,string *keys)
{
string s;
int i;

    s="Available keywords in section '"+section+"' are:\n";
    for (i=0;i<sizeof(keys);i+=3)
    {
      if (i+2<sizeof(keys))
        s+=sprintf("%-25.25s %-25.25s %-25.25s\n",
          keys[i],keys[i+1],keys[i+2]);
      else if (i+1<sizeof(keys))
        s+=sprintf("%-25.25s %-25.25s\n",
          keys[i],keys[i+1]);
      else
        s+=sprintf("%-25.25s\n",
          keys[i]);
    }
    MORE->SMore(s);
}
/* The main command for showing manpages */
int main(string str)
{
  mixed *n_data;
  string *sections;
  int i;
  string s,section,key,fname;

  seteuid(getuid());
  notify_fail("man <topic>?\n");
  if (!str || str=="?")
  {
    sections=({string *})MAN_D->GetSections()||({});
    sections=sort_array(sections,#'> /*'*/);
    msg_write(CMSG_GENERIC,
      "Available sections are:\n"+
      implode(sections,", ")+".\n");
    return 1;
  }

  str=lower_case(str);

  // index a doc file manually
  if (1==sscanf(str,"%s new",fname))
  {
    fname = ({string})this_player()->get_path( fname, 0, this_player() );
    s=({string})MAN_D->IndexFile(fname,1);
    if (!s)
      msg_write(CMSG_GENERIC,"Done.\n");
    else
      msg_write(CMSG_GENERIC,s);
    return 1;
  }
  // list the contents of a section
  else if (2==sscanf(str,"%s %s list",section,key))
  {
    sections=({string *})MAN_D->GetKeywords(section);
    sections=regexp(sections,key)||({});
    sections=sort_array(sections,#'> /*'*/);
    show_keys(section,sections);
    return 1;
  }
  // list the contents of a section
  else if (1==sscanf(str,"%s list",section))
  {
    sections=({string *})MAN_D->GetKeywords(section);
    sections=sort_array(sections,#'> /*'*/);
    show_keys(section,sections);
    return 1;
  }
  // reinitialises a section
  else if (1==sscanf(str,"%s init",section))
  {
    if (!({int})MAN_D->InitSection(section))
      return notify_fail("Unknown section or other error.\n");
    msg_write(CMSG_GENERIC,"'"+section+"' initialized.\n");
    return 1;
  }
  // get only the keywords top a given section
  else if (2==sscanf(str,"%s %s",section,key))
  {
  }
  else
  {
    section=0;
    key=str;
  }

  if (key)
  {
    n_data=({mixed *})MAN_D->GetKeyword(key,section);
    if (!n_data || !sizeof(n_data))
    {
      msg_write(CMSG_ERROR,"'"+key+"' not found.\n");
      return 1;
    }
    s="Found "+sizeof(n_data)+" entries for '"+key+"':\n";

    // direct show of a page
    if (sizeof(n_data)==1)
    {
      man_select("1",n_data);
      return 1;
    }

    // show a menu of the topics found
    for (i=0;i<sizeof(n_data);i++)
    {
       if (n_data[i][1]!=-1)
         s+=sprintf("%2d: %-40.40s %3d..%3d\n",
             i+1,n_data[i][0],n_data[i][1],n_data[i][2]);
       else
         s+=sprintf("%2d: %-40.40s\n", i+1,n_data[i][0]);
    }
    msg_write(CMSG_GENERIC,s);

    msg_write(CMSG_GENERIC|MMSG_DIRECT,"[1.."+sizeof(n_data)+", q] ");
    input_to("man_select",0,n_data);
  } // end found topics

  return 1;
}
