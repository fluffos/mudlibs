#include <secure/domaininfo.h>
#include <secure/wizlevels.h>
#include <macros.h>
#include <properties.h>
#include <string.h>

public int main( string str ) {
	mixed  * data;
	string * names, * lords, * domains;
	string   msg,res;
	int      i, j, maxlen;

	if (str) return 0;

	switch (({int})DOMAININFO->QueryState()) {
    	case DI_UNINITED:
      		write("Sorry, no information available at the moment.\n");
      		DOMAININFO->check_state();
      		return 1;
    	case DI_INITING:
      		write("The information presented here is incomplete yet.\n\n");
			  break;
	}

	res = "God: Nostradamus\n";

	domains = sort_array( map(({string *})DOMAININFO->QueryAllDomains(), SF(capitalize)), SF(>));

	if (sizeof(domains)) {
		res += "\n";
		maxlen = sort_array(map(domains,SF(sizeof)),SF(<))[0];

		for (i = 0; i < sizeof(domains); i++) {
			names = 0;
			lords = 0;
			data = ({mixed *})DOMAININFO->QueryDomain(lower_case(domains[i]));
			if (   pointerp(data)
				&& pointerp(data[DD_WIZ])
				&& sizeof(data[DD_WIZ][DW_NAME])) {
					data = data[DD_WIZ];
					names = ({});
					lords = ({});
					for (j = 0; j < sizeof(data[DW_NAME]); j++) {
						switch (data[DW_DSTAT][j]) {
							case D_LORD:
								lords += ({ capitalize(data[DW_NAME][j]) });
								break;
							case D_VICE:
								names += ({ capitalize(data[DW_NAME][j]) });
								break;
						}
					}
				names = (sizeof(lords)
					? sort_array(lords,SF(>))
					: ({"no Lord/Lady"})) + sort_array(names, SF(>));
			}
			if (!sizeof(names) && IS_IMMORTAL(TP))
				res += sprintf("%*s: No wizards enlisted.\n", maxlen, domains[i]);
			else if (sizeof(names)) {
				msg = implode(names, ", ");
				res+=sprintf("%*s: ", maxlen, domains[i])
					+sprintf("%*s%-*=s", maxlen+2, "", 78-maxlen-2, msg)[maxlen+2..]+"\n";
			}
		}
	}
	L_STRING -> smore(res);
	return 1;
}
