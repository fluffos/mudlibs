/******************************************************************************
 *  File:           formatter.c
 *  Function:       Select and display news groups and posts
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         14/06/2004
 *  Notes:          
 *  Change History: 
 *****************************************************************************/
#include <security.h>
#include <ansi.h>
#include "/obj/news.h"

inherit "/obj/newtreasure";

#define PROMPT "Current: " + Global_Name + ": " + \
        implode(explode(read_file(Global_Group + \
        Global_ID, 1,3), "\n"), " - ")

string  Global_Message;             /* Text of Output Message */
string  *Global_Posts;              /* Posts in Current Group */
string  Global_Group;               /* Path to Current Group  */
string  Global_Name;                /* Name of Current Group  */
string  *Global_Group_Names; /* Necessitated by Archaic input_to function */
mapping Global_Group_List;          /* Group:Path Mapping     */
string  Global_ID;                  /* Message Name/ID Tag    */
int     Current_Post;               /* Current  Message       */
string  Temp_Time;                  /* Show Last Time Posted  */

void reset(status arg);
void init();
void menu_text();
varargs status read_it(string str);
void output_message();
status start_menu();
varargs void start_selection(string selected_option);
varargs void list_groups(int load);
varargs status list_posts(int load);
status select_post(string posts);
varargs status select_group();
status select_group2(string group);
status message_menu(string selected_option);
status confirm_function(int menu_flag);
varargs status help_start();
varargs status help_menu(string selected_option);
status help_startup();
status help_groups();
status help_posts();
status help_colors();

/******************************************************************************
 *  Function:     reset
 *  Description:  Sets up the newsreader/paper
 *              
 *  Arguments:  arg - reset or not reset
 *  Returns:    void
 *****************************************************************************/
void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("newspaper");
  set_alias("newsreader");
  set_short("");
  set_long("");
  set_weight(1);
  set_value(0);
  add_id("news");
  add_id("paper");
  Global_ID = "00groupintro.news";
}

/******************************************************************************
 *  Function:   init
 *  Descrip:    Adds the command to read the news.
 *              
 *  Arguments:  none
 *  Returns:    void
 *****************************************************************************/
void
init()
{
  ::init();
  add_action("read_it","read");
}

/******************************************************************************
 *  Function:   read_it
 *  Descrip:    Pulls up the initial menu for the news reader and allows the
 *              individual to select what they want to do.
 *  Arguments:  str - "news" to start the whole thing
 *  Returns:    status
 *****************************************************************************/
varargs status
read_it(string str)
{
  if (!str || str != "news")
  {
    notify_fail("\
  If you want to read about all the cool things that are going on\n\
  in and around Nirvana, just type " + HIW + "read news" + NORM + ".\n");
    return 0;
  }
  if (str == "news")
  {
    list_groups(0);
    write("  Welcome to the vNews System. The vNews Reader is currently at \
version\n" + HIW + VERSION + NORM +" and will probably undergo several \
revisions before it is\ncompletely functional. If you have any issues with \
the way the vNews\nReader works, mudmail Vital immediately.\n");
    start_menu();
    return 1;
  }
  write("begin_reading\(\) function ended w/o value.\n");
  return 1;
}

/******************************************************************************
 *  Function:   start_menu
 *  Descrip:    Initial menu, also called later to restart the reading process 
 *              
 *  Arguments:  none
 *  Returns:    status - inputs to start_selection()
 *****************************************************************************/
status
start_menu()
{
  write("Make a selection from the following options:\n" + pad("",80,'=') + "\n\
         [" + HIW + "1" + NORM + "]  Select/List News Group\n\
         [" + HIW + "2" + NORM + "]  List Posts in Current Group\n\
         [" + HIW + "3" + NORM + "]  Read Current Message\n\
         [" + HIW + "4" + NORM + "]  Stop Reading News\n\
         [" + HIW + "5" + NORM + "]  Access Help-System\n" + pad("",80,'=') +
"\nAn empty enter/return will move up one menu.\n");
  write("Select Number: ");
  input_to("start_selection");
  return 1;
}

/******************************************************************************
 *  Function:   list_groups
 *  Descrip:    Cycles through the news group directories and pulls out the
 *              groups [dirs] and populates them with posts [files]
 *  Arguments:  load - int switch to repopulate the mappings or not
 *  Returns:    void
 *****************************************************************************/
varargs void
list_groups(int load)
{
  int a, b, c, d, e, f, g, h, i, j;
  string *level1, *level2, *level3, *level4, *level5;
  string name;

  Global_Group_List = ([ ]);
  level1 = get_dir(GROUPS + "???*");
  a = sizeof(level1);
  for (b = 0; b < a; b++)
  {
    if(file_size(GROUPS + level1[b]) == -2);
    {
      name = level1[b];
      if (load) write(name + "\n");
      Global_Group_List += ([ name:GROUPS + level1[b] + "/" ]);
      if (level2 = get_dir(GROUPS + level1[b] + "/???*"))
      {
        c = sizeof(level2);
        for (d = 0; d < c; d++ )
        {
          if (file_size(GROUPS + level1[b] + "/" + level2[d]) == -2)
          {
            name = level1[b] + "." + level2[d];
            if (load) write(name + "\n");
            Global_Group_List += ([ name:GROUPS + level1[b] + "/" +
              level2[d] + "/" ]);
            if (level3 = get_dir(GROUPS + level1[b] + "/" + level2[d] +
              "/???*"))
            {
              e = sizeof(level3);
              for (f = 0; f < e; f++)
              {
                if (file_size(GROUPS + level1[b] + "/" + level2[d] + "/" +
                  level3[f]) == -2)
                {
                  name = level1[b] + "." + level2[d] + "." + level3[f];
                  if (load) write(name + "\n");
                  Global_Group_List += ([ name:GROUPS + level1[b] + "/" +
                    level2[d] + "/" + level3[f] + "/" ]);
                  if (level4 = get_dir(GROUPS + level1[b] + "/" + level2[d] +
                    "/" + level3[f] + "/???*"))
                  {
                    g = sizeof(level4);
                    for (h = 0; h < g; h++)
                    {
                      if (file_size(GROUPS + level1[b] + "/" + level2[d] + "/"
                        + level3[f] + "/" + level4[h]) == -2)
                      {
                        name = level1[b] + "." + level2[d] + "." + level3[f] +
                          "." + level4[h];
                        if (load) write(name + "\n");
                        Global_Group_List += ([ name:GROUPS + level1[b] +
                          "/" + level2[d] + "/" + level3[f] + "/" +
                          level4[h] + "/" ]);
                        if (level5 = get_dir(GROUPS + level1[b] + "/" +
                          level2[d] + "/" + level3[f] + "/" + level4[h] +
                          "/???*"))
                        {
                          i = sizeof(level5);
                          for (j = 0; j < i; j++)
                          {
                            if (file_size(GROUPS + level1[b] + "/" +
                              level2[d] + "/" + level3[f] + "/" + level4[h] +
                              "/" + level5[j]) == -2)
                            {
                              name = level1[b] + "." + level2[d] + "." +
                                level3[f] + "." + level4[h] + "." + level5[j];
                              if (load) write(name + "\n");
                              Global_Group_List += ([ level5[j]:GROUPS +
                                level1[b] + "/" + level2[d] + "/" + level3[f] +
                                "/" + level4[h] + "/" + level5[j] + "/" ]);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (load) confirm_function(1);
}

/******************************************************************************
 *  Function:   list_posts
 *  Descrip:    Writes out the posts in the current group, or if no group is
 *              selected, then writes out the "area" group's posts
 *  Arguments:  none
 *  Returns:    status
 *****************************************************************************/
varargs status
list_posts(int load)
{
  int x, y, z, a;
  string complete, subject, date, author, color, junk, morejunk;
  if (!Global_Group) Global_Group = "/open/NEWS/groups/area/";
  Global_Posts = get_dir(Global_Group + "*.news");
  if (!sizeof(Global_Posts) ||
    ((this_player()->query_level() < WIZARD ) &&
       (text_contains(Global_Group, "dev"))))
  {
    write("There are no posts available for this group.\n");
    message_menu("g");
    return 1;
  }
  z = 0;
  write("Select a post by number from the list below:\n" +
    pad("",80,'=') + "\n");
  y = sizeof(Global_Posts);
  for (x = 0; x < y; x++)
  {
    int b;
    sscanf(Global_Posts[x], "%d.news", b);
    if( b > (time() - 604800))
    {
      color = HIR;
    }
    else if( b > (time() - 1209600))
    {
      color = HIG;
    }
    else
    {
      color = HIW;
    }
    complete = implode(explode(implode(explode(read_file(Global_Group +
               Global_Posts[x], HEADER), "\n"), " - "), ":  "), ":");
    if (sscanf(complete, "Posted:  %s - %s", date, junk) == 2)
    {
      if (!date) date = "Eternal";
/*       date = color + date + NORM; */
    }
    if (sscanf(complete, "%sSubject: %s - %s", junk, subject, morejunk) == 3)
    {
      if (!subject) subject = "Eternal Message";
/*       subject = color + subject + NORM; */
    }
    if (sscanf(complete, "%sAuthor:  %s", junk, author) == 2)
    {
      if (!author) author = "vNews System";
/*       author = color + author + NORM; */
    }
    complete =  colour_pad("[" + color + (x + 1) + NORM + "] ", 5) + color +
      "Date: " + NORM + colour_pad(date, 10) + color + " Subj: " + NORM +
      colour_pad(subject, 30) + color + " Author: " + NORM +
      colour_pad(author, 13) + NORM + "\n";
    write(complete);
  }
  menu_text();
  write("An empty enter/return will move up one \
menu.\nSelect Post's Number: ");
  input_to("select_post");
  return 1;
}

/******************************************************************************
 *  Function:   select_post
 *  Descrip:    chooses one of the posts in the currently selected newsgroup
 *              and hands it off to output_message()
 *  Arguments:  string of post
 *  Returns:    status
 *****************************************************************************/
status
select_post(string post)
{
  string junk;
  
  if (post == "" || !post)
  {
    write("Returning to Group Selection.\n");
    message_menu("g");
    return 1;
  }
  if (message_menu(post)) return 1;
  if (sscanf(post, "%d %s", Current_Post, junk) == 1)
  {
    if (Current_Post < 1 ||
        Current_Post > (sizeof(Global_Posts) + 1) )
    {
      write("There is no post " + Current_Post + ".\n");
      list_posts(0);
      return 1;
    }
    if (catch(Global_ID = Global_Posts[Current_Post - 1]) )
    {
      write("No such post. Returning to Post Selection.\n");
      list_posts(0);
      return 1;
    }
    Global_Message = read_file(Global_Group + Global_ID);
    write("\n\n\nYou have selected the post: [" + HIW + Current_Post + NORM +
          "] \n");
    output_message();
    return 1;
  }
  list_posts(0);
  return 1;
}

/******************************************************************************
 *  Function:   query_message_age
 *  Descrip:    Determine if message was posted in the last week and return
 *              red color code, green if older and blue if no messages
 *  Arguments:  str
 *  Returns:    
 *****************************************************************************/
string
query_message_age(string group)
{
  int z, c;
  string *x;
  string temp;
  temp = "";
  if ( !(x = get_dir(Global_Group_List[group] + "*.news" ) ) ) return NORM;
  if ( z = sizeof(x) )
  {
    int a;
    for (a = 0, Temp_Time = "", c = 0; a < z; a++)
    {
      int b;
      sscanf(x[a], "%d.news", b);
      if (b > c)
      {
        Temp_Time = ctime(b);
        c = b;
      }
      if( b > (time() - 604800))
        temp = HIR;
    }
    if (temp)
      return temp;
  }
  return HIG;
}

/******************************************************************************
 *  Function:   select_group
 *  Descrip:    Displays the newsgroups and hands off to select_group2() to 
 *              process the users selection
 *  Arguments:  flag - skips input w/o flag
 *  Returns:    status
 *****************************************************************************/
varargs status
select_group(int flag)
{
  int x, y, z;
  string output, color, date;
  Global_Group_Names = keys(Global_Group_List);
  z = 0;
  write("Select a newsgroup by number from the list below:\n" +
    pad("",80,'=') + "\n");
  y = sizeof(Global_Group_Names);
  for (x = 0; x < y; x++)
  {
    if ( (this_player()->query_level() < WIZARD ) &&
         (text_contains(Global_Group_Names[x], "dev")) ) continue;
    color = query_message_age(Global_Group_Names[x]);
    if (Temp_Time && strlen(Temp_Time) > 22 )
    {
      date = numeric_month(Temp_Time[4..6]) + "\/" + Temp_Time[8..9] +
             "\/" + Temp_Time[20..23];
    }
    else
      date = "No Postings";
    output = colour_pad("[" + color + (x + 1) + NORM + "] ", 5) +
      colour_pad(color + Global_Group_Names[x] + NORM, 20) +
      pad(date, 13);
    if (z < 1)
      z++;
    else
    {
      z = 0;
      output += "\n";
    }
    write(output);
  }
  menu_text();
  write("\tOR\nSelect Group's Number: \n");
  if (!flag)
    input_to("select_group2");
  return 1;
}

/******************************************************************************
 *  Function:   select_group2
 *  Descrip:    Loads the selected group's posts and displays them, handing
 *              off to select_group() if no group or list_posts() if there is.
 *  Arguments:  string group
 *  Returns:    status
 *****************************************************************************/
status
select_group2(string group)
{
  int selected_number, temp;
  string junk;
  if (group == "")
  {
    write("Returning to previous menu.\n");
    message_menu("m");
    return 1;
  }
  if (sscanf (group, "%d", selected_number) == 1 && intp (selected_number) )
  {
    if ( ( selected_number < 1 ) || 
         ( selected_number > ( sizeof (Global_Group_Names) ) ) ) 
    {
      write("There is no group " + selected_number + "\n");
      if (message_menu(group)) return 1;
      select_group();
      return 0;
    }
    temp = selected_number - 1;
    Global_Name = Global_Group_Names[temp];
    Global_Group = Global_Group_List[Global_Name];
    if ( ((this_player()->query_level() < WIZARD ) &&
       (text_contains(Global_Group, "dev"))) )
    {
      write("There is no group " + selected_number + "\n");
      if (message_menu(group)) return 1;
      select_group();
      return 0;
    }
    write("You have selected the group: [" + selected_number + "] " +
      Global_Name + "\n\n\n");
    list_posts(0);
    return 1;
  }
    else
  {
    if (message_menu(group)) return 1;
    write("You failed to enter a valid value.\n");
    select_group();
  }
  return 1;
}

/******************************************************************************
 *  Function:   start_selection
 *  Descrip:    Handles start_menu()'s selection and hands off to the correct
 *              function
 *  Arguments:  string menu_item
 *  Returns:    void
 *****************************************************************************/
void
start_selection(string selected_option)
{
  if (!selected_option)
  {
    write("Returning to the menu.\n");
    start_menu();
  }
  switch(selected_option)
  {
    case "1"  :
      write("\nPreparing to Select News Group.\n\n");
      list_groups(00);
      select_group();
      break;
    case "2"  :
      write("\nObtaining List of Posts in " + Global_Name + ".\n\n");
      list_posts(0);
      break;
    case "3"  :
      write("\nReading Current Message.\n\n");
      output_message();
      break;
    case "x"  :
    case "4"  :
      write("Closing News Connection.\nGood-bye.\n");
      return;
    case "5"  :
      write("Accessing News Help System. Please hold for connection...\n");
      help_start();
      break;
    case ""   :
      start_selection("4");
      return;
    default   :
      write("Invalid or Unknown menu selection.\n\Please enter the number \
at the " + HIW + "Select Number" + NORM + " prompt\n");
      start_menu();
  }
}

/******************************************************************************
 *  Function:   output_message
 *  Descrip:    Writes out the message or moves to the confirm_function() if
 *              there is no text or message
 *  Arguments:  none
 *  Returns:    void
 *****************************************************************************/
void
output_message()
{
  if (Global_Message)
    if ( file_size(Global_Group + Global_ID) || strlen(Global_Message) > 0)
    {
      write(Global_ID + "\n");
      write(Global_Message + "\n");
    }
    else
      write("Error: No Message Text.");
  confirm_function(2);
}

/******************************************************************************
 *  Function:   message_menu
 *  Descrip:    Menu displayed during the 
 *              
 *  Arguments:  
 *  Returns:    
 *****************************************************************************/
status
message_menu(string selected_option)
{
  string temp;
  switch(selected_option)
  {
    case "r"  :
      output_message();
      break;
    case "g"  :
      write("Preparing to select news group.\n");
      select_group(0);
      break;
    case "p"  :
      write("Attempting to access next message.\n");
      temp = "" + (Current_Post - 1);
      select_post(temp);
      break;
    case "n"  :
      write("Attempting to access next message.\n");
      temp = "" + (Current_Post + 1);
      select_post(temp);
      break;
    case "s"  :
      list_posts(0);
      break;
    case "m"  :
      start_menu();
      break;
    case "?"  :
    case "H"  :
    case "h"  :
      help_start();
      break;
    case "x"  :
      start_selection("4");
      break;
    case ""   :
      write("\nReturning to Main Menu.\n");
      start_menu();
      break;
    default   :
      confirm_function(2);
      return 0;
  }
  return 1;
}

/******************************************************************************
 *  Function:   confirm_function
 *  Descrip:    News Reader internal/switchable menu to handle psuedo-menu
 *              based calls from other functions.
 *  Arguments:  int menu_flag
 *  Returns:    status
 *****************************************************************************/
status
confirm_function(int menu_flag)
{
  switch (menu_flag)
  {
    case 1  :
      write("<Return to Main Menu>\n");
      start_menu();
      break;
    case 2  :
      menu_text();
      write("    Selection:\n");
      input_to("message_menu");
      break;
    default : input_to("start_menu");
  }
  return 1;
}

/******************************************************************************
 *  Function:   menu_text
 *  Descrip:    Write out the menu in multiple places
 *****************************************************************************/
void
menu_text()
{
  write(
"Select from the following:\n" + pad("",80,'=') + "\n\
    " + HIW + "r" + NORM + "  to read the post again\
    " + HIW + "n" + NORM + "  to go to the next post\n\
    " + HIW + "s" + NORM + "  to select another post\
    " + HIW + "g" + NORM + "  to list all the groups\n\
    " + HIW + "m" + NORM + "  to return to main menu\
    " + HIW + "p" + NORM + "  to go to previous post\n\
    " + HIW + "x" + NORM + "  to exit the newsreader\
    " + HIW + "h" + NORM + "  to see the help system\n" +
    pad("",80,'=') + "\n");
}

/******************************************************************************
 *  Function:   help_start
 *  Descrip:    Begins the help session for the vNews Reader
 *  Arguments:  none
 *  Returns:    status
 *****************************************************************************/
varargs status
help_start(string str)
{
  write(pad(" vNews Help System", -38, '*') +
        pad(" ", 22, '*'));
  write("\n\n\
  Welcome to the vNews System. The vNews Reader is currently at \
version\n" + HIW + VERSION + NORM +" and will probably undergo several \
revisions before it is\ncompletely functional. If you have any issues with \
the way the vNews\nReader works, mudmail Vital immediately.\n");
  write("\n\
  The following topics are available within the vNews Help System for\n\
exploration. For more information choose one of the following:\n\
" + pad("",80,'=') + "\n      " + HIW + "1" + NORM + " Startup   " + HIW +
"2" + NORM + " Newsgroups    " + HIW + "3" + NORM + " Posts   " + HIW +
"4" + NORM + " Colors\nEnter Selection: \n");
  input_to("help_menu");
  return 1;
}

/******************************************************************************
 *  Function:   help_menu
 *  Descrip:    Processes the help selections and passes off to the help text
 *  Arguments:  selected_option
 *  Returns:    status
 *****************************************************************************/
varargs status
help_menu(string selected_option)
{
  switch(selected_option)
  {
    case "1"  :
      write("Accessing help on the Startup of the vNews Reader.\n");
      help_startup();
      break;
    case "2"  :
      write("Accessing help on the Newsgroup in the vNews Reader.\n");
      help_groups();
      break;
    case "3"  :
      write("Accessing help on the Post found in the vNews Reader.\n");
      help_posts();
      break;
    case "4"  :
      write("Accessing help on the Colors used in the vNews Reader.\n");
      help_colors();
      break;
    default:
      write("Returning to the main menu\n");
      start_menu();
      break;
  }
  return 1;
}

/******************************************************************************
 *  Function:   help_startup
 *  Descrip:    Information on the startup process in the vNews Reader
 *  Arguments:  none
 *  Returns:    status
 *****************************************************************************/
status
help_startup()
{
  write(format("  The vNews Reader starts at a menu giving you 5 options to choose from. The default action at any menu [entering a blank line] will cause the vNews Reader move up level. For example: at the main menu, a blank return will cause the vNews Reader to close. At the post listing, it will move up to the group listing.\n  The first option \"1\" brings up the Newsgroup listing and allows you to decide which newsgroup you would like to begin reading. The default group is [area]"));
  write(format("  The second option \"2\" lists the posts in the currently selected group. If you've just started the vNews Reader, the default [area] group will be selected and the posts listed."));
  write(format("  The third option \"3\" reads the currently selected message. This is the first message in the default [area] group when you first start."));
  write(format("  The fourth option \"4\" closes the connection to the vNews Reader and ends the current newsreading session."));
  write(format("  The fifth option \"5\" is what you are reading right now.\n\nReturn to continue: \n"));
  input_to("help_start");
  return 1;
}

/******************************************************************************
 *  Function:   help_groups
 *  Descrip:    Information on the newsgroups in the vNews Reader
 *  Arguments:  none
 *  Returns:    status
 *****************************************************************************/
status
help_groups()
{
  write(format("  The vNews Reader System is broken down into group that are hierarchally organized according to their topics.\n\nReturn to continue:\n"));
  input_to("help_start");
  return 1;
}

/******************************************************************************
 *  Function:   help_posts
 *  Descrip:    Information on the news posts in the vNews Reader
 *  Arguments:  none
 *  Returns:    status
 *****************************************************************************/
status
help_posts()
{
  write(format("  The vNews Reader System is set to automatically read in new posts as they are added. The posts display the date, name, subject and author.\n\nReturn to continue :\n"));
  input_to("help_start");
  return 1;
}

/******************************************************************************
 *  Function:   help_colors
 *  Descrip:    Information on the colors used in the vNews Reader
 *  Arguments:  none
 *  Returns:    status
 *****************************************************************************/
status
help_colors()
{
  write(format_colour("  The use of colors within the vNews System has been \
chosen to make things easier to navigate and to maintain a standard interface. "
+ HIW + "Commands are usually highlighted to allow them to stand out better."
+ NORM + " The newsgroups themselves are listed in color based on the status \
of recent posts. Currently if a group contains posts that are newer than 1 \
week it is colored " + HIR + "red" + NORM + " and the rest are colored " + HIG +
"green" + NORM + ". If a group has no posts, then it is colored " + HIW +
"white"+NORM+".\n\nReturn to continue: \n", 70));
  input_to("help_start");
  return 1;
}
