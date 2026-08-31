string crazyString(string sStr) {
    int i,iLen,iCount;

    sStr=lower_case(sStr);
    iLen=strlen(sStr);
    iCount=0;
    for(i=0;i<iLen;i++) {
        if(sStr[i]>='a' && sStr[i]<='z') {
            if(!(iCount%2))
                sStr[i]-=32;
            iCount++;
        }
    }

    return sStr;
}
