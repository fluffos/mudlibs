string garbler(string mess);

string long(){
    return "Yes, newts can talk too.\n";
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
    mess=implode(explode(mess,"an"),"ass");
    mess=implode(explode(mess,"An"),"Ass");
    mess=implode(explode(mess,"au"),"as");
    mess=implode(explode(mess,"Au"),"As");
    mess=implode(explode(mess,"en"),"ess");
    mess=implode(explode(mess,"ew"),"eu");
    mess=implode(explode(mess,"ir"),"eer");
    mess=implode(explode(mess,"i"),"ee");
    mess=implode(explode(mess,"ow"),"eu");
    mess=implode(explode(mess,"o"),"ee");
    mess=implode(explode(mess,"O"),"Ee");
    mess=implode(explode(mess,"the"),"sse");
    mess=implode(explode(mess,"The"),"Sse");
    mess=implode(explode(mess,"th"),"ss");
    mess=implode(explode(mess,"tion"),"esson");
    mess=implode(explode(mess,"v"),"f");
    mess=implode(explode(mess,"V"),"F");
    mess=implode(explode(mess,"s"),"ss");
    mess=implode(explode(mess,"S"),"Ss");
    mess=implode(explode(mess,"X"),"S");
    mess=implode(explode(mess,"s"),"s");
    mess=implode(explode(mess,"j"),"i");
    mess=implode(explode(mess,"J"),"I");
    mess=implode(explode(mess,"Y"),"I");
    mess=implode(explode(mess,"y"),"i");
    return capitalize(mess);
}
