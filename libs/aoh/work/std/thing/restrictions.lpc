//---------------------------------------------------------------------------
// thing/restrictions.c
//
// Light and weight handling of a thing.
//---------------------------------------------------------------------------

#define ENV environment()

//--- global variables ------------------------------------------------------

protected nosave int Pbright, Plight, Pweight;

//--- light handling of a thing ---------------------------------------------

public void emit_light(int l) {
  if(l) {
    if(ENV) ENV->light_from_inside(l);
    Plight += l;
  }
}

/* Nasty hack to circumvent inheritance problems */
public void _add_light (int l) {
  Plight += l;
}

public int QueryLight()    { return Plight; }
public int SetLight(int l) {
  emit_light(l -= Plight);
  Pbright += l;
  return Plight;
}

public int QueryBright()    { return Pbright; }
public int SetBright(int l) {
  emit_light(l - Pbright);
  return Pbright = l;
}

//--- weight handling of a thing --------------------------------------------

public varargs int QueryWeight(int flag)    { return Pweight; }
public int SetWeight(int w) {
  if(!ENV || ({int})ENV->MayAddWeight(w - Pweight)) {
    if (ENV)
      ENV->AddIntWeight(w - Pweight);
    Pweight = w;
  }
  return Pweight;
}
