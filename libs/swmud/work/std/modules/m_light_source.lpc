// An object that provides light to its environment.
// Iizuka seperated from m_lightable on 06-26-1998

#include <hooks.h>
#include <flags.h>

void set_light(int);
mixed call_hooks(string, int);
void set_flag(int);
int test_flag(int);
void clear_flag(int);

private int light_class = 1;

int query_is_lit()
{
   if (test_flag(F_LIGHTED))
   {
      return 1;
   }

   return 0;
}

int query_light_class()
{
   return light_class;
}

void set_light_class(int x)
{
   light_class = x;
}

int is_light_source() { return 1; }

mixed deactivate_light_source()
{
   string tmp;

   //:HOOK prevent_extinguish
   //A yes/no/error hook that can prevent an object from being extinguished
   tmp = call_hooks("prevent_extinguish", HOOK_YES_NO_ERROR);

   if(!tmp || stringp(tmp))
   {
      return tmp;
   }

   clear_flag(F_LIGHTED);
   set_light(0);

   //:HOOK extinguish
   //called when an object is extinguished.  The return value is ignored
   call_hooks("extinguish", HOOK_IGNORE);

   return 1;
}

varargs mixed activate_light_source(object with)
{
   string tmp;

   //:HOOK prevent_light
   //A yes/no/error hook that can prevent an object from getting lit
   tmp = call_hooks("prevent_light", HOOK_YES_NO_ERROR);

   if (!tmp || stringp(tmp))
   {
      return tmp;
   }

   set_flag(F_LIGHTED);
   set_light(light_class);

   //:HOOK light
   //called when an object is lit.  The return value is ignored.
   call_hooks("light", HOOK_IGNORE);

   return 1;
}