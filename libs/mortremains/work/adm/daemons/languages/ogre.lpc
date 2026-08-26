#include <language.h>
#include <daemons.h>

string garble( string *chunks )
{
   int t;
   string *garb, actual_string;

   garb=({
       "a", "arth", "air", "aie", "aur", "bo", "bha", "boe", "bor", "bur",
       "che", "chou", "can", "chen", "chan", "dhou", "der", "dirun",
       "dhon", "das", "dar", "dor", "eir", "eu", "e", "fo", "fu", "fe",
       "fin", "gahr", "ga", "go", "ge", "gi", "gu", "hor", "hai", "hou",
       "han", "hur", "har", "hche", "i", "ihe", "iyur", "iaur", "iour",
       "ihan", "iheir", "ior", "iau", "jhin", "jher", "jeh", "jhon", "jha",
       "khe", "kha", "khou", "lir", "lour", "lerin", "lau", "mo", "ma", "me",
       "mou", "mae", "mei", "nah", "nhou", "nhe", "nehi", "oor", "oour",
       "oar", "or", "our", "pei", "pou", "pau", "pei", "phe", "pai", "que",
       "qhan", "quu", "rhe", "rhei", "rhan", "rhun", "rhen", "rhin", "ran",
       "ren", "rin", "sil", "sal", "shul", "shil", "tar", "thur", "tha",
       "thin", "thein", "uur", "uoi", "uour", "uah", "uh", "u", "vin",
       "vah", "vhou", "vir", "xa", "xhy", "xin", "yar", "your", "ya",
       "zhe", "zhou", "zhan", "zhei", "zhin", "ze", "zi"
   });

   actual_string="";
   t = sizeof(chunks);

   while( t--)
   {
       string part1, part2, concat;

       // get 2 strings from the garbling.

       part1=garb[random(sizeof(garb))];
       part2=garb[random(sizeof(garb))];

       if (chunks[t] != "")
          concat = part1 ;
       else
          concat = " " ;

       // randomized chance of hetting the second part. ;)

       if ( random (101) <= 45 && concat != " " )
          concat += part2;

       if ( (int)LANGUAGE_D->check_capitalizing( chunks[t] ) )
          concat = capitalize(concat) ;

       actual_string += concat + LANGUAGE_D->get_signs(chunks[t]) + " ";

   }

   return actual_string;
}



