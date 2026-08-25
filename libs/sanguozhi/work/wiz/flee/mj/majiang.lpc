#include <mudlib.h>
#include <ansi.h>

private mapping *P, *P1, *P2, *P3, *P4;
private mapping *W, *W1, *W2, *W3, *W4;
private mapping Pai;
private mapping Playerp, Playerw;

void sort_pai(mapping *ptemp);
void init_table(string o1, string o2, string o3, string o4);
string look_pai(mapping *ptemp);
string get_first(mapping ptemp);
string get_second(mapping ptemp);

void sort_pai(mapping *ptemp)
{
	int i, n, m;
        mapping pai1, pai2, pp;

        m = sizeof( ptemp );
        for(n = 0; n < (m - 1); n++)
        	for(i = 0; i < (m - n - 1); i++){
                	pai1 = ptemp[i];
                	pai2 = ptemp[i+1];
                	if(pai1["m"] > pai2["m"]){
                        	pp = ptemp[i];
                        	ptemp[i] = ptemp[i+1];
                        	ptemp[i+1] = pp;	
			};
	};	
}
void init_table(string o1, string o2, string o3, string o4)
{
	int i, j ,k ,l ,m;

	P = ({ }); P1 = ({ }); P2 = ({ }); P3 = ({ }); P4 = ({ });
	W = ({ }); W1 = ({ }); W2 = ({ }); W3 = ({ }); W4 = ({ });
	
        for(j = 0; j < 4; j++)
                for(k = 0; k < 9; k++)
                        for(l = 0; l < 4 ;l++){
                                m++;
                                Pai = (["row":j,"col":k,"deep":l,"m":m,]);
                                P = P + ({ Pai });
	};

	Pai = ([ ]);
	Playerp = ([o1:P1, o2:P2, o3:P3, o4:P4]);
	Playerw = ([o1:W1, o2:W2, o3:W3, o4:W4]);

	for( j = 0; j < 4; j++)
                for( i = 0; i < 13; i++){
                        Pai = P[random(sizeof(P))];
                        P = P - ({ Pai });
                        if( j == 1 )	 P1 = P1 + ({ Pai });
                        else if( j == 2) P2 = P2 + ({ Pai });
                        else if( j == 3) P3 = P3 + ({ Pai });
                        else 		 P4 = P4 + ({ Pai });
        };
	
	for( i = 0; i < sizeof(Playerp); i++ ) sort_pai(values(Playerp)[i]);
	
}	
string look_pai(mapping *ptemp)
{
	int i,k,j;
        string str;

        k = sizeof(ptemp);
        str = "\n";
        for(j = 0; j < (int)(k/10)+1; j++){
                for(i = j*10; i < ( (j+1)*10 > k ? k : (j+1)*10 ); i++)
                        str = str + "【"+get_first( ptemp[i] )+"】";
                str = str + "\n";
                for(i = j*10; i < ( (j+1)*10 > k ? k : (j+1)*10 ); i++)
                        str = str + "【"+get_second( ptemp[i] )+"】";
                str = str + "\n";
                for(i = j*10; i < ( (j+1)*10 > k ? k : (j+1)*10 ); i++)
		str = str+"  "+((i + 1)>9?(i+1+""):((i+1)+" "))+"  ";
                str = str + "\n";
        };
       
        return str;
}
string get_first(mapping ptemp)
{
        if( ptemp["row"] == 3 ){
                if( ptemp["col"] == 0) return HIW"白"NOR;
                else if( ptemp["col"] == 1) return HIR"红"NOR;
                else if( ptemp["col"] == 2) return HIG"绿"NOR;
                else if( ptemp["col"] == 3) return HIY"东"NOR;
                else if( ptemp["col"] == 4) return HIY"西"NOR;
                else if( ptemp["col"] == 5) return HIY"南"NOR;
                else if( ptemp["col"] == 6) return HIY"北"NOR;
                else {
                        if( ptemp["col"] == 7){
                        if( ptemp["deep"] == 0)return HIY"春"NOR;
                        else if( ptemp["deep"] == 1)return HIY"夏"NOR;
                        else if( ptemp["deep"] == 2)return HIY"秋"NOR;
                        else return HIY"冬"NOR;
                        } else {
                                if( ptemp["deep"] == 0)return HIY"梅"NOR;
                                else if( ptemp["deep"] == 1)return HIY"兰"NOR;
                                else if( ptemp["deep"] == 2)return HIY"竹"NOR;
                                else return HIY"菊"NOR;
                        };
                };
        };
        return chinese_number( ptemp["col"]+1 );
}
string get_second(mapping ptemp)
{
        if( ptemp["row"] == 0 )return HIR"饼"NOR;
        else if( ptemp["row"] == 1 )return HIG"条"NOR;
        else if( ptemp["row"] == 2 )return HIC"万"NOR;
        else {
                if( ptemp["col"] == 0) return HIW"板"NOR;
                else if( ptemp["col"] == 1) return HIR"中"NOR;
                else if( ptemp["col"] == 2) return HIG"发"NOR;
                else if( ptemp["col"] == 3) return HIY"风"NOR;
                else if( ptemp["col"] == 4) return HIY"风"NOR;
                else if( ptemp["col"] == 5) return HIY"风"NOR;
                else if( ptemp["col"] == 6) return HIY"风"NOR;
                else {
                        if( ptemp["col"] == 7){
                                if( ptemp["deep"] == 0)return HIY"春"NOR;
                                else if( ptemp["deep"] == 1)return HIY"夏"NOR;
                                else if( ptemp["deep"] == 2)return HIY"秋"NOR;
                                else return HIY"冬"NOR;
                        } else {
                                if( ptemp["deep"] == 0)return HIY"梅"NOR;
                                else if( ptemp["deep"] == 1)return HIY"兰"NOR;
                                else if( ptemp["deep"] == 2)return HIY"竹"NOR;
                                else return HIY"菊"NOR;
                        };
                };
        };
  return "  ";
}
