string long(){
    return "Rribit?\n";
}

mixed garble_say(string start, string rest){
    string nam, loud;

    sscanf(start, "%s %s:", nam, start);
    if(sscanf(start,"%s loudly",start) ==1)
	loud = " loudly";
    else
	loud = "";
    switch (start){
    case "asks":
	nam = nam+" curiously rribits"+loud;
	break;
    case "shouts asking":
	nam=nam+" curiously rribits"+loud;
	break;
    case "yells":
	nam=nam+" croooaks"+loud;
	break;
    case "asks you":
	nam=nam+" curiously rribits at you"+loud;
	break;
    case "tells you exclaiming":
	nam=nam+" croooaks at you"+loud;
	break;
    case "tells you":
	nam=nam+" rribits at you"+loud;
	break;
    case "exclaims" :
	nam=nam+" croooaks"+loud;
	break;
    default :
	nam = nam+" rribits"+loud;
	break;
    }
    return ({nam+".",""});
}
