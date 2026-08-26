#ifndef __SEFUN_NUMBERS_H__
#define __SEFUN_NUMBERS_H__
#define NUMBERS ({"no", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"})
#define TENS ({"no", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"})
#endif

string formal_number(int i) {
    string tmp=(""+i)[<1..<1], ret="";
    if(i>99) return "dozens";
    switch (i) {
    case(11) : return "eleven"; break;
    case(12) : return "twelve"; break;
    case(13) : return "thirteen"; break;
    case(14) : return "fourteen"; break;
    case(15) : return "fifteen"; break;
    case(16) : return "sixteen"; break;
    case(17) : return "seventeen"; break;
    case(18) : return "eightteen"; break;
    case(19) : return "ninteen"; break;
    default :
        if(tmp!="0") ret=(i>10?"-":"")+NUMBERS[to_int(tmp)];
        i=i/10;
        return (i?TENS[i]:"")+ret;
    }
    return "some";
}

string ordinal(int i) {
    string tmp=(""+i)[<1..<1];
    if(i==11 || i==12 || i==13) return ""+i+"th";
    if(tmp=="1") return ""+i+"st";
    if(tmp=="2") return ""+i+"nd";
    if(tmp=="3") return ""+i+"rd";
    return ""+i+"th";
}

string plural(string str) {
    mapping special=(["moose":"moose","mouse":"mice",]);
    if(special[str]) return special[str];
    else return str+"s";
}

string consolidate(int i, string item, int a) {
    string *words;
    string word, p;
    int x,y;
    if(i==1 && a) return "a "+item;
    if(i==1) return item;
    words=explode(item, " ");
    if(member_array(words[0],({"a","A","The","the"}))!=-1) {
        item=implode(words[1..<1]," ");
        words=explode(item, " ");
    }
    x=sizeof(words)-1;
    while (x && words[x][0..0]=="(") x--;
    if(y=member_array("of",words)) if(y>0) x=y-1;
    word=words[x];
    p=formal_number(i);
    words[x]=plural(word);
    return (a && i>8 ? "many" : p)+" "+implode(words," ");
}
