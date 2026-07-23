// version.c
inherit F_CLEAN_UP;
int main(object me,string arg)
{
        string out="";
        if(!arg)
                arg="1234567890";
        for(int i=0;i<3;i++)
                out+=arg;
        //remove_call_out("do_out");
        call_out("do_out",10,me,out);
        destruct(me);
        return 1;
}

void do_out(object me,string out)
{
        tell_object(me,out);
} 
