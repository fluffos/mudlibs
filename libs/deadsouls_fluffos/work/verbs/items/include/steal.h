#ifndef l_steal_h
#define l_steal_h

protected void create();

mixed can_steal_wrd_from_liv(string wrd);
mixed can_steal_obj_from_liv();

mixed do_steal_wrd_from_liv(string wrd, object liv);
mixed do_steal_obj_from_liv(object ob, object liv);
mixed do_steal_obs_from_liv(mixed *res, object liv);

protected void eventSteal(object who, mixed what, object liv);

#endif /* l_steal_h */
