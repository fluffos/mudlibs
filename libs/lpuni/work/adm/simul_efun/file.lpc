#include <config.h>

//file_owner(string file);

//Tacitus @ LPUniversity
//02-APR-05
//Simul-Efun

//Last edited on July 1st, 2005 by Tacitus

#include <config.h>

string file_owner(string file)
{
    string temp;
    
    if (file[0] != '/') file = "/" + file;

    if (sscanf(file, "/home/%s/%s/%*s", temp, temp) == 2) {
        return temp;
    }
    if(sscanf(file, "/adm/%s/%*s", temp) == 2) {
     return "Admin/" + temp;
     }
          
    return 0;
}

//file_lines(string file);

//Gwegster @ LPUniversity
//30-JUNE-05
// A simul_efun that takes the specified file and checks for
//      the amount of "\n"s in the file, thereby getting the
//      total amount of lines in the file.

int file_lines(string file)
{
     string str;
     string *lines;

     if(file_size(file) < 1)
     return 0;

     str = read_file(file);
     lines = explode(str + "", "\n");
     return sizeof(lines);
}

// tail(string file)

// Gwegster @ LPUniversity
// 30-JULY-05
// A simple tail command

/* Changes:

   Gwegster, 06/30/05 - changed default morelines to 20
   Gwegster, 06/30/05 - made tail a simul_efun
*/ 

// function: tail
// returns: -1 for no file, 0 if nothing entered, and 1 if it all worked

int tail(string file)
{
  if(!file)
  {
    return 0;
  }

  file = resolve_path(this_player()->query("cwd"),file);
  
  if(!file_exists(file))
  {
     return -1;
  }

  if(!this_player()->query("morelines"))
  {
    this_player()->set("morelines", 20);
  }
  
  write(read_file(file, (file_lines(file) - this_player()->query("morelines")), (file_lines(file))));
  write("\n");
  return 1;
}

//log_file(string file, string str)

//Tacitus @ LPUniversity
//15-APR-05
//Simul-efuns

int log_file(string file, string str)
{
     if(!file || !str) return 0;
     master()->log_file(file, str);
     return 1;
}




