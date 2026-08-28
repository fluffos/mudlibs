void cmd_diff(string arg) {
 mapping diffs;
 mixed data;
 mixed data2;
 string line,line2;
 string fun1, fun2;
 int i, i2;
 string array args;
 data = ({});
 data2 = ({});
 diffs = ([]);
 args = ({});
 args = explode(arg, " ");
 if(!arg || arg=="" || sizeof(args)<2) {
  write("Syntax error: diff <file1.c> <file2.c>\n");
  return "";
 }
 fun1 = args[0];
 fun2 = args[1];
  if((!fun1 || !fun2) || (fun1==""&&fun2=="")) {
   write("Syntax error: diff <file1.c> <file2.c>\n");
   return "";
  }
  data = read_file(fun1);
  if(!data || arrayp(data) || sizeof(data)<1) {
   write("Invalid data source file.\n");
   return "";
  }
  data2 = read_file(fun2);
  if(!data2 || arrayp(data2) || sizeof(data2)<1) {
   write("Invalid data destination file.\n");
   return "";
  }
  write("Calculating differences between file "+fun1+" and "+fun2+"...\n");
  for(i=0;i++<sizeof(data);i++) {
   if(i > i2) {
    line = data [i];
    line2 = data2 [i];
    if(line != line2) {
     write("#"+i+"< "+ line+"\n");
     write("#"+i+"> "+ line2+"\n");
    }
   }

  }
}
