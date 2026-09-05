#define ATTRIBUTE_INDEX 2

varargs void add_attribute(string name, mixed value, object ob) {
  mapping attributes;
/** Gnar Testing **/
#if 0
  int i,j;
  mixed *ar;
  mixed *ind;

  write("10\n");
  ar = get_extra_wizinfo(0);
  if( mappingp( ar ) )
    write("Map\n");
  if( pointerp( ar ) ) {
    write("Array\n");
    write("size: " + sizeof(ar)+"\n");
    for( i=0; i < sizeof(ar); i++ ) {
      if( mappingp( ar[i] ) ) {
        write("["+i+"] is a mapping.\n");
        ind = m_indices( ar[i] );
        for(j=0; j < sizeof(ind); j++ ) {
          if( stringp( ind[j] ) )
            write("\t["+j+"]"+ind[j]+"\n");
          if( objectp( ind[j] ) )
            write("\t["+j+"]"+ind[j]->short()+"\n");
        }
      }
    }
  }
  if( mappingp( ar[ATTRIBUTE_INDEX] ) )
    write("Map2\n");
  if( pointerp( ar[ATTRIBUTE_INDEX] ) ) {
    write("Array2\n");
  }
  if( objectp( ar[ATTRIBUTE_INDEX] ) )
    write("Obj2\n");
  if( ar[ATTRIBUTE_INDEX] )
    write("ok\n");
  write("100\n");
#endif
/** Gnar Testing **/

  if (!ob) {
    if (objectp(value)) {
      ob = value;
      value = 1;
    } else {
      ob = previous_object();
    }
  }
  attributes =
     (attributes = get_extra_wizinfo(0)[ATTRIBUTE_INDEX])[ob] ||
     (attributes[ob] = m_allocate(1, 1));
  if (member(attributes, quote(name))) {
    attributes[quote(name)] = value;
    return;
  }
  attributes[name] = value;
}

varargs void add_prot_attribute(string name, mixed value, object ob) {
  mapping attributes;

  if (!ob) {
    if (objectp(value)) {
      ob = value;
      value = 1;
    } else {
      ob = previous_object();
    }
  }
  efun::m_delete(
     ( (attributes = get_extra_wizinfo(0)[ATTRIBUTE_INDEX])[ob] ||
       (attributes[ob] = m_allocate(1, 1)) )
     , name)[quote(name)] = value;
}

varargs void delete_attribute(string name, object ob) {
  mapping attributes;

  if (attributes =
     get_extra_wizinfo(0)[ATTRIBUTE_INDEX][ob || previous_object()]) {
    if (member(attributes, quote(name)))
      raise_error(
         sprintf("Error, cannot delete protected attribute %s.\n", name));
    if (!sizeof(efun::m_delete(attributes, name)))
      efun::m_delete(
         get_extra_wizinfo(0)[ATTRIBUTE_INDEX], ob || previous_object());
  }
}


varargs mixed get_attribute(mixed m, object ob) {
  mapping attributes;

  if (!stringp(m))
    return transpose_array(( {
       m_indices(
          attributes =
             get_extra_wizinfo(0)
                [ATTRIBUTE_INDEX][m || previous_object()] ||
              m_allocate(0, 1)),
              m_values(attributes)
    }) );
  if ((attributes =
     get_extra_wizinfo(0)[ATTRIBUTE_INDEX][ob || previous_object()]) &&
      (m_contains(attributes, m, &m) ||
       m_contains(attributes, quote(m), &m)))
    return m;
  return -1;
}

varargs mixed query_attribute(string m, object ob) {
  mapping attributes;

  attributes =
     get_extra_wizinfo(0)[ATTRIBUTE_INDEX][ob || previous_object()];
  if (!attributes) attributes = ([]);
  return member(attributes, m) || member(attributes, quote(m));
  /*
  return
     ( attributes =
          get_extra_wizinfo(0)[ATTRIBUTE_INDEX][ob || previous_object()]) &&
     (member(attributes, m) ||
      member(attributes, quote(m)));
  */
}

