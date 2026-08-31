
int preparing,timeslight,lightdam;
object *di;

int light_heart();
int free(string str);
int do_free(string str);
int spread(string str);
int do_spread(string str);
void lightReset();
int lightS();
int lightD();
int lightT();
int light_all();

int prepare(string str) {

    if(str!="lightning") return 1;
    if(preparing) {
        write("You are already preparing a lightning.\n");
        return 1;
    }
    write("You concentrate the Force on your hands.\n");
    preparing=1;
    light_heart();
    return 1;
}

int light_heart() {

    int dam;

    timeslight++;
    if(timeslight+1>=lightT()) {
        write("You'd better free the energy.\n");
    }
    if(timeslight>lightT() && !random(TP->query_wis()/3)) {
        write("You free the energy uncontrolled and hurt yourself.\n");
        TP->hit_player(lightdam/10+5,7,0);
        lightReset();
        return 1;
    }
    dam = lightD()+random(8);
//if(TP->RNAME == "mangla")
    lightdam += dam;
    if(TP->query_sp()-dam/2<0) {
        write("You are low at mental energy.\n");
        lightdam = 0;
        free("lightning");
        return 1;
    }

    TP->ADDSP(-dam/2);
    write("You feel the energy rising.\n");
    call_out("light_heart",lightS());
}

int free(string str) {

    if(find_call_out("do_free")!=-1) return 1;
    if(find_call_out("do_spread")!=-1) return 1;
    call_out("do_free", 1, str);
    return 1;
}

int do_free(string str) {

    string what,pro,whom;
    object att;
    int i;

    if(ENV(TP)->query_property("no_fight")) {
        write("You are not allowed to fighgt here!\n");
        return 1;
    }
    if(str=="lightning") att=TP->query_attack();
    else {
        if(!str || sscanf(str,"%s %s %s",what,pro,whom)!=3) return 1;
        if(what!="lightning" && pro!="at" && pro!="to") return 1;
        att=present(whom,ENV(TP));
    }
    if(!att) {
        if(!preparing) {
            write("Bolts of electricity swirl around your fingers.\n");
            say("Bolts of electricity swirl around "+TP->NAME+"'s fingers.\n");
            return 1;
        }
        write("You free the energy.\n");
        say(TP->NAME+" fills the area with a lightning effect.\n"+
            "It only lasts for a second, but nevertheless it is very strong.\n");
        light_all();
        if(present("corpse",ENV(TP))) {
            i=0;
            while(att=present("corpse",ENV(TP))) {
                destruct(att);
                i++;
            }
            if(i==1) {
                write("The corpse falls to ashes.\n");
                say("The corpse falls to ashes.\n");
            }
            else {
                write(i +" corpses falls to ashes.\n");
                say(i +" corpses falls to ashes.\n");
            }
        }
        lightReset();
        return 1;
    }
    if(!living(att)) {
        write("That would have no effect.\n");
        return 1;
    }
    if(!preparing) {
        write("You throw non-harmful lighting at "+att->query_name()+".\n");
        say(TP->NAME+" throws a non-harmful lightning at "+att->query_name()+".\n"+
            CAP(TP->PRO)+ " glows for a second.\n");
        tell_object(att,TP->NAME+" throws non-harmful lightning at you.\n"+
                "You glow for a second.\n");
        return 1;
    }
    write("You stretch forth your hands and lightning strikes out of them "+
          "towards "+ att->NAME+".\n");
    say(TP->NAME+" stretches forth "+TP->POS+" hands and strikes "+att->NAME+
        " with lightning.\n",att);
    TELL(att,TP->NAME+" stretches forth "+TP->POS+" hands and throws lightning "+
                "at you.\n");
    att->hit_player(lightdam,5,0);
    lightReset();
/*
    if(TP->query_sp() < lightdam) {
        printf("You feel completely drained.\n");
        TP->ADDSP(-TP->SP);
    }
    else {
        TP->ADDSP(-lightdam/2);
    }
*/
    return 1;
}

int spread(string str) {

    if(str == "lightning") {
        if(find_call_out("do_free")!=-1) return 1;
        if(find_call_out("do_spread")!=-1) return 1;
        call_out("do_spread", 1, str);
        return 1;
    }
    return 0;
}

int do_spread(string str) {

    object *ob,*gr;
    int i,j,enemys,dam;

    if(ENV(TP)->query_property("no_fight")) {
        write("You are not allowed to fight here!\n");
        return 1;
    }
    if(str!="lightning") return 1;
    if(!preparing) {
        write("That would have no effect.\n");
        return 1;
    }
    write("You quickly turn around spreading the lightning all across the area.\n");
    say(TP->NAME+" turns around a spreads a lightning all across the area.\n");

    enemys = 0;
    ob=all_inventory(ENV(TP));
    gr = TP->grmems_in_room();
    for (i=0,j=sizeof(ob); i < j; i++) {
        if ((ob[i]->query_npc() || ob[i]->query_player())
            && ob[i]->query_guild()!=4 && ob[i]!=TP && member_array(ob[i],gr)==-1) {
            enemys++;
        }
    }

    if(!enemys) dam=0;
    else dam=3*lightdam/enemys/2+random(7);

    for(i=0;i<sizeof(ob);i++)
        if((ob[i]->query_npc() || ob[i]->query_player()) &&
            ob[i]->query_guild()!=4 && ob[i]!=TP && member_array(ob[i],gr)==-1) {
    if((ENV(ob[i]))->query_property("no_fight")) {
        write("You are not allowed to fight here!\n");
        return 1;
    }
write("TEST\n");
            write(ob[i]->query_name()+" has been hit.\n");
            ob[i]->hit_player(dam,5,0);
        }
    lightReset();
/*
    if(TP->query_sp() < dam/4) {
        printf("You feel completely drained.\n");
        TP->ADDSP(-TP->SP);
    }
    else {
        TP->ADDSP(-dam);
    }
*/
    return 1;
}

void lightReset() {

    remove_call_out("light_heart");
    preparing = 0;
    timeslight = 0;
    lightdam = 0;
}

int lightS() {

    if(TPL<10) return 6;
    if(TPL<20) return 4;
    return 2;
}
int lightD() {

    if(TP->query_legend_level())
        return 17 + (TP->query_legend_level() * (random(5) + 1));
    if(TPL<10) return 7;
    if(TPL<15) return 9;
    if(TPL<20) return 12;
    if(TPL<25) return 15;
    return 17;
}

int lightT() {

    if(TPL<4 ) return 4;
    if(TPL<10) return 5;
    if(TPL<13) return 7;
    if(TPL<20) return 9;
    return 12;
}

int light_all() {

    int i;

    i=0;
    di=deep_inventory(ENV(TP));
    for(i=0;i<sizeof(di);i++)
        if(di[i]->id("can_light"))
            if(di[i]->out(1)) ;
}

