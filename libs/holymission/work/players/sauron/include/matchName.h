#ifndef __MATCHNAME_H__

#define __MATCHNAME_H__

#ifndef __SAURON_INCLUDE_H__

#include "/sys/include/sys_defs.h"

#endif // SAURON_INCLUDE_H__

string getName(object oOb) {
    return oOb->query_real_name();
}

varargs string matchName(string sName,int iFlag,object *oaArr) {
    string sTmp,*saTmp;
    int i,iLen,iSz;

    if(!sName || sName=="")
        return 0;
    else
        iLen=strlen(sName)-1;
    sTmp=sName;
    sName=lower_case(sName);
    saTmp=({});
    i=0;
    if(!iFlag)
        oaArr=users();
    else if(iFlag==1)
        oaArr=filter_array(ALL(ENV(TP)),(: interactive :));
    else if(iFlag==2)
        oaArr=filter_array(ALL(ENV(TP)),(: living :));
    else if(iFlag!=3)
        return 0;

#ifdef DEBUG
    printf("Matching name '%s' from list '%s'.\n",sName,
           listArray(map_array(oaArr,"getName",this_object()),1)[0..<2]);
#endif // DEBUG

    iSz=sizeof(oaArr);
    for(i=0;i<iSz;i++) {
        if(oaArr[i]->query_real_name()[0..iLen]==sName)
            saTmp+=({oaArr[i]->query_real_name()});
    }

    if(sizeof(saTmp)==1)
        return saTmp[0];
    else if(sizeof(saTmp))
        printf("The name \"%s\" is ambiguous (\"%s\"). Please be more \
precise.\n",
               sName,listArray(saTmp,1));
    else
        printf("No-one found to match '%s'.\n",sName);
}

#endif // __MATCHNAME_H__
