/*
 * /basic/property.c
 */

private mapping properties;

void
set_properties (string *keys)
{
    map (keys, "set_property", this_object (), 1);
    // it is necessary that the function is given as a string because
    // set_property() is overloaded sometimes and then the overloading
    // function should be called.
}

// added optional argument 'item' here, too. see comment at query_property().
varargs void
set_property (mixed key, mixed value, string item)
{
    int i;
    string *keys;

    if (mappingp(key)) {
      keys = m_indices(key);
      for (i=sizeof(keys); i--;) set_property(keys[i], key[keys[i]]);
      return;
    }

    if (!properties)
        properties = ([ key : value || 1 ]);
    else
        properties[key] = value || 1;
}

// pass second argument 'item' to query_property(), if you want to
// get the property of a fakeitem or component-object
varargs mixed
query_property (string key, string item)
{
    if (!key) return properties || ([ ]);
    return properties && funcall (properties[key]);
}

varargs void
remove_property(string key,string item)
{
    if (properties)
        properties = m_delete(properties, key);
}

varargs void add_to_property(string key,mixed value,string item) {
  mixed h;
  if (h=query_property(key,item))
    h += ({ value });  // will result in an error if the property was set
                       // but not to an array. it is correct to raise an
                       // error then because add_to_property() should not
                       // be used on a property which does contain a single
                       // value.
  else
    h = ({ value });
  set_property(key,h,item);
}

mapping query_properties() {
  return properties && copy(properties); 
}


