#include "../pr.h"
#define SCROLL "=[---------------------------------------------------------------]=\n"
int do_whole();
int do_single(string str);
void do_list();
string *alpha(string *str)
{
  int i, x;
  string *newString, tmp, tmp2;
  x = sizeof(str);
  while(x--)
  {
   tmp = str[x];
     tmp2 = (x != 0) ? str[x - 1] : str[x];
   newString =  sort_array(str, strcmp(tmp, tmp2) );
  }
  return newString;
 }
int cmd_religion(string str)
{
switch(str)
  {
    case "-l" : do_list(); break;
    case "-w" : do_whole(); break;
    default   : do_single(str); break;  
  }
  return 1;
}

int do_whole(){
  mapping ph;
  mixed *axes, *k;
  int i;
  ph = REL_D->get_spheres();
  if(!ph)
    return (int) notify_fail("Religion list unavailible. Contact Zur.\n");
  axes = values(ph);
  i = sizeof(ph);
  k = keys(ph);
  while(i--)
  {
    printf("Faith: %s\nMajor Spheres: %s\n, Minor spheres: %s\n", capitalize(k[i]),
    implode(axes[i][0], ", "), implode(axes[i][1], ", "));
  }
  return 1;
  }

void do_list()
{
   int i, col, x;
   mixed *k;
   k = keys(REL_D->get_spheres());
   k = alpha(k);
   i = sizeof(k);
   printf("The following relgions exist on the planes of %s.\n", capitalize(mud_name()));
   printf(SCROLL);
   for(x = 0; x < i; x++)
   {
     if(col > 4){ col = 0; printf("\n"); }
     printf("%:-13s", capitalize(k[x]));
     col++;
   }
  printf("\n");
  printf(SCROLL);
   return ;
}

int do_single(string str)
{
  mapping m;
  mixed *v, s;
  if(!str){
    tell_object(this_player(),"Usage: reilgion [-lw<religion name>]\n");
    return 1;
    }
  if(!(m = REL_D->get_spheres())) 
      return (int) notify_fail("Failed to load religion daemon.");
  v = m[str];
  if(member_array(str, keys(m)) == -1)
  {
       tell_object(this_player(), "There is no one in the multiverse of that faith\n");
       return 1;
  }
  printf(SCROLL+"Faith: %s\n", capitalize(str));
  s = implode(alpha(v[0]), ", ");
  printf("Greater Spheres: %s\n", s);
  s = implode(alpha(v[1]), ", ");
  printf("Minor Spheres: %s\n", s);
  printf(SCROLL);
  return 1;
}

string help(){
  return @EndHelp
The religion command is associated with the religions of the realm.
It accepts one of two flags or an argument.
     -l   :  Lists all religions in the multiverse.     
     -w   :  Provides the entire list of religions, with their greater and
             lesser spheres. (a pretty exhaustive read)
<argument>:  This lists the greater and minor spheres of access for <arg>'s religion.

--Zur(May '97)
EndHelp;
}