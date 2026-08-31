/* Do not remove the headers from this file! see /USAGE for more info. */

#define need(x) badness += x + " is required for LIMA libs.\n"

#define FOOTER "**********************************************************\n"
#define IMPOSSIBLE_TO_MISS_HEADER                                                                                      \
   FOOTER                                                                                                              \
   "* You have incorrectly compiled the FluffOS driver. This  *\n"                                                     \
   "* driver is not compatible with the LIMA mudlib.   Please *\n"                                                     \
   "* make the following changes to 'local_options' ) in the  *\n"                                                     \
   "* driver source, and recompile.                           *\n" FOOTER

protected
void create()
{
   string badness = "";
   string version = __VERSION__;

   switch (version[0..11])
   {
   case "fluffos 2019":
   case "fluffos 2020":
      badness += "This FluffOS driver is too old to run the Lima mudlib. \n";
   }

   if (mud_name() == "My LIMA MUD")
      badness += "You must change your mud's name in config.mud under adm/dist/\n";

#ifndef __SANE_EXPLODE_STRING__
   need("#define SANE_EXPLODE_STRING");
#endif
#ifdef __CAST_CALL_OTHERS__
   need("#undef CAST_CALL_OTHERS");
#endif
#ifndef __NO_LIGHT__
   need("#define NO_LIGHT");
#endif
#ifndef __NO_ADD_ACTION__
   need("#define NO_ADD_ACTION");
#endif
#ifdef __NO_ENVIRONMENT__
   need("#undef NO_ENVIRONMENT");
#endif
#ifndef __NO_WIZARDS__
   need("#define NO_WIZARDS");
#endif
#ifdef __OLD_RANGE_BEHAVIOR__
   need("#undef OLD_RANGE_BEHAVIOR");
#endif
#ifdef __OLD_ED__
   need("#undef OLD_ED");
#endif
#ifndef __MUDLIB_ERROR_HANDLER__
   need("#define MUDLIB_ERROR_HANDLER");
#endif
#ifdef __ARRAY_RESERVED_WORD__
   need("#undef ARRAY_RESERVED_WORD");
#endif
#ifndef __PACKAGE_CONTRIB__
   need("#define PACKAGE_CONTRIB");
#endif
#ifndef __PACKAGE_PARSER__
   need("#define PACKAGE_PARSER");
#endif
#ifdef __PACKAGE_UIDS__
   need("#undef PACKAGE_UIDS");
#endif

   if (strlen(badness))
      error("Bad driver configuration:\n" + IMPOSSIBLE_TO_MISS_HEADER + badness + FOOTER);
}
