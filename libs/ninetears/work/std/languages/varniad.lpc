string garbler(string mess);

string long(){
    return "Vuzzrnkrkuzzd luzzngfuzzgss.\n";
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
    mess=implode(explode(mess,"a"),"uzz");
    mess=implode(explode(mess,"A"),"Uzz");
    mess=implode(explode(mess,"e"),"ss");
    mess=implode(explode(mess,"E"),"Ss");
    mess=implode(explode(mess,"i"),"krk");
    mess=implode(explode(mess,"I"),"Krk");
    mess=implode(explode(mess,"o"),"trr");
    mess=implode(explode(mess,"O"),"Trr");
    mess=implode(explode(mess,"u"),"f");
    mess=implode(explode(mess,"U"),"F");
    return capitalize(mess);
}
