/* Programed by Moon 1998.03.23      */

#include <config.h>
#include <commands.h>
#include <daemons.h>
#include <login.h>
#include <uid.h>

void message(string cla,  string  mess,  mixed  target,
             mixed exclude)
{
     string * str;
     string new_mess;
     int i;
     str=explode(mess,"$");
     new_mess="";
     for(i=0;i<sizeof(str);i+=2)
     {
        if(i+1<sizeof(str) )
        {
           new_mess+=set_color(str[i+1],str[i]);
           continue;
         }
        else
        {
           new_mess+=str[i];
           break;
         }
     }
     efun::message(cla,new_mess,target,exclude);
}

