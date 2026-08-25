string garbler(string mess);

string long(){
    return "Blubb?\n";
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
    mess=implode(explode(mess,"a"),"u");
    mess=implode(explode(mess,"A"),"U");
    mess=implode(explode(mess,"E"),"V");
    mess=implode(explode(mess,"e"),"v");
    mess=implode(explode(mess,"i"),"o");
    mess=implode(explode(mess,"I"),"O");
    mess=implode(explode(mess,"r"),"b");
    mess=implode(explode(mess,"R"),"B");
    mess=implode(explode(mess,"k"),"l");
    mess=implode(explode(mess,"K"),"L");
    mess=implode(explode(mess,"T"),"L");
    mess=implode(explode(mess,"t"),"l");
    mess=implode(explode(mess,"s"),"ll");
    mess=implode(explode(mess,"S"),"Ll");
    mess=implode(explode(mess,"n"),"u");
    mess=implode(explode(mess,"N"),"U");
    return capitalize(mess);
}
