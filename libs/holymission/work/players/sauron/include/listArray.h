#ifndef __LISTARRAY_H__

#define __LISTARRAY_H__
string *capArray(string *saArr);
varargs string listArray(string *saList,int iSep,int iFlag);

string *capArray(string *saArr) {
    int i,iSz;

    if(!pointerp(saArr))
        return ({});
    else if(!(iSz=sizeof(saArr)))
        return saArr;
    else {
        for(i=0;i<iSz;i++)
            saArr[i]=capitalize(saArr[i]);
    }
    return saArr;
}

varargs string listArray(string *saList,int iSep,int iFlag) {

// Final separator is "and" by default - if iSep == 1, "or" i used.
// NB. iFlag = 0 -> unordered, uncap list
//     iFlag = 1 -> ordered, uncap list
//     iFlag = 2 -> unordered, cap list
//     iFlag = 3 -> ordered, cap list

    string sRet;
    int i,iSz;

    iSz=sizeof(saList);
    if(iFlag%2)
        saList=sort_array(saList,#'>);
    if(iFlag/2)
        saList=capArray(saList);
    switch(iSz) {
        case 0:
            return "";
            break;
        case 1:
            return saList[0]+".";
            break;
        case 2:
            return saList[0]+(iSep?" or ":" and ")+saList[1]+".";
            break;
        default:
            sRet="";
            for(i=0;i<iSz-2;i++)
                sRet+=saList[i]+", ";
            return sRet+saList[iSz-2]+(iSep?" or ":" and ")+saList[iSz-1]+".";
          break;
    }
}

#endif // __LISTARRAY_H__
