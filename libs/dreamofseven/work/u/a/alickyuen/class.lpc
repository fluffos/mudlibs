inherit F_SAVE;
function func = (: write, "test save" :);


string query_save_file()
{return "/u/a/alickyuen/class.o";}
class test
{
float a;
int i;
string str;
mapping m;
array ar;
object ob;
function fun;
}

void create()
{
class test t = new(class test); 
t->a = 1.111;
t->i = 1;
t->str = "test";
t->m = (["test" : "test"]);
t->ar = ({ 1,2,"test" });
t->ob = load_object("/obj/money/coin");
t->fun = (: write, "test fun" :);
printf("%O\n", t);
}
