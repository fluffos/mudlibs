string garbler(string mess);

string long(){
    return "Shouting giants...\n";
}

mixed garble_say(string start, string mess){
    mess=garbler(mess);
    return({start,mess});
}

mixed garble_shout(string start, string mess, string nam, string loud){
    mess=garbler(mess);
    return ({start,mess});
}

string garbler(string mess){
    mess=lower_case(mess);
    mess=implode(explode(mess,"an"),"okk");
    mess=implode(explode(mess,"An"),"Okk");
    mess=implode(explode(mess,"au"),"ook");
    mess=implode(explode(mess,"Au"),"Ook");
    mess=implode(explode(mess,"a"),"o");
    mess=implode(explode(mess,"A"),"O");
    mess=implode(explode(mess,"en"),"ekk");
    mess=implode(explode(mess,"ew"),"et");
    mess=implode(explode(mess,"ir"),"eer");
    mess=implode(explode(mess,"i"),"ee");
    mess=implode(explode(mess,"ow"),"ot");
    mess=implode(explode(mess,"o"),"oo");
    mess=implode(explode(mess,"O"),"Oo");
    mess=implode(explode(mess,"the"),"kre");
    mess=implode(explode(mess,"The"),"Kre");
    mess=implode(explode(mess,"th"),"kr");
    mess=implode(explode(mess,"tion"),"oon");
    mess=implode(explode(mess,"v"),"f");
    mess=implode(explode(mess,"V"),"F");
    mess=upper_case(mess);
    return capitalize(mess);
}
