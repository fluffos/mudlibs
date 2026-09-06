#include <const.h>

int main(string param) {
   int reps;
   string comand;

   WIZ_CHECK

   if( !param ) {
      notify_fail("==> [Format] rep # 'command'.\n");
      return 0;
    }

   sscanf(param, "%d %s", reps, comand);

   if(!reps || !comand) {
      notify_fail("==>Invalid # of parameters.\n");
      return 0;
   }

  if( reps > 20 ) {
     notify_fail("==> Woah! The limit of reps is 20.\n");
     return 0;
   }

  if( reps < 1 ) {
     notify_fail("==>Woah! You should at least repeat it once.\n");
     return 0;
   }

  if(strstr(comand, "rep") != -1) {
     notify_fail("==>You cannot repeat repeats. Duh!\n");
     return 0;
  }

   if ( command(comand,this_player()) != 0 ) {
      for(int x=1; x<reps; x++)
         command(comand, this_player());
   }
return 1;
}
