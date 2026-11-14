/*************************************************************************/
/* properties */

/*
 set_prop(), query_prop() enables you to give attributes to an object.
 If the object already expresses those attributes as functions then it will
 call those. However, it should not be used extensively to set, and query
 functions for two reasons. Firstly, they are more cpu intensive; Secondly,
 any syntactically incorrect (mispelled) properties are not easily
 detected.
 */

mixed *properties;


mixed *query_properties() { return properties + ({}); }


varargs void set_prop(mixed prop, mixed arg1, mixed arg2) {
  int i;

  if(!prop || prop == "prop") return;
  if(pointerp(prop)) {
    while(i < sizeof(prop)-1) set_prop(prop[i++],prop[i++]);
    return;
  }
  if(function_exists("set_"+prop,this_object())) {
    call_other(this_object(),"set_"+prop,arg1,arg2);
  }
  else { /* 2nd arg drops out here */
    if(!properties) properties = ({});
    if((i = member_array(prop,properties)) == -1) {
      properties += ({ prop, arg1, });
    }
    else {
      properties[i+1] = arg1;
      if(!arg1) { 
        properties = properties[0..(i-1)]
                   + properties[(i+2)..(sizeof(properties)-1)];
      }
    }
  }
} 


varargs mixed query_prop(string prop, mixed arg1, mixed arg2) {
  int i;

  if(!prop || prop == "prop") return;
  if(function_exists("query_"+prop,this_object())) {
    return (mixed)call_other(this_object(),"query_"+prop, arg1, arg2);
  }
  else {  /* arg1 & arg2 drop out here */
    if(!properties) properties = ({});
    if((i = member_array(prop,properties)) != -1) return properties[i+1];
  }
  return 0;
} 
