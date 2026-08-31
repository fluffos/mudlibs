#ifndef __LOCALTIME_H__

#define __LOCALTIME_H__

string localTime() {
    string sMod;
    int iAdd,iTime;
    object oTp;

    oTp=(this_player()?this_player():previous_object());
    iTime=time()+2430;
    sMod=(string)oTp->queryenv("TIMEDIFF");
    if(!sMod)
        sMod="";

    if(sscanf(sMod,"+%d%s",iAdd,sMod)==2) {
        switch(sMod) {
            case "h":
                iAdd*=60;
            case "m":
                iAdd*=60;
            case "s":
                break;
            default:
                return "Unknown time modifier: "+sMod;
                break;
        }
        iTime+=iAdd;
    }
    else if(sscanf(sMod,"-%d%s",iAdd,sMod)==2) {
        switch(sMod) {
            case "h":
                iAdd*=60;
            case "m":
                iAdd*=60;
            case "s":
                break;
            default:
                return "Unknown time modifier: "+sMod;
                break;
        }
        iTime-=iAdd;
    }
    return ctime(iTime);
}

#endif // __LOCALTIME_H__
