string toh(int x)
{
        if( x<10 ) return int_to_str(x);
        else if( x== 10) return "A";
        else if( x== 11) return "B";
        else if( x== 12) return "C";
        else if( x== 13) return "D";
        else if( x== 14) return "E";
        else if( x== 15) return "F";
}

string z2c(string msg)
{
        int i;
        string result="";

        for(i=0;i<sizeof(msg);i++) {
                if( (msg[i] >47 && msg[i]<58)||(msg[i] >65 && msg[i]<123) ) 
                        result+=msg[i..i]; 
                else {
                        result += "%" + toh(msg[i]/16) + toh(msg[i]%16);
                }
        }
        return result;  
}

int hot(string arg)
{
        if( arg == "A" ) return 10;
        else if( arg == "B" ) return 11;
        else if( arg == "C" ) return 12;
        else if( arg == "D" ) return 13;
        else if( arg == "E" ) return 14;
        else if( arg == "F" ) return 15;
        else if( arg == "0" ) return 0;
        else if( arg == "1" ) return 1;
        else if( arg == "2" ) return 2;
        else if( arg == "3" ) return 3;
        else if( arg == "4" ) return 4;
        else if( arg == "5" ) return 5;
        else if( arg == "6" ) return 6;
        else if( arg == "7" ) return 7;
        else if( arg == "8" ) return 8;
        else if( arg == "9" ) return 9;
}

string c2z(string arg)
{
        int i, index1,index2,index;
        string result="",a="a";

        for(i=0;i<sizeof(arg);i++) {
                if( arg[i]=='%' ){
                        index1 = hot(arg[i+1..i+1]);
                        index2 = hot(arg[i+2..i+2]);
                        index = index1 * 16 + index2;
                        a[0]=index;
                        result += a;
                        i+=2;
                } else result += arg[i..i];
        }
        return result;  

}
