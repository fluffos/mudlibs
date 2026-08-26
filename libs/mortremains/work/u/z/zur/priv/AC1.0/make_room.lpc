// The room code for Auto Coder 1.0
#include "ac.h"

int defs_request(string str)
{
  switch(str)
  {
    case "n":
    case "N":printf("What light level does this room have?\n");
             printf(IPROMPT("light level"));
             input_to("light_level");
             break;
    case "q": return 1;
    default:  printf("What file needs to be included?\n");
              printf(IPROMPT("file included"));
              input_to("set_defs");
              break;
  }
  return 1;
}

int set_defs(string str)
  {
    file += sprintf("#include \"%s\"\n", str);
    printf("What light level does this room have?\n");
    printf(IPROMPT("light level"));
    input_to("light_level");
  }

int light_level(string str)
{
  int i;
  i = make_int(str);
  if(str == "q" || str == "Q") return 1;
  if(!str || !i)
  {
    printf("What light level do you wish the room to have?\n"+IPROMPT("light level"));
    input_to("light_level");
    return 1;
  }

  file += "void create(){\n\t\n\tseteuid( getuid(this_object()) );\n";
  file += sprintf("\tset(\"light\", %d);\n", i);
  printf("What short description does the room need?\n"+IPROMPT("short desc"));
  input_to("short_desc");
  return 1;
}

int short_desc(string str)
{
  if(str == "q" || str == "Q") return 1;
  if(!str)
  {
       printf("What short description does the room need?\n"+IPROMPT("short desc"));
       input_to("short_desc");
       return 1;
  }
  file += sprintf("\tset(\"short\", \"%s\");\n", str);
  printf("Please enter a long description for the room.\n");
  this_player()-> edit( TMP, "long_desc", this_object() );
  return 1;
}

int long_desc(){
 string str;
 str = read_file(TMP);
 file += sprintf("\tset(\"long\", @End\n%sEnd);\n", str);
 rm(TMP);
 printf("Input the first exit of the room using the form [ north, /a/file/name/thing.c ]\n"+IPROMPT("exit"));
 input_to("do_exit");
 file += "\tset(\"exits\", ([\n";
 return 1;
 }

int do_exit(string str)
{
  string di, fy;
  if(str == "q" || str == "Q") return 1;
  if(sscanf(str, "%s, %s", di, fy) != 2)
  {
    printf("Please use the form [ direction, filename ].\n"+IPROMPT("exit"));
    input_to("do_exit");
    return 1;
  }
  file += sprintf("\t   \"%s\" : \"%s\",\n", di, fy);
  printf("Any more exits?\n"+IPROMPT("more exits (Y/n|q)"));
  input_to("more_exits");
  return 1;
}
int have_obj(string str)
{
  switch(str)
  {
    case "n":
    case "N": printf("Finishing up....\n");
              file += "\t]));\n";
    		  finish_up();
    		  return 1;
    		  break;
   case "y":
   case "Y": printf("Please input the first object/monster in the form [ filename, # appearing ].\n"+IPROMPT("object/monster"));
             input_to("do_obj");
             return 1;
             break;
  default:  have_obj("N"); return 1; break;//This is stupid, I know.
 }
}
int do_obj(string str)
{
  string di, fy;
  if(str == "q" || str == "Q") return 1;
  if(sscanf(str, "%s, %s", di, fy) != 2)
  {
    printf("Please use the form [ filename, no. appearing ].\n"+IPROMPT("object/monster"));
    input_to("do_exit");
    return 1;
  }
  file += sprintf("\t   \"%s\" : %d,\n", di, make_int(fy));
  printf("Any more monsters/objects?\n"+IPROMPT("more monster/objects? (Y/n|q)"));
  input_to("more_obj");
  return 1;
}
int do_item(string str)
{
  string di, fy, *its, itm;
  if(str == "q" || str == "Q") return 1;
  if(sscanf(str, "%s : %s", di, fy))
     {
        int i;
        its = explode(di, ", ");
       if(its)
       {
        i = sizeof(its);
        itm = "({";
        while(i--)
        {
          itm += "\""+its[i]+"\",";
        }
        itm += "})";
       }
    }
  else{
  if(sscanf(str, "%s, %s", di, fy) != 2)
  {
    printf("Please use the form [ item, description ] or [ item1, item2, item3 : description ].\n"+IPROMPT("item"));
    input_to("do_item");
    return 1;
    }
    }
  file += sprintf("\t   %s : \"%s\",\n", (itm) ? itm : "\""+di+"\"", fy);
  printf("Any more item descriptions?\n"+IPROMPT("more items (Y/n|q)"));
  input_to("more_items");
  return 1; 
}
int more_items(string str)
{
  switch(str)
  {
    case "q":
    case "Q": return 1; break;
    case "n":
    case "N": printf("Does this room need any monsters/objects?\n"+IPROMPT("object/monster (y/N|q"));
    		  input_to("have_obj");
    		  file += "\t]));\n\tset(\"objects\", ([\n";
    		  return 1;
    		  break;
   default:   printf("Input next item description please.\n"+IPROMPT("item"));
              input_to("do_item");
              return 1;
              break;
 }
 return 1; //just in case.
}

int have_item(string str)
 {
   
   if(str == "q" || str == "Q") return 1;
   switch(str)
   {
     case "n":
     case "N": more_items("N"); return 1; break;
     case "y":
     case "Y":printf("Input the first item description in the form [ item, description ] or [ items : description ]\n"+IPROMPT("item"));
    		  input_to("do_item");
    		  return 1;
    		  break;
     default: have_item("Y");
   }
}
int more_exits(string str)
{
  switch(str)
  {
    case "q":
    case "Q": return 1; break;
    case "n":
    case "N": printf("Does this room require item descriptions?.\n"+ IPROMPT("item ? (Y/n|q)"));
    		  input_to("have_item");
    		  file += "\t]));\n\tset(\"item_desc\", ([\n";
    		  return 1;
    		  break;
   default:   printf("Input next exit now please.\n"+IPROMPT("exit"));
              input_to("do_exit");
              return 1;
              break;
 }
 return 1;
}

int more_obj(string str)
{
  switch(str)
  {
    case "q":
    case "Q": return 1; break;
    case "n":
    case "N": printf("Finishing up...\n");
    		  file += "\t]));\n";
    		  finish_up();
    		  return 1;
    		  break;
   default:   printf("Input next object/monster now please.\n"+IPROMPT("object/monster"));
              input_to("do_obj");
              return 1;
              break;
 }
 return 1;
}
int make_room(){
  string d;
  printf("Creating room [%s]\n", fname);
  d = TP->query("cwd");
  file += sprintf("//Coded by %s on %s\n", TP->query("cap_name"), ctime( time() ));
  file += "inherit ROOM;\n#include <mudlib.h>\n";
  printf("Are any files to be included by this file?\n");
  printf(IPROMPT("include? (Y/n|q)"));
  input_to("defs_request");
  return 1;
  }