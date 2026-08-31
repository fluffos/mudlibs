string extra_look() {

    string m;

    m = CAP(environment()->PRO)+" is a member of the famous Jedi guild.\n";

    switch (environment()->query_al_string()) {
        case "demonic":
             m+="You sense that "+environment()->PRO+" is one with the Dark Side of the Force";
             break;
        case "evil":
             m+=CAP(environment()->PRO)+" is a disciple of the Dark Side of the Force" ;
             break;
        case "nasty":
             m+=CAP(environment()->PRO)+" is beginning to turn toward the Dark Side of the Force";
             break;
        case "neutral":
             m+="You sense balance and oneness with the Force in "+environment()->OBJ;
             break;
        case "nice":
             m+=CAP(environment()->PRO)+" adheres to the Code of the Light Side of the Force";
             break;
        case "good":
             m+="You have a sense of goodness and great Force about "+environment()->OBJ;
             break;
        case "saintly":
             m+=CAP(environment()->PRO)+" emanates goodness and the power of the Light Side of the Force";
             break;
        default : ;
    }
    return m;
}
