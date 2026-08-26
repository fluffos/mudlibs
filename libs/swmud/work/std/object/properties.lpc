// Last edited by deforce on 05-01-2010
// 12-18-98 Tigran made the variables sets and psets initialize when declared
// and removed create().  Added query_perm_sets() for consistancy
// This is our property implementation.  Use as little as possible
private nosave mapping sets = ([ ]);
private mapping psets = ([ ]);

void set(mixed key, mixed value)
{
   sets[key] = value;
}

void add(mixed key, mixed value)
{
   if (typeof(value) == typeof(sets[key]))
   {
      if (!functionp(value))
      {
         sets[key]+=value;
      }
   }
}

mixed query(mixed key)
{
   return sets[key];
}

mapping query_sets()
{
   return sets;
}

void delete(mixed key)
{
   map_delete(sets, key);
}

void set_perm(mixed key, mixed value)
{
   psets[key] = value;
}

mixed query_perm(mixed key)
{
   return psets[key];
}

void delete_perm(mixed key)
{
   map_delete(psets,key);
}

void add_perm(mixed key, mixed value)
{
   if (typeof(value) == typeof(psets[key]))
   {
      if (!functionp(value))
      {
         psets[key] += value;
      }
   }
}

mapping query_perm_sets()
{
   return psets;
}