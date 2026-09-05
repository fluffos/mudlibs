mixed r_w_r,r_w_c;
object r_w_t,r_w_n;
activate_robe_watch(ob)
{
	r_w_t = ob;
	r_w_n = previous_object();
	return shadow (ob,1);
}
add_amount(v1,v2,v3)
{
	r_w_c = catch(r_w_r = r_w_t->add_amount(v1,v2,v3));
	if (r_w_n)
		r_w_n->collect_watch_results(({ r_w_t,"add_amount",r_w_r,r_w_c,v1,v2,v3}) );
	else
		destruct(this_object());
	return r_w_r;
}
