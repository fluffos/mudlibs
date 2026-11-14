// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/handle_light.inc
// Description: Lichtbeschreibung von Reaumen
// Author:	Francis
//
// $Log: handle_light.inc,v $
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

/*
 * Hier fragen die Raeume nach ihrem Tageszeit-String.
 */

static mixed *light_descriptions;

private void get_light_descriptions() {
    light_descriptions = ({
	({      0, "Es ist Geisterstunde."			}),
	({  10000, "Es ist Nacht."				}),
	({  40000, "Der Horizont hellt sich langsam auf."	}),
	({  42000, "Es daemmert."				}),
	({  45000, "Die Sonne geht auf."			}),
	({  51000, "Es ist kurz nach Sonnenaufgang."		}),
	({  54000, "Es ist frueh am Morgen."			}),
	({  62000, "Es ist frueher Vormittag."			}),
	({  73000, "Es ist vormittags."				}),
	({  90000, "Es ist spaet am Vormittag."			}),
	({ 104000, "Es ist kurz vor Mittag."			}),
	({ 113000, "Die Sonne steht im Zenit."			}),
	({ 130000, "Es ist frueher Nachmittag."			}),
	({ 143000, "Es ist nachmittags."			}),
	({ 161000, "Es ist spaet am Nachmittag."		}),
	({ 174000, "Es ist frueh am Abend."			}),
	({ 182000, "Es ist abends."				}),
	({ 190000, "Es ist spaet abends."			}),
	({ 193000, "Es ist kurz vor Sonnenuntergang."		}),
	({ 195000, "Die Sonne geht unter."			}),
	({ 201000, "Es daemmert."				}),
	({ 205000, "Es wird dunkel."				}),
	({ 212000, "Es ist Nacht."				}),
	({ 240001, "Es ist Mitternacht."			})
    });
}

string query_light_description(int time) {
    int a;

    for (a=1; a<sizeof(light_descriptions); a++)
	if (time < light_descriptions[a][0])
	    return light_descriptions[a-1][1];
    return "Es ist irgendwann Tagsueber.";
}
