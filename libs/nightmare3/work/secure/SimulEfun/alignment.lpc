/*    /adm/simul_efun/alignment.c
 *    from Nightmare IV
 *    efuns which deal with player alignments
 *    created by Descartes of Borg 940206
 */


int alignment_ok(object ob) {
    string str_class;
    int al;

    if((int)ob->query_level() == 1) return 1;
    str_class = (string)ob->query_class();
    if(!str_class) return 1;
    al = (int)ob->query_alignment();
    switch(str_class) {
        case "monk": return (al > 200);
        case "cleric": return (al > 0);
        case "kataan": return (al < -200);
        default: return 1;
    }
}

string alignment_string(mixed val) {
    if(objectp(val)) val = (int)val->query_alignment();
    else if(val && !intp(val)) error("Bad argument 1 to alignment_string().\n");
    if(val > 1000) return "saintly";
    else if(val > 750) return "righteous";
    else if(val > 500) return "good";
    else if(val > 280) return "benevolent";
    else if(val > 135) return "nice";
    else if(val > -135) return "neutral";
    else if(val > -280) return "mean";
    else if(val > -500) return "malevolent";
    else if(val > -750) return "bad";
    else if(val > -1000) return "evil";
    else return "demonic";
}
