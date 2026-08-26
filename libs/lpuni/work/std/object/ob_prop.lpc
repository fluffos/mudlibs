//ob_prop.c

//Tacitus @ LPUniversity
//03-MAR-05
//Object Properties

//Last updated: January 2nd, 2006 by Tacitus

#include <config.h>

int set(string name, mixed var);
int delete(string name);
int add(string name, mixed var);
mixed query(string name);
void init_ob();

mapping ob_data;

int set(string name, mixed var)
{
     if(!ob_data || !mapp(ob_data)) init_ob();
     if(!name) return 0;
     if(ob_data[name]) map_delete(ob_data, name);
     ob_data += ([name : var]);
     return 1;
}

int delete(string name)
{
     if(!ob_data || !mapp(ob_data)) init_ob();
     if(!name) return 0;
     if(!ob_data[name]) return 0;
     map_delete(ob_data, name);
     return 1;
}

int add(string name, mixed var)
{
     mixed temp;
     if(!ob_data || !mapp(ob_data)) init_ob();
     if(!name) return 0;
     if(!ob_data[name]) return 0;
     temp = ob_data[name];
     temp += var;
     ob_data[name] = temp;
     return 1;
}

mixed query(string name)
{
     if(!ob_data || !mapp(ob_data))
     {
          init_ob();
          return 0;
     }
     
     if(!name) return 0;
     if(!ob_data[name]) return 0;
     return ob_data[name];
}

void init_ob()
{
     ob_data = ([]);
}