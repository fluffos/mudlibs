/*
 * /basic/synonym.c
 *
 * An easy way to define synonyms to keywords
 */

private mapping synonyms;

void add_synonym(mixed which, string to);
string get_synonym(string word);

void
add_synonym(mixed which, string to)
{
  if (pointerp(which)) 
  {
    if (!synonyms) 
      synonyms = m_allocate(sizeof(which), 2);
    map(which, #'add_synonym, to);
    return;
  }
  if (!synonyms) 
    synonyms = m_allocate(1, 2);
  if (!synonyms[to]) 
    synonyms += ([ to : ({}); ({}) ]);
  if (closurep(which))
    synonyms[to,1] += ({which});
  else
    synonyms[to] += ({which});
}

string
get_synonym(string word)
{
  int i, j;
  string *keys, *aliases;
  closure *id_functions;
  if (!synonyms) return word;
  keys = m_indices(synonyms);
  if (member(keys, word)>=0) return word;
  for (i = sizeof(keys); i--; )
  {
    if (aliases = synonyms[keys[i]])
      if (member(aliases, word)>=0) 
	return keys[i];
  }
  for (i = sizeof(keys); i--; )
  {
    if (id_functions = synonyms[keys[i],1])
    for (j = sizeof(id_functions); j--; )
      if (funcall(id_functions[j],word)) return keys[i];
  }
  return word;
}

