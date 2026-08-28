//	/bin/user/_background.c
//	from the Darkemud mudlib
//	created by Shadowraith the Damned 02 october 1996

#include <std.h>
#include <security.h>
#include <daemons.h>
#include <dirs.h>

inherit DAEMON;

int cmd_background(string text);
int help();


int
cmd_background(string text)
{
    string file,who,*whol,uid,euid;
    string *allbg;
    object ob;
    int i,j;

    uid = getuid();
    euid=geteuid();
    write(sprintf("uid:%s euid:%s",uid,euid));
    ob = this_player();
    if( !text )
    {
       help();
       return 1;
    }
    text = lower_case(text);
    file = DIR_SAVE+"/backgrounds/"+ text +".b";
    if( (file_size(file) > 0) &&
            (text != "set") &&
            (text != "delete") &&
            (text != "list") )
    {
       ob->more(file);
       return 1;
    }
    else if(text == "list") {
      allbg=get_dir(DIR_SAVE+"/backgrounds/");
      j=sizeof(allbg);
      whol = ({""});
      for(i=0; i < j; i++) {
         sscanf(allbg[i],"%s.b",who);
         whol +=({capitalize(who)});
      }
      message("info","The Following Characters have backgrounds:",this_player());
      this_player()->more(whol);
      return 1;
    }
    else if(text == "set")
    {
       file=DIR_SAVE+"/backgrounds/"+ ob->query_name() + ".b";
       ob->edit(file, "finished", this_object());//send to callback finished()
       
       return 1;
    }
    else if(text == "delete")
    {
       file=DIR_SAVE+"/backgrounds/"+ ob->query_name() + ".b";
       if(file_size(file) > 0) rm(file);
       message("info", "Your background file has been deleted.\n",ob);
       return 1;
    }
    else
       return notify_fail (capitalize(text)+ " has not created a character background.\n");
}

void finished() {
        message("info","You have updated your background.\n",this_player());
}

int
help()
{
	write(
	"Syntax: <background [name/set/delete/list]>\n"+
	"\n"+
	"When name is given, returns tha background (if any) of that.\n"+
	"character.  When set is specified, it opens an editor to write/edit "+
        "the background history of the character. if delete is specified, \n"+
        "it remove the character's background file.  If list is specified\n"+
        " it will list all character's with backgrounds.\n"+
	"\nSee also: biography, score, and roleplay.\n");
	return 1;
}
