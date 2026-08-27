string garbler(string mess);

string long(){
    return "A language similar to the giant.\n";
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
    mess=implode(explode(mess,"an"),"og");
    mess=implode(explode(mess,"An"),"Og");
    mess=implode(explode(mess,"au"),"oog");
    mess=implode(explode(mess,"Au"),"Oog");
    mess=implode(explode(mess,"a"),"o");
    mess=implode(explode(mess,"A"),"O");
    mess=implode(explode(mess,"en"),"egg");
    mess=implode(explode(mess,"ew"),"eu");
    mess=implode(explode(mess,"ir"),"eer");
    mess=implode(explode(mess,"i"),"ee");
    mess=implode(explode(mess,"ow"),"ou");
    mess=implode(explode(mess,"o"),"oo");
    mess=implode(explode(mess,"O"),"Oo");
    mess=implode(explode(mess,"the"),"gre");
    mess=implode(explode(mess,"The"),"Gre");
    mess=implode(explode(mess,"th"),"gr");
    mess=implode(explode(mess,"tion"),"oon");
    mess=implode(explode(mess,"v"),"f");
    mess=implode(explode(mess,"V"),"F");
    mess=implode(explode(mess,"k"),"g");
    mess=implode(explode(mess,"K"),"G");
    return capitalize(mess);
}
