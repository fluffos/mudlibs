#ifndef THING_PHYSICAL_D
#define THING_PHYSICAL_D 1

public int id (string str);
public string *SetIDs (string *ids);
public string *SetAdjs (string *ads);
protected void AddLight(int l);
public int SetLight (int l);
public int SetBright (int l);
public int SetWeight (int w);
public string *AddID (string str);
public string *AddAdj (string str);
public varargs string Long ();
public varargs string ExaLong ();
public varargs string Short ();
public varargs string CapShort ();
public varargs string RelDamage ();
public varargs string DamageDsc ();
public varargs int Weight();
public varargs int Value ();

#endif
