/* Name generator, imported from Multia mudlib */
string *sylls1,*sylls2,*jap_sylls;

void init_sylls() {
   /* Just 625 different names...but nearly all are sensible... */
   sylls1 = ({"ar","um","ca","for","mor","gon","mel","va","var","ro",
      "el","ka","mi","ti","gan","olo","tul","zar","mir","mul",
      "be","mag","ha","ba","con"
   });
   sylls2 = ({"nor","bar","nost","dor","han","ras","kor","lar","da","dain",
      "ric","ran","nas","rith","der","rin","kas","hir","ros","tia",
      "leg","lor","rak","tak","lak"
   });

   /* Infinite amount of 95% sensible oriental names */
   jap_sylls = ({
    "yen","ten","wo","ya","yu","yo","ka","ki","ku","ke","ko","sa",
    "shi","su","se","so","ta","chi","tsu","te","to","na","ni","nu",
    "ne","no","ha","hi","fu","he","ho","me","mi","mu","me","mo","ya",
    "ra","ri","ru","re","ro","wa"
   });
}

/* Generate single Multian name */
string random_name() {
   string n;

   if(!sylls1 || !sylls2) init_sylls();
   n = sylls1[random(sizeof(sylls1))] + sylls2[random(sizeof(sylls2))];

   return n;
}

/* Oriental (japanese) names */
string random_oriental_name() {
   int syl,i,num;
   string name;

   if(!jap_sylls) init_sylls();
   num = random(3) + 2; name = "";
   for(i=0;i<num;i++) {
      name += jap_sylls[random(sizeof(jap_sylls))];
   }
   return name;
}

/* Orcish names */
string random_orc_name() {
   int i;
   string tmp;

   tmp = "";
   for(i=0;i<3+random(4);i++)
      tmp += ({"a","c","g","h","k","p","r","s","t","z"})[random(10)];
   return tmp;
}
