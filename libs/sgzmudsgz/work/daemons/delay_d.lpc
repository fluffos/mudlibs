//delay_d.c by fire on Jan 1999
// this is used to handle dealy action
void d_t_a(mixed par)
{
   if(!objectp(par[0])) return;
   if(!objectp(par[1])) return;
   if(!objectp(par[0]->query_body())) return;
   if(!objectp(par[1]->query_body())) return;

   par[0]->targetted_action(par[2],par[1]);

}
void delay_targetted_action(object me,object tar,string s,int t)
{
	call_out("d_t_a",t,({me,tar,s}));
}

void d_s_a(mixed par)
{
   if(!objectp(par[0])) return;
   if(!objectp(par[0]->query_body())) return;
   par[0]->simple_action(par[1]);

}
void delay_simple_action(object me,string s,int t)
{
	call_out("d_s_a",t,({me,s}));
}


void d_e_a(mixed par) {
	if(sizeof(par)<2) return;
	if(!objectp(par[0])) return;
	par[0]->responda(par[1]);
}
// this can be used not only for emote, but for real action too
void delay_emote(object me, string emt,int t, string t_id) {
	if(stringp(t_id)&&(sizeof(t_id)))
		emt=emt+" "+t_id;
	call_out("d_e_a",t,({me, emt }));
}