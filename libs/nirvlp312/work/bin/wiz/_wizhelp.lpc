#define levelGrps ({21,30,40,50,60,70,80,90,100,1000})

int levelGrpSize;

void reset(status x)
{
 if(!x) levelGrpSize=sizeof(levelGrps);
}

status cmd_wizhelp(string arg) {
 int  x;

 if(!arg)
  arg = "wizhelp";
 if(sscanf(arg,"%d",x))
  arg = ""+x+"/"+x+"";
 for(x=0;x<levelGrpSize;x++)
 {
/*
  if((int)this_player()->query_level() < levelGrps[x])
   break;
*/
   if(cat("/doc/wizhelp/"+levelGrps[x]+"/"+arg) > 0)
    return 1;
 }
 if(cat("/doc/wizhelp/"+arg) == -1)
  write("Wizhelp file for \""+arg+"\" does not exist.\n");
 return 1;
}
