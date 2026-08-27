int atoi(string a)
{
        int i;
        sscanf(a,"%d",i);
        return i;
}

int *classify_number(string arg)
{
        int *result;
        string *exps;
        result = ({ 0,0,0,0,0,0,0 });
        exps = explode(arg, ";");

        for(int x=0;x<sizeof(exps);x++)
                if( atoi(exps[x]) >= 0 && atoi(exps[x]) <= 5 && atoi(exps[x]) != 3 ) result[atoi(exps[x])] = 1;
                else if( atoi(exps[x]) >= 30 && atoi(exps[x]) <= 37 ) result[3] = atoi(exps[x]);
                else if( atoi(exps[x]) >= 40 && atoi(exps[x]) <= 47 ) result[6] = atoi(exps[x]);
        return result;
}

string pansi(string sor)
{
        int *now, *proc, i, flag;
        string t1, t2, exp, result = "", *arg;

        flag = 0;
        now = ({ 0,0,0,0,0,0,0 });
        proc = ({ 0,0,0,0,0,0,0 });
        arg = explode(sor, "\x1b");
        if( sizeof(arg) < 2 ) return sor;

        for(int x=0;x<sizeof(arg);x++, flag=0)
        {
                printf("Process: %s\n", arg[x]);
                if( sscanf(arg[x], "[%sm%s", t1, t2) == 2 )
                {
                        if( t2 == "" )
                        {
                                now = classify_number(t1);
                                //
                                for(int g=0;g<sizeof(now);g++)
                                        printf("%d ", now[g]);
                                printf("AA\n");
                                //
                                continue;
                        }
                        proc = classify_number(t1);
                        now[0] = proc[0] || now[0];
                        now[1] = proc[1] || now[1];
                        now[2] = proc[2] || now[2];
                        now[4] = proc[5] || now[4];
                        now[5] = proc[5] || now[5];
                        
                        now[3] = (proc[3])? proc[3]: now[3];
                        now[6] = (proc[6])? proc[6]: now[6];

                        //
                        for(int g=0;g<sizeof(now);g++)
                                printf("%d ", now[g]);
                        printf("BB%s\n",t2);
                        //
                }
                else {
                        result += arg[x];
                }
                for(int t=0;t<sizeof(now);t++)
                        if( now[t] == 1 )
                        {
                                if( !flag )
                                {
                                        flag = 1;
                                        result += "[";
                                }
                                result += ";"+t;
                        }
                        else if( now[t] )
                        {
                                if( !flag )
                                {
                                        flag = 1;
                                        result += "[";
                                }
                                result += ";"+now[t];
                        }

                if( flag ) result += "m";
                result += t2;
        }
        return result;
}
