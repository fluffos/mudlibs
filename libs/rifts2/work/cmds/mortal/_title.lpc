#include <std.h>

inherit DAEMON;      
int cmd_title(string str) {
      int level;
      string name, title, pre, gen, rank, _class;
    _class = lower_case(this_player()->query_class());
    level = (int)this_player()->query_level();
    title = (string)this_player()->query_title();
    name = (string)this_player()->query_cap_name();
    gen = (string)this_player()->query_gender();
 switch(level) {
    default:
    case 1..3:
      rank = "novice";
      break;
    case 4..6:
      rank = "apprentice";
      break;
    case 7..10:
      rank = "journeyman";
      break;
    case 11..14:
      rank = "craftsman";
      break;
    case 15..17:
      rank = "artisan";
      break;
    case 18..19:
      rank = "expert";
      break;
    case 20..24:
      rank = "master";
      break;
    case 25..30:
      rank = "adept";
      break;
    case 31..1000:
      rank = "grand";
      break;
    }

    if(file_size("/data/pretitles/"+_class+"/"+rank+".pt") > -1){
        pre = read_file( "/data/pretitles/"+_class+"/"+rank+".pt", 1, 1 );
        pre = replace_string(pre, "\n", "");

    }
    else {
        pre = capitalize(rank);
    }

    if(!str) {
        notify_fail("Your title is currently: "+pre+" "+title+"\n");
        return 0;
    }
    if(str=="reset"){
        this_player()->setenv("TITLE", pre+" $N the "+capitalize(this_player()->query_race()));
          write("Your title has been reset.\n");
        return 1;

    }        
    if(level < 12)  {
         notify_fail("You must be level 12 to set your title!\n");
         return 0;      
         }
        this_player()->setenv("TITLE", pre+" $N "+str);
        write("Your title is now: "+pre+" "+name+" "+str+"\n");
    return 1;
}

void help() {
    write("Syntax: <title [new title]>\n\n"+
        "Changes your title that comes after your name.\n");
}
