/**
 * This handler keeps track of citizenships and magistrates.
 * @author Pinkfish 
 * @started Fri Jun 23 20:38:10 PDT 2000
 */

private mapping _magistrates;
private mapping _citizens;

void save_me();

void create() {
   _citizens = ([ ]);
   _magistrates = ([ ]);
} /* create() */

/**
 * This method creates an area for citizens to womble in.
 * @param area the name of the area to create
 * @param num_magistrates the number of magistrates
 * @return 1 on succes, 0 on failure
 */
int create_area(string area, int num_magistrates) {
   _citizens[area] = ({ });
   _magistrates[area] = allocate(num_magistrates);
   save_me();
} /* create_area() */

/**
 * This method adds a citizen to the specified area.
 * @param area the area to add the citizen too
 * @param citizen the citizen to add to the area
 */
int remove_citizen(string area, string citizen) {
   int pos;

   if (!_citizens[area]) {
      return 0;
   }

   if (member_array(citizen, _citizens[area]) != -1) {
      _citizens[area] -= ({ citizen });
      pos = member_array(citizen, _magistrates[area]);
      if (pos != -1) {
         _magistrates[area][pos] = 0;
      }
      save_me();
      return 1;
   }

   return 0;
} /* remove_citizen() */

/**
 * This method adds a magistrate to the area.  If there are no more
 * magistrate slots then this fails.
 * @param area the area to add the magistrate too
 * @param magistrate the magistrate to add
 */
int add_magistrate(string area, string magistrate) {
   if (!is_citizen_of(area, magistrate)) {
      return 0;
   }

   pos = member_array(0, _magistrates[area]);
   if (pos == -1) {
      return 0;
   }
   _magistrates[area][pos] = magistrate;
   return 1;
} /* add_magistrate() */

/**
 * This method adds a citizen to the specified area.
 * @param area the area to add the citizen too
 * @param citizen the citizen to add to the area
 */
int add_citizen(string area, string citizen) {
   string bing;

   if (!PLAYER_HANDLER->test_user(citizen)) {
      return 0;
   }

   if (!_citizens[area]) {
      return 0;
   }

   foreach (bing in keys(_citizens)) {
      if (member_array(citizen, _citizens[bing]) != -1) {
         return 0;
      }
   }

   _citizens[area] += ({ citizen });
   save_me();
   return 1;
} /* add_citizen() */

/**
 * This method checks to see if the specified person is a citizen or
 * not.
 * @param area the area to check them in
 * @param citizen the person to check for citizenship
 * @return 1 if they are a citizen, 0 if not
 */
int is_citizen_of(string area, string citizen) {
   if (!_citizens[area]) {
      return 0;
   }

   return member_array(citizen, _citizens[area]) != -1;
} /* is_citizen_of() */

/**
 * This method checks to see if the specified person is a citizen and
 * where they are a citizen.
 * @param citizen the person to find where they are the citizen of
 * @return where they are a citizen, or 0 on failure
 */
string query_citizen(string citizen) {
   string bing;

   foreach (bing in keys(_citizens)) {
      if (member_array(citizen, _citizens[bing]) != -1) {
         return 0;
      }
   }

   return 0;
} /* query_citizen() */
