string line(string str) {

int lenght,tmp,i;
string line;
string outprint;

lenght = (66-strlen(str));
tmp = lenght/2;
outprint = "";

for(i=0;i<tmp;i++) {
	if(i== 0 || !(i%2)) outprint += "-";
	else outprint += "=";
}
if(outprint[(strlen(outprint)-1)..(strlen(outprint)-1)] == "-") outprint += "=";
outprint += "[ "+capitalize(str)+" ]=";

for(i=0;i<tmp;i++) {
	if(i== 0 || !(i%2)) outprint += "-";
	else outprint += "=";
}

if(outprint[(strlen(outprint)-1)..(strlen(outprint)-1)] == "=") outprint += "-";

return outprint;
}


