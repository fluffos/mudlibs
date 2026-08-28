//      /adm/simul_efun/high_mortalp.c
//      from the Nightmare mudlib
//      a pointer for high mortals
//      written by Descartes of Borg 28 january 1993

int high_mortalp(object ob) {
    if(!ob) ob = previous_object();
    if(!wizardp(ob) && (int)ob->query_level() > 24) return 1;
    return 0;
}
