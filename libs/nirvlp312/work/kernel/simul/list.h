varargs mixed make_list(string *items,mixed alternative,string and,
                        string comma);
varargs mapping factorize(mixed *tokens,closure f,mixed *args);
varargs string *describe_list(mixed ob,mixed article,int full,status poss,
                              closure desc);
varargs string describe_heap(mapping m,string name,string *order,
                             int threshold);

