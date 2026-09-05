mixed *exclude_array(mixed *arr,int from,int to);
mixed *exclude_element(mixed *arr,int index);
mixed *merge_array(mixed *arr);
mixed *split_array(mixed *arr,int mod);
varargs mixed *flatten_array(mixed *arr,status recursive);
mixed turn_array(mixed m);
mixed shuffle_array(mixed m);
varargs mixed find_extreme(mixed *m,closure c,mixed extra);
varargs mixed find_map_extreme(mixed *m,closure map,closure c,mixed extra);
varargs mixed find_element(mixed m,closure c,int i,mixed extra);
varargs mixed find_last_element(mixed m,closure c,int i,mixed extra);
varargs mixed *sort_map_array(mixed *Arr,mixed a,mixed b,mixed c,mixed d,
                              mixed extra);
varargs object *sort_objects(object *os,string lfun,closure sortfun,
                             mixed extra);
mapping count_elements(mixed *arr);

