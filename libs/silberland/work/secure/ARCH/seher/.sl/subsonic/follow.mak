/def gehnorden = norden%;
/def gehsueden = sueden%;
/def gehosten = osten%;
/def gehwesten = westen%;
/def gehnordosten = nordosten%;
/def gehnordwesten = nordwesten%;
/def gehsuedosten = suedosten%;
/def gehsuedwesten = suedwesten%;
/def gehnordunten = nordunten%;
/def gehsuedunten = suedunten%;
/def gehostunten = ostunten%;
/def gehwestunten = westunten%;
/def gehnordostunten = nordostunten%;
/def gehnordwestunten = nordwestunten%;
/def gehsuedostunten = suedostunten%;
/def gehsuedwestunten = suedwestunten%;
/def gehnordoben = nordoben%;
/def gehsuedoben = suedoben%;
/def gehostoben = ostoben%;
/def gehwestoben = westoben%;
/def gehnordostoben = nordostoben%;
/def gehnordwestoben = nordwestoben%;
/def gehsuedostoben = suedostoben%;
/def gehsuedwestoben = suedwestoben%;
/def gehunten = unten%;
/def gehoben = oben%;
/def gehrunter = runter%;
/def gehrauf = rauf%;
/def gehraus = raus%;

/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Norden und ruft nach InfraSchall' ric1 = \
        /gehnorden
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Sueden und ruft nach InfraSchall' ric2 = \
        /gehsueden
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Osten und ruft nach InfraSchall' ric3 = \
        /gehosten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Westen und ruft nach InfraSchall' ric4 = \
        /gehwesten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Nordosten und ruft nach InfraSchall' ric5 = \
        /gehnordosten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Nordwesten und ruft nach InfraSchall' ric6 = \
        /gehnordwesten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Suedosten und ruft nach InfraSchall' ric7 = \
        /gehsuedosten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Suedwesten und ruft nach InfraSchall' ric8 = \
        /gehsuedwesten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Nordunten und ruft nach InfraSchall' ric9 = \
        /gehnordunten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Suedunten und ruft nach InfraSchall' ric10 = \
        /gehsuedunten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Ostunten und ruft nach InfraSchall' ric11 = \
        /gehostunten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Westunten und ruft nach InfraSchall' ric12 = \
        /gehwestunten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Nordostunten und ruft nach InfraSchall' ric13 = \
        /gehnordostunten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Nordwestunten und ruft nach InfraSchall' ric14 = \
        /gehnordwestunten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Suedostunten und ruft nach InfraSchall' ric15 = \
        /gehsuedostunten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Suedwestunten und ruft nach InfraSchall' ric16 = \
        /gehsuedwestunten
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Nordoben und ruft nach InfraSchall' ric17 = \
        /gehnordoben
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Suedoben und ruft nach InfraSchall' ric18 = \
        /gehsuedoben
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Ostoben und ruft nach InfraSchall' ric19 = \
        /gehostoben
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Westoben und ruft nach InfraSchall' ric20 = \
        /gehwestoben
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Nordostoben und ruft nach InfraSchall' ric21 = \
        /gehnordostoben
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Nordwestoben und ruft nach InfraSchall' ric22 = \
        /gehnordwestoben
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Suedostoben und ruft nach InfraSchall' ric23 = \
        /gehsuedostoben
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach Suedwestoben und ruft nach InfraSchall' ric24 = \
        /gehsuedwestoben
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft rauf und ruft nach InfraSchall' ric25 = \
        /gehrauf
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft runter und ruft nach InfraSchall' ric26 = \
        /gehrunter
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach oben und ruft nach InfraSchall' ric27 = \
        /gehoben
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft nach unten und ruft nach InfraSchall' ric28 = \
        /gehrunter
/def -i -p99 -F -ah -mregexp -t'(> )*Subsonic laeuft raus und ruft nach InfraSchall' ric29 = \
        /gehraus







