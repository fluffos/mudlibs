//      /adm/simul_efun/translate.c
//      from the Nightmare Mudlib
//      translates a string into nonsense for non-proficient speakers
//      created by Descartes of Borg 930823
//      based on a speak function by Valodin@Nightmare
//      Modified by Seeker@Primal Darkness

#define FLUBS ({ "womble", "assimilate", "scruvy", "bing", "lait", "krishe",\
"something", "blarg", "gyro", "yellow hephalumps", "darmok", "tanagra",\
"cabbage", "blurgle", "jello", "migrated", "furry", "driznit", "folnar",\
"pamplemousse", "burrito", "eyne", "duh",\
})

string *alpha = ({ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
                 "l", "m", "n", "o","p","q","r","s","t","u","v","w","x",
                "y", "z" });
string translate(string str, int prof) {
    string *words, tmp;
    int i, a, max, flubsize;

    
    flubsize = sizeof(FLUBS);
    for(i=0, max = sizeof(words = explode(str, " ")); i<max; i++) 
      if(random(10)+1 > prof) 
       {  
        tmp = "";
        for (a=0; a<sizeof(words[i]); a++)
           if (random(10) > 5)
             tmp += capitalize(alpha[random(sizeof(alpha)-1)]);
            else
              tmp += alpha[random(sizeof(alpha)-1)];
    //    words[i] = FLUBS[random(flubsize)];
          words[i] = tmp;
       }
    return implode(words, " ");
}
