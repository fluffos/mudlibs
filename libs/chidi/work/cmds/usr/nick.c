

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   int i;
   
   if( !arg ) return notify_fail("дЦр╙лФвт╪╨х║й╡ц╢╢б╨её©\n");
   
   if( arg=="none" ) {
   me->delete("nickname");
   return 1;
   }

if(!wizardp(me)&&(i = strlen(arg)) > 50 )
     return notify_fail("дЦ╣д╢б╨ел╚Ё╓акё╛оКр╩╦Ж╤лр╩╣Ц╣д║╒оЛаар╩╣Ц╣д║ё\n");

   while(i--) {
                  if( arg[i]<' ' ) {
                          return notify_fail("╤т╡╩фПё╛дЦ╣дм╥он╡╩дэсц©ьжфвжт╙║ё\n");
                  }
          }

   arg = replace_string(arg, "$BLK$", BLK);
   arg = replace_string(arg, "$RED$", RED);
   arg = replace_string(arg, "$GRN$", GRN);
   arg = replace_string(arg, "$YEL$", YEL);
   arg = replace_string(arg, "$BLU$", BLU);
   arg = replace_string(arg, "$MAG$", MAG);
   arg = replace_string(arg, "$CYN$", CYN);
   arg = replace_string(arg, "$WHT$", WHT);
   arg = replace_string(arg, "$HIR$", HIR);
   arg = replace_string(arg, "$HIG$", HIG);
   arg = replace_string(arg, "$HIY$", HIY);
   arg = replace_string(arg, "$HIB$", HIB);
   arg = replace_string(arg, "$HIM$", HIM);
   arg = replace_string(arg, "$HIC$", HIC);
   arg = replace_string(arg, "$HIW$", HIW);
   arg = replace_string(arg, "$BLINK$", BLINK);
   arg = replace_string(arg, "$NOR$", NOR);  


   me->set("nickname", arg + NOR);
   write("Ok.\n");
   return 1;
}
int help(object me)
{
        write(@HELP
ж╦аН╦Яй╫ : nick <мБ╨е, ╢б╨е>
      nick none   х║оШ
 
уБ╦Жж╦аН©иртхцдЦн╙вт╪╨х║р╩╦ЖоЛаа╣дцШ╨е╩Рм╥онё╛дЦхГ╧ШоёмШтз╢б╨ежп
й╧сц ANSI ╣д©ьжфвжт╙╦д╠Дяуи╚ё╛©иртсцртоб╣д©ьжфвж╢╝ё╨

$BLK$ - ╨зи╚       $NOR$ - ╩ж╦╢уЩЁёяуи╚
$RED$ - [31m╨Ли╚[0m       $HIR$ - [0;1;31mаа╨Ли╚[0m
$GRN$ - [32mбли╚[0m       $HIG$ - [0;1;32mаабли╚[0m
$YEL$ - [33mма╩фи╚[0m     $HIY$ - [0;1;33m╩фи╚[0m
$BLU$ - [34mиНю╤и╚[0m     $HIB$ - [0;1;34mю╤и╚[0m
$MAG$ - [35mгЁвои╚[0m     $HIM$ - [0;1;35m╥ш╨Ли╚[0m
$CYN$ - [36mю╤бли╚[0m     $HIC$ - [0;1;36mлЛгЮи╚[0m
$WHT$ - [30mгЁ╩ри╚[0m     $HIW$ - [0;1;37m╟ви╚[0m
$BLINK$ - иак╦и╚
 

фДжпо╣мЁвт╤╞╩Атзвж╢╝н╡╤к╪ср╩╦Ж $NOR$║ё

HELP
        );
        return 1;
}
