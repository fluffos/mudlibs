int low_parry(string str) {

    if(str!="parry") return 0;
    if(!arm_obj) return 0;
    arm_obj->stop();
    TELL(TP,"You stop your parrying.\n");
    parrying=0;
    lastparry=time();
    remove_call_out("parry_heart");
    return 1;
}


int parry_heart() {

    if(TP->SP <= PARRYRANGE || !TP->query_wielded()) {
        low_parry("parry");
        return 1;
    }
    TP->ADDSP(-5);
    call_out("parry_heart",10);
        return 1;
}

int parry() {

    int cost,armor,retime;

    if(!TP->query_wielded()) {
        write("You are not wielding a weapon.\n");
        return 1;
    }
    if(parrying) {
        write("You are already parrying.\n");
        return 1;
    }
    if(time()-lastparry<PARRYTIME) {
        write("You have to wait for a while.\n");
        return 1;
    }
    write("You start your parrying.\n");
    armor=TP->DEX/5+3+TPL/10;
    arm_obj=clone_object("players/mangla/guild/parryarmor");
    arm_obj->set_ac(armor);
    transfer(arm_obj,TP);
    TP->wear(arm_obj);
    retime=60+TPL*3+TPL*2;
    parrying=1;
    parry_heart();
    return 1;
}

