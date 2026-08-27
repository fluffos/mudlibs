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
    mess=implode(explode(mess,"an"),"ann");
    mess=implode(explode(mess,"An"),"Ann");
    mess=implode(explode(mess,"au"),"ai");
    mess=implode(explode(mess,"Au"),"Ai");
    mess=implode(explode(mess,"en"),"ern");
    mess=implode(explode(mess,"En"),"Ern");
    mess=implode(explode(mess,"ew"),"ef");
    mess=implode(explode(mess,"ir"),"iir");
    mess=implode(explode(mess,"i"),"ir");
    mess=implode(explode(mess,"ow"),"orr");
    mess=implode(explode(mess,"o"),"oo");
    mess=implode(explode(mess,"O"),"Oo");
    mess=implode(explode(mess,"the"),"rre");
    mess=implode(explode(mess,"The"),"Rre");
    mess=implode(explode(mess,"th"),"rr");
    mess=implode(explode(mess,"tion"),"rron");
    mess=implode(explode(mess,"v"),"iu");
    mess=implode(explode(mess,"V"),"Iu");
    mess=implode(explode(mess,"E"),"Er");
    mess=implode(explode(mess,"e"),"er");
    mess=implode(explode(mess,"t"),"tt");
    mess=implode(explode(mess,"T"),"Tt");
    mess=implode(explode(mess,"m"),"mr");
    mess=implode(explode(mess,"M"),"Mr");
    mess=implode(explode(mess,"st"),"sst");
    mess=implode(explode(mess,"St"),"Sst");
    mess=implode(explode(mess,"d"),"g");
    mess=implode(explode(mess,"y"),"i");
    mess=implode(explode(mess,"Y"),"I");
    mess=implode(explode(mess,"p"),"b");
    mess=implode(explode(mess,"P"),"B");
    mess=implode(explode(mess,"w"),"f");
    return capitalize(mess);
}
