

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   int i;
   
   if( !arg ) return notify_fail("ÄãÒªÌæ×Ô¼ºÈ¡Ê²Ã´´ÂºÅ£¿\n");
   
   if( arg=="none" ) {
   me->delete("nickname");
   return 1;
   }

if(!wizardp(me)&&(i = strlen(arg)) > 50 )
     return notify_fail("ÄãµÄ´ÂºÅÌ«³¤ÁË£¬ÏëÒ»¸ö¶ÌÒ»µãµÄ¡¢ÏìÁÁÒ»µãµÄ¡£\n");

   while(i--) {
                  if( arg[i]<' ' ) {
                          return notify_fail("¶Ô²»Æð£¬ÄãµÄÍ·ÏÎ²»ÄÜÓÃ¿ØÖÆ×ÖÔª¡£\n");
                  }
          }

arg = trans_color(arg, 2);

   me->set("nickname", arg + NOR);
        message_vision("$NµÄ´ÂºÅ±»Éè¶¨Îª:"+arg+"\n",me);
   return 1;
}
int help(object me)
{
        write(@HELP
Ö¸Áî¸ñÊ½ : nick <ÍâºÅ, ´ÂºÅ>
      nick none   È¡Ïû
 
Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄãÎª×Ô¼ºÈ¡Ò»¸öÏìÁÁµÄÃûºÅ»òÍ·ÏÎ£¬ÄãÈç¹ûÏ£ÍûÔÚ´ÂºÅÖÐ
Ê¹ÓÃ ANSI µÄ¿ØÖÆ×ÖÔª¸Ä±äÑÕÉ«£¬¿ÉÒÔÓÃÒÔÏÂµÄ¿ØÖÆ×Ö´®£º

$BLK$ - ºÚÉ«       $NOR$ - »Ö¸´Õý³£ÑÕÉ«
$RED$ - [31mºìÉ«[0m       $HIR$ - [0;1;31mÁ[1mÁ[1mº[1mì[1mÉ[1m«[0m
$GRN$ - [32mÂÌÉ«[0m       $HIG$ - [0;1;32mÁ[1mÁ[1mÂ[1mÌ[1mÉ[1m«[0m
$YEL$ - [33mÍÁ»ÆÉ«[0m     $HIY$ - [0;1;33m»[1mÆ[1mÉ[1m«[0m
$BLU$ - [34mÉîÀ¶É«[0m     $HIB$ - [0;1;34mÀ[1m¶[1mÉ[1m«[0m
$MAG$ - [35mÇ³×ÏÉ«[0m     $HIM$ - [0;1;35m·[1mÛ[1mº[1mì[1mÉ[1m«[0m
$CYN$ - [36mÀ¶ÂÌÉ«[0m     $HIC$ - [0;1;36mÌ[1mì[1mÇ[1mà[1mÉ[1m«[0m
$WHT$ - [30mÇ³»ÒÉ«[0m     $HIW$ - [0;1;37m°[1m×[1mÉ[1m«[0m

 
ÆäÖÐÏµÍ³×Ô¶¯»áÔÚ×Ö´®Î²¶Ë¼ÓÒ»¸ö $NOR$¡£

HELP
        );
        return 1;
}
