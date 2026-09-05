mapping vars;
string *saved_vars;

varargs int set_var(string nm, mixed val)
{
  if(MASTER->allow_varAccess(nm,val,CALLER,TO))
    return (vars[nm] = val, GREEN);
  else
    return RED;
}

mixed query_var(string nm)
{
  if(MASTER->allow_varAccess(nm,0,CALLER,TO))
    return vars[nm];
  else
    return RED;
}

mixed query_vars()
{
  if(MASTER->allow_varAccess("ALL",0,CALLER,TO))
    return vars;
  else
    return RED;
}

int delete_var(string nm)
{
  if(MASTER->allow_varAccess(nm,0,CALLER,TO))
    return (vars = m_delete(vars, nm), GREEN);
  else
    return RED;
}

varargs int add_var(string nm, mixed val)
{
  if(MASTER->allow_varAccess(nm,val,CALLER,TO))
    return (vars[nm] += val, GREEN);
  else
    return RED;
}

varargs int subtract_var(string nm, mixed val)
{
  if(MASTER->allow_varAccess(nm,val,CALLER,TO))
    return (vars[nm] -= val, GREEN);
  else
    return RED;
}
