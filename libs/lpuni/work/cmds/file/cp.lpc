//cp.c

//Tacitus @ LPUniversity
//08-APR-05
//File system management

//Lasted edited on January 25th, 2006 by Tacitus

int main(string str)
{
     string source, dest;
     
     if(!str || !sscanf(str, "%s %s", source, dest)) return notify_fail("Syntax: cp <source> <dest>\n");
     
     source = resolve_path(this_player()->query("cwd"), source);
     dest = resolve_path(this_player()->query("cwd"), dest);
     
     if(directory_exists(dest) || dest[<1..<1] == "/")
     {
          if(dest[<1..<1] != "/") dest += "/";
          
          if(strsrch(source, "/", -1) != -1)
          {
             dest += source[(strsrch(source, "/", -1) + 1)..<1];
          }
          
          else dest += source;
     }
     
     if(source == dest)
          return(notify_fail("Error [cp]: Destination may not match source.\n"));
          
     if(!(int)master()->valid_write(dest, this_object(), "cp")) 
          return(notify_fail("Error [cp]: Permission Denied.\n"));
            
     if(cp(source, dest) < 0)
          return(notify_fail("Error [cp]: Copy failed.\n"));    
     else
          write("Successful [cp]: " + source + " copied to " + dest + "\n");
          
     return 1;
}

string help() {
    return (HIW + " SYNTAX: " + NOR + "cp <source> <destination>\n\n" +
    "This command copies a file from it's current destination to a specified one.\n");
}
