mixed r_w_r,r_w_c;
object r_w_t,r_w_n;
activate_robe_watch(ob)
{
	r_w_t = ob;
	r_w_n = previous_object();
	return shadow (ob,1);
}
set_notify_fail(v0,v1)
{
	r_w_c = catch(r_w_r = r_w_t->set_notify_fail(v0,v1));
	if (r_w_n)
		r_w_n->collect_watch_results( ({ r_w_t,"set_notify_fail",r_w_r,r_w_c,v0,v1}) );
	else
		destruct(this_object());
	return r_w_r;
}
