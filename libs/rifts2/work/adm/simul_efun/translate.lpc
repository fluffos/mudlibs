//      /adm/simul_efun/translate.c
//      from the Nightmare Mudlib
//      translates a string into nonsense for non-proficient speakers
//      created by Descartes of Borg 930823
//      based on a speak function by Valodin@Nightmare

#define FLUBS ({ "euismod ", "ut", "accumsan", "posuere", "blurgle", "malesuada", "bing", "convallis", "condimentum", "imperdiet", "ut", "nisi", "vitae", "nunc", "lacinia", "congue", "vel", "ut", "mauris"})
string translate(string str, int prof) {
    string *words;
    int i, max, flubsize;

    flubsize = sizeof(FLUBS);
    for(i=0, max = sizeof(words = explode(str, " ")); i<max; i++)
      if(random(100) > prof) words[i] = FLUBS[random(flubsize)];
    return implode(words, " ");
}
