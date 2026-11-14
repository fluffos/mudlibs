# Ranger Changelog

## 06.02.2026
* `Melodie der Avatara` hat jetzt eine (viel) hoehere Chance für Mehrfachschutz
* Dauer und Trefferchance von `Ode des Sturms` wurde geringfuegig hochgedreht.
* Die Abklingzeit der Hymne des Waldes sinkt jetzt mit der Faehigkeit. Ebenso haelt die "mitlaufende"
  Hymne nun laenger an.

## 04.01.2025
* fix: Report der aktiven Spells wird auf neuer Basis (aktive Flags im Spieler) berechent wodurch
       die MudDriver resourcen geschont werden sollen und hoffentlich weniger zufaellige Abbrueche 
       auftreten. (Vorher wurde bei jedem Herzschlag das Inventar des Spielers auf Objekte durchsucht.)

## 03.10.2024
* fix: Tierbegleiter sind no_attack fuer den owner und andere Spieler.

## 09.09.204
* Bei der Gildenquest fuer Stufe 17 wird `Lord Soth` jetzt korrekt gewertet
* Die `Melodie der Veraenderung` erfordert nun nicht mehr, dass man faelschlich ein Messer gezueckt haben muss.

## 05.08.2024
* `schattenschnitt` eingebaut
* Tierbegleiter resetten nach `kraft der ahnen` schneller

## 01.08.2024
Das System der Erzfeinde wurde ueberarbeitet. Ab sofort:

* Kann man fuer jeden Kreis, den man in der Gilde aufsteigt einen zusaetzlichen Erzfeindtyp waehlen.
* Gibt es eine groessere und breitere Auswahl an Erzfeinden. Nicht alle sind leich sinnvoll, aber mehr ist moeglich. Auch der Fraggle und Gaffos.
* `schaetz` gibt nun Auskunft darueber, ob das Ziel ein Erzfeind ist. 
* Zaehlt nicht mehr nur die Rasse, sondern wird breiter erkannt, ob es sich um einen Erzfreind handelt.

## 29.07.2024
* Das `Bandolier des Waldlaeufers` ist ein neues Item, mit dem man alle Kraeuter, Mixturen und Wurfmesser verstauen kann.

## 26.07.2024
* Alle Kraeuter funktionieren nun korrekt als `kraeutermixtur`.
* Alle Zauber wurden so ueberarbeitet, dass sie den Itembonus in irgendeiner Form einrechnen.
* `durchdringe` zeigt nun an, ob ein Gegenstand verflucht ist.
* Tierbegleiter hoeren nun auf Erfahrungspunkte zu sammeln, wenn sie ihre Maximalstufe erreicht haben. Damit gelang auch mehr vom Ueberschuss zu ihrem Herrchen oder Frauchen.
* Die Wirkungsdauer der `hymne des waldes` wurde erhoeht, wenn sie sich mit dem Waldlaeufer mitbewegt.
* Die Chance des `giftpfeil` auch ohne dem Talent `Meister der Gifte` zu vergiften wurde erhoeht.

## 22.07.2024
* Der `doppelschuss` wurde durch den neuen Zauber `panzerbrechender schuss` ersetzt da er nutzlos war und sich zu sehr mit `salve deckte`.

Der Zauber wird automatisch ausgetauscht sobald man Raziel aufsucht.

## 11.07.2024
* Maulwuerfe koennen jetzt als Kleintiere gezaehmt werden
* Der `tierangriff` eines Panzertiers funktioniert nun so, dass er dessen Schutz vor Angriffen eine Zeit lang erhoeht. Zuvor hatte er die gleiche Wirkung wie `kampfgeist`.

## 04.06.2024
* Bugfix bei "Schnell wieder Wind": Wenn man keine Waffe mehr hatte beim Ausloesen der Aktion kam es zu einem Fehler.
* Bugfix: In seltenen Faellen konnte die "Erzfeindabfrage" zu einem Fehler fuehren, wenn das Timing zwischen Sterben des Gegners und Check (zB durch einen Zauber) aufeinander viel.

## 08.05.2024
* Bugfix `klinge des blutdorns`: Loescht nun nicht mehr die Sonderfaehigkeiten von Waffen.
* Der Zusatzschlag von `schnell wieder wind` sollte nun normalen Schaden zufuegen.
* Zusaetzliche Wurfmesser vom `messerwurf` kosten weniger MP
* Die Kombination `ode des sturms` und `trance des wilden ebers` loest nun keinen Fehler mehr aus
* Der `stolperdraht` zerfaellt nun nicht mehr sofort
* Bugfix `fusstritt`: Der Fusstritt ist ein physischer Angriff und kann nicht als Zauber abgewehrt werden.

## 03.05.2024
* Neuer GS 17 Zauber: Wilder Schwarm
* Meisterpfad kann absofort gewaehlt werden
* Der Meisterpfad wird in `wlinfo` hervorgehoben

## 29.04.2024
* Fehlende Hilfeseiten zu Meisterzaubern sind jetzt verfuegbar.
* Bugfix bei `klinge des blutdorns`: Die besonderen Angriffe (HitFuncs) von
  Waffen werden nicht mehr ueberschrieben. Der Effekt der Klinge des Blutdorns
  tritt nun zusaetzlich zu den besonderen Effekten magischer Waffen auf.

## 28.04.2024
* Informatione zum 'Meisterpfad' sind jetzt verfuegbar
* Der 'stolperdraht' laesst sich jetzt mit 'loese draht aus' aktivieren
* Bugfix bei `aspekt des panthers`:
  * Das Verstecken for Feinden hat nicht funktioniert. Nun funktioniert es.
    Man hat eine Chance sich vor aktiven Feinden zu verstecken, sodass sie 
    nicht mehr angreifen, wenn man aus dem Kampf flieht.

## 25.04.2024
* Hork kennt nun alle Tierarten und kann Tiere auch den Tierarten zuordnen.
* Neuer Stufe 17 zauber fuer Tiermeister: Wut der Bestie
* Stufenanforderungen fur GS 17-20 wurden angepasst (End-Spielerstufe ist nun 70 fuer GS 20)
* Die 'Hymne des Waldes' bewegt sich jetzt mit dem Spieler mit, wenn er sie gut genug beherrscht.

## 22.04.2024
* Aenderungen an `melodie des ostens`:
  * Der Zauber hat jetzt eine Meldung, wenn er auslaeuft.
  * Die Melodie gibt einen zusaetzlichen Bonus aufs Ausweichen.
* Bei `giftpfeil` und `spinne` wurde ein Fehler behoben durch den 
  das Gift gepluendert werden konnte und damit den Spieler vergiftet
  hat.
* `gemeinsame attacke` funktioniert nun grundsaetzlich anders:
  Anstatt eines direkten Angriffs erhaelt der Tierbegleiter eine Chance
  bei einem Angriff des Waldlaeufers eine Unterstuetuzungsakttion
  durchzufuehren. Diese Aktion ist je nach Tierart eine andere.
* Neuer Zauber `blick des falken` fuer Stufe 17 (Bogenpfad)

## 21.04.2024
* Der Koecher zeigt im Report jetzt mit einem "u" an, wenn die
  `kraft der ahnen` gerade nicht auf das Tier beschworen werden
  kann.
* Neuer Zauber fuer Stufe 16: Aspekt des Panthers

## 20.04.2024
* Aenderungen beim `messerwurf`:
  * Es wurde ein Bug behoben, wenn der Gegner durch eines der
    geworfenen Messer stirbt.
  * Wenn mehrere Messer auf den Gegner geworfen werden verursacht
    nur das letzte eine Wunde.
* Die Meldung des `klingenwirbel`s wurde deutlicher gestaltet, wenn
  sie kein gueltiges Ziel (zB weil es am Boden liegt) finden kann.
* Quest fuer GS 15 ist aktiv

## 19.04.2024
* Aufgabe fuer Gildenstuen 14 ist nun aktiv
* Die Zauberdauer von `kampfgeist` wurde auf eine Runde reduziert
* Beschworene Tiere wurden grundlegend geaendert:
  * Ihre Angriffe skalieren jetztgit mit der Waffe des Waldlaeufers
  * Ihre Lebenspunkte verbessern sich je nach Ausdauer des Beschwoerers
  * Ihre Verteidigung verbessert sich mit der Ruestung des Beschwoerers
  * Sie aktivieren Sonderangriffe jetzt selbststaendig
  * Die Chance fuer Spezialattacken ist von der Intelligenz des Beschwoerers
    abhaengig.
  * Die Spinne greift Gegner nun nicht mehr reglaer an.
* Bugfix bei Tiergefaehrten: Sie koennen nun nicht mehr ueber das Maximal-
  Level hinausgehen und werden beim Rufen runtergeregelt, wenn sie darueber
  liegen.


## 15.05.2024
* Verbesserungen bei `trance des wilden ebers` um die Ueberlebenschance zu
  verbessern:
  * kostet nun keine laufenden MP mehr
  * am Ende der Wirkung gibt es keine Paralyse mehr, lediglich eine 
    Angriffs- und Zauberpause.
* Bei der `melodie der avatara` koennen effekte nun nicht mehr doppelt vorkommen.

## 12.04.2024
* Die Aufgabe fuer GS 13 ist nun loesbar
* Beim Zauber `pakt der schatten` ist es nun nicht mehr moeglich ihn zu 
  zaubern, wenn der Abklingeffekt wirkt.
* Ein Bug (Herzschlagaussetzer) beim Talent `Schnell wie der Wind` sollte
  nun behoben sein.
* Bei `melodie der avatara` wird nun der Schutz mit steigender Faehigkeit
  durch mehrere Tierkoenige gewaehrt  

## 08.04.2024
* `durchdringe` zeigt bei Boegen und Messern nun naehere Informationen an.

## 05.04.2024
* Tierbegleiter:
  * Wenn ein Tierbegleiter schwer verwundet wird und sich aus dem Kampf zurueck 
    ziehen muss, verliert er jetzt Erfahrungspunkte und kann somit sogar Stufen 
    absteigen.
  * Der `tierangriff`n der Begleiter sind nun auf wirksame Effekte umgestellt,
    teilweise haben sie nicht funktioniert.
  * Der `tierangriff` von Katzen kann jetzt blutende Wunden verursachen.
  * Wenn Tierbegleiter Spezialangirffe haben, dann steigt die Anwendungschance
    auch beim Levelanstieg. Vorher tat sie das nur beim neuen Herbeirufen.
* Pakt der Schatten:
  * Kann jetzt auch ausserhalb des Kampfs angewandt werden
  * Hat kein LP-Limit mehr in der Anwendung
  * Ausgaben, die fuer den Raum gedacht waren, werden dem Spieler nciht mehr 
    angezeigt.
* Fertigkeit 'Verbesserter Pakt': Die Fertigkeit funktioniert jetzt grundlegend
  anders. Wenn man die Fertigkeit hat werden Abzuege schneller reduziert, als 
  ohne UND man erhaelt, solange die Nachteile wirken, einen Schutz vor physischem
  Schaden, der mit der Gildenstufe steigt.

## 04.04.2024
* Verbesserungen am Tierreport:
  * `wlinfo` zeigt nun auch den Levelfortschritt des Tierbegleiters
  * Die Lebenspunkte eines Tierbegleiters werden jetzt vollstaendig anstatt in Prozent angezeigt
  * Veraenderungen der LP des Tierbegleiters werden angezeigt
* Zauber:
  * Das Maximum der Boni und Zauberkostensenkung, das durch Items erreicht werden kann wurde auf 50% erhoeht.

## 03.04.2024
* Band des Schuetzen
  * Gibt nun weniger Schadensbonus
  * dafuer koennen die Geisterpfeile, wenn sie einem gelingen, 
    die Seelenkraft des Gegners absorbieren
* Der Report zeigt nun alle Zauber an.
* Ein Bug in der 'Trances des wilden Ebers', der einen FIRZG ausgeloest hat wurde behoben


## 02.04.2024
* Gildenstufe 12 Aufgabe angeschlossen
* Die Topliste enthaelt nun keine Testspieler mehr
* Zauberkosten fuer einige Zaber (Iama-Pfad und Beschwoerer-Pfad gesenkt)
* Kampfgeist funktioniert grundlegend anders und das Tier hat somit eine Uerbelebenschance
* Klinge des Blutdorns
  * kann nicht mehr doppelt gezaubert werden
  * Doppelte Meldungen wurden entfernt
* Ode des Sturms 
  * zaehlt jetzt nicht mehr als Kampftrance
  * Kann nur mehr einmal pro Runde einen Zusatzangriffe ausloesen
  * Erhoeht dafuer die Chacne, dass der Fusstritt den Gegner umwirft
  * Kann den Angriffsschaden mit der Waffe in Blitzschaden umwandeln

## 29.03.2024
* Neue Zaehmbare Tierarten (Kleintiere): Marder, Hasen, Eichhoernchen 
* Neue Tierklasse "Insekten": Insekten, Bienen, Ameisen, Libellen
* Es gibt einen zusaetlichen Skillpunkt (in Summe also 9) auf Stufe 13
* `tiere besprechen` gibt dem Tier auch wieder Erholung, sodass es weitere Spezialangriffe (zB `tierangriff`) machen kann

## 28.03.2024
* Kosten von Tierangriff wurden reduziert. Das erschoepft jetzt auch zunehmend durch den Angriff und muss sich ggf. erst wieder regenerieren.
* Der Koecher erlaubt nun 'wltitel' zu nutzen um sein TItel/Presay auch bei Sehern zu setzen
* Geschwindigkeit wurde angepasst (balancing):
  * Der Geschwindigkeitsbuff ist etwas reduziert
  * 'Schwerere' (aka starke) Waffen sind langsamer als 'leichtere' (aka schwaechere) Waffen
  * Die Zauberkosten wurden auf 25 MP reduziert, dafuer kostet der Zauber jetzt laufend, je nach Geschwindigkeitsbonus, eine kleine Menge MP


## 25.02.2024
* Quest fuer Gildenstufe 11 angehaengt

## 19.02.2024
* Der Spezialangriff des Messerkampfs, der die Schlaeger erhoeht, stackt jetzt angepasster mit 'geschwindigkeit' und aehnlichen Effekten.
* 'Rindenhaut' hat jetzt eine Meldung, wenn die Wirkung aufhoert.

## 13.02.2024
* Combotreffer erhoehen jetzt den Schaden von Angriffen.

## 11.02.2024
* Der Schaden fon 'fusstritt' steigt mit besseren Stiefeln.
* Die Umwerfchance von 'fusstritt' steigt ebenso mit besseren Stiefeln.
* Oben drein profitiert 'fusstritt' jetzt von Schuhen, die besseren Schaden machen, aehnlich zum zertreten der Berserker.
* Ausgeloeste Kombos (z.B. Folgezauber oder am Boden liegende Gegner) erhoehen nun den Fixschaden der Angriffe, anstatt des Maximalschadens.

## 07.02.2024
* Tierbegleiter koennen jetzt mit dem Befehl 'taufe <wen> <was>' bzw 'nenne <wen> <wie>' einmal umbenannt werden.
* Beim Zaehmen werden nun spezielle Identifier des gezaehmten Tieres entfernt. Diese koennten bewirken, dass sie von anderen Objekten oder Raeumen als spezielle NPC erkannt werden, die sie nicht mehr sind.

## 05.02.2024
* Bugfix in Kraeutern und der Kraeutermixtur, damit der Fertigkeitspunkt korrekt beruecksichtigt wird
* Bufgfix bei Kraeutern, die Gift heilen. Es wurde nicht immer komplett geheilt.

## 04.02.2024
* Anpassungen in den Schadensformeln fuer 'deutschuss' und 'messerstich', um die Zauber gegenander zu balancieren. Der Grundschaden von 'messerstich' ist verringert. Der Fixschaden von 'deutschuss' erhoeht. 
* Ein Fehler im 'Sonnenkraut' wurde behoben.
* Alle Heilkraeuter koennen mit 'heilkraut' angesprochen werden.
* Die Kraeutermixtur konsumiert das Kraut nun nicht mehr sofort, sondern verwandelt es in eine potentierte Mixtur mit staerkerer Wirkung, die der Waldlaeufer jederzeit essen kann, wenn er oder sie es braucht.

## 01.02.2024
* Tiere koennen jetzt ihre natuerlichen Sonderangriffe (aka Zauber) nutzen, wenn ihre Stufe hoch genug ist.
* Die Angriffe von Tieren zaehlen ebenso zum lernen des Kampfs gegen Erzfeinde.

## 31.01.2024
* Die Liste in der Fertigkeitsbewertung von Raziel ist jetzt alphabetisch (A-Z) sortiert.

## 30.01.2024
* 'Pakt der Schatten' kann nun aktiviert werden, wenn man zumindest die Haelfte seiner Lebenspunkte verloren hat, anstatt 80 Prozent.

## 28.01.2024
* Schaden von 'messerstich' nach oben hin begrenzt
* Schaden von 'deutschuss' erhoeht. Boegen profitieren in Summe weniger von Dingen, wie 'geschwindigkeit', da sie langsamer angreifen.
* 'Markierung der Beute' kann nun auch bei nur einem Gegner genutzt werden.
* Tierbegleiter attackieren markierte Beute nun mit mehr Eifer. Ihr Schaden gegen markierte Gegner ist geringfuegig erhoeht.

## 26.01.2024
* Messerstich wurde verbilligt (10MP), da Messerkampf schnelle Angriffe mit weniger Schaden sein sollen
* Gezaehmte Tiere koennen nun von jedem Level auf ihre maximale Ausbildungsstufe trainiert werden
* Pakt der Schatten kann nun kaum noch fehlschlagen, ausser man beherrscht ihn extrem schlecht.
  der Pakt soll eine valide und halbwegs zuverlaessige Fluchtoption sein.
* Tiergefaehrten, die sich verstecken oder sterben kommen nun nicht mehr vollgeheilt zurueck.
* Die Aufgabe fuer Gildenstufe 9 ist verfuegbar und kann erledigt werden.
* Die Aufgabe fuer Gildenstufe 10 ist verfuegbar und kann erledigt werden.